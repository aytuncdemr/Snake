#ifndef _MENU_HPP_
#define _MENU_HPP_

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "Button.hpp"

class Menu{

    sf::RenderWindow m_window;

    sf::Event m_event;

    std::vector<Button> m_buttons;

    bool m_is_multiplayer_menu_created {false};

    public:

        Menu();

        void launch();

        void create_exit_button();
        void create_single_player_button();

        void check_button_clicked();

        void create_back_button();

        void create_buttons();

        void draw_main_menu_buttons();

        void close();

};

#endif