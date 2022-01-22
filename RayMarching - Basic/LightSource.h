#pragma once

#include <SFML/Graphics.hpp>
#include "PrototypeObject.h"

class LightSource : public PrototypeObject
{
private:
	float _brightness;

public:

	LightSource(sf::Vector3f pos, sf::Vector3f color, float br);

	void SetBrightness(float br);

	void GetBrighness();
};