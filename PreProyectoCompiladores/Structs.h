#ifndef Structs_program_h
#define Structs_program_h

/*********************Struct and operations of symbol table***************/

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

/*Definicion de tipos enumerados*/
enum tType
{
    boolean,
    integer
};
enum tLabel
{
    DEC,
    STM,
    VAL,
    VAR,
    SUMA,
    MULT,
    RESTA,
    PROG
};

/*Estructura del nodo*/
typedef struct infoToken
{
    int value;
    int line;
    enum tType type;
    char *name;
};

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
typedef struct bTree node;

/*perfil de las funciones*/
node *create_node(enum tLabel label, info *infN, node *left, node *right);
void freeMemory(node *tree);
void inOrder(node *tree);

#endif