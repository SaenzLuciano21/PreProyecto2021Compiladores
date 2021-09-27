#ifndef Structs_program_h
#define Structs_program_h

/*********************Struct and operations of symbol table***************/

/*Definicion de tipos enumerados*/

enum tLabel { DEC, STM, VAL, VAR, SUMA, MULT, RESTA, PROG };

enum tType { boolean, integer };

/*Estructura del nodo*/
struct infoToken
{
    int value;
    int line;
    enum tType type;
    char *name;
};

typedef struct infoToken info;

/*como deberia ser los nodos de la lista*/
struct node
{
    info *infoN;
    struct node *next;
};

/*Definicion del nombre de la lista*/
typedef struct node TList;

/*perfil de las funciones*/
TList *Insert(TList *lista);
void ShowList(TList *lista);
void EmptyList(TList *lista);
int IsEmpty(TList *lista);
TList *getElement(TList *lista, char *name);

/**********************Structs and operations of tree****************/

/*Definicion del nombre del nodo*/
typedef struct infoToken info;

/*Estructura del arbol*/
struct bTree
{
    enum tLabel fact;
    struct bTree *right, *left;
    info *infoN;
};

/*Definicion del nombre del arbol*/
typedef struct bTree bNode;

/*perfil de las funciones*/
bNode *create_node(enum tLabel label, info *infN, bNode *left, bNode *right);
void freeMemory(bNode *tree);
void inOrder(bNode *tree);

#endif