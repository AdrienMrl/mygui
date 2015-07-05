#include "widgets.hh"

Triangle::Triangle(int pax, int pay,
        int pbx, int pby,
        int pcx, int pcy, Widget *parent)
    : Widget(pax - pbx, pay - pby, pax, pay, parent)
{
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(pax, pay));
    triangle.setPoint(1, sf::Vector2f(pbx, pby));
    triangle.setPoint(2, sf::Vector2f(pcx, pcy));
}

sf::Vector2i Triangle::draw()
{
    triangle.setFillColor(mColor);
    mwindow->draw(triangle);
    return Widget::draw();
}
