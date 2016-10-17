#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include "map.h"

void Map::generate(sf::RenderWindow &window, sf::Texture &tileTexture, int xOfRect)
{
    sf::Sprite tile;
    std::vector <Tile> map;

    std::ifstream openfile("Map2.txt");
    if(openfile.is_open())
    {
       std::string line;
       int lineCount = 0;
       while(std::getline(openfile, line))
       {

           for(int column = 0; column < line.length(); column++)
           {
               if(line[column] == '1')
               {
                   Tile block(tileTexture, tile, column*32, lineCount*32, xOfRect);
                   map.push_back(block);
               }
           }
           lineCount++;
        }
    }
    tilemap = map;
    for(int i=0; i<map.size(); i++)
    {
           map[i].draw(window);
    }

}
std::vector <Tile> Map::getTilemap()
{
    return tilemap;
}


Tile::Tile(sf::Texture &t, sf::Sprite s, int x, int y, int xOfRect, int sX, int sY)
{
    sizeX = sX;
    sizeY = sY;
    posX = x;
    posY = y;
    s.setTexture(t);
    s.setTextureRect(sf::IntRect(xOfRect, 0, 32, 32));
    s.setPosition(x,y);
    sprite = s;

}
int Tile::getPosY()
{
    return posY;
}
int Tile::getPosX()
{
    return posX;
}
void Tile::draw(sf::RenderWindow &window)
{
    window.draw( sprite );
}
