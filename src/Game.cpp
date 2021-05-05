
#include "Game.h"

Game::Game()
    : Engine(50,50)
{
}

void Game::PlayGame(sf::RenderWindow &window)
{
    while(window.isOpen())      // standard SFML window loop
    {
        sf::Event event;
        while(window.pollEvent(event))  // loop to check particular events
        {
            if(event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape ))     // window closes after pressing X button
            {
                window.close();
            }
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))     // pressing LMB calls method to change state of clicked cell
            {
                changeState(window);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))     // pressing Space calls method that updates game board
            {
                updateStatus();
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::C))     // pressing C calls method that cleanes game board (kills all cells)
            {
                clearArrays();
            }
            Draw(window);       // drawing game board
        }
        //Draw(window);
        //sf::sleep(sf::milliseconds(1));
    }
}

