#ifndef Structs_program_h
#define Structs_program_h

/*********************Struct and operations of symbol table***************/

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
struct infoToken
{
    int value;
    int line;
    enum tType type;
    char *name;
};

/*como deberia ser los nodos de la lista*/
struct node
{
    struct info *infoN;
    struct TList *next;
};

/*Definicion del nombre de la lista*/
typedef struct node TList;

/*perfil de las funciones*/
TList *insert(TList *lista, struct info *info);
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
    struct info *infoN;
};

/*Definicion del nombre del arbol*/
typedef struct bTree node;

/*perfil de las funciones*/
node *create_node(enum tLabel label, info *infN, node *left, node *right);
void freeMemory(node *tree);
void inOrder(node *tree);


char * infoName(info *n) {
    return n->name;
}

int infoValue(info *n) {
    return n->value;
}

#endif