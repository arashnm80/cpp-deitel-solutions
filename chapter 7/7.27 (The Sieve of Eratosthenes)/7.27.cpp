// Exercise 7.27
// The Sieve of Eratosthenes
#include <iostream>
#include <array>

using namespace std;

const int arraySize{1000};
array<int, arraySize> prime;

void setArrayToNumber(int number);
void printArray();

int main(){
    setArrayToNumber(1);
    prime[0] = 0; // subscript 0 is ignored
    prime[1] = 0; // subscript 1 is ignored
    for(int subscript{2}; subscript < arraySize; subscript++){
        if(1 == prime[subscript]){
            for(int i{subscript + 1}; i < arraySize; i++){
                if(0 == i % subscript){
                    prime[i] = 0;
                }
            }
        }
    }
    printArray();
}

void setArrayToNumber(int number){
    for(int i{0}; i < arraySize; i++){
        prime[i] = number;
    }
}

void printArray(){
    cout << "prime numbers from 2 to " << arraySize - 1 << " :" << endl;
    for(int i{0}; i < arraySize; i++){
        if(1 == prime[i]){
            cout << i << endl;
        }
    }
}

