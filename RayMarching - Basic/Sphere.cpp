#include <SFML/Graphics.hpp>
#include <iostream>

#include "Sphere.h"

unsigned int Sphere::numberOfSpheres = 0;

Sphere::Sphere(sf::Vector3f pos, sf::Vector3f col, unsigned long r) : PrototypeObject(pos, col)
{
	_radius = r;
	id = numberOfSpheres;
	numberOfSpheres++;
}

Sphere::~Sphere()
{
	float x = Pos.x;
	float y = Pos.y;
	float z = Pos.z;
	std::printf("Sphere of id: %u at pos: (%.3f, %.3f, %.3f)", id, x, y, z);
}

float Sphere::GetSDF(sf::Vector3f point)
{
	return GetDistance(point, Pos) - _radius;
}