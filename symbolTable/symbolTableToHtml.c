#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int pos_st = 10;
typedef struct symbol {
    char nombre[50];
    char tipo[10];
    char valor[100];
    char alias[50];
    int longitud;
    int limite;
} symbol;


void writeStyle(FILE *p){
    fprintf(p,"<style>\ntable {\nfont-family: arial, sans-serif;\nborder-collapse: collapse;\nwidth: 100%%;\n}\ntd, th {\nborder: 1px solid #dddddd;\ntext-align: left;\npadding: 8px;\n}\ntr:nth-child(even) {\nbackground-color: #dddddd;\n}\n</style>\n");
}


void writeTupla(FILE *p ,int filas,symbol symbolTable[]){
    int j;
    for(j=0; j < filas; j++ ){
        fprintf(p, "<tr>\n");
        fprintf(p,"\t<th>%s</th>\n",symbolTable[j].nombre);
        fprintf(p,"\t<th>%s</th>\n",symbolTable[j].tipo);
        fprintf(p,"\t<th>%s</th>\n",symbolTable[j].valor);
        fprintf(p,"\t<th>%s</th>\n",symbolTable[j].alias);
        fprintf(p,"\t<th>%d</th>\n",symbolTable[j].longitud);
        fprintf(p,"\t<th>%d</th>\n",symbolTable[j].limite);
        fprintf(p, "</tr>\n");
    }

}

void writeTable(FILE *p,  int filas, symbol symbolTable[], void (*tupla)(FILE *p ,int filas, symbol symbolTable[])){
    fprintf(p,"<table>\n");
    fprintf(p, "<tr>\n");
    char titulos[6][20] = {"Nombre","Tipo","Valor","Alias","Longitud","Limite"};
    int j;
    for(j=0; j < 6; j++ ){
        fprintf(p,"<th>%s</th>\n",titulos[j]);
    }
    fprintf(p, "</tr>");

    int i;

        tupla(p,filas,symbolTable);


    fprintf(p,"</table>\n");
}
/*
<table>
  <tr>
    <th>Company</th>
    <th>Contact</th>
    <th>Country</th>
  </tr>
  <tr>
    <td>Alfreds Futterkiste</td>
    <td>Maria Anders</td>
    <td>Germany</td>
  </tr>
*/

void writeHeader(FILE *p, char *title, void (*style)(FILE *p)){
fprintf (p,"<!DOCTYPE html>\n<html>\n<head>\n<title>%s</title>\n",title);
style(p);
fprintf (p,"</head>\n<body>");
}

void writeFooter(FILE *p){
fprintf (p,"</body>\n</html>");
}





//Estructura de la SymbolTable

void symbolTableToHtml(symbol symbolTable[],char * ruta)
{
//Declaracion de variables

//Definicion del archivo de salida y su cabecera
FILE  *p = fopen(ruta, "w");
writeHeader(p, "Tabla de simbolos",writeStyle);
writeTable(p,pos_st  , symbolTable,writeTupla);
writeFooter(p);

//Fin
fclose(p);
}





//Test
int main() {
symbol symbolTable[10] = {
                        {"uno","b","c","d",5,6},
                        {"dos","f","g","h",5,6},
                        {"(","b","c","d",5,6},
                        {"{","b","c","d",5,6},
                        {"2","f","g","h",5,6},
                        {"@","b","c","d",5,6},
                        {"$%^&*","f","g","h",5,6},
                        {":","b","c","d",5,6},
                        {"<8","f","g","h",5,6},
                        {".","b","c","d",5,6}
                        };

symbolTableToHtml(symbolTable,"salida.html");
}
