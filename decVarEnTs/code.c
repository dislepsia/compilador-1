#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char varTypeArray[2][100][50];
int idPos = 0;
int typePos = 0;

void collectId (char *id) {
    strcpy(varTypeArray[0][idPos++],id);
}

void collectType (char *type){
    strcpy(varTypeArray[1][typePos++],type);

}

void consolidateIdType() {
    printf("Consolidando\n");
    int i;
    for(i=0; i < idPos; i++ ) {
        printf("%s %s\n",varTypeArray[0][i],varTypeArray[1][i]);
    }
    idPos=0;
    typePos=0;
}



int main(){

    collectId("a");
    collectId("b");
    collectType("string");
    collectType("int");
    collectId("c");
    collectId("d");
    collectType("float");
    collectType("string");
    consolidateIdType();
    return 0;
}
