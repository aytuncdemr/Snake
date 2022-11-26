#ifndef _SNAKE_HPP_
#define _SNAKE_HPP_

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

class Snake{

    std::vector <sf::RectangleShape> m_shapes;

    public:

        Snake();

        void create_head_shape();

        void draw_to(sf::RenderWindow &target_window);

};

#endif