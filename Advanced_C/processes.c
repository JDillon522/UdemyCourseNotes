/**
 * Processes
 * 
 * #include <sys/types.h>
 * #include <unistd.h>
 * 
 * pid_t getpid(void); - returns the parent id of the calling the calling process
 * 
 * TODO: Research
 * - Message queues
 * - Pipes
 * - Shared memory
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    printf("Program to know PID and PPI's information\n");
    printf("My process ID is %d\n", getpid());
    printf("My parent process ID is %d\n", getppid());
    printf("Cross verification of pid's by execution process commands on shell\n");
    char command[] = sprintf("ps -ef | grep %d", getppid());
    system(command);
    return 0;
}