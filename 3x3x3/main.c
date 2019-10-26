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

void main()
{
	srand(time(NULL));
	
	int cube[6][3][3];
	int cubeParfait[6][3][3];

	
	init(cubeParfait);
	init(cube);
	cube[0][0][0] = 8;
	cube[5][0][1] = 9;
	tourner(1,cube);
	//melangeCube(cube);
	affiche(cube);
	
	
}
