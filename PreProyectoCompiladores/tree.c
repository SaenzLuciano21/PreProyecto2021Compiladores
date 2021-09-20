#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define SIZE 16


enum tType{bool, integer};
enum tLabel{DEC, STM, VAL, VAR, SUMA, MULT, RESTA, PROG};

typedef struct infoToken 
{
    int value;
    int line;
    enum tType type;
    char * name;
} info;


struct bTree {
    enum tLabel * fact;
    struct bTree * right, * left;
    info * infoN;
};

typedef struct bTree node;

node * create_node(enum tLabel label, info * infN, node * left, node * right)
{
    node *new;
    new = (node *) malloc(sizeof(node));
    new->fact = label;
    new->left = left;
    new->right = right;
    new->infoN = infN;
    return new;
}

/*free up memory*/
void freeMemory(node * tree)
{
    if (tree)
    {   
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