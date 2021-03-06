#include <iostream>
#include <cstdlib>
#include "arrayutil.h"

using namespace std;

/*
 * getMax takes in an array and the length, and returns the max value in the array.
 */
int getMax(int arr[], int length){

    int max = arr[0];
    for(int i = 0; i < length; i++) { // find the max value by comparing each value
        if (arr[i] > max) {
            max = arr[i]; // saves the new highest value to max
        }
    } // for
    return max;
} // get max

/*
 * getMean takes in an array and the length, and returns the mean value of the array.
 */
double getMean(int arr[], int length){
    double mean = 0;
    double average = 0;
    for(int i = 0; i < length; i++) { // adds all the values in the array together
        mean += arr[i];
        average++;
    } // for

    return mean = mean/average; // returns the mean by dividing the sum of the array by the length
} // get mean

/*
 * getVar taks in an array and the length, and returns the population variance of the array.
 */
double getVar(int arr[], int length){
    double sumOne = 0;
    double sumTwo = 0;
    double doubleLength = 0;
    for(int i = 0; i < length; i++) { // calculates the sum of the square of each array value and
        sumOne += arr[i] * arr[i];    // divides by the length of the array.
        doubleLength++;
    } // for
    sumOne = sumOne/doubleLength;

    for(int i = 0; i < length; i++) { // calculates the sum of the array elements, divides by the
        sumTwo += arr[i];             // length of the array, then squares the sum.
    }
    sumTwo = sumTwo/doubleLength;
    sumTwo = sumTwo*sumTwo;

    return sumOne - sumTwo;
} // get var

/*
 * sortArray takes an input array and length and prints the array in ascending order.
 * This method utilizes insertion sort.
 */
void sortArray(int arr[], int length){
    for(int i = 1; i < length; i++) { // implements insertion sort
        int temp = arr[i];
        int comp = i-1;
        while(comp>=0 && temp <= arr[comp]) {
            arr[comp + 1] = arr[comp];
            comp = comp - 1;
        } // while
        arr[comp + 1] = temp;
    } // for

    cout << "{";
    for(int j = 0; j < length; j++) { // print the array in ascending order
        cout << arr[j];
        if (j < length - 1) { // puts the comma in there
            cout << ",";
        } // if
    } // for
    cout << "}" << endl;
} //sort array

void printArray(int arr[], int length){ // prints the array
    cout << "\nArray: {";
    for(int j = 0; j < length; j++) {
        cout << arr[j];
        if (j < length - 1) { // puts the comma in there
             cout << ",";
        } // if
    } // for
    cout << "}" << endl;
}
