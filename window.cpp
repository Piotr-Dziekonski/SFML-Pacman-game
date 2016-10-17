#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include "window.h"


Window::Window(std::string n, int w, int h, int c)
:sf::RenderWindow(sf::VideoMode( w, h, c ), n)
{
    name = n;
    width = w;
    height = h;
    colors = c;
}


