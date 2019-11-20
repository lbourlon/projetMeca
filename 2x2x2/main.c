#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fonctions.h"

/*
#define WHITE = 0
#define GREEN = 1
#define ORANGE = 2
#define BLUE = 3
#define RED = 4
#define YELLOW = 5 */

void main(){
	
	int WHITE = 0;
	int GREEN = 1;
	int ORANGE = 2;
	int BLUE = 3;
	int RED = 4;
	int YELLOW = 5;
		
	srand(time(NULL));
	
	int cube[6][2][2];
	int cubeParfait[6][2][2];

	
	/*init(cubeParfait);
	init(cube);

	
	melangeCube(cube);
	affiche(cube);*/
	
	cube[0][0][0] = GREEN;
	cube[0][1][0] = WHITE;
	cube[0][0][1] = YELLOW;
	cube[0][1][1] = YELLOW;
	
	cube[2][0][0] = WHITE;
	cube[2][1][0] = ORANGE;
	cube[2][0][1] = YELLOW;
	cube[2][1][1] = BLUE;
	
	cube[5][0][0] = ORANGE;
	cube[5][1][0] = ORANGE;
	cube[5][0][1] = GREEN;
	cube[5][1][1] = YELLOW;
	
	cube[1][0][0] = WHITE;
	cube[1][1][0] = RED;
	cube[1][0][1] = BLUE;
	cube[1][1][1] = RED;

	cube[4][0][0] = BLUE;
	cube[4][1][0] = GREEN;
	cube[4][0][1] = GREEN;
	cube[4][1][1] = RED;
	
	cube[3][0][0] = BLUE;
	cube[3][1][0] = WHITE;
	cube[3][0][1] = RED;
	cube[3][1][1] = ORANGE;
	
	int* tabSolution = BruteForce(cube);
	//int tabSolution[14] = {0,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	int i = 0;
	printf("\n Une solution est: |");
	for (i = 0; i < 14; i++)
	{
		printf("%d|",tabSolution[i]);
	}
	printf("\n");
	
	AppliqueSolution(cube,tabSolution);
	affiche(cube);
	

	//printf("compare : %d\n", compare(cube,cubeParfait));
	
/*	
	affiche(cube);
	tourner(2,cube);
	affiche(cube);
*/


	


	
}
