
#ifndef ENGINE_H
#define ENGINE_H

class Engine
{
public:
    Engine(int r = 50, int c = 50);     // constructor with parameters with default values
    virtual ~Engine();
    Engine(const Engine& other) = delete;       // deleted coping constructor and assignment operator to prevent unauthorized uses
    Engine& operator=(const Engine& other) = delete;

    int getRows();      // standard getter methods, setter methods are not implemented to prevent changing array size
    int getColumns();

    bool getCellStatus(int r, int c);       // method that returns particular cells status
    void setCellStatus(int r, int c, bool status);      // method that sets particular cell status to chosen by user

protected:
    void Initialize(bool **arr);        // method that initialize living cells
    void updateStatus();        // method that updates whole array
    void clearArrays();         // method that sets all cells dead

private:
    enum class position         // enumerator with possible cells positions
    {
        LEFT_UP_CORNER,
        RIGHT_UP_CORNER,
        LEFT_DOWN_CORNER,
        RIGHT_DOWN_CORNER,
        UP_BORDER,
        DOWN_BORDER,
        RIGHT_BORDER,
        LEFT_BORDER,
        CENTER,
    };
    int rows, columns;      // numbers of rows and columns on game board
    bool **cellsArray;          // main array
    bool **tempArray;           // array to contains status changes
    void updateStatus(int r, int c);        // method that updates particular cell
    position checkPosition(int r, int c);       // method that checks where is located cell on the game board
    int checkNeighbours(int r, int c);      // method that counts living neighbours of particular cell
    void copyArrays(bool **src, bool **dest);       // simple method to copy statuses from temporary array to main
};

#endif // ENGINE_H
