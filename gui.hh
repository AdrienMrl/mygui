#ifndef GUI_HH_
#define GUI_HH_

#include <SFML/Graphics.hpp>
#include <list>
#include "widgets.hh"

class Widget;

class GUI {

  public:
    GUI(const std::string& name = "");
    void addWidget(Widget *w);
    int execute();
    Widget base;

  private:
    sf::RenderWindow window;
};

#endif
