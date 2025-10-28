#include <iostream>
using namespace std;

void printBoard(char board[3][3]) {
    cout << "-------------\n";
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    char currentPlayer = 'X';
    bool gameEnded = false;

    while (!gameEnded) {
        printBoard(board);
        cout << "Player " << currentPlayer << ", enter your move (row and column 0-2): ";
        int row, col;
        cin >> row >> col;

        if (row < 0 || row > 2 || col < 0 || col > 2) {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        if (board[row][col] != ' ') {
            cout << "Cell already taken. Try again.\n";
            continue;
        }

        board[row][col] = currentPlayer;

        if (
            (board[0][0] == currentPlayer && board[0][1] == currentPlayer && board[0][2] == currentPlayer) ||
            (board[1][0] == currentPlayer && board[1][1] == currentPlayer && board[1][2] == currentPlayer) ||
            (board[2][0] == currentPlayer && board[2][1] == currentPlayer && board[2][2] == currentPlayer) ||

            (board[0][0] == currentPlayer && board[1][0] == currentPlayer && board[2][0] == currentPlayer) ||
            (board[0][1] == currentPlayer && board[1][1] == currentPlayer && board[2][1] == currentPlayer) ||
            (board[0][2] == currentPlayer && board[1][2] == currentPlayer && board[2][2] == currentPlayer) ||

            (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
            (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
        ) {
            printBoard(board);
            cout << "Player " << currentPlayer << " wins!\n";
            gameEnded = true;
        } else {
            bool draw = true;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (board[i][j] == ' ') {
                        draw = false;
                    }
                }
            }

            if (draw) {
                printBoard(board);
                cout << "It's a draw!\n";
                gameEnded = true;
            } else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }
    }

    return 0;
}
