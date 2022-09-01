// 7.33 (Maze Traversal)
#include <iostream>
#include <iomanip>
#include <array>
#include <vector>
#include <algorithm> // for sort & binary_search

using namespace std;

// indexes are from 0 to grid * grid -1
// rows & columns are from 0 to grid - 1
const int grid{12}; // in a maze -1 = wall, 0 = empty space, 1 upward = X(steps of path incrementing on each step)
array<array<int, grid>, grid> maze1{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,0,0,-1,0,0,0,0,0,0,-1,0,0,-1,0,-1,0,-1,-1,-1,-1,0,-1,-1,-1,-1,0,-1,0,0,0,0,-1,0,-1,-1,0,0,0,0,-1,-1,-1,0,-1,0,0,-1,-1,-1,-1,0,-1,0,-1,0,-1,0,-1,-1,0,0,-1,0,-1,0,-1,0,-1,0,-1,-1,-1,0,-1,0,-1,0,-1,0,-1,0,-1,-1,0,0,0,0,0,0,0,0,-1,0,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,0,-1,-1,0,0,0,0,0,0,-1,0,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
array<array<int, grid>, grid> maze2{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,0,0,0,0,0,0,0,0,0,-1,-1,0,0,0,0,0,0,0,0,0,0,-1,-1,0,0,-1,-1,0,0,0,0,0,0,-1,-1,0,0,0,-1,0,0,0,0,0,0,-1,0,0,0,0,-1,0,0,0,0,0,0,-1,-1,-1,-1,-1,-1,-1,-1,0,0,0,0,-1,-1,0,0,0,0,0,-1,0,0,0,0,0,-1,0,0,0,0,0,-1,0,0,0,0,-1,-1,0,0,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,0,0,0,0,0,0,0,0,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
array<array<int, grid>, grid> maze3{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,0,-1,-1,-1,0,0,0,0,0,-1,0,0,0,0,0,-1,0,0,0,0,0,-1,-1,0,0,-1,-1,-1,0,0,0,0,0,-1,-1,0,0,0,0,-1,0,0,0,0,0,-1,-1,0,0,0,0,-1,0,0,0,0,0,0,-1,-1,-1,-1,0,-1,0,0,0,0,0,-1,-1,0,0,-1,0,-1,0,0,0,0,0,-1,-1,0,0,-1,0,-1,0,0,0,0,0,-1,-1,0,0,-1,0,-1,0,0,0,0,0,-1,-1,0,0,0,0,-1,0,0,0,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
enum class Direction{RIGHT, UP, LEFT, DOWN};
vector<int> ignoredStepsInPrint(0); // this vector is used to clear traversed route when we come back a part of it and some of Xs should be cleared. this vector has list of the steps that should not be X in printMaze

void printMaze(const array<array<int, grid>, grid>& maze); // converts maze numbers to corresponding #s and .s
int indexToRow(int index); // gives row of an index
int indexToColumn(int index); // gives column of an index
int rowAndColumnToIndex(int row, int column); // gives index of a row and column
bool isInsideBoard(const int& index); // checks whether an index is valid and inside the board
bool doesStepExist(const array<array<int, grid>, grid>& maze, const int& step); // checks whether a step exists in maze or not
int indexOfStepFunction(const array<array<int, grid>, grid>& maze, const int& step); // gives index of a step
Direction nextCounterclockwiseDirection(Direction d); // gets a direction and tells what will be next direction if we look counterclockwise
bool isDirectionPossible(const array<array<int, grid>, grid>& maze, const int& step, Direction testDirection); // checks whether is it possible to move in the testDirection from current step or not
int findNextMoveIndex(const array<array<int, grid>, grid>& maze, const int& startIndex, const int& endIndex, const int& step); // note: this function can only handle start points on the edge of table and if start point is one of the center cells i have to reimplement this function
void mazeTraverse(array<array<int, grid>, grid>& maze, const int& startIndex, const int& endIndex,const int& step = 0); // recursive function to solve the maze (default value for step argument is 0)


int main(){
    printMaze(maze1);
    mazeTraverse(maze1, 24, 59);

    printMaze(maze2);
    mazeTraverse(maze2, 60, 95);

    printMaze(maze3);
    mazeTraverse(maze3, 24, 71);

}

// these funcions are independent and don't use other functions:
void printMaze(const array<array<int, grid>, grid>& maze){
    cout << "   0 1 2 3 4 5 6 7 8 9 1011" << endl;
    for(int row{0}; row < grid; row++){
        cout << row << (row < 10 ? "  ": " ");
        for(int column{0}; column < grid; column++){
            if(0 == maze[row][column]){
                cout << ". ";
            }else if(-1 == maze[row][column]){
                cout << "# ";
            }else{ // clear unnecessary Xs for the useless traversed path:
                sort(ignoredStepsInPrint.begin(), ignoredStepsInPrint.end());
                if(binary_search(ignoredStepsInPrint.begin(), ignoredStepsInPrint.end(), rowAndColumnToIndex(row,column))){
                    cout << ". ";
                }else{
                    cout << "X ";
                }
            }
        }
        cout << endl;
    }
    cout << endl;
}

int indexToRow(int index){
    if(index < 0 || index > grid * grid - 1){
        cout << "wrong index for row" << endl;
    }
    return index / grid;
}

int indexToColumn(int index){
    if(index < 0 || index > grid * grid - 1){
        cout << "wrong index for column" << endl;
    }
    return index % grid;
}

int rowAndColumnToIndex(int row, int column){
    if(row < 0 || row > grid - 1){
        cout << "wrong row for index" << endl;
    }else if(column < 0 || column > grid - 1){
        cout << "wrong column for index" << endl;
    }
    return row * grid + column;
}

bool isInsideBoard(const int& index){
    if(index >= 0 && index <= grid * grid - 1){
        return true;
    }
    return false;
}

bool doesStepExist(const array<array<int, grid>, grid>& maze, const int& step){
    for(auto const& row : maze){
        for(auto const& column : row){
            if(column == step){
                return true;
            }
        }
    }
    return false;
}

int indexOfStepFunction(const array<array<int, grid>, grid>& maze, const int& step){
    for(int row{0}; row < grid; row++){
        for(int column{0}; column < grid; column++){
            if(maze[row][column] == step){
                return row * grid + column;
            }
        }
    }
    cout << "error! index of step not found." << endl;
    return -1;
}

Direction nextCounterclockwiseDirection(Direction d){
    switch(d){
        case Direction::RIGHT:
            return Direction::UP;
            break;
        case Direction::UP:
            return Direction::LEFT;
            break;
        case Direction::LEFT:
            return Direction::DOWN;
            break;
        case Direction::DOWN:
            return Direction::RIGHT;
            break;
        default:
            cout << "error on nextCounterclockwiseDirection function!" << endl;
            return d;
    }
}

// these functions use functions above:
bool isDirectionPossible(const array<array<int, grid>, grid>& maze, const int& step, Direction testDirection){
    int newIndex;
    int newRow;
    int newColumn;
    int lastStepIndex{indexOfStepFunction(maze, step)};
    int lastStepRow{indexToRow(lastStepIndex)};
    int lastStepColumn{indexToColumn(lastStepIndex)};
    if(Direction::RIGHT == testDirection){
        newIndex = lastStepIndex + 1;
        newRow = lastStepRow;
        newColumn = lastStepColumn + 1;
    }else if(Direction::DOWN == testDirection){
        newIndex = lastStepIndex + grid;
        newRow = lastStepRow + 1;
        newColumn = lastStepColumn;
    }else if(Direction::LEFT == testDirection){
        newIndex = lastStepIndex - 1;
        newRow = lastStepRow;
        newColumn = lastStepColumn - 1;
    }else if(Direction::UP == testDirection){
        newIndex = lastStepIndex - grid;
        newRow = lastStepRow - 1;
        newColumn = lastStepColumn;
    }else{
        cout << "error! wrong testDirection is passed to isDirectionPossible function." << endl;
    }
    if(newRow >= 0 && newRow < grid && newColumn >= 0 && newColumn < grid && (maze[newRow][newColumn] != -1)){
        return true;
    }else{
        return false;
    }
}

int findNextMoveIndex(const array<array<int, grid>, grid>& maze, const int& startIndex, const int& endIndex, const int& step){
    Direction firstDirectionToTest;
    Direction rightDirection;
    int lastStepIndex{indexOfStepFunction(maze, step)};
    int oneBeforeLastStepIndex{indexOfStepFunction(maze, step - 1)};
    int nextMoveIndex;
    if(0 == step){
        return startIndex;
    }else if(1 == step){
        if(lastStepIndex >= 1 && lastStepIndex < grid){ // up side
            firstDirectionToTest = Direction::LEFT;
        }else if(grid - 1 == indexToColumn(lastStepIndex)){ // right side
            firstDirectionToTest = Direction::UP;
        }else if(grid - 1 == indexToRow(lastStepIndex)){ // down side
            firstDirectionToTest = Direction::RIGHT;
        }else if(0 == indexToColumn(lastStepIndex)){ // left side
            firstDirectionToTest = Direction::DOWN;
        }else{
            cout << "error! findNextMoveIndex function cannot handle start points on center." << endl;
        }
    }else{
        if(lastStepIndex == oneBeforeLastStepIndex + 1){
            firstDirectionToTest = Direction::DOWN;
        }else if(lastStepIndex == oneBeforeLastStepIndex + grid){
            firstDirectionToTest = Direction::LEFT;
        }else if(lastStepIndex == oneBeforeLastStepIndex - 1){
            firstDirectionToTest = Direction::UP;
        }else if(lastStepIndex == oneBeforeLastStepIndex - grid){
            firstDirectionToTest = Direction::RIGHT;
        }else{
            cout << "error! 2 last steps are wrong for findNextMoveIndex function." << endl;
        }
    }
    for(int i{0}; i < 4; i++){
        if(isDirectionPossible(maze, step, firstDirectionToTest)){
            rightDirection = firstDirectionToTest;
            break;
        }
        firstDirectionToTest = nextCounterclockwiseDirection(firstDirectionToTest);
    }
    if(Direction::RIGHT == rightDirection){
        nextMoveIndex = lastStepIndex + 1;
    }else if(Direction::DOWN == rightDirection){
        nextMoveIndex = lastStepIndex + grid;
    }else if(Direction :: LEFT == rightDirection){
        nextMoveIndex = lastStepIndex - 1;
    }else if(Direction::UP == rightDirection){
        nextMoveIndex = lastStepIndex - grid;
    }else{
        cout << "error! wrong rightDirection on findNextMoveIndex function." << endl;
    }
    return nextMoveIndex;
}

void mazeTraverse(array<array<int, grid>, grid>& maze, const int& startIndex, const int& endIndex, const int& step){
    // cin.ignore(); // used to pause and see the result on each step
    int lastStepIndex{indexOfStepFunction(maze, step)};
    if(lastStepIndex == endIndex){
        printMaze(maze);
        cout << "Hooray! We did it." << endl;
        return;
    }
    if(0 == step){
        while(!ignoredStepsInPrint.empty()){
            ignoredStepsInPrint.pop_back();
        }
        maze[indexToRow(startIndex)][indexToColumn(startIndex)] = 1;
    }else{
        int rightMoveIndex = findNextMoveIndex(maze, startIndex, endIndex, step);
        if(step > 1 && maze[indexToRow(rightMoveIndex)][indexToColumn(rightMoveIndex)] > 0){
            for(int i{maze[indexToRow(rightMoveIndex)][indexToColumn(rightMoveIndex)] + 1}; i <= step; i++){
                if(doesStepExist(maze, i)){
                    ignoredStepsInPrint.push_back(indexOfStepFunction(maze, i)); 
                }
            }
        }
        maze[indexToRow(rightMoveIndex)][indexToColumn(rightMoveIndex)] = step + 1;
        if(rightMoveIndex == startIndex){
            printMaze(maze);
            cout << "This maze is unsolvable." << endl;
            return;
        }
    }
    // printMaze(maze);
    mazeTraverse(maze, startIndex, endIndex, step + 1);
}
