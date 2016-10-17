#include "tilemap.hpp"

void generateMap(sf::RenderWindow &appWindow, sf::Sprite &ghostSprite, direction &nextDirection, direction &key )
{
    sf::Texture tileTexture;
    tileTexture.loadFromFile("tile.png");
    sf::Sprite tile;
    tile.setTexture(tileTexture);
    std::vector < std::vector<int> > tilemap;
    tilemap.resize(100,std::vector<int>(100,0));

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
                   tilemap [lineCount][column] = 1;
               }
           }
           lineCount++;
        }
    }


    //MAP DRAWING AND COLLISION
    for(int i=0; i<tilemap.size(); i++)
    {
        for(int j=0; j<tilemap[0].size(); j++)
        {
            if(tilemap[j][i] == 1)
            {
               tile.setPosition(i * 32, j * 32);
               appWindow.draw(tile);
               if(tile.getGlobalBounds().intersects(ghostSprite.getGlobalBounds()))
                   {
                       if(nextDirection == none)
                       {
                            switch (key)
                            {
                                case up:
                                    ghostSprite.move( 0, 4 );
                                    break;
                                case left:
                                    ghostSprite.move( 4, 0 );
                                    break;
                                case right:
                                    ghostSprite.move( -4, 0 );
                                    break;
                                case down:
                                    ghostSprite.move( 0, -4 );
                                    break;
                                default:
                                    break;
                            }
                       }
                       else
                       {
                           switch (key)
                            {
                                case up:
                                    ghostSprite.move( 0, 4 );
                                    break;
                                case left:
                                    ghostSprite.move( 4, 0 );
                                    break;
                                case right:
                                    ghostSprite.move( -4, 0 );
                                    break;
                                case down:
                                    ghostSprite.move( 0, -4 );
                                    break;
                                default:
                                    break;
                            }
                            key = nextDirection;
                            nextDirection = none;
                       }


                   }

            }

        }
    }
}

