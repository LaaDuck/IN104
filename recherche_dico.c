#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char** charger_dico(char* filename, int* ndico) {
    FILE* fp = fopen(filename, "r");
    *ndico = 0;
    char c;
    while(!feof(fp)) {
        c = fgetc(fp);
        if (c == 10) {
            (*ndico)++;
        }
    }
    fclose(fp);

    char** dico = malloc(sizeof(char*)* *ndico);
    FILE* fp2 = fopen(filename, "r");
    int i = 0;
    while(!feof(fp2) && i < *ndico) {
        dico[i] = malloc(sizeof(char*));
        fscanf(fp2, "%s\n", dico[i]);
        i++;
    }
    fclose(fp2);
    return dico;
}

int recherche_dico(char* mot, char** dico, int ndico) {
    for (int i = 0; i < ndico; i++) {
        if (strcmp(mot, dico[i]) == 0) return 1;
    }
    return 0;
}