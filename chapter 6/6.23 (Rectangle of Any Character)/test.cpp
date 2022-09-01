// Exercise 6.23
#include <iostream>

using namespace std;

void rectangle(unsigned, unsigned, char);

int main(){
    unsigned width, height;
    char fillCharacter;
    cout << "enter height: ";
    cin >> height;
    cout << "enter width: ";
    cin >> width;
    cout << "enter fill character: ";
    cin >> fillCharacter;
    rectangle(width, height, fillCharacter);
}

void rectangle(unsigned width, unsigned height, char fillCharacter){
    for(unsigned h{height}; h >= 1; h--){
        for(unsigned w{width}; w >= 1; w--){
            cout << fillCharacter;
        }
        cout << endl;
    }
}