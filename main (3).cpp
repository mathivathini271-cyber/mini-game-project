#include <iostream>
using namespace std;

char board[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

void displayBoard()
{
    cout << "\n";

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout << " " << board[i][j] << " ";

            if(j < 2)
                cout << "|";
        }

        cout << endl;

        if(i < 2)
            cout << "---|---|---" << endl;
    }
}

bool checkWin(char player)
{
    for(int i = 0; i < 3; i++)
    {
        if(board[i][0] == player &&
           board[i][1] == player &&
           board[i][2] == player)
            return true;

        if(board[0][i] == player &&
           board[1][i] == player &&
           board[2][i] == player)
            return true;
    }

    if(board[0][0] == player &&
       board[1][1] == player &&
       board[2][2] == player)
        return true;

    if(board[0][2] == player &&
       board[1][1] == player &&
       board[2][0] == player)
        return true;

    return false;
}

int main()
{
    char playAgain;

    do
    {
        board[0][0]='1'; board[0][1]='2'; board[0][2]='3';
        board[1][0]='4'; board[1][1]='5'; board[1][2]='6';
        board[2][0]='7'; board[2][1]='8'; board[2][2]='9';

        int choice;
        char player = 'X';
        int moves = 0;
        bool gameOver = false;

        cout << "\n===== TIC TAC TOE GAME =====\n";

        while(!gameOver)
        {
            displayBoard();

            cout << "\nPlayer " << player;
            cout << ", enter position (1-9): ";
            cin >> choice;

            if(choice < 1 || choice > 9)
            {
                cout << "Invalid position! Try again.\n";
                continue;
            }

            int row = (choice - 1) / 3;
            int col = (choice - 1) % 3;

            if(board[row][col] == 'X' ||
               board[row][col] == 'O')
            {
                cout << "Position already occupied!\n";
                continue;
            }

            board[row][col] = player;
            moves++;

            if(checkWin(player))
            {
                displayBoard();
                cout << "\nPlayer " << player << " Wins!\n";
                gameOver = true;
            }
            else if(moves == 9)
            {
                displayBoard();
                cout << "\nGame Draw!\n";
                gameOver = true;
            }
            else
            {
                if(player == 'X')
                    player = 'O';
                else
                    player = 'X';
            }
        }

        cout << "\nPlay Again? (Y/N): ";
        cin >> playAgain;

    } while(playAgain == 'Y' || playAgain == 'y');

    cout << "\nThank You for Playing!\n";

    return 0;
}