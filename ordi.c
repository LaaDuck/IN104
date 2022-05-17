#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

int lettre_dans_mot(char lettre, char* mot) {
    int i = 0;
    while (mot[i] != '\0') {
        if (mot[i] == lettre) return 1;
        i++;
    }
    return 0;
}

int maj_possibles_ordi(char* tentative, int* tab_verif, int* possibles, int n_possibles, char** dico, int ndico) {
    int index_mot = 0;
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
            if (tab_verif[lettre] > 0 && lettre_dans_mot(tentative[lettre], dico[i])) { //lettre grise
                n_possibles--;
                possibles[i] = 0;
                break;
            }
        }
    }

    return n_possibles;
}