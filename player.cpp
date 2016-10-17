#include <SFML/Graphics.hpp>
#include "player.h"
#include "map.h"

Player::Player(sf::Texture &t, sf::Sprite s, sf::IntRect rect, int x, int y)
{
    directionToCheck = "none";
    s.setTexture(t);
    s.setTextureRect(rect);
    s.setPosition(x,y);
    direction = "none";
    posX = x;
    posY = y;
    sprite = s;
}
void Player::draw(sf::RenderWindow &window){
    window.draw( sprite );
}
bool Player::checkCollision(std::vector <Tile> tilemap)
{
    for(int i = 0; i< tilemap.size(); i++)
    {
        if((tilemap[i].getPosX() < posX + 64) && (tilemap[i].getPosX() + 32 > posX) && (tilemap[i].getPosY() < posY + 64) && (tilemap[i].getPosY() + 32 > posY))
        {
            return true;
        }

    }
    return false;

}
void Player::checkColAndMove(std::vector <Tile> map, int pix)
{
    if(Player::directionToCheck != "none")
        {
            std::string dir = Player::getDirection();
            Player::setDirection(Player::directionToCheck);
            Player::move(pix);
            if(Player::checkCollision(map))
            {
                Player::move(-pix);
                Player::setDirection(dir);
                if(Player::checkCollision(map))
                {
                    Player::move(-pix);
                    Player::setDirection("none");
                    Player::directionToCheck = "none";
                }

            }
            else
            {
                Player::setFace(Player::getDirection());
                Player::directionToCheck = "none";
                Player::move(-pix);
            }
        }
        else if(Player::checkCollision(map))
        {
            Player::move(-pix);
            Player::setDirection("none");
        }
}
void Player::setDirection(std::string dir)
{
    direction = dir;
}
std::string Player::getDirection()
{
    return direction;
}
void Player::setFace(std::string face)
{
    if(face == "right")
    {
        sprite.setTextureRect(sf::IntRect( 0, 0, 64, 64 ));
    }
    else if(face == "left")
    {
        sprite.setTextureRect(sf::IntRect( 66, 0, 64, 64 ));
    }
    else if(face == "up")
    {
        sprite.setTextureRect(sf::IntRect( 132, 0, 64, 64 ));
    }
    else if(face == "down")
    {
        sprite.setTextureRect(sf::IntRect( 198, 0, 64, 64 ));
    }

}
/*void Player::turn(std::string dir)
{
    Player::setDirection(dir);
    Player::setFace(dir);
}*/
void Player::chooseDirection(std::string dir)
{
    if (Player::getDirection() == "none") // pacman not moving
    {
        Player::setDirection(dir);
        Player::setFace(dir);
    }
    else // pacman is moving
    {
        Player::directionToCheck = dir;
    }
}
void Player::move(int pix)
{
    if(direction == "right")
    {
        posX += pix;
        sprite.setPosition(posX,posY);
    }
    else if(direction == "left")
    {
        posX -= pix;
        sprite.setPosition(posX,posY);
    }
    else if(direction == "up")
    {
        posY -= pix;
        sprite.setPosition(posX,posY);
    }
    else if(direction == "down")
    {
        posY += pix;
        sprite.setPosition(posX,posY);
    }
}
int Player::getPosY()
{
    return posY;
}
int Player::getPosX()
{
    return posX;
}

