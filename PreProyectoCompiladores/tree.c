#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define SIZE 16

/*
typedef struct infoToken 
{
    int value;
    int line;
} info;
*/

struct bTree {
    char * fact;
    struct btree * right, * left;
};

typedef struct bTree node;

node * create_node(char array[], node * left, node * right)
{
    node *new;
    new = (node *) malloc(sizeof(node));
    new->fact = array;
    new->left = left;
    new->right = right;
    return new;
}

/*free up memory*/
void freeMemory(node * tree)
{
    if (tree)
    {   
        freeMemory(tree->fact);
        freeMemory(tree->left);
        freeMemory(tree->right);
        free(tree);
    }
}

/*walk the tree*/
void inOrder(node * tree)
{
    if (tree)
    {
        inOrder(tree->left);
        printf(" %s |", tree->fact);
        inOrder(tree->right);
    }
}