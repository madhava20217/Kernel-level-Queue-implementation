#include <sys/syscall.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#define clearBuf(buf) memset(&buf, 0, sizeof(buf))  //macro for fast memset
#define numBytes 8                                  // read 8 bytes


void readChars(char* buf)
{
    int fd = open("/dev/urandom", O_RDONLY);
    clearBuf(buf);
    read(fd, buf, numBytes);
    close(fd);
}

int main(void){
    
/*     char buf[numBytes+2];

    readChars(buf);
    printf("%s", buf); */

    int byte_count = 64;
char data[64];
FILE *fp;
fp = fopen("/dev/urandom", "r");
fread(&data, 1, byte_count, fp);
fclose(fp);

printf("%s", data);

    return 0;
}