#include <stdio.h>
#include <stdlib.h>

#include "mot.c"
#include "recherche_dico.c"
#include "veriflettre.c"

int main(){
    printf("0\n");
    int* ndico = malloc(sizeof(int));
    char** dico = charger_dico("dico.txt", ndico);
    printf("3\n");
    char* tentative = malloc(sizeof(char)*256);
    printf("1\n");
    mot(tentative);
    printf("11\n");
    while(!recherche_dico(tentative, dico, *ndico)) {
        printf("2\n");
        printf("Votre mot n'est pas dans le dictionnaire\n");
        mot(tentative);
    }
    printf("10\n");
    veriflettre("monde", tentative);
    return 0;
}