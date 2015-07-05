#include "widgets.hh"
#include <iostream>

Base::Base(int sx, int sy, int px, int py, Widget *parent)
	: Widget(sx, sy, px, py, parent) {
}

void Base::focusNext() {
	focused = NULL;
	int elem_number = take(focus_idx, focused);
	focus_idx += hasShift ? -1 : 1;
	if (focused == NULL) {
		focus_idx = hasShift ? elem_number - 1 : 0;
		take(focus_idx, focused);
		focus_idx += hasShift ? -1 : 1;
	}
}

const Widget* Base::getFocused() {
	return focused;
}

void Base::OnKeyReleased(sf::Keyboard::Key key) {
	if (key == sf::Keyboard::LShift)
		hasShift = false;
}

void Base::OnKeyPressed(sf::Keyboard::Key key) {

	if (key == sf::Keyboard::Tab) {
		focusNext();
	} else if (key == sf::Keyboard::LShift) {
		hasShift = true;
	} else if (key == sf::Keyboard::Return) {
		if (focused)
			focused->OnClicked();
	} else if (key == sf::Keyboard::Escape) {
		focused = NULL;
		focus_idx = 0;
	}


	Widget::OnKeyPressed(key);
}
