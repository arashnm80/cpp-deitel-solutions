#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int i,j;
    int height{0};
    cout << "enter an odd number fo height: ";
    cin >> height;
    while(height % 2 != 1){ // we could also write:	while(!(height % 2))
        cout << "your number was even, please try again: ";
        cin >> height;
    }
    for(i = 1; i <= height; i++){
        for(j = 1; j <= height; j++){
            if(1 == i || height == i || 1 == j || height == j){
                cout << '#';
            }else if(((j >= i) && (j <= height - i + 1)) || ((j <= i) && (j >= height -i + 1))){
                cout << '*';
            }else{
                cout << ' ';
            }
        }
        cout << endl;
    }
}
