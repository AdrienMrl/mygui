#include "widgets.hh"
#include <iostream>

Picture::Picture(int sx, int sy, int px, int py,
        const std::string& path, Widget *parent) :
    Rectangle(sx, sy, px, py, parent) {
        texture.loadFromFile(path);
        texture.setRepeated(true);
        setColor(sf::Color(255, 255, 255, 255));
        rect.setTexture(&texture);
        setRepeated(false);
}

void Picture::setRepeated(bool repeated) {
    texture.setRepeated(repeated);
    rect.setTexture(&texture);
}

sf::Vector2i Picture::draw() {

    sf::Vector2i dimens = getDimens();
    rect.setTextureRect({0, 0, dimens.x, dimens.y});
    return Rectangle::draw();
}
