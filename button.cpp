#include "widgets.hh"
#include <iostream>

Button::Button(int px, int py, const std::string& txt, Widget *parent)
    : Button(0, 0, px, py, txt, parent)
{
}

Button::Button(int sx, int sy, int px, int py,
        const std::string& txt, Widget *parent) 
    : Rectangle(sx, sy, px, py, parent),
    text(0, 0, txt, this)
{
    OnMouseUp(sf::Vector2i(0, 0));
    rect.setOutlineColor(sf::Color::Black);
    text.setText(""); // because whatever !
    setText(txt);
}

void Button::setSize(int sx, int sy)
{
    Rectangle::setSize(sx, sy);

    sf::Vector2i dimenButton = getDimens();
    sf::Vector2i dimenText = this->text.getDimens();

    this->text.setPosition(
            dimenButton.x / 2 - dimenText.x / 2,
            dimenButton.y / 2 - dimenText.y / 2);
}

void Button::setText(const std::string& text) {
    this->text.setText(text);
    setSize(msx, msy);
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
