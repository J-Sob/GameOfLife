
#ifndef GAME_H
#define GAME_H

#include <Engine.h>
#include <SFML/Graphics.hpp>


class Game : public Engine
{
    public:
        Game();
        virtual ~Game() {};     // default destructor
        Game(const Game& other) = delete;   // deleting for the same reason as in Engine class
        Game& operator=(const Game& other) = delete;

        void PlayGame(sf::RenderWindow &window);    // main game loop, gets sf::Window as parameter
        virtual void Draw(sf::RenderWindow &window) = 0;
        virtual void changeState(sf::RenderWindow &window) = 0;

    protected:

    private:
};

#endif // GAME_H
