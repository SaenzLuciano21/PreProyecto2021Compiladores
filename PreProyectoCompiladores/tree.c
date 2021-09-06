#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define SIZE 16

/*tree definition*/
typedef struct nodE
{
    char *fact;
    struct nodE *left;
    struct nodE *right;
} node;

/*prototype*/
node *create_node(char array[], node *left, node *right);
void inOrder(node *facts);
void freeMemory(node *facts);

/*create a node */
node *create_node(char array[], node *left, node *right)
{
    node *new;
    new = (node *)malloc(sizeof(node));
    new->fact = array;
    new->left = left;
    new->right = right;
    return new;
}

/*walk the tree*/
void inOrder(node *facts)
{
    if (facts != NULL)
    {
        inOrder(facts->left);
        printf(" %s |", facts->fact);
        inOrder(facts->right);
    }
}

/*free up memory*/
void freeMemory(node *facts)
{
    if (facts != NULL)
    {
        freeMemory(facts->left);
        freeMemory(facts->right);
        free(facts);
    }
}