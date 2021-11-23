/**
 * Linked List Implementation... take 1
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct LinkedNode {
    struct LinkedNode *prevNode;
    struct LinkedNode *nextNode;
    int val;
};

struct LinkedList {
    int length;
    struct LinkedNode * pFirstNode;
    struct LinkedNode * pLastNode;
};

typedef struct LinkedList LL;
typedef struct LinkedNode LN;


// Prototypes
void insert(LL *head, int val);
void insertAtEnd(LL *head, int val);
void insertAtBegining(LL *head, int val);
int deleteList(LL *head);
void deleteAtBegining(LL *head);
void deleteAtEnd(LL *head);
bool isEmpty(LL head);
void printList(LL *pList);


int main()
{
    LL myList = { .length = 0, .pFirstNode = NULL, .pLastNode = NULL };
    LL * pMyList = NULL;

    pMyList = &myList;

    insertAtBegining(pMyList, 0);

    insert(pMyList, 15);
    deleteAtBegining(pMyList);
    insert(pMyList, 5);
    insertAtBegining(pMyList, 5);
    
    printList(pMyList);
    deleteList(pMyList);

    return 0;
}

void insertAtBegining(LL *pList, int val)
{
    pList->length += 1;

    LN * newNode = malloc(sizeof(LN));
    newNode->val = val;
    newNode->nextNode = pList->pFirstNode;
    pList->pFirstNode = newNode;

    if (!pList->pLastNode)
    {
        pList->pLastNode = newNode;
    }
}

void insertAtEnd(LL *pList, int val)
{
    pList->length += 1;

    LN * newNode = malloc(sizeof(LN));
    newNode->val = val;
    newNode->prevNode = pList->pLastNode;
    pList->pLastNode = newNode;
}

void insert(LL *pList, int val)
{
    pList->length += 1;

    LN * newNode = malloc(sizeof(LN));
    newNode->val = val;
    newNode->prevNode = pList->pLastNode;
    newNode->nextNode = NULL;
    pList->pLastNode->nextNode = newNode;
    pList->pLastNode = newNode;
}

void printList(LL *pList)
{
    LN *currentNode = pList->pFirstNode;
    printf("Val: %d\n", currentNode->val);

    
    do 
    {
        currentNode = currentNode->nextNode;
        printf("Val: %d\n", currentNode->val);
    } 
    while (currentNode->nextNode);
    
}

int deleteList(LL *head) // TODO: the list still retains addresses from the pLastNode on down.
{
    while (head->length > 0)
    {
        deleteAtBegining(head);
    }

    // deleteAtEnd(head);
}

void deleteAtBegining(LL *head)
{
    LN *deletingNode = head->pFirstNode;

    head->pFirstNode = deletingNode->nextNode;
    head->length -= 1;
    free(deletingNode);
}   

void deleteAtEnd(LL *head)
{
    LN *deletingNode = head->pLastNode;

    head->pLastNode = deletingNode->prevNode;
    head->length -= 1;
    free(deletingNode);
}   

bool isEmpty(LL head)
{
    return head.length == 0;
}