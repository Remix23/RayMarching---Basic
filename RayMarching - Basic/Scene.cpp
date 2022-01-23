#define _USE_MATH_DEFINES

#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>
#include <limits>
#include <memory>

#include "Scene.h"
#include "Camera.h"
#include "PrototypeObject.h"

Scene::Scene()
{
	_objects = std::vector <std::unique_ptr<PrototypeObject>>();
	_lights = std::vector <std::unique_ptr<LightSource>>();

	MaxNumberOfSteps = 255;
	MinStepSize = 0.0001f;

	MaxDistanceTraveled = 100.0f;
}

sf::Vector3f Scene::GetRayDirection(float fov, sf::Vector2f screenSize, sf::Vector2f outPixelCords)
{
	/*
		we consider only the space between camera and screen (camera z = 0, screen z we calcalating)
	*/
	sf::Vector2f xy = outPixelCords - screenSize / 2.0f;

	float z = screenSize.y / std::tan(fov * M_PI / 360);

	return PrototypeObject::NormaliseVector(sf::Vector3f(xy.x, xy.y, -z));
}

float Scene::TraceVector(sf::Vector3f cameraPos, sf::Vector3f marchingDirection)
{
	/*
		march along the normalised vector until any surface is hit
	*/
	float distanceTravelled = 0;
	for (int i = 0; i < MaxNumberOfSteps; i++)
	{
		sf::Vector3f currentPos = sf::Vector3f(cameraPos + distanceTravelled * marchingDirection);
		float sceneSDF = GetSceneSDF(currentPos);

		if (sceneSDF < MinStepSize) return distanceTravelled; // the ray hitted surface

		distanceTravelled += sceneSDF;

		if (distanceTravelled > MaxDistanceTraveled) break;
	}
	return distanceTravelled;
}

sf::Vector3f Scene::GetPixelColor()
{

	return sf::Vector3f(0.0f, 0.0f, 0.0f);
}

float Scene::GetSceneSDF(sf::Vector3f point)
{
	float minDistance = std::numeric_limits<float>::infinity();

	for (auto&& obj : _objects)
	{
		float distance = obj->GetSDF(point);

		if (distance < minDistance) minDistance = distance;
	}
	return minDistance;
}

float Scene::SDFunion(float sdf1, float sdf2)
{
	return std::min(sdf1, sdf2);
}

float Scene::SDFintersection(float sdf1, float sdf2)
{
	return std::max(sdf1, sdf2);
}

float Scene::SDFdifference(float sdf1, float sdf2)
{
	return std::max(sdf1, -sdf2);
}