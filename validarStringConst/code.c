#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <float.h>
int yylineno = 0; //esto en lo da flex en realidad, es el numero de línea del error
                    //acá se lo pongo para que el yyerror sea compatible con el nuestro
char yytext[100]; //lo mismo que lo de arriba

int yyerror(char *msg){
    fprintf(stderr, "At line %d %s in text: %s\n", yylineno, msg, yytext);
    //exit(1);
}

int validarString(char cadena[]) {
    char msg[100];
    int longitud = strlen(cadena);

    if( strlen(cadena) > 32){ //en lugar de 30 verifica con 32 porque el string viene entre comillas
        sprintf(msg, "ERROR: Cadena %s demasiado larga. Maximo 30 caracteres\n", cadena);
        yyerror(msg);
    }
    char sincomillas[31];
    int i;
    for(i=0; i< longitud - 2 ; i++) {
            sincomillas[i]=cadena[i+1];
    }
    sincomillas[i]='\0';
    //guardarenTS();
/*
    // Bloque para debug
    printf("***************************\n");
    printf("%d\n",strlen(sincomillas));
    for ( i = 0; i < strlen(sincomillas)+1; i++) {
        printf("%d : %c , %d \n",i,sincomillas[i],sincomillas[i]);
    }
    printf("***************************\n");
*/

    //guardarenTS;
    return 0;
}



int main(){

    validarString("\"123456789012345678901234567890\"");//se debe probar el texto entre comillas
    return 0;
}
