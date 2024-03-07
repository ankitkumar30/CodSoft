#include <iostream>
#include <array>
#include <string>
using namespace std;
class TicTacToe {
private:
    array<array<char, 3>, 3> board;
    char currentPlayer;

public:
    TicTacToe() :  currentPlayer('X') { 
        for(int i = 0; i<3 ; i++)
        {
            for(int j= 0;j<3;j++)
                board[i][j] = ' ';
        }
        
    }

    void displayBoard() {
        cout << "  1 2 3" << endl;
        for (int i = 0; i < 3; ++i) {
            cout << i + 1 << " ";
            for (int j = 0; j < 3; ++j) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }

    bool isValidMove(int row, int col) {
        return row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ';
    }

    void makeMove(int row, int col) {
        board[row][col] = currentPlayer;
    }

    bool checkWin() {
        // Check rows and columns
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
                return true;
            if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
                return true;
        }
        // Check diagonals
        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
            return true;
        if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
            return true;
        return false;
    }

    bool checkDraw() {
        for (const auto& row : board) {
            for (char cell : row) {
                if (cell == ' ')
                    return false; // If there is any empty cell, game is not draw yet
            }
        }
        return true; // If no empty cell found, game is draw
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    char getCurrentPlayer() {
        return currentPlayer;
    }
};

int main() {
    TicTacToe game;
    bool gameEnd = false;

    cout << "Welcome to Tic-Tac-Toe!" << endl;

    do {
        game.displayBoard();
        cout << "Player " << game.getCurrentPlayer() << "'s turn. Enter row and column (1-3): ";
        int row, col;
        cin >> row >> col;
        --row;
        --col;

        if (game.isValidMove(row, col)) {
            game.makeMove(row, col);
            if (game.checkWin()) {
                game.displayBoard();
                cout << "Player " << game.getCurrentPlayer() << " wins!" << endl;
                gameEnd = true;
            } else if (game.checkDraw()) {
                game.displayBoard();
                cout << "It's a draw!" << endl;
                gameEnd = true;
            } else {
                game.switchPlayer();
            }
        } else {
            cout << "Invalid move! Try again." << endl;
        }
    } while (!gameEnd);

    return 0;
}
