#include "Game.hpp"

Game::Game(const uint32_t &window_width, const uint32_t &window_height, const std::string &window_title):m_window{sf::VideoMode(window_width,window_height),window_title,sf::Style::Close | sf::Style::Titlebar},m_score{0}{

    std::cout << "[Game window initialized with " << window_width << "x" << window_height << "]" << std::endl;

}

void Game::start(){

    m_window.setFramerateLimit(120);

    std::cout << "[Starting Game]" << std::endl;

    for(int x{0};rand()%20;x++)
        spawn_food(true);

    for(int x{0};rand()%10;x++)
        spawn_bomb(true);

    main_loop();

}

void Game::create_game_over_buttons(){

    Button retry_button (570,360,200,65,{255,0,0},ButtonText{620,370,"RETRY",{0,255,255},30},(int)ButtonType::RETRY);
    Button return_to_menu_button (570,440,200,65,{255,0,0},ButtonText{578,457,"RETURN MENU",{0,255,255},25},(int)ButtonType::RETURN_TO_MAIN_MENU);

    Button::set_button_target_window(m_window);

    m_buttons.push_back(retry_button);
    m_buttons.push_back(return_to_menu_button);
    
}

void Game::spawn_food(bool non_stop){

    static sf::Clock last_spawn_time;

    static int rand_next_spawn_time = rand() % 1000 - m_score / 10;

    if(last_spawn_time.getElapsedTime().asMilliseconds() > rand_next_spawn_time or non_stop){

        rand_next_spawn_time = rand() % 1000 - m_score / 10;

        last_spawn_time.restart();

        m_foods.push_back(new Food{});

    }

}

void Game::spawn_bomb(bool non_stop){

    static sf::Clock last_spawn_time;

    static int rand_next_spawn_time = rand() % 2000 - m_score / 10; 

    if(last_spawn_time.getElapsedTime().asMilliseconds() > rand_next_spawn_time or non_stop){

        rand_next_spawn_time = rand() % 2000 - m_score /10;

        last_spawn_time.restart();

        m_boombs.push_back(new Bomb{});

    }

}

void Game::check_snake_out_of_bounds(){

    sf::Vector2f head_pos = m_snake.m_shapes[0].getPosition();

    if(head_pos.x > 1400)
        head_pos.x = 0;        

    if(head_pos.x < 0)
        head_pos.x = 1400;

    if(head_pos.y < 0)
        head_pos.y = 800;

    if(head_pos.y > 800)
        head_pos.y = 0;

    m_snake.m_shapes[0].setPosition(head_pos);

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
    
    draw_score();

    m_window.display();

}

void Game::draw_score(){
    
    static bool font_loaded {false};

    sf::Text score_text;

    static sf::Font font;

    if(!font_loaded){
    
        font.loadFromFile("./Data/Milky Honey.ttf");
    
        font_loaded = true;

    }

    score_text.setCharacterSize(40);

    score_text.setFont(font);

    score_text.setString(std::string{"Score:"} + std::to_string(m_score));

    score_text.setFillColor({255,100,100});

    m_window.draw(score_text);

}

void Game::update(){

    if(!is_game_over){

        spawn_food();

        spawn_bomb();

        check_snake_eat_food();

        check_snake_eat_bomb();

        check_snake_out_of_bounds();

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
            
                m_score += 100;

                m_snake.expand();

                m_foods.erase(m_foods.begin()+x);

                m_snake.m_speed += 0.5f;

            }

        else if(head_pos.x+20 >= food_pos.x && head_pos.x+20 < food_pos.x + 33)
            if(head_pos.y+20 >= food_pos.y && head_pos.y+20 < food_pos.y + 33){
            
                m_score += 100;

                m_snake.expand();

                m_foods.erase(m_foods.begin()+x);

                m_snake.m_speed += 0.5f;

            }


    }

}

void Game::check_snake_eat_bomb(){

    sf::Vector2f head_pos = m_snake.m_shapes[0].getPosition();

    for(int x{0};x<m_boombs.size();x++){

        sf::Vector2f food_pos = m_boombs[x]->m_shape.getPosition();

        if(head_pos.x >= food_pos.x && head_pos.x < food_pos.x + 33)
            if(head_pos.y >= food_pos.y && head_pos.y < food_pos.y + 33){
                
                is_game_over = true;

                m_snake.is_game_over = true;

                create_game_over_buttons();

            }

        else if(head_pos.x+20 >= food_pos.x && head_pos.x+20 < food_pos.x + 33)
            if(head_pos.y+20 >= food_pos.y && head_pos.y+20 < food_pos.y + 33){

                is_game_over = true;

                m_snake.is_game_over = true;

                create_game_over_buttons();

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

    m_buttons[0].draw_to(m_window);
    m_buttons[1].draw_to(m_window);

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

            case sf::Event::MouseButtonPressed:

                handle_mouse_events();

                break;
            
           default:
        
        
                break;
    
        }    

    }

}

void Game::reset_game(){

    m_score = 0;

    is_game_over = false;

    m_clock.restart();

    m_snake.reset_snake();

}

void Game::handle_mouse_events(){

    for(Button &button:m_buttons){

        if(button.is_clicked()){

            switch((ButtonType)button.get_button_type()){

                case ButtonType::RETRY:

                    std::cout << "[Retry]" << std::endl;

                    reset_game();

                    break;

                case ButtonType::RETURN_TO_MAIN_MENU:

                    std::cout << "[Returned to main menu]" << std::endl;

                    close();

                    system("Snake.exe");

                    break;

            }

        }

    }

}