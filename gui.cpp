#include "gui.hh"
#include <SFML/System.hpp>
#include <iostream>

GUI::GUI(const std::string& name)
  : base(1920, 1080, 0, 0, NULL),
   	window(sf::VideoMode(1920, 1080), name.c_str()) {
      base.setWindow(&window);
}

void GUI::addWidget(Widget *w) {
  w->setParent(&base);
}

int GUI::execute() {

  sf::Event event;

  sf::Time delay = sf::milliseconds(1000 / 30);

  while (window.isOpen()) {
	
	  sf::sleep(delay);
    while (window.pollEvent(event)) {

		window.clear(sf::Color(200, 200, 220));
		base.draw();
		window.display();

		if (event.type == sf::Event::Closed)
			window.close();
		else
			base.onEvent(event);
    }
  }

  return 0;
}
