#include <iostream>
#include <iomanip>
using namespace std;

void print();

int main(){
    print();
    cout << boolalpha; // just for my practice
    print();
    cout << noboolalpha; // just for my practice
    print();
}

void print(){
    int a{4}, b{3}, c{2}, d{1};
    //answers are commented
    cout << "a: "; cout << (a == 1) << endl; // 0
    cout << "b: "; cout << (b == 3) << endl; // 1
    cout << "c: "; cout << (d >= 1 && c < 4) << endl; // 1
    cout << "d: "; cout << (d <= 4 && b < d) << endl; // 0
    cout << "e: "; cout << (b >= d || c == a) << endl; // 1
    cout << "f: "; cout << ( c + d < b || b >= a) << endl; // 0
    cout << "g: "; cout << (!d ) << endl; // 0
    cout << "h: "; cout << (!( a - b)) << endl; // 0
    cout << "i: "; cout << (!(c < d)) << endl << endl; // 1
}