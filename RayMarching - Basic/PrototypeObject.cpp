#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>

#include "PrototypeObject.h"

PrototypeObject::PrototypeObject()
{
	Pos = sf::Vector3f(0.0f, 0.0f, 0.0f);
	Color = sf::Vector3f(0.0f, 0.0f, 0.0f);
}

PrototypeObject::PrototypeObject(sf::Vector3f pos)
{
	Pos = pos;
	Color = sf::Vector3f(0.0f, 0.0f, 0.0f);
}

PrototypeObject::PrototypeObject(sf::Vector3f p, sf::Vector3f c)
{
	Pos = p;
	Color = c;
}

PrototypeObject::~PrototypeObject()
{
	std::cout << "Object destroyed" << std::endl;
}

sf::Vector3f PrototypeObject::GetPos()
{
	return Pos;
}

sf::Vector3f PrototypeObject::GetColor()
{
	return Color;
}

float PrototypeObject::objSDF(sf::Vector3f point)
{
	return GetDistanceSquared(Pos, point);
}