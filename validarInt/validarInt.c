#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int yylineno = 0; //esto en lo da flex en realidad, es el numero de línea del error
                    //acá se lo pongo para que el yyerror sea compatible con el nuestro
char yytext[30]; //lo mismo que lo de arriba

int yyerror(char *msg){
    fprintf(stderr, "At line %d %s in text: %s\n", yylineno, msg, yytext);
    exit(1);
}

int validarInt(char entero[]) {
    int casteado = atoi(entero);
    char msg[100];
    if(casteado < -32768 || casteado > 32767) {
        sprintf(msg, "ERROR: Entero %d fuera de rango. Debe estar entre [-32768; 32767]\n", casteado);
        yyerror(msg);
    } else {
        //guardarenTS
        //printf solo para pruebas:
        printf("Entero ok! %d \n", casteado);
        return 0;

    }

}

int validarBin(char binario[]){
    char *ptr ;//puntero que misteriosamente usa esta funcion
    long casteado = strtol(binario+2, &ptr, 2);

    char msg[100];
    if(casteado < -32768 || casteado > 32767) {
        sprintf(msg, "ERROR: Entero %d fuera de rango. Debe estar entre [-32768; 32767]\n", casteado);
        yyerror(msg);
    } else {
        //guardarenTS
        //printf solo para pruebas:
    //    printf("Binario ok! %d \n", casteado);
        return 0;

    }

}


int main(){
    validarBin("0b10");
    return 0;
}
