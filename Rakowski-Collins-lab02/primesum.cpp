#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

bool isPrime(int p) {
    if (p == 1) {
        return false;
    } // if
    bool q = true;
    for (int i = 2; i < p; i++) { //checks to see if any factors between 2 and a are divisible
        if ((p % i) == 0) {
            q = false;
        } // if
    } // for
    return q;
} // isPrime

/**
  * Primesum calculates the sum of the first inputted prime numbers.
  */
int main()
{
    int input = 0;
    int sum = 0;
    int count = 0;
    int i = 1;

    cout << "Enter integer: " << endl;
    cin >> input;

    if ((input < 1) || (input > 100000)) { //ensures inputted values falls within range
        cout << "Accepted integers: 1<=x<=100000." << endl;
        return 0;
    } // if

    while(input > count) { //adds all prime numbers
        if (isPrime(i)) {
            sum += i;
            count++;
        } // if
        i++;
    } // while

    cout << "Prime sum: " << sum << endl; //prints out final sum
    return 0;
} // main
