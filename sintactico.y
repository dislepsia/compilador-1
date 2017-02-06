%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern int yylineno;

%}


%union{
    char id[50];
    float f;
}
%token IF ELSE WHILE DEFVAR ENDDEF PERCENT INLIST
%token ENTERO BIN REAL STRING ID TIPO
%token P_A P_C L_A L_C FL DP
%token OP_CONCAT OP_SUM OP_RES OP_DIV OP_MUL MOD DIV
%token CMP_MAY CMP_MEN CMP_MAYI CMP_MENI CMP_DIST CMP_IGUAL
%token ASIG


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
condicion  : expresion CMP_MAY expresion
           | expresion CMP_MEN expresion
           | expresion CMP_MAYI expresion
           | expresion CMP_MENI expresion
           | expresion CMP_DIST expresion
           | expresion CMP_IGUAL expresion
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

int yyerror(char *msg){
    fprintf(stderr, "At line %d %s\n", yylineno, msg);
    exit(1);
}
