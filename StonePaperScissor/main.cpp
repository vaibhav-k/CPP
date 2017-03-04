#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int player1;
    int player2;

    cout << "Type 0 for stone, ";
    cout << "1 for scissors, 2 for paper\n";
    cout << "Enter player 1's move\n";
    cin >> player1;
    cout << "Enter player 2's move\n";
    cin >> player2;

    if (player1 == player2)
    {
        cout << "It's a draw!\a\n";
    }
    else
    {
        int diff;

        diff = player1 - player2;

        if (diff == -2 || diff == 1)
        {
            cout << "Player 1 won!\a\n";
        }
        else
        {
            cout << "Player 2 won!\a\n";
        }
    }
}
