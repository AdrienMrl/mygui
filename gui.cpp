#include "gui.hh"
#include <SFML/System.hpp>
#include <iostream>


GUI::GUI(int type)
{
      windows.push_back(new Window(1920, 1080, type, *this));
}

Window *GUI::getWindow() const
{
    return windows.back();
}

void GUI::addTimer(Timer *t) {
	timers.push_back(t);
}

void GUI::addWindow(Window *w)
{
    windows.push_back(w);
}

int GUI::execute() {

  sf::Event event;

  sf::Time delay = sf::milliseconds(1000 / 30);

  for (;;)
  {
      sf::sleep(delay);
      for (Timer *t : timers)
          t->tick(delay);

      for (Window *w: windows)
      {
          while (w->getWindow()->pollEvent(event))
          {
              if (event.type == sf::Event::Closed) {
                  w->getWindow()->close();
                  windows.remove(w);
                  return 0;
              }
              else
                  w->onEvent(event);
          }
          w->getWindow()->clear(sf::Color(200, 200, 220));
          w->draw();
          w->getWindow()->display();
      }
  }

  /*

  while (window.isOpen()) {
	
	sf::sleep(delay);
	for (Timer *t : timers)
		t->tick(delay);

    while (window.pollEvent(event)) {

		if (event.type == sf::Event::Closed)
			window.close();
		else
			base.onEvent(event);
    }

	window.clear(sf::Color(200, 200, 220));
	base.draw();
	window.display();

  }
  */

  return 0;

}
