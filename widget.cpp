#include "widgets.hh"
#include <iostream>

Widget::Widget(int sx, int sy, int px, int py, Widget *parent) :
  msx(sx), msy(sy), mpx(px), mpy(py), mwindow(NULL), mColor(100, 100, 130, 100)
{
     setParent(parent);
}

void Widget::setWindow(sf::RenderWindow* w) {
  mwindow = w;
}

sf::Vector2i Widget::getPosRelative() const {

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

  sf::Vector2i dimens = getDimens();

  // draw the focused square
  if (parent && this == parent->getFocused()) {

	sf::RectangleShape border(sf::Vector2f(dimens.x + 10, dimens.y + 10));

	border.setPosition(mpx - 5, mpy - 5);
	border.setFillColor(sf::Color(100, 100, 100, 100));
	mwindow->draw(border);
  }

  return dimens;
}

const Widget *Widget::getFocused() {
	if (parent == NULL)
		return NULL;
	return parent->getFocused();
}

bool Widget::doCollide(int x, int y) const
{
    return x <= mpx + getDimens().x && x >= mpx &&
        y <= mpy + getDimens().y && y >= mpy;
}

void Widget::onEvent(sf::Event e) {

	for (Widget *child : children)
		child->onEvent(e);

	switch (e.type) {

		case sf::Event::MouseButtonReleased:
		case sf::Event::MouseButtonPressed: {

			sf::Event::MouseButtonEvent mouse = e.mouseButton;

			if (doCollide(mouse.x, mouse.y)) {
				if (e.type == sf::Event::MouseButtonReleased) {
					OnMouseUp(sf::Vector2i(mouse.x, mouse.y));
					OnClicked();
				}
				else
					OnMouseDown(sf::Vector2i(mouse.x, mouse.y));
			}
			break;
		}
        case sf::Event::MouseMoved: { 
            sf::Event::MouseMoveEvent mouse = e.mouseMove;
            if (doCollide(mouse.x, mouse.y))
               OnMouseMove(sf::Vector2i(mouse.x, mouse.y));
            break;
        }

		case sf::Event::KeyPressed: {
			OnKeyPressed(e.key.code);
			break;
		}

		case sf::Event::KeyReleased: {
										 OnKeyReleased(e.key.code);
	    }


		default: {
			break;
		}
	}
}

#define SET_LISTENER(name, param_type) \
	void Widget::set##name##Listener(void (*ptr)(Widget *, param_type)) { \
		m##name##Listener = ptr; \
	} \
	void Widget::name(param_type param) { \
		if (m##name##Listener) m##name##Listener(this, param); \
	}

#define SET_LISTENER_VOID(name) \
	void Widget::set##name##Listener(void (*ptr)(Widget *)) { \
		m##name##Listener = ptr; \
	} \
	void Widget::name() { \
		if (m##name##Listener) m##name##Listener(this); \
	}

SET_LISTENER(OnMouseDown, sf::Vector2i)
SET_LISTENER(OnMouseUp, sf::Vector2i)
SET_LISTENER(OnMouseMove, sf::Vector2i)
SET_LISTENER(OnKeyPressed, sf::Keyboard::Key)
SET_LISTENER(OnKeyReleased, sf::Keyboard::Key)
SET_LISTENER_VOID(OnClicked)

int Widget::take(int idx, Widget *&dest) {
	return take(idx, 0, dest);
}

int Widget::take(int idx, int pos, Widget *&dest)
{

	if (idx == pos)
	{
		dest = this;
		return 0;
	}

	pos++;

	for (Widget *child: children)
	{
		pos = child->take(idx, pos, dest);
		if (pos == 0)
			return pos;
	}
	return pos;
}

void Widget::setColor(const sf::Color& color)
{
	mColor = color;
}

void Widget::setPosition(int px, int py)
{
	int parpx = parent ? parent->getX() : 0;
	int parpy = parent ? parent->getY() : 0;

	mpx = parpx + px;
	mpy = parpy + py;
}

void Widget::setSize(int sx, int sy)
{
	msx = sx;
	msy = sy;
}
