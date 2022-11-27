#ifndef _GAME_HPP_
#define _GAME_HPP_

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

#include "Snake.hpp"
#include "Bomb.hpp"
#include "Food.hpp"

class Game{

    sf::RenderWindow m_window;

    sf::Event m_event;

    Snake m_snake;

    std::vector<Food*> m_foods;
    std::vector<Bomb*> m_boombs;

    sf::Clock m_clock;

    bool is_game_over {false};

    uint32_t m_score;

    public:

        Game(const uint32_t &window_width,const uint32_t &window_height,const std::string &window_title);

        void start();

        void main_loop();

        void close();

        void draw();

        void draw_score();

        void update();

        void handle_events();

        void handle_mouse_events();

        void check_snake_eat_food();

        void spawn_food(bool non_stop = false);

        void check_snake_eat_bomb();

        void check_snake_out_of_bounds();

        void spawn_bomb(bool non_stop = false);

        void draw_game_over();

        void eatable_life_span_check();

        ~Game(){ 
            
            for(Food *&food:m_foods)
                    delete food;
        

        }

};

#endif