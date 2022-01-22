#pragma once
#include <SFML/Graphics.hpp>

class PrototypeObject
{
public:
	sf::Vector3f Pos;
	sf::Vector3f Color;

	PrototypeObject(sf::Vector3f p, sf::Vector3f c);
	~PrototypeObject();

	sf::Vector3f GetPos() {}
	sf::Vector3f GetColor() {}



	static float GetDistance(PrototypeObject obj1, PrototypeObject obj2) {}
	static float GetDistanceSquared(PrototypeObject obj1, PrototypeObject obj2) {}
};