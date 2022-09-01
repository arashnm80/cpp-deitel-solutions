#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int accountNumber;
    double beginningBalance;
    double totalCharges;
    double totalCredits;
    double creditLimit;
    double newBalance;

    cout << setprecision(2) << fixed;

    cout << "Enter account number (or -1 to quit): ";
    cin >> accountNumber;

    while(accountNumber != -1){
        cout << "Enter beginning balance: ";
        cin >> beginningBalance;
        cout << "Enter total charges: ";
        cin >> totalCharges;
        cout << "Enter total credits: ";
        cin >> totalCredits;
        cout << "Enter credit limit: ";
        cin >> creditLimit;

        newBalance = beginningBalance + totalCharges - totalCredits;
        cout << "New balance is " << newBalance;

        if(newBalance > creditLimit){
            cout << "\nAccount:\t" << accountNumber;
            cout << "\nCredit limit:\t" << creditLimit;
            cout << "\nBalance:\t" << newBalance;
            cout << "\nCredit limit exeeded";
        }

        cout << "\n\nEnter account number (or -1 to quit): ";
        cin >> accountNumber;
    }   
}
