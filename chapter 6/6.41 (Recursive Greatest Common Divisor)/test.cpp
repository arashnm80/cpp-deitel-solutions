// greatest common divisor recursive function

#include <iostream>

using namespace std;

unsigned gcd(unsigned x, unsigned y);

int main(){
    unsigned x, y;
    cout << "enter 2 positive integer numbers: ";
    cin >> x >> y;
    cout << "greatest common divisor: " << gcd(x, y) << endl;
}

unsigned gcd(unsigned x, unsigned y){
    if(0 == x * y){
        return x + y; // if one of numbers is zero, the gcd will be the other one
    }else{
        if(y > x){ // for using this algorithm the first number should be the bigger one
            // classic swapping of 2 variables:
            x += y;
            y = x - y;
            x -= y;
        }
        return gcd(y, x % y);
    }
}
