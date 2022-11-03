#include <fcntl.h>
#include <unistd.h>
int main()
{
        int f, f2;
        char buf[12];
        f = open("file.txt", O_RDWR);
        f2 = dup(f);
        read(f, buf, 12);
        write(1, buf, 12);
        read(f2, buf, 12);
        write(1, buf, 12);
        lseek(f2, 0, SEEK_SET);
        read(f, buf, 12);
        write(1, buf, 12);
}

