//test.cpp

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
    int number{0}; // we can't define it as unsigned int because it can be negative for exit checking
    int min{0};
    int input{0};
    // getting count of numbers with check:
    cout << "Enter how many numbers do you have(enter -1 to exit): ";
    cin >> number;
    while(number <= 0){
        if(-1 == number){
            cout << "program is closed." << endl;
            return 0;
        }else{
            cout << "you should enter a positive number, try again: ";
            cin >> number;
        }
    }
    // getting each number and compare it with min:
    cout << "please enter first number: ";
    cin >> input;
    min = input;
    number--;
    while(number > 0){
        cout << "please enter next number: ";
        cin >> input;
        if(input < min){
            min = input;
        }
        number--;
    }
    cout << "\nminimum is: " << min << endl;
}