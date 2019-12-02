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

typedef struct _coin coin;
struct _coin {
	coord coord1;
	coord coord2;
	coord coord3;
};

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
//(l'ordre d'entrée n'est pas conserv)
coin RechercherCoin(int cube[6][2][2],coin tab[8], int couleur1, int couleur2, int couleur3){
	for(int i = 0; i < 8; i++){
		
		//Couleur 1 en tête
		if((cube[tab[i].coord1.face][tab[i].coord1.x][tab[i].coord1.y] == couleur1 &&
		    cube[tab[i].coord2.face][tab[i].coord2.x][tab[i].coord2.y] == couleur2 &&
		    cube[tab[i].coord3.face][tab[i].coord3.x][tab[i].coord3.y] == couleur3))
		{
			return tab[i];
		}
		
		if((cube[tab[i].coord1.face][tab[i].coord1.x][tab[i].coord1.y] == couleur1 &&
		    cube[tab[i].coord2.face][tab[i].coord2.x][tab[i].coord2.y] == couleur3 &&
		    cube[tab[i].coord3.face][tab[i].coord3.x][tab[i].coord3.y] == couleur2))
		{
			return tab[i];
		}
		
		
		//couleur 1 au milieu
		if((cube[tab[i].coord1.face][tab[i].coord1.x][tab[i].coord1.y] == couleur2 &&
		    cube[tab[i].coord2.face][tab[i].coord2.x][tab[i].coord2.y] == couleur1 &&
		    cube[tab[i].coord3.face][tab[i].coord3.x][tab[i].coord3.y] == couleur3))
		{
			coin coinSortie;
			coinSortie.coord1 = tab[i].coord2;
			coinSortie.coord2 = tab[i].coord1;
			coinSortie.coord3 = tab[i].coord3;
			
			return coinSortie;
		}
		
		if((cube[tab[i].coord1.face][tab[i].coord1.x][tab[i].coord1.y] == couleur3 &&
		    cube[tab[i].coord2.face][tab[i].coord2.x][tab[i].coord2.y] == couleur1 &&
		    cube[tab[i].coord3.face][tab[i].coord3.x][tab[i].coord3.y] == couleur2))
		{
			coin coinSortie;
			coinSortie.coord1 = tab[i].coord2;
			coinSortie.coord2 = tab[i].coord1;
			coinSortie.coord3 = tab[i].coord3;
			
			return coinSortie;
		}
		
		
		//couleur 1 en fin
		if((cube[tab[i].coord1.face][tab[i].coord1.x][tab[i].coord1.y] == couleur3 &&
		    cube[tab[i].coord2.face][tab[i].coord2.x][tab[i].coord2.y] == couleur2 &&
		    cube[tab[i].coord3.face][tab[i].coord3.x][tab[i].coord3.y] == couleur1))
		{
			coin coinSortie;
			coinSortie.coord1 = tab[i].coord3;
			coinSortie.coord2 = tab[i].coord1;
			coinSortie.coord3 = tab[i].coord2;
			
			return coinSortie;
		}
		
		if((cube[tab[i].coord1.face][tab[i].coord1.x][tab[i].coord1.y] == couleur2 &&
		    cube[tab[i].coord2.face][tab[i].coord2.x][tab[i].coord2.y] == couleur3 &&
		    cube[tab[i].coord3.face][tab[i].coord3.x][tab[i].coord3.y] == couleur1))
		{
			coin coinSortie;
			coinSortie.coord1 = tab[i].coord3;
			coinSortie.coord2 = tab[i].coord1;
			coinSortie.coord3 = tab[i].coord2;
			
			return coinSortie;
		}
		
		
		
	}
	
	printf("vous vous êtes trompés de couleurs mêssier \n");
	return	rc(0,0,0,0,0,0,0,0,0);
}

//retourne le cas dans lequel est situé le coin passé en paramètre pour faire les coins de la croix orange
char* TrouveCasCoin(int cube[6][2][2], coin co){
	char* cas;
	//=====================Si cas FACE=====================
	if(co.coord1.face == ORANGE){
		//cas parfait:

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
			if((co.coord2.face == cube[co.coord2.face][co.coord2.x][co.coord2.y]
			&& co.coord1.face == cube[co.coord3.face][co.coord3.x][co.coord3.y])
			|| (co.coord3.face == cube[co.coord3.face][co.coord3.x][co.coord3.y]
			&& co.coord1.face == cube[co.coord2.face][co.coord2.x][co.coord2.y])){
				cas = "cote_bas_parfait";
			}
			else{cas = "cote_bas_imparfait";}
		}
	
	}
	
	
	
	//=====================Si cas DESSOUS=====================
	if (co.coord1.face == RED)
	{
		cas = "dessous";	
	}
	

	return cas;
}

//place le coin co dans son bon emplacement.
void FaireCoinOrange(int cube[6][2][2],coin co, coin tabCoins[8]){
	char* cas;
	cas = TrouveCasCoin(cube, co);
	int couleur2 = cube[co.coord2.face][co.coord2.x][co.coord2.y];
	int couleur3 = cube[co.coord3.face][co.coord3.x][co.coord3.y];
	
	coin coTemp;
	char* casTemp;
	
	coin coTemp2;
	char* casTemp2;
	
	
	while(cas != "parfait")
	{
		//devient côté_bas
		if(cas == "imparfait")
		{

			mtourner(co.coord2.face, cube);
			coTemp = RechercherCoin(cube, tabCoins, ORANGE, couleur2, couleur3);
			casTemp = TrouveCasCoin(cube, coTemp);
			if(casTemp == "cote_bas_imparfait"){
				mtourner(RED, cube);
				mtourner(RED, cube);
				mtourner(co.coord2.face, cube);
				mtourner(co.coord2.face, cube);
				mtourner(co.coord2.face, cube);
				
			} else {
				mtourner(co.coord2.face, cube);
				mtourner(co.coord2.face, cube);
				mtourner(RED, cube);
				mtourner(RED, cube);
				mtourner(co.coord2.face, cube);
				
			}
		
		
		}
		
	
		//devient coté_bas
		if(cas == "cote_haut")
		{

			mtourner(co.coord1.face, cube);
			coTemp = RechercherCoin(cube, tabCoins, ORANGE, couleur2, couleur3);
			casTemp = TrouveCasCoin(cube, coTemp);
			if(casTemp == "cote_bas_imparfait" ||  casTemp == "cote_bas_parfait" ){
				mtourner(RED, cube);
				mtourner(RED, cube);
				mtourner(co.coord1.face, cube);
				mtourner(co.coord1.face, cube);
				mtourner(co.coord1.face, cube);
				
			} else {
				mtourner(co.coord1.face, cube);
				mtourner(co.coord1.face, cube);
				mtourner(RED, cube);
				mtourner(RED, cube);
				mtourner(co.coord1.face, cube);
			}
		}
		
		//cas dessous parfait ou imparfait
		//devient coté_bas
		if(cas == "dessous")
		{

			if((co.coord2.face == couleur2 && co.coord3.face == couleur3) ||
				(co.coord2.face == couleur3 && co.coord3.face == couleur2))
			{
				mtourner(co.coord2.face, cube);
				coTemp = RechercherCoin(cube, tabCoins, ORANGE, couleur2, couleur3);
				casTemp = TrouveCasCoin(cube, coTemp);
				if(casTemp == "cote_bas_imparfait"){
					mtourner(RED, cube);
					mtourner(RED, cube);
					mtourner(co.coord2.face, cube);
					mtourner(co.coord2.face, cube);
					mtourner(co.coord2.face, cube);
				} else {
					mtourner(co.coord2.face, cube);
					mtourner(co.coord2.face, cube);
					mtourner(RED, cube);
					mtourner(RED, cube);
					mtourner(co.coord2.face, cube);
				}
				
			} else {
				mtourner(RED, cube);
			}
			
			
		}
		
		//devient coté_bas_parfait
		if(cas == "cote_bas_imparfait")
		{

			coTemp = RechercherCoin(cube, tabCoins, ORANGE, couleur2, couleur3);
			casTemp = TrouveCasCoin(cube, coTemp);
			while (casTemp != "cote_bas_parfait")
			{
				mtourner(RED, cube);
				coTemp = RechercherCoin(cube, tabCoins, ORANGE, couleur2, couleur3);
				casTemp = TrouveCasCoin(cube, coTemp);

				affiche(cube);
				
			}
			

		}
		
		if(cas == "cote_bas_parfait")
		{
			mtourner(co.coord1.face, cube);
			coTemp = RechercherCoin(cube, tabCoins, ORANGE, couleur2, couleur3);
			casTemp = TrouveCasCoin(cube, coTemp);
			
			if(casTemp == "cote_bas_imparfait"){
				mtourner(RED, cube);
				coTemp2 = RechercherCoin(cube, tabCoins, ORANGE, couleur2, couleur3);
				casTemp2 = TrouveCasCoin(cube, coTemp2);
				if(casTemp2 != "cote_bas_parfait"){
					mtourner(RED, cube);
					mtourner(RED, cube);
				}
				
				mtourner(co.coord1.face, cube);
				mtourner(co.coord1.face, cube);
				mtourner(co.coord1.face, cube);
				
				 
			} else {
				mtourner(co.coord1.face, cube);
				mtourner(co.coord1.face, cube);
				
				coTemp2 = RechercherCoin(cube, tabCoins, ORANGE, couleur2, couleur3);
				casTemp2 = TrouveCasCoin(cube, coTemp2);
				while(casTemp2 != "cote_bas_parfait"){
					mtourner(RED, cube);
					coTemp2 = RechercherCoin(cube, tabCoins, ORANGE, couleur2, couleur3);
					casTemp2 = TrouveCasCoin(cube, coTemp2);
				}
				
				mtourner(co.coord1.face, cube);
				
			}
			
		}
		
	co = RechercherCoin(cube,tabCoins,ORANGE, couleur2, couleur3);
	cas = TrouveCasCoin(cube, co);
	affiche(cube);
	}
	printf("===================FIN DU COIN================\n");

}

//appelle FaireCoinOrange, pour résouder les quatre coins manquants de la face orange
void FaireFaceOrange(int cube[6][2][2], coin tabCoins[8]){
	coin co210, co215, co253, co230;
	
	co210 = RechercherCoin(cube, tabCoins, 2, 1, 0);
	FaireCoinOrange(cube, co210, tabCoins);

	co215 = RechercherCoin(cube, tabCoins, 2, 1, 5);
	FaireCoinOrange(cube, co215, tabCoins);
	
	co253 = RechercherCoin(cube, tabCoins, 2, 5, 3);
	FaireCoinOrange(cube, co253, tabCoins);
	
	co230 = RechercherCoin(cube, tabCoins, 2, 3, 0);
	FaireCoinOrange(cube, co230, tabCoins);
}


void MiseEnPlaceCoinRouge(int cube[6][2][2])
{
	
	mtourner(GREEN, cube);
	mtourner(RED, cube);

	mtourner(GREEN, cube);
	mtourner(GREEN, cube);
	mtourner(GREEN, cube);

	mtourner(RED, cube);

	mtourner(GREEN, cube);

	mtourner(RED, cube);
	mtourner(RED, cube);

	mtourner(GREEN, cube);
	mtourner(GREEN, cube);
	mtourner(GREEN, cube);

}


void FaireCoinsRouge(int cube[6][2][2])
{
	while(cube[4][0][0] != RED || cube[4][1][0] != RED || cube[4][0][1] != RED || cube[4][1][1] != RED)
		{
		//cas pas de coins
		if(cube[4][0][0] != RED && cube[4][1][0] != RED && cube[4][0][1] != RED && cube[4][1][1] != RED)
		{
			printf("cas pasdecoins\n");
			MiseEnPlaceCoinRouge(cube);
		}

		//cas 2 coins opposés parfait
		if(cube[4][0][0] == RED && cube[4][1][1] == RED )
		{
			printf("cas 2coinsopposés1\n");
			MiseEnPlaceCoinRouge(cube);
		}

		//cas 2 coins opposés imparfait
		if(cube[4][0][1] == RED && cube[4][1][0] == RED )
		{
			printf("cas 2coinsopposés2\n");
			tourner(RED, cube);
			MiseEnPlaceCoinRouge(cube);
		}

		//cas 2 coins alignés
		if((cube[4][0][0] == RED && cube[4][1][0] == RED) ||
			(cube[4][1][0] == RED && cube[4][1][1] == RED) ||
			(cube[4][1][1] == RED && cube[4][0][1] == RED) ||
			(cube[4][0][1] == RED && cube[4][0][0] == RED))
			{
				printf("cas 2coinsopposés\n");
				while(cube[4][1][1] != RED && cube[4][0][1] != RED)
				{
					mtourner(RED, cube);
				}
				MiseEnPlaceCoinRouge(cube);
			}

		//cas 1 seul coin
		if((cube[4][0][0] == RED && cube[4][1][0] != RED && cube[4][0][1] != RED && cube[4][1][1] != RED) ||
			(cube[4][0][0] != RED && cube[4][1][0] == RED && cube[4][0][1] != RED && cube[4][1][1] != RED) ||
			(cube[4][0][0] != RED && cube[4][1][0] != RED && cube[4][0][1] == RED && cube[4][1][1] != RED) ||
			(cube[4][0][0] != RED && cube[4][1][0] != RED && cube[4][0][1] != RED && cube[4][1][1] == RED))
		
		{
			while(cube[4][0][1] != RED)
			{
				printf("cas 1seulcoin\n");
				affiche(cube);
				mtourner(RED,cube);
			}
			MiseEnPlaceCoinRouge(cube);
		}
		//else{printf("pbm\n"); affiche(cube);}
	}
}

void MiseEnPlaceCoinsFinal(int cube[6][2][2])
{
	mtourner(GREEN, cube);
	mtourner(GREEN, cube);
	mtourner(GREEN, cube);

	mtourner(WHITE, cube);

	mtourner(GREEN, cube);
	mtourner(GREEN, cube);
	mtourner(GREEN, cube);

	mtourner(YELLOW, cube);
	mtourner(YELLOW, cube);

	mtourner(GREEN, cube);

	mtourner(WHITE, cube);
	mtourner(WHITE, cube);
	mtourner(WHITE, cube);

	mtourner(GREEN, cube);
	mtourner(GREEN, cube);
	mtourner(GREEN, cube);

	mtourner(YELLOW, cube);
	mtourner(YELLOW, cube);

	mtourner(GREEN, cube);
	mtourner(GREEN, cube);
}

void FaireCoinsFinal(int cube[6][2][2])
{
	while(cube[3][1][1] != cube[3][1][0] || cube[5][1][0] != cube[5][0][0] || cube[1][0][0] != cube[1][0][1] || cube[0][0][1] != cube[0][1][1])
	{
		//cas 2coins bien cote a cote
		int i = 0;
		while((cube[5][0][0] != cube[5][1][0]) && i <= 3)
		{
			mtourner(RED, cube);
			i = i + 1;
		}
	
		printf("cas2cote\n");
		affiche(cube);
		MiseEnPlaceCoinsFinal(cube);
	
		//printf("cas 1 coin\n");
		//MiseEnPlaceCoinsFinal(cube);
		
		printf("fin de boucle\n");
		affiche(cube);
	}
	printf("sortie de boucle\n");
	affiche(cube);
	while(cube[3][1][1] != cube[3][0][0])
	{
		printf("dans la dernière boucle\n");
		mtourner(RED, cube);
		affiche(cube);
	}
}