#include <iostream>
#include <cstdlib>
#include "arrayutil.h"

using namespace std;

/*
 * Main method establishes the array size and the numbers in the array.
 *
 */
int main(){


    int arr[] = {2 ,4 ,1, 3, 99 , 88 , 77 , 101, 141, 69, 420, 94}; //initializes array elements
    int length = sizeof(arr)/sizeof(arr[0]); //calculates length of array

    printArray(arr, length);
    cout << "Max Value of Array: " << getMax(arr, length) << endl; //prints the max value in arr
    cout << "Mean of Array: " << getMean(arr, length) << endl; //prints the mean value in arr
    cout << "Population Variance of Array: " << getVar(arr, length) << endl; //prints pop var of arr
    cout << "Ascending Array Sort: "; //prints the array sorted from smallest to greatest value
    sortArray(arr, length);

    int arrTestTwo[] = {2 ,4 ,1, 3}; //initializes array elements
    length = sizeof(arrTestTwo)/sizeof(arrTestTwo[0]); //calculates length of array

    printArray(arrTestTwo, length);
    cout << "Max Value of Array: " << getMax(arrTestTwo, length) << endl;
    cout << "Mean of Array: " << getMean(arrTestTwo, length) << endl; //prints the mean value in arr
    cout << "Population Variance of Array: " << getVar(arrTestTwo, length) << endl;
    cout << "Ascending Array Sort: "; //prints the array sorted from smallest to greatest value
    sortArray(arrTestTwo, length);

    int arrTestThree[] = {6, 8, 3, 24, 4, 24, 3}; //initializes array elements
    length = sizeof(arrTestThree)/sizeof(arrTestThree[0]); //calculates length of array

    printArray(arrTestThree, length);
    cout << "Max Value of Array: " << getMax(arrTestThree, length) << endl;
    cout << "Mean of Array: " << getMean(arrTestThree, length) << endl;
    cout << "Population Variance of Array: " << getVar(arrTestThree, length) << endl;
    cout << "Ascending Array Sort: ";
    sortArray(arrTestThree, length);


} // main
