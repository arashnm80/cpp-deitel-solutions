#include <iostream>

using namespace std;

int main(){
    unsigned int counter{1};
    unsigned int number;
    unsigned int largest;

    cout << "Input number 1: ";
    cin >> number;
    largest = number;
    counter++;

    while(counter <= 10){
        cout << "Input number " << counter << ": ";
        cin >> number;
        if(number > largest){
            largest = number;
        }
        counter++;
    }

    cout << "\nLargest number is: " << largest << endl;
}
