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

int validarFloat(char flotante[]) {
    double casteado = atof(flotante);
    casteado = fabs(casteado);
    char msg[300];

    if(casteado < FLT_MIN || casteado > FLT_MAX) {
        sprintf(msg, "ERROR: Float %f fuera de rango. Debe estar entre [1.17549e-38; 3.40282e38]\n", casteado);
        yyerror(msg);
    } else {
        //guardarenTS
        //printf solo para pruebas:
        printf("Float ok! %f \n", casteado);
        return 0;

    }

}



int main(){
    double min = pow(-1.17549,-38);
    double max = pow(3.40282,38);
    validarFloat("-1234567890123456789012345678901234567890123456789");
    validarFloat("-111111111111111111.17549");
    validarFloat("333333333333333.40282");
    validarFloat("-1444444444444.17550");
    validarFloat("3555555555555555555555555.40283");
    return 0;
}
