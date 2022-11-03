#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
        int f, f1;
        char buf[6];
        f = open("file.txt", O_RDWR);
        f1 = lseek(f, 10, SEEK_SET);
        printf("File offset is at byte %d\n", f1);
        read(f, buf, 6);
        write(1, buf, 6);
}

