// 8.12 (Simulation: The Tortoise and the Hare)

#include <iostream>

using namespace std;

const int TOTAL_SQUARES{70};

int randBetween(int start, int end);
void moveTortoise(int randomNumber, int* tortoisePosition);
void moveHare(int randomNumber, int* harePosition);
void print(int* tortoisePosition, int* harePosition);

int main(){
    int tortoisePosition{1};
    int harePosition{1};
    int randomNumber;
    while(tortoisePosition < TOTAL_SQUARES && harePosition < TOTAL_SQUARES){
        cin.ignore();
        randomNumber = randBetween(1, 100);
        moveTortoise(randomNumber, &tortoisePosition);
        moveHare(randomNumber, &harePosition);
        print(&tortoisePosition, &harePosition);
    }
}

int randBetween(int start, int end){
    return rand() % (end - start + 1) + start;
}

void moveTortoise(int randomNumber, int* tortoisePosition){
    if(randomNumber >= 1 && randomNumber <= 50){
        // fast plod
        *tortoisePosition += 3;
    }else if(randomNumber <= 50 + 16){
        // slip
        *tortoisePosition -= 6;
    }else if(randomNumber <= 50 + 16 + 34){
        // slow plod
        *tortoisePosition += 1;
    }else{
        cout << "error: wrong randomNumber on moveTortoise function" << endl;
    }

    // check for not going out of bound
    if(*tortoisePosition < 1){
        *tortoisePosition = 1;
    }
}

void moveHare(int randomNumber, int* harePosition){
    if(randomNumber >= 1 && randomNumber <= 38){
        // no move at all
    }else if(randomNumber <= 38 + 16){
        // big hop
        *harePosition += 11;
    }else if(randomNumber <= 38 + 16 + 16){
        // big slip
        *harePosition -= 9;
    }else if(randomNumber <= 38 + 16 + 16 + 20){
        // small hop
        *harePosition += 1;
    }else if(randomNumber <= 38 + 16 + 16 + 20 + 10){
        // small slip
        *harePosition -= 2;
    }

    // check for not going out of bound
    if(*harePosition < 1){
        *harePosition = 1;
    }
}

void print(int* tortoisePosition, int* harePosition){
    cout << "tortoise position: " << *tortoisePosition << endl;
    cout << "hare position: " << *harePosition << endl;
    
    if(*tortoisePosition >= TOTAL_SQUARES && *harePosition >= TOTAL_SQUARES){
        cout << "tie" << endl;
    }else if(*tortoisePosition >= TOTAL_SQUARES){
        cout << "tortoise wins" << endl;
    }else if(*harePosition >= TOTAL_SQUARES){
        cout << "hare wins" << endl;
    }

    for(int i{1}; i <= TOTAL_SQUARES; i++){
        if(i == *tortoisePosition){
            if(*tortoisePosition == *harePosition){
                cout << "OUCH!!!";
                i += 7; // "OUCH!!!" has 7 characters
            }else{
                cout << "T";
            }
        }else if(i == *harePosition){
            cout << "H";
        }else{
            cout << ".";
        }
    }
    cout << endl;
}
