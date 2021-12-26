#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

/** isPrime returns true when an inputted int value is prime. False otherwise.
 *
 * @param a  integer value
 * @return  true if prime, false otherwise
 */
bool isPrime(int a) {
    if (a == 1) {
        return false;
    } // if
    bool y = true;
    for (int i = 2; i < a; i++) { //checks to see if any factors between 2 and a are divisible
        if ((a % i) == 0) {
            y = false;
        } // if
    } // for
    return y;
} // isPrime

/** Primesum calculates the sum of the first chosen amount of prime numbers.
 *  For example, input of 3 would return the sum of the first 3 prime numbers.
 */
int main()
{
    int x = 0; //initialization of variables
    int sum = 0;
    int count = 0;
    int i = 1;

    cout << "Enter integer: " << endl; //console asks user for value
    cin >> x; //input recorded

    if ((x < 1) || (x > 100000)) { //ensures inputted values falls within range
        cout << "Accepted integers: 1<=x<=100000." << endl;
        return 0;
    } // if

    while(x > count) { //adds chosen amount of prime numbers
        if (isPrime(i)) {
            sum += i;
            count++; //count only incremented if prime number is successfully added
        } // if
        i++; //evaluated next integer
    } // while

    cout << "Prime sum: " << sum << endl; //prints out final sum
    return 0;
} // main
