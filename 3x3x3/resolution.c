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
//(l'ordre d'entrée n'est pas conserv)
coin RechercherCoin(int cube[6][3][3],coin tab[8], int couleur1, int couleur2, int couleur3){
	
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
char* TrouveCasCoin(int cube[6][3][3], coin co)
{
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
	
	//printf("\nle cas est %s\n",cas);
	return cas;
}


void FaireCoinOrange(int cube[6][3][3],coin co, coin tabCoins[8]){
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
			printf("%s\n", cas);
			tourner(co.coord2.face, cube);
			coTemp = RechercherCoin(cube, tabCoins, ORANGE, couleur2, couleur3);
			casTemp = TrouveCasCoin(cube, coTemp);
			if(casTemp == "cote_bas_imparfait"){
				tourner(RED, cube);
				tourner(RED, cube);
				tourner(co.coord2.face, cube);
				tourner(co.coord2.face, cube);
				tourner(co.coord2.face, cube);
				
			} else {
				tourner(co.coord2.face, cube);
				tourner(co.coord2.face, cube);
				tourner(RED, cube);
				tourner(RED, cube);
				tourner(co.coord2.face, cube);
				
			}
		
		
		}
		
	
		//devient coté_bas
		if(cas == "cote_haut")
		{
			printf("%s\n", cas);
			tourner(co.coord1.face, cube);
			coTemp = RechercherCoin(cube, tabCoins, ORANGE, couleur2, couleur3);
			casTemp = TrouveCasCoin(cube, coTemp);
			if(casTemp == "cote_bas_imparfait" ||  casTemp == "cote_bas_parfait" ){
				tourner(RED, cube);
				tourner(RED, cube);
				tourner(co.coord1.face, cube);
				tourner(co.coord1.face, cube);
				tourner(co.coord1.face, cube);
				
			} else {
				tourner(co.coord1.face, cube);
				tourner(co.coord1.face, cube);
				tourner(RED, cube);
				tourner(RED, cube);
				tourner(co.coord1.face, cube);
			}
		}
		
		//cas dessous parfait ou imparfait
		//devient coté_bas
		if(cas == "dessous")
		{
			printf("%s\n", cas);
			if((co.coord2.face == couleur2 && co.coord3.face == couleur3) ||
				(co.coord2.face == couleur3 && co.coord3.face == couleur2))
			{
				tourner(co.coord2.face, cube);
				coTemp = RechercherCoin(cube, tabCoins, ORANGE, couleur2, couleur3);
				casTemp = TrouveCasCoin(cube, coTemp);
				if(casTemp == "cote_bas_imparfait"){
					tourner(RED, cube);
					tourner(RED, cube);
					tourner(co.coord2.face, cube);
					tourner(co.coord2.face, cube);
					tourner(co.coord2.face, cube);
				} else {
					tourner(co.coord2.face, cube);
					tourner(co.coord2.face, cube);
					tourner(RED, cube);
					tourner(RED, cube);
					tourner(co.coord2.face, cube);
				}
				
			} else {
				tourner(RED, cube);
			}
			
			
		}
		
		//devient coté_bas_parfait
		if(cas == "cote_bas_imparfait")
		{
			printf("%s\n", cas);
			coTemp = RechercherCoin(cube, tabCoins, ORANGE, couleur2, couleur3);
			casTemp = TrouveCasCoin(cube, coTemp);
			while (casTemp != "cote_bas_parfait")
			{
				tourner(RED, cube);
				coTemp = RechercherCoin(cube, tabCoins, ORANGE, couleur2, couleur3);
				casTemp = TrouveCasCoin(cube, coTemp);
				
			}
			

		}
		
		if(cas == "cote_bas_parfait")
		{
			tourner(co.coord1.face, cube);
			coTemp = RechercherCoin(cube, tabCoins, ORANGE, couleur2, couleur3);
			casTemp = TrouveCasCoin(cube, coTemp);
			
			if(casTemp == "cote_bas_imparfait"){
				tourner(RED, cube);
				coTemp2 = RechercherCoin(cube, tabCoins, ORANGE, couleur2, couleur3);
				casTemp2 = TrouveCasCoin(cube, coTemp2);
				if(casTemp2 != "cote_bas_parfait"){
					tourner(RED, cube);
					tourner(RED, cube);
				}
				
				tourner(co.coord1.face, cube);
				tourner(co.coord1.face, cube);
				tourner(co.coord1.face, cube);
				
				 
			} else {
				tourner(co.coord1.face, cube);
				tourner(co.coord1.face, cube);
				
				coTemp2 = RechercherCoin(cube, tabCoins, ORANGE, couleur2, couleur3);
				casTemp2 = TrouveCasCoin(cube, coTemp2);
				while(casTemp2 != "cote_bas_parfait"){
					tourner(RED, cube);
					coTemp2 = RechercherCoin(cube, tabCoins, ORANGE, couleur2, couleur3);
					casTemp2 = TrouveCasCoin(cube, coTemp2);
				}
				
				tourner(co.coord1.face, cube);
				
			}
			
		}
		
	co = RechercherCoin(cube,tabCoins,ORANGE, couleur2, couleur3);
	cas = TrouveCasCoin(cube, co);
	affiche(cube);
	
	}
	printf("===================FIN DU COIN================\n");

}
	

//appelle FaireCoinOrange, pour résouder les quatre coins manquants de la face orange
void FinirFaceOrange(int cube[6][3][3], coin tabCoins[8]){
	coin co210, co215, co253, co230;
	
	printf("boujour mêssier1\n");
	co210 = RechercherCoin(cube, tabCoins, 2, 1, 0);
	printf("boujour mêssier2\n");
	FaireCoinOrange(cube, co210, tabCoins);
	
	printf("boujour mêssier3\n");
	co215 = RechercherCoin(cube, tabCoins, 2, 1, 5);
	FaireCoinOrange(cube, co215, tabCoins);
	
	
	co253 = RechercherCoin(cube, tabCoins, 2, 5, 3);
	FaireCoinOrange(cube, co253, tabCoins);
	
	
	co230 = RechercherCoin(cube, tabCoins, 2, 3, 0);
	FaireCoinOrange(cube, co230, tabCoins);
	

}


char* TrouveCasCouronne(int cube[6][3][3], milieu mil){
	char* cas;
	
	//CAS COTE
	if(mil.coord1.face != RED  &&
	   mil.coord2.face != RED)
	{
		//cas cote_parfait
		if(mil.coord1.face == cube[mil.coord1.face][mil.coord1.x][mil.coord1.y] &&
		   mil.coord2.face == cube[mil.coord2.face][mil.coord2.x][mil.coord2.y])
		{
			cas = "cote_parfait";
		} 
		
		//cas cote_imparfait
		else {
			cas = "cote_imparfait";
		}
	}
	
	//CAS BAS
	if(mil.coord1.face == RED || mil.coord2.face == RED) {
		//cas bas parfait
		if(mil.coord1.face == cube[mil.coord1.face][mil.coord1.x][mil.coord1.y] ||
		   mil.coord2.face == cube[mil.coord2.face][mil.coord2.x][mil.coord2.y])
		{
			cas = "bas_parfait";
		} 
		
		//cas bas imparfait
		else {
			cas = "bas_imparfait";
		}
		
			
	}
	
	return cas;
	
	
}


void FairePartieCouronne(int cube[6][3][3], milieu mil, milieu* tabMilieux){
	char* cas;
	cas = TrouveCasCouronne(cube, mil);
	printf("!!!!!!!!!!!!!!!!!%s\n", cas);

	int couleur1 = cube[mil.coord1.face][mil.coord1.x][mil.coord1.y];
	int couleur2 = cube[mil.coord2.face][mil.coord2.x][mil.coord2.y];
	
	char* sens;
	int orient ;

	milieu milTemp;
	char* casTemp;
	
	while(cas != "cote_parfait"){
		
		
		if(cas == "bas_parfait")
		{
			//recherche du coté sur la face du dessous
			if(mil.coord1.face == RED)
			{
				orient = 2;
			} 
			if(mil.coord2.face == RED)
			{
				orient = 1;
			}
			
			//on veut savoir si on va être en cote droit ou gauche parfait.
			char* cote;

			if(couleur1 == YELLOW && couleur2 == GREEN){if(orient == 1){cote = "droite_parfait";} else{cote = "gauche_parfait";}}
			if(couleur1 == 3 && couleur2 == 5){if(orient == 1){cote ="droite_parfait";}else{cote = "gauche_parfait";}}
			if(couleur1 == 0 && couleur2 == 1){if(orient == 1){cote = "gauche_parfait";}else{cote = "droite_parfait";}}
			if(couleur1 == 0 && couleur2 == 3){if(orient == 1){cote = "droite_parfait";}else{cote = "gauche_parfait";}}





		printf("orient est %d\n",orient);
		printf("%s\n", cas);
		affiche(cube);
		//on tourne bien sur coord1
			if(orient == 1){
				tourner(mil.coord1.face, cube);
				milTemp = RechercherMilieu(cube, tabMilieux, couleur1, couleur2);
				casTemp = TrouveCasCouronne(cube, milTemp);
				printf("le cas cote est %s\n", cote);
				printf("le casTemp est %s\n", casTemp);
				if(cote == "gauche_parfait"){
					if (casTemp == "cote_parfait")
					{
						tourner(RED, cube);
						tourner(mil.coord1.face, cube);
						tourner(RED, cube);
						tourner(mil.coord1.face, cube);
						
						tourner(RED, cube);
						tourner(RED, cube);
						tourner(RED, cube);
						tourner(mil.coord1.face, cube);				
						tourner(mil.coord1.face, cube);
						tourner(mil.coord1.face, cube);
						tourner(RED, cube);
						tourner(RED, cube);
						tourner(RED, cube);
						tourner(mil.coord1.face, cube);				
						tourner(mil.coord1.face, cube);
						tourner(mil.coord1.face, cube);
					}
					else
					{
						tourner(mil.coord1.face, cube);
						tourner(mil.coord1.face, cube);
						tourner(RED, cube);
						tourner(mil.coord1.face, cube);
						tourner(mil.coord1.face, cube);
						tourner(mil.coord1.face, cube);
						tourner(RED, cube);
						tourner(mil.coord1.face, cube);
						tourner(mil.coord1.face, cube);
						tourner(mil.coord1.face, cube);
						
						tourner(RED, cube);
						tourner(RED, cube);
						tourner(RED, cube);
						tourner(mil.coord1.face, cube);				
						tourner(RED, cube);
						tourner(RED, cube);
						tourner(RED, cube);
						tourner(mil.coord1.face, cube);	
					}
					
					
								
				}
				if(cote == "droite_parfait") {
					if(casTemp == "cote_parfait"){
				
					tourner(RED, cube);
					tourner(RED, cube);
					tourner(RED, cube);
					tourner(mil.coord1.face, cube);
					tourner(RED, cube);
					tourner(RED, cube);
					tourner(RED, cube);
					tourner(mil.coord1.face, cube);
					
					tourner(RED, cube);
					tourner(mil.coord1.face, cube);
					tourner(mil.coord1.face, cube);
					tourner(mil.coord1.face, cube);
					tourner(RED, cube);
					tourner(mil.coord1.face, cube);
					tourner(mil.coord1.face, cube);
					tourner(mil.coord1.face, cube);
					}
					else{
					
					tourner(mil.coord1.face, cube);
					tourner(mil.coord1.face, cube);
					tourner(RED, cube);
					tourner(RED, cube);
					tourner(RED, cube);
					tourner(mil.coord1.face, cube);
					tourner(mil.coord1.face, cube);
					tourner(mil.coord1.face, cube);
					tourner(RED, cube);
					tourner(RED, cube);
					tourner(RED, cube);
					tourner(mil.coord1.face, cube);
					tourner(mil.coord1.face, cube);
					tourner(mil.coord1.face, cube);
					
					tourner(RED, cube);
					tourner(mil.coord1.face, cube);
					tourner(RED, cube);
					tourner(mil.coord1.face, cube);
					}
					
				}
				/*if(casTemp == "cote_parfait"){
					tourner(RED, cube);
					tourner(RED, cube);
					tourner(RED, cube);
					tourner(mil.coord1.face, cube);
					tourner(RED, cube);
					tourner(RED, cube);
					tourner(RED, cube);
					tourner(mil.coord1.face, cube);
					
					tourner(RED, cube);
					tourner(mil.coord1.face, cube);				
					tourner(mil.coord1.face, cube);
					tourner(mil.coord1.face, cube);
					tourner(RED, cube);
					tourner(mil.coord1.face, cube);				
					tourner(mil.coord1.face, cube);
					tourner(mil.coord1.face, cube);
								
				} else {	
					tourner(mil.coord1.face, cube);
					tourner(mil.coord1.face, cube);
					
					tourner(RED, cube);
					tourner(RED, cube);
					tourner(RED, cube);
					tourner(mil.coord1.face, cube);
					tourner(mil.coord1.face, cube);
					tourner(mil.coord1.face, cube);
					tourner(RED, cube);
					tourner(RED, cube);
					tourner(RED, cube);
					tourner(mil.coord1.face, cube);
					tourner(mil.coord1.face, cube);
					tourner(mil.coord1.face, cube);
					
					tourner(RED, cube);
					tourner(mil.coord1.face, cube);
					tourner(RED, cube);
					tourner(mil.coord1.face, cube);				
				}*/
			}
			//on tourne sur coord2
			if(orient == 2){
				tourner(mil.coord2.face, cube);
				milTemp = RechercherMilieu(cube, tabMilieux, couleur1, couleur2);
				casTemp = TrouveCasCouronne(cube, milTemp);
				printf("le cas cote est %s\n", cote);
				printf("le casTemp est %s\n", casTemp);
				
				if(cote == "gauche_parfait"){
					if (casTemp == "cote_parfait")
					{
						tourner(RED, cube);
						tourner(mil.coord2.face, cube);
						tourner(RED, cube);
						tourner(mil.coord2.face, cube);
						
						tourner(RED, cube);
						tourner(RED, cube);
						tourner(RED, cube);
						tourner(mil.coord2.face, cube);				
						tourner(mil.coord2.face, cube);
						tourner(mil.coord2.face, cube);
						tourner(RED, cube);
						tourner(RED, cube);
						tourner(RED, cube);
						tourner(mil.coord2.face, cube);				
						tourner(mil.coord2.face, cube);
						tourner(mil.coord2.face, cube);
					}
					else
					{
						tourner(mil.coord2.face, cube);
						tourner(mil.coord2.face, cube);
						tourner(RED, cube);
						tourner(mil.coord2.face, cube);
						tourner(mil.coord2.face, cube);
						tourner(mil.coord2.face, cube);
						tourner(RED, cube);
						tourner(mil.coord2.face, cube);
						tourner(mil.coord2.face, cube);
						tourner(mil.coord2.face, cube);
						
						tourner(RED, cube);
						tourner(RED, cube);
						tourner(RED, cube);
						tourner(mil.coord2.face, cube);				
						tourner(RED, cube);
						tourner(RED, cube);
						tourner(RED, cube);
						tourner(mil.coord2.face, cube);	
					}
					
					
								
				}
				if(cote == "droite_parfait") {
					if(casTemp == "cote_parfait"){
				
					tourner(RED, cube);
					tourner(RED, cube);
					tourner(RED, cube);
					tourner(mil.coord2.face, cube);
					tourner(RED, cube);
					tourner(RED, cube);
					tourner(RED, cube);
					tourner(mil.coord2.face, cube);
					
					tourner(RED, cube);
					tourner(mil.coord2.face, cube);
					tourner(mil.coord2.face, cube);
					tourner(mil.coord2.face, cube);
					tourner(RED, cube);
					tourner(mil.coord2.face, cube);
					tourner(mil.coord2.face, cube);
					tourner(mil.coord2.face, cube);
					}
					else{
					
					tourner(mil.coord2.face, cube);
					tourner(mil.coord2.face, cube);
					tourner(RED, cube);
					tourner(RED, cube);
					tourner(RED, cube);
					tourner(mil.coord2.face, cube);
					tourner(mil.coord2.face, cube);
					tourner(mil.coord2.face, cube);
					tourner(RED, cube);
					tourner(RED, cube);
					tourner(RED, cube);
					tourner(mil.coord2.face, cube);
					tourner(mil.coord2.face, cube);
					tourner(mil.coord2.face, cube);
					
					tourner(RED, cube);
					tourner(mil.coord2.face, cube);
					tourner(RED, cube);
					tourner(mil.coord2.face, cube);
					}
					
				}
			}
		}
		if (cas == "bas_imparfait")
		{
			printf("%s\n", cas);
			affiche(cube);

			milTemp = RechercherMilieu(cube, tabMilieux, couleur1, couleur2);
			casTemp = TrouveCasCouronne(cube, milTemp);
			while (casTemp != "bas_parfait")
			{
				tourner(RED, cube);
				milTemp = RechercherMilieu(cube, tabMilieux, couleur1, couleur2);
				casTemp = TrouveCasCouronne(cube, milTemp);
			}

			
		}

		if (cas == "cote_imparfait")
		{
			printf("%s\n", cas);
			int side;
			/*if(couleur1 == YELLOW && couleur2 == GREEN){side = 1;}
			if(couleur1 == 3 && couleur2 == 5){side = 1;}
			if(couleur1 == 0 && couleur2 == 1){side = 2;}
			if(couleur1 == 0 && couleur2 == 3){side = 1;}*/
			//on regarde la couleur 

			if((mil.coord1.face == BLUE && mil.coord1.x == 1 && mil.coord1.y == 0)
				|| (mil.coord1.face == YELLOW && mil.coord1.x == 0 && mil.coord1.y == 1)
				|| (mil.coord1.face == GREEN && mil.coord1.x == 1 && mil.coord1.y == 2)
				|| (mil.coord1.face == WHITE && mil.coord1.x == 2 && mil.coord1.y == 1)
			){side = 1;}
			else{side = 2;}
			



			
			if(side == 1){
				tourner(mil.coord1.face, cube);
				milTemp = RechercherMilieu(cube, tabMilieux, couleur1, couleur2);
				casTemp = TrouveCasCouronne(cube, milTemp);		
				printf("le side est %d\n", side);
				printf("le casTemp est %s\n", casTemp);
				if(casTemp != "bas_imparfait"){
					printf("bon sens\n");
					tourner(RED, cube);
					tourner(RED, cube);
					tourner(RED, cube);
					tourner(mil.coord1.face, cube);
					tourner(RED, cube);
					tourner(RED, cube);
					tourner(RED, cube);
					tourner(mil.coord1.face, cube);
					
					tourner(RED, cube);
					tourner(mil.coord1.face, cube);				
					tourner(mil.coord1.face, cube);
					tourner(mil.coord1.face, cube);
					tourner(RED, cube);
					tourner(mil.coord1.face, cube);				
					tourner(mil.coord1.face, cube);
					tourner(mil.coord1.face, cube);
								
				} else {	
					printf("mauvais sens");
					tourner(mil.coord1.face, cube);
					tourner(mil.coord1.face, cube);
					
					tourner(RED, cube);
					tourner(RED, cube);
					tourner(RED, cube);
					tourner(mil.coord1.face, cube);
					tourner(mil.coord1.face, cube);
					tourner(mil.coord1.face, cube);
					tourner(RED, cube);
					tourner(RED, cube);
					tourner(RED, cube);
					tourner(mil.coord1.face, cube);
					tourner(mil.coord1.face, cube);
					tourner(mil.coord1.face, cube);
					
					tourner(RED, cube);
					tourner(mil.coord1.face, cube);
					tourner(RED, cube);
					tourner(mil.coord1.face, cube);				
				}
			}
			else{
				tourner(mil.coord2.face, cube);
				milTemp = RechercherMilieu(cube, tabMilieux, couleur1, couleur2);
				casTemp = TrouveCasCouronne(cube, milTemp);	
				printf("le side est %d\n", side);
				printf("le casTemp est %s\n", casTemp);	
				if(casTemp != "bas_imparfait"){
				
					tourner(RED, cube);
					tourner(RED, cube);
					tourner(RED, cube);
					tourner(mil.coord2.face, cube);
					tourner(RED, cube);
					tourner(RED, cube);
					tourner(RED, cube);
					tourner(mil.coord2.face, cube);
					
					tourner(RED, cube);
					tourner(mil.coord2.face, cube);
					tourner(mil.coord2.face, cube);
					tourner(mil.coord2.face, cube);
					tourner(RED, cube);
					tourner(mil.coord2.face, cube);
					tourner(mil.coord2.face, cube);
					tourner(mil.coord2.face, cube);
					}
					else{
					
					tourner(mil.coord2.face, cube);
					tourner(mil.coord2.face, cube);
					tourner(RED, cube);
					tourner(RED, cube);
					tourner(RED, cube);
					tourner(mil.coord2.face, cube);
					tourner(mil.coord2.face, cube);
					tourner(mil.coord2.face, cube);
					tourner(RED, cube);
					tourner(RED, cube);
					tourner(RED, cube);
					tourner(mil.coord2.face, cube);
					tourner(mil.coord2.face, cube);
					tourner(mil.coord2.face, cube);
					
					tourner(RED, cube);
					tourner(mil.coord2.face, cube);
					tourner(RED, cube);
					tourner(mil.coord2.face, cube);
					}

			}
					
			affiche(cube);
		}
		
	affiche(cube);
		
	mil = RechercherMilieu(cube,tabMilieux,couleur1, couleur2);
	cas = TrouveCasCouronne(cube, mil);
	}
	printf("--------------------------FIN COTE COURONNE-----------------------\n");
}

void FaireCouronne(int cube[6][3][3],milieu tab[12])
{
	milieu mil35, mil51, mil01, mil03;

	mil35 = RechercherMilieu(cube,tab,3,5);
	FairePartieCouronne(cube, mil35,tab);
	
	mil51 = RechercherMilieu(cube,tab,5,1);
	FairePartieCouronne(cube, mil51,tab);

	mil01 = RechercherMilieu(cube,tab,0,1);
	FairePartieCouronne(cube, mil01,tab);

	mil03 = RechercherMilieu(cube,tab,0,3);
	FairePartieCouronne(cube, mil03,tab);

}

void MiseEnPlaceCoteRouge(int cube[6][3][3])
{
	tourner(WHITE, cube);
	tourner(RED, cube);
	tourner(GREEN, cube);

	tourner(RED, cube);
	tourner(RED, cube);
	tourner(RED, cube);
	tourner(GREEN, cube);
	tourner(GREEN, cube);
	tourner(GREEN, cube);
	tourner(WHITE, cube);
	tourner(WHITE, cube);
	tourner(WHITE, cube);

}

void FaireCroixRouge(int cube[6][3][3])
{while(cube[4][0][1] != RED || cube[4][1][0] != RED || cube[4][2][1] != RED || cube[4][1][2] != RED){
		//cas point (pas de L ni de barre)
		if(cube[4][0][1] != RED && cube[4][1][0] != RED && cube[4][2][1] != RED)
		{
			printf("casrien\n");
			MiseEnPlaceCoteRouge(cube);
		}

		//cas ligne horizontale
		if(cube[4][0][1] == cube[4][2][1]){
			printf("caslignehori\n");
			MiseEnPlaceCoteRouge(cube);
		}
		//cas ligne verticale
		if(cube[4][1][0] == cube[4][1][2]){
			printf("casligneverti\n");
			tourner(RED,cube);
			MiseEnPlaceCoteRouge(cube);
		}
		//cas L
		else{
			printf("casL\n");
			while(cube[4][0][1] != RED || cube[4][1][0] != RED){
				tourner(RED,cube);
			}
			MiseEnPlaceCoteRouge(cube);
		}
	}

}

void MiseEnPlaceCoinRouge(int cube[6][3][3])
{
	
	tourner(GREEN, cube);
	tourner(RED, cube);

	tourner(GREEN, cube);
	tourner(GREEN, cube);
	tourner(GREEN, cube);

	tourner(RED, cube);

	tourner(GREEN, cube);

	tourner(RED, cube);
	tourner(RED, cube);

	tourner(GREEN, cube);
	tourner(GREEN, cube);
	tourner(GREEN, cube);

}


void FaireCoinsRouge(int cube[6][3][3])
{
	while(cube[4][0][0] != RED || cube[4][2][0] != RED || cube[4][0][2] != RED || cube[4][2][2] != RED)
		{
		//cas pas de coins
		if(cube[4][0][0] != RED && cube[4][2][0] != RED && cube[4][0][2] != RED && cube[4][2][2] != RED)
		{
			printf("cas pasdecoins\n");
			MiseEnPlaceCoinRouge(cube);
		}

		//cas 2 coins opposés imparfait
		if(cube[4][0][0] == RED && cube[4][2][2] == RED )
		{
			printf("cas 2coinsopposés\n");
			MiseEnPlaceCoinRouge(cube);
		}

		//cas 2 coins opposés parfait
		if(cube[4][0][2] == RED && cube[4][2][0] == RED )
		{
			printf("cas 2coinsopposés\n");
			tourner(RED, cube);
			MiseEnPlaceCoinRouge(cube);
		}

		//cas 2 coins alignés
		if((cube[4][0][0] == RED && cube[4][2][0] == RED) ||
			(cube[4][2][0] == RED && cube[4][2][2] == RED) ||
			(cube[4][2][2] == RED && cube[4][0][2] == RED) ||
			(cube[4][0][2] == RED && cube[4][0][0] == RED))
			{
				printf("cas 2coinsopposés\n");
				while(cube[4][2][2] != RED && cube[4][0][2] != RED)
				{
					tourner(RED, cube);
				}
				MiseEnPlaceCoinRouge(cube);
			}

		//cas 1 seul coin
		if((cube[4][0][0] == RED && cube[4][2][0] != RED && cube[4][0][2] != RED && cube[4][2][2] != RED) ||
			(cube[4][0][0] != RED && cube[4][2][0] == RED && cube[4][0][2] != RED && cube[4][2][2] != RED) ||
			(cube[4][0][0] != RED && cube[4][2][0] != RED && cube[4][0][2] == RED && cube[4][2][2] != RED) ||
			(cube[4][0][0] != RED && cube[4][2][0] != RED && cube[4][0][2] != RED && cube[4][2][2] == RED))
		
		{
			while(cube[4][0][2] != RED)
			{
				printf("cas 1seulcoin\n");
				tourner(RED,cube);
			}
			MiseEnPlaceCoinRouge(cube);
		}
		//else{printf("pbm\n"); affiche(cube);}
	}
}

void FaireCoinsFinal(int cube[6][3][3])
{
	while(cube[3][2][2] != BLUE || cube[3][2][0] == BLUE || cube[5][2][0] == YELLOW || cube[5][0][0] == YELLOW || cube[1][0][0] == GREEN || cube[1][0][2] == GREEN || cube[0][0][2] == WHITE || cube[0][2][2] == WHITE)
	{
		//cas 1 coin bien
		if((cube[3][2][2] == BLUE && cube[0][2][2] != RED) ||
			(cube[0][0][2] == WHITE && cube[1][0][2] != GREEN) ||
			(cube[3][2][0] == BLUE && cube[0][2][2] != RED) ||
			(cube[3][2][2] == BLUE && cube[0][2][2] != RED))

		//cas 2coins bien opposés

		//cas pas de coin?
	}
}