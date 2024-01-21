#include <stdio.h>
#include <stdbool.h>
#define N 4 // Define the size of the chessboard
// Function to print the chessboard
void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", board[i][j] ? 'Q' : '.');
        }
        printf("\n");
    }
    printf("\n");
}
// Function to check if a queen can be placed at the given position
bool isSafe(int board[N][N], int row, int col) {
    // Check the left side of the row
    for (int i = 0; i < col; i++) {
        if (board[row][i]) {
            return false;
        }
    }
    // Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }
    // Check lower diagonal on left side
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j]) {
            return false;
        }
    }
    return true;
}
// Recursive function to solve N-Queens problem using backtracking
bool solveNQueens(int board[N][N], int col) {
    if (col == N) {
        // All queens are placed successfully
        printBoard(board);
        return true;
    }
    bool res = false;
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            // Place queen at (i, col)
            board[i][col] = 1;
            // Recur to place queens in the remaining columns
            res = solveNQueens(board, col + 1) || res;
            // If placing queen at (i, col) doesn't lead to a solution, backtrack
            board[i][col] = 0;
        }
    }
    return res;
}
// Function to solve the N-Queens problem
void nQueens() {
    int board[N][N] = {0};
    if (!solveNQueens(board, 0)) {
        printf("Solution does not exist.\n");
    }
}
int main() {
    nQueens();
    return 0;
}
