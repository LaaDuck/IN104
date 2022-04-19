#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mot.c"
#include "recherche_dico.c"
#include "veriflettre.c"

int main(){
    for(int i=0; i<6; i++) {
        char* solution = "monde";
        int* ndico = malloc(sizeof(int));
        char** dico = charger_dico("dico.txt", ndico); // car c'est un tableau de chaines de caractères ; 
        char* tentative = malloc(sizeof(char)*256); // on crée l'espace nécessaire pour mettre un mot dedans : celui de la tentative
        mot(tentative); // on vérifie que le mot tenté vérifie tous les critères
        while(!recherche_dico(tentative, dico, *ndico)) {
            printf("Votre mot n'est pas dans le dictionnaire\n"); // le programme renvoie un booléen, et tant que ce n'est pas 1 qui a été renvoyé, on renvoie cette info
            mot(tentative);
        }
        veriflettre(solution, tentative);
        if (strcmp(solution, tentative) == 0) {
            printf("Tu as réussi à trouver le mot ! Bravo !\n");
            break;
        }
        if(i==5){
            printf("Dommage... Tu as perdu ! Tu devais trouver le mot %s !\n", solution );
            break;
            }
    }
    // il reste à dire au bout de 6 essais qu'il a échoué, ou dire dès que le mot est trouvé qu'il a fini le jeu !
    return 0;
}

// penser à libérer tous les malloc