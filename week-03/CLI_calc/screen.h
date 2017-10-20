/*  HEADER FILE FOR CLI CALCULATOR
 *  Contains the functions of printing
 *  ==================================
 */

#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED

void print_dec_result(double value);
void print_str_result(char value[]);
void clear_screen();
void print_help();
void set_cursor_pos(int x, int y);
short get_cursor_y();

#endif // SCREEN_H_INCLUDED
