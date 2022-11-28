#include "Button.hpp"

Button::Button(const uint32_t &x_position,const uint32_t &y_position,const uint32_t &button_width,const uint32_t &button_height,const sf::Color &button_color,const ButtonText &button_text,const uint32_t &button_type):m_button_type{button_type},m_button_text{button_text}{

    m_button_shape.setPosition(x_position,y_position);

    m_button_shape.setSize(sf::Vector2f(button_width,button_height));

    m_button_shape.setFillColor(button_color);

}

void Button::draw_to(sf::RenderWindow &target_window){

    target_window.draw(m_button_shape);

    target_window.draw(m_button_text.m_button_Text);

}

bool Button::is_clicked(){

    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){

        sf::Vector2f button_pos = m_button_shape.getPosition();

        sf::Vector2i mouse_pos = sf::Mouse::getPosition(*c_target_window);

        if(mouse_pos.x >= button_pos.x && mouse_pos.x <= button_pos.x + m_button_shape.getSize().x){

            if(mouse_pos.y >= button_pos.y && mouse_pos.y <= button_pos.y + m_button_shape.getSize().y){

                return true;

            }

        }

    }

    return false;
}

uint32_t Button::get_button_type(){

    return m_button_type;
}

void Button::set_button_target_window(sf::RenderWindow &target_window){

    c_target_window = &target_window;

}