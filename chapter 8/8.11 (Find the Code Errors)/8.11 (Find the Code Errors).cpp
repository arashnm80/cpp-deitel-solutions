// 8.11 (Find the Code Errors)

/* 
    a) number doesn't point to anything
    b) double* can't be assigned to long* without cast
    c) x is pointer to int , y is int
    d) s is const. correct form could be:
        for (char* i{s}; *i != '\0'; ++i) {
            cout << *i << ' ';
        }
    e) genericPtr is void* and cannot be dereferenced
    f) double* cannot be assigned to double
*/

#include <iostream>
using namespace std;
int main(){
    
}