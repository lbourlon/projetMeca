#include <stdio.h>
#include "fonctions.h"
// Résolution faite en començant par la face orange
#define WHITE   0
#define GREEN   1
#define ORANGE  2
#define BLUE    3
#define RED     4
#define YELLOW  5


typedef struct _coord coord;
struct _coord {
	int face;
	int x;
	int y;
};

typedef struct _milieu milieu;
struct _milieu {
	coord coord1;
	coord coord2;
};

typedef struct _coin coin;
struct _coin {
	coord coord1;
	coord coord2;
	coord coord3;
};


//Prend les coordonnées d'une case milieu et les remplie dans un milieu
//Abréviation de RemplirMilieu
milieu rm(int face1,int x1,int y1,int face2,int x2,int y2){
	milieu milieuVar;
	milieuVar.coord1.face = face1;
	milieuVar.coord1.x = x1;
	milieuVar.coord1.y = y1;
	milieuVar.coord2.face = face2; 
	milieuVar.coord2.x = x2;
	milieuVar.coord2.y = y2;
	
	return milieuVar;
}





//Recherce l'emplacement de la piece milieu contenant les couleurs 1 et 2
//Et retourne un objet milieu avec les coordonées respectives aux couleurs
//(l'ordre d'entrée est conserv)
milieu RechercherMilieu(int cube[6][3][3],milieu tab[12], int couleur1, int couleur2){
	
	for(int i = 0; i < 12; i++){
		
		
		if((cube[tab[i].coord1.face][tab[i].coord1.x][tab[i].coord1.y] == couleur1 &&
		   cube[tab[i].coord2.face][tab[i].coord2.x][tab[i].coord2.y] == couleur2))
		{
			return tab[i];
		}
			
		 
		if(cube[tab[i].coord1.face][tab[i].coord1.x][tab[i].coord1.y] == couleur2 &&
		   cube[tab[i].coord2.face][tab[i].coord2.x][tab[i].coord2.y] == couleur1)
		{
		 	milieu milSortie;
			milSortie.coord1 = tab[i].coord2;
			milSortie.coord2 = tab[i].coord1;
			
			return milSortie;
		 }
	}
	
	printf("vous vous êtes trompés de couleurs mêssier \n");
	return	rm(0,0,0,0,0,0);
}

void FaireCroixOrange(int cube[6][3][3],milieu tab[12])
{
	printf("ca marche cas  debut\n");

	milieu mil25, mil21, mil20, mil23;
	mil25 = RechercherMilieu(cube,tab,ORANGE, YELLOW);
	printf("ca marche rechercher milieu\n");
	char* cas = "";
	
	//Si cas FACE
	if(mil25.coord1.face == ORANGE){
		//cas parfait:
		if(mil25.coord1.face == YELLOW){
			cas = "parfait";
		} else {
		//cas imparfait --> cas dessous
			cas = "imparfait";
			tourner(mil25.coord2.face, cube);
			
			tourner(mil25.coord2.face, cube);
			
			
		}
	}
	
	mil25 = RechercherMilieu(cube,tab,ORANGE, YELLOW);

	printf("ca marche cas FACE\n");

	//Si cas CÔTÉ
	if (mil25.coord1.face != RED && mil25.coord1.face != ORANGE ){
		printf("azer\n");
		//cas haut:
		printf("azer2\n");
		if (mil25.coord2.face == ORANGE)
		{
			printf("wah\n");
			tourner(mil25.coord1.face, cube);
			printf("wah2\n");
			//devient un cas côté
			mil25 = RechercherMilieu(cube,tab,ORANGE, YELLOW);
			printf("a");

		}
		printf("b");
		//cas bas
		if(mil25.coord2.face == RED)
		{
			tourner(mil25.coord1.face, cube);
			//devient un cas côté
			mil25 = RechercherMilieu(cube,tab,ORANGE, YELLOW);
			printf("c");
		}
		printf("d");
		//cas côté

		//compteur de tour pour la face
		int n =0;
		int temp = mil25.coord1.face;
		while (mil25.coord1.face != RED)
		{
			tourner(temp,cube);
			n = n+1;
			
		}
		mil25 = RechercherMilieu(cube,tab,ORANGE, YELLOW);
		printf("e");
		tourner(RED,cube);
		tourner(RED,cube);

		while (n != 4)
		{
			tourner(temp,cube);
			n = n+1;
		}
		mil25 = RechercherMilieu(cube,tab,ORANGE, YELLOW);
		printf("f\n");
		//devient cas DESSOUS
		


		
			
	}
	mil25 = RechercherMilieu(cube,tab,ORANGE, YELLOW);
	printf("ca marche cas CÔTE\n");
	affiche(cube);
	//Si cas DESSOUS
	if (mil25.coord1.face == RED)
	{
		while (mil25.coord2.face != YELLOW)
		{
			tourner(RED, cube);
		}
		tourner(YELLOW, cube);
		tourner(YELLOW,cube);
	}
	printf("ca marchecas DESSOUS\n");

	
		
	
	
	//cas parfait si on a ça, alors on ne fait rien:
	/*if(mil25.coord1.face == ORANGE &&
		mil25.coord1.x == 1		    &&
		mil25.coord1.y == 0 		&&
		
		mil25.coord1.face == GREEN  &&
		mil25.coord1.x == 1		    &&
		mil25.coord1.y == 2)
	{
		cas = "parfait";
	} else{
		//cas face imparfaite
		
	
		
	}*/
}












