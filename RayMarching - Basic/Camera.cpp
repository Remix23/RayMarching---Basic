#include <SFML/Graphics.hpp>

#include "Camera.h"

Camera::Camera() : PrototypeObject()
{
	FOV = 45;
}

Camera::Camera(sf::Vector3f pos, float fov) : PrototypeObject(pos)
{
	FOV = fov
;
}