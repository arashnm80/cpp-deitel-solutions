#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    double hoursWorked;
    cout << setprecision(2) << fixed;
    cout << "Enter number of hours worked (-1 to end): ";
    cin >> hoursWorked;
    while(hoursWorked != -1){
        cout << "Accrued leave: " << (hoursWorked / 10) + 2 << " hours" << endl << endl;
        cout << "Enter number of hours worked (-1 to end): ";
        cin >> hoursWorked;
    }
}
