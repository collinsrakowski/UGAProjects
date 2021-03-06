#include <iostream>
#include <cstddef>
#include "Matrix.h"

using namespace std;

int main() {

  /** Matrices **/
  Matrix small(2,2);

  Matrix med(3,2);
  med.at(0,0) = 2;
  med.at(0,1) = 2; // 2 2
  med.at(1,0) = 2; // 2 2
  med.at(1,1) = 2; // 2 2
  med.at(2,0) = 2;
  med.at(2,1) = 2;

  Matrix med2(3,2);
  med2.at(0,0) = 1;
  med2.at(0,1) = 2;
  med2.at(1,0) = 3;
  med2.at(1,1) = 4;
  med2.at(2,0) = 5;
  med2.at(2,1) = 6;

  Matrix larg(3, 3);
  larg.at(0,0) = 1;
  larg.at(0,1) = 2;
  larg.at(0,2) = 3;
  larg.at(1,0) = 4;
  larg.at(1,1) = 5;
  larg.at(1,2) = 6;
  larg.at(2,0) = 7;
  larg.at(2,1) = 8;
  larg.at(2,2) = 9;
  //Matrix

  Matrix d(2,3);
  d.at(0,0) = 3;
  d.at(0,1) = 6;
  d.at(0,2) = 9;
  d.at(1,0) = 2;
  d.at(1,1) = 4;
  d.at(1,2) = 6;


  /** Testing **/
  cout << "\nDefault constructor: " << endl; /** DEFAULT **/
  small.makeMat(small);

  cout << "\nMatrix A: " << endl;
  med.makeMat(med);

  cout << "\nMatrix B: " << endl;
  med2.makeMat(med2);

  cout << "\nMatrix C: " << endl;
  larg.makeMat(larg);

  cout << "\nMatrix D: " << endl;
  d.makeMat(d);

  cout << "\nCopy constructor copies the Matrix B " << endl; /** COPY **/
  Matrix loser(med2);
  loser.makeMat(loser);

  cout << "\nAdd 3 scalar to Matrix A " << endl;
  med.makeMat(med.add(3));

  cout << "\nAdd Matrix A to Matrix B  " << endl;
  med.makeMat(med.add(med2));

  cout << "\nSubtraction by a scalar of 3 to Matrix A " << endl;
  med.makeMat(med.subtract(3));

  cout << "\nSubtraction of Matrix B by Matrix A " << endl;
  med2.makeMat(med2.subtract(med));

  cout << "\nMultiply Matrix A by a scalar of 8" << endl;
  med.makeMat(med.multiply(8));

  cout << "\nMultiply Matrix A by Matrix D " << endl;
  med.makeMat(med.multiply(d));

  cout << "\nDivide Matrix C by a scalar of 3" << endl;
  larg.makeMat(larg.divide(3));

  cout << "\nTransposed Matrix D" << endl;
  d.makeMat(d.t());

} // main
