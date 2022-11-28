#include "ButtonText.hpp"

ButtonText::ButtonText(const uint32_t &x_position,const uint32_t &y_position,const std::string &button_text,const sf::Color &text_color,const uint32_t &character_size){

    ButtonText_count++;

    if(ButtonText_count == 1){

        font.loadFromFile("./Data/Milky Honey.ttf");

    }    

    m_button_Text.setFont(font);

    m_button_Text.setString(button_text);

    m_button_Text.setCharacterSize(character_size);

    m_button_Text.setColor(text_color);

    m_button_Text.setPosition(x_position,y_position);

}