#include "Game.hpp"

Game::Game(const uint32_t &window_width, const uint32_t &window_height, const std::string &window_title):m_window{sf::VideoMode(window_width,window_height),window_title,sf::Style::Close | sf::Style::Titlebar}{

    m_window.setFramerateLimit(120);

    std::cout << "[Game window initialized with " << window_width << "x" << window_height << "]" << std::endl;

}

void Game::start(){

    std::cout << "[Starting Game]" << std::endl;

    for(int x{0};rand()%20;x++)
        spawn_food(true);

    for(int x{0};rand()%10;x++)
        spawn_bomb(true);

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

void Game::spawn_bomb(bool non_stop){

    static sf::Clock last_spawn_time;

    static int rand_next_spawn_time = rand() % 2000;

    if(last_spawn_time.getElapsedTime().asMilliseconds() > rand_next_spawn_time or non_stop){

        rand_next_spawn_time = rand() % 2000;

        last_spawn_time.restart();

        m_boombs.push_back(new Bomb{});

    }

}

void Game::draw(){

    m_window.clear({100,200,70});

    m_snake.draw_to(m_window);

    for(Food *&food:m_foods)
        food->draw_to(m_window);

    for(Bomb *&bomb:m_boombs)
        bomb->draw_to(m_window);

    if(is_game_over)
        draw_game_over();

    m_window.display();

}

void Game::update(){

    if(!is_game_over){

        spawn_food();

        spawn_bomb();

        check_snake_eat_food();

        check_snake_eat_bomb();

        eatable_life_span_check();
    
    }

}

void Game::main_loop(){

    while(m_window.isOpen()){

        handle_events();

        update();

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

void Game::check_snake_eat_bomb(){

    sf::Vector2f head_pos = m_snake.m_shapes[0].getPosition();

    for(int x{0};x<m_boombs.size();x++){

        sf::Vector2f food_pos = m_boombs[x]->m_shape.getPosition();

        if(head_pos.x >= food_pos.x && head_pos.x < food_pos.x + 33)
            if(head_pos.y >= food_pos.y && head_pos.y < food_pos.y + 33){
                
                m_boombs.erase(m_boombs.begin()+x);

                is_game_over = true;

                m_snake.is_game_over = true;

            }

        else if(head_pos.x+20 >= food_pos.x && head_pos.x+20 < food_pos.x + 33)
            if(head_pos.y+20 >= food_pos.y && head_pos.y+20 < food_pos.y + 33){

                m_boombs.erase(m_boombs.begin()+x);

                is_game_over = true;

                m_snake.is_game_over = true;

            }


    }

}

void Game::eatable_life_span_check(){

    for(int x{0};x<m_foods.size();x++){

        if(m_foods[x]->is_life_span_end())
            m_foods.erase(m_foods.begin()+x);

    }

    for(int x{0};x<m_boombs.size();x++){
        
        if(m_boombs[x]->is_life_span_end())
            m_boombs.erase(m_boombs.begin()+x);

    }


}

void Game::draw_game_over(){

    static bool font_loaded {false};

    sf::Text game_over_text;

    static sf::Font font;

    if(!font_loaded){
    
        font.loadFromFile("./Data/Milky Honey.ttf");
    
        font_loaded = true;

    }

    game_over_text.setCharacterSize(40);

    game_over_text.setFont(font);

    game_over_text.setString("Game Over!");

    game_over_text.setPosition({560,300});

    m_window.draw(game_over_text);

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