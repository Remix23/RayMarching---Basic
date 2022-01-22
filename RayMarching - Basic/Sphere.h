#pragma once
#include <SFML/Graphics.hpp>

#include "PrototypeObject.h"

class Sphere : public PrototypeObject
{
private:
	unsigned long _radius;
public:

	Sphere(sf::Vector3f pos, sf::Vector3f col, unsigned long r);

	float objSDF(sf::Vector3f point) override;
};