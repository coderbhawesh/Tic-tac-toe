#include <stdio.h>
#include <stdbool.h>

typedef struct {
    char board[3][3];
    char turn;
    bool draw;
} TicTacToe;

void initializeBoard(TicTacToe* game) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            game->board[i][j] = '1' + i * 3 + j;
        }
    }
    game->turn = 'X';
    game->draw = false;
}

void displayBoard(const TicTacToe* game) {
    printf("PLAYER - 1 [X]\tPLAYER - 2 [O]\n\n");
    printf("\t\t     |     |     \n");
    printf("\t\t  %c  | %c  |  %c \n", game->board[0][0], game->board[0][1], game->board[0][2]);
    printf("\t\t_____|_____|_____\n");
    printf("\t\t     |     |     \n");
    printf("\t\t  %c  | %c  |  %c \n", game->board[1][0], game->board[1][1], game->board[1][2]);
    printf("\t\t_____|_____|_____\n");
    printf("\t\t     |     |     \n");
    printf("\t\t  %c  | %c  |  %c \n", game->board[2][0], game->board[2][1], game->board[2][2]);
    printf("\t\t     |     |     \n");
}

void playerTurn(TicTacToe* game) {
    int choice;
    int row, column;

    if (game->turn == 'X') {
        printf("\n\tPlayer - 1 [X] turn : ");
    } else if (game->turn == 'O') {
        printf("\n\tPlayer - 2 [O] turn : ");
    }

    scanf("%d", &choice);

    // switch case to get which row and column will be updated
    switch (choice) {
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
            printf("Invalid Move");
            playerTurn(game);
    }

    if (game->turn == 'X' && game->board[row][column] != 'X' && game->board[row][column] != 'O') {
        game->board[row][column] = 'X';
        game->turn = 'O';
    } else if (game->turn == 'O' && game->board[row][column] != 'X' && game->board[row][column] != 'O') {
        game->board[row][column] = 'O';
        game->turn = 'X';
    } else {
        printf("Box already filled!\nPlease choose another!!\n\n");
        playerTurn(game);
    }

    displayBoard(game);
}

bool isGameOver(const TicTacToe* game) {
    int i;

    // Check for win in rows and columns
    for (i = 0; i < 3; i++) {
        if ((game->board[i][0] == game->board[i][1] && game->board[i][0] == game->board[i][2]) ||
            (game->board[0][i] == game->board[1][i] && game->board[0][i] == game->board[2][i])) {
            return true;
        }
    }

    // Check for win in diagonals
    if ((game->board[0][0] == game->board[1][1] && game->board[0][0] == game->board[2][2]) ||
        (game->board[0][2] == game->board[1][1] && game->board[0][2] == game->board[2][0])) {
        return true;
    }

    // Check if the game is in continue mode or not
    for (i = 0; i < 3; i++) {
        int j;
        for (j = 0; j < 3; j++) {
            if (game->board[i][j] != 'X' && game->board[i][j] != 'O') {
                return false;
            }
        }
    }

    game->draw = true;
    return true;
}

void playGame() {
    TicTacToe game;
    initializeBoard(&game);
    printf("\t\t\tT I C K -- T A C -- T O E -- G A M E\t\t\t");
    printf("\n\t\t\t\tFOR 2 PLAYERS\n\t\t\t");

    while (!isGameOver(&game)) {
        displayBoard(&game);
        playerTurn(&game);
    }

    if (game.turn == 'X' && !game.draw) {
        printf("\n\nCongratulations! Player with 'X' has won the game");
    } else if (game.turn == 'O' && !game.draw) {
        printf("\n\nCongratulations! Player with 'O' has won the game");
    } else {
        printf("\n\nGAME DRAW!!!\n\n");
    }
}

int main() {
    playGame();
    return 0;
}
