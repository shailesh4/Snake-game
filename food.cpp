//
// Created by Silvina on 17.05.2019.
//

#include "Food.h"
#include <time.h>
#include "WindowManager.h"


/*bool Food::getFoodLocation() {
    FoodX = rand()% 800;

    FoodY = rand()% 600; // Use a function access.

    squares.push_back(sf::RectangleShape(sf::Vector2f(30,30)));
    squares[0].setPosition(x_position, y_position); //FoodX, FoodY
    squares[0].setFillColor(sf::Color(223,82,134));
    squares[0].setOutlineColor(sf::Color::Black);

    return true;
}*/
Food::Food() {
    Circle.push_back(sf::CircleShape(12));
    Circle[0].setPosition(FoodX, FoodY);
    Circle[0].setFillColor(sf::Color(175, 0, 42));
    Circle[0].setOutlineColor(sf::Color::Black);
}
void Food::draw(sf::RenderWindow &window)
{
    //Food();
    for(sf::CircleShape& rect : Circle)
    {
        window.draw(rect);
        //std::cout << "Drawing a circle at: " << rect.getPosition().x << ", " << rect.getPosition().y << "\n";
    }
}
