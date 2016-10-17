#pragma once
#include <SFML/Graphics.hpp>
class Tile
{
    int sizeX;
    int sizeY;
    int posX;
    int posY;
    sf::Sprite sprite;

public:
    Tile(sf::Texture&, sf::Sprite, int, int, int xOfRect = 264, int sX = 32, int sY = 32);
    int getPosY();
    int getPosX();
    void draw(sf::RenderWindow &window);

};
class Map
{

    std::vector <Tile> tilemap;

public:
    void generate(sf::RenderWindow &window, sf::Texture &tileTexture, int xOfRect = 264); //ZROB TO tak zeby tworzylo obiekty klasy tile i wysiwetlalo je metod¹ draw() zgodnie z map¹ z pliku
    std::vector <Tile> getTilemap();
};



