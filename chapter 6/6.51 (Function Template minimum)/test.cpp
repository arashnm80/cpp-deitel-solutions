#include <iostream>
#include "testHeader.h"

using namespace std;

int main(){
    int aInt{2};
    int bInt{5};

    char aChar{'m'};
    char bChar{'e'};

    double aDouble{1.3};
    double bDouble{4.2};

    cout << minimum(aInt, bInt) << "\t" << minimum(aChar, bChar) << "\t" << minimum(aDouble, bDouble) << endl;
}
