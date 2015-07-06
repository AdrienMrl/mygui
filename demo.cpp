#include "gui.hh"
#include "widgets.hh"
#include <iostream>

static void onMouseDown(Widget *, sf::Vector2i unused) {
	(void)unused;
	std::cout << "mouse down !" << std::endl;
}

static void onClicked(Widget *) {
	std::cout << "clicked !" << std::endl;
}

int main()
{
  static GUI app(2);

  Window *window = app.getWindow();

  
  Rectangle *rectangle = new Rectangle(100, 100, 100, 100, window);
  Label *test = new Label(10, 20, "I'm a label. And i'm long", rectangle);
  test->setText("Foooooo");
  new Label(130, 200, "i'm very very long", rectangle);
  Label *green_lab = new Label(700, 220, "GREEEEEEN", rectangle);
  green_lab->setColor(sf::Color(0, 255, 0));

  test->setOnMouseDownListener(onMouseDown);

  Point *p = new Point(500, 900, window);
  p->setColor(sf::Color(255, 0, 0));

  Button *button = new Button(1300, 700, "Click me", window);
  button->setOnClickedListener(onClicked);
  button->setOnMouseMoveListener(onMouseDown);
  button->setSize(300, 200);

  Line *l = new Line(900, 900, 100, 45, window);
  l->setColor(sf::Color::Red);
  

  Picture *pic = new Picture(600, 500, 440, 260, "dog.jpg", window);
  pic->setRepeated(true);

  Timer *timer = new Timer(1000, app);
  timer->setOnClickedListener(onClicked);

  new ScrollBar(30, 200, 1200, 200, ScrollBar::VERTICAL, window);
  new ScrollBar(200, 30, 1500, 300, ScrollBar::HORIZONTAL, window);

  new Triangle(20, 10, 300, 200, 10, 220, window);

  new TextBox(10, 10, button, "password");
  return app.execute();
}
