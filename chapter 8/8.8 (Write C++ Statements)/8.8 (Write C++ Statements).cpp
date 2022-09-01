// 8.8 (Write C++ Statements)
#include <iostream>
using namespace std;

int main(){
    cout << "size of unsigned int in this system: " << sizeof(unsigned) << endl << endl;
    const unsigned SIZE{5};
    unsigned values[5]{2, 4, 6, 8, 10}; // section a
    unsigned int* vptr{nullptr}; // section b

    // section d:
    vptr = &values[0];
    cout << "&values[0] = \t" << vptr << endl;
    unsigned* v2ptr{values};
    cout << "values = \t" << v2ptr << endl << endl;

    // section c:
    for(size_t i{0}; i < SIZE; i++){
        cout << "values[" << i << "] = " << values[i] << endl;
    }
    cout << endl;

    // section e:
    for(size_t i{0}; i < SIZE; i++){
        cout << "*(vptr + " << i << ") = " << *(vptr + i) << endl;
    }
    cout << endl;

    // section f:
    for(size_t i{0}; i < SIZE; i++){
        cout << "*(values + " << i << ") = " << *(values + i) << endl;
    }
    cout << endl;

    // section g:
    for(size_t i{0}; i < SIZE; i++){
        cout << "vptr[" << i << "] = " << vptr[i] << endl;
    }
    cout << endl;

    // section h:
    // easy and skipped

    // section i:
    cout << "vptr + 3 = " << vptr + 3 << endl;
    cout << "*(vptr + 3) = " << *(vptr + 3) << endl;
    cout << endl;

    // section j:
    vptr = &values[4];
    vptr -= 4;
    cout << "vptr = " << vptr << endl;
    cout << "*vptr = " << *vptr << endl;
}