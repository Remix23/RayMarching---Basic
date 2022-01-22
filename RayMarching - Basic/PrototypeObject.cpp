#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>

#include "PrototypeObject.h"

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

float PrototypeObject::GetDistance(PrototypeObject obj1, PrototypeObject obj2)
{
	return std::sqrt(std::pow(obj1.Pos.x - obj2.Pos.x, 2) + std::pow(obj1.Pos.y - obj2.Pos.y, 2) + std::pow(obj1.Pos.z - obj2.Pos.z, 2));
}

float PrototypeObject::GetDistanceSquared(PrototypeObject obj1, PrototypeObject obj2)
{
	return std::pow(obj1.Pos.x - obj2.Pos.x, 2) + std::pow(obj1.Pos.y - obj2.Pos.y, 2) + std::pow(obj1.Pos.z - obj2.Pos.z, 2);
}