#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int a[5];
    for(int i{0}; i < 5; i++){
        cout << i + 1 << ": ";
        cin >> a[i];
    }
    for(int i{0}; i < 5; i++){
        for(int j{0}; j < a[i]; j++){
            cout << a[i];
        }
        cout << '\n';
        for(int j{0}; j < a[i]; j++){
            cout << a[i];
        }
        cout << '\n';
    }
}