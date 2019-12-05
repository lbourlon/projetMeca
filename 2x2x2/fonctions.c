#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Initialise le cube, avec les int couleurs appropriés.
void init(int cube[6][2][2]){
	
	int k;
	for (k = 0; k <= 5; k++)
	{
		int i;
		for(i = 0; i<=1; i++)
		{
			int j;
			for (j = 0; j <= 1 ; j++)
			{
				cube[k][i][j] = k;
			}
			
		}
	}
	
}

//Affiche un cube 2x2x2 sur le terminal.
void affiche(int cube[6][2][2]){
	printf("---------------\n");
	printf("      ");
	printf("%d ",cube[5][0][0]);
	printf("%d ",cube[5][1][0]);
	printf("    \n      ");
	printf("%d ",cube[5][0][1]);
	printf("%d ",cube[5][1][1]);
	printf("        \n");
	printf("      ---        \n");

	printf("%d ",cube[1][0][0]);
	printf("%d ",cube[1][1][0]);
	printf("| ");
	printf("%d ",cube[2][0][0]);
	printf("%d ",cube[2][1][0]);
	printf("| ");
	printf("%d ",cube[3][0][0]);
	printf("%d ",cube[3][1][0]);
	printf("| ");
	printf("%d ",cube[4][0][0]);
	printf("%d ",cube[4][1][0]);
	printf("\n");

	printf("%d ",cube[1][0][1]);
	printf("%d ",cube[1][1][1]);
	printf("| ");
	printf("%d ",cube[2][0][1]);
	printf("%d ",cube[2][1][1]);
	printf("| ");
	printf("%d ",cube[3][0][1]);
	printf("%d ",cube[3][1][1]);
	printf("| ");
	printf("%d ",cube[4][0][1]);
	printf("%d ",cube[4][1][1]);
	printf("\n");
	printf("      ---        \n");
	printf("      ");

	printf("%d ",cube[0][0][0]);
	printf("%d ",cube[0][1][0]);
	printf("        \n");
	printf("      ");
	printf("%d ",cube[0][0][1]);
	printf("%d ",cube[0][1][1]);
	printf("        \n");


	printf("---------------\n");
}

//Prends la face à tourner et le cube en paramètre, et aplique la rotation au cube.
void tourner(int face, int cube[6][2][2]){
	switch(face)
	{
		int temp;
		int temp1;
		
		case 0:
			temp = cube[face][1][0];
			cube[face][1][0] = cube[face][0][0];
			cube[face][0][0] = cube[face][0][1];
			cube[face][0][1] = cube[face][1][1];
			cube[face][1][1] = temp;
			
			temp =  cube[4][0][1];
			temp1 = cube[4][1][1];
			
			int i;
			for (i = 4; i >= 2 ; i = i-1)
			{
				cube[i][0][1] = cube[i-1][0][1];
				cube[i][1][1] = cube[i-1][1][1];
			}
			
			cube[1][0][1] = temp;
			cube[1][1][1] = temp1;
			
			break;
			
		case 1:
			temp = cube[face][1][0];
			cube[face][1][0] = cube[face][0][0];
			cube[face][0][0] = cube[face][0][1];
			cube[face][0][1] = cube[face][1][1];
			cube[face][1][1] = temp;
			
			temp =  cube[4][1][0];
			temp1 = cube[4][1][1];
			
			cube[4][1][0] = cube[0][0][1];
			cube[4][1][1] = cube[0][0][0];
			
			cube[0][0][1] = cube[2][0][1];
			cube[0][0][0] = cube[2][0][0];
			
			cube[2][0][1] = cube[5][0][1];
			cube[2][0][0] = cube[5][0][0];
			
			cube[5][0][1] = temp;
			cube[5][0][0] = temp1;
			
			break;
			
		case 2:
			temp = cube[face][1][0];
			cube[face][1][0] = cube[face][0][0];
			cube[face][0][0] = cube[face][0][1];
			cube[face][0][1] = cube[face][1][1];
			cube[face][1][1] = temp;
			
			temp =  cube[0][0][0];
			temp1 = cube[0][1][0];
			
			cube[0][0][0] = cube[3][0][1];
			cube[0][1][0] = cube[3][0][0];
			
			cube[3][0][1] = cube[5][1][1];
			cube[3][0][0] = cube[5][0][1];
			
			cube[5][1][1] = cube[1][1][0]; 
			cube[5][0][1] = cube[1][1][1];
			
			cube[1][1][0] = temp;
			cube[1][1][1] = temp1;
			
			break;
		
		case 3: 
			//Equivalent de 3x le côté 2
			tourner(1,cube);
			tourner(1,cube);
			tourner(1,cube);
			
			break;
			
		case 4: 
			//Equivalent de 3x le côté 2
			tourner(2,cube);
			tourner(2,cube);
			tourner(2,cube);
			
			break;
		
		case 5:
			//Équivalet de 3x le côté 0
			tourner(0,cube);
			tourner(0,cube);
			tourner(0,cube);
			
			break;
			
		}		
	
	
}


void mtourner(int face, int cube[6][2][2]){
	switch(face)
	{
		int temp;
		int temp1;
		
		case 0:
			temp = cube[face][1][0];
			cube[face][1][0] = cube[face][0][0];
			cube[face][0][0] = cube[face][0][1];
			cube[face][0][1] = cube[face][1][1];
			cube[face][1][1] = temp;
			
			temp =  cube[4][0][1];
			temp1 = cube[4][1][1];
			
			int i;
			for (i = 4; i >= 2 ; i = i-1)
			{
				cube[i][0][1] = cube[i-1][0][1];
				cube[i][1][1] = cube[i-1][1][1];
			}
			
			cube[1][0][1] = temp;
			cube[1][1][1] = temp1;
			
			break;
			
		case 1:
			temp = cube[face][1][0];
			cube[face][1][0] = cube[face][0][0];
			cube[face][0][0] = cube[face][0][1];
			cube[face][0][1] = cube[face][1][1];
			cube[face][1][1] = temp;
			
			temp =  cube[4][1][0];
			temp1 = cube[4][1][1];
			
			cube[4][1][0] = cube[0][0][1];
			cube[4][1][1] = cube[0][0][0];
			
			cube[0][0][1] = cube[2][0][1];
			cube[0][0][0] = cube[2][0][0];
			
			cube[2][0][1] = cube[5][0][1];
			cube[2][0][0] = cube[5][0][0];
			
			cube[5][0][1] = temp;
			cube[5][0][0] = temp1;
			
			break;
			
		case 2:
			temp = cube[face][1][0];
			cube[face][1][0] = cube[face][0][0];
			cube[face][0][0] = cube[face][0][1];
			cube[face][0][1] = cube[face][1][1];
			cube[face][1][1] = temp;
			
			temp =  cube[0][0][0];
			temp1 = cube[0][1][0];
			
			cube[0][0][0] = cube[3][0][1];
			cube[0][1][0] = cube[3][0][0];
			
			cube[3][0][1] = cube[5][1][1];
			cube[3][0][0] = cube[5][0][1];
			
			cube[5][1][1] = cube[1][1][0]; 
			cube[5][0][1] = cube[1][1][1];
			
			cube[1][1][0] = temp;
			cube[1][1][1] = temp1;
			
			break;
		
		case 3: 
			
			temp = cube[face][1][0];
			cube[face][1][0] = cube[face][0][0];
			cube[face][0][0] = cube[face][0][1];
			cube[face][0][1] = cube[face][1][1];
			cube[face][1][1] = temp;
			
			temp =  cube[0][1][0];
			temp1 = cube[0][1][1];
			
			cube[0][1][0] = cube[4][0][1];
			cube[0][1][1] = cube[4][0][0];
			
			cube[4][0][1] = cube[5][1][0];
			cube[4][0][0] = cube[5][1][1];
			
			cube[5][1][1] = cube[2][1][1]; 
			cube[5][1][0] = cube[2][1][0];
			
			cube[2][1][0] = temp;
			cube[2][1][1] = temp1;
			
			
			break;
			
		case 4: 
			
			
			temp = cube[face][1][0];
			cube[face][1][0] = cube[face][0][0];
			cube[face][0][0] = cube[face][0][1];
			cube[face][0][1] = cube[face][1][1];
			cube[face][1][1] = temp;
			
			temp =  cube[3][1][0];
			temp1 = cube[3][1][1];
			
			cube[3][1][0] = cube[0][1][1];
			cube[3][1][1] = cube[0][0][1];
			
			cube[0][1][1] = cube[1][0][1];
			cube[0][0][1] = cube[1][0][0];
			
			cube[1][0][1] = cube[5][0][0]; 
			cube[1][0][0] = cube[5][1][0];
			
			cube[5][0][0] = temp;
			cube[5][1][0] = temp1;
			
			break;
		
		case 5:	
			
			temp = cube[face][1][0];
			cube[face][1][0] = cube[face][0][0];
			cube[face][0][0] = cube[face][0][1];
			cube[face][0][1] = cube[face][1][1];
			cube[face][1][1] = temp;
			
			temp =  cube[2][1][0];
			temp1 = cube[2][0][0];
			
			cube[2][1][0] = cube[3][1][0];
			cube[2][0][0] = cube[3][0][0];
			
			cube[3][1][0] = cube[4][1][0];
			cube[3][0][0] = cube[4][0][0];
			
			cube[4][1][0] = cube[1][1][0]; 
			cube[4][0][0] = cube[1][0][0];
			
			cube[1][1][0] = temp;
			cube[1][0][0] = temp1;
	
			break;
			
		}		
	
	
}

//Fait tourner une face aléatoire du cube en orientation aléatoire
void randTour(int cube[6][2][2]){
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

//Mélange un cube 2x2x2.
void melangeCube(int cube[6][2][2]){
	int i;
	for (i = 0; i < 20; i++)
	{
		randTour(cube);
	}
	
}

//Compare deux cubes, rends 1 si identiques et 0 sinon.
int compare(int cube1[6][2][2], int cube2[6][2][2]){
	int i = 0;
	while (i <= 5)
	{
		int j = 0;
		while (j <= 1)
		{
			int k = 0;
			while (k <= 1)
			{
				if(cube1[i][j][k] != cube2[i][j][k]){
					return 0;
				}
				
				k = k+1;
			}
			
			j = j+1;
		}
		
		i=i+1;
	}
	return 1;
	
}

//Copie cube a dans cube b.
void copieCube(int CubeACopier[6][2][2], int CubeSortie[6][2][2]){
	int k;
	for (k = 0; k <= 5; k++)
	{
		int i;
		for(i = 0; i<=1; i++)
		{
			int j;
			for (j = 0; j <= 1 ; j++)
			{
				CubeSortie[k][i][j] = CubeACopier[k][i][j];
			}
			
		}
	}
}
	
int verifie( int CubeSortie[6][2][2]){
	int sortie = 0;
	for(int i = 1; i <= 4; i++){
		if(!(CubeSortie[i][0][0] == CubeSortie[i][1][0] && 
			 CubeSortie[i][0][1] == CubeSortie[i][1][1] &&
			 CubeSortie[i][0][0] == CubeSortie[i][1][1]))
		{
			return 0;
		}
	}
	return 1;
}


/*La fonction prend en paramètre un pointeur pour un compteur (un entier) et le
 * tableau de solution qui est retourné par BruteForce.
 * La fonction compte juste le nombre de éléments dans tabSolution
 */
int CompteMouvementBF(int TabSolution[14]){
	
	int i = 0, compt = 0;
	while(TabSolution[i] != -1)
	{
		compt = compt + 1;
		i = i + 1;
	}
	return compt;
}


/* A exécuter après la fonction startClock pour mesurer un temps.
 * 
 * Prends en paramètre un objet clock avec le temps de début (retourné par startClock)
 * et calcule le temps passé entre les deux instants. La fonction retourne ensuite le double temps.
 */
double stopClock(clock_t tempsDebut){
	clock_t end;
	double timeUsed; 
	end = clock();
	timeUsed = ((double) (end - tempsDebut)) / CLOCKS_PER_SEC;
	
	return timeUsed;
}




