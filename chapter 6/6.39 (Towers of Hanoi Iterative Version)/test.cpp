#include <iostream>
#include <string>

using namespace std;

string changeChars(string, char, char, char); // calculates repetitive next moves based on previous ones
unsigned tempPegFinder(unsigned startPeg, unsigned endPeg); // gets start & end pegs and tells that 3rd peg is the temp one
void swapStartAndEndPeg(unsigned& startPeg, unsigned& endPeg); // swaps start & end pegs

int main(){
    string hanoiAnswer;

    // due to my algorithm in this answer startPeg & endPeg are going to be swapped with each other (disks - 1) times
    unsigned disks;
    cout << "enter how many disks you want to move: ";
    cin >> disks;
    unsigned startPeg;
    cout << "enter the initial peg number between 1 to 3: ";
    cin >> startPeg;
    unsigned endPeg;
    cout << "enter final peg number between 1 to 3: ";
    cin >> endPeg;

    unsigned tempPeg{tempPegFinder(startPeg, endPeg)};
    if(disks % 2 == 0){
        hanoiAnswer = to_string(startPeg) + " -> " + to_string(tempPeg);
        startPeg = tempPeg;
        // endPeg = endPeg      I mean no change in endPeg
    }else{
        hanoiAnswer = to_string(startPeg) + " -> " + to_string(endPeg);
        startPeg = endPeg;
        endPeg = tempPeg;
    }

    // the first peg with pile of disks is going to be the tempPeg to the end of program
    // 2 other pegs will change places between starPeg & endPeg on every loop
    tempPeg = tempPegFinder(startPeg, endPeg);
    string tempString;
    for(unsigned i{disks - 1}; i >= 1; i--){
        // for casting number 2 to character 2, we should add 48 to it because character code of it is 50
        tempString = changeChars(hanoiAnswer, static_cast<char>(tempPeg + 48), static_cast<char>(startPeg + 48), static_cast<char>(endPeg + 48));
        hanoiAnswer += string("\n") + to_string(tempPeg) + string(" -> ") + to_string(endPeg) + string("\n") + tempString;
        swapStartAndEndPeg(startPeg, endPeg);
    }
    cout << hanoiAnswer << endl;
}

string changeChars(string text, char peg1, char peg2, char peg3){
    for(unsigned i{0}; i < text.length(); i++){
        if(text[i] == peg1){
            text[i] = peg2;
        }else if(text[i] == peg2){
            text[i] = peg3;
        }else if(text[i] == peg3){
            text[i] = peg1;
        }
    }
    return text;
}

unsigned tempPegFinder(unsigned startPeg, unsigned endPeg){
    switch(startPeg * endPeg){
        case 2:
            return 3;
        case 3:
            return 2;
        case 6:
            return 1;
        default:
            return 0;
    }
}

void swapStartAndEndPeg(unsigned& startPeg, unsigned& endPeg){
    // classic way of swapping 2 integers without any other variable:
    startPeg += endPeg;
    endPeg = startPeg - endPeg;
    startPeg -= endPeg;
}
