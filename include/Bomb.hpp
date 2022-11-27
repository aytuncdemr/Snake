#ifndef _BOMB_HPP_
#define _BOMB_HPP_

#include <SFML/Graphics.hpp>

class Bomb{

    friend class Game;

    sf::RectangleShape m_shape;

    static inline sf::Texture m_texture;

    static inline int bomb_count {0};

    uint32_t m_life_span;

    sf::Clock m_life_span_clock;

    public:

        Bomb();

        void draw_to(sf::RenderWindow &target_window);

        bool is_life_span_end();

};

#endif