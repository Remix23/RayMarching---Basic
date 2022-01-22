#include <SFML/Graphics.hpp>

#include "Camera.h"

Camera::Camera() : PrototypeObject()
{
	angleOfViev = 45;
}

Camera::Camera(sf::Vector3f pos, float aov) : PrototypeObject(pos)
{
	angleOfViev = aov;
}