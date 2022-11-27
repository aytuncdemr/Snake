#include "Game.hpp"

Game::Game(const uint32_t &window_width, const uint32_t &window_height, const std::string &window_title):m_window{sf::VideoMode(window_width,window_height),window_title,sf::Style::Close | sf::Style::Titlebar}{

    m_window.setFramerateLimit(120);

    std::cout << "[Game window initialized with " << window_width << "x" << window_height << "]" << std::endl;

}

void Game::start(){

    std::cout << "[Starting Game]" << std::endl;

    for(int x{0};rand()%20;x++)
        spawn_food(true);

    main_loop();

}

void Game::spawn_food(bool non_stop){

    static sf::Clock last_spawn_time;

    static int rand_next_spawn_time = rand() % 2000;

    if(last_spawn_time.getElapsedTime().asMilliseconds() > rand_next_spawn_time or non_stop){

        rand_next_spawn_time = rand() % 2000;

        last_spawn_time.restart();

        m_foods.push_back(new Food{});

    }

}

void Game::draw(){

    m_window.clear();

    m_snake.draw_to(m_window);

    for(Food *&food:m_foods)
        food->draw_to(m_window);

    m_window.display();

}

void Game::main_loop(){

    while(m_window.isOpen()){

        handle_events();

        spawn_food();

        check_snake_eat_food();

        draw();

    }

}

void Game::close(){

    std::cout << "[Closing Game]" << std::endl;

    m_window.close();

}

void Game::check_snake_eat_food(){

    sf::Vector2f head_pos = m_snake.m_shapes[0].getPosition();

    for(int x{0};x<m_foods.size();x++){

        sf::Vector2f food_pos = m_foods[x]->m_shape.getPosition();

        if(head_pos.x >= food_pos.x && head_pos.x < food_pos.x + 33)
            if(head_pos.y >= food_pos.y && head_pos.y < food_pos.y + 33){

                std::cout << "[Score +100]" << std::endl;
            
                m_snake.expand();

                m_foods.erase(m_foods.begin()+x);

            }

        else if(head_pos.x+20 >= food_pos.x && head_pos.x+20 < food_pos.x + 33)
            if(head_pos.y+20 >= food_pos.y && head_pos.y+20 < food_pos.y + 33){

                std::cout << "[Score +100]" << std::endl;
            
                m_snake.expand();

                m_foods.erase(m_foods.begin()+x);

            }


    }

}

void Game::handle_events(){

    while(m_window.pollEvent(m_event)){

        switch (m_event.type){

            case sf::Event::KeyPressed:

                if(m_event.key.code == sf::Keyboard::Key::Space)
                    m_snake.expand();

                break;

            case sf::Event::Closed:

                close();

                break;
            
           default:
        
        
                break;
    
        }    

    }

}