#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char** charger_dico(char* filename, int* ndico) {
    FILE* fp = fopen(filename, "r");
    *ndico = 0; //va servir à déterminer le nombre de ligne dans le dico
    char c;
    while(!feof(fp)) {s
        c = fgetc(fp); // on lit le caractère actuel
        if (c == 10) { // si c==10 cela veut dire qu'on a à fiare à un retour à la ligne
            (*ndico)++;
        }
    }
    fclose(fp);

    char** dico = malloc(sizeof(char*)* *ndico); //cette fois on ouvre le document pour lire les mots
    FILE* fp2 = fopen(filename, "r");
    int i = 0;
    while(!feof(fp2) && i < *ndico) { // tan(t qu'on arrive pas à la fin du document on continue
        dico[i] = malloc(sizeof(char*)); // pour chaque mot on le réécrit dans une case : on crée une chaine de caractère et on met le pointeur qui correspond au premier caractère du mot dans le tableau
        fscanf(fp2, "%s\n", dico[i]);
        i++;
    }
    fclose(fp2);
    return dico;
}

int recherche_dico(char* mot, char** dico, int ndico) {
    for (int i = 0; i < ndico; i++) {
        if (strcmp(mot, dico[i]) == 0) return 1; //on compare les chaines de caractères afin de vérifier si le mot se trouve bien dans le dictionnaire
    }
    return 0;
}


// penser à libérer tous les malloc