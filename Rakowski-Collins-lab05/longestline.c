#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

/**
 * findLoc finds the size of the file passed in
 *
 * @param file the file that its size is being checked
 * @return size the size of the file in ints
 */
long int findLoc(char* file) {

    FILE* input = fopen(file, "r");

    if(input == NULL) { // checks if the file is available
        printf("File Not Found!");
    } // if

    fseek(input, 0L, SEEK_END); // finds the location of the end of the file
    long int size = ftell(input); // saves the location to size
    fclose(input);

    return size; // returns size
} // findSize

/**
 * Main prints out the number of characters of the longest line of the file.
 *
 * @param argc stores the number of files passed into the file
 * @param *args[] stores the files passed into the command line
 */
int main(int argc, char *args[]) {

    FILE *input;

    for(int i = 1; i < argc; i++) { // iterates through every file

        input = fopen(args[i], "r");
        long int length = findLoc(args[i]);
        char temp[length]; // stores the current line being checked
        char longest[length]; //stores the longest line found

        while(fgets(temp, length + 1, input) != NULL) { // iterates through every line of the file
            if (strlen(longest) < strlen(temp)) { // saves a new longest line if it finds one
                strcpy(longest, temp);
            } // if
        } // while

        if (strstr(longest, "\n") != NULL) { // if it finds a new line it subtracts out the \n
            printf("%ld\n", strlen(longest) - 1);
        } else {
            printf("%ld\n", strlen(longest));
        } // else
    } // for
} // main
