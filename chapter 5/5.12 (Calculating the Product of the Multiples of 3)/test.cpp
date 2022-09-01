#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    uint64_t product{1}; // we should use a big unsigned type for this variable
    int i;
    for(i = 3; i < 50; i += 3){
        product *= i;
        cout << "step: " << setw(2) << i / 3 << '\t';
        cout << setw(20) << product << endl;
    }
}