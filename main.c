#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "mot.c"
#include "recherche_dico.c"
#include "veriflettre.c"
#include "ordi.c"

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Not enough arguments.\n");
        return 0;
    } else {
        if (strcmp(argv[1],"ordi") == 0) {
            printf("Mode ordinateur : \n");
            srand(time(NULL));
            char* solution = "mamie";
            int ndico = 0;
            char** dico = charger_dico("dico.txt", &ndico);
            int* possibles = malloc(sizeof(int)*ndico);
            for (int i=0; i<ndico; i++) {
                possibles[i] = 1;
            }
            int n_possibles = ndico;
            char* tentative = malloc(sizeof(char)*6);
            int tab_verif[5] = {0};
            int n_tentatives = 0;
            int i=0;

            do {
                ordi(tentative, dico, ndico, possibles, n_possibles);
                printf("Tentative de l'ordinateur : ");
                veriflettre(solution, tentative, tab_verif);
                if (strcmp(solution, tentative) == 0) {
                    printf("L'ordinateur a gagné\n");
                    return 0;
                }
                n_possibles = maj_possibles_ordi(tentative, tab_verif, possibles, n_possibles, dico, ndico);
                i++;
            } while(i < 6);
            printf("L'ordinateur a perdu\n");
            return 0;
        } else if (strcmp(argv[1],"joueur") == 0) {
            printf("Mode joueur : \n");
            for(int i=0; i<6; i++) {
                char* solution = "mamie"; //prendre un mot de manière aléatoire dans le dico ?
                int* ndico = malloc(sizeof(int));
                char** dico = charger_dico("dico.txt", ndico); // car c'est un tableau de chaines de caractères ; 
                char* tentative = malloc(sizeof(char)*256); // on crée l'espace nécessaire pour mettre un mot dedans : celui de la tentative
                mot(tentative); // on vérifie que le mot tenté vérifie tous les critères
                while(!recherche_dico(tentative, dico, *ndico)) {
                    printf("Votre mot n'est pas dans le dictionnaire\n"); // le programme renvoie un booléen, et tant que ce n'est pas 1 qui a été renvoyé, on renvoie cette info
                    mot(tentative);
                }

                int* tab_verif = malloc(5*sizeof(int));
                veriflettre(solution, tentative, tab_verif);
                if (strcmp(solution, tentative) == 0) {
                    printf("Tu as réussi à trouver le mot ! Bravo !\n");
                    break;
                }
                if(i==5){
                    printf("Dommage... Tu as perdu ! Tu devais trouver le mot %s !\n", solution );
                    break;
                    }
            }
            return 0;
        } else {
            printf("Invalid mode.\n");
            return 0;
        }
    }
    
}

// penser à libérer tous les malloc