
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "symbol-table.c"
#include "tree.c"
#include "Structs.h"

// takes the declarations from the tree and inserts them into the symbol table
TList * findDecs(bNode * tree) {
    if (tree) {

        // list initialization
        TList *symbol_table;
        symbol_table = (TList *) malloc(sizeof(TList));

        // tree traversal (inOrder)
        findDecs(tree->left);
        
        if (tree->fact == DEC) {
            insert(symbol_table, tree->infoN);
        }

        findDecs(tree->right);
    }
}