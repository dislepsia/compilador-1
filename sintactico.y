%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern int yylineno;
extern char *yytext;

%}

%union{
 char s[20];
}


%token IF ELSE WHILE DEFVAR ENDDEF PERCENT INLIST
%token REAL BINA ENTERO ID STRING_CONST
%token FLOAT INT STRING
%token P_A P_C L_A L_C FL DP CO
%token OP_CONCAT OP_SUM OP_RES OP_DIV OP_MUL MOD DIV
%token CMP_MAY CMP_MEN CMP_MAYI CMP_MENI CMP_DIST CMP_IGUAL
%token ASIG


%%
programa    : sentencias        {printf("Compila OK \n");}
            ;
sentencias  : sentencias sentencia  {printf("sentencias  : sentencias sentencia\n");}
            | sentencia             {printf("sentencias  : sentencia \n");}
sentencia   : asignacion FL         {printf("sentencias  : asignacion FL\n");}
            | iteracion             {printf("sentencias  : iteracion \n");}
            | decision              {printf("sentencias  : decision\n");}
            | bloque_dec            {printf("sentencias  : sentencias bloque_dec\n");}
            ;
decision   : IF P_A condicion P_C L_A sentencias L_C {printf("decision   : IF P_A condicion P_C L_A sentencias L_C\n");}
           | IF P_A condicion P_C L_A sentencias L_C ELSE L_A sentencias L_C {printf("decision   : IF P_A condicion P_C L_A sentencias L_C ELSE L_A sentencias L_C\n");}
           ;
iteracion  : WHILE P_A condicion P_C L_A sentencias L_C {printf("iteracion  : WHILE P_A condicion P_C L_A sentencias\n");}
           ;
bloque_dec : DEFVAR declaraciones ENDDEF {printf(" bloque_dec : DEFVAR declaraciones ENDDEF \n ");}
           ;
declaraciones: declaraciones declaracion    {printf("declaraciones: declaraciones declaracion \n");}
           | declaracion                    {printf("declaraciones: declaracion  \n");}
           ;
declaracion: lista_variables DP lista_tipos_datos {printf("declaracion: lista_variables DP lista_tipos_datos \n");}
           ;
lista_tipos_datos   : lista_tipos_datos CO tipo_dato {printf(" lista_tipos_datos   : lista_tipos_datos CO tipo_dato \n");}
                    | tipo_dato {printf(" lista_tipos_datos   : tipo_dato \n");}
                    ;
lista_variables     : lista_variables CO ID { printf("lista_variables     : lista_variables CO ID \n");}
                    | ID { printf("lista_variables     : ID \n");}
                    ;
tipo_dato  : STRING { printf("tipo_dato  : STRING \n");}
           | FLOAT  { printf("tipo_dato  : FLOAT \n");}
           | INT    { printf("tipo_dato  : INT \n");}
           ;
asignacion : ID ASIG expresion              {printf("asignacion : ID ASIG expresion \n");}
           ;
condicion  : expresion CMP_MAY expresion    {printf("condicion  : expresion CMP_MAY expresion \n");}
           | expresion CMP_MEN expresion    {printf("condicion  | expresion CMP_MEN expresion \n");}
           | expresion CMP_MAYI expresion   {printf("condicion  :  \n");}
           | expresion CMP_MENI expresion   {printf("condicion  : CMP_MENI expresion   \n");}
           | expresion CMP_DIST expresion   {printf("condicion  : CMP_DIST expresion   \n");}
           | expresion CMP_IGUAL expresion  {printf("condicion  : CMP_IGUAL expresion  \n");}
           ;
expresion  : expresion OP_SUM termino       {printf("expresion  : expresion OP_SUM termino \n");}
           | expresion OP_RES termino       {printf("expresion  : expresion OP_RES termino\n");}
           | termino                        {printf("expresion  : termino                 \n");}
           ;
termino    : termino OP_MUL factor          {printf("termino    : termino OP_MUL factor \n");}
           | termino OP_DIV factor          {printf("termino    : termino OP_DIV factor \n");}
           | factor                         {printf("termino    : factor \n");}
           ;
factor     : P_A expresion P_C              {printf("factor : P_A expresion P_C  \n");}
           | OP_RES factor                  {printf("factor : OP_RES factor      \n");}
           | ENTERO                         {printf("factor : ENTERO: %s             \n" , yylval.s);}
           | REAL                           {printf("factor : REAL: %s               \n" , yylval.s);}
           | BINA                           {printf("factor : BINA: %s               \n" , yylval.s);}
           | ID                             {printf("factor : ID: %s                \n", yylval.s);}
           ;


%%

int main(int argc,char *argv[]){

    yyparse();
    return 0;
}

int yyerror(char *msg){
    fprintf(stderr, "At line %d %s in text: %s\n", yylineno, msg, yytext);
    exit(1);
}
