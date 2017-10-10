#include <stdio.h>
#include <stdlib.h>

int main()
{
    char array[] = "cica";
    //char array2[] = {'c', 'i', 'c', 'a', '\0'};

    //printf("%c", array[1]);
    printf("%s\n", array);
    puts(array);

    scanf("%s", array);
    puts(array);

    printf("%d", sizeof(array));

    for (int i = 0; i < sizeof(array); i++)
        printf("%c", array[i]);

    printf("mas\n");

    int array3[2][3] = {
        (1, 2, 3),
        (3, 4, 5),
    };

    printf("%d", array3[1][1]);

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 3; j++) {
            printf("%d", array3[i][j]);
        }
        printf("\n");
    }

    return 0;
}
