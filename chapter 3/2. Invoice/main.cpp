#include <iostream>
#include <string>
#include "Invoice.h"

using namespace std;

int main(){
    string partNumber;
    string partDescripton;
    int quantity;
    int price;
    double tax;
    double discount;

    cout << "please enter the following information about this item: " << endl;
    cout << "part number: ";
    cin >> partNumber;
    cout << "part description: ";
    getline(cin >> ws, partDescripton);
    cout << "quantity: ";
    cin >> quantity;
    cout << "price: ";
    cin >> price;

    Invoice Item1{partNumber, partDescripton, quantity, price};

    cout << "part number: " << Item1.getPartNumber() << " | "
         << "part description: " << Item1.getPartDescription() << " | "
         << "quantity: " << Item1.getQuantity() << " | "
         << "price: " << Item1.getPrice() << " | "
         << "tax: " << Item1.getTax() << " | "
         << "discount: " << Item1.getDiscount() << endl;
    
    cout << "please enter new iformation: " << endl;
    cout << "part number: ";
    cin >> partNumber;
    cout << "part description: ";
    getline(cin >> ws, partDescripton);
    cout << "quantity: ";
    cin >> quantity;
    cout << "price: ";
    cin >> price;
    cout << "tax: ";
    cin >> tax;
    cout << "discount: ";
    cin >> discount;

    Item1.setPartNumber(partNumber);
    Item1.setPartDescription(partDescripton);
    Item1.setQuantity(quantity);
    Item1.setPrice(price);
    Item1.setTax(tax);
    Item1.setDiscount(discount);
    
    cout << "part number: " << Item1.getPartNumber() << " | "
         << "part description: " << Item1.getPartDescription() << " | "
         << "quantity: " << Item1.getQuantity() << " | "
         << "price: " << Item1.getPrice() << " | "
         << "tax: " << Item1.getTax() << " | "
         << "discount: " << Item1.getDiscount() << endl;

     cout << "total amount: " << Item1.getInvoiceAmount() << endl;
}