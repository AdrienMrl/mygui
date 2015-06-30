#ifndef WIDGETS_HH_
# define WIDGETS_HH_

#include <SFML/Graphics.hpp>
#include <list>

class Widget {

  public:
    Widget(int, int, int, int, Widget *);
    void setWindow(sf::RenderWindow*);
    void setParent(Widget *);
    virtual sf::Vector2i draw();
    virtual sf::Vector2i getDimens() const;
    int getX() const { return mpx; }
    int getY() const { return mpy; }
    sf::Vector2i getPosRelative() const;
    virtual void onClick(sf::Vector2i pos);
    void onEvent(sf::Event);

    void setOnMouseDownListener(void (*ptr)());

  protected:
    int msx, msy, mpx, mpy;
    sf::RenderWindow *mwindow;
    Widget* parent;
    std::list<Widget *> children;

    void (*mOnMouseDownListener)() = NULL;

    void addWidget(Widget *);
};

class Rectangle : public Widget {

  public:
    Rectangle(int, int, int, int, Widget *);
    virtual sf::Vector2i draw();

  protected:
    sf::RectangleShape rect;
};

class Label : public Widget {

  public:
    Label(int, int, const std::string& text, Widget *);
    virtual sf::Vector2i draw();
    void setText(const std::string&);
    void prepare();
    sf::Font font;

  protected:
    sf::Text text;
};

#endif
