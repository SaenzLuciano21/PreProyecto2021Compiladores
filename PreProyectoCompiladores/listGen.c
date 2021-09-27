
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "symbol-table.c"

// takes the declarations from the tree and inserts them into the symbol table
void findDecs(list *symbol_table, bNode * tree) {
    if (tree) {

        // tree traversal (inOrder)
        findDecs(symbol_table, tree->left);
         
        if (tree->fact == DEC) {
            if (tree->infoN->name) 
                printf("before insert %s\n", tree->infoN->name);
                insert(symbol_table, tree->infoN);
        }
        findDecs(symbol_table, tree->right);
    }
}