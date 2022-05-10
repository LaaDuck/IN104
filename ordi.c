#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void ordi(char* tentative, char** dico, int ndico, int* possibles, int n_possibles) {
    // il manque de le faire jouer le mot "saine" dès la première tentative
    int r = rand()%n_possibles;
    int compteur = 0;
    for (int i = 0 ; i < ndico ; i++ ){
        if ( possibles[i]!=0 ) {
            if (compteur == r) {
                strcpy(dico[i], tentative);
                return;
            }
            compteur++;
        }
    }
}

int maj_possibles_ordi(char* tentative, int*tab_verif, int* possibles, char** dico, int n_possibles) {
    int index_mot = 0;
    int n_possibles_new = n_possibles;
    for (int i = 0; i < n_possibles; i++ ) {
        while (possibles[i] == 0) index_mot ++;

        for (int lettre = 0; lettre < 5; lettre++) {
            if (tab_verif[lettre] == -1) {
                if (tentative[lettre] != dico[i][lettre]) {
                    n_possibles_new--;
                    possibles[i] = 0;
                    break;
                }
                
            }
        }

        if (possibles[i] == 0) continue;

        for (int lettre = 0; lettre < 5; lettre++) {
            if (tab_verif[lettre] > 0) {
                for (int j = 0; j < 5; j++) {
                    if (dico[i][j] != tentative[lettre]) {
                        n_possibles_new--;
                        possibles[i] = 0;
                        break;
                    }
                }
            }
        }
    }

    return n_possibles;

}