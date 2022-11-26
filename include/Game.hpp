#ifndef _GAME_HPP_
#define _GAME_HPP_

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Snake.hpp"

class Game{

    sf::RenderWindow m_window;

    sf::Event m_event;

    Snake m_snake;

    public:

        Game(const uint32_t &window_width,const uint32_t &window_height,const std::string &window_title);

        void start();

        void main_loop();

        void close();

        void draw();

        void handle_events();

};

#endif