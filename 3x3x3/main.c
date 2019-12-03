#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fonctions.h"
#include "resolution.h"


void main()
{
	srand(time(NULL));
	int WHITE  = 0;
	int GREEN  = 1;
	int ORANGE = 2;
	int BLUE   = 3;
	int RED    = 4;
	int YELLOW = 5;
	
	//----------------    LISTE DES MILIEUX       ------------------------
	milieu tabMilieux[12] = {rm(0,1,0,2,1,2), rm(0,2,1,3,1,2), rm(0,0,1,1,1,2), 
							 rm(0,1,2,4,1,2), rm(1,0,1,4,2,1), rm(1,1,0,5,0,1),
							 rm(1,2,1,2,0,1), rm(2,1,0,5,1,2), rm(2,2,1,3,0,1),
							 rm(3,1,0,5,2,1), rm(4,1,0,5,1,0), rm(3,2,1,4,0,1)};
	//---------------------------------------------------------------------
	//-----------------   LISTE DES COINS      ----------------------------
	coin tabCoins[8] = {rc(2,2,0,5,2,2,3,0,0), rc(2,2,2,3,0,2,0,2,0), rc(2,0,2,0,0,0,1,2,2), rc(2,0,0,1,2,0,5,0,2),
						rc(5,2,0,3,2,0,4,0,0), rc(0,2,2,3,2,2,4,0,2), rc(4,2,2,0,0,2,1,0,2), rc(4,2,0,5,0,0,1,0,0)};
	//----------------------------------------------------------------------
	
	int compteur = 0;
				  
	int cube[6][3][3];
	init(cube);
	
	
	
	melangeCube(cube);
	affiche(cube);

	

	printf("---------------------------------------------------\n");
	//--------------------Face Orange
	FaireCroixOrange(cube,tabMilieux, &compteur); 
	FinirFaceOrange(cube, tabCoins, &compteur);
	printf("---------------------------------------------------\n");
	//--------------------Deuxième Couronne
	FaireCouronne(cube, tabMilieux,tabCoins, &compteur);
	printf("---------------------------------------------------\n");
	//--------------------Croix Rouge Couronne
	FaireCroixRouge(cube, &compteur);
	//--------------------Coins Rouge
	FaireCoinsRouge(cube, &compteur);
	printf("---------------------------------------------------\n");
	//--------------------Positionnement Coins Rouge
	FaireCoinsFinal(cube, &compteur);
	printf("---------------------------------------------------\n");
	//--------------------Positionnement Milieux Rouge
	affiche(cube);
	FinirCube(cube, &compteur);
	printf("---------------------------------------------------\n");
	
	
	affiche(cube);

	printf("Nombre de tour: %d\n", compteur);
	
	/*int* tabSolution = BruteForce(cube);
	AppliqueSolution(cube,tabSolution);
	affiche(cube);

	printTabSolution(tabSolution);*/

	
	

}
