/***
 * Signals
 * 
 * Limited form of inter-process communication (IPC)
 * A way to signal to a process the status of another process
 * When a signal is sent the OS interrupts the target process' normal flow of execution to deliver the signal
 * 
 * A process can receive a particular signal async and at any time
 * - after receiving the singal the process will interrupt its current operations
 * - the process has to stop whatever it is doing and go deal with the signal
 * - it will either handle or ignore the signal, or in some cases terminate
 * 
 * There are a fixed set of signals that can be sent to a process defined by the OS
 * A signal is just a short message that contains a single int val
 * 
 * Signals sent from the terminal:
 * - ctl+z = SIGINT 
 * - ctl+c = SIGSTP
 * - fg / bg = SIGCONT
 * 
 * Default Actions
 * - Term - process will terminate
 * - Core - the process terminates and produces a core dump
 * - Ign - process ignores the sig
 * - Stop - the process stops, like ctl+z
 * - Cont - the process continues after stopping
 * 
 * Common signals:
 * SIGHUP   1   Term    Hangup detected on controlling terminal or death of controlling process
 * SIGINT   2   Term    Interrupt from keyboard
 * SIGQUIT  3   Core    Quit from keyboard
 * SIGILL   4   Core    Illegal instruction
 * SIGABRT  6   Core    Abort signal from abort(3)
 * SIGFPE   8   Core    Floating Point Exception (FPE)
 * SIGKILL  9   TERM    Kill signal
 * SIGSEGV  11  Core    Invalid memory reference
 * SIGPIPE  13  Term    Broken pipe: write to pipe with no readers
 * 
 * Type `kill -l` to see all available signals on the OS
 * 
 * RAISING A SIGNAL
 * <signal.h>
 * 
 * A signal can be generated by calling raise() or kill()
 * - `int raise(int sig)` sends a signal to the current process (the program that contains it)
 *      - After raising the signal the current process stops
 * - `kill()` sends a signal to a specific process
 * 
 * alarm()
 * Provides a mechanism for a process to interrupt itself in the future
 * Sets a timer. When expired the process receives a signal: SIGALARM
 * If we ignore or do not catch the signal the process is terminated
 * The default action for SIGALARM is to terminate the process
 * 
 * Handling A Signal with the signal function
 * #include <signal.h>
 * 
 * typedef void (*sighandler_t)(int); 
 * sighandler_t signal(int signum, sighandler_t handler);
 * 
 * signal(<signum>, <function pointer that handles the signal passing an int>)
 * You can also pass SIG_IGN (ignore the signal) or SIG_DFL (setting signal back to default) as
 * the function instead of defining your own
 */

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handler_divideByZero(int signum);


int main()
{
    void (*sigHandlerReturn)(int);

    sigHandlerReturn = signal(SIGFPE, handler_divideByZero);
    // Junk code that will throw an error because diving by zero is no bueno
    int v1 = 121, v2 = 0;
    int result = v1 / v2;

    return 0;
}

void handler_divideByZero(int signum)
{
    if (signum == SIGFPE)
    {
        printf("Received SIGFPE, Divide by zero exception\n");
        exit(0);
    }

    printf("Received %d Signal\n", signum);
    return;

}