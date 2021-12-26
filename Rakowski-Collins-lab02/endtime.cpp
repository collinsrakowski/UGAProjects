#include <iostream>
#include <cstdlib>

using namespace std;

/** Endtime takes the an inputted start time of a day and then the duration of time
 * that passes and prints an output in military time.
 */
int main()
{
    int time;
    int duration;
    int newTime;

    cout << "Enter in a start time: "; //console requests start time
    cin >> time; //start time recorded
    cout << "Enter in a duration: "; //console requests duration
    cin >> duration; //duration recorded
    newTime = time + duration;

    if (((newTime / 10) % 10) >= 6) { //adds the minutes past 59 to the next hour
        newTime += 40;
    } // if
    if ((newTime / 100) >= 24) { //adds hours past 24 to the next day
        newTime -= 2400;
    } // if
    cout << "End time is: " << newTime << endl;
    return 0;
} // main
