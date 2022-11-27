#include "Snake.hpp"

Snake::Snake():m_speed{5},m_current_direction{Direction(rand()%2+2)}{

    std::cout << "[Snake object created]" << std::endl;

    create_head_shape();

    expand();
    expand();
    expand();

}

void Snake::create_head_shape(){

    sf::RectangleShape head_shape{sf::Vector2f(20,20)};

    head_shape.setFillColor({183, 29, 255}); // <- rgb color of purple

    head_shape.setPosition({rand()%1300 + 100,rand()%700 + 100});

    m_shapes.push_back(head_shape);

}

void Snake::update(){

    if(!is_game_over){
    
        check_direction_update(); // <- checking for direction update before the drawing. (cizimden once yılanın yonunun degistigini kontrol etme)

        follow_each_other(); // <- following each other for animation. (animasyon için yılan bloklarının birbirini takip etmesi)

        move_head(); // <- updating snake's position before the drawing. (cizimden once yılanın pozisyonunu güncelleme)
        
    }

}

void Snake::draw_to(sf::RenderWindow &target_window){

    update();
    
    for(sf::RectangleShape &shape:m_shapes)
        target_window.draw(shape);

}

void Snake::check_direction_update(){

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){

        m_current_direction = Direction::UP;

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){

        m_current_direction = Direction::LEFT;
        
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){

        m_current_direction = Direction::DOWN;

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){

        m_current_direction = Direction::RIGHT;
        
    }

}

void Snake::expand(){

    sf::RectangleShape new_shape{sf::Vector2f(20,20)};

    sf::Vector2f new_shape_pos;

    int last_shape_index {m_shapes.size() - 1};

    switch(m_current_direction){

        case Direction::UP:

            new_shape_pos = m_shapes[last_shape_index].getPosition() + sf::Vector2f(0,20);

            break;

        case Direction::DOWN:

            new_shape_pos = m_shapes[last_shape_index].getPosition() + sf::Vector2f(0,-20);

            break;

        case Direction::LEFT:

            new_shape_pos = m_shapes[last_shape_index].getPosition() + sf::Vector2f(20,0);

            break;

        case Direction::RIGHT:

            new_shape_pos = m_shapes[last_shape_index].getPosition() + sf::Vector2f(-20,0);

            break;

        default:

            break;

    }

    new_shape.setPosition(new_shape_pos);

    new_shape.setFillColor({183, 29, 255}); // <- rgb color of purple

    m_shapes.push_back(new_shape);

}

void Snake::follow_each_other(){

    for(int x{m_shapes.size()-1};x > 0;x--){

        m_shapes[x].setPosition(m_shapes[x-1].getPosition());

    }


}

void Snake::move_head(){

    int movement_x {0};
    int movement_y {0};

    switch (m_current_direction){

        case Direction::UP:

            movement_y = -m_speed;

            break;

        case Direction::DOWN:

            movement_y = m_speed;

            break;

        case Direction::LEFT:

            movement_x = -m_speed;

            break;

        case Direction::RIGHT:

            movement_x = m_speed;

            break;

        default:

            break;

    }

    m_shapes[0].move({movement_x,movement_y});   

}