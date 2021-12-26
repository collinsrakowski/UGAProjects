#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>


/**
 * Main method prints the first line in the file.
 * File can take any number of files through command lines arguments.
 * @param argc
 * @param *args[]
 */
int main(int argc, char *args[]) {

    FILE *input;
    char buf[1000];

    for (int i = 1; i < argc; i++) { // iterates through any number of command line arguments
        fopen(args[i], "r");
        if (args[i] == NULL) { // determines if the file can be opened
        printf("Cannot open file \n");
        exit(0);
    }

    input = fopen(args[i], "r"); // read contents from file
    fgets(buf, 1000, input); // gets the first line and saves it to buf char array
    printf(buf); // prints the first line
    }

    fclose(input);

    return 0;
}
