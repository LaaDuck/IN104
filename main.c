#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mot.c"
#include "recherche_dico.c"
#include "veriflettre.c"

int main(){
    int* ndico = malloc(sizeof(int));
    char** dico = charger_dico("dico.txt", ndico);
    char* tentative = malloc(sizeof(char)*256);
    mot(tentative);
    while(!recherche_dico(tentative, dico, *ndico)) {
        printf("Votre mot n'est pas dans le dictionnaire\n");
        mot(tentative);
    }
    veriflettre("monde", tentative);
    return 0;
}