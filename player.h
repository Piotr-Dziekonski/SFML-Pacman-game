#include <SFML/Graphics.hpp>
#include <string>
#include "map.h"
class Player
{
    sf::Sprite sprite;
    int posX;
    int posY;
    std::string direction;
    bool isMoving;


public:
    std::string directionToCheck;
    Player(sf::Texture&, sf::Sprite, sf::IntRect, int, int);
    void checkColAndMove(std::vector <Tile>, int pix = 2);
    void draw(sf::RenderWindow &window);
    bool checkCollision(std::vector <Tile>);
    void setDirection(std::string);
    std::string getDirection();
    void move(int);
    void setFace(std::string);
    void chooseDirection(std::string);
    int getPosY();
    int getPosX();
    //void turn(std::string);
};
