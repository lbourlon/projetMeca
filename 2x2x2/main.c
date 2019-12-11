#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fonctions.h"
#include "resolution.h"

//Définition des couleurs
#define WHITE   0
#define GREEN   1
#define ORANGE  2
#define BLUE    3
#define RED     4
#define YELLOW  5



//Simple fonction pour entrer les données d'un cube par l'utilisateur.
void EntrerDonnees(int cube[6][2][2]){

	cube[0][0][0] = WHITE;
	cube[0][1][0] = YELLOW;
	cube[0][0][1] = GREEN;
	cube[0][1][1] = GREEN;

	cube[1][0][0] = WHITE;
	cube[1][1][0] = YELLOW;
	cube[1][0][1] = RED;
	cube[1][1][1] = BLUE;

	cube[2][0][0] = RED;
	cube[2][1][0] = ORANGE;
	cube[2][0][1] = RED;
	cube[2][1][1] = RED;
	
	cube[3][0][0] = BLUE;
	cube[3][1][0] = GREEN;
	cube[3][0][1] = BLUE;
	cube[3][1][1] = ORANGE;

	cube[4][0][0] = ORANGE;
	cube[4][1][0] = ORANGE;
	cube[4][0][1] = WHITE;
	cube[4][1][1] = WHITE;

	cube[5][0][0] = BLUE;
	cube[5][1][0] = YELLOW;
	cube[5][0][1] = GREEN;
	cube[5][1][1] = YELLOW;
}



void main(){

	srand(time(NULL)); //Pour les fonction de mélange
	
		
	//-----------------   LISTE DES COINS      ----------------------------
	//Elle sert à savoir où regarder dans le cube pour trouver les coins, elle simplifie le code 
	coin tabCoins[8] = {rc(2,1,0,5,1,1,3,0,0), rc(2,1,1,3,0,1,0,1,0), rc(2,0,1,0,0,0,1,1,1), rc(2,0,0,1,1,0,5,0,1),
						rc(5,1,0,3,1,0,4,0,0), rc(0,1,1,3,1,1,4,0,1), rc(4,1,1,0,0,1,1,0,1), rc(4,1,0,5,0,0,1,0,0)};
	//----------------------------------------------------------------------

	SortieDonnees(tabCoins, 20);
	//pour sortir les donnes



	int cube[6][2][2];
	init(cube);
	melangeCube(cube);
	



	//-----------------   Pour Rentrer le cube à la main      ----------------------------
	//Utiliser Entrer Donées en bien prenant soin de l'orientation initiale
	
	EntrerDonnees(cube);
	//----------------------------------------------------------------------

	affiche(cube);



	
	//-----------------   Pour Utiliser SmartSolve      ----------------------------
	//Creer compteur et rentrer cube mélangee en paramètre
	/*
	int compteurTours = 0;
	clock_t TempsSS = clock(); //initialise un clock
	SmartSolve(cube, tabCoins, &compteurTours);
	double tempsEcoule = stopClock(TempsSS);
	
	printf("nombre de tours : %d\n", compteurTours);
	printf("temps de calcul : %f\n", tempsEcoule);
	*/
	
	//----------------------------------------------------------------------




	
	//-----------------   Pour Utiliser BruteForce      ----------------------------
	//Creer compteur et rentrer cube mélangé en paramètre
	/*
	clock_t TempsBF = clock(); //initialise un clock
	int* tabSolution = BruteForce(cube);
	double tempsEcouleBF = stopClock(TempsBF);
	
	AppliqueSolution(cube,tabSolution);
	

	int compteurToursBF = CompteMouvementBF(tabSolution);
	
	
	printf("nombre de tours : %d\n", compteurToursBF);
	printf("temps de calcul : %f\n", tempsEcouleBF);
	
		
	printTabSolution(tabSolution);
	*/
	
	
	//----------------------------------------------------------------------

	

	affiche(cube);
	
}
