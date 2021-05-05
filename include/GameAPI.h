
#ifndef GAMEAPI_H
#define GAMEAPI_H

#include <Game.h>
#include <cmath>

class GameAPI : public Game
{
    public:
        GameAPI();
        virtual ~GameAPI() {};      // default destructor
        GameAPI(const GameAPI& other) = delete;
        GameAPI& operator=(const GameAPI& other) = delete;
        void Draw(sf::RenderWindow &window);        // method that draws game board in a window
        void changeState(sf::RenderWindow &window);     // method that changes status of clicked cell
    protected:

    private:
        float cellWidth, cellHeight;        // drawn cells width and height
};

#endif // GAMEAPI_H
