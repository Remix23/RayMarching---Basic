#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Camera.h"
#include "PrototypeObject.h"
#include "LightSource.h"

class Scene
{
private:

	std::vector <PrototypeObject> _objects;

	std::vector <LightSource> _lights;

	Camera _camera;

	// ray marching properties 
	int MaxNumberOfSteps;
	float MinStepSize;


public:

	Scene();

	float GetSceneSDF();

	sf::Vector3f GetPixelColor();

};
