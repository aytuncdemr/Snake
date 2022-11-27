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

    friend class Game;

    std::vector <sf::RectangleShape> m_shapes;

    Direction m_current_direction;

    float m_speed;

    bool is_game_over {false};

    public:

        Snake();

        void create_head_shape();

        void draw_to(sf::RenderWindow &target_window);

        void move_head();

        void check_direction_update();

        void expand();

        void follow_each_other();

        void update();

};

#endif