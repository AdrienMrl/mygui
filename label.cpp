#include "widgets.hh"
#include <cassert>
#include <iostream>

Label::Label(int px, int py, const sf::String& txt, Widget *parent) :
	Widget(0, 0, px, py, parent)
{
	setText(txt);
	mColor = sf::Color(0, 0, 0);
}

void Label::setText(const sf::String& txt)
{
	text.setString(txt);
	font.loadFromFile("OpenSans-Regular.ttf");
	text.setFont(font);

	sf::FloatRect bounds = text.getGlobalBounds();
	msx = bounds.width + 5;
	msy = bounds.height + 15;
}

sf::Vector2i Label::draw()
{

	sf::Vector2i dimens = Widget::draw();

	text.setPosition(mpx, mpy);
	text.setColor(mColor);
	assert(mwindow);
	mwindow->draw(text);
	return dimens;
}
