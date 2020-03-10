//
/// / Created by Silvina on 09.05.2019.
//

#include "Snake.h"
#include <iostream>

Snake::Snake(int x_position, int y_position)
{
    squares.push_back(sf::RectangleShape(sf::Vector2f(30,30)));
    squares[0].setPosition(x_position, y_position); //FoodX, FoodY
    squares[0].setFillColor(sf::Color(223,82,134));
    squares[0].setOutlineColor(sf::Color::Black);
    direction = Up;
    directions.push_back(direction);
}

bool Snake::move() {
    directions.insert(directions.begin(),direction);
    directions.pop_back();
    const float speed = 30;
    for (int i = 0; i < squares.size(); i++)
    {
        switch(directions[i])
        {
            case Left:
                squares[i].move(sf::Vector2f(-speed,0));
                if(squares[0].getPosition().x < 25)
                {
                    return false;
                }
                break;
            case Right:
                squares[i].move(sf::Vector2f(speed,0));
                if(squares[0].getPosition().x > 745)
                {
                    return false;
                }
                break;
            case Up:
                squares[i].move(sf::Vector2f(0,-speed));
                if(squares[0].getPosition().y < 25)
                {
                    return false;
                }
                break;
            case Down:
                squares[i].move(sf::Vector2f(0,speed));
                if(squares[0].getPosition().y > 545)
                {
                    return false;
                }
                break;
        }
    }
    return true;
}

void Snake::draw(sf::RenderWindow &window)
{
    for(sf::RectangleShape& rect : squares)
    {
        window.draw(rect);
        std::cout << "Drawing an rectangle at: " << rect.getPosition().x << ", " << rect.getPosition().y << "\n";
    }
}

void Snake::grow(){
    squares.push_back(sf::RectangleShape(sf::Vector2f(30,30)));
    squares[squares.size()-1].setPosition(squares[squares.size()-2].getPosition());
    squares[squares.size()-1].setFillColor(sf::Color(223,82,134));
    squares[squares.size()-1].setOutlineColor(sf::Color::Black);
}