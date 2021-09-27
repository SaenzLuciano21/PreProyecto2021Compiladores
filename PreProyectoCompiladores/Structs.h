#ifndef Structs_program_h
#define Structs_program_h

/*********************Struct and operations of symbol table***************/

/*Definicion de tipos enumerados*/

enum tLabel { DEC, STM, VAL, VAR, SUMA, MULT, RESTA, PROG };

enum tType { bool, integer };

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
typedef struct node list;

/*perfil de las funciones*/
void insert(list *lista, info *nodeinfo);
void showList(list *lista);
void emptyList(list *lista);
list *getElement(list *lista, char *name);
int contains(list *plist, char *name);


/**********************Structs and operations of tree****************/

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
bNode * create_node(enum tLabel label, info * infN, bNode * left, bNode * right);
void freeMemory(bNode *tree);
void inOrder(bNode *tree);

#endif