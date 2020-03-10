//
// Created by Silvina on 09.05.2019.
//

#ifndef UNTITLED3_WINDOWMANAGER_H
#define UNTITLED3_WINDOWMANAGER_H


#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Snake.h"
#include "Food.h"


class WindowManager {
    sf::RenderWindow window;
    Snake snake;
    Food food;
    sf::RectangleShape background;
    sf::Clock gameClock;
    bool toMove;
    int width = 800;
    int height = 600;

public:
    WindowManager();

    void runApplication();
    void draw();
    void handleEvent(sf::Event& event);
    int getWidth();
    int getHeight();
};


#endif //UNTITLED3_WINDOWMANAGER_H
