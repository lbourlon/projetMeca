#include <cini.h>
#include <SDL2/SDL.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fonctions.h"
#include "resolution.h"


#define TAILLE_CASE 20
#define HAUTEUR 6
#define LARGEUR 8


void afficher_plateau(int plateau[HAUTEUR][LARGEUR], char* tab[]){
	
	CINI_fill_window("white"); //On changera en "black" après

	int i, j;
	for (j = 0; j < LARGEUR; j += 1){
		for (i = 0; i < HAUTEUR; i += 1){
			if (plateau[i][j] == -1){
				CINI_fill_rect(i*TAILLE_CASE,j*TAILLE_CASE,TAILLE_CASE,TAILLE_CASE,"black");
			}
			if (plateau[i][j] != -1){
				CINI_fill_rect(i*TAILLE_CASE,j*TAILLE_CASE,TAILLE_CASE,TAILLE_CASE,tab[plateau[i][j]]);
			}
		}
	}
}


main()
{
	int tab_fenetre[HAUTEUR][LARGEUR];
	char* tab_couleur[7]={"yellow","cyan","orange","blue","red","green","purple"};
	afficher_plateau(tab_fenetre, tab_couleur);
}
