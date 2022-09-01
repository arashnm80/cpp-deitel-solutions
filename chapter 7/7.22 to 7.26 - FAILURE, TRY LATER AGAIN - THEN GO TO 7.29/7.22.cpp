// exercise 7.22 knight's tour
// note: all parts done except section d (i left it because of shortage of time and getting a little harder & messier)
// I coudn't make it 2 level heuristic because my code wasn't made on robust basis and doing this required a lot of 
// reduntant and bad code
#include <iostream>
#include <iomanip>
#include <array>

using namespace std;
const int grid{8}; // number of chess board rows & columns
const int totalPossibleMoves{8}; // tagged from 0 to 7
array<int, grid> horizontal{2,1,-1,-2,-2,-1,1,2};
array<int, grid> vertical{-1,-2,-2,-1,1,2,2,1};
array<array<int, grid + 1>, grid + 1> board{}; // start from subscript 1
array<array<int, grid + 1>, grid + 1> accessibility{}; // start from subscript 1
int currentRow, currentColumn;
int counter;
int winCounts{0};

int welcomeMessage();
void setStartPoint();
void setStartPoint(int row, int column);
void clearBoard();
void printBoard();
void move(int move);
bool validInsideBoardMove(int row, int column, int move);
void accessibilityCalc();

int main(){
    int option{welcomeMessage()};
    if(1 == option){
        setStartPoint();
        printBoard();
        int moveNumber;
        while(counter < grid * grid){
            cout << "enter next move number: ";
            cin >> moveNumber;
            if(validInsideBoardMove(currentRow, currentColumn, moveNumber)
            && 0 == board[currentRow + vertical[moveNumber]][currentColumn + horizontal[moveNumber]]){
                move(moveNumber);
                printBoard();
            }else{
                cout << "nonvalid move! try again." << endl;
            }
        }
    }else if(2 == option){
        setStartPoint();
        while(counter < grid * grid){
            int maxAccessibility{8};
            int rightMove{-1};
            for(int possibleMove{0}; possibleMove < totalPossibleMoves; possibleMove++){
                if( validInsideBoardMove(currentRow, currentColumn, possibleMove)
                && 0 == board[currentRow + vertical[possibleMove]][currentColumn + horizontal[possibleMove]]
                && accessibility[currentRow + vertical[possibleMove]][currentColumn + horizontal[possibleMove]] < maxAccessibility){
                    maxAccessibility = accessibility[currentRow + vertical[possibleMove]][currentColumn + horizontal[possibleMove]];
                    rightMove = possibleMove;
                }
            }
            if(-1 == rightMove){
                cout << "lose! game ended on counter: " << counter << endl;
                break;
            }else{
                // cout << "right move is: " << rightMove << endl;
                move(rightMove);
                // cout << "move " << counter << " happened." << endl;
            }
        }
        if(64 == counter){
            cout << "\ncongratulation, we won!\n" << endl;
        }
        printBoard();
    }else if(3 == option){
        for(int i{1}; i <= 8; i++){
            for(int j{1}; j <= 8; j++){
                setStartPoint(i, j);
                while(counter < grid * grid){
                    int maxAccessibility{8};
                    int rightMove{-1};
                    for(int possibleMove{0}; possibleMove < totalPossibleMoves; possibleMove++){
                        if( validInsideBoardMove(currentRow, currentColumn, possibleMove)
                        && 0 == board[currentRow + vertical[possibleMove]][currentColumn + horizontal[possibleMove]]
                        && accessibility[currentRow + vertical[possibleMove]][currentColumn + horizontal[possibleMove]] < maxAccessibility){
                            maxAccessibility = accessibility[currentRow + vertical[possibleMove]][currentColumn + horizontal[possibleMove]];
                            rightMove = possibleMove;
                        }
                    }
                    if(-1 == rightMove){
                        break;
                    }else{
                        move(rightMove);
                    }
                    if(64 == counter){
                        winCounts++;
                    }
                }
            }
        }
        cout << "win counts: " << winCounts << endl; // my code is not symmetric so win counts could be equal to any number even 63!
        // the not solved start pint is 4,3 (or 3, 4 - i don't remember well)
    }else if(4 == option){
        for(int i{1}; i <= 8; i++){
            for(int j{1}; j <= 8; j++){
                setStartPoint(i, j);
                while(counter < grid * grid){
                    int maxAccessibility{8};
                    int rightMove{-1};
                    for(int possibleMove{0}; possibleMove < totalPossibleMoves; possibleMove++){
                        if( validInsideBoardMove(currentRow, currentColumn, possibleMove)
                        && 0 == board[currentRow + vertical[possibleMove]][currentColumn + horizontal[possibleMove]]){
                            if(accessibility[currentRow + vertical[possibleMove]][currentColumn + horizontal[possibleMove]] < maxAccessibility){
                                maxAccessibility = accessibility[currentRow + vertical[possibleMove]][currentColumn + horizontal[possibleMove]];
                                rightMove = possibleMove;
                            }else if(accessibility[currentRow + vertical[possibleMove]][currentColumn + horizontal[possibleMove]] == maxAccessibility){
                                if(-1 == rightMove){
                                    rightMove = possibleMove;
                                }else{
                                    int move1{rightMove};
                                    int move2{possibleMove};

                                    int currentRow1{currentRow + vertical[move1]};
                                    int currentColumn1{currentColumn + horizontal[move1]};
                                    int place1{board[currentRow1][currentColumn1]};

                                    int currentRow2{currentRow + vertical[move2]};
                                    int currentColumn2{currentColumn + horizontal[move2]};
                                    int place2{board[currentRow2][currentColumn2]};
                                    
                                    int maxAccessibility1{9};
                                    int maxAccessibility2{9};
                                    for(int possibleMove1{0}; possibleMove1 < totalPossibleMoves; possibleMove1++){
                                        // I quit this exercise at this point, it is getting a little hard and a lot time consuming
                                    }
                                }
                            }
                        }
                    }
                    if(-1 == rightMove){
                        break;
                    }else{
                        move(rightMove);
                    }
                    if(64 == counter){
                        winCounts++;
                    }
                }
            }
        }
        cout << "win counts: " << winCounts << endl; // my code is not symmetric so win counts could be equal to any number even 63!
    }
}

int welcomeMessage(){
    cout << "welcome to knight tour program." << endl;
    cout << "1. play myself" << endl;
    cout << "2. set start point and see if heuristic can solve it" << endl;
    cout << "3. run heurstic for 64 different start points and see how many times heustic method works" << endl;
    cout << "4. run improved heuristic version for option 3 (if tie between possible moves seen, the cell with lowest accessibility is chosen (not completed)";
    // I quit this exercise at option 4, it is getting a little hard and a lot time consuming
    cout << "\nchoose one of options above by entering its number: ";
    int option;
    cin >> option;
    return option;
}

void clearBoard(){
    for(auto& row : board){
        for(auto& column : row){
            column = 0;
        }
    }
}

void printBoard(){
    // system("CLS");
    // cout << flush;

    cout << "board:" << endl;
    for(int row{1}; row <= grid; row++){
        for(int column{1}; column <= grid; column++){
            cout << setw(3) << board[row][column];
        }
        cout << endl;
    }
    // for(auto const& row : board){
    //     for(auto const& column : row){
    //         cout << setw(3) << column;
    //     }
    //     cout << endl;
    // }
    accessibilityCalc();
    cout << "\naccessiblity: " << endl;
    for(int row{1}; row <= grid; row++){
        for(int column{1}; column <= grid; column++){
            cout << setw(3) << accessibility[row][column];
        }
        cout << endl;
    }
    // for(auto const& row : accessibility){
    //     for(auto const& column : row){
    //         cout << setw(3) << column;
    //     }
    //     cout << endl;
    // }
}

void move(int move){
    currentRow += vertical[move];
    currentColumn += horizontal[move];
    counter++;
    board[currentRow][currentColumn] = counter;
    accessibilityCalc();
}

bool validInsideBoardMove(int row, int column, int move){
    if(row + vertical[move] >= 1
    && row + vertical[move] <= 8
    && column + horizontal[move] >= 1
    && column + horizontal[move] <= 8){
        return true;
    }
    return false;
}

void accessibilityCalc(){
    for(int row{1}; row <= grid; row++){
        for(int column{1}; column <= grid; column++){
            accessibility[row][column] = 0;
            for(int move{0}; move < totalPossibleMoves; move++){
                if(validInsideBoardMove(row, column, move)
                && 0 == board[row + vertical[move]][column + horizontal[move]])
                    ++accessibility[row][column];
            }
        }
    }
}

void setStartPoint(){
    clearBoard();
    cout << "enter start point row & column: ";
    cin >> currentRow >> currentColumn;
    counter = 1;
    board[currentRow][currentColumn] = counter;
    accessibilityCalc();
}

void setStartPoint(int row, int column){
    clearBoard();
    currentRow = row;
    currentColumn = column;
    counter = 1;
    board[currentRow][currentColumn] = counter;
    accessibilityCalc();
}

