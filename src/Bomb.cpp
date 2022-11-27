#include "Bomb.hpp"

Bomb::Bomb():m_shape{sf::Vector2f(30,30)},m_life_span{rand()%4000 + 3000}{

    bomb_count++;

    if(bomb_count == 1)
        m_texture.loadFromFile("./Data/bomb.png");

    m_shape.setPosition(rand()%1400,rand()%800);
    m_shape.setTexture(&m_texture);

}

void Bomb::draw_to(sf::RenderWindow &target_window){

    target_window.draw(m_shape);

}

bool Bomb::is_life_span_end(){


    return (m_life_span_clock.getElapsedTime().asMilliseconds() > m_life_span);
}