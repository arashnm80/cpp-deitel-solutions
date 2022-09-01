// exercise 7.14
// I left some parts of the last exercise just to make some differences visible
#include <iostream>
// #include <array>
#include <vector>
#include <algorithm> // used for sort & binary search

using namespace std;

const size_t size{10}; // fun fact: the name "size" is ambiguous for compiler, I have 2 options: change the name of refer to it with unary scope resolution operator

int main(){
    vector<int> numbers(0);
    // array<int, size> numbers{}; // initialized to zero
    int inputNumber;
    // int count{0};
    cout << "enter " << ::size << " numbers between 10 & 100: ";
    for(size_t i{0}; i < ::size; i++){
        cin >> inputNumber;
        while(inputNumber < 10 || inputNumber > 100){
            cout << "number is out of range, try again: ";
            cin >> inputNumber;
        }
        if(!binary_search(numbers.begin(), numbers.end(), inputNumber)){
            numbers.push_back(inputNumber);
            // numbers[0] = inputNumber;
            sort(numbers.begin(), numbers.end()); // input numbers will go to the end because array is initialized to zero
            // count++;
        }
    }
    cout << "\nthese are unique numbers: ";
    for(auto const& number : numbers){
        // if(number){
            cout << number << " ";
        // }
    }
    if(numbers.size() == ::size){
        cout << "\nworst case, all numbers are different" << endl;
    }
}