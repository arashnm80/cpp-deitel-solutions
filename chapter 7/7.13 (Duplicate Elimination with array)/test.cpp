#include <iostream>
#include <array>
#include <algorithm> // used for sort & binary search

using namespace std;

const size_t arraySize{20};

int main(){
    array<int, arraySize> numbers{}; // initialized to zero
    int inputNumber;
    int count{0};
    cout << "enter " << arraySize << " numbers between 10 & 100: ";
    for(size_t i{0}; i < arraySize; i++){
        cin >> inputNumber;
        while(inputNumber < 10 || inputNumber > 100){
            cout << "number is out of range, try again: ";
            cin >> inputNumber;
        }
        if(!binary_search(numbers.begin(), numbers.end(), inputNumber)){
            numbers[0] = inputNumber;
            sort(numbers.begin(), numbers.end()); // input numbers will go to the end because array is initialized to zero
            count++;
        }
    }
    cout << "\nthese are unique numbers: ";
    for(auto const& number:numbers){
        if(number){
            cout << number << " ";
        }
    }
    if(count == arraySize){
        cout << "\nworst case, all numbers are different" << endl;
    }
}