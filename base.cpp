#include "widgets.hh"
#include <iostream>

Base::Base(int sx, int sy, int px, int py, Widget *parent)
	: Widget(sx, sy, px, py, parent) {
}

void Base::focusNext() {
	focused = NULL;
	take(focus_idx, focused);
	focus_idx++;
	if (focused == NULL) {
		focus_idx = 0;
		take(focus_idx++, focused);
	}
}

const Widget* Base::getFocused() {
	return focused;
}

void Base::onKeyPressed(sf::Keyboard::Key key) {

	if (key == sf::Keyboard::Tab) {
		focusNext();
	}

	Widget::onKeyPressed(key);
}
