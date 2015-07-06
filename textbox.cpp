#include "widgets.hh"
#include <SFML/System/String.hpp>
#include <iostream>

TextBox::TextBox(int px, int py, Widget *parent, const std::string& text)
    : Rectangle(0, 0, px, py, parent),
      label(0, 0, text, this)
{
}

void TextBox::OnTextEntered(sf::Uint32 unicode)
{
    if (unicode == 8) // backspace
        return;
    label.setText(sf::String(label.getText()) + unicode);
}

void TextBox::OnKeyPressed(sf::Keyboard::Key k)
{
    if (k == sf::Keyboard::BackSpace)
    {
        sf::String text = label.getText();
        text = text.substring(0, text.getSize() - 1);
        label.setText(text);
    }
}
