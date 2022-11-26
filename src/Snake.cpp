#include "Snake.hpp"

Snake::Snake(){

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

    for(sf::RectangleShape &shape:m_shapes)
        target_window.draw(shape);

}