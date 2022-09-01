#include <iostream>

using namespace std;

const double PI = 3.141592;

inline double circleArea(const double& radius);

int main(){
    cout << "enter radius: ";
    double radius;
    cin >> radius;
    cout << "circle area is: " << circleArea(radius) << endl;
}

inline double circleArea(const double& radius){
    return PI * radius * radius;
}