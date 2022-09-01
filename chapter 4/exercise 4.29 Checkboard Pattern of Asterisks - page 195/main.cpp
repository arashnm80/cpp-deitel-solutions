#include <iostream>
using namespace std;
int main(){
    unsigned int row{1};
    unsigned int column{1};

    while(row <= 8){
        while(column <= 8){
            if(row % 2 == 1){
                cout << "* ";
            }else{
                cout << " *";
            }
            column++;
        }
        column = 1;
        cout << '\n';
        row++;
    }
}
