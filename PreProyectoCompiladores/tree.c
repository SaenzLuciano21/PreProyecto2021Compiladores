#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "symbol-table.c"
#include "Structs.h"
#define SIZE 16

/*Creacion de la lista e inicializacion*/
TList *lista = NULL;

/*Create node*/
node * create_node(enum tLabel label, info * infN, node * left, node * right) {
    node *new;
    new = (node *) malloc(sizeof(node));
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
void freeMemory(node * tree) {
    if (tree)
    {   
        freeMemory(tree->left);
        freeMemory(tree->right);
        free(tree);
    }
}

/*Walk the tree*/
void inOrder(node * tree) {
    if (tree)
    {   
        /*Visualizacion de la tabla de simbolos*/
        ShowList(lista);
        
        /*Visualizacion del arbol
        inOrder(tree->left);
        printf(" %s |", tree->infoN->name);
        inOrder(tree->right);*/
    }
}

/*con el arbol ya generado, recorrerlo como en el inorder y armar la tabla de simbol*/