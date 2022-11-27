#ifndef _GAME_HPP_
#define _GAME_HPP_

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

#include "Snake.hpp"
#include "Food.hpp"

class Game{

    sf::RenderWindow m_window;

    sf::Event m_event;

    Snake m_snake;

    std::vector<Food*> m_foods;

    sf::Clock m_clock;

    public:

        Game(const uint32_t &window_width,const uint32_t &window_height,const std::string &window_title);

        void start();

        void main_loop();

        void close();

        void draw();

        void handle_events();

        void handle_mouse_events();

        void check_snake_eat_food();

        void spawn_food(bool non_stop = false);

        ~Game(){ 
            
            for(Food *&food:m_foods)
                    delete food;
        

        }

};

#endif