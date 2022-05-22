#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count_possibles(int* possibles, int ndico) {
    int c = 0;
    for (int i=0; i<ndico; i++) {
        if (possibles[i] != 0) {
            c++;
        }
    }
    return c;
}

void ordi(char* tentative, char** dico, int ndico, int* possibles, int n_possibles) {
    // il manque de le faire jouer le mot "saine" dès la première tentative
    int r = rand()%n_possibles;
    int compteur = 0;
    for (int i = 0 ; i < ndico ; i++ ){
        if ( possibles[i] != 0 ) {
            if (compteur == r) {
                strncpy(tentative, dico[i], 6);
                return;
            }
            compteur++;
        }
    }
}

int verif_grise(char lettre, char* mot, int* tab_verif) {
    for (int i = 0; i < 5; i++) {
        if (mot[i] == lettre && tab_verif[i] > 0) return 1;
    }
    return 0;
}

int maj_possibles_ordi(char* tentative, int* tab_verif, int* possibles, int n_possibles, char** dico, int ndico) {
    for (int i = 0; i < ndico; i++ ) {
        if (possibles[i] == 0) continue;

        for (int lettre = 0; lettre < 5; lettre++) {
            if (tab_verif[lettre] == -1 && tentative[lettre] != dico[i][lettre]) { //lettre verte
                n_possibles--;
                possibles[i] = 0;
                break;
            }
        }
    }
    for (int i = 0; i < ndico; i++ ) {
        if (possibles[i] == 0) continue;

        for (int lettre = 0; lettre < 5; lettre++) {
            if (tab_verif[lettre] > 0 && verif_grise(tentative[lettre], dico[i], tab_verif)) { //lettre grise
                n_possibles--;
                possibles[i] = 0;
                break;
            }
        }
    }

    return n_possibles;
}

