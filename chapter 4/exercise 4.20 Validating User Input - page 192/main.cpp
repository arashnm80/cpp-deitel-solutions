
#include <iostream>
using namespace std;
int main()
{

    unsigned int passes{0};
    unsigned int failures{0};
    unsigned int studentCounter{1};

    while (studentCounter <= 10)
    {
        cout << "Enter result number " << studentCounter << " (1 = pass, 2 = fail): ";
        int result;
        cin >> result;

        if (result == 1)
        {
            passes = passes + 1;
            studentCounter++;
        }
        else if(result == 2)
        {
            failures = failures + 1;
            studentCounter++;
        }
        else
        {
            cout << "Invalid input. please enter again" << endl;
        }

    }

    cout << "Passed: " << passes << "\nFailed: " << failures << endl;

    if (passes > 8)
    {
        cout << "Bonus to instructor!" << endl;
    }
}

