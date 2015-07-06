#ifndef GUI_HH_
#define GUI_HH_

#include <SFML/Graphics.hpp>
#include <list>
#include "widgets.hh"

class Widget;
class Timer;

class GUI {

  public:
    GUI(int WindowType = 2);
    int execute();
	void addTimer(Timer *);
    void addWindow(Window *);
    Window *getWindow() const;

    std::list<Window *> windows;

  private:
	std::list<Timer *> timers;
};

#endif
