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
 * toupper - 
*/