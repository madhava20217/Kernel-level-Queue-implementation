Programs:
    1) producer.c   : producer of the bytes, reads 8 bytes (or one unsigned long) sized data from /dev/urandom
                    then writes them to the kernel queue.
    2) consumer.c   : consumer of the bytes, reads and prints as unsigned long from the kernel queue.

Compilation instructions:
    make

Running instructions: 
    1. ./producer
    2. ./consumer

For implementing the queue, the array implementation was used since the fixed size criterion was specified clearly.

There were four syscalls implemented:

1) sys_allocate_queue: requires one parameter: the size of the queue. Allocates a queue and has a pointer point to the structure allocated

2) sys_enqueue_queue: requires one parameter: the element. Enqueues the element in the queue, returns 1 if success, else returns 0 (in case full).

3) sys_dequeue_queue: no parameters required: returns one unsigned long. returns 0 if queue is empty, otherwise the dequeued number.

4) sys_clear_queue: resets the head, tail and the number of items in the queue to 0.

The queue struct is as follows:

> struct queue{
>     int head, tail, numElements, maxElements;
>     unsigned long* arr;
>     atomic_t mutex;               // would be 1 for free, and 0 for not free
> };

The mutex is initialised to 1 in the sys_allocate_queue syscall. 1 implies that the queue is free, and 0 implies that 
the queue is full.

Spinloops were used in the enqueue and dequeue syscalls (based on the mutex).

Enqueue and dequeue operations were done in the standard way for fixed size array based implementations of the queue, however with kmalloc being used for the array initialisation with the GFP_KERNEL flag which implies kernel space allocation.

NOTE: The other syscalls are present in the patch file because I had taken the diff with respect to the original kernel. Please ignore them.
    Command for diff was: diff -r (original linux) (modified linux)  > (patch file path)