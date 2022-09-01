// 7.30 (Print an array)
#include <iostream>
#include <array>

using namespace std;

const int arraySize{20};
array<int, arraySize> myArray{1, 2, 3, 4, 5, 2, 4, 6, 8, 10, -1, -2, -3, -4, -5, 11, 12, 13, 14, 15}; // just an example array to test

void printArray(const array<int, arraySize>& myArray, int start, int end);

int main(){
    cout << "enter start & stop point of the array that you want (between 0 & 19): ";
    int start, end;
    cin >> start >> end;
    printArray(myArray, start, end);
}

void printArray(const array<int, arraySize>& myArray, int start, int end){
    cout << myArray[start] << " ";
    if(start == end){
        return;
    }
    printArray(myArray, start + 1, end);
}