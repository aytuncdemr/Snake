#include "Game.hpp"

Game::Game(const uint32_t &window_width, const uint32_t &window_height, const std::string &window_title):m_window{sf::VideoMode(window_width,window_height),window_title,sf::Style::Close | sf::Style::Titlebar}{

    std::cout << "[Game window initialized with " << window_width << "x" << window_height << "]" << std::endl;

}

void Game::start(){

    std::cout << "[Starting Game]" << std::endl;

    main_loop();

}

void Game::draw(){

    m_window.clear();



    m_window.display();

}

void Game::main_loop(){

    while(m_window.isOpen()){

        handle_events();


        draw();

    }

}

void Game::close(){

    std::cout << "[Closing Game]" << std::endl;

    m_window.close();

}

void Game::handle_events(){

    while(m_window.pollEvent(m_event)){

        switch (m_event.type){

            case sf::Event::Closed:

                close();

                break;
            
           default:
        
        
                break;
    
        }    

    }

}