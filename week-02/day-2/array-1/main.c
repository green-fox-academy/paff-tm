#include <stdio.h>

int main() {
    char my_name_array[] = "Andras Pasztor";

	//TODO:
    // Print out the array character-by-character
    for (int i = 0; i < sizeof(my_name_array); i++)
        printf("%c", my_name_array[i]);

    return 0;
}
