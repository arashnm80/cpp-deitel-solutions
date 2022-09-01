#include <iostream>
using namespace std;
int main(){
    unsigned int a{0};
    unsigned int b{1};
    unsigned int temp;
    cout << 0 << '\n' << 1 << '\n';
    //because of this while loop condition it will be run forever
    while(true){
        cout << a << endl;
        temp = a + b;
        a = b;
        b = temp;
        //another way of doing 3 upper lines without using temp variable:
        // b = a + b;
        // a = b - a;
    }
}
