#include <iostream>

using namespace std;

void honai(unsigned, unsigned, unsigned);

int main(){
    unsigned disks;
    cout << "enter how many disks you want to move: ";
    cin >> disks;
    unsigned startPeg;
    cout << "enter the initial peg number between 1 to 3: ";
    cin >> startPeg;
    unsigned endPeg;
    cout << "enter final peg number between 1 to 3: ";
    cin >> endPeg;

    honai(disks, startPeg, endPeg);
}

void honai(unsigned disks, unsigned startPeg, unsigned endPeg){
    if(1 == disks){
        cout << startPeg << " -> " << endPeg << endl;
    }else{
        unsigned tempPeg;
        switch(startPeg * endPeg){
            case 2:
                tempPeg = 3;
                break;
            case 3:
                tempPeg = 2;
                break;
            case 6:
                tempPeg = 1;
                break;
            default:
                cout << "error";
        }
        honai(disks - 1, startPeg, tempPeg);
        cout << startPeg << " -> " << endPeg << endl;
        honai(disks - 1, tempPeg, endPeg);
    }
}