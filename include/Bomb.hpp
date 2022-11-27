#ifndef _BOMB_HPP_
#define _BOMB_HPP_

#include <SFML/Graphics.hpp>

class Bomb{

    friend class Game;

    sf::RectangleShape m_shape;

    static inline sf::Texture m_texture;

    static inline int bomb_count {0};

    public:

        Bomb();

        void draw_to(sf::RenderWindow &target_window);

};

#endif