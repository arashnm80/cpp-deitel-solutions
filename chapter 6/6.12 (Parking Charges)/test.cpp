#include <iostream>
#include <iomanip>

using namespace std;

double calculateCharges(double);

int main(){
   double totalHours{0};
   double totalCharge{0};
   //no difference between left << setw(5) or setw(5) << left in this example
   //upper line also applies for right << setw(10)
   cout << left << setw(5) << "Car" << right << setw(10) << "Hours" << setw(10) << "Charge" << endl << fixed;
   double inputHours[4];
   inputHours[1] = 1.5;
   inputHours[2] = 4;
   inputHours[3] = 24;
   unsigned int counter{1};
   for(;counter <= 3; counter++){
      totalHours += inputHours[counter];
      totalCharge += calculateCharges(inputHours[counter]);
      cout << left << setw(5) << counter 
         << right << setw(10) << setprecision(1) << inputHours[counter] 
            << setw(10) << setprecision(2) << calculateCharges(inputHours[counter]) << endl;
   }
   cout << left << setw(5) << "TOTAL" 
         << right << setw(10) << setprecision(1) << totalHours 
            << setw(10) << setprecision(2) << totalCharge << endl;
}

double calculateCharges(double hours){
   double cost{0};
   if(hours <= 3){
      cost = 20;
   }else{
      cost = 20 + (hours - 3) * 5;
      if(cost > 50){
         cost = 50;
      }
   }
   return cost;
}
