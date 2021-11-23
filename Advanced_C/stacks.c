/**
 * Stacks
 * "Last In First Out" (LIFO) 
 * 
 * push
 * pop
 * peek - looks at an ele without removing it
 * isEmpty - checks to see if its empty
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct stack {
    struct stack *nextNode;
    int val;
};

typedef struct stack Stack;

void push(Stack **stack, int val);
int pop(Stack **stack);
bool isEmpty(Stack **stack);
int peek(Stack **stack);

int main()
{
    Stack *pStack = NULL;

    printf("Pushing\n");
    push(&pStack, 5);
    push(&pStack, 22);

    printf("Popping %d\n", pop(&pStack));
    printf("Peeking at first Element: %d\n", peek(&pStack));
    printf("Popping %d\n", pop(&pStack));

    if (!isEmpty(&pStack))
    {
        printf("Popping %d\n", pop(&pStack));
    }
    
    return 0;
}


void push(Stack **stack, int val)
{
    Stack * newNode = malloc(sizeof(Stack));
    newNode->val = val;
    newNode->nextNode = (*stack);
    (*stack) = newNode;
};

int pop(Stack **stack)
{
    if (*stack == NULL)
    {
        printf("ERROR: The stack is empty\n");
        exit(1);
    }

    Stack *nextNode = (*stack)->nextNode;
    Stack *popedNode = (*stack);
    int val = (*stack)->val;
    if (popedNode != NULL)
    {
        free(popedNode);
    }
    (*stack) = nextNode;
    return val;
}

int peek(Stack **stack)
{
    if (*stack == NULL)
    {
        printf("ERROR: The stack is empty\n");
        exit(1);
    }

    return (*stack)->val;
}

bool isEmpty(Stack **stack)
{
    if (*stack == NULL)
    {
        return true;
    }
    return false;
}