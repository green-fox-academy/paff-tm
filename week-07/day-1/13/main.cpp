#include <iostream>
#include <cstdio>
#include <ctime>
#include <windows.h>

using namespace std;

// Create a simple program which has a time lock
// The program should ask for a user input, but the user only has
// 10 seconds to reply, if the user fails (reaches the time limit)
// the program should print out: "failed, it took you too much time"
// This program cloud be the engine of a quiz game.

class Timer {
    public:
        Timer()
        {
            //start = clock();
        }
        clock_t getTime()
        {
            return clock() - start_time / CLOCKS_PER_SEC;
        }
        void start()
        {
            start_time = clock();
        }
    private:
        clock_t start_time;
};

int main()
{
    string x;
    Timer t;

    t.start();

    cout << "Add your input: ";
    getline(cin, x);

    if (t.getTime() >= 2000) {
        cout << "Out of Time";
    } else {
        cout << "Great! Your input is: " << x << endl;
    }

    cout << "Elapsed time is: " << (float)t.getTime() / 1000 << " sec" << endl;

    return 0;
}
