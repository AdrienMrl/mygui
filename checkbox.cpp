#include "widgets.hh"

CheckBox::CheckBox(int px, int py, const std::string& text, Widget *parent)
    : Widget(0, 0, px, py, parent),
      label(0, 0, text, this), mText(text)
{
}

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

bool CheckBox::isChecked() const
{
    return checked;
}

void CheckBox::toggle()
{
    checked = !checked;
    update();
}

void CheckBox::setChecked(bool checked)
{
    this->checked = checked;
    update();
}

void CheckBox::update()
{
    label.setText(checked ? "x " + mText : "   " + mText);
}

sf::Vector2i CheckBox::draw()
{
    return Widget::draw();
}

void CheckBox::OnClicked()
{
    toggle();
}
