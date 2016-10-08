#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>

//#include "tilemap.hpp"
enum pressedKey
{
    left,
    right,
    up,
    down,
    none
};
int main()
{
    // WINDOW
    sf::RenderWindow appWindow( sf::VideoMode( 1280, 1024, 32 ), "Pacman" );
    appWindow.setVerticalSyncEnabled(true);

    // IMAGES
    sf::Texture spriteSheet;
    sf::Texture tileTexture;
    spriteSheet.loadFromFile( "spriteSheet.png" );
    tileTexture.loadFromFile("tile.png");
    // SPRITES
    sf::Sprite ghostSprite;
    ghostSprite.setTexture( spriteSheet );
    ghostSprite.setTextureRect(sf::IntRect( 0, 0, 64, 64 ));
    ghostSprite.setOrigin( 32, 32 );
    ghostSprite.setPosition( 400, 300 );

    sf::Sprite tile;
    tile.setTexture(tileTexture);




    while( appWindow.isOpen() )
    {
        pressedKey key;
        sf::Event event;
        while( appWindow.pollEvent( event ) )
        {
            if( event.type == sf::Event::Closed )
            {
                appWindow.close();
            }
            if( event.type == sf::Event::KeyPressed )
            {
                switch (event.key.code)
                {
                    case sf::Keyboard::Up:
                        key = up;
                        break;
                    case sf::Keyboard::Left:
                        key = left;
                        break;
                    case sf::Keyboard::Right:
                        key = right;
                        break;
                    case sf::Keyboard::Down:
                        key = down;
                        break;
                    case sf::Keyboard::Escape:
                        appWindow.close();
                        break;
                    default:
                        break;
                }
            }
        }

        switch (key)
        {
            case up:
                ghostSprite.move( 0, -6 );
                ghostSprite.setTextureRect(sf::IntRect( 132, 0, 64, 64 ));
                break;
            case left:
                ghostSprite.move( -6, 0 );
                ghostSprite.setTextureRect(sf::IntRect( 66, 0, 64, 64 ));
                break;
            case right:
                ghostSprite.move( 6, 0 );
                ghostSprite.setTextureRect(sf::IntRect( 0, 0, 64, 64 ));
                break;
            case down:
                ghostSprite.move( 0, 6 );
                ghostSprite.setTextureRect(sf::IntRect( 198, 0, 64, 64 ));
                break;
            default:
                break;
        }

        // MAP GENERATION

        appWindow.clear( sf::Color::Black );

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
                       tile.setPosition(column * 32, lineCount * 32);
                       appWindow.draw(tile);
                       // COLLISION
                       if(tile.getGlobalBounds().intersects(ghostSprite.getGlobalBounds()))
                       {
                            switch (key)
                            {
                                case up:
                                    ghostSprite.move( 0, 6 );
                                    break;
                                case left:
                                    ghostSprite.move( 6, 0 );
                                    break;
                                case right:
                                    ghostSprite.move( -6, 0 );
                                    break;
                                case down:
                                    ghostSprite.move( 0, -6 );
                                    break;
                                default:
                                    break;
                            }
                       }
                   }
               }
               lineCount++;
            }

        }


        appWindow.draw( ghostSprite );
        //generateMap(appWindow);
        appWindow.display();

        sf::sleep(sf::microseconds(100));
    }
    return 0;
}





