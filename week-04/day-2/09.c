#include <stdio.h>
#include <conio.h>
#include <time.h>

// NOT WORKING YET

void time_diff(struct tm t1, struct tm t2, struct tm *diff);

struct tm start(time_t raw_tm);
struct tm stop(time_t raw_tm);

//TODO: write a stopwatch program. If you hit enter start the stopwatch, if you hit enter again stop the watch. If you hit escape, the program should exit.
//use the time.h header: https://www.tutorialspoint.com/c_standard_library/c_function_localtime.htm
//it's enough if you can measure the elapsed seconds, and minutes

int main()
{
    struct tm start_time, stop_time, diff;
	time_t raw_time;
    char c;

    do {
    printf("Hit Enter to start.");
        fflush(stdin);
        c = getchar();
    } while (c != '\n');

    start(raw_time);
    
    do {
        c = getch();

        if (c == '\n') {
            stop(raw_time);
        }

	} while(c != 27);


    return 0;
}
