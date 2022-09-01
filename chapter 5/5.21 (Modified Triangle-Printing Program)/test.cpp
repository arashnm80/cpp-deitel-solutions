#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int i,j;
    for(i = 1; i <= 10; i++){
        //part1:
        for(j = 1; j <= i; j++){
            cout << '*';
        }
        for(j = 1; j <= 10 -i; j++){
            cout << ' ';
        }
        //part2:
        cout << '\t';
        for(j = 1; j <= 10 - i + 1; j++){
            cout << '*';
        }
        for(j = 1; j <= i - 1; j++){
            cout << ' ';
        }
        //part3: we only need to change order of loops in part2
        cout << '\t';
        for(j = 1; j <= i - 1; j++){
            cout << ' ';
        }
        for(j = 1; j <= 10 - i + 1; j++){
            cout << '*';
        }
        //part4: we only need to change order of loops in part1
        cout << '\t';
        for(j = 1; j <= 10 -i; j++){
            cout << ' ';
        }
        for(j = 1; j <= i; j++){
            cout << '*';
        }
        //and we go to new line
        cout << endl;
    }

    //program that we wrote in 5.15 was this:

    /*
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
    */
}