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
        for(int i = 0;i<3;i++)
        {
            for(int j= 0;j<3;j++)
                board[i][j] = ' ';
        }
        
    }

    void displayBoard() {
        std::cout << "  1 2 3" << std::endl;
        for (int i = 0; i < 3; ++i) {
            std::cout << i + 1 << " ";
            for (int j = 0; j < 3; ++j) {
                std::cout << board[i][j] << " ";
            }
            std::cout << std::endl;
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

    std::cout << "Welcome to Tic-Tac-Toe!" << std::endl;

    do {
        game.displayBoard();
        std::cout << "Player " << game.getCurrentPlayer() << "'s turn. Enter row and column (1-3): ";
        int row, col;
        std::cin >> row >> col;
        --row;
        --col;

        if (game.isValidMove(row, col)) {
            game.makeMove(row, col);
            if (game.checkWin()) {
                game.displayBoard();
                std::cout << "Player " << game.getCurrentPlayer() << " wins!" << std::endl;
                gameEnd = true;
            } else if (game.checkDraw()) {
                game.displayBoard();
                std::cout << "It's a draw!" << std::endl;
                gameEnd = true;
            } else {
                game.switchPlayer();
            }
        } else {
            std::cout << "Invalid move! Try again." << std::endl;
        }
    } while (!gameEnd);

    return 0;
}
