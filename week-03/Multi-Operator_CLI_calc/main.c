/*        MULTI-OPERATOR CLI CALCULATOR
 * ============================================
 * Greenfox Academy Pallida Cohort Static Class
 *               András Pásztor
 */

//TODO: check header section
//TODO: update comments
//TODO: solve the priorizing of the operators, also handle the negative numbers and subtraction

#include <stdio.h>
#include <string.h>

#include "stringev.h"
#include "operations.h"
#include "screen.h"

int main()
{
    char input_str[80] = "";        //the input string
    double result = 0;              //the result of the calculation

    print_help();
    while (1) {
        gets(input_str);

        // set the cursor position to the end of the input line
        set_cursor_pos(strlen(input_str) + 1, get_cursor_y() - 1);

        remove_spaces(input_str);

        if (strcmp(input_str, "exit") == 0){
            break;
        } else if (strcmp(input_str, "help") == 0) {
            print_help();
        } else if (strcmp(input_str, "clear") == 0) {
            clear_screen();
        } else {
            if (calculate(input_str, &result) == 0) {
                printf("= %g\n", result);
            }
        }
    }
    return 0;
}
