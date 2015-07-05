#include "widgets.hh"
#include <iostream>

Button::Button(int px, int py, const std::string& txt, Widget *parent) 
    : Rectangle(0, 0, px, py, parent),
    text(0, 0, txt, this)
{
    OnMouseUp(sf::Vector2i(0, 0));
    rect.setOutlineColor(sf::Color::Black);
}

void Button::setText(const std::string& text) {
    this->text.setText(text);
}

void Button::OnMouseUp(sf::Vector2i pos) {
    isPressed = false;
    setColor(sf::Color(100, 100, 120, 80));
    Rectangle::OnMouseUp(pos);
    rect.setOutlineThickness(5);
}

void Button::OnMouseDown(sf::Vector2i pos) {
    isPressed = true;
    setColor(sf::Color(100, 100, 120, 150));
    Rectangle::OnMouseDown(pos);
    rect.setOutlineThickness(-5);
}
