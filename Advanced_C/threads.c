/**
 * Threads
 * 
 * Threads have their own unique id, program counter (PC), register set, and stack space just like a process.
 * Threads share memory across each thread by having the same address space
 * --- ie: Thread A can change a variable in Thread B
 * 
 * POSIX / pthreads 
 * <pthread.h> API
 * 
 * Make sure you link to the pthread lib when you compile
 * `gcc <file>.c -lpthread`
 * 
 * Categories:
 * Thread Management (creating, joining, etc)
 * Synchronization (read/write locks, mutex, etc)
 * Condition Variables (communication between threads)
 * 
 * Thread lifecycle
 * - Creation: created with a function pointer as the entry point
 * - pthread_create
 *      -- called to create a new thread. main() is the default single thread, all others must be designated by the dev
 *      -- max num of threads is process implementation dependent
 *      -- args: 
 *          `pthread_t` an int to identify the thread on the system
 *          thread attrs, NULL for default values
 *          name of the function that will be executed when created
 *          arguments passed to the function
 * 
 * - pthread_join
 *      -- used to identify when a thread has completed or exited
 *      -- used to link the current process to another thread
 *      -- a thread calling routine may launch multiple threads and wait for them all to complete
 *      -- a call to pthread_join blocks the calling thread until the thread with identifier equal to the first argument terminates
 *      -- All threads are automatically joined when the main thread terminates 
 *      -- receives the return value of the thread function and stores it in a void pointer var
 *      `int pthread_join(pthread_t thread, void ** value_ptr)`
 * 
 * - pthread_exit
 *      -- will automatically exit the thread
 *      -- typically called after the thread ends and doesnt need to exist
 *      `void pthread_exit(void *value_prt)`
 *              
*/

#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>

struct threadExampleData {
    int thread_id;
    int sum;
    char *message;
};

void * hello_fun()
{
    printf("Hello WOrld\n");
    printf("In function \"hello_fun\" and getting the thread id: %ld\n", pthread_self());

    return NULL;
}

void * print_message(void *ptr)
{
    char *message = (char *) ptr;
    printf("%s\n", message);
    printf("In function \"print_message\" and getting the thread id: %ld\n", pthread_self());
    return NULL;
}

void *printHello(void *thread_arg)
{
    struct threadExampleData *data;
    char msg[255];

    data = (struct threadExampleData *) thread_arg;
    int taskid = data->thread_id;
    int sum = data->sum;
    strcpy(msg, data->message);
    printf("Task ID = %d, Sum = %d, Message = %s\n", taskid, sum, msg);
    
}

void *returnSomething(void * args)
{
    char *hello = strdup("Witness Me! *sprays chrome*\n");
    // Get the current thread ID
    printf("In function \"returnSomething\" and getting the thread id: %ld\n", pthread_self());
    return (void *) hello;
}

int main(int argc, char *argv[])
{
    // Without arguments or return value
    pthread_t thread;
    int iter1 = pthread_create(&thread, NULL, hello_fun, NULL);
    // Without a join the main() will just keep going and exit before it can execute
    pthread_join(thread, NULL);

    pthread_t thread2;
    char *message1 = "This is a dumb message\n";
    int iter2 = pthread_create(&thread2, NULL, print_message, (void*) message1);
    
    pthread_join(thread2, NULL);

    // With arguments as a struct
    pthread_t thread3;
    struct threadExampleData myData;
    myData.message = malloc(sizeof(char) * 255);
    myData.sum = 45;
    myData.thread_id = 22;
    myData.message = "HEEELLLOOOOOOO Vietnam!";

    int iter3 = pthread_create(&thread3, NULL, printHello, (void*) &myData);
    pthread_join(thread3, NULL);


    // With return values
    char * str;
    pthread_t thread4;
    int iter4 = pthread_create(&thread4, NULL, returnSomething, NULL);
    pthread_join(thread4, (void **) &str);
    printf("%s", str);

    // printf("Thread 1 return: %d\n", iter1);
    // printf("Thread 2 return: %d\n", iter2);
    // printf("Thread 3 return: %d\n", iter3);
    pthread_exit(NULL);

    printf("\n\n");
    return 0;
}