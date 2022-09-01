#include <iostream>
using namespace std;
int main(){
    int x;
    int y;

    cout << "input x: ";
    cin >> x;
    cout << "input y: ";
    cin >> y;
//block 1:
    if(x > 5)
        if(y > 5)
            cout << "x and y are both greater than 5" << endl;
    else
        cout << "x is greater than 5 but y is not" << endl;
//block 2:
    if(x > 5){
        if(y > 5){
            cout << "x and y are both greater than 5" << endl;
        }else{
            cout << "x is greater than 5 but y is not" << endl;
        }
    }
//block 1 and 2 are the same
//the 'else' in block 1 is related to inner 'if' not the outer one
}
