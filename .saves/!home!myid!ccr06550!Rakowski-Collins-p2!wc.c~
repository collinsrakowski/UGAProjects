#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFF 100000

int getBytes(int k, char *file[]) { // works lol ez
    int bytes = 0;
    int fd;
    fd = open(file[k], O_RDWR);
    bytes = lseek(fd, 1, SEEK_END) - 1;
} //get Bytes

int getnewLines(int k, char *file[]) { // works lol ez
    int fd;
    int posEnd;
    int things = 0;
    char buffer[BUFF];
    int numLines = 0;
    fd = open(file[k], O_RDWR);
    posEnd = lseek(fd, 1, SEEK_END);
    lseek(fd, 0, SEEK_SET);
    read(fd, buffer, BUFF);
    for (int k = 0; ((k < BUFF) && (k != posEnd)); k++) {
        if (buffer[k] == '\n') {
            numLines++;
        } // if
        things++;
    } // for
    return numLines;
} // getnewlines

int getWords(int k, char *file[]) {
    int fd;
    int posEnd;
    int things = 0;
    char buffer[BUFF];
    int words = 0;
    int gate = 0;
    int isSpace = 0;
    fd = open(file[k], O_RDWR);
    posEnd = lseek(fd, 1, SEEK_END);
    lseek(fd, 0, SEEK_SET);
    read(fd, buffer, BUFF);
    char lastchar = '\n';

    for (int k = 0; ((k < BUFF) && (k != posEnd)); k++) {

        if ((buffer[k] != ' ') && (gate == 0)) {
            words++;
            gate = 1;
//            printf("beg word %d\n", buffer[k]);
        }
        if ((buffer[k] == ' ') || (buffer[k] == '\n')) {
            if ((buffer[k-1] == ' ') || (buffer[k-1] == '\n')) {
//                gate = 0;
            } else {
                gate = 0;
            }
        }// if

    } // for

/*
    if ((buffer[posEnd] == ' ') || (buffer[posEnd] == '\n')) {
        words -= 1;
    }
*/
    close(fd);
    return words;
} // getnewlines

int main(int argc, char *argv[]) {

    int arr[argc + 1];
    int path = 0;
    /*

    int save = getBytes(1, argv);
    printf("getbytes %d\n", save);
    int numLines = getnewLines(1, argv);
    printf("numlines %d\n", numLines);
    int words = getWords(1, argv);
    printf("words %d\n", words);
    */

     if (argc < 2) {
            printf("ERROR: You need at least one argument.\n");
            return -1;
     }
     int place = 0;
     int h = 0;
     for (char **pargv = argv+1; *pargv != argv[argc]; pargv++) {
         place++;
         for (char *ptr = *pargv; *ptr != '\0'; ptr++) {

             if (*ptr == '-' && *ptr == 'c') {
                 path = path + 100;
             } else if (*ptr == '-' && *ptr == 'l') {
                 path = path + 10;
             } else if (*ptr == '-' && *ptr == 'w') {
                 path = path + 1;
             } else {
                 // this should let us know where the args are
                 arr[h] = place;
                 h++;
             }

         }
         printf ("yikes \n");

     }
     printf("place %d\n", arr[h]);
     printf("path %d\n", path);

//    return 0;


/*
    switch(path) {
    case '100':
        printf(loser);
//        getBytes(1, argv);
        break;
    case '110':
        break;
    case '111':
        break;
    case '101':
        break;
    case '001':
        break;
    case '010':
        break;
    case '000':
        break;
    case '011':
        break;
    } // switch

    return 0;
*/
} // main
