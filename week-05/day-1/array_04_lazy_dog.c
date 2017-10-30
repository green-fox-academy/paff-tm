/*
 * Create 9 arrays of characters, each should contain a word.
 * Let it be this: The Quick brown Dog jumps over the Lazy Fox.
 * Create an array of 9 pointers of chractrer type.
 * Make it so, that each pointer points to one of the words. Meaning to one of the original arrays You just created.
 * So You'll have a pointer pointing to each of these original arrays in an array of pointers.
 * Print them out, each in a new line using this array of pointers.
 * Now make it so, that the Fox is Green and he jumps over the lazy dog.
 * Use the existing arrays to achive this.
 * Print it out again.
 */

 #include <stdio.h>

 int main()
 {
     char
         c1[20] = "The",
         c2[20] = "Quick",
         c3[20] = "brown",
         c4[20] = "Dog",
         c5[20] = "jumps",
         c6[20] = "over",
         c7[20] = "the",
         c8[20] = "lazy",
         c9[20] = "fox";

    char *array[9];

    array[0] = c1;
    array[1] = c2;
    array[2] = c3;
    array[3] = c4;
    array[4] = c5;
    array[5] = c6;
    array[6] = c7;
    array[7] = c8;
    array[8] = c9;

    for (int i = 0; i < 9; i++) {
        printf("%s ", array[i]);
    }
    printf("\n");

    strcpy(c3, "green");
    array[3] = c9;
    array[8] = c4;

    for (int i = 0; i < 9; i++) {
        printf("%s ", array[i]);
    }

    return 0;
 }
