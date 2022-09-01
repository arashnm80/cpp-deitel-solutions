// 7.28 (Palindromic Sentences)
#include <iostream>
#include <string>

using namespace std;

string ignoredCharacters{". \'\",;"};

bool isValidCharacter(char);
string removeCharacters(const string&);
string makeAllSmallCaps(const string&);
bool testPalindrome(const string&);

int main(){
    cout << "enter your string: ";
    string test;
    getline(cin, test);
    cout << "after removing unnecessary characters: " << removeCharacters(test) << endl;
    cout << "after making all small caps: " << makeAllSmallCaps(removeCharacters(test)) << endl;
    if(testPalindrome(makeAllSmallCaps(removeCharacters(test)))){
        cout << "it is palindrome." << endl;
    }else{
        cout << "not a palindrome." << endl;
    }
}

bool isValidCharacter(char testCharacter){
    for(int i{0}; i < ignoredCharacters.size(); i++){
        if(testCharacter == ignoredCharacters[i]){
            return false;
        }
    }
    return true;
}

string removeCharacters(const string& input){
    string output;
    for(int index{0}; index < input.size(); index++){
        if(isValidCharacter(input[index])){
            output += input[index];
        }
    }
    return output;
}

string makeAllSmallCaps(const string& input){
    string output{input};
    for(int index{0}; index < input.size(); index++){
        if(output[index] >= 65 && output[index] <= 90){
            output[index] += 32;
        }
    }
    return output;
}

bool testPalindrome(const string& test){
    for(size_t index{0}; index < test.size() / 2; index++){
        if(test[index] != test[test.size() - index - 1]){
            return false;
            cout << "this line should not be printed" << endl;
        }
    }
    return true;
}