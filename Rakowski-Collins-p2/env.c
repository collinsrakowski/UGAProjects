#include <stdio.h>
#include <unistd.h>
#include <string.h>

extern char **environment;

int main() {
    char **point = environment;
    for (; *point; point++) {
        write(STDOUT_FILENO, *point, strlen(*point));
        write(STDOUT_FILENO, "\n", 1);
    } // for
    return 0;
} // main
