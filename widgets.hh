#ifndef WIDGETS_HH_
# define WIDGETS_HH_

#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <list>

class Widget {

  public:
    Widget(int, int, int, int, Widget *);
    void setWindow(sf::RenderWindow*);
    void setParent(Widget *);
	Widget *getParent() const { return parent; }
    virtual sf::Vector2i draw();
    virtual sf::Vector2i getDimens() const;
    int getX() const { return mpx; }
    int getY() const { return mpy; }
    sf::Vector2i getPosRelative() const;
    void onEvent(sf::Event);
	int take(int idx, Widget *&);
	virtual const Widget *getFocused();
	virtual void setColor(const sf::Color& color);
	virtual void setPosition(int px, int py);
	virtual void setSize(int sx, int sy);

    void setOnMouseDownListener(void (*ptr)(Widget *, sf::Vector2i));
    virtual void OnMouseDown(sf::Vector2i pos);
    void setOnMouseMoveListener(void (*ptr)(Widget *, sf::Vector2i));
    virtual void OnMouseMove(sf::Vector2i pos);
    void setOnMouseUpListener(void (*ptr)(Widget *, sf::Vector2i));
	virtual void OnMouseUp(sf::Vector2i);
    void setOnKeyPressedListener(void (*ptr)(Widget *, sf::Keyboard::Key key));
	virtual void OnKeyPressed(sf::Keyboard::Key k);
    void setOnKeyReleasedListener(void (*ptr)(Widget *, sf::Keyboard::Key key));
	virtual void OnKeyReleased(sf::Keyboard::Key);
    void setOnClickedListener(void (*ptr)(Widget *));
	virtual void OnClicked();

  protected:
    int msx, msy, mpx, mpy;
    sf::RenderWindow *mwindow;
    Widget* parent;
    std::list<Widget *> children;
	sf::Color mColor;

    void (*mOnMouseDownListener)(Widget *, sf::Vector2i pos) = NULL;
    void (*mOnMouseUpListener)(Widget *, sf::Vector2i pos) = NULL;
    void (*mOnMouseMoveListener)(Widget *, sf::Vector2i pos) = NULL;
    void (*mOnKeyPressedListener)(Widget *, sf::Keyboard::Key) = NULL;
    void (*mOnKeyReleasedListener)(Widget *, sf::Keyboard::Key) = NULL;
    void (*mOnClickedListener)(Widget *) = NULL;

    void addWidget(Widget *);
	int take(int idx, int pos, Widget *&);
    bool doCollide(int x, int y) const;
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

class Base : public Widget {

	public:
		Base(int, int, int, int, Widget *);
		void OnKeyPressed(sf::Keyboard::Key);
		void OnKeyReleased(sf::Keyboard::Key);
		const Widget *getFocused();

	private:
		unsigned focus_idx = 0;
		Widget *focused = NULL;

		bool hasShift = false;
		void focusNext();
};

class Point : public Rectangle {
	public:
		Point(int, int, Widget *);
};

class Button : public Rectangle {
	public:
		Button(int, int, const std::string&, Widget *);
		Button(int sx, int sy, int, int, const std::string&, Widget *);
		void OnMouseDown(sf::Vector2i);
		void OnMouseUp(sf::Vector2i);
		void setText(const std::string&);
		void setSize(int sx, int sy);

	protected:
		Label text;
		bool isPressed = false;
};

class Line : public Widget {
	public:
		Line(int, int, int, int, Widget *);
		sf::Vector2i draw();
        void setColor(const sf::Color&);

	protected:
		sf::Vertex line[2];
};

class Triangle : public Widget
{
    public:
        Triangle(int, int, int, int, int, int, Widget *);
        sf::Vector2i draw();

    protected:
        sf::ConvexShape triangle;
};

class Picture : public Rectangle {
	public:
		Picture(int, int, int, int, const std::string&, Widget *);
		void setRepeated(bool);
		sf::Vector2i draw();

	private:
		sf::Texture texture;

};

class GUI;

class Timer : public Widget {

	public:
		Timer(int, GUI&);
		void tick(sf::Time delay);

	private:
		int milisecToWait = 0;
		int timerDelay;

};

class RadioButton : public Widget
{
	public:
		RadioButton(int, int, Widget *);
		bool isChecked() const;
		void toggle();
		void setChecked(bool checked);
		void update();
		sf::Vector2i draw();
		void OnClicked();

		static const int RADIUS = 15;

	protected:
		bool checked = false;
		sf::CircleShape circle;

};

class CheckBox : public RadioButton
{

	public:
		CheckBox(int, int, const std::string&, Widget *);
		void setText(const std::string&);
		void computeDimens();

    protected:
		Label  label;
		std::string mText;
};

class ScrollBar : public Rectangle
{
	public:

		enum orientation {
			HORIZONTAL,
			VERTICAL
		};

		ScrollBar(int, int, int, int,
				ScrollBar::orientation orientation, Widget *);
		int getProgress() const;
		void update();
		void setProgress(int);
		virtual void OnMouseDown(sf::Vector2i pos);

	protected:
		Button up;
		Button down;
		Rectangle cursor;
		int progress = 50;
		orientation morientation;
};

#endif
