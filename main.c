#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mot.c"
#include "recherche_dico.c"
#include "veriflettre.c"

int main(){
    int* ndico = malloc(sizeof(int));
    char** dico = charger_dico("dico.txt", ndico); // car c'est un tableau de chaines de caractères ; 
    char* tentative = malloc(sizeof(char)*256); // on crée l'espace nécessaire pour mettre un mot dedans : celui de la tentative
    mot(tentative); // on vérifie que le mot tenté vérifie tous les critères
    while(!recherche_dico(tentative, dico, *ndico)) {
        printf("Votre mot n'est pas dans le dictionnaire\n"); // le prgramme renvoie un booléen, et tant que ce n'est pas 1 qui a été renvoyé, on renovie cette info
        mot(tentative);
    }
    veriflettre("monde", tentative);
    return 0;
}

// penser à libérer tous les malloc