#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Structs.h"

/*Estructura del nodo
struct node
{
    /*puntero a info token y un puntero a next
    char *name;
    int value, valueBool;
    struct node *next;
};

/*Definicion del nombre de la lista
typedef struct node TList; */

/*hacer lo mismo que en el node, retornar la lista xq sino tendremos problemas con los punteros de punteros*/
/*Insertar nodo*/
void Insert(TList *lista, char *name, int valor, int valorBool)
{
    TList *nuevo;
    nuevo = (TList *)malloc(sizeof(TList));
    nuevo->name = name;
    nuevo->value = valor;
    nuevo->valueBool = valorBool;
    nuevo->next = lista;
    lista = nuevo;
}

/*Imprimir lista*/
void ShowList(TList *lista)
{
    TList *nodo = lista;

    if (IsEmpty(nodo))
        printf("Lista vacia\n");
    else
    {
        while (nodo)
        {
            printf("%s %d -> ", nodo->name, "-", nodo->value);
            nodo = nodo->next;
        }
        printf("\n");
    }
}

/*Vaciar toda la lista*/
void EmptyList(TList *lista)
{
    TList *nodo;
    nodo = lista;

    if (lista != NULL)
    {
        while (lista != NULL)
        {
            nodo = lista;
            lista = lista->next;
            free(nodo);
        }
    }
    else
        printf(" Lista vacia..!\n");
}

/*Lista Vacia*/
int IsEmpty(TList *lista)
{
    return (lista == NULL);
}

/*hacer otra funcion de getelement*/
/*retornar el puntero a toda la info de las variables*/
int getElement(TList *lista, char *name)
{
    /*Conocer si es vacia*/
    if (!IsEmpty(lista))
    {
        printf(" Lista vacia..!\n");
        return -1;
    }
    else
    {
        int aux = -1;
        TList *nodo;
        nodo = lista;
        while (lista != NULL)
        {
            if (strcmp(lista->name, name) == 0)
            {
                aux = lista->value;
                return aux;
            }
            lista = lista->next;
        }
        printf("Elemento no encontrado \n");
        return -1;
    }
}

/*armar un inorder que muestre el hijo izq con la informacion*/