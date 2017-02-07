#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct symbol {
    char nombre[50];
    char tipo[10];
    char valor[100];
    char alias[50];
    int longitud;
    int limite;
} symbol;



symbol symbolTable[1000];
int pos_st = 0;

// el valor ! representa al simbolo nulo.


/* symbol table functions */


int searchSymbol(char key[]){
    int i;
    for ( i = 1;  i < pos_st ; i++) {
        if(strcmp(symbolTable[i].nombre,key) == 0){
            return i;
        }
    }
    return -1;
}

int saveSymbol(char nombre[], char tipo[],char valor[], char alias[] ){
    int use_pos = searchSymbol(nombre);
    if ( use_pos == -1){
        use_pos = pos_st;
        pos_st++;
    }
    symbol newSymbol;
    strcpy(newSymbol.nombre, nombre);
    strcpy(newSymbol.tipo, tipo);
    strcpy(newSymbol.valor, valor);
    strcpy(newSymbol.alias, alias);
    symbolTable[use_pos] = newSymbol;
    return 0;
}

symbol getSymbol(char nombre[]){
    int i;
    for ( i = 0;  i < pos_st ; i++) {
        if(strcmp(symbolTable[i].nombre,nombre) == 0){
            return symbolTable[i];
        }
    }
    return nullSymbol;
}


//traer symbolo





int main(){

//declaración del null symbol

    symbol nullSymbol;
    strcpy(nullSymbol.nombre,"!");

    saveSymbol("brian","string","valor","alias");
    symbol s = getSymbol("brian");
    printf ("%s has valor %f \n", s.nombre, s.valor );
    return 0;
}
