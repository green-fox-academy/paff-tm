#include <stdio.h>
#include <stdlib.h>

/*
create a program which prints out the days from monday to sunday
use a loop and variables to do that
for example:
for(int i = 0; i < 6; i++){
    printf("%d\n", i);
}
you can match the numbers with the name of the days
write this program first with if and else-if statements
then do it again with switch-statement
take the conclusion:
    - which method was faster?
    - which was shorter?
    - which one did you find easier?
*/

int main()
{
    for(int i = 0; i < 7; i++){
        if (i == 0)
            printf("%d monday\n", i);
        else if (i == 1)
            printf("%d tuesday\n", i);
            else if (i == 2)
                printf("%d wednesday\n", i);
                else if (i == 3)
                    printf("%d thirsday\n", i);
                    else if (i == 4)
                        printf("%d friday\n", i);
                        else if (i == 5)
                            printf("%d saturday\n", i);
                            else if (i == 6)
                                printf("%d sunday\n", i);
                                else
                                    printf("oups!");

        switch (i) {
        case (0):
            printf("%d monday\n", i);
            break;
        case (1):
            printf("%d tuesday\n", i);
            break;
        case (2):
            printf("%d wednesday\n", i);
            break;
        case (3):
            printf("%d thirsday\n", i);
            break;
        case (4):
            printf("%d friday\n", i);
            break;
        case (5):
            printf("%d saturday\n", i);
            break;
        case (6):
            printf("%d sunday\n", i);
            break;
        }

    }
    return 0;
}
