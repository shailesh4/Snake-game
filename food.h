//
// Created by Silvina on 17.05.2019.
//

#ifndef UNTITLED3_FOOD_H
#define UNTITLED3_FOOD_H
#include <iostream>
#include "WindowManager.h"
//#include "Square.h"
#include <vector>


class Food{
private:
    sf::CircleShape Circle;

public:
    int  FoodX = rand()% 800;
    int  FoodY = rand()% 600;

    // bool getFoodLocation();

    Food ();
    void draw(sf::RenderWindow& window);
};


#endif //UNTITLED3_FOOD_H