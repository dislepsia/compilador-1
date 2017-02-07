#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int yylineno = 0; //esto en lo da flex en realidad, es el numero de línea del error
                    //acá se lo pongo para que el yyerror sea compatible con el nuestro
char yytext[30]; //lo mismo que lo de arriba

int yyerror(char *msg){
    fprintf(stderr, "At line %d %s in text: %s\n", yylineno, msg, yytext);
    //exit(1);
}

int validarFloat(char flotante[]) {
    double casteado = atof(flotante);
    char msg[100];
    double min = pow(-1.17549,-38);
    double max = pow(3.40282,38);
    printf("%f \n", min);
    printf("%f \n", max);
    if(casteado < min || casteado > max) {
        sprintf(msg, "ERROR: Float %d fuera de rango. Debe estar entre [-1.17549e-38; 3.40282e38]\n", casteado);
        yyerror(msg);
    } else {
        //guardarenTS
        //printf solo para pruebas:
        printf("Float ok! %d \n", casteado);
        return 0;

    }

}



int main(){
    double min = pow(-1.17549,-38);
    double max = pow(3.40282,38);
    validarFloat("-1.17549");
    validarFloat("3.40282");
    validarFloat("-1.17550");
    validarFloat("3.40283");
    return 0;
}
