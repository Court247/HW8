#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
        int f, f1;
        char buf[6];
        f = open("file.txt", O_RDWR);
        if (!fork()) {
           f1 = lseek(f, 10, SEEK_SET);
           printf("Child: File offset is at byte %d\n", f1);
        } else {
           wait(NULL);
           f1 = lseek(f, 0, SEEK_CUR);
           printf("Parent: File offset is at byte %d\n", f1);
           read(f, buf, 6);
           write(1, buf, 6);
           f1 = lseek(f, 0, SEEK_CUR);
           printf("\nParent: File offset is at byte %d\n", f1);
        }
        exit(0);
} 
