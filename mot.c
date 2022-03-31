#include <stdio.h>
#include <stdlib.h>

int mot(char* mot)
{
  printf("Quel est votre mot?\n");
  scanf("%s", mot);
 
  printf("Votre mot est %s!\n", mot); // On renvoie le mot entré dans "mot"
 
  return 0;
}
