#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yyerror() {
    printf("llama a yyerror del bison\n");
    return 0;
};

int validarInt(char entero[]) {
    int casteado = atoi(entero);
    if(casteado < -32768 || casteado > 32767) {
        printf(" ERROR: Entero %d fuera de rango. Debe estar entre [-32768; 32767]\n", casteado);
        yyerror();
    } else {
        //guardarenTS
        //printf solo para pruebas:
        printf("Entero ok! %d \n", casteado);
        return 0;

    }

}


int main(){
    validarInt("-32768");
    validarInt("32767");
    validarInt("-32769");
    validarInt("32768");
    return 0;
}
