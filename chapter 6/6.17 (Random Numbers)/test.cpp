#include <iostream>

using namespace std;

int main(){
    cout << "a:" << endl;
    for(int i = 1; i <= 20; i++){
        cout << (rand() % 5) * 3 << ",";
    }

    cout << "\n\nb:" << endl;
    for(int i = 1; i <= 20; i++){
        cout << (((rand() % 6) + 1) * 2) + 1 << ",";
    }
    
    cout << "\n\nc:" << endl;
    for(int i = 1; i <= 20; i++){
        cout << ((rand() % 4) * 4) + 6 << ",";
    }
}