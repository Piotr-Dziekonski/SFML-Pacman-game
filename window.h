#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>

class Window :public sf::RenderWindow
{
    int width, height, colors;
    std::string name;

public:
    Window(std::string, int, int, int);
};
