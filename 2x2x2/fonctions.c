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

//Affiche un cube 2x2x2 sur le terminale.
void affiche(int cube[6][2][2]){
	printf("    ");
	printf("%d ",cube[5][0][0]);
	printf("%d ",cube[5][1][0]);
	printf("        \n    ");

	printf("%d ",cube[5][0][1]);
	printf("%d ",cube[5][1][1]);
	printf("        \n");

	printf("%d ",cube[1][0][0]);
	printf("%d ",cube[1][1][0]);
	printf("%d ",cube[2][0][0]);
	printf("%d ",cube[2][1][0]);
	printf("%d ",cube[3][0][0]);
	printf("%d ",cube[3][1][0]);
	printf("%d ",cube[4][0][0]);
	printf("%d ",cube[4][1][0]);
	printf("\n");

	printf("%d ",cube[1][0][1]);
	printf("%d ",cube[1][1][1]);
	printf("%d ",cube[2][0][1]);
	printf("%d ",cube[2][1][1]);
	printf("%d ",cube[3][0][1]);
	printf("%d ",cube[3][1][1]);
	printf("%d ",cube[4][0][1]);
	printf("%d ",cube[4][1][1]);
	printf("\n    ");

	printf("%d ",cube[0][0][0]);
	printf("%d ",cube[0][1][0]);
	printf("        \n");
	printf("    ");
	printf("%d ",cube[0][0][1]);
	printf("%d ",cube[0][1][1]);
	printf("        \n");
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

void randTour(int cube[6][2][2]){
	//tire au sort un numero entre 0 et 5 et fait tourner le cube en fonction de celui-ci
	int RandNum = (rand() % (6));
	
	tourner(RandNum, cube);
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
//Prend un cube et un tableauSolution, et applique les rotations décrites dans le tableau au cube.
void AppliqueSolution(int cube[6][2][2], int tabSolution[14]){
	int i;
	for (i = 0; i < 14; i++)
	{
		if (tabSolution[i]!=-1)
		{
			tourner(tabSolution[i],cube);
		}
		
	}
	
		
}

int *BruteForce(int cube[6][2][2])
{
	clock_t start, end;
     double timeUsed;
     
     start = clock();
     
	
	
	int* tabSolution = malloc(14 * sizeof(int));
	
	int cubeParfait[6][2][2];
	init(cubeParfait);
	
	int cubecopie[6][2][2];
	copieCube(cube,cubecopie);

	int a = -1, b = -1, c = -1, d = -1, e = -1,
	    f = -1, g = -1, h = -1, i = -1, j = -1,
	    k = -1, l = -1, m = -1, n = -1;
	
	
	while (a <= 5)
	{
		tabSolution[0] = a;
		tabSolution[1] = b;
		tabSolution[2] = c;
		tabSolution[3] = d;
		tabSolution[4] = e;
		tabSolution[5] = f;
		tabSolution[6] = g;
		tabSolution[7] = h;
		tabSolution[8] = i;
		tabSolution[9] = j;
		tabSolution[10] = k;
		tabSolution[11] = l;
		tabSolution[12] = m;
		tabSolution[13] = n;
		AppliqueSolution(cubecopie, tabSolution);
		
		if (verifie(cubecopie) == 1)
		{	
			
			end = clock();
			timeUsed = ((double) (end - start)) / CLOCKS_PER_SEC;
			printf("temps mis pour déterminer la réponse en seconde : %f\n",timeUsed);
			return tabSolution;
		}
		
		copieCube(cube,cubecopie);
		
		
		if (a == 5)
		{
			if (b==5)
			{
				if (c==5)
				{	
					if (d==5)
					{	
						if (e==5)
						{	
							if (f==5)
							{	
								if (g==5)
								{	
									if (h==5)
									{	
										if (i==5)
										{	
											if (j==5)
											{	
												if (k==5)
												{	
													if (l==5)
													{	
														if (m==5)
														{	
															if (n==5)
															{	
																printf("AUCUNE SOLUTION");
																return tabSolution;
																n = 0;
																
															} else { n++; }		
															m = 0;
															
														} else { m++; }										
														l = 0;
														
													} else { l++; }	
													k = 0;
													
												} else { k++; }										
												j = 0;
												
											} else { j++; }										
											i = 0;
											
										} else { i++; }										
										h = 0;
										
									} else { h++; }										
									g = 0;
									
								} else { g++; }									
								f = 0;
								
							} else { f++; }									
							e = 0;
							
						} else { e++; }									
						d = 0;
						
					} else { d++; }									
					c = 0;
					
				} else { c++; }
				
				b = 0;
				
			} else { b++; }
			
			a = 0;
		} else { a++;  }
		
		
	}
	
}

//Prend un tableaux Solution (avec des 1,2,3,4,5 et -1) et affiche les cotés a tourner.
void printTabSolution(int tabSolution[14]){
	int i = 0, num = 0;
	printf("\n Une solution est: |");
	for (i = 0; i < 14; i++)
	{
		num = tabSolution[i];
		if(num != -1){
			if(num == 0){printf(" F|");}
			if(num == 1){printf(" C|");}
			if(num == 2){printf(" H|");}
			if(num == 3){printf("-C|");}
			if(num == 4){printf("-H|");}
			if(num == 5){printf("-F|");}
			
		}
	}
	printf("\n");
}




