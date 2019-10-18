#include <stdio.h>
#include <stdlib.h>
#include <time.h>


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

void affiche(int cube[6][2][2]){
	printf("  ");
	printf("  ");
	printf("%d ",cube[5][0][0]);
	printf("%d ",cube[5][1][0]);
	printf("  ");
	printf("  ");
	printf("  ");
	printf("  ");
			printf("\n");
	printf("  ");
	printf("  ");
	printf("%d ",cube[5][0][1]);
	printf("%d ",cube[5][1][1]);
	printf("  ");
	printf("  ");
	printf("  ");
	printf("  ");
			printf("\n");
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
			printf("\n");
	printf("  ");
	printf("  ");
	printf("%d ",cube[0][0][0]);
	printf("%d ",cube[0][1][0]);
	printf("  ");
	printf("  ");
	printf("  ");
	printf("  ");
			printf("\n");
	printf("  ");
	printf("  ");
	printf("%d ",cube[0][0][1]);
	printf("%d ",cube[0][1][1]);
	printf("  ");
	printf("  ");
	printf("  ");
	printf("  ");
	printf("\n");
}

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


void melangeCube(int cube[6][2][2]){
	int i;
	for (i = 0; i < 20; i++)
	{
		randTour(cube);
	}
	
}

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

void copieCube(int CubeACopier[6][2][2], int CubeSortie[6][2][2])
/*Copie cube a dans cube b*/
{
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
	


int* BruteForce(int cube[6][2][2]){
	int* tabSortie = (int*)malloc(14 * sizeof(int));
	int cubeParfait[6][2][2];
	init(cubeParfait);
	
	int cubecopie[6][2][2];
	copieCube(cube,cubecopie);

	int a = 0,b = 0,c = 0,d = 0,e = 0,f = 0,g = 0,h = 0,i = 0,
		j = 0,k = 0,l = 0,m = 0,n = 0;
		
	while(a < 6)
	{
		tourner(a,cube);
		b = 0;
		while(b < 6)
		{
			tourner(b,cube);
			c = 0;
			while(c < 6)
			{
				tourner(c,cube);
				d = 0;
				while(d < 6)
				{
					tourner(d,cube);
					e = 0;
					while(e < 6)
					{
						tourner(e,cube);
						f = 0;
						while(f < 6)
						{
							tourner(f,cube);
							g = 0;
							while(g < 6)
							{
								tourner(g,cube);
								h = 0;
								while(h < 6)
								{
									tourner(h,cube);
									i = 0;
									while(i < 6)
									{
										tourner(i,cube);
										j = 0;
										while(j < 6)
										{
											tourner(j,cube);
											k = 0;
											while(k < 6)
											{
												tourner(k,cube);
												l = 0;
												while(l < 6)
												{
													tourner(l,cube);
													m = 0;
													while(m < 6)
													{
														tourner(m,cube);
														n = 0;
														while(n < 6)
														{
															tourner(n,cube);
															if(compare(cube, cubeParfait) == 1 )
															{
																printf("La solution la plus éfficace est : %d-%d-%d-%d-%d-%d-%d-%d-%d-%d-%d-%d-%d-%d\n",a,b,c,d,e,f,g,h,i,j,k,l,m,n);
																
																tabSortie[0] = n;
																tabSortie[1] = m;
																tabSortie[2] = l;
																tabSortie[3] = k;
																tabSortie[4] = j;
																tabSortie[5] = i;
																tabSortie[6] = h;
																tabSortie[7] = g;
																tabSortie[8] = f;
																tabSortie[9] = e;
																tabSortie[10] = d;
																tabSortie[11] = c;
																tabSortie[12] = b;
																tabSortie[13] = a;
																
																
																
																return tabSortie;
															}
															copieCube(cube,cubecopie);
															
															n = n+1;
														}
														m = m+1;
													}
													l = l+1;
												}
												k = k+1;
											}
											j = j+1;
										}
										i = i+1;
									}
									h = h+1;
								}
								g = g+1;
							}
							f = f+1;
						}
						e = e+1;
					}
					d = d+1;
				}
				c = c+1;
			}
			b = b+1;
		}
		a = a+1;
		printf("tour %d \n",a);
	}

	printf("désolé messiêr"); 
	//hello
	
}



