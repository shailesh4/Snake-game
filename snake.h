
// Created by Silvina on 09.05.2019.
//

#ifndef UNTITLED3_SNAKE_H
#define UNTITLED3_SNAKE_H

#include <vector>
#include "Square.h"

class Snake {
public:
    enum Direction
    {
        Left,
        Right,
        Up,
        Down
    };

private:
    std::vector<sf::RectangleShape> squares;
    std::vector<Direction> directions;

public:
    Snake(int x_position, int y_position);

    Direction direction;

    bool move();
    void grow();
    void draw(sf::RenderWindow& window);
};


#endif //UNTITLED3_SNAKE_H
