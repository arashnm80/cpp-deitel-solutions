#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int lapsCompleted;
    double sponsorshipRate;
    double studentContribution;
    double totalFunds{0};

    cout << setprecision(2) << fixed;

    cout << "Enter laps completed (-1 to end): ";
    cin >> lapsCompleted;
    while(lapsCompleted != -1){
        cout << "Enter sponsorship rate: ";
        cin >> sponsorshipRate;
        if(lapsCompleted > 40){
            studentContribution = (40 * sponsorshipRate) + ((lapsCompleted - 40) * sponsorshipRate * 1.5);
        }else{
            studentContribution = (lapsCompleted * sponsorshipRate);
        }
        cout << "Student contribution is: " << studentContribution << endl << endl;
        totalFunds += studentContribution;
        cout << "Enter laps completed (-1 to end): ";
        cin >> lapsCompleted;
    }
    cout << "Total funds raised: " << totalFunds << endl;
}
