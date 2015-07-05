#include "widgets.hh"
#include <iostream>

static int DIAMETER = 15;

RadioButton::RadioButton(int px, int py, Widget *parent)
    : Widget(DIAMETER * 2, DIAMETER * 2, px, py, parent),
      circle(DIAMETER)
{
    circle.setOutlineColor(sf::Color::Black);
    circle.setOutlineThickness(DIAMETER / 3);
}


bool RadioButton::isChecked() const
{
    return checked;
}

void RadioButton::toggle()
{
    checked = !checked;
    update();
}

void RadioButton::setChecked(bool checked)
{
    this->checked = checked;
    update();
}

void RadioButton::update()
{
    if (isChecked())
        circle.setFillColor(sf::Color::Black);
    else
        circle.setFillColor(sf::Color::White);
}

sf::Vector2i RadioButton::draw()
{
    circle.setPosition(mpx, mpy);
    mwindow->draw(circle);
    return Widget::draw();
}

void RadioButton::OnClicked()
{
    toggle();
}
