
#include "Engine.h"

Engine::Engine(int r, int c)    // constructor allocates dynamically both arrays
{
    this->rows = r;
    this->columns = c;
    this->cellsArray = new bool*[rows];
    this->tempArray = new bool*[rows];
    for(int i = 0; i < rows; i++){
        cellsArray[i] = new bool[columns];
        tempArray[i] = new bool[columns];
    }

    clearArrays();        // setting all cells to dead

    Initialize(cellsArray);     // initializing both arrays
    Initialize(tempArray);
}

Engine::~Engine()       // destructor deallocates pointers
{
    for(int i = 0; i < rows; i++){
        delete[] cellsArray[i];
        delete[] tempArray[i];
    }
    delete[] cellsArray;
    delete[] tempArray;
}

void Engine::updateStatus(){        // checking each cell in an array
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            updateStatus(i,j);
        }
    }
    copyArrays(tempArray,cellsArray);       // copying values
}

void Engine::updateStatus(int r, int c){
    int neighbours = checkNeighbours(r,c);
    if(cellsArray[r][c] == 1){
        if(neighbours < 2 || neighbours > 3)
            tempArray[r][c] = 0;
    }else if (cellsArray[r][c] == 0){
        if(neighbours == 3)
            tempArray[r][c] = 1;
    }
}

int Engine::checkNeighbours(int r, int c){  // I am aware of how big this block of code is but I'm not sure if it isn't actually more efficient than for loops
    int neighbours = 0;                                                                                                 // still, something to improve
    position pos = checkPosition(r,c);
    switch (pos){
    case position::LEFT_UP_CORNER:
        if(cellsArray[r][c+1] == 1) neighbours++;
        if(cellsArray[r+1][c] == 1) neighbours++;
        if(cellsArray[r+1][c+1] == 1) neighbours++;
        break;
    case position::RIGHT_UP_CORNER:
        if(cellsArray[r][c-1] == 1) neighbours++;
        if(cellsArray[r+1][c] == 1) neighbours++;
        if(cellsArray[r+1][c-1] == 1) neighbours++;
        break;
    case position::LEFT_DOWN_CORNER:
        if(cellsArray[r-1][c] == 1) neighbours++;
        if(cellsArray[r-1][c+1] == 1) neighbours++;
        if(cellsArray[r][c+1] == 1) neighbours++;
        break;
    case position::RIGHT_DOWN_CORNER:
        if(cellsArray[r-1][c] == 1) neighbours++;
        if(cellsArray[r-1][c-1] == 1) neighbours++;
        if(cellsArray[r][c-1] == 1) neighbours++;
        break;
    case position::UP_BORDER:
        if(cellsArray[r][c+1] == 1) neighbours++;
        if(cellsArray[r][c-1] == 1) neighbours++;
        if(cellsArray[r+1][c] == 1) neighbours++;
        if(cellsArray[r+1][c+1] == 1) neighbours++;
        if(cellsArray[r+1][c-1] == 1) neighbours++;
        break;
    case position::DOWN_BORDER:
        if(cellsArray[r][c+1] == 1) neighbours++;
        if(cellsArray[r][c-1] == 1) neighbours++;
        if(cellsArray[r-1][c] == 1) neighbours++;
        if(cellsArray[r-1][c+1] == 1) neighbours++;
        if(cellsArray[r-1][c-1] == 1) neighbours++;
        break;
    case position::LEFT_BORDER:
        if(cellsArray[r+1][c] == 1) neighbours++;
        if(cellsArray[r-1][c] == 1) neighbours++;
        if(cellsArray[r-1][c+1] == 1) neighbours++;
        if(cellsArray[r][c+1] == 1) neighbours++;
        if(cellsArray[r+1][c+1] == 1) neighbours++;
        break;
    case position::RIGHT_BORDER:
        if(cellsArray[r+1][c] == 1) neighbours++;
        if(cellsArray[r-1][c] == 1) neighbours++;
        if(cellsArray[r-1][c-1] == 1) neighbours++;
        if(cellsArray[r][c-1] == 1) neighbours++;
        if(cellsArray[r+1][c-1] == 1) neighbours++;
        break;
    case position::CENTER:
        if(cellsArray[r][c+1] == 1) neighbours++;
        if(cellsArray[r][c-1] == 1) neighbours++;
        if(cellsArray[r+1][c] == 1) neighbours++;
        if(cellsArray[r+1][c+1] == 1) neighbours++;
        if(cellsArray[r+1][c-1] == 1) neighbours++;
        if(cellsArray[r-1][c] == 1) neighbours++;
        if(cellsArray[r-1][c+1] == 1) neighbours++;
        if(cellsArray[r-1][c-1] == 1) neighbours++;
        break;
    }
    return neighbours;
}

int Engine::getRows(){
    return rows;
}

int Engine::getColumns(){
    return columns;
}

void Engine::Initialize(bool **arr){    // method initializes game board with glider pattern
    arr[1][2] = 1;
    arr[2][3] = 1;
    arr[3][3] = 1;
    arr[3][2] = 1;
    arr[3][1] = 1;
}

Engine::position Engine::checkPosition(int r, int c){   // returns position depending on where on the board is particular cell located
    if(r == 0 && c == 0) return position::LEFT_UP_CORNER;
    else if(r == 0 && c == columns - 1) return position::RIGHT_UP_CORNER;
    else if(r == rows - 1 && c == 0) return position::LEFT_DOWN_CORNER;
    else if(r == rows - 1 && c == columns - 1) return position::RIGHT_DOWN_CORNER;
    else if(r == 0 && (c > 0 && c < columns - 1)) return position::UP_BORDER;
    else if(r == rows - 1 && (c > 0 && c < columns - 1)) return position::DOWN_BORDER;
    else if(c == 0 && (r > 0 && r < rows - 1)) return position::LEFT_BORDER;
    else if(c == columns - 1 && (r > 0 && r < rows - 1)) return position::RIGHT_BORDER;
    else return position::CENTER;
}


void Engine::copyArrays(bool **src, bool **dest){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            dest[i][j] = src[i][j];
        }
    }
}

bool Engine::getCellStatus(int r, int c){
    return cellsArray[r][c];
}

void Engine::setCellStatus(int r, int c, bool status){
    cellsArray[r][c] = status;
    tempArray[r][c] = status;
}

void Engine::clearArrays(){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            cellsArray[i][j] = 0;
            tempArray[i][j] = 0;
        }
    }
}
