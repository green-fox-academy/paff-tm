/*
 * Create a representation of a chess board in the form of a two dimensional character array.
 * Each figure should have a character representing it. Empty places should be a single space: ' '.
 *
 * Create a function which sets up the board.
 *
 * Create a function for checking the moves for each of the figurs. They should get coordinates for the figure and where to move it.
 * They should return 0 if the move is acceptable in chess and -1 if not.
 *
 * Create a function which moves figures by getting the initial coordinate and the target coordinate.
 * This should return -1 if the move was not successful and 0 if all is right and if all is right then also move the figure.
 *
 * Determine what kind of arguments You need for the functions. Write them accordingly.
 *
 * For the sake of this exercise it's enough if You write the specific functions for peasants and horse.
 *
 * In the main functions set up the board and try them. Check if they work as intended.
 */

#include <stdio.h>
#include <stdlib.h>

void setup_board(char chessboard[8][8]);
void print_board(char chessboard[8][8]);
int move_is_ok(char chessboard[8][8], int from_x, int from_y, int to_x, int to_y);
int move(char chessboard[8][8], int from_x, int from_y, int to_x, int to_y);

int main ()
{
    char chessboard[8][8];
    int from_x, from_y, to_x, to_y;

    setup_board(chessboard);
    print_board(chessboard);

    printf("Input from x, from y, to x, to y: ");
    scanf("%d, %d, %d, %d", &from_x, &from_y, &to_x, &to_y);

    if (move(chessboard, from_x - 1, from_y - 1, to_x - 1, to_y - 1) != 0) {
        printf("Wrong step\n");
    }

    print_board(chessboard);

    return 0;
 }

void setup_board(char chessboard[8][8])
{
    for (int i = 2; i < 6; i++) {
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
}

void print_board(char chessboard[8][8])
{
    printf("  12345678\n");
    for (int i = 0; i < 8; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < 8; j++) {
            printf("%c", chessboard[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int move_is_ok(char chessboard[8][8], int from_x, int from_y, int to_x, int to_y)
{
    switch (chessboard[from_y][from_x]) {
    case 'P':
        // if step one forward
        if (from_y - to_y == 1) {
            return 0;
        // if step one forward, and aside to hit a figure
        } else if ((from_y - to_y == 1) && (from_x - to_x == abs(1)) && (chessboard[to_y][to_x] != ' ') && (chessboard[to_y][to_x] != 'X')) {
            return 0;
        } else {
            return -1;
        }
        break;
    case 'H':
        if (((abs(from_x - to_x) == 2) && (abs(from_y - to_y) == 1)) || ((abs(from_x - to_x) == 1) && (abs(from_y - to_y) == 2))) {
            return 0;
        } else {
            return -1;
        }
        break;
    }
}

int move(char chessboard[8][8], int from_x, int from_y, int to_x, int to_y)
{
    if (move_is_ok(chessboard, from_x, from_y, to_x, to_y) == 0) {
        chessboard[to_y][to_x] = chessboard[from_y][from_x];
        if (from_x % 2 == 0 && from_y % 2 == 0)
            chessboard[from_y][from_x] = ' ';
        else
            chessboard[from_y][from_x] = 'X';
        return 0;
    } else {
        return -1;
    }
}


