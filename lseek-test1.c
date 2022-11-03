#include <fcntl.h>
#include <unistd.h>
int main()
{
        int f;
        char buf[6];
        f = open("file.txt", O_RDWR);
        read(f, buf, 6);
        write(1, buf, 6);
        lseek(f, 5, SEEK_CUR);
        read(f, buf, 6);
        write(1, buf, 6);
}

