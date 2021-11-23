/**
 * Binary Trees
 * 
 * nodes contain a maximum of two links where none, one, or both can be NULL
 * the root is the first node
 * each link refers to a child
 * -- the left child is the leftSubtree
 * -- the right child is the rightSubtree
 * children of a node are called siblings
 * a node with no children is called a leaf node
 *
 * Binary Search Tree
 * values in the left subtree are LESS than the value of the parent node
 * values in the right subtree are GREATER than the value of the parent node
 * 
 * considered ballanced if every level of the tree is fully filled with the exception of the last level
 * -- on the last lvl, the tree is filled left to right
 * considered full and complete if every level has a left and right child node and all child nodes are on the same level
 * contains NO duplicate node values
 * a node can only be inserted as a leaf node
 * 
 * Operations:
 * insert
 * search (inorder, preorder, postorder) -> c
 * 
 * Search Traversals:
 * - inorder traversal
 * --- steps: traverse the left subtree in order -> process value in the node -> traverse the right subtree in order
 * 
 * - preorder traversal:
 * --- used to create a copy of the tree
 * --- the value in each node is processed as the node is visited
 * --- the values in the left subtree are then processed, then right subtree
 * 
 * - postorder traversal
 * --- used to delete the subtree
 * --- steps: traverse left, then right, then process the value in the node
 * --- the value in each node is not processed until the values of its children are processed
 * 
 * Visualizer: https://www.cs.usfca.edu/~galles/visualization/BST.html
 * GeekForGeeks: https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct treeNode {
    int data;
    struct treeNode *leftPtr;
    struct treeNode *rightPtr;
};
typedef struct treeNode TreeNode;

// DONT OBFUCATE POINTER TO A POINTER TYPES. It makes it a PITA to read
// typedef TreeNode *TreeNodePtr;

void insertNode(TreeNode **treeNode, int val);
void inOrder(TreeNode *tree);
void preOrder(TreeNode *tree);
void postOrder(TreeNode *tree);
void findInTreeInOrder(TreeNode *tree, int val);

int main()
{
    // For comparing output to the geeksforgeeks site
    // int nums[] = {25, 50, 15, 10, 22, 70, 35, 12, 4, 18, 24, 31, 44, 66, 90};

    TreeNode *pRoot = NULL;

    srand(time(NULL)); // seed the random num generator
    printf("The numbers being placed in the tree are:\n");

    for (int i = 0; i < 15; i++)
    {
        int item = rand() % 15;
        printf("%3d\n", item);
        insertNode(&pRoot, item); // Pass in the address of the null initialized node 
    }

    printf("\nThe preOrder traversal is:\n");
    preOrder(pRoot);

    printf("\nThe postOrder traversal is:\n");
    postOrder(pRoot);

    printf("\nThe inOrder traversal is:\n");
    inOrder(pRoot);

    printf("\nSearching in order\n");
    findInTreeInOrder(pRoot, 5);

    printf("\n");
    return 0;
}

void findInTreeInOrder(TreeNode *rootPtr, int val)
{
    if (rootPtr == NULL)
    {
        return;
    }

    if (rootPtr->data == val) 
    {
        printf("%d \n", rootPtr->data);
        return;
    }

    // first recursion: on left child
    inOrder(rootPtr->leftPtr);

    // Print out current node data
    printf("%d ", rootPtr->data);

    // Second recursion: on right child
    inOrder(rootPtr->rightPtr);
}

void insertNode(TreeNode **treePtr, int val)
{
    // if the contents of the address of the ptr is null, create and insert a new leafe node
    if ((*treePtr) == NULL) {
        *treePtr = malloc(sizeof(TreeNode));

        if (treePtr == NULL)
        {
            printf("There was an error inserting data\n");
            exit(1);
        }

        (*treePtr)->leftPtr = NULL;
        (*treePtr)->rightPtr = NULL;
        (*treePtr)->data = val;
    }
    else
    {
        // if the val is less than node's value, insert data into that node's left node
        if (val < (*treePtr)->data) 
        {   
            /**
             * treePtr is a pointer to a pointer. So we need to dereference it to get the original pointer
             * then we need to pass in the address of the left subtree pointer
            */
            insertNode(&(*treePtr)->leftPtr, val);
        } 
        // if the val is greater than the node's value, insert data into that nodes right node
        else if (val > (*treePtr)->data)
        {
            insertNode(&(*treePtr)->rightPtr, val);
        }
        else 
        {
            printf("Duplicate\n");
        }
    }
}

void inOrder(TreeNode *rootPtr)
{
    if (rootPtr == NULL)
    {
        return;
    }

    // first recursion: on left child
    inOrder(rootPtr->leftPtr);

    // Print out current node data
    printf("%d ", rootPtr->data);

    // Second recursion: on right child
    inOrder(rootPtr->rightPtr);
};

void preOrder(TreeNode *rootPtr)
{
    if (rootPtr == NULL)
    {
        return;
    }

    // Print out current node data
    printf("%d ", rootPtr->data);

    // first recursion: on left child
    preOrder(rootPtr->leftPtr);

    // Second recursion: on right child
    preOrder(rootPtr->rightPtr);
};

void postOrder(TreeNode *rootPtr)
{
    if (rootPtr == NULL)
    {
        return;
    }

    // first recursion: on left child
    postOrder(rootPtr->leftPtr);

    // Second recursion: on right child
    postOrder(rootPtr->rightPtr);

    // Print out current node data
    printf("%d ", rootPtr->data);
};