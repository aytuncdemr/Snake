#ifndef _BUTTON_HPP_
#define _BUTTON_HPP_

#include <SFML/Graphics.hpp>

#include "ButtonText.hpp"

class Button{

    sf::RectangleShape m_button_shape;

    uint32_t m_button_type;

    ButtonText m_button_text;

    static inline sf::RenderWindow *c_target_window;

    public:

        Button(const uint32_t &x_position,const uint32_t &y_position,const uint32_t &button_width,const uint32_t &button_height,const sf::Color &button_color,const ButtonText &button_text,const uint32_t &button_type);

        uint32_t get_button_type();

        bool is_clicked();

        void draw_to(sf::RenderWindow &target_window);

        static void set_button_target_window(sf::RenderWindow &target_window);

};

#endif