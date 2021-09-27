#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Structs.h"
#define SIZE 16

/*Create bNode*/
bNode * create_node(enum tLabel label, info * infN, bNode * left, bNode * right) {
    bNode *new;
    new = (bNode *) malloc(sizeof(bNode));
    new->fact = label;
    new->left = left;
    new->right = right;
    new->infoN = infN;
    /*Insercion en la lista (tabla de simbolos)*/
    /*corregir, no queremos almacenar todos los nodos
    la lista debe ser de infotouken*/
    return new;
}

/*Free up memory*/
void freeMemory(bNode * tree) {
    if (tree)
    {   
        freeMemory(tree->left);
        freeMemory(tree->right);
        free(tree);
    }
}

/*Walk the tree*/
void inOrder(bNode * tree) {
    if (tree)
    {   
        inOrder(tree->left);
        printf(" %s |", tree->infoN->name);
        inOrder(tree->right);
    }
}

/*con el arbol ya generado, recorrerlo como en el inorder y armar la tabla de simbol*/