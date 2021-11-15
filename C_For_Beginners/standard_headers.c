// CTL click to view

#include <stdio.h>
#include <stddef.h> // contains some standard deffenitions 
#include <limits.h> // various limits for char and int data types
#include <stdbool.h> // nice shortcut to use true / false instead of 1 / 0
#include <string.h> 
/**
 * Common String methods
 * 
 * strcat - concats two strings
 * strchr - searches a string for the first occurence of a char
 * strcmp - compares two strings
 * strcpy - copies a string to another
 * strlen - returns the len of a string
 * 
 * // Safer for buffer overflows
 * strncat - concats 
 * strncmp - compares
 * strncpy - copy
 * strrchr - returns the LAST occurence of a char
 * strstr - searches a string for the first occurence of a string
 * strtok - breaks the string into tokens based on delimater. ie String.split(' ')
 * 
*/
#include <ctype.h> // character functions
/**
 * tolower - returns the lowercase equivalent of char
 * toupper - duh
*/
#include <math.h>
#include <stdlib.h> // useful utility functions
/**
 * abs - absolute val
 * exit - dump out of the program from any function. 
 * abort - same as exit??
 * getenv - read env vars
 * qsort - sort i think
 * rand - random int. wooo
 * srand - seed the random number
 * system - run any system command
 * assert - supported by the assert.h header
 *          useful for double checking your assumptions in prd
*/
#include <time.h> // self explainatory 
#include <errno.h> // macros for reporting of errs
#include <locale.h> // for formatting currency 
#include <signal.h> // ??
#include <stdarg.h> // ??