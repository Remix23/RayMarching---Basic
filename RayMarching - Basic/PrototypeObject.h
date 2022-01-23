#pragma once
#include <SFML/Graphics.hpp>

class PrototypeObject
{
public:
	sf::Vector3f Pos;
	sf::Vector3f Color;

	PrototypeObject();

	PrototypeObject(sf::Vector3f pos);

	PrototypeObject(sf::Vector3f p, sf::Vector3f c);

	virtual ~PrototypeObject();

	sf::Vector3f GetPos();
	sf::Vector3f GetColor();

	static float GetDistance(sf::Vector3f obj1Pos, sf::Vector3f obj2Pos) 
	{
		return std::sqrt(std::pow(obj1Pos.x - obj2Pos.x, 2) + std::pow(obj1Pos.y - obj2Pos.y, 2) + std::pow(obj1Pos.z - obj2Pos.z, 2));
	}
	static float GetDistanceSquared(sf::Vector3f obj1Pos, sf::Vector3f obj2Pos) 
	{
		return std::pow(obj1Pos.x - obj2Pos.x, 2) + std::pow(obj1Pos.y - obj2Pos.y, 2) + std::pow(obj1Pos.z - obj2Pos.z, 2);
	}

	static sf::Vector3f NormaliseVector(sf::Vector3f vec)
	{
		float vecLenght = std::sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);

		return vec / vecLenght;
	}

	virtual float GetSDF(sf::Vector3f point);
};