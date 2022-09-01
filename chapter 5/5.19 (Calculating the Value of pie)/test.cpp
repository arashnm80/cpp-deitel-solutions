#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int precision{1000000}; // this precision looks good enough
    double pie{0};
    for(int i{1}; i <= precision; i++){
        pie += (i % 2 ? 1 : -1) * static_cast<double>(4) / (2 * i - 1);
    }
    cout << pie << endl;
}