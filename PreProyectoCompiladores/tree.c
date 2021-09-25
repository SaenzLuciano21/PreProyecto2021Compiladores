#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "symbol-table.c"
#define SIZE 16

/*Definicion de tipos enumerados*/
enum tType{bool, integer};
enum tLabel{DEC, STM, VAL, VAR, SUMA, MULT, RESTA, PROG};

/*Estructura del nodo*/
typedef struct infoToken {
    int value;
    int line;
    enum tType type;
    char * name;
} info;

/*Estructura del arbol*/
struct bTree {
    enum tLabel fact;
    struct bTree * right, * left;
    info * infoN;
};

/*Definicion del nombre del arbol*/
typedef struct bTree node;

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
    Insert(lista, infN->name, infN->value, infN->value);
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