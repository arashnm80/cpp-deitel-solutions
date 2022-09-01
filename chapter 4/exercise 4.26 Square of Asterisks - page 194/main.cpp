// I love my code. It's beautiful :)
#include <iostream>
using namespace std;
int main(){
    unsigned int size;
    int sizeValidateFlag{0};
    unsigned int row{1};
    unsigned int column{1};

    cout << "Enter size: ";
    // sizeValidateFlag is 0 by default so the while loop will be executed at least once
    while(!sizeValidateFlag){
        cin >> size;
        if(size >= 1 && size <= 20){
            sizeValidateFlag = 1; // breaks the while loop
        }else{
            cout << "Size has to be in range of 1 to 20. Please enter again: "; // sizeValidateFlage will remain 0
        }
    }

    while(row <= size){
        while(column <= size){
            ///////////main block start
            if(row == 1 || row == size || column == 1 || column == size){
                cout << "*";
            }else{
                cout << ' ';
            }
            ///////////main block end
            ++column;
        }
        cout << endl;
        column = 1;
        ++row;
    }
    
}
