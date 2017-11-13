#include <iostream>

using namespace std;

// An average Green Fox attendee codes 6 hours daily
// The semester is 17 weeks long
//
// Print how many hours is spent with coding in a semester by an attendee,
// if the attendee only codes on workdays.
//
// Print the percentage of the coding hours in the semester if the average
// work hours weekly is 52

int main()
{
    int semester_long = 17;
    int daily_codes = 6;
    int average_weekly_working_hours = 52;

    int coding_hours = semester_long * 5 * daily_codes;
    float coding_hours_percentage = (float)coding_hours / (average_weekly_working_hours * semester_long) * 100;

    cout << "Hours spent with coding in a semester by an attendee: " << coding_hours << endl;
    cout << "The percentage of the coding hours in the semester: " << coding_hours_percentage << "%" << endl;

    return 0;
}
