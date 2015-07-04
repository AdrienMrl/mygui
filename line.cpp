#include "widgets.hh"

Line::Line(int px, int py, int lenght, int rot, Widget *parent) :
    Rectangle(lenght, 5, px, py, parent) {
    rect.rotate(rot);
}
