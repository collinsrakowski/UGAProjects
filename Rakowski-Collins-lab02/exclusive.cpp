#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

/** Exclusive allows the user to input an odd amount of positive integers separated by spaces and
 *  on a single line. The inputted integer that only appears once is printed.
 */
int main()
{

  string input = "";
  stringstream ss;
  stringstream l;
  int length = 0;

  cout << "Enter integers: ";
  getline(cin, input);
  l << input;
  ss << input;

  string temp;
  int f;
  while (!l.eof()) { // gathers size of the array
      l >> temp;
      if (stringstream(temp) >> f) {
          length++;
      } // if
      temp = "";
  } // while

  int *value = new int[length];
  int pos = 0;
  while (!ss.eof()) {
      ss >> temp;
      if (stringstream(temp) >> f) {
          value[pos] = f;
          pos++;
      } // if
      temp = "";
  } // while

  if ((length % 2) != 1) { //ends program if even number of integers
      cout << "Enter an odd number of integers! Try again." << endl;
      return 0;
  }

  for (int a = 0; a < length; a++) { // interates through the array and increments the counter if
      // there is a duplicate.
      int count = 0;
      for (int b = 0; b < length; b++) {
          if (value[a] == value[b]) {
              count++;
          } // if
      } // for
      if (count < 2) {
          cout << "Exclusive: " << value[a] << endl; //prints when exclusive value is found
      } // if
  } // for
  return 0;
} // main
