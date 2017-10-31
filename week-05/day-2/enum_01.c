/*
 * Take exercise array_function_04.c
 *
 * We're creating an exploration out of it.
 * Create a program that takes user input,  kinds: 'q' 'w' 'a' 's' 'd'.
 * For 'q' it quits.
 * For 'w' it goes up if possible.
 * For 'a' it goes left, for 's' down, for 'd' to the right if possible.
 * Create enums for these steps.
 *
 * Let the user explore the chess board and write out at each case whether the place is empty
 * or if there is a figure, which one is there.
 * And also, if there is a figure which places it could go to, with the possible targets coordinates.
 */

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

typedef enum {LEFT = 'a', RIGHT = 'd', UP = 'w', DOWN = 's'} t_direction;
typedef enum {KING = 'K', QUEEN = 'Q', BISHOP = 'B', PAWN = 'P', HORSE = 'H', ROOK = 'R', NOFIGURE = ' '} t_figure;
typedef struct {
    int x;
    int y;
} t_pos;

void setup_board(char chessboard[8][8]);
void setup_figures(t_figure chessfigures[8][8]);
void print_board(char chessboard[8][8], t_pos actual_pos);
int move_is_ok(t_figure chessfigures[8][8], t_pos pos_from, t_pos pos_to);
int move(t_figure chessfigures[8][8], t_pos pos_from, t_pos pos_to);
void set_cursor_pos(int x, int y);

int main ()
{
    char c = '\0';
    char chessboard[8][8];
    t_figure chessfigures[8][8];
    t_pos pos_actual, pos_from, pos_to;

    setup_board(chessboard);
    setup_figures(chessfigures);
    pos_actual.x = 3;
    pos_actual.y = 2;

    do {
        set_cursor_pos(0,0);
        print_board(chessboard, pos_actual);
        printf("Use a, w, d, s to move on chessboard\n");
        printf("Actual position: %c%d\n", pos_actual.x + 97, pos_actual.y + 1);
        printf("Figure on actual position: %c\n", chessfigures[pos_actual.x][pos_actual.y]);
        c = _getch();

        switch (c) {
        case LEFT:
            if (pos_actual.x > 0) {
                //aprintf("%c", chessboard[pos_actual.x][pos_actual.y])
                pos_actual.x--;
            }
            break;
        case RIGHT:
            if (pos_actual.x < 7)
                pos_actual.x++;
            break;
        case DOWN:
            if (pos_actual.y > 0)
                pos_actual.y--;
            break;
        case UP:
            if (pos_actual.y < 7)
                pos_actual.y++;
            break;
        default:
            break;
        }
    } while (c != 27);

    return 0;
 }

void setup_board(char chessboard[8][8])
{
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 7; x += 2) {
            if (y % 2 == 0) {
                chessboard[x][y] = ' ';
                chessboard[x + 1][y] = 219;
            } else {
                chessboard[x][y] = 219;
                chessboard[x + 1][y] = ' ';
            }
        }
    }
}

void setup_figures(t_figure chessfigures[8][8])
{
    for (int y = 2; y < 6; y++)
        for (int x = 0; x < 8; x++) {
            chessfigures[x][y] = NOFIGURE;
    }

    for (int x = 0; x < 8; x++) {
        chessfigures[x][1] = PAWN;
        chessfigures[x][6] = PAWN;
    }

    chessfigures[0][0] = ROOK;
    chessfigures[7][0] = ROOK;
    chessfigures[0][7] = ROOK;
    chessfigures[7][7] = ROOK;

    chessfigures[1][0] = HORSE;
    chessfigures[6][0] = HORSE;
    chessfigures[1][7] = HORSE;
    chessfigures[6][7] = HORSE;

    chessfigures[2][0] = BISHOP;
    chessfigures[5][0] = BISHOP;
    chessfigures[2][7] = BISHOP;
    chessfigures[5][7] = BISHOP;

    chessfigures[4][0] = KING;
    chessfigures[3][0] = QUEEN;
    chessfigures[4][7] = KING;
    chessfigures[3][7] = QUEEN;
}

void print_board(char chessboard[8][8], t_pos actual_pos)
{
    for (int y = 7; y >= 0; y--) {
        printf("%d ", y + 1);
        for (int x = 0; x < 8; x++) {
            if (x == actual_pos.x && y == actual_pos.y) {
                printf("%c", 'X');
            } else {
                printf("%c", chessboard[x][y]);
            }
        }
        printf("\n");
    }
    printf("  abcdefgh\n\n");
}

int move_is_ok(t_figure chessfigures[8][8], t_pos pos_from, t_pos pos_to)
{
    switch (chessfigures[pos_from.x][pos_from.y]) {
    case 'P':
        // if step one forward
        if (pos_from.y - pos_to.y == 1) {
            return 0;
        // if step one forward, and aside to hit a figure
        } else if ((pos_from.y - pos_to.y == 1) && (pos_from.x - pos_to.x == abs(1)) && (chessfigures[pos_to.x][pos_to.y] != ' ') && (chessfigures[pos_to.x][pos_to.y] != 'X')) {
            return 0;
        } else {
            return -1;
        }
        break;
    case 'H':
        if (((abs(pos_from.x - pos_to.x) == 2) && (abs(pos_from.y - pos_to.x) == 1)) || ((abs(pos_from.x - pos_to.x) == 1) && (abs(pos_from.y - pos_to.y) == 2))) {
            return 0;
        } else {
            return -1;
        }
        break;
    default:
        return -1;
    }
}

int move(t_figure chessfigures[8][8], t_pos pos_from, t_pos pos_to)
{
    if (move_is_ok(chessfigures, pos_from, pos_to) == 0) {
        chessfigures[pos_to.x][pos_to.y] = chessfigures[pos_from.x][pos_from.y];
        if (pos_from.x % 2 == 0 && pos_from.y % 2 == 0)
            chessfigures[pos_from.x][pos_from.y] = ' ';
        else
            chessfigures[pos_from.x][pos_from.y] = 'X';
        return 0;
    } else {
        return -1;
    }
}

COORD coord = {0,0};
void set_cursor_pos(int x, int y)
{
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
