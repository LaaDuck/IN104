#wordle

Bienvenue ! Ceci est une implémentation de WORDLE. 

La commande si vous voulez jouer le jeu vous-même :

à taper dans le main :

cd Documents puis
cd IN104 puis
gcc -o main.out main.c puis
./main.out joueur

puis suivre les étapes indiquées par le jeu.

Le mot que vous devez rentré doit faire 5 lettres, sinon de toute manière le jeu vous renverra un message d'erreur.
Si la lettre est à la bonne place dans le mot, elle s'affichera en vert.
Si elle est présente dans le mot mais à la mauvaise place, elle s'affichera en jaune.
Si elle n'est pas dans le mot à deviner, elle s'affichera en gris.

Vous avez 6 tentatives, si vous n'avez pas trouvé à l'issue de ces 6 essais, le jeu vous renverra un message explicit vous disant que vous avez perdu.
Si vous trouvez en moins de 6 essais, vous serez félicité. 

Bonne partie !

La commande si vous voulez que l'ordi joue le jeu :

à taper dans le main :

cd Documents puis
cd IN104 puis
gcc -o main.out main.c puis
./main.out ordi

Vous verrez par la suite s'afficher les tentatives jouées par l'ordinateur, et le résultat final : si il a gagné ou non. 
