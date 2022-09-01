// 7.31 (Print a String Backward)
#include <iostream>
#include <string>

using namespace std;

void stringReverse(const string& inputString, int startIndex);

int main(){
    cout << "enter your string: ";
    string inputString;
    getline(cin, inputString);
    int startIndex;
    cout << "enter start index (-1 to reverse whole string): ";
    cin >> startIndex;
    if(-1 == startIndex){
        stringReverse(inputString, inputString.size() - 1); // reverses the whole string
    }else{
        stringReverse(inputString, startIndex); // reverses string from startpoint
    }
}

void stringReverse(const string& inputString, int startIndex){
    cout << inputString[startIndex];
    if(0 == startIndex){
        return;
    }
    stringReverse(inputString, startIndex - 1);
}