// Exercise 6.28
#include <iostream>
#include <cmath>

using namespace std;

bool isDudeney(unsigned long);

int main(){
    cout << "apparently there are 6 Dudeney Numbers and the book wrote 7 wrong." << endl;
    unsigned long i{1};
    unsigned count{0};
    while(6 != count){
        if(true == isDudeney(i)){
            count++;
            cout << count << ". " << i << endl;
        }
        i++;
    }
    cout << "of course it was better to reach from roots to cubes instead of cubes to roots like what we did!" << endl;
    cout << "we examined too many numbers more than what was necessary.";
}

bool isDudeney(unsigned long input){
    unsigned cubeRoot{static_cast<unsigned long>(cbrt(input))};
    if(cubeRoot * cubeRoot * cubeRoot != input){return false;} // in case it doesn't even have a round integer cube root
    unsigned long sumOfDigits{0};
    while(input > 0){
        sumOfDigits += input % 10;
        input /= 10;
    }
    return (sumOfDigits == cubeRoot) ? true : false;
}