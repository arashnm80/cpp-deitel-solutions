#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int a{1}, b{2}, x{3}, y{4}; // just random numbers. in any combination of numbers every pair below should be equal
    cout << "a:" << endl;
    cout << !((x <= 6) && (y % 2==1)) << '\t' << (!(x <= 6) || !(y % 2==1)) << endl;
    cout << "\nb:" << endl;
    cout << !((a < 4) || (b >= 6)) << '\t' << (!(a < 4) && !(b >= 6)) << endl;
    cout << "\nc:" << endl;
    cout << (!(x < 3) && !(y >= 2)) << '\t' << !((x < 3) || (y >= 2)) << endl; // funny note: if we omit outer parentheses we will encounter to error
    cout << "\nd:" << endl;
    cout << (!(a == b) || !(b != 2)) << '\t' << !((a == b) && (b != 2)) << endl;
}