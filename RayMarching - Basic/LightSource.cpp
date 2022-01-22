#include <SFML/Graphics.hpp>
#include "LightSource.h"

LightSource::LightSource(sf::Vector3f pos, sf::Vector3f col, float br) : PrototypeObject(pos, col)
{
	_brightness = br;
}