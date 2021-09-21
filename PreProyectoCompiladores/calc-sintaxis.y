%{

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tree.c"

struct bTree *ast;

%} 
%union { int i; char *s; struct bTree *p; enum tType * t; }
%token<i> INT
%token<s> ID
%token<s> BOOL
%token<s> TRUE
%token<s> FALSE
%token<s> RETURN
%token<s> INTEGER

%type<p> declaration
%type<p> declarations
%type<p> statement
%type<p> statements
%type<t> type
%type<p> expression
%type<p> value
%type<p> boolean



/*precedence*/
%left '+' '-'
%left '*'

%%
program: declarations statements            { printf("No hay errores \n"); 
                                            info *infS = (info *)malloc(sizeof(info));
                                            ast = create_node(PROG, infS, $1, $2); 
                                            inOrder(ast);
                                            freeMemory(ast); }
;

statements: statement                       { $$ = $1; }
| statement statements                      { info *infS = (info *)malloc(sizeof(info));
                                            $$ = create_node(STM, infS, $1, $2); }
;

statement: ID '=' expression ';'            { info *infS = (info *)malloc(sizeof(info));
                                            /*bucar el id en la ts y retornar el puntero a info*/
                                            $$ = create_node(STM, infS, NULL, $3); }
| RETURN expression ';'                     { info *infS = (info *)malloc(sizeof(info));
                                            $$ = create_node(STM, infS, NULL, $2); }
;

declarations: declaration                   { $$ = $1; }
| declaration declarations                  { info *infD = (info *)malloc(sizeof(info));
                                            $$ = create_node(DEC, infD, $1, $2); }
;

declaration: type ID '=' expression ';'     { info *infD = (info *)malloc(sizeof(info));
                                            infD->name=$2; infD->type=*$1;
                                            $$ = create_node(DEC, infD, NULL, $4); }
;

type: INTEGER           { enum tType *aux = (enum tType *) malloc (sizeof(enum tType)); *aux=integer; $$=aux; }
| BOOL                  { enum tType *aux = (enum tType *) malloc (sizeof(enum tType)); *aux=integer; $$=aux; }
;

expression: ID                              { info *infV = (info *)malloc(sizeof(info));
                                            infV->name=$1;
                                            $$ = create_node(VAR, infV, NULL, NULL); }
| value                                     { $$ = $1; }
| expression '+' expression                 { info *infE = (info *)malloc(sizeof(info));
                                            infE->name = (char *)malloc(sizeof(char)*5);
                                            strcpy(infE->name,"+");  
                                            $$ = create_node(SUMA, infE, $1, $3); }     
| expression '*' expression                 { info *infE = (info *)malloc(sizeof(info));
                                            infE->name = (char *)malloc(sizeof(char)*5);
                                            strcpy(infE->name,"*");  
                                            $$ = create_node(MULT, infE, $1, $3); }
| expression '-' expression                 { info *infE = (info *)malloc(sizeof(info));
                                            infE->name = (char *)malloc(sizeof(char)*5);
                                            strcpy(infE->name,"-");  
                                            $$ = create_node(RESTA, infE, $1, $3); }
| '(' expression ')'                        { $$ = $2; }
;

value: INT                                  { info *inf =  (info *)malloc(sizeof(info));
                                            inf->value=$1; 
                                            $$ = create_node(VAL, inf, NULL, NULL); }
| boolean                                   { $$ = $1; }
;

boolean: TRUE                               { info *inf =  (info *)malloc(sizeof(info));
                                            inf->name=$1; inf->value=1; /*distinto de 0 es true*/ 
                                            $$ = create_node(VAL, inf, NULL, NULL); }    
| FALSE                                     { info *inf =  (info *)malloc(sizeof(info));
                                            inf->name=$1; inf->value=0; 
                                            $$ = create_node(VAL, inf, NULL, NULL); }
;
%%