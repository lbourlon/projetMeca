#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fonctions.h"
#include "resolution.h"

#define WHITE   0
#define GREEN   1
#define ORANGE  2
#define BLUE    3
#define RED     4
#define YELLOW  5




void hello(int cube[6][2][2]){

	cube[0][0][0] = WHITE;
	cube[0][1][0] = YELLOW;
	cube[0][0][1] = YELLOW;
	cube[0][1][1] = WHITE;

	cube[1][0][0] = ORANGE;
	cube[1][1][0] = RED;
	cube[1][0][1] = ORANGE;
	cube[1][1][1] = BLUE;

	cube[2][0][0] = YELLOW;
	cube[2][1][0] = WHITE;
	cube[2][0][1] = RED;
	cube[2][1][1] = GREEN;
	
	cube[3][0][0] = GREEN;
	cube[3][1][0] = BLUE;
	cube[3][0][1] = RED;
	cube[3][1][1] = GREEN;

	cube[4][0][0] = ORANGE;
	cube[4][1][0] = GREEN;
	cube[4][0][1] = ORANGE;
	cube[4][1][1] = BLUE;

	cube[5][0][0] = YELLOW;
	cube[5][1][0] = WHITE;
	cube[5][0][1] = BLUE;
	cube[5][1][1] = RED;
}



void main(){
	srand(time(NULL));
	//-----------------   LISTE DES COINS      ----------------------------
	coin tabCoins[8] = {rc(2,1,0,5,1,1,3,0,0), rc(2,1,1,3,0,1,0,1,0), rc(2,0,1,0,0,0,1,1,1), rc(2,0,0,1,1,0,5,0,1),
						rc(5,1,0,3,1,0,4,0,0), rc(0,1,1,3,1,1,4,0,1), rc(4,1,1,0,0,1,1,0,1), rc(4,1,0,5,0,0,1,0,0)};
	//----------------------------------------------------------------------

	int cube[6][2][2];
	int compteur = 0;

	init(cube);
	affiche(cube);

	
	melangeCube(cube);	
	affiche(cube);

	/*
	FaireFaceOrange(cube, tabCoins, &compteur);	
	affiche(cube);

	FaireCoinsRouge(cube, &compteur);
	affiche(cube);

	FaireCoinsFinal(cube, &compteur);
	affiche(cube);
	printf("le nombre de tour est: %d\n",compteur);
	
	*/
	//-----------------------BRUTE FORCE----------------

	int* tabSolution = BruteForce(cube);
	AppliqueSolution(cube,tabSolution);
	affiche(cube);



	
	printf("%d\n",tabSolution[1]);
	printf("%d\n",tabSolution[2]);
	printf("%d\n",tabSolution[3]);
	printf("%d\n",tabSolution[4]);
	printf("%d\n",tabSolution[5]);
	printf("%d\n",tabSolution[6]);
	printf("%d\n",tabSolution[7]);
	printf("%d\n",tabSolution[8]);
	printf("%d\n",tabSolution[9]);
	printf("%d\n",tabSolution[10]);
	printf("%d\n",tabSolution[11]);
	printf("%d\n",tabSolution[12]);

	int compt = 0;
	CompteMouvementBF(&compt, tabSolution);
	printf("le nombre de tour est : %d\n", compt);

	printTabSolution(tabSolution);
	
	
	
}
