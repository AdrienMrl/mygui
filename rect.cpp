#include "widgets.hh"
#include <iostream>

Rectangle::Rectangle(int sx, int sy, int px, int py, Widget *parent) :
  Widget(sx, sy, px, py, parent) {

  rect.setSize(sf::Vector2f(msx, msy));
}

sf::Vector2i Rectangle::draw() {

  sf::Vector2i dimens = Widget::draw();
  rect.setPosition(mpx, mpy);
  rect.setSize(sf::Vector2f(dimens.x, dimens.y));
  rect.setFillColor(mColor);
  mwindow->draw(rect);
  return dimens;
}
