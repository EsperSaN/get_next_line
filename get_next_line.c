#include "get_next_line.h"

int main()
{
    int fd = open("./tes.txt",O_RDONLY);
    printf("%s FD = %d",get_next_line(fd), fd);
}

char *get_next_line(fd)
{
    char *s = "hello";
    if(fd > 0)
    {
        printf("%s","FD IN \n");
        return (s);
    }
    return("NO FD");
}