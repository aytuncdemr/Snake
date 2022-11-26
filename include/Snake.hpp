#ifndef _SNAKE_HPP_
#define _SNAKE_HPP_

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

enum class Direction{

    UP,
    DOWN,
    LEFT,
    RIGHT

};

class Snake{

    std::vector <sf::RectangleShape> m_shapes;

    Direction m_current_direction;

    uint32_t m_speed;

    public:

        Snake();

        void create_head_shape();

        void draw_to(sf::RenderWindow &target_window);

        void move();

        void set_direction();

};

#endif