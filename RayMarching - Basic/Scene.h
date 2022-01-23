#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <math.h>

#include "Camera.h"
#include "PrototypeObject.h"
#include "LightSource.h"

class Scene
{
private:

	std::vector <std::unique_ptr<PrototypeObject>> _objects;

	std::vector <std::unique_ptr<LightSource>> _lights;

	// ray marching properties 
	int MaxNumberOfSteps;
	float MinStepSize;

	float MaxDistanceTraveled;


public:

	Scene();

	void AddObject(PrototypeObject obj);
	void AddLightSOurce(LightSource light);

	void RemoveObject(int index);
	void RemoveLightSource(int index);

	PrototypeObject PopObject();
	LightSource PopLightource();
	
	PrototypeObject GetObjectFromScene(int index);
	LightSource GetLightSource(int index);

	std::vector<std::unique_ptr<PrototypeObject>> GetSceneObjects();
	std::vector<std::unique_ptr<LightSource>> GetLightSources();

	sf::Vector3f GetRayDirection(float fov, sf::Vector2f screenSize, sf::Vector2f outPixelCords); // calculates the normalised vector to travel along
	float GetSceneSDF(sf::Vector3f point);
	float TraceVector(sf::Vector3f cameraPos, sf::Vector3f marchingDirection);

	sf::Vector3f GetPixelColor();

	float SDFunion(float sdf1, float sdf2);
	float SDFintersection(float sdf1, float sdf2);
	float SDFdifference(float sdf1, float sdf2);

};
