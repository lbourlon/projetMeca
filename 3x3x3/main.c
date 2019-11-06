#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fonctions.h"
#include "resolution.h"


void main()
{
	int WHITE  = 0;
	int GREEN  = 1;
	int ORANGE = 2;
	int BLUE   = 3;
	int RED    = 4;
	int YELLOW = 5;
	srand(time(NULL));
	//----------------    LISTE DES MILIEUX       ------------------------
	milieu tabMilieux[12] = {rm(0,1,0,2,1,2), rm(0,2,1,3,1,2), rm(0,0,1,1,1,2), 
							 rm(0,1,2,4,1,2), rm(1,0,1,4,2,1), rm(1,1,0,5,0,1),
							 rm(1,2,1,2,0,1), rm(2,1,0,5,1,2), rm(2,2,1,3,0,1),
							 rm(3,1,0,5,2,1), rm(4,1,0,5,1,0), rm(3,2,1,4,0,1)};
	//---------------------------------------------------------------------
	
				  
	int cube[6][3][3];
	int cubeParfait[6][3][3];

	
	init(cubeParfait);
	init(cube);
	//cube[5][0][0] = 8;
	//cube[4][0][0] = 9;
	
	tourner(2,cube);
	
	melangeCube(cube);
	affiche(cubeParfait);
	printf("---------------------------------------------------\n");
	affiche(cube);
	printf("---------------------------------------------------\n");
	
	milieu mil1 = RechercherMilieu(cubeParfait, tabMilieux, GREEN, ORANGE);
	milieu mil2 = RechercherMilieu(cube, tabMilieux, GREEN, ORANGE);
	
	printf("%d %d %d %d %d %d\n", mil1.coord1.face, mil1.coord1.x, mil1.coord1.y, mil1.coord2.face, mil1.coord2.x, mil1.coord2.y);
	printf("%d %d %d %d %d %d\n", mil2.coord1.face, mil2.coord1.x, mil2.coord1.y, mil2.coord2.face, mil2.coord2.x, mil2.coord2.y);
	
		
	/*for(int i = 0; i < 12; i++){
			cube[tabMilieux[i].coord1.face][tabMilieux[i].coord1.x][tabMilieux[i].coord1.y] = 8+i; 
			cube[tabMilieux[i].coord2.face][tabMilieux[i].coord2.x][tabMilieux[i].coord2.y] = 8+i; 
	}*/	
}
