#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void init(int tab[6][2][2]){
	
	int k;
	for (k = 0; k <= 5; k++)
	{
		int i;
		for(i = 0; i<=1; i++)
		{
			int j;
			for (j = 0; j <= 1 ; j++)
			{
				tab[k][i][j] = k;
			}
			
		}
	}
	
}

void affiche(int tab[6][2][2]){
	printf("  ");
	printf("  ");
	printf("%d ",tab[5][0][0]);
	printf("%d ",tab[5][1][0]);
	printf("  ");
	printf("  ");
	printf("  ");
	printf("  ");
			printf("\n");
	printf("  ");
	printf("  ");
	printf("%d ",tab[5][0][1]);
	printf("%d ",tab[5][1][1]);
	printf("  ");
	printf("  ");
	printf("  ");
	printf("  ");
			printf("\n");
	printf("%d ",tab[1][0][0]);
	printf("%d ",tab[1][1][0]);
	printf("%d ",tab[2][0][0]);
	printf("%d ",tab[2][1][0]);
	printf("%d ",tab[3][0][0]);
	printf("%d ",tab[3][1][0]);
	printf("%d ",tab[4][0][0]);
	printf("%d ",tab[4][1][0]);
			printf("\n");
	printf("%d ",tab[1][0][1]);
	printf("%d ",tab[1][1][1]);
	printf("%d ",tab[2][0][1]);
	printf("%d ",tab[2][1][1]);
	printf("%d ",tab[3][0][1]);
	printf("%d ",tab[3][1][1]);
	printf("%d ",tab[4][0][1]);
	printf("%d ",tab[4][1][1]);
			printf("\n");
	printf("  ");
	printf("  ");
	printf("%d ",tab[0][0][0]);
	printf("%d ",tab[0][1][0]);
	printf("  ");
	printf("  ");
	printf("  ");
	printf("  ");
			printf("\n");
	printf("  ");
	printf("  ");
	printf("%d ",tab[0][0][1]);
	printf("%d ",tab[0][1][1]);
	printf("  ");
	printf("  ");
	printf("  ");
	printf("  ");
	printf("\n");
}

void tourner(int face, int tab[6][2][2]){
	switch(face)
	{
		int temp;
		int temp1;
		
		case 0:
			temp = tab[face][1][0];
			tab[face][1][0] = tab[face][0][0];
			tab[face][0][0] = tab[face][0][1];
			tab[face][0][1] = tab[face][1][1];
			tab[face][1][1] = temp;
			
			temp =  tab[4][0][1];
			temp1 = tab[4][1][1];
			
			int i;
			for (i = 4; i >= 2 ; i = i-1)
			{
				tab[i][0][1] = tab[i-1][0][1];
				tab[i][1][1] = tab[i-1][1][1];
			}
			
			tab[1][0][1] = temp;
			tab[1][1][1] = temp1;
			
			break;
			
		case 1:
			temp = tab[face][1][0];
			tab[face][1][0] = tab[face][0][0];
			tab[face][0][0] = tab[face][0][1];
			tab[face][0][1] = tab[face][1][1];
			tab[face][1][1] = temp;
			
			temp =  tab[4][1][0];
			temp1 = tab[4][1][1];
			
			tab[4][1][0] = tab[0][0][1];
			tab[4][1][1] = tab[0][0][0];
			
			tab[0][0][1] = tab[2][0][1];
			tab[0][0][0] = tab[2][0][0];
			
			tab[2][0][1] = tab[5][0][1];
			tab[2][0][0] = tab[5][0][0];
			
			tab[5][0][1] = temp;
			tab[5][0][0] = temp1;
			
			break;
			
		case 2:
			temp = tab[face][1][0];
			tab[face][1][0] = tab[face][0][0];
			tab[face][0][0] = tab[face][0][1];
			tab[face][0][1] = tab[face][1][1];
			tab[face][1][1] = temp;
			
			temp =  tab[0][0][0];
			temp1 = tab[0][1][0];
			
			tab[0][0][0] = tab[3][0][1];
			tab[0][1][0] = tab[3][0][0];
			
			tab[3][0][1] = tab[5][1][1];
			tab[3][0][0] = tab[5][0][1];
			
			tab[5][1][1] = tab[1][1][0]; 
			tab[5][0][1] = tab[1][1][1];
			
			tab[1][1][0] = temp;
			tab[1][1][1] = temp1;
			
			break;
		
		case 3: 
			//Equivalent de 3x le côté 2
			tourner(1,tab);
			tourner(1,tab);
			tourner(1,tab);
			
			break;
			
		case 4: 
			//Equivalent de 3x le côté 2
			tourner(2,tab);
			tourner(2,tab);
			tourner(2,tab);
			
			break;
		
		case 5:
			//Équivalet de 3x le côté 0
			tourner(0,tab);
			tourner(0,tab);
			tourner(0,tab);
			
			break;
			
		
			
		}		
	
	
}

void randTour(int tab[6][2][2]){
	//tire au sort un numero entre 0 et 5 et fait tourner le cube en fonction de celui-ci
	int RandNum = (rand() % (6));
	tourner(RandNum, tab);
}


void melangeCube(int tab[6][2][2]){
	int i;
	for (i = 0; i < 20; i++)
	{
		randTour(tab);
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

void BruteForce(int tab[6][2][2]){
	int cubeParfait[6][2][2];
	init(cubeParfait);
	
	int a = 0,b = 0,c = 0,d = 0,e = 0,f = 0,g = 0,h = 0,i = 0,
		j = 0,k = 0,l = 0,m = 0,n = 0;
		
	while(a < 6)
	{
	tourner(a,tab);
		while(b < 6)
		{
		tourner(b,tab);
			while(c < 6)
			{
			tourner(c,tab);
				while(d < 6)
				{
				tourner(d,tab);
					while(e < 6)
					{
					tourner(e,tab);
						while(f < 6)
						{
						tourner(f,tab);
							while(g < 6)
							{
							tourner(g,tab);
								while(h < 6)
								{
								tourner(h,tab);
									while(i < 6)
									{
									tourner(i,tab);
										while(j < 6)
										{
										tourner(j,tab);
											while(k < 6)
											{
											tourner(k,tab);
												while(l < 6)
												{
												tourner(l,tab);
													while(m < 6)
													{
													tourner(m,tab);
														while(n < 6)
														{
														tourner(n,tab);
														if(compare(tab,cubeParfait)==1)
															{printf("\n\n%d-%d-%d-%d-%d-%d-%d-%d-%d-%d-%d-%d-%d-%d\n\n",a,b,c,d,e,f,g,h,i,j,k,l,m,n);}
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
	}
	printf("désolé messiêr");
	
}



