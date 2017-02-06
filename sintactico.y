%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


%}


%union{
    char id[50];
    float f;
}
%token  FL
%token  <f> NUM
%token <id> ID
%type


%%
programa: programa linea
        | linea
linea   : asignacion FL
        | iteracion
        | decision
        | bloque_dec
        | linea asignacion FL
        | linea iteracion
        | linea decision
        ;
decision   : IF P_A condicion P_C L_A linea L_C
           | IF P_A condicion P_C L_A linea L_C ELSE L_A linea L_C
           ;
iteracion  : WHILE P_A condicion P_C L_A linea L_C
           ;
bloque_dec : DEFVAR declaraciones ENDDEF
           ;
declaraciones: declaraciones declaracion
           | declaracion
           ;
declaracion: ID DP TIPO
           ;
asignacion : ID ASIG expresion
           ;
expresion  : expresion OP_SUM termino
           | expresion OP_RES termino
           | termino
           ;
termino    : termino OP_MUL factor
           | termino OP_DIV factor
           | factor
           ;
factor     : P_A expresion P_C
           | OP_RES factor
           | ENTERO
           | REAL
           | ID
           ;


%%

int main(int argc,char *argv[]){

    yyparse();
    return 0;
}

void yyerror(char *msg){
    fprintf(stderr, "%s\n", msg);
    exit(1);
}
