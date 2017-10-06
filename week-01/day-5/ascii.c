#include <stdio.h>
#include <stdlib.h>

/*your outpu should be something like this:
ASCII value of character 8 = 56
ASCII value of character 9 = 57
ASCII value of character : = 58
ASCII value of character ; = 59
ASCII value of character < = 60
ASCII value of character = = 61
ASCII value of character > = 62
ASCII value of character ? = 63
ASCII value of character @ = 64
ASCII value of character A = 65
ASCII value of character B = 66
*/

/*
Tricky characters are a question how to display...
*/


int main()
{
    for (int i = 1; i < 256; i++) {
        printf("ASCII value of character %c = %d\n", i, i);
    }
	return 0;
}
