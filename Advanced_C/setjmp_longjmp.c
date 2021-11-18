/**
 * setjmp can be used like a try/catch
 * longjmp can be used like throw
 */

#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h> 

jmp_buf buff;

void myFunc()
{
    printf("in myFunc\n");
    longjmp(buff, 1);

    // Never reached
    printf("you will never see this because we longjmp'd");
};

// int main()
// {   
//     int i = setjmp(buff); // set the jump to here
//     printf("i = %d\n", i);

//     if (i != 0)
//     {
//         exit(0);
//     }
//     longjmp(buff, 42); // 42 is the return value given to setjmp


//     printf("Does this line get printed?");

//     return 0;
// }

int main()
{
    if (setjmp(buff)) // setjmp initially returns 0. we return 1 in myFunc
    {
        printf("Back in main\n");
    }
    else 
    {
        printf("first time through\n");
        myFunc();
    }

    // Error recovery exe
    switch (setjmp(buff))
    {
    case 0:
        // do something normal
        break;
    
    case 1:
        // handle an unexpected event
        break;
    default:
        die("unexpected and unrecoverable situation returned from longjmp");
        break;
    }


    return 0;
}

