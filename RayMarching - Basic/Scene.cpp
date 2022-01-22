#include <SFML/Graphics.hpp>
#include <vector>

#include "Scene.h"
#include "Camera.h"

Scene::Scene()
{
	_objects = std::vector <PrototypeObject>();
	_lights = std::vector <LightSource>();

	_camera = Camera();
}