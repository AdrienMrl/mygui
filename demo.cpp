#include "gui.hh"
#include "widgets.hh"
#include <iostream>

static void onMouseDown(sf::Vector2i unused) {
	(void)unused;
	std::cout << "mouse down !" << std::endl;
}

static void onClicked() {
	std::cout << "clicked !" << std::endl;
}

int main()
{
  static GUI app("demo app");

  /*
  Rectangle *rectangle = new Rectangle(10, 900, 100, 100, &app.base);
  Label *test = new Label(10, 20, "I'm a label. And i'm long", rectangle);
  new Label(130, 200, "i'm very very long", rectangle);
  Label *green_lab = new Label(700, 220, "GREEEEEEN", rectangle);
  green_lab->setColor(sf::Color(0, 255, 0));

  test->setOnMouseDownListener(onMouseDown);

  Point *p = new Point(500, 900, &app.base);
  p->setColor(sf::Color(255, 0, 0));

  Button *button = new Button(800, 100, "Click me", &app.base);
  button->setOnClickedListener(onClicked);

  new Line(900, 900, 100, 45, &app.base);

  Picture *pic = new Picture(1900, 2000, 440, 660, "dog.jpg", &app.base);
  pic->setRepeated(true);

  Timer *timer = new Timer(1000, app);
  timer->setOnClickedListener(onClicked);

  */
  new RadioButton(1000, 200, &app.base);
  return app.execute();
}
