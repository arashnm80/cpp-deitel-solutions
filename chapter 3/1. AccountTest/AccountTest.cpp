#include <iostream>
#include "Account.h"

using namespace std;

int main(){
    string accountName;
    cout << "Enter account name: " << endl;
    getline(cin, accountName);

    int accountInitialBalance;
    cout << "Enter initial balance for this account: " << endl;
    cin >> accountInitialBalance;

    Account Account1{accountName, accountInitialBalance};
    cout << Account1.getName() << " balance is: " << Account1.getBalance() << endl;

    
    int depositAmount;
    cout << "Enter new deposit amount: " << endl;
    cin >> depositAmount;
    Account1.deposit(depositAmount);

    cout << Account1.getName() << " balance is: " << Account1.getBalance() << endl;

    int withdrawAmount;
    cout << "Enter withdraw amount: " << endl;
    cin >> withdrawAmount;
    if(withdrawAmount > Account1.getBalance()){
        cout << "Withdrawal amount exeeded " << Account1.getName() << " balance." << endl;
    }else{
        Account1.withdraw(withdrawAmount);
        cout << Account1.getName() << " balance is: " << Account1.getBalance() << endl;
    }
}