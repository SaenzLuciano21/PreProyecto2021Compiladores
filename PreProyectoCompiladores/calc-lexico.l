%{

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "calc-sintaxis.tab.h"

%}

%option noyywrap
%option yylineno

letra [a-zA-Z]
digito [0-9]

%%
"integer"   				{
								yylval.s=(char *) malloc(sizeof(yytext)*yyleng);
								strcpy(yylval.s,yytext);
								printf("INTEGER: %s\n",yytext);
								return INTEGER; }

"bool"						{	
								yylval.s=(char*) malloc(sizeof(yytext)*yyleng);
								strcpy(yylval.s,yytext);
								printf("BOOL: %s\n",yytext);
								return BOOL; }

"false"     				{
								yylval.s=(char*) malloc(sizeof(yytext)*yyleng);
								strcpy(yylval.s,yytext);
								printf("FALSE: %s\n",yytext);
								return FALSE; }

"true"      				{
								yylval.s=(char*) malloc(sizeof(yytext)*yyleng);
								strcpy(yylval.s,yytext);
								printf("TRUE: %s\n",yytext);
								return TRUE; }

"return"                    {
                                yylval.s=(char *) malloc(sizeof(yytext)*yyleng);
                                strcpy(yylval.s,yytext);
                                printf("RETURN: %s\n",yytext);
                                return RETURN; }

[+*;()=]                   	{	
                                printf("%s\n",yytext);
                            	return *yytext; }

"-"                       	{	
                                printf("%s\n",yytext);
                                return TMENOS; }

{digito}+                   { 
                                yylval.i=atoi(yytext);
								printf("INT : %d\n",atoi(yytext)); 
                                return INT; }

{letra}({letra}|{digito})*  { 
								yylval.s=(char*) malloc(sizeof(yytext)*yyleng);
								strcpy(yylval.s,yytext);
                                printf("ID : %s\n",yytext);
                                return ID; }

.|\n                          ; /* ignore all the rest */

%%

void yyerror() {
	printf("%s%d\n","-> ERROR Sintactico en la linea: ",yylineno);
}

int main(int argc,char *argv[]) {
	++argv,--argc;
	if (argc > 0)
		yyin = fopen(argv[0],"r");
	else
		yyin = stdin;
	yyparse();
}