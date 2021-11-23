/**
 * Queues
 * "First in First Out" (FIFO)
 * 
 * enqueue - add an element to the back
 * dequeue - remove an element from the front
 * isEmpty
 * isFull
 * peek - val of the first
 * 
 * 
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct queueNode {
    struct queueNode *pNext;
    struct queueNode *pPrevious;
    int val;
};
typedef struct queueNode QN;

struct queue {
    QN *pNext;
    QN *pLast;
    int length;
    int limit;
};
typedef struct queue Queue;

void enqueue(Queue *queue, int val);
int dequeue(Queue *queue);
bool isEmpty(Queue *queue);
bool isFull(Queue *queue);
int peek(Queue *queue);

int main()
{
    Queue queue = {.limit = 5};
    Queue *pQueue = NULL;
    pQueue = &queue;

    printf("Is empty? %s\n", isEmpty(pQueue) ? "True" : "False");
    enqueue(pQueue, 1);
    enqueue(pQueue, 2);
    printf("Is empty? %s\n", isEmpty(pQueue) ? "True" : "False");
    enqueue(pQueue, 3);
    enqueue(pQueue, 4);
    enqueue(pQueue, 5);
    
    printf("Is full? %s\n", isFull(pQueue) ? "True" : "False");

    printf("Peeking %d\n", peek(pQueue));
    printf("%d\n", dequeue(pQueue));
    printf("%d\n", dequeue(pQueue));
    printf("%d\n", dequeue(pQueue));

    printf("\n");
    return 0;
}

bool isFull(Queue *queue)
{
    return queue->length == queue->limit;
}

bool isEmpty(Queue *queue)
{
    return queue->length == 0;
}

void enqueue(Queue *queue, int val)
{
    if (queue->length == queue->limit) 
    {
        printf("\nThe queue is full at %d nodes\n", queue->length);
        exit(1);
    }

    QN *newNode = malloc(sizeof(QN));
    if (!newNode)
    {
        printf("\nThere was an issue assigning memory for a new queue node\n");
        exit(2);
    }
    newNode->val = val;                     // set the val
    newNode->pPrevious = queue->pLast;      // set the node's previous to the last in the line

    if (queue->pLast)                       
    {
        queue->pLast->pNext = newNode;      // if there was at least one element then assign 
    }                                       // the last element's next node to the new node
    
    queue->pLast = newNode;                 // Add the new node to the end

    if (!queue->pNext)                      // If the queue is empty also set the new node as the next node
    {
        queue->pNext = newNode;
    }
    queue->length += 1;                     // increment counter
}

int dequeue(Queue *queue)
{
    if (queue->length == 0)                      // exit if the list is empty. Could track the lenght too 
    {
        printf("\nError: The queue is empty. Check length first\n");
        exit(3);
    }

    QN *node = queue->pNext;                
    queue->pNext = node->pNext;             // Set the queue's next to the element after the node
    int val = node->val;                    // save the val for after the node is deleted
    queue->length -= 1;
    
    if (queue->length == 0)                 // if its empty after decrementing then set the last node to NULL as well
    {
        queue->pLast = NULL;
    }

    return val;
}

int peek(Queue *queue)
{
    if (queue->length == 0)
    {
        printf("\nThe queue is empty. Check first\n");
        exit(4);
    }
    return queue->pNext->val;
}
