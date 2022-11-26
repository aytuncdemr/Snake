#include "Snake.hpp"

Snake::Snake():m_speed{5},m_current_direction{Direction(rand()%4)}{

    std::cout << "[Snake object created]" << std::endl;

    create_head_shape();

}

void Snake::create_head_shape(){

    sf::RectangleShape head_shape{sf::Vector2f(20,20)};

    head_shape.setFillColor({rand()%255,rand()%255,rand()%255});

    head_shape.setPosition({rand()%1300 + 100,rand()%700 + 100});

    m_shapes.push_back(head_shape);

}

void Snake::draw_to(sf::RenderWindow &target_window){

    set_direction(); // <- checking for direction update before the drawing. (cizimden once yılanın yonunun degistigini kontrol etme)

    move(); // <- updating snake's position before the drawing. (cizimden once yılanın pozisyonunu güncelleme)

    for(sf::RectangleShape &shape:m_shapes)
        target_window.draw(shape);

}

void Snake::set_direction(){

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

void Snake::move(){

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