#include "widgets.hh"

Line::Line(int pax, int pay, int pbx, int pby, Widget *parent)
    : Widget(pax, pay, pbx, pby, parent)
{
    line[0] = sf::Vertex(sf::Vector2f(pax, pay));
    line[1] = sf::Vertex(sf::Vector2f(pbx, pby));

    msx = pax - pbx;
    msy = pay - pby;
}

void Line::setColor(const sf::Color& c)
{
    Widget::setColor(c);
    line[0].color = c;
    line[1].color = c;
}

sf::Vector2i Line::draw()
{
    mwindow->draw(line, 2, sf::Lines);
    return Widget::draw();
}
