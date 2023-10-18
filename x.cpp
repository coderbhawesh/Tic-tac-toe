#include <iostream>
#include <stdlib.h>
using namespace std;

class TicTacToe
{
private:
    char board[3][3];
    char turn;
    bool draw;

public:
    TicTacToe()
    {
        // Initialize the board
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                board[i][j] = '1' + i * 3 + j;
            }
        }
        turn = 'X';
        draw = false;
    }

    void displayBoard()
    {
        cout << "PLAYER - 1 [X]\tPLAYER - 2 [O]\n\n";
        cout << "\t\t     |     |     \n";
        cout << "\t\t  " << board[0][0] << "  | " << board[0][1] << "  |  " << board[0][2] << " \n";
        cout << "\t\t_____|_____|_____\n";
        cout << "\t\t     |     |     \n";
        cout << "\t\t  " << board[1][0] << "  | " << board[1][1] << "  |  " << board[1][2] << " \n";
        cout << "\t\t_____|_____|_____\n";
        cout << "\t\t     |     |     \n";
        cout << "\t\t  " << board[2][0] << "  | " << board[2][1] << "  |  " << board[2][2] << " \n";
        cout << "\t\t     |     |     \n";
    }

    void playerTurn()
    {
        int choice;
        int row, column;

        if (turn == 'X')
        {
            cout << "\n\tPlayer - 1 [X] turn : ";
        }
        else if (turn == 'O')
        {
            cout << "\n\tPlayer - 2 [O] turn : ";
        }

        cin >> choice;

        // switch case to get which row and column will be updated
        switch (choice)
        {
        case 1:
            row = 0;
            column = 0;
            break;
        case 2:
            row = 0;
            column = 1;
            break;
        case 3:
            row = 0;
            column = 2;
            break;
        case 4:
            row = 1;
            column = 0;
            break;
        case 5:
            row = 1;
            column = 1;
            break;
        case 6:
            row = 1;
            column = 2;
            break;
        case 7:
            row = 2;
            column = 0;
            break;
        case 8:
            row = 2;
            column = 1;
            break;
        case 9:
            row = 2;
            column = 2;
            break;
        default:
            cout << "Invalid Move";
            playerTurn();
        }

        if (turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O')
        {
            board[row][column] = 'X';
            turn = 'O';
        }
        else if (turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O')
        {
            board[row][column] = 'O';
            turn = 'X';
        }
        else
        {
            cout << "Box already filled!\nPlease choose another!!\n\n";
            playerTurn();
        }

        displayBoard();
    }

    bool isGameOver()
    {
        // Check for win in rows and columns
        for (int i = 0; i < 3; i++)
        {
            if (board[i][0] == board[i][1] && board[i][0] == board[i][2] ||
                board[0][i] == board[1][i] && board[0][i] == board[2][i])
            {
                return true;
            }
        }

        // Check for win in diagonals
        if (board[0][0] == board[1][1] && board[0][0] == board[2][2] ||
            board[0][2] == board[1][1] && board[0][2] == board[2][0])
        {
            return true;
        }

        // Check if the game is in continue mode or not
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] != 'X' && board[i][j] != 'O')
                {
                    return false;
                }
            }
        }

        draw = true;
        return true;
    }

    void playGame()
    {
        cout << "\t\t\tT I C K -- T A C -- T O E -- G A M E\t\t\t";
        cout << "\n\t\t\t\tFOR 2 PLAYERS\n\t\t\t";

        while (!isGameOver())
        {
            displayBoard();
            playerTurn();
        }

        if (turn == 'X' && !draw)
        {
            cout << "\n\nCongratulations! Player with 'X' has won the game";
        }
        else if (turn == 'O' && !draw)
        {
            cout << "\n\nCongratulations! Player with 'O' has won the game";
        }
        else
        {
            cout << "\n\nGAME DRAW!!!\n\n";
        }
    }
};

int main()
{
    TicTacToe game;
    game.playGame();
    return 0;
}
