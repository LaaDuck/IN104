#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VERT "\x1B[32m"
#define JAUNE "\x1B[33m"
#define RESET "\x1B[0m"

void veriflettre (char* solution , char* tentative) {
    int enplace = 0;
    int autrepart = 0;
    int tableau[5] = {0}; //pour chaque lettre : -1 si en place -2 si autre part, ASCII sinon
    for (int i=0; i < 5; i++) {
        if (tentative[i] == solution[i]) {
            tableau[i] = -1;
            enplace++;
        } else {
            tableau[i] = (int) tentative[i];
        }
    }

    for (int i=0; i < 5; i++) {
        for (int j=0; j < 5; j++) {
            if ( (int) solution[i] == tableau[j]) {
                tableau[j] = -2;
                autrepart++;
                break;
            }
        }
    }

    for(int i=0; i<5; i++) {
        if (tableau[i] == -1) printf("%s%c%s", VERT, tentative[i], RESET);
        if (tableau[i] == -2) printf("%s%c%s", JAUNE, tentative[i], RESET);
        if (tableau[i] >0) printf("%c", tentative[i]);
    
    }
    printf("\n");
        
}