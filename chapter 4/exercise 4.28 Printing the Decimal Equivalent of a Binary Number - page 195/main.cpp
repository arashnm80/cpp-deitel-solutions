#include <iostream>
using namespace std;
int main(){
    unsigned int binaryInput;
    unsigned int binaryInputValidate{0};
    unsigned int binaryInputTemp;
    unsigned int binaryInputReversed{0};
    unsigned int decimalOutput{0};
    // check for being in right range and consisting right digits.
    cout << "Enter binary input : ";
    while(!binaryInputValidate){
        cin >> binaryInput;
        if(binaryInput < 0 || binaryInput > 1111111111){
            cout << "your number should be from 0 to 1111111111. Please enter again:";
        }else{
            binaryInputValidate = 1;
            binaryInputTemp = binaryInput;
            while(binaryInputTemp > 0){
                if(binaryInput % 10 > 1){ // check digit by digit for being 0 or 1
                    binaryInputTemp = 0;
                    binaryInputValidate = 0;
                    cout << "Your number should only contain 1s & 0s. Please enter again: ";
                }else{
                    binaryInputTemp /= 10;
                }
            }
        }
    }
    //calculate binary input reversed
    binaryInputTemp = binaryInput;
    while(binaryInputTemp > 0){
        binaryInputReversed = (binaryInputReversed * 10) + (binaryInputTemp % 10);
        binaryInputTemp /= 10;
    }
    //calculate decimal output
    while(binaryInputReversed > 0){
        decimalOutput = (decimalOutput * 2) + (binaryInputReversed % 10);
        binaryInputReversed /= 10;
    }

    cout << "\nDecimal equivalent of " << binaryInput << " is: " << decimalOutput << endl;
}
