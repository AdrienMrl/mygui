#include "gui.hh"
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

  while (window.isOpen()) {
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
