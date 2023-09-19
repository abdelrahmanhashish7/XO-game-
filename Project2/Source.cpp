#include <iostream>
using namespace std;

// Function to display the Tic-Tac-Toe board
void displayBoard(char board[3][3]) {
    cout << "Tic-Tac-Toe\n";
    cout << "-------------\n";
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

// Function to check if a player has won
bool checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        // Check rows and columns
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

int main() {
    char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
    int row, col;
    char currentPlayer = 'X';
    int moves = 0;

    while (true) {
        displayBoard(board);

        // Get player input
        cout << "Player " << currentPlayer << ", enter row (1-3) and column (1-3): ";
        cin >> row >> col;

        // Check if the input is valid
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] == 'X' || board[row - 1][col - 1] == 'O') {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        // Update the board
        board[row - 1][col - 1] = currentPlayer;
        moves++;

        // Check for a win or a draw
        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }
        else if (moves == 9) {
            displayBoard(board);
            cout << "It's a draw!\n";
            break;
        }

        // Switch to the other player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
