// 7.32 (Find the Maximum Value in an array)
#include <iostream>
#include <array>

using namespace std;

const int arraySize{10};
array<int, arraySize> myArray{2, -3, 0, 7, 8, 1, 12, 15, -5, 11}; // just a random array for test

int recursiveMaximum(const array<int, arraySize>& myArray, int start, int end);

int main(){
    cout << recursiveMaximum(myArray, 0, 9) << endl;
}

int recursiveMaximum(const array<int, arraySize>& myArray, int start, int end){
    if(start == end){
        return myArray[start];
    }
    return (myArray[start] > recursiveMaximum(myArray, start + 1, end) ? myArray[start] : recursiveMaximum(myArray, start + 1, end));
}