#include <iostream>

/*
 * Task Summary:
 *   - Create a small app that calculates all necessary parameters to drive PWM.
 * Requirements:
 *   - Create a class that encapsulates all the necessary information You would need to set up PWM.
 *      - These are all unsigned integers:
 *        - period_cycles
 *        - prescaler
 *        - overflow
 *        - duty
 *      - All 4 should have setter and getter methods which return or take an argument as a method. NONE of these should write or read from the console.
 *      - Make a string toString() method which returns a string with all the necessary information in human readable form. You'll use this method to call it when You want to write on teh console.
 *   - Create an abstract base class to represent a Processor.
 *     - This should have setter and getter methods too.
 *     - This should also have a toString() method for the same purpose as above.
 *     - This should have methods which return an instance of the class You created first. (The PWM setup info stuff)
 *        - Let's call this method: getPWMParams()
 *        - Create 2 versions of this method: (or You can make it in one version too if You know how and want to.)
 *          - One takes only the percentage of the duty cycle and assumes a frequency to be 250 Hz as a default.
 *          - One takes both.
 *
 *  - Create a main function, where You fill a vector<CPU> with 5 innstances of a type of CPU choosen randomly. Then You iterate the vector and get PWM settings for different paramters. Write out the results to the console.
 *  - Please follow the style guide.
 *
 *  - HINT: https://electronics.stackexchange.com/176922/setting-the-frequency-of-a-pwm-on-a-stm32
 *
 */

using namespace std;

int main()
{

    return 0;
}
