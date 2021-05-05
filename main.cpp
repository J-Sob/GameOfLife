/*
    Game Of Life
    Author: Jakub Sobczynski
    Date: 22.04.2021

*/
#include <GameAPI.h>


int main()
{
    sf::RenderWindow window(sf::VideoMode(800,800),"Game of Life",sf::Style::Close);
    Game *gameoflife = new GameAPI();

    gameoflife->PlayGame(window);

    delete gameoflife;
    return 0;
}
