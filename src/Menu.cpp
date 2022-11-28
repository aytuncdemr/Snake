#include "Menu.hpp"

Menu::Menu():m_window{sf::VideoMode(1400,800),"Snake",sf::Style::Close | sf::Style::Titlebar}{

    m_window.setFramerateLimit(120);

    Button::set_button_target_window(m_window);

}

void Menu::create_single_player_button(){

    Button single_player_button (570,280,200,65,{255,0,0},ButtonText{628,290,"PLAY",{0,255,255},30},(int)ButtonType::SINGLEPLAYER);

    m_buttons.push_back(single_player_button);

}

void Menu::create_exit_button(){

    Button exit_button (570,380,200,65,{255,0,0},ButtonText{630,390,"EXIT",{0,255,255}},(int)ButtonType::EXIT);

    m_buttons.push_back(exit_button);

}

void Menu::create_buttons(){

    create_exit_button();

    create_single_player_button();

}

void Menu::close(){

    std::cout << "[Closing menu]" << std::endl;

    m_window.close();

}

void Menu::create_back_button(){

    Button join_game_button (570,380,200,65,{255,0,0},ButtonText{622,390,"BACK",{0,255,255}},(int)ButtonType::BACK);

    m_buttons.push_back(join_game_button);

}

void Menu::check_button_clicked(){

    for(Button &button:m_buttons){

        if(button.is_clicked()){

            switch((ButtonType)button.get_button_type()){

                case ButtonType::EXIT:

                    if(m_is_multiplayer_menu_created == false)
                        close();

                    break;

                case ButtonType::SINGLEPLAYER:

                    if(m_is_multiplayer_menu_created == false){

                        close();
                        
                        {
                        
                        Game game(1400,800,"Snake");

                        game.start();
                        
                        }

                    }

                    break;

                case ButtonType::BACK:

                    {

                        m_window.close();

                        system("Snake.exe");

                    }

                    break;

                default:

                    break;

            }

        }

    }

}

void Menu::launch(){

    create_buttons();

    while(m_window.isOpen()){

        while(m_window.pollEvent(m_event)){

            switch(m_event.type){
            
                case sf::Event::Closed:

                    m_window.close();

                    break;

                case sf::Event::MouseButtonPressed:

                    check_button_clicked();

                    break;

                default:

                    break;

            }

        }

        m_window.clear();

        draw_main_menu_buttons();

        m_window.display();

    }

}

void Menu::draw_main_menu_buttons(){

    if(m_is_multiplayer_menu_created == false)
        for(int x{1};x<2;x++)
            m_buttons[x].draw_to(m_window);

    m_buttons[0].draw_to(m_window);

}