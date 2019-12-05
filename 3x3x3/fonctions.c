/* Ce ficher contient toutes le fonctions prélimintaires de définition du cube
 * et toutes les fonctions suplémentaires. 
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Prends un cube en paramètre, c'est à dire une matrice [6][3][3] et
 * l'initialise avec des entiers 'couleurs' suivant les couleurs du rubiks cube.
 */
void init(int cube[6][3][3]){
	
	int k;
	for (k = 0; k <= 5; k++)
	{
		int i;
		for(i = 0; i<=2; i++)
		{
			int j;
			for (j = 0; j <= 2 ; j++)
			{
				cube[k][i][j] = k;
			}
			
		}
	}
	
}

//Copie un cubeA dans un cubeB
void copie(int cubeACopier[6][3][3], int cubeAColler[6][3][3]){
	
	int k;
	for (k = 0; k <= 5; k++)
	{
		int i;
		for(i = 0; i<=2; i++)
		{
			int j;
			for (j = 0; j <= 2 ; j++)
			{
				cubeAColler[k][i][j] = cubeACopier[k][i][j];
			}
			
		}
	}
	
}


//Affiche un cube sur le terminal
void affiche(int cube[6][3][3]){
	printf("  ");
	printf("  ");
	printf("  ");
	printf("  ");
	printf("%d ",cube[5][0][0]);
	printf("%d ",cube[5][1][0]);
	printf("%d ",cube[5][2][0]);
			printf("\n");
	printf("  ");
	printf("  ");
	printf("  ");
	printf("  ");
	printf("%d ",cube[5][0][1]);
	printf("%d ",cube[5][1][1]);
	printf("%d ",cube[5][2][1]);
			printf("\n");
	printf("  ");
	printf("  ");
	printf("  ");
	printf("  ");
	printf("%d ",cube[5][0][2]);
	printf("%d ",cube[5][1][2]);
	printf("%d ",cube[5][2][2]);
			printf("\n");
	printf("        -----\n");


	printf("%d ",cube[1][0][0]);
	printf("%d ",cube[1][1][0]);
	printf("%d ",cube[1][2][0]);
	printf("| ");
	printf("%d ",cube[2][0][0]);
	printf("%d ",cube[2][1][0]);
	printf("%d ",cube[2][2][0]);
	printf("| ");
	printf("%d ",cube[3][0][0]);
	printf("%d ",cube[3][1][0]);
	printf("%d ",cube[3][2][0]);
	printf("| ");
	printf("%d ",cube[4][0][0]);
	printf("%d ",cube[4][1][0]);
	printf("%d ",cube[4][2][0]);
			printf("\n");
	printf("%d ",cube[1][0][1]);
	printf("%d ",cube[1][1][1]);
	printf("%d ",cube[1][2][1]);
	printf("| ");
	printf("%d ",cube[2][0][1]);
	printf("%d ",cube[2][1][1]);
	printf("%d ",cube[2][2][1]);
	printf("| ");
	printf("%d ",cube[3][0][1]);
	printf("%d ",cube[3][1][1]);
	printf("%d ",cube[3][2][1]);
	printf("| ");
	printf("%d ",cube[4][0][1]);
	printf("%d ",cube[4][1][1]);
	printf("%d ",cube[4][2][1]);
			printf("\n");
	printf("%d ",cube[1][0][2]);
	printf("%d ",cube[1][1][2]);
	printf("%d ",cube[1][2][2]);
	printf("| ");
	printf("%d ",cube[2][0][2]);
	printf("%d ",cube[2][1][2]);
	printf("%d ",cube[2][2][2]);
	printf("| ");
	printf("%d ",cube[3][0][2]);
	printf("%d ",cube[3][1][2]);
	printf("%d ",cube[3][2][2]);
	printf("| ");
	printf("%d ",cube[4][0][2]);
	printf("%d ",cube[4][1][2]);
	printf("%d ",cube[4][2][2]);
				printf("\n");

	printf("        -----\n");


	printf("  ");
	printf("  ");
	printf("  ");
	printf("  ");
	printf("%d ",cube[0][0][0]);
	printf("%d ",cube[0][1][0]);
	printf("%d ",cube[0][2][0]);
			printf("\n");
	printf("  ");
	printf("  ");
	printf("  ");
	printf("  ");
	printf("%d ",cube[0][0][1]);
	printf("%d ",cube[0][1][1]);
	printf("%d ",cube[0][2][1]);
	printf("  ");
	printf("  ");
	printf("  ");
	printf("  ");
	printf("  ");
	printf("  ");
			printf("\n");
	printf("  ");
	printf("  ");
	printf("  ");
	printf("  ");
	printf("%d ",cube[0][0][2]);
	printf("%d ",cube[0][1][2]);
	printf("%d ",cube[0][2][2]);
	printf("  ");
	printf("  ");
	printf("  ");
	printf("  ");
	printf("  ");
	printf("  ");
			printf("\n");
}

/* Prends un cube en paramètre et la face à tourner fait tourner cette face.
 * Ceci en suivant les règles physiques imposés par le cube.
 * Les rotations sont faites en sens Horaire (suivant le schéma).
 */

void tourner(int face, int cube[6][3][3]){
		
		//S'applique indépendament de la face, fait tourner les valeurs sur celle-ci
			int temp;
			temp = cube[face][0][0];
			cube[face][0][0] = cube[face][0][2];
			cube[face][0][2] = cube[face][2][2];
			cube[face][2][2] = cube[face][2][0];
			cube[face][2][0] = temp;
				
			temp = cube[face][1][0];
			cube[face][1][0] = cube[face][0][1];
			cube[face][0][1] = cube[face][1][2];
			cube[face][1][2] = cube[face][2][1];
			cube[face][2][1] = temp;
		
		
		//SENS HORAIRE
	
		int temp0;
		int temp1;
		int temp2;
		
		//Suivant la face choisie, il faudra changer différement les couleurs
		switch(face){
			case 0:
				
				temp0 = cube[1][0][2];
				temp1 = cube[1][1][2];
				temp2 = cube[1][2][2];
				
				
				cube[1][2][2] = cube[4][2][2];
				cube[1][1][2] = cube[4][1][2];
				cube[1][0][2] = cube[4][0][2];
				
				cube[4][2][2] = cube[3][2][2];
				cube[4][1][2] = cube[3][1][2];
				cube[4][0][2] = cube[3][0][2];
				
				cube[3][2][2] = cube[2][2][2];
				cube[3][1][2] = cube[2][1][2];
				cube[3][0][2] = cube[2][0][2];
				
				cube[2][2][2] = temp2;
				cube[2][1][2] = temp1;
				cube[2][0][2] = temp0;
				break;
				
			case 1:
				
				temp0 = cube[5][0][0];
				temp1 = cube[5][0][1];
				temp2 = cube[5][0][2];
				
				cube[5][0][2] = cube[4][2][0];
				cube[5][0][1] = cube[4][2][1]; 
				cube[5][0][0] = cube[4][2][2];
				
				cube[4][2][0] = cube[0][0][2]; 
				cube[4][2][1] = cube[0][0][1];
				cube[4][2][2] = cube[0][0][0];
			
				cube[0][0][2] = cube[2][0][2];
				cube[0][0][1] = cube[2][0][1];
				cube[0][0][0] = cube[2][0][0];
				
				cube[2][0][2] = temp2;
				cube[2][0][1] = temp1;
				cube[2][0][0] = temp0;
				break;
			
			case 2:
				
				temp0 = cube[0][0][0];
				temp1 = cube[0][1][0];
				temp2 = cube[0][2][0];
				
				cube[0][0][0] = cube[3][0][2];
				cube[0][1][0] = cube[3][0][1];
				cube[0][2][0] = cube[3][0][0];
				
				cube[3][0][2] = cube[5][2][2];
				cube[3][0][1] = cube[5][1][2];
				cube[3][0][0] = cube[5][0][2];
				
				cube[5][2][2] = cube[1][2][0];
				cube[5][1][2] = cube[1][2][1];
				cube[5][0][2] = cube[1][2][2];
				
				cube[1][2][0] = temp0;
				cube[1][2][1] = temp1;
				cube[1][2][2] = temp2;
				break;
				
			case 3:
				
				temp0 = cube[5][2][2];
				temp1 = cube[5][2][1];
				temp2 = cube[5][2][0];
				
				
				cube[5][2][2] = cube[2][2][2];
				cube[5][2][1] = cube[2][2][1];
				cube[5][2][0] = cube[2][2][0];
				
				cube[2][2][2] = cube[0][2][2];
				cube[2][2][1] = cube[0][2][1];
				cube[2][2][0] = cube[0][2][0];
				
				cube[0][2][0] = cube[4][0][2];
				cube[0][2][1] = cube[4][0][1];
				cube[0][2][2] = cube[4][0][0];
				
				cube[4][0][2] = temp2;
				cube[4][0][1] = temp1;
				cube[4][0][0] = temp0;
				break;
				
			case 4:
				
				temp0 = cube[5][0][0];
				temp1 = cube[5][1][0];
				temp2 = cube[5][2][0];
				
				
				cube[5][2][0] = cube[3][2][2];
				cube[5][1][0] = cube[3][2][1];
				cube[5][0][0] = cube[3][2][0];
				
				cube[3][2][0] = cube[0][2][2];
				cube[3][2][1] = cube[0][1][2];
				cube[3][2][2] = cube[0][0][2];
				
				cube[0][2][2] = cube[1][0][2];
				cube[0][1][2] = cube[1][0][1];
				cube[0][0][2] = cube[1][0][0];
				
				cube[1][0][2] = temp0;
				cube[1][0][1] = temp1;
				cube[1][0][0] = temp2;
				break;
			
			case 5:
				
				temp0 = cube[3][2][0];
				temp1 = cube[3][1][0];
				temp2 = cube[3][0][0];
				
				
				cube[3][0][0] = cube[4][0][0];
				cube[3][1][0] = cube[4][1][0];
				cube[3][2][0] = cube[4][2][0];
				
				cube[4][0][0] = cube[1][0][0];
				cube[4][1][0] = cube[1][1][0];
				cube[4][2][0] = cube[1][2][0];
				
				cube[1][0][0] = cube[2][0][0];
				cube[1][1][0] = cube[2][1][0];
				cube[1][2][0] = cube[2][2][0];
				
				
				cube[2][0][0] = temp2;
				cube[2][1][0] = temp1;
				cube[2][2][0] = temp0;
				break;
		
		}


}




//Fait tourner une face aléatoire du cube en orientation aléatoire
void randTour(int cube[6][3][3]){
	int randFace = (rand() % (6));
	int randOrientation = (rand() % (2));
	
	if(randOrientation == 0){
		tourner(randFace, cube);
	} else {
		tourner(randFace, cube);
		tourner(randFace, cube);
		tourner(randFace, cube);
	}
}

//Utilise randTour pour mélanger le cube: en tout 20 mouvements
void melangeCube(int cube[6][3][3]){
	int i;
	for (i = 0; i < 40; i++)
	{
		randTour(cube);
	}
	
}


/* A exécuter après la fonction startClock pour mesurer un temps.
 * 
 * Prends en paramètre un objet clock avec le temps de début (retourné par startClock)
 * et calcule le temps passé entre les deux instants. La fonction retourne ensuite le double temps.
 */
float stopClock(clock_t tempsDebut){
	clock_t end;
	double timeUsed; 
	end = clock();
	timeUsed = ((double) (end - tempsDebut)) / CLOCKS_PER_SEC;
	
	return timeUsed;
}
