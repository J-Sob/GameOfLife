
#include "GameAPI.h"

GameAPI::GameAPI()
    : Game()
{
}

void GameAPI::Draw(sf::RenderWindow &window)
{
    window.clear(sf::Color::Black);     // clearing window (required before drawing stuff)

    cellWidth= window.getSize().x / getColumns();      // cells width and height are dependent on window size and numbers of columns and rows
    cellHeight= window.getSize().y / getRows();

    sf::Color DeadCell(128,128,128);        // colors of the cells
    sf::Color AliveCell(240,230,0);

    for(int i = 0; i < getRows(); i++)
    {
        for(int j = 0; j < getColumns(); j++)
        {
            sf::RectangleShape cell(sf::Vector2f(cellWidth,cellHeight));    // creating a rectangle that represents cell

            if(getCellStatus(i,j) == 1)     // setting color of the rectangle depending on the cell status
            {
                cell.setFillColor(AliveCell);
            }
            else
            {
                cell.setFillColor(DeadCell);
            }

            cell.setOutlineColor(sf::Color::White);
            cell.setOutlineThickness(1.f);
            cell.move(sf::Vector2f(i * cellWidth, j * cellHeight));     // moving each rectangle by the size of the cell so they don't interfere with eachother
            window.draw(cell);      // drawing a cell
        }
    }

    window.display();       // displaying drawn scene
}
void GameAPI::changeState(sf::RenderWindow &window){        // method gets mouse position and changes cell status that is located on current coordinates
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    if(std::fabs(mousePosition.x) <= window.getSize().x && std::fabs(mousePosition.y) <= window.getSize().y){   // if statement was supposed to capture only those coordinates that
        int r = mousePosition.x / cellHeight;   // calculating witch cell position in game array                    // were clicked inside the window but it doesn't quite work
        int c = mousePosition.y / cellWidth;
        setCellStatus(r,c,!getCellStatus(r,c));     // changing status of clicked cell to opposite of the current one
    }
}
