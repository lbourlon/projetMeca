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

	
	//melangeCube(cube);

	tourner(0,cube);
	
	//int* tabSolution = BruteForce(cube);
	int tabSolution[14] = {0,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

	resout(cube,tabSolution);

	printf("compare : %d\n", compare(cube,cubeParfait));
	
	



	


	
}
