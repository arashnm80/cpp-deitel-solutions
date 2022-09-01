#include <iostream>
#include <iomanip>
using namespace std;

unsigned long factorial(unsigned long);
unsigned long indent;
bool newFactorial{true};

int main() {
    for (unsigned int counter{0}; counter <= 10; ++counter) {
        cout << factorial(counter) << endl << endl;
    }
}

 
unsigned long factorial(unsigned long number) {
    if(true == newFactorial){
        indent = number;
        cout << left << setw(2) << number << "!" << endl;
    }
    for(unsigned long i{number + 1}; i < indent; i++){
        cout << "       ";
    }
    if(false == newFactorial){
        cout << "⊢ " << setw(2) << number + 1 << " * " << setw(2) << number << "!" << endl;
    }
    if(true == newFactorial){
        newFactorial = false;
    }
    if(number <= 1) {
        for(unsigned long i{number}; i < indent; i++){
            cout << "       ";
        }
        cout << "⊢ " << setw(2) << 1 << endl;
        newFactorial = true;
        return 1;
    }else {   
        return number * factorial(number - 1);
    }
}