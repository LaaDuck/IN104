#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int veriftaillemot (char* mot) {
    if (strlen(mot)==5) {
        return 1;
    } else {
        printf ("Le mot n'est pas de la bonne longueur\n");
        return 0;
    }
}

