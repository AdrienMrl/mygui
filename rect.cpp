#include "widgets.hh"
#include <iostream>

Rectangle::Rectangle(int sx, int sy, int px, int py, Widget *parent) :
  Widget(sx, sy, px, py, parent) {

  rect.setSize(sf::Vector2f(msx, msy));
  rect.setPosition(px, py);
  rect.setFillColor(sf::Color(10, 10, 10, 40));
}

sf::Vector2i Rectangle::draw() {

  sf::Vector2i dimens = Widget::draw();
  rect.setSize(sf::Vector2f(dimens.x, dimens.y));
  mwindow->draw(rect);
  return dimens;
}
