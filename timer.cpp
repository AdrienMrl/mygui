#include <iostream>
#include "gui.hh"
#include "widgets.hh"

Timer::Timer(int delayms, GUI& gui) :
    Widget(0, 0, 0, 0, &gui.base), timerDelay(delayms) {
    gui.addTimer(this);
}

void Timer::tick(sf::Time delay) {
    milisecToWait -= delay.asMilliseconds();
    if (milisecToWait <= 0) {
        OnClicked();
        milisecToWait = timerDelay;
    }
}
