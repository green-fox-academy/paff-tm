#include <stdio.h>
#include <stdlib.h>

//writing ABC with loop like this : aAbBcC...zZ

int main()
{
    for (int i = 65; i < 91; i++) {
        printf("%c%c", i + 32, i);
    }
	return 0;
}
