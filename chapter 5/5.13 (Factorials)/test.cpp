#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    long factorial{1}; // but when numbers become bigger, the program produces garbage!
    int i;
    for(i = 1; i < 100; i++){
        factorial *= i;
        cout << setw(2) << i << "! = " << ' ';
        cout << setw(30) << factorial << endl;
    }
}