#include <iostream>
#include <iomanip>
#include <math.h> // used for sqrt
using namespace std;

int main(){
    int a,b,c;
    cout << "side1\tside2\thypotenuse" << endl;
    for(a = 1; a <= sqrt(500); a++){
        for(b = a; b <= sqrt(500); b++){ // if we start b from 1 in this for loop, every answer will be shown twice
            for(c = 1; c <= sqrt(500); c++){
                if(a * a + b * b == c * c){
                    cout << a << '\t' << b << '\t' << c << endl;
                }
            }
        }
    }
}