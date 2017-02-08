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


symbol nullSymbol;
symbol symbolTable[1000];
int pos_st = 0;

// el valor ! representa al simbolo nulo.


/* symbol table functions */

//tipo float int string
//const cfloat cint cstring
// helpers: downcase, limpiar comillas , anteponer _
char *downcase(char *p){
    char *pOrig = p;
    for ( ; *p; ++p) *p = tolower(*p);
    return pOrig;
}

char *prefix_(char *p){
    int tam = strlen(p);
    p = p + tam ;
    int i;
    for(i=0; i < tam + 1 ; i++){
        *(p+1) = *p;
        p--;
    }
    *(p+1) = '_';
    return p+1;
}


int searchSymbol(char key[]){
    static int llamada=0;
    llamada++;
    char mynombre[100];
    strcpy(mynombre,key);
    prefix_(downcase(mynombre));
    int i;
    for ( i = 0;  i < pos_st ; i++) {
        printf("[%d]**%s--->%s\n",llamada,symbolTable[i].nombre,mynombre);
        if(strcmp(symbolTable[i].nombre, mynombre ) == 0){
            return i;
        }
    }

    return -1;
}

int saveSymbol(char nombre[], char tipo[] ){
    char mynombre[100];
    char type[10];
    strcpy(type,tipo);
    strcpy(mynombre,nombre);
    downcase(type);
    int use_pos = searchSymbol(nombre);
    if ( use_pos == -1){
        use_pos = pos_st;
        pos_st++;
    }
    symbol newSymbol;
    strcpy(newSymbol.nombre, prefix_(downcase(mynombre)));
    strcpy(newSymbol.tipo, type);
    strcpy(newSymbol.valor, nombre);
    //strcpy(newSymbol.alias, alias);
    newSymbol.longitud = strlen(nombre);
    symbolTable[use_pos] = newSymbol;
    newSymbol = nullSymbol;
    return 0;
}

symbol getSymbol(char nombre[]){
    int pos = searchSymbol(nombre);
    if(pos >= 0) return symbolTable[pos];
    return nullSymbol;
}




//traer symbolo





int main(){

//declaración del null symbol


    strcpy(nullSymbol.nombre,"!");
    saveSymbol("aaaaa","string");
    saveSymbol("134.4","creal");
    saveSymbol("bbbb","creal");
    symbol s = getSymbol("bbbb");
    //saveSymbol
    printf ("%s has valor %s  %s\n", s.nombre, s.valor, s.tipo);
    saveSymbol("bbbb","nreal");
    printf ("%s has valor %s  %s\n", s.nombre, s.valor, s.tipo);
    return 0;
}
