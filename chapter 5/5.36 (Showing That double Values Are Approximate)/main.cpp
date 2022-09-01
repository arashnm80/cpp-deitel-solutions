#include <iostream>
#include <iomanip>
using namespace std;
int main(){
   double a{123.02};
   cout << setprecision(17)<< a << endl; // prints 123.02
   cout << setprecision(18)<< a << endl; // prints 123.019999999999996
}
