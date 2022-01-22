#include <SFML/Graphics.hpp>

#include "Sphere.h"

Sphere::Sphere(sf::Vector3f pos, sf::Vector3f col, unsigned long r) : PrototypeObject(pos, col)
{
	_radius = r;
}

float Sphere::objSDF(sf::Vector3f point)
{
	return GetDistance(point, Pos) - _radius;
}