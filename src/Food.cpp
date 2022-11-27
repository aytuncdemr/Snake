#include "Food.hpp"

Food::Food():m_shape{sf::Vector2f{30,30}}{

    food_count++;

    if(food_count == 1)
        m_texture.loadFromFile("./Data/apple.png");


    m_shape.setPosition(rand()%1400,rand()%800);
    m_shape.setTexture(&m_texture);

}

void Food::draw_to(sf::RenderWindow &target_window){

    target_window.draw(m_shape);

}