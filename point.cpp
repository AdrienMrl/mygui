#include "widgets.hh"

Point::Point(int px, int py, Widget *parent)
    : Rectangle(1, 1, px, py, parent) {
}
