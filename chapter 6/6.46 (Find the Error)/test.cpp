#include <iostream>

using namespace std;

float cube(float);

double square(double number) {
    // double number{0};     d) this line is removed because it has conflict with parameter name
    return number * number;
}

int sum(int n){
    if (0 == n){
        return 0;
    }else{
        return n + sum(n - 1); // e) the function never stops so I changed n to (n - 1)
    }
}

int main(){
    // b) first: srad should have seed parameter     second: correct form is in 2 lines like below:
    srand(5);
    int randomNumber{rand()};

    float y{123.45678};
    int x;
    x = y;
    cout << static_cast<float>(x) << endl; // c) this is wrong becuase truncating has happened in the upper line

    cout << sum(5) << endl;
}

float cube(float number){ // a) return type in function defenition was missed
    return number * number * number;
}