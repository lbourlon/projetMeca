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
	int cube1[6][2][2];
	init(cube1);
	init(cube);
	
	//cube1[3][0][1] = 8;	

	melangeCube(cube);

	affiche(cube);

	BruteForce(cube);
	
	



	


	
}
