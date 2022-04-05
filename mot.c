#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "veriftaillemot.c"

void mot(char* mot)
{
  do {
    printf("Quel est votre mot?\n");
    scanf(" %s ", mot);
  } while( !veriftaillemot(mot) );
  printf("Votre mot est %s!\n", mot); // On renvoie le mot entré dans "mot"
}
