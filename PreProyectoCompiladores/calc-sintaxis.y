%{

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tree.c"

%}
%union { int i; char *s; struct nodE *p; }
%token<i> INT
%token<s> ID
%token<s> BOOL
%token<s> TRUE
%token<s> FALSE
%token<s> RETURN
%token<s> INTEGER

%type<p> declaration
%type<p> statement
%type<p> statements
%type<p> type
%type<p> expression
%type<p> value
%type<p> boolean

/*precedence*/
%left '+' '-'
%left '*'

%%
program: declaration            { printf("No hay errores \n"); 
                                  inOrder($1);
                                  freeMemory($1); }
;

statements: statement
| statement statements
;

statement: ID '=' expression ';'            { $$ = create_node("=", create_node($1, NULL, NULL), create_node(";", $3, NULL)); }
| RETURN expression ';'                     { $$ = create_node(";", create_node($1, NULL, NULL), $2); }
;

declaration: type ID '=' expression ';'     { $$ = create_node("=", create_node($2, $1, NULL), create_node(";", $4, NULL)); }
| type ID '=' expression ';' declaration    { $$ = create_node("=", create_node($2, $1, NULL), create_node(";", $4, $6)); }
| type ID '=' expression ';' statements     { $$ = create_node("=", create_node($2, $1, NULL), create_node(";", $4, $6)); }
;

type: INTEGER           { $$ = create_node($1, NULL, NULL); }
| BOOL                  { $$ = create_node($1, NULL, NULL); }
;

expression: ID                      { $$ = create_node($1, NULL, NULL); }
| value                             { $$ = $1; }
| expression '+' expression         { $$ = create_node("+", $1, $3); }     
| expression '*' expression         { $$ = create_node("*", $1, $3); }
| expression '-' expression      { $$ = create_node("-", $1, $3); }
| '(' expression ')'                { $$ = create_node("()", $2, NULL); }
;

value: INT                  { char *types = malloc(sizeof(char[SIZE]));
                              sprintf(types, "%d", $1);
                              $$ = create_node(types, NULL, NULL); }
| boolean                   { $$ = $1; }
;

boolean: TRUE                 { $$ = create_node($1, NULL, NULL); }    
| FALSE                       { $$ = create_node($1, NULL, NULL); }
;
%%