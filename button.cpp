#include "widgets.hh"
#include <iostream>

Button::Button(int px, int py, const std::string& txt, Widget *parent) 
    : Rectangle(0, 0, px, py, parent),
    text(0, 0, txt, this)
{
    OnMouseDown(sf::Vector2i(0, 0));
}

void Button::setText(const std::string& text) {
    this->text.setText(text);
}

void Button::OnMouseUp(sf::Vector2i pos) {
    isPressed = false;
    setColor(sf::Color(100, 100, 120, 100));
    msx -= 10;
    msy -= 10;
    mpx += 5;
    mpy += 5;
    Rectangle::OnMouseUp(pos);
}

void Button::OnMouseDown(sf::Vector2i pos) {
    isPressed = true;
    setColor(sf::Color(100, 100, 120, 130));
    msx += 10;
    msy += 10;
    mpx -= 5;
    mpy -= 5;
    Rectangle::OnMouseDown(pos);
}
