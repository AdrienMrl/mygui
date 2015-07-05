#include "widgets.hh"
#include <iostream>

static void goUp(Widget *w) {
    ScrollBar *sb = dynamic_cast<ScrollBar *>(w->getParent());

    sb->setProgress(sb->getProgress() - 10);
    sb->update();
}


static void goDown(Widget *w) {
    ScrollBar *sb = dynamic_cast<ScrollBar *>(w->getParent());

    sb->setProgress(sb->getProgress() + 10);
    sb->update();
}

ScrollBar::ScrollBar(int sx, int sy, int px, int py,
        ScrollBar::orientation orientation, Widget *parent)
    : Rectangle(sx, sy, px, py, parent),
      up(0, 0, 0, 0, "", this),
      down(0, 0, 0, 0, "", this),
      cursor(0, 0, 0, 0, this),
      morientation(orientation)
{
    if (orientation == VERTICAL)
    {
        up.setText("^");
        up.setPosition(0, 0);
        up.setSize(sx, 0);
        down.setText("v");
        down.setPosition(0, sy - 20);
        down.setSize(sx, 0);
        cursor.setSize(sx, 20);
    }
    else
    {
        up.setText("<");
        up.setSize(0, sy);
        up.setPosition(0, 0);
        down.setText(">");
        down.setPosition(sx - 20, 0);
        down.setSize(0, sy);
        cursor.setSize(20, sy);
    }

    cursor.setColor(sf::Color::Blue);
    update();

    up.setOnClickedListener(goUp);
    down.setOnClickedListener(goDown);
}

void ScrollBar::update()
{
    if (morientation == VERTICAL)
        cursor.setPosition(0, up.getDimens().y +
                (progress * (msy - (up.getDimens().y + down.getDimens().y + 10))
                 / 100));
    else
        cursor.setPosition(up.getDimens().x +
                (progress * (msx - (up.getDimens().x + down.getDimens().x))
                 / 100), 0);
}


int ScrollBar::getProgress() const
{
    return progress;
}

void ScrollBar::setProgress(int new_progress)
{
    if (new_progress >= 0 && new_progress <= 100)
        progress = new_progress;
    update();
}

void ScrollBar::OnMouseDown(sf::Vector2i pos)
{
    pos.x -= mpx;
    pos.y -= mpy;
    if (morientation == VERTICAL) {
        if (pos.y < up.getDimens().y || pos.y > msy - down.getDimens().y)
            return;
        setProgress(((float)pos.y / msy) * 100);
    }
    else {
        if (pos.x < up.getDimens().x || pos.x > msx - up.getDimens().x)
            return;
        setProgress(((float)pos.x / msx) * 100);
    }
}

