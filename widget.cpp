#include "widgets.hh"
#include <iostream>

Widget::Widget(int sx, int sy, int px, int py, Widget *parent) :
  msx(sx), msy(sy), mpx(px), mpy(py), mwindow(NULL)
{
     setParent(parent);
}

void Widget::setWindow(sf::RenderWindow* w) {
  mwindow = w;
}

sf::Vector2i Widget::getPosRelative() const {
  sf::Vector2i dim = getDimens();
  return sf::Vector2i(mpx - parent->getX(),
                      mpy - parent->getY());
}

sf::Vector2i Widget::getDimens() const {

  sf::Vector2i biggestChild(msx, msy);

  for (Widget *child : children) {
    sf::Vector2i dim = child->getDimens();
    dim += child->getPosRelative();
    if (dim.x > biggestChild.x)
      biggestChild.x = dim.x;
    if (dim.y > biggestChild.y)
      biggestChild.y = dim.y;
  }

  return biggestChild;
}

void Widget::setParent(Widget *parent) {
  if (parent == NULL)
    return;
  this->parent = parent;
  parent->addWidget(this);
  mpx += parent->getX();
  mpy += parent->getY();
}

void Widget::addWidget(Widget *w) {
  w->setWindow(mwindow);
  children.push_front(w);
}

sf::Vector2i Widget::draw() {

  for (Widget *child : children)
    child->draw();
  return getDimens();
}

void Widget::onClick(sf::Vector2i pos) {
	if (mOnMouseDownListener)
		mOnMouseDownListener();
}

void Widget::onEvent(sf::Event e) {

	for (Widget *child : children)
		child->onEvent(e);

	if (e.type == sf::Event::MouseButtonPressed) {

		sf::Event::MouseButtonEvent mouse = e.mouseButton;

		if (mouse.x <= mpx + getDimens().x && mouse.x >= mpx &&
			mouse.y <= mpy + getDimens().y && mouse.y >= mpy)
			onClick(sf::Vector2i(mouse.x, mouse.y));
	}
}

void Widget::setOnMouseDownListener(void (*ptr)(void)) {
    mOnMouseDownListener = ptr;
}
