// Fig. 3.9: AccountTest.cpp
// Displaying and updating Account balances.
#include <iostream>
#include "Account.h"

using namespace std;

void displayAccount(Account accountToDisplay){
   cout << "Account name is: " << accountToDisplay.getName() <<
   " and account balance is: " << accountToDisplay.getBalance() << endl;
}

int main() 
{
   Account account1{"Jane Green", 50};
   Account account2{"John Blue", -7}; 

   // display initial balance of each object
   cout << "\nAccount 1:" << endl;
   displayAccount(account1);
   cout << "Account 2:" << endl;
   displayAccount(account2);  

   cout << "\n\nEnter deposit amount for account1: "; // prompt
   int depositAmount;
   cin >> depositAmount; // obtain user input
   cout << "adding " << depositAmount << " to account1 balance";
   account1.deposit(depositAmount); // add to account1's balance

   // display balances
   cout << "\nAccount 1:" << endl;
   displayAccount(account1);
   cout << "Account 2:" << endl;
   displayAccount(account2);  

   cout << "\n\nEnter deposit amount for account2: "; // prompt
   cin >> depositAmount; // obtain user input
   cout << "adding " << depositAmount << " to account2 balance";
   account2.deposit(depositAmount); // add to account2 balance

   // display balances
   cout << "\nAccount 1:" << endl;
   displayAccount(account1);
   cout << "Account 2:" << endl;
   displayAccount(account2); 
} 

/**************************************************************************
 * (C) Copyright 1992-2017 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/
