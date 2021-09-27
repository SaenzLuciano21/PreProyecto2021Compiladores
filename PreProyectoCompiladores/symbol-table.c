#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Structs.h"

/*hacer lo mismo que en el node, retornar la lista xq sino tendremos problemas con los punteros de punteros*/
/*Insertar nodo*/
TList *insert(TList *lista)
{
    TList *nuevo;
    nuevo = (TList *)malloc(sizeof(TList));
    nuevo->next = lista;
    lista = nuevo;
    return nuevo;
}

/*Imprimir lista*/
void showList(TList *lista)
{
    TList *nodo = lista;

    if (IsEmpty(nodo))
        printf("Lista vacia\n");
    else
    {
        while (nodo)
        {
            printf("%s - %d -> ", nodo->infoN->name, nodo->infoN->value);
            nodo = nodo->next;
        }
        printf("\n");
    }
}

/*Vaciar toda la lista*/
void emptyList(TList *lista)
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
int isEmpty(TList *lista)
{
    return (lista == NULL);
}

/*hacer otra funcion de getelement*/
/*retornar el puntero a toda la info de las variables*/
TList *getElement(TList *lista, char *name)
{
    /*Conocer si es vacia*/
    if (!IsEmpty(lista))
    {
        printf(" Lista vacia..!\n");
        return NULL;
    }
    else
    {
        TList *nodo;
        nodo = lista;
        while (lista != NULL)
        {
            if (strcmp(lista->infoN->name, name) == 0)
            {
                return lista;
            }
            lista = lista->next;
        }
        printf("Elemento no encontrado \n");
        return NULL;
    }
}

/*armar un inorder que muestre el hijo izq con la informacion*/

/**/
int exist(TList *list, char *name)
{
    if (isEmpty(list))
    {
        printf("LISTA VACIA ");
    }
    else
    {
        TList *aux = malloc(sizeof(TList));
        aux = list;
        while (isEmpty(aux) != 1)
        {
            if (strcmp(aux->infoN->name, name) == 0)
            {
                return 1;
            }
            aux = aux->next;
        }
    }
    return 0;
}