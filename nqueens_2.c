#include <stdio.h>

void placeRooks(int board[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = (i == j) ? 1 : 0;
        }
    }
}

void printBoard(int board[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int board[8][8];
    placeRooks(board);
    printBoard(board);
    return 0;
}
