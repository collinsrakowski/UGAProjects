#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

/**
 * findSize finds the size of the any file passed through.
 *
 * @param file takes in the file
 * @return size returns the size of the array
 */
long int findSize(char* file) {

    FILE* input = fopen(file, "r"); // opens files

    if (input == NULL) { // checks to see if there is a file
        printf("File Not Found!");
    } // if

    fseek(input, 0L, SEEK_END); //finds the end of the file
    long int size = ftell(input);
    fclose(input);

    return size;
} // findSize

/**
 * Main prints out the last line in any file passed through the function.
 *
 * @param argc
 * @param *args[]
 * @return exits the main
 */
int main(int argc, char *args[]) {

    FILE *input;
    for(int i = 1; i < argc; i++) { // iterates through any amount of files passed through the cmd

        input = fopen(args[i], "r");
        long int length = findSize(args[i]) + 1; // assigns the size of the file to length
        char temp[length]; // creates a temp array
        int check = 1;

        while (check == 1) {
            if(fgets(temp, length + 1, input) == NULL) { // finds the last line of the file
                check = 0;
            } // if
        } //while
//        printf("\n");
        printf("%s", temp); // last line printed
    } // for

    fclose(input);

    return 0;
} // main
