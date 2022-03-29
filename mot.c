mot.c

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  char mot = 0; // 

  printf("Quel est votre mot?\n");
  scanf("%s",&mot);
 
  printf("Votre mot est %s!\n", mot); // On renvoie le mot entré dans "mot"
 
  return 0;
}
