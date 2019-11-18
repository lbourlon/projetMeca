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

//Recherche l'emplacement de la piece milieu contenant les couleurs 1 et 2
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

//retourne le cas dans lequel est situé le milieu passé en paramètre pour faire la croix orange
char* TrouveCasMilieu(int cube[6][3][3], milieu mil)
{

	
	char* cas;
	//=====================Si cas FACE=====================
	if(mil.coord1.face == ORANGE){
		//cas parfait:
		if(mil.coord2.face == cube[mil.coord2.face][mil.coord2.x][mil.coord2.y]){
			cas = "parfait";
		} else {
		//cas imparfait --> cas dessous
			cas = "imparfait";	
		}
	}
	
	
	
	//=====================Si cas CÔTE=====================
	if (mil.coord1.face != RED && mil.coord1.face != ORANGE ){
		//cas haut:
		if (mil.coord2.face == ORANGE)
		{
			cas = "cote_haut";

		}
		
		//cas bas
		else  if(mil.coord2.face == RED)
		{
			cas = "cote_bas";
		}
	
		//cas côté
		else
		{
			cas = "cote_cote";
		}
	}
	
	
	
	//=====================Si cas DESSOUS=====================
	if (mil.coord1.face == RED)
	{
		if(mil.coord2.face == cube[mil.coord2.face][mil.coord2.x][mil.coord2.y])
		{
			cas = "dessous_parfait";
		}
		else
		{
			cas = "dessous_imparfait";
		}
		
	}
	//printf("le cas est %s",cas);
	return cas;
}


void FaireBrasCroix(int cube[6][3][3],milieu mil, milieu tabMilieux[12]){
	char* cas;
	cas = TrouveCasMilieu(cube, mil);
	int couleur2 = cube[mil.coord2.face][mil.coord2.x][mil.coord2.y];
	
	
	while(cas != "parfait")
	{
		if(cas == "imparfait")
		{
			printf("%s\n", cas);
			tourner(mil.coord2.face, cube);
			tourner(mil.coord2.face, cube);
		}
		
		if(cas == "cote_haut")
		{
			printf("%s\n", cas);
			tourner(mil.coord1.face, cube);
		}
		
		if(cas == "cote_bas")
		{
			printf("%s\n", cas);
			//Regarder si la pièce en haut est déjà bien placée
			if(TrouveCasMilieu(cube, RechercherMilieu(cube, tabMilieux, ORANGE, mil.coord1.face)) == "parfait")
			{
				tourner(RED, cube);
			} else {
				tourner(mil.coord1.face,cube);
			}
		}
		
		
		if(cas == "cote_cote")
		{
			printf("%s\n", cas);
			tourner(mil.coord2.face, cube);
			
			mil = RechercherMilieu(cube,tabMilieux,ORANGE, couleur2);
			//
			//
			
			if(TrouveCasMilieu(cube, RechercherMilieu(cube, tabMilieux, cube[mil.coord1.face][mil.coord1.x][mil.coord1.y], cube[mil.coord2.face][mil.coord2.x][mil.coord2.y])) == "dessous_imparfait" ||
			   TrouveCasMilieu(cube, RechercherMilieu(cube, tabMilieux, cube[mil.coord1.face][mil.coord1.x][mil.coord1.y], cube[mil.coord2.face][mil.coord2.x][mil.coord2.y])) == "dessous_parfait")
			{
				
			if(TrouveCasMilieu(cube, RechercherMilieu(cube, tabMilieux, cube[mil.coord1.face][mil.coord1.x][mil.coord1.y], cube[mil.coord2.face][mil.coord2.x][mil.coord2.y])) == "dessous_parfait"){printf("BEllowwellow\n");}
				tourner(RED, cube);
				tourner(mil.coord2.face, cube);
				tourner(mil.coord2.face, cube);
				tourner(mil.coord2.face, cube);
			} else {
				
			if(TrouveCasMilieu(cube, RechercherMilieu(cube, tabMilieux, cube[mil.coord1.face][mil.coord1.x][mil.coord1.y], cube[mil.coord2.face][mil.coord2.x][mil.coord2.y])) == "dessous_parfait"){printf("BEllowwellow\n");}
				tourner(mil.coord2.face, cube);
				tourner(mil.coord2.face, cube);
				tourner(RED, cube);
				tourner(mil.coord2.face, cube);
			}
			
		}
		if(cas == "dessous_imparfait")
		{
			printf("%s\n", cas);
			tourner(RED, cube);
		}
		
		
		if(cas == "dessous_parfait")
		{
			printf("%s\n", cas);
			tourner(mil.coord2.face, cube);
			tourner(mil.coord2.face, cube);
		}
		
		
	
	mil = RechercherMilieu(cube,tabMilieux,ORANGE, couleur2);
	cas = TrouveCasMilieu(cube, mil);
	
	}	
	
	printf("===================FIN DU BRAS================\n");
}


void FaireCroixOrange(int cube[6][3][3],milieu tabMilieux[12])
{
	
	

	
	
	//printf("le milieu a pour coordonné %d , %d ,%d ,%d ,%d ,%d \n",mil21.coord1.face, mil21.coord1.x,mil21.coord1.y,mil21.coord2.face, mil21.coord2.x, mil21.coord2.y);
	milieu mil25, mil21, mil20, mil23;
	mil25 = RechercherMilieu(cube,tabMilieux, ORANGE, YELLOW);
	FaireBrasCroix(cube, mil25, tabMilieux);
	mil21 = RechercherMilieu(cube,tabMilieux, ORANGE, GREEN);
	FaireBrasCroix(cube, mil21, tabMilieux);
	mil20 = RechercherMilieu(cube,tabMilieux, ORANGE, WHITE);
	FaireBrasCroix(cube, mil20, tabMilieux);
	mil23 = RechercherMilieu(cube,tabMilieux, ORANGE, BLUE);
	FaireBrasCroix(cube, mil23, tabMilieux);

	
	
		
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------

//Prend les coordonnées d'une case coin et les remplie dans un coin
//Abréviation de RemplirCoin
coin rc(int face1,int x1,int y1,int face2,int x2,int y2, int face3, int x3, int y3){
	coin coinVar;
	coinVar.coord1.face = face1;
	coinVar.coord1.x = x1;
	coinVar.coord1.y = y1;
	coinVar.coord2.face = face2; 
	coinVar.coord2.x = x2;
	coinVar.coord2.y = y2;
	coinVar.coord3.face = face3;
	coinVar.coord3.x = x3;
	coinVar.coord3.y = y3;
	
	return coinVar;
}


//Recherche l'emplacement de la piece coin contenant les couleurs 1 et 2 et 3
//Et retourne un objet coin avec les coordonées respectives aux couleurs
//(l'ordre d'entrée est conserv)
coin RechercherCoin(int cube[6][3][3],coin tab[8], int couleurimportante, int couleur2, int couleur3){
	for(int i = 0; i < 8; i++){
		
		coin coinSortie;
		
		if((cube[tab[i].coord1.face][tab[i].coord1.x][tab[i].coord1.y] == couleurimportante &&
		   cube[tab[i].coord2.face][tab[i].coord2.x][tab[i].coord2.y] == couleur2 &&
		   cube[tab[i].coord3.face][tab[i].coord3.x][tab[i].coord3.y] == couleur3) ||
		   (cube[tab[i].coord1.face][tab[i].coord1.x][tab[i].coord1.y] == couleurimportante &&
		   cube[tab[i].coord2.face][tab[i].coord2.x][tab[i].coord2.y] == couleur3 &&
		   cube[tab[i].coord3.face][tab[i].coord3.x][tab[i].coord3.y] == couleur2))
		{
			return tab[i];
		}
		
		if((cube[tab[i].coord1.face][tab[i].coord1.x][tab[i].coord1.y] == couleur2 &&
		   cube[tab[i].coord2.face][tab[i].coord2.x][tab[i].coord2.y] == couleurimportante &&
		   cube[tab[i].coord3.face][tab[i].coord3.x][tab[i].coord3.y] == couleur3) ||
		   (cube[tab[i].coord1.face][tab[i].coord1.x][tab[i].coord1.y] == couleur3 &&
		   cube[tab[i].coord2.face][tab[i].coord2.x][tab[i].coord2.y] == couleurimportante &&
		   cube[tab[i].coord3.face][tab[i].coord3.x][tab[i].coord3.y] == couleur2))
		{
			
			coinSortie.coord1 = tab[i].coord2;
			coinSortie.coord2 = tab[i].coord1;
			coinSortie.coord3 = tab[i].coord3;
		}
		
		if((cube[tab[i].coord1.face][tab[i].coord1.x][tab[i].coord1.y] == couleur2 &&
		   cube[tab[i].coord2.face][tab[i].coord2.x][tab[i].coord2.y] == couleur3 &&
		   cube[tab[i].coord3.face][tab[i].coord3.x][tab[i].coord3.y] == couleurimportante) ||
		   (cube[tab[i].coord1.face][tab[i].coord1.x][tab[i].coord1.y] == couleur3 &&
		   cube[tab[i].coord2.face][tab[i].coord2.x][tab[i].coord2.y] == couleur2 &&
		   cube[tab[i].coord3.face][tab[i].coord3.x][tab[i].coord3.y] == couleurimportante))
		{
			
			
			coinSortie.coord1 = tab[i].coord3;
			coinSortie.coord2 = tab[i].coord1;
			coinSortie.coord3 = tab[i].coord2;
		}
			
		 return coinSortie;
		
	}
	
	printf("vous vous êtes trompés de couleurs mêssier \n");
	return	rc(0,0,0,0,0,0,0,0,0);
}


//retourne le cas dans lequel est situé le coin passé en paramètre pour faire les coins de la croix orange
char* TrouveCasCoin(int cube[6][3][3], coin co)
{
	char* cas;
	//=====================Si cas FACE=====================
	if(co.coord1.face == ORANGE){
		//cas parfait:

		printf("coucou\n");
		if(co.coord2.face == cube[co.coord2.face][co.coord2.x][co.coord2.y]
			&& co.coord3.face == cube[co.coord3.face][co.coord3.x][co.coord3.y]){
			cas = "parfait";
			return cas;
		} else {
		//cas imparfait --> cas dessous
			cas = "imparfait";	
		}
	}
	
	
	
	//=====================Si cas CÔTE=====================
	if (co.coord1.face != RED && co.coord1.face != ORANGE ){
		
		//cas haut:
		if (co.coord2.face == ORANGE || co.coord3.face == ORANGE)
		{
			cas = "cote_haut";

		}
		
		//cas bas
		else if(co.coord2.face == RED || co.coord3.face == RED)
		{
			if(co.coord2.face == cube[co.coord2.face][co.coord2.x][co.coord2.y]
			&& co.coord3.face == cube[co.coord1.face][co.coord1.x][co.coord1.y]
			|| co.coord3.face == cube[co.coord3.face][co.coord3.x][co.coord3.y]
			&& co.coord2.face == cube[co.coord1.face][co.coord1.x][co.coord1.y]){
				cas = "cote_bas_parfait";
			}
			else{cas = "cote_bas";}
		}
	
	}
	
	
	
	//=====================Si cas DESSOUS=====================
	if (co.coord1.face == RED)
	{
		cas = "dessous";	
	}
	
	printf("\nle cas est %s\n",cas);
	return cas;
}

