#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    //part1:
    for(int i{1}; i <= 10; i++){
        for(int j{1}; j <= i; j++){
            cout << '*';
        }
        cout << '\n';
    }
    //part2:
    cout << '\n';
    for(int i{10}; i >= 1; i--){
        for(int j{1}; j <= i; j++){
            cout << '*';
        }
        cout << '\n';
    }
    //part3:
    cout << '\n';
    for(int i{10}; i >= 1; i--){
        for(int j{1}; j <= 10 - i; j++){
            cout << ' ';
        }
        for(int j{i}; j >= 1; j--){
            cout << '*';
        }
        cout << '\n';
    }
    //part4:
    cout << '\n';
    for(int i{1}; i <= 10; i++){
        for(int j{1}; j <= 10 - i; j++){
            cout << ' ';
        }
        for(int j{1}; j <= i; j++){
            cout << '*';
        }
        cout << '\n';
    }
}