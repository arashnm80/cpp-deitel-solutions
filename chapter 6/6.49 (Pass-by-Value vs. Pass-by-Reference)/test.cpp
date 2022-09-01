#include <iostream>

using namespace std;

int tripleByValue(int);
int tripleByReference(int&);

int main(){
    int count{1};
    cout << tripleByValue(count) << endl;
    cout << count << endl;

    cout << tripleByReference(count) << endl;
    cout << count << endl;
}

int tripleByValue(int value){
    value *= 3;
    return value;
}

int tripleByReference(int& reference){
    reference *= 3;
    return reference;
}