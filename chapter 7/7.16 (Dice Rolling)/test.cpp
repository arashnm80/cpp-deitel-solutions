// exercise 7.16
#include <iostream>
#include <array>

using namespace std;

const int diceFaces{6};
const int minSum{2};
const int maxSum{12};

int main(){
    array<int, maxSum + 1> diceSum{}; // we use subscripts 2 to 12 (0, 1, 2 are unnecessary)
    int dice1, dice2;
    for(int i{0}; i < 36'000'000; i++){
        dice1 = rand() % 6 + 1;
        dice2 = rand() % 6 + 1;
        ++diceSum[dice1 + dice2];
    }
    for(int i{minSum}; i <= maxSum; i++){
        cout << "count of sum = " << i << ": " << diceSum[i] << "\tproportion: " << static_cast<double>(diceSum[i]) / 1'000'000 << endl;
    }
}