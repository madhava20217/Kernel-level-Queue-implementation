#include <sys/syscall.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#define sys_allocate_queue 451
#define sys_enqueue_queue 452
#define sys_dequeue_queue 453
#define sys_clear_queue 454

void writeToQueue(){
    /**
     * Function responsible for writing the 8 bytes to the kernel queue
     * 
     */
    unsigned long data;
    FILE *fp;
    fp = fopen("/dev/urandom", "r");
    fread(&data, 8, 1, fp);                 //read 8 bytes from the file (equivalent to one long)
    fclose(fp);

    printf("read from urandom: %lu\n", data);

    syscall(sys_enqueue_queue, data);
}

int main(void){
    

    //allocating queue
    syscall(sys_allocate_queue, 50);

    while(1){
        writeToQueue();
        sleep(2);
    }
    

    return 0;
}