#include <iostream>
#include "testHeader.h"

using namespace std;

int main(){
    double base;
    cout << "enter base: ";
    cin >> base;
    unsigned exponent;
    cout << "enter exponent: ";
    cin >> exponent;
    cout << power(base, exponent) << endl;
}
