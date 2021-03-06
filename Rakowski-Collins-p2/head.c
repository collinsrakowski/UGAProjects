#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFF 1500

int isNumber(char number[])
{
    int i = 0;

    //checking for negative numbers
    if (number[0] == '-')
        i = 1;
    for (; number[i] != 0; i++)
    {
        //if (number[i] > '9' || number[i] < '0')
        if (!isdigit(number[i]))
            return 1;
    }
    return 0;
}

int main(int argc, char *argv[]) {

    int temp1;
    int temp2;
    int iterate = 1;
    int sub = 0;
    int actLines;
    int actBytes;
    //  char *bytes;
    // char *yikes;
    char option;
    int arr[argc];
//    int newlineCounter = 0;
//    char buf[100]


    for(int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-n") == 0) { // if its output is zero then they are the same
            if (isNumber(argv[i + 1]) ==  0) {
//                char *lines = argv[i + 1];
                temp1 = i + 1;
                actLines = atoi(argv[temp1]);
                printf("Number of lines read: %d\n", actLines);
                option = 'A';
                sub++;
            } else {
                printf("Please give a number of lines to read after -n\n");
                exit(0);
            } // else
        } else if (strcmp(argv[i], "-c") == 0) {
            if (isNumber(argv[i + 1]) ==  0) { // crashes if you do not give it a number lol
                //              char *bytes = argv[i + 1];
                temp2 = i + 1;
                actBytes = atoi(argv[temp2]);
                printf("Number of bytes read: %d\n", actBytes);
                option = 'B';
                sub++;
            } else {
                printf("Please give a number of chars to read after -c\n");
                exit(0);
            } // else
        } else {
//            int arr[argc];
            arr[iterate] = i; // saves position of the files
            iterate++;
        }

    } // for

    for (int j = 1; j < argc - sub; j++) {
        int fd;
        int posEnd;
        int things = 0;
        char buffer[BUFF];
        fd = open(argv[arr[j]], O_RDWR); //O_RDONLY
        posEnd = lseek(fd, 1, SEEK_END); // finds the end of the file
        lseek(fd, 0, SEEK_SET); // when it finds the end needs to be set to beginning
        if (fd != -1) {
            switch(option){
            case 'A':
                read(fd, buffer, BUFF);
                int l = 0;
                for (int k = 0; (((k < BUFF) && ( l < actLines)) && (things != posEnd)); k++) {
                    if (buffer[k] == '\n') {
                        l++;
                    }
                    things++;
                } // for
                write(STDOUT_FILENO, buffer, things);
                break;
            case 'B': // done I think
                read(fd, buffer, posEnd);
                write(STDOUT_FILENO, buffer, actBytes);
                break;
            default:
                break;
            } // switch
        } else {
//            printf("Invalid File. Try again!");
            //          exit(0);
        }
    } // for

    return(0);

} // main
