#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tree.c"

/*hacer lo mismo que en el node, retornar la lista xq sino tendremos problemas con los punteros de punteros*/
/*Insertar nodo*/
void insert(list *lista, info *nodeinfo)
{   
    // checks if the element already containss in the list
    if(!contains(lista, nodeinfo->name)) {
        list *nuevo;
        nuevo = (list *)malloc(sizeof(list));
        nuevo->infoN = nodeinfo;
        nuevo->next = lista;
        lista = nuevo;
    }
}

/*Imprimir lista*/
void showList(list *lista)
{
    list *nodo = lista;

    if (!nodo)
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
void emptyList(list *lista)
{
    list *nodo;
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

/*hacer otra funcion de getelement*/
/*retornar el puntero a toda la info de las variables*/
list *getElement(list *lista, char *name)
{
    /*Conocer si es vacia*/
    if (lista)
    {
        printf(" Lista vacia..!\n");
        return NULL;
    }
    else
    {
        list *nodo;
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

/**/
int contains(list *plist, char *name)
{
    if(plist)
    {
        list *aux = malloc(sizeof(list));
        aux = plist;
        while (aux)
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