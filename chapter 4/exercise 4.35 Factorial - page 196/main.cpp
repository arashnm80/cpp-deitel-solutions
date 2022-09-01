#include <iostream>
using namespace std;

unsigned int factorial(unsigned int factorialInput);
double power(double base, int power);

int main(){
    //calculate facorial of a number
    unsigned int input;
    cout << "Enter a number to calculate it's factorial: ";
    cin >> input;
    cout << input << "! = " << factorial(input) << "\n";

    //calculate neper
    int accuracy{1};
    cout << "\nEnter accuracy for e & e^x terms: ";
    cin >> accuracy;
    int accuracyTemp{accuracy};
    double neper{0};
    while(accuracyTemp >= 0){
        neper += static_cast<double>(1) / factorial(accuracyTemp);
        accuracyTemp--; //if I had defined accuracy & accuracyTemp as unsinged int,
                        // they would produce a wrong positive number instead of -1 in this point
    }
    cout << "Neper with " << accuracy << " terms accuracy is: " << neper << endl;
    
    //calculate neper to the power of x
    double neperToPowerX{0};
    unsigned int x;
    cout << "\nEnter x for calculaing neper to the power of x with given accuracy: ";
    cin >> x;
    accuracyTemp = accuracy;
    while(accuracyTemp >= 0){
        neperToPowerX += power(x, accuracyTemp) / factorial(accuracyTemp); //power output is double, so we are cool
        accuracyTemp--; //if I had defined accuracy & accuracyTemp as unsinged int,
                        // they would produce a wrong positive number instead of -1 in this point
    }
    cout << "\nNeper to the power of " << x << " with " << accuracy << " terms accuracy is: " << neperToPowerX << endl;
}

unsigned int factorial(unsigned int factorialInput){
    unsigned int factorialOutput{1};
    if(factorialInput > 1){
        while(factorialInput > 1){
            factorialOutput *= factorialInput;
            factorialInput--;
        }
    }
    return factorialOutput;
}

double power(double base, int power){
    double powerOutput{1};
    if(power > 0){
        while(power > 0){
            powerOutput *= base;
            power--;
        }
    }else{ // I am trying this king of writing in this block just as a test
        if(power < 0){
            while(power < 0){
                powerOutput /= base;
                power++;
            }
        }
    }

    return powerOutput;
}
