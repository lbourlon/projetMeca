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
	cube[0][1][0] = ORANGE;
	cube[0][0][1] = BLUE;
	cube[0][1][1] = BLUE;

	cube[1][0][0] = YELLOW;
	cube[1][1][0] = RED;
	cube[1][0][1] = YELLOW;
	cube[1][1][1] = BLUE;

	cube[2][0][0] = GREEN;
	cube[2][1][0] = WHITE;
	cube[2][0][1] = RED;
	cube[2][1][1] = BLUE;
	
	cube[3][0][0] = ORANGE;
	cube[3][1][0] = RED;
	cube[3][0][1] = WHITE;
	cube[3][1][1] = YELLOW;

	cube[4][0][0] = WHITE;
	cube[4][1][0] = ORANGE;
	cube[4][0][1] = RED;
	cube[4][1][1] = ORANGE;

	cube[5][0][0] = GREEN;
	cube[5][1][0] = GREEN;
	cube[5][0][1] = YELLOW;
	cube[5][1][1] = GREEN;
}



void main(){

	srand(time(NULL)); //Pour les fonction de mélange
	
	clock_t SmartSolveClock;
	clock_t BruteForceClock;

	double tempsSmartSolve;
	double tempsBruteForce;
	
	
	//-----------------   LISTE DES COINS      ----------------------------
	coin tabCoins[8] = {rc(2,1,0,5,1,1,3,0,0), rc(2,1,1,3,0,1,0,1,0), rc(2,0,1,0,0,0,1,1,1), rc(2,0,0,1,1,0,5,0,1),
						rc(5,1,0,3,1,0,4,0,0), rc(0,1,1,3,1,1,4,0,1), rc(4,1,1,0,0,1,1,0,1), rc(4,1,0,5,0,0,1,0,0)};
	//----------------------------------------------------------------------


	SortieDonnees(tabCoins);
	
	
	
	
	
	//int cube[6][2][2];
	//init(cube);
	//hello(cube);
	
	
	
	/*
	int compteur = 0;
	
	SmartSolve(cube, tabCoins, &compteur);
	
	printf("compteur : %d\n", compteur);
	*/

	//-----------------------BRUTE FORCE----------------
	/*
	affiche(cube);
	int* tabSolution = BruteForce(cube);
	AppliqueSolution(cube,tabSolution);
	affiche(cube);


	int compt = 0;
	CompteMouvementBF(&compt, tabSolution);
	

	printTabSolution(tabSolution);
	*/
	
	
}
