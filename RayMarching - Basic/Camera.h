#pragma once

#include <SFML/Graphics.hpp>
#include <math.h>
#include "PrototypeObject.h"

class Camera : public PrototypeObject
{
public:

	float FOV;

	Camera();

	Camera(sf::Vector3f pos, float fov);

};
