#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int inputProductNumber{0};
    int inputProductQuantity{0};
    double productPrice[6]; // index 0 will be unused
    productPrice[1] = 2.98;
    productPrice[2] = 4.50;
    productPrice[3] = 9.98;
    productPrice[4] = 4.49;
    productPrice[5] = 6.87;
    double productRetailPrice[6]{0}; //this initializes all to zero
    double totalRetailPrice{0};
    for(int i{1}; i <= 5; i++){
        cout << "price of product " << i << " is: " << productPrice[i] << endl;
    }

    while(inputProductNumber != -1){
        cout << "\nenter product number(-1 to exit): ";
        cin >> inputProductNumber;
        if(inputProductNumber != -1){
            cout << "enter quantity: ";
            cin >> inputProductQuantity;
            productRetailPrice[inputProductNumber] += inputProductQuantity * productPrice[inputProductNumber];
        }else{
            cout << "\nprogram ended\n" << endl;
        }
    }

    for(int i{1}; i <= 5; i++){
        cout << "retail price of product " << i << " is: " << productRetailPrice[i] << endl;
        totalRetailPrice += productRetailPrice[i];
    }
    cout << "\ntotal retail price: " << totalRetailPrice << endl;
}
