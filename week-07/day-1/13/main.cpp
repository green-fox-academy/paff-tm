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
            start = clock();
        }
        clock_t getTime()
        {
            return clock() - start / CLOCKS_PER_SEC;
        }
    private:
        clock_t start;
};

int main()
{
    int x;
    Timer t;

    try {
        while (1) {
           if (t.getTime() > 2000) {
                throw 2;
           } else if (feof(stdin)) {
                throw 3;
           }
        }
    }
    catch (int x) {
        switch (x) {
        case 2:
            cout << "Out of Time" << endl;
            break;
        case 3:
            cin >> x;
            cout << "Your number is: " << x << endl;
            break;
        default:
            break;
        }
    }

    cout << x << " | " << t.getTime();
    cin >> x;

    return 0;
}
