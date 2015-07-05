#include "widgets.hh"

CheckBox::CheckBox(int px, int py, const std::string& text, Widget *parent)
    : RadioButton(px, py, parent),
      label(RADIUS * 2 + 10, 0, text, this), mText(text)
{
}

// TODO: put in widget
void CheckBox::computeDimens()
{
    sf::Vector2i label_dim = label.getDimens();
    msx = RADIUS * 2 + 10 + label_dim.x;
    msy = RADIUS * 2;
}

void CheckBox::setText(const std::string& text)
{
    label.setText(text);
}
