#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char** charger_dico(char* filename, int* ndico) {
    FILE* fp = fopen(filename, "r");
    *ndico = 0;
    char c;
    while(!feof(fp)) {
        c = fgetc(fp);
        if (c == '\n') *ndico++;
    }
    fclose(fp);

    printf("4\n"); 
    printf("ndico %d \n", *ndico);
    char** dico = malloc(sizeof(char*)* *ndico);
    printf("5\n");
    fp = fopen(filename, "r");
    int i = 0;
    while(!feof(fp) && i < *ndico) {
        printf("6\n");
        fgets(dico[i],256,fp);
        printf("7\n");
        i++;
    }
    printf("5\n");
    fclose(fp);
    return dico;
}

int recherche_dico(char* mot, char** dico, int ndico) {
    for (int i = 0; i < ndico; i++) {
        printf("9\n");
        if (strcmp(mot, dico[i]) == 0) return 1;
    }
    return 0;
}