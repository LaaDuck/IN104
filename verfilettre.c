verfilettre.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void verifplace (char mot , char notrechoix) {
    int i=0;
    int j=0;
    char* I=[];
    char* J=[];
    for (i; i<5;i++) {
        for (j;j<5;j++){
            if (mot[i]==notrechoix[j]) {
                printf "la lettre est dans le mot";
                if (i==j) {I=I+[mot(i)]}
                else {J=J+[mot(i)]}
                }
            
        
        }
    for (int i=0; i<strlen(I); i++) {printf "les lettres à la bonne place sont :" ;
    printf("%d", I[i])}
    for (int i=0 ; i<strlen(J) ; i++) {printf "Les lettres présentent mais à la mauvaise place sont : " ; printf ("%d", J[i]) 
    }
        
}