#include "widgets.hh"

CheckBox::CheckBox(int px, int py, const std::string& text, Widget *parent)
    : RadioButton(px, py, parent),
      label(0, 0, text, this), mText(text)
{
}

// TODO: put in widget
void CheckBox::computeDimens()
{
    sf::Vector2i label_dim = label.getDimens();
    msx = label_dim.x;
    msy = label_dim.y;
}

void CheckBox::setText(const std::string& text)
{
    label.setText(text);
}
