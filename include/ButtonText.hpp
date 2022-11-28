#ifndef _BUTTON_TEXT_HPP_
#define _BUTTON_TEXT_HPP_

#include <SFML/Graphics.hpp>

class ButtonText{

    friend class Button;

    sf::Text m_button_Text;

    static inline sf::Font font;

    static inline int ButtonText_count {0};

    public:

        ButtonText():ButtonText{0,0,"None",{0,0,0},0}{}

        ButtonText(const uint32_t &x_position,const uint32_t &y_position,const std::string &button_text,const sf::Color &text_color,const uint32_t &character_size = 32);

};

#endif