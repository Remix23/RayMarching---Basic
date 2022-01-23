#pragma once
#include <SFML/Graphics.hpp>

#include "PrototypeObject.h"

class Sphere : public PrototypeObject
{
private:
	unsigned long _radius;
	unsigned int id;
public:

	static unsigned int numberOfSpheres;

	Sphere(sf::Vector3f pos, sf::Vector3f col, unsigned long r);

	~Sphere() override;

	float GetSDF(sf::Vector3f point) override;
};