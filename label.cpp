#include "widgets.hh"
#include <cassert>
#include <iostream>

Label::Label(int px, int py, const std::string& txt, Widget *parent) :
  Widget(0, 0, px, py, parent)
{
  setText(txt);
  text.setPosition(sf::Vector2f(px, py));
  text.setColor(sf::Color(0, 0, 0));
}

void Label::setText(const std::string& txt) {
  text.setString(txt);
  font.loadFromFile("OpenSans-Regular.ttf");
  text.setFont(font);

  sf::FloatRect bounds = text.getLocalBounds();
  msx = bounds.width;
  msy = bounds.height;
}

sf::Vector2i Label::draw() {
  text.setPosition(mpx, mpy);
  assert(mwindow);
  mwindow->draw(text);
  return getDimens();
}
