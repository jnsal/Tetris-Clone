#include "UI.hpp"
#include <iostream>
#include "configs.hpp"

UI::UI()
{
    texture = Defaults::Get().Texture();
    
    rect.setSize(sf::Vector2f(150.f, 50.f));
    rect.setFillColor(sf::Color::Green);
}

UI::UI(V2 pos, float width, float height): pos(pos)
{
    if (width != 0 && height != 0) 
        collision = BoxCollision(pos.x, pos.y, width, height);
}
UI::UI(V2 pos, sf::IntRect sprPlace): pos(pos), sprPlace(sprPlace)
{
    texture = Defaults::Get().Texture();

    collision = BoxCollision(pos.x, pos.y, sprPlace.width, sprPlace.height);
}

void UI::mouseIsOver(RenderWindow& window)
{
    V2 m = window.getMousePosition();
    if (collision.isInside(m.x, m.y))
    {
        rect.setFillColor(sf::Color::Red);
    } else {
        rect.setFillColor(sf::Color::Green);
    }
}

bool UI::isPointInside(int x, int y)
{
    return collision.isInside(x, y);
}

void UI::setCollision(int x, int y, int w, int h)
{
    collision.updateCollision(x, y, w, h);
}

void UI::setScale(float scale)
{
    spr.setScale(scale, scale);
}
