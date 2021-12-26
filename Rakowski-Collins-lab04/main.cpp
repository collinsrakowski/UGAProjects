#include <iostream>
#include <cstdlib>

int a [2] = {1, 2};

const int foo() {
    return 2;
} // foo

const int * bar() {
    return a;
} // bar

int * const baz() {
    return a;
} // baz

int main() {
// part (a)
    int x = foo();
    x++;
    foo()++;

// part (b)
    const int * p1 = bar();
    p1++;
    (*p1)++;
    bar()++;
    (*bar())++;

// part (c)
    const int * p2 = baz();
    p2++;
    (*p2)++;
    baz()++;
    (*baz())++;
    return EXIT_SUCCESS;
} // main
