/**
 * create a prog that shares files amongst two files
 * 
 * main.c
 * - should include a global var used as a loop counter
 * - includes a main func that uses the global var to iterate through a loop 5 times
 * -- in the loop a func should be invoked (display()) that is defined in another file. Do not use #include <display.h>
 * -- dispaly should take no params
 * 
 * display.c
 * - display()
 * -- displays the global var from main.c (incremented by 1)
 */
#include <stdio.h>

int counter;
extern void display(); 

int main()
{
    counter = 0;

    for ( ; counter < 5; counter++)
    {
        display();
    }
    
}