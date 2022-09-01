// 8 queens program
// I couldn't make it successfully, heuristic didn't work and trid to make it 2 level heuristic but like the knight tour program,
// I got stuck becuase I had to add a lot of redundant codes and my code wasn't efficient
#include <iostream>
#include <iomanip>
#include <array>

using namespace std;

const int grid{8};
array<array<int,grid + 1>,grid + 1> board{}; // (free cells: 0, queen cells:1, forbidden cells due to queens: 2, useless cells with subscript 0: 3)
array<array<int,grid + 1>,grid + 1> tempBoard{}; // auxiliary array to save board for later calculations
array<array<int,grid + 1>,grid + 1> elimination{}; // shows how many other cells are eliminated by placing queen to this cell (0 for occupied cells)
int lowestEliminationRow;
int lowestEliminationColumn;

int welcomePage();
void printBoard();
void clearBoard();
bool isRightMove(int row, int column);
void placeQueen(int row, int column);
bool isInRange(int row, int column);
bool isBoardStillFree();
void refreshBoard(); // calculate -1 cells (used after placing every queen)
bool checkForWin();
void boardToTempBoard();
void tempBoardtoBoard();
int singleCellEliminationCalc(int row, int column);
void EliminationArrayCalc();
void findAndSetLowestElimination();
void option1();
void option2();

int main(){
    int option{welcomePage()};
    switch(option){
        case 1:
            option1();
        break;
        case 2:
            option2();
        break;
        default:
            cout << "invalid option." << endl;
    }
}

int welcomePage(){
    clearBoard();
    cout << "welcome to 8 queens program." << endl;
    cout << "1. play by yourself" << endl;
    cout << "2. try to solve the problem with lowest elimination heruristic";
    cout << "\nchoose one of options above: ";
    int option;
    cin >> option;
    return option;
}

void printBoard(){
    cout << endl;
    cout << "board:" << endl;
    for(int row{1}; row <= grid; row++){
        for(int column{1}; column <= grid; column++){
            cout << setw(3) << board[row][column];
        }
        cout << endl;
    }
    cout << endl;
    cout << "elimination array:" << endl;
    for(int row{1}; row <= grid; row++){
        for(int column{1}; column <= grid; column++){
            cout << setw(3) << elimination[row][column];
        }
        cout << endl;
    }
}

void clearBoard(){
    for(int row{0}; row <= grid; row++){
        for(int column{0}; column <= grid; column++){
            if(0 == row || 0 == column){
                board[row][column] = 3;
            }else{
                board[row][column] = 0;
            }
        }
    }
}

bool isRightMove(int row, int column){
    if(0 == board[row][column]){
        return true;
    }
    return false;
}

void placeQueen(int row, int column){
    board[row][column] = 1;
    refreshBoard();
}

bool isInRange(int row, int column){
    if(row >= 1 && row <= grid && column >= 1 && column <= grid){
        return true;
    }
    return false;
}

bool isBoardStillFree(){
    for(int row{1}; row <= grid; row++){
        for(int column{1}; column <= grid; column++){
            if(0 == board[row][column]){
                return true;
            }
        }
    }
    return false;
}

void refreshBoard(){
    for(int row{1}; row <= grid; row++){
        for(int column{1}; column <= grid; column++){
            if(1 == board[row][column]){
                for(int i{1}; i <= grid; i++){
                    //changing same row values to 2:
                    if(0 == board[row][i]){
                        board[row][i] = 2;
                    }
                    //changing same column values to 2:
                    if(0 == board[i][column]){
                        board[i][column] = 2;
                    }
                    //changing diagonal values to 2:
                    if(isInRange(row + i, column + i) && 0 == board[row + i][column + i]){board[row + i][column + i] = 2;}
                    if(isInRange(row - i, column + i) && 0 == board[row - i][column + i]){board[row - i][column + i] = 2;}
                    if(isInRange(row + i, column - i) && 0 == board[row + i][column - i]){board[row + i][column - i] = 2;}
                    if(isInRange(row - i, column - i) && 0 == board[row - i][column - i]){board[row - i][column - i] = 2;}
                }

            }
        }
    }
}

bool checkForWin(){
    int counter{0};
    for(int row{1}; row <= grid; row++){
        for(int column{1}; column <= grid; column++){
            if(1 == board[row][column]){
                counter++;
            }
        }
    }
    if(8 == counter){
        return true;
    }
    return false;
}

void boardToTempBoard(){
    for(int row{0}; row <= grid; row++){
        for(int column{0}; column <= grid; column++){
            tempBoard[row][column] = board[row][column];
        }
    }
}

void tempBoardtoBoard(){
    for(int row{0}; row <= grid; row++){
        for(int column{0}; column <= grid; column++){
            board[row][column] = tempBoard[row][column];
        }
    }
}

int singleCellEliminationCalc(int row, int column){
    boardToTempBoard();
    placeQueen(row, column);
    int zerosBefore{0};
    int zerosAfter{0};
    for(int i{1}; i <= grid; i++){
        for(int j{1}; j <= grid; j++){
            if(0 == tempBoard[i][j]){
                zerosBefore++;
            }
            if(0 == board[i][j]){
                zerosAfter++;
            }
        }
    }
    tempBoardtoBoard();
    return zerosBefore - zerosAfter;
}

void EliminationArrayCalc(){
    for(int row{1}; row <= grid; row++){
        for(int column{1}; column <= grid; column++){
            if(isRightMove(row, column)){
                elimination[row][column] = singleCellEliminationCalc(row, column);
            }else{
                elimination[row][column] = 0;
            }
        }
    }
}

void findAndSetLowestElimination(){
    int lowest{64}; // just a big number
    int ties{0}; // in case we have multiple cells with the same lowest elimination
    for(int row{1}; row <= grid; row++){
        for(int column{1}; column <= grid; column++){
            if(0 != elimination[row][column]){
                if(elimination[row][column] < lowest){
                    ties = 1;
                    lowestEliminationRow = row;
                    lowestEliminationColumn = column;
                    lowest = elimination[row][column];
                }else if(elimination[row][column] == lowest){
                    ties++;
                }
            }
        }
    }
    // for(int tie{1}; tie <= ties; tie++){

    // }
}

void option1(){
    int row, column;
    while(isBoardStillFree()){
        cout << "enter next queen's row & column: ";
        cin >> row >> column;
        if(isRightMove(row, column)){
            placeQueen(row, column);
            EliminationArrayCalc(); // not necessary, I added this line to test it
            printBoard();
        }else{
            cout << "wrong place, try again. ";
        }
    }
    if(checkForWin()){
        cout << "\nWin!" << endl;
    }else{
        cout << "\nLose!" << endl;
    }
}

void option2(){
    while(isBoardStillFree()){
        findAndSetLowestElimination();
        placeQueen(lowestEliminationRow, lowestEliminationColumn);
        EliminationArrayCalc();
        printBoard();
        // system("pause");
    }
    // printBoard();
    if(checkForWin()){
        cout << "\nWin!" << endl;
    }else{
        cout << "\nLose!" << endl;
    }
}