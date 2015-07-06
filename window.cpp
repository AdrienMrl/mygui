#include "widgets.hh"
#include "gui.hh"

Window::Window(int sx, int sy, int type, GUI& gui)
    : Widget(sx, sy, 0, 0, NULL)
{
    mwindow =
        new sf::RenderWindow(sf::VideoMode(sx, sy), "MyGui",
            type == 0 ? sf::Style::None : type == 1
                ? sf::Style::Titlebar
                : sf::Style::Default);
    gui.addWindow(this);
}

Window::Type Window::getType() const
{
    return WINDOW;
}

sf::RenderWindow *Window::getWindow() const
{
    return mwindow;
}

void Window::focusNext() {
	focused = NULL;
	int elem_number = take(focus_idx, focused);
	focus_idx += hasShift ? -1 : 1;
	if (focused == NULL) {
		focus_idx = hasShift ? elem_number - 1 : 0;
		take(focus_idx, focused);
		focus_idx += hasShift ? -1 : 1;
	}
}

const Widget* Window::getFocused() {
	return focused;
}

void Window::OnKeyReleased(sf::Keyboard::Key key) {
	if (key == sf::Keyboard::LShift)
		hasShift = false;
}

void Window::OnKeyPressed(sf::Keyboard::Key key) {

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

sf::Vector2i Window::draw()
{
    /*
    sf::Vector2i dimens = getDimens();

    mwindow->setSize(sf::Vector2u(dimens.x, dimens.y));
    */
    return Widget::draw();
}

