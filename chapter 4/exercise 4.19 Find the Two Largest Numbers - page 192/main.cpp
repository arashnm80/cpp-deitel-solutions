#include <iostream>

using namespace std;

int main(){
    unsigned int counter{1};
    unsigned int number;
    unsigned int largest;
    unsigned int secondLargest;

    // note: as the exercise says, you should input each number only once
    cout << "Input number 1: ";
    cin >> number;
    largest = number;
    counter++;
    
    cout << "Input number 2: ";
    cin >> number;
    if(number > largest){
        secondLargest = largest;
        largest = number;
    }else{
        secondLargest = number;
    }
    counter++;

    while(counter <= 10){
        cout << "Input number " << counter << ": ";
        cin >> number;
        if(number > largest){
            secondLargest = largest;
            largest = number;
        }else if(number > secondLargest){
            secondLargest = number;
        }
        counter++;
    }

    cout << "\nLargest number is: " << largest << endl;
    cout << "Second largest number is: " << secondLargest << endl;
}

