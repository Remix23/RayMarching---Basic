#include <SFML/Graphics.hpp>
#include <iostream>
#include "Sphere.h"
#include "Scene.h"
#include "Camera.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 800), "SFML works!");
    sf::CircleShape shape(100.f);

    Scene scene;



    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        shape.setOrigin(100.0f, 100.0f);
        sf::Vector2u win_size = window.getSize();

        shape.setPosition(win_size.x / 2, win_size.y / 2);

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}