#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int i,j;
    for(i = 1; i <= 9; i++){
        for(j = 1; j <= 9; j++){
            if(1 == i || 9 == i || 1 == j || 9 == j){
                cout << '#';
            }else if(((j >= i) && (j <= 10 - i)) || ((j <= i) && (j >= 10 -i))){
                cout << '*';
            }else{
                cout << ' ';
            }
        }
        cout << endl;
    }
}