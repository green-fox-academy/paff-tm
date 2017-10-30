/*
 * Create a 2 dimensonal array of characters. 8x8
 * Fill the array with X and space alternating.
 * Print it out row by row. (It should resemble a chess board)
 * Designate a character for each chess peace. (Queen could be Q, King could be K, etc.)
 * Set up the start of a game.
 * Print it out again.
 * Make one move with a horse.
 * Print it again.
 */

 #include <stdio.h>

 int main ()
 {
    char chessboard[8][8];

    //fill the array
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j += 2) {
            if (i % 2 == 0) {
                chessboard[i][j] = 'X';
                chessboard[i][j + 1] = ' ';
            } else {
                chessboard[i][j] = ' ';
                chessboard[i][j + 1] = 'X';
            }
        }
    }

    //print the array
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c", chessboard[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    chessboard[0][0] = 'R';
    chessboard[0][7] = 'R';
    chessboard[7][0] = 'R';
    chessboard[7][7] = 'R';

    chessboard[0][1] = 'H';
    chessboard[0][6] = 'H';
    chessboard[7][1] = 'H';
    chessboard[7][6] = 'H';

    chessboard[0][2] = 'B';
    chessboard[0][5] = 'B';
    chessboard[7][2] = 'B';
    chessboard[7][5] = 'B';

    chessboard[0][3] = 'K';
    chessboard[0][4] = 'Q';
    chessboard[7][3] = 'K';
    chessboard[7][4] = 'Q';

    for (int i = 0; i < 8; i++) {
        chessboard[1][i] = 'P';
        chessboard[6][i] = 'P';
    }

    //print the array
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c", chessboard[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    //step with a horse on position 7-1
    int x = 7;
    int y = 1;
    chessboard[x-2][y+1] = chessboard[x][y];

    if (x % 2 == 0 && y % 2 == 0)
        chessboard[x][y] = ' ';
    else
        chessboard[x][y] = 'X';

    //print the array
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c", chessboard[i][j]);
        }
        printf("%c", '\n');
    }
    return 0;
 }
