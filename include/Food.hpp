#ifndef _FOOD_HPP_
#define _FOOD_HPP_

#include <SFML/Graphics.hpp>

class Food{

    friend class Game;

    sf::RectangleShape m_shape;

    static inline sf::Texture m_texture;

    static inline int food_count {0};

    uint32_t m_life_span;

    sf::Clock m_life_span_clock;

    public:

        Food();

        void draw_to(sf::RenderWindow &target_window);

        bool is_life_span_end();

};

#endif