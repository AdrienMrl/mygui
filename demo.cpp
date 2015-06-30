#include "gui.hh"
#include "widgets.hh"
#include <iostream>

static void onMouseDown() {
	std::cout << "mouse down !" << std::endl;
}

int main()
{
  static GUI app("demo app");

  Rectangle *rectangle = new Rectangle(10, 900, 100, 100, &app.base);
  Label *test = new Label(10, 20, "I'm a label. And i'm long", rectangle);
  Label *test2 = new Label(100, 200, "i'm very very long", rectangle);
  test->setOnMouseDownListener(onMouseDown);

  return app.execute();
}
