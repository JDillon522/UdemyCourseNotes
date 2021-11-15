#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
    char * itemName;
    int quantity;
    float price;
    float amount;
};

void readItem(struct Item * item);
void printItem(struct Item * item);

int main()
{
    struct Item item;
    struct Item * pItem = NULL;
    pItem = &item;

    readItem(pItem);
    printItem(pItem);

    return 0;
}

// Get the item name from the user
void readItem(struct Item * item)
{
    // Assign the temp to hold the input
    char temp[100];
    printf("Define the structure:\n\tName: ");
    fgets(temp, 100, stdin);
    // Allocate memory of the necessary size
    item->itemName = (char *)calloc(strlen(temp) + 1, sizeof(char));
    if (!item->itemName) 
    {
        exit(-1);
    }
    // copy temp to allocated memory
    strcpy(item->itemName, temp);

    // Normalish
    printf("\tPrice: ");
    scanf("%f", &item->price);

    printf("\tQuantity: ");
    scanf("%d", &item->quantity);

    item->amount = item->price * (float)item->quantity;
}

// Cough it back out
void printItem(struct Item * item)
{
    printf("\nThe item details are:\n\tItem Name: %s\n\tQty On Hand: %d\n\tPrice: %.2f\n\tAmount: %.2f\n\n",
        item->itemName, item->quantity, item->price, item->amount);
}