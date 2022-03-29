verfilettre.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void verifplace (char mot , char notrechoix) {
    int i=0;
    int j=0;
    
    for (i; i<5;i++) {
        for (j;j<5;j++){
            if (mot[i]==notrechoix[j]) {printf "la lettre est dans le mot"}
            
        }
    }
}