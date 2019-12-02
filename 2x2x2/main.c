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
	srand(time(NULL)); //Pour les fonction de mélange
	
	clock_t SmartSolveClock;
	clock_t BruteForceClock;

	double tempsSmartSolve;
	double tempsBruteForce;
	


	//--------------------------   LISTE DES COINS      ----------------------------
	coin tabCoins[8] = {rc(2,1,0,5,1,1,3,0,0), rc(2,1,1,3,0,1,0,1,0), rc(2,0,1,0,0,0,1,1,1), rc(2,0,0,1,1,0,5,0,1),
						rc(5,1,0,3,1,0,4,0,0), rc(0,1,1,3,1,1,4,0,1), rc(4,1,1,0,0,1,1,0,1), rc(4,1,0,5,0,0,1,0,0)};
	//-------------------------------------------------------------------------------
	
	int cube1[6][2][2];
	int cube2[6][2][2];

	
	init(cube1);
	
	melangeCube(cube1);	
	affiche(cube1);
	copieCube(cube1, cube2);
	

	//--------------------------   SMART SOLVE      ----------------------------
	SmartSolveClock = startClock();
	FaireFaceOrange(cube1, tabCoins);	
	FaireCoinsRouge(cube1);
	FaireCoinsFinal(cube1);
	tempsSmartSolve = endClock(SmartSolveClock);
	
	//--------------------------   BRUTE FORCE      ----------------------------

	BruteForceClock = startClock();
	int* tabSolution = BruteForce(cube2);
	AppliqueSolution(cube2,tabSolution);
	affiche(cube2);
	tempsBruteForce = endClock(BruteForceClock);

	//printTabSolution(tabSolution);
	
	printf("Temps mis pour SmartSolve est : %f (en secondes).\n",tempsSmartSolve);
	printf("temps mis pour BruteForce est : %f (en secondes).\n",tempsBruteForce);
	
	
}
