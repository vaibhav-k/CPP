#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int mark;
    cout << "What was your average mark?\n";
    cin >> mark;

    if (mark >= 70)
    {
        cout << "Congratulation!\n";
        cout << "You got a distinction.\n";
    }
    else if (mark >= 60)
    {
        cout << "Well done!\n";
        cout << "You got a merit!\n";
    }
    else if (mark >= 50)
    {
        cout << "You passed.\n";
    }
    else
    {
        cout << "You failed :-{\n";
    }
}
