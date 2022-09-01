// Exercise 6.18
#include <iostream>

using namespace std;

int integerPower(const int&, const unsigned&);

int main(){
    int base;
    cout << "enter base: ";
    cin >> base;
    unsigned exponent;
    cout << "enter exponent: ";
    cin >> exponent;
    cout << "\nresult= " << integerPower(base, exponent) << endl;
}

int integerPower(const int& base, const unsigned& exponent){
    int result{1};
    for(unsigned i{1}; i <= exponent; i++){
        result *= base;
    }
    return result;
}