#include <iostream>
using namespace std;
int mystery(int, int);
int main()
{
    cout << "Enter two integers: ";
    int x{0};
    int y{0};

    cin >> x >> y;
    cout << "The result is " << mystery(x, y) << endl;
}
// Parameter b is now free to be both positive and negative
int mystery(int a, int b)
{
    if(b < 0){
        b *= -1;
        a *= -1;
    }
    if (1 == b)
    {
        return a;
    }
    else
    {
        return a + mystery(a, b - 1);
    }
}
