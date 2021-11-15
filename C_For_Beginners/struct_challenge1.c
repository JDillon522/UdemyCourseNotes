#include <stdio.h>

struct Employee
{
    char name[20];
    int hireDate;
    float slary;
};


int main()
{
    struct Employee joe = { .name = "Joseph", .hireDate = 123, .slary = 124.0 };
    printf("The first employee is %s. He was hired on %d and earns %.2f.\n", joe.name, joe.hireDate, joe.slary);

    struct Employee betty;
    
    printf("Lets enter the new hire's info.\nWhat is the new hire's name? ");
    fgets(betty.name, 20, stdin);

    printf("What is the new hire's hire date? ");
    scanf("%d", &betty.hireDate);

    printf("What is the new hire's salary? ");
    scanf("%f", &betty.slary);

    printf("\nThe new hire is %s, hired on %d with a slary of %.2f\n\n", betty.name, betty.hireDate, betty.slary);

    return 0;
}