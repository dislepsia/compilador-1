%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


%}


%union{
    char id[50];
    float f;
}
%token  FIN MAS MENOS DIV POR ASIG P_A P_C  PRINT EXIT_COMMAND PC
%token  <f> NUM
%token <id> ID
%type


%%

L : A PC                {;}
  | EXIT_COMMAND PC     {exit(0);}
  | PRINT E PC          {printf("Printing %f\n", $2);}
  | L A PC              {;}
  | L PRINT E PC        {printf("Printing %f\n", $3);}
  | L EXIT_COMMAND PC   {exit(0);}
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
