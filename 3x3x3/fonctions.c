
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void affiche(int cube[6][3][3]){
	printf("  ");
	printf("  ");
	printf("  ");
	printf("%d ",cube[5][0][0]);
	printf("%d ",cube[5][1][0]);
	printf("%d ",cube[5][2][0]);
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
	printf("%d ",cube[5][0][1]);
	printf("%d ",cube[5][1][1]);
	printf("%d ",cube[5][2][1]);
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
	printf("%d ",cube[5][0][2]);
	printf("%d ",cube[5][1][2]);
	printf("%d ",cube[5][2][2]);
	printf("  ");
	printf("  ");
	printf("  ");
	printf("  ");
	printf("  ");
	printf("  ");
			printf("\n");
	printf("%d ",cube[1][0][0]);
	printf("%d ",cube[1][1][0]);
	printf("%d ",cube[1][2][0]);
	printf("%d ",cube[2][0][0]);
	printf("%d ",cube[2][1][0]);
	printf("%d ",cube[2][2][0]);
	printf("%d ",cube[3][0][0]);
	printf("%d ",cube[3][1][0]);
	printf("%d ",cube[3][2][0]);
	printf("%d ",cube[4][0][0]);
	printf("%d ",cube[4][1][0]);
	printf("%d ",cube[4][2][0]);
			printf("\n");
	printf("%d ",cube[1][0][1]);
	printf("%d ",cube[1][1][1]);
	printf("%d ",cube[1][2][1]);
	printf("%d ",cube[2][0][1]);
	printf("%d ",cube[2][1][1]);
	printf("%d ",cube[2][2][1]);
	printf("%d ",cube[3][0][1]);
	printf("%d ",cube[3][1][1]);
	printf("%d ",cube[3][2][1]);
	printf("%d ",cube[4][0][1]);
	printf("%d ",cube[4][1][1]);
	printf("%d ",cube[4][2][1]);
			printf("\n");
	printf("%d ",cube[1][0][2]);
	printf("%d ",cube[1][1][2]);
	printf("%d ",cube[1][2][2]);
	printf("%d ",cube[2][0][2]);
	printf("%d ",cube[2][1][2]);
	printf("%d ",cube[2][2][2]);
	printf("%d ",cube[3][0][2]);
	printf("%d ",cube[3][1][2]);
	printf("%d ",cube[3][2][2]);
	printf("%d ",cube[4][0][2]);
	printf("%d ",cube[4][1][2]);
	printf("%d ",cube[4][2][2]);
				printf("\n");
	printf("  ");
	printf("  ");
	printf("  ");
	printf("%d ",cube[0][0][0]);
	printf("%d ",cube[0][1][0]);
	printf("%d ",cube[0][2][0]);
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
void tourner(int face, int cube[6][3][3]){
		
		void tourneInter(int face, int cube[6][3][3]){
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
		}
		
		//SENS HORAIRE MESSIER!
	
		int temp0;
		int temp1;
		int temp2;
		
		
		switch(face){
			case 1:
				tourneInter(face,cube);
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
				tourneInter(face,cube);
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
		}


}





void randTour(int cube[6][3][3]){
	//tire au sort un numero entre 0 et 5 et fait tourner le cube en fonction de celui-ci
	int RandNum = (rand() % (6));
	tourner(RandNum, cube);
}


void melangeCube(int cube[6][3][3]){
	int i;
	for (i = 0; i < 20; i++)
	{
		randTour(cube);
	}
	
}
