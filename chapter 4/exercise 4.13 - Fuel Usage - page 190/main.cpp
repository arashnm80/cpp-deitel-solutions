#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    unsigned int totalKilometers {0};
    unsigned int totalLiters {0};
    int currentKilometers;
    unsigned int currentLiters;

    cout << setprecision(6) << fixed;

    cout << "Enter kilometers driven (-1 to quit): ";
    cin >> currentKilometers;

    while(currentKilometers != -1){
        cout << "Enter liters used: ";
        cin >> currentLiters;
        cout << "Kms per liter of this trip: " << static_cast<double> (currentKilometers) / currentLiters << endl;
        totalKilometers += currentKilometers;
        totalLiters += currentLiters;
        cout << "Total Kms per liter: " << static_cast<double> (totalKilometers) / totalLiters << endl << endl;
        cout << "Enter kilometers driven (-1 to quit): ";
        cin >> currentKilometers;
    }
}
