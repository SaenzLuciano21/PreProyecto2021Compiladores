%{

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tree.c"

%}
%union { int i; char *s; }
%token<i> INT
%token<s> ID
%token<s> TMENOS
%token<s> BOOL
%token<s> TRUE
%token<s> FALSE
%token<s> RETURN
%token<s> INTEGER

/*precedence*/
%left '+' TMENOS
%left '*'

%%
program: declaration ';' statements { printf("No hay errores \n"); }
;

type: INTEGER           
| BOOL                  
;

statements: statement
| statement statements
;

statement: RETURN expression ';'
| ID '=' expression ';'
;

declaration: type ID '=' expression ';'
| type ID '=' expression ';' declaration           
;

expression: ID      
    | value        
    | expression '+' expression 
    | expression '*' expression 
    | expression TMENOS expression 
    | '(' expression ')' 
    ;

value: INT     
    | boolean   
    ;

boolean: TRUE  
    | FALSE     
    ;
%%