#include <stdio.h>
int main()

/*
create a program which draws a diamond, like this:
      *
    * * *
  * * * * *
* * * * * * *
* * * * * * *
  * * * * *
    * * *
      *
*/

{
    for (int i = 1; i < 5; i++){
        for (int j = 0; j < 4 - i; j++){
            printf("  ");
        }
        for (int j = 0; j < i * 2 - 1; j++){
            printf("* ");
        }
        for (int j = 0; j < 5 - i; j++){
            printf("  ");
        }
        printf("\n");
    }
    for (int i = 4; i > 0; i--){
        for (int j = 0; j < 4 - i; j++){
            printf("  ");
        }
        for (int j = 0; j < i * 2 - 1; j++){
            printf("* ");
        }
        for (int j = 0; j < 5 - i; j++){
            printf("  ");
        }
        printf("\n");
    }

// other solution

    printf("Other solution with parametric size:\n");
    int s = 5; // numbers of lines are s * 2 - 1. s > 0
    for (int i = s - 1; i > -s; i--){
        if (abs(i)>0){
        for (int j = 0; j < abs(i) - 1; j++){
            printf("  ");
        }
        for (int j = 0; j < (s - abs(i)) * 2 - 1 ; j++){
            printf("* ");
        }
        for (int j = 0; j < abs(i) - 1; j++){
            printf("  ");
        }
        printf("\n");
        }
    }

    return 0;
}
