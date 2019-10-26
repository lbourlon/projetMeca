#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fonctions.h"

#define BLANC = 0
#define GREEN = 1
#define ORANGE = 2
#define BLUE = 3
#define RED = 4
#define YELLOW = 5

void main(){
	
	srand(time(NULL));
	
	int cube[6][2][2];
	int cubeParfait[6][2][2];

	
	init(cubeParfait);
	init(cube);

	
	melangeCube(cube);
	affiche(cube);

	
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
