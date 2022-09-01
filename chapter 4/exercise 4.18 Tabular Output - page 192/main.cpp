#include <iostream>

using namespace std;

int main(){
    int i{1};
    cout << "N" << '\t' << "5*N" << '\t' << "10*N" << '\t' << "15*N" << endl;
    while(i <=12){
        cout << i << '\t' << i*5 << '\t' << i*10 << '\t' << i*15 << endl;
        i++;
    }
}
