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

void readFromQueue(){
    /**
     * Function responsible for reading data from the queue.
     * 
     */ 
    unsigned long data = syscall(sys_dequeue_queue);
    if(data != 0) printf("The consumer received data: %lu\n", data);
}

int main(void){
    

    while(1){
        readFromQueue();
        sleep(2);
    }
    return 0;
}