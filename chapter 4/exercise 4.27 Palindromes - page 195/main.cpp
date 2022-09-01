#include <iostream>
using namespace std;
int main(){
    unsigned int input;
    int inputValidateFlag{0};
    unsigned int reverse{0};
    unsigned int temp;
    cout << "Enter the number: ";
    while(!inputValidateFlag){
        cin >> input;
        if(input >= 10000 && input <= 99999){
            inputValidateFlag = 1;
        }else{
            cout << "number should be 5 digits. please try again: ";
        }
    }

    temp = input;
    while(temp > 0){
        reverse = (reverse * 10) + (temp % 10);
        temp /= 10;
    }

    if(reverse == input){
        cout << "\nIt is a palindrome" << endl;
    }else{
        cout << "\nNot a palindrome" << endl;
    }
}
