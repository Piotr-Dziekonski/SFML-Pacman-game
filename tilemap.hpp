#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
enum direction
{
    left,
    right,
    up,
    down,
    none
};
void generateMap(sf::RenderWindow &appWindow, sf::Sprite &ghostSprite, direction &nextDirection, direction &key);

