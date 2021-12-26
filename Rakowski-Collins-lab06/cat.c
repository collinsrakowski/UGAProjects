#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main( int argc, char* args[]) {
    if (argc == 1) {
        int n;
        char stdinput[100];
        while ((n = read(STDIN_FILENO, stdinput, 100)) > 0) {
            write(STDOUT_FILENO, stdinput, n);
        }// while
    } else {
        for (int i = 1; i < argc; i++) {
            char* File = args[i];
            if (*File == '-') {
                int n;
                char fileinput[100];
                while ((n = read(STDIN_FILENO, fileinput, 100)) > 0) {
                    write(STDOUT_FILENO, fileinput, n);
                } // while
            } else {
                int fd = open(File, O_RDONLY);
                if (fd == -1) perror ("open");
                int n;
                char writebuffer[100];
                while ((n = read(fd, writebuffer, 100)) > 0) {
                    write(STDOUT_FILENO, writebuffer, n);
                } // while
                if (n == -1) perror( "read" );

                close(fd);
            } // if
        }// for
    }
} // main
