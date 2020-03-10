//
// Created by Silvina on 09.05.2019.
//

#include <iostream>
#include "WindowManager.h"
#include  <windows.h>


WindowManager::WindowManager()
 : window(sf::VideoMode(800,600), "Snake game"), snake(400,300), background(sf::Vector2f(750,550)), gameClock(), toMove(false)
{
    background.setPosition(25,25);
    background.setFillColor(sf::Color(139,0,139));
}

void WindowManager::runApplication()
{
    sf::Time deltaTime;
    gameClock.getElapsedTime();
    while(window.isOpen())
    {
        deltaTime += gameClock.getElapsedTime();
        if(deltaTime.asSeconds() > 1000)
        {
            std::cout << "Delta time as seconds: " << deltaTime.asSeconds() << "\n";
            deltaTime = deltaTime.Zero;
            std::cout << "Delta time as seconds: " << deltaTime.asSeconds() << "\n";
            toMove = true;
            std::cout << "move";

        }
        sf::Event event;
        while (window.pollEvent(event)) {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window.close();

            handleEvent(event);
        }
       //food();
        // Moving the snake
        if(toMove == true)
        {
            toMove=false;
            if(snake.move() == false)
            {
                bool wasEnterPressed = false;
                window.clear(sf::Color(0,0,0));
                sf::Font font;
                font.loadFromFile("font.ttf");
                sf::Text text;
                text.setFont(font);
                text.setString("You lose!\nPress enter to start new game");
                text.setCharacterSize(50);
                text.setFillColor(sf::Color::White);
                text.setPosition(75,150);
                window.draw(text);
                window.display();
                for(;;)
                {
                    while (window.pollEvent(event)) {
                        // Close window : exit
                        if (event.type == sf::Event::Closed)
                            window.close();

                        if(event.type == sf::Event::KeyPressed) {
                            if (event.key.code == sf::Keyboard::Enter) {
                                wasEnterPressed = true;
                                break;
                            }
                        }
                    }
                    if(wasEnterPressed)
                    {
                        break;
                    }
                }
                snake = Snake(400,300);
            }
        }

        // Clear screen
        window.clear(sf::Color(0,0,0));
       // window.clear(sf::Color(139,0,139));

        // Draw current state
        draw();

        // Update the window
        window.display();
    }
}

void WindowManager::draw()
{
    window.draw(background);
    snake.draw(window);
    food.draw(window);
    //Sleep(10);
}

void WindowManager::handleEvent(sf::Event &event)
{
    if(event.type == sf::Event::KeyPressed)
    {
        if(event.key.code == sf::Keyboard::Left)
        {
            snake.direction = Snake::Direction::Left;
        }
        else if(event.key.code == sf::Keyboard::Right)
        {
            snake.direction = Snake::Direction::Right;
        }
        else if(event.key.code == sf::Keyboard::Up)
        {
            snake.direction = Snake::Direction::Up;
        }
        else if(event.key.code == sf::Keyboard::Down)
        {
            snake.direction = Snake::Direction::Down;
        }
    }
}

int WindowManager::getWidth() {
    return width;

}

int WindowManager::getHeight() {
    return height;
}
