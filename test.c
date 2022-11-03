#include <fcntl.h>
#include <unistd.h>
int main()
{
        int f;
        char buf[12];
        f = open("file.txt", O_RDWR);
        read(f, buf, 12);
        write(1, buf, 12);
        read(f, buf, 12);
        write(1, buf, 12);
}
