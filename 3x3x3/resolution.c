#include <stdio.h>
#include <time.h>
#include "fonctions.h"
#include <stdlib.h>



//Définition des couleurs
#define WHITE   0
#define GREEN   1
#define ORANGE  2
#define BLUE    3
#define RED     4
#define YELLOW  5

/* Ces structures permettent de définir les cublons coins et milieux pour les repérer dans le tableau représentant le cube.
 * Ils ont donc: une face, un x, un y, pour chaque face du cublon (trois pour les coins et 2 pour les milieux). 
 */
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


//Prend les coordonnées d'une case milieu et les remplit dans un struct milieu
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

//Recherche l'emplacement de la pièce milieu contenant les couleurs 1 et 2
//Et retourne un objet milieu avec les coordonées respectives aux couleurs
//(l'ordre d'entrée est conservé)
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
	
	printf("vous vous êtes trompés de couleurs \n");
	return	rm(0,0,0,0,0,0);
}

//retourne le cas dans lequel est situé le milieu passé en paramètre pour faire la croix orange
//L'algorithme à appliquer dépends de ce cas
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
	
	return cas;
}

//Applique un algorithme spécifique en fonction de chaque cas pour faire la croix orange
void FaireBrasCroix(int cube[6][3][3],milieu mil, milieu tabMilieux[12], int *compt){
	char* cas;
	cas = TrouveCasMilieu(cube, mil);
	int couleur2 = cube[mil.coord2.face][mil.coord2.x][mil.coord2.y];
	
	
	while(cas != "parfait")
	{
		if(cas == "imparfait")
		{
			
			tourner(mil.coord2.face, cube);
			tourner(mil.coord2.face, cube);
			*compt = *compt + 2;
		}
		
		if(cas == "cote_haut")
		{
			tourner(mil.coord1.face, cube);
			*compt = *compt + 1;
		}
		
		if(cas == "cote_bas")
		{
			
			//Regarder si la pièce en haut est déjà bien placée
			if(TrouveCasMilieu(cube, RechercherMilieu(cube, tabMilieux, ORANGE, mil.coord1.face)) == "parfait")
			{
				tourner(RED, cube);
				*compt = *compt + 1;
			} else {
				tourner(mil.coord1.face,cube);
				*compt = *compt + 1;
			}
		}
		
		
		if(cas == "cote_cote")
		{
			tourner(mil.coord2.face, cube);
			*compt = *compt + 1;
			
			mil = RechercherMilieu(cube,tabMilieux,ORANGE, couleur2);
			//
			//
			
			if(TrouveCasMilieu(cube, RechercherMilieu(cube, tabMilieux, cube[mil.coord1.face][mil.coord1.x][mil.coord1.y], cube[mil.coord2.face][mil.coord2.x][mil.coord2.y])) == "dessous_imparfait" ||
			   TrouveCasMilieu(cube, RechercherMilieu(cube, tabMilieux, cube[mil.coord1.face][mil.coord1.x][mil.coord1.y], cube[mil.coord2.face][mil.coord2.x][mil.coord2.y])) == "dessous_parfait")
			{
				tourner(RED, cube);
				tourner(mil.coord2.face, cube);
				tourner(mil.coord2.face, cube);
				tourner(mil.coord2.face, cube);
				*compt = *compt + 2;
			} else {
				tourner(mil.coord2.face, cube);
				tourner(mil.coord2.face, cube);
				tourner(RED, cube);
				tourner(mil.coord2.face, cube);
				*compt = *compt + 4;
			}
			
		}
		if(cas == "dessous_imparfait")
		{
			
			tourner(RED, cube);
			*compt = *compt + 1;
		}
		
		
		if(cas == "dessous_parfait")
		{
			
			tourner(mil.coord2.face, cube);
			tourner(mil.coord2.face, cube);
			*compt = *compt + 2;
		}
		
		
	
	mil = RechercherMilieu(cube,tabMilieux,ORANGE, couleur2);
	cas = TrouveCasMilieu(cube, mil);
	
	}	
	
	printf("===================FIN DU BRAS================\n");
}


//Fais les 4 bras de la croix en appelant la fonction FaireBrasCroix
void FaireCroixOrange(int cube[6][3][3],milieu tabMilieux[12], int *compt)
{
	
	

	
	
	
	milieu mil25, mil21, mil20, mil23;
	mil25 = RechercherMilieu(cube,tabMilieux, ORANGE, YELLOW);
	FaireBrasCroix(cube, mil25, tabMilieux, compt);
	mil21 = RechercherMilieu(cube,tabMilieux, ORANGE, GREEN);
	FaireBrasCroix(cube, mil21, tabMilieux, compt);
	mil20 = RechercherMilieu(cube,tabMilieux, ORANGE, WHITE);
	FaireBrasCroix(cube, mil20, tabMilieux, compt);
	mil23 = RechercherMilieu(cube,tabMilieux, ORANGE, BLUE);
	FaireBrasCroix(cube, mil23, tabMilieux, compt);

	
	
		
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------

//Prend les coordonnées d'une case coin et les remplit dans un coin (semblable à RemplirMilieu)
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
//(l'ordre d'entrée n'est pas conservé)
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
	
	printf("vous vous êtes trompés de couleurs \n");
	return	rc(0,0,0,0,0,0,0,0,0);
}



//retourne le cas dans lequel est situé le coin passé en paramètre pour faire les coins de la face orange
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
	

	return cas;
}

//Positionne correctement le coin de la face orange passé en paramètre
void FaireCoinOrange(int cube[6][3][3],coin co, coin tabCoins[8], int *compt){
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
			
			tourner(co.coord2.face, cube);
			*compt = *compt + 1;
			coTemp = RechercherCoin(cube, tabCoins, ORANGE, couleur2, couleur3);
			casTemp = TrouveCasCoin(cube, coTemp);
			if(casTemp == "cote_bas_imparfait"){
				tourner(RED, cube);
				tourner(RED, cube);
				tourner(co.coord2.face, cube);
				tourner(co.coord2.face, cube);
				tourner(co.coord2.face, cube);
				*compt = *compt + 3;
				
			} else {
				tourner(co.coord2.face, cube);
				tourner(co.coord2.face, cube);
				tourner(RED, cube);
				tourner(RED, cube);
				tourner(co.coord2.face, cube);
				*compt = *compt + 5;
				
			}
		
		
		}
		
	
		//devient coté_bas
		if(cas == "cote_haut")
		{
			
			tourner(co.coord1.face, cube);
			*compt = *compt + 1;
			coTemp = RechercherCoin(cube, tabCoins, ORANGE, couleur2, couleur3);
			casTemp = TrouveCasCoin(cube, coTemp);
			if(casTemp == "cote_bas_imparfait" ||  casTemp == "cote_bas_parfait" ){
				tourner(RED, cube);
				tourner(RED, cube);
				tourner(co.coord1.face, cube);
				tourner(co.coord1.face, cube);
				tourner(co.coord1.face, cube);
				*compt = *compt + 3;
				
			} else {
				tourner(co.coord1.face, cube);
				tourner(co.coord1.face, cube);
				tourner(RED, cube);
				tourner(RED, cube);
				tourner(co.coord1.face, cube);
				*compt = *compt + 5;
			}
		}
		
		//cas dessous parfait ou imparfait
		//devient coté_bas
		if(cas == "dessous")
		{
			
			if((co.coord2.face == couleur2 && co.coord3.face == couleur3) ||
				(co.coord2.face == couleur3 && co.coord3.face == couleur2))
			{
				tourner(co.coord2.face, cube);
				*compt = *compt + 1;
				coTemp = RechercherCoin(cube, tabCoins, ORANGE, couleur2, couleur3);
				casTemp = TrouveCasCoin(cube, coTemp);
				if(casTemp == "cote_bas_imparfait"){
					tourner(RED, cube);
					tourner(RED, cube);
					tourner(co.coord2.face, cube);
					tourner(co.coord2.face, cube);
					tourner(co.coord2.face, cube);
					*compt = *compt + 3;
				} else {
					tourner(co.coord2.face, cube);
					tourner(co.coord2.face, cube);
					tourner(RED, cube);
					tourner(RED, cube);
					tourner(co.coord2.face, cube);
					*compt = *compt + 5;
				}
				
			} else {
				tourner(RED, cube);
				*compt = *compt + 1;
			}
			
			
		}
		
		//devient coté_bas_parfait
		if(cas == "cote_bas_imparfait")
		{
			
			coTemp = RechercherCoin(cube, tabCoins, ORANGE, couleur2, couleur3);
			casTemp = TrouveCasCoin(cube, coTemp);
			while (casTemp != "cote_bas_parfait")
			{
				tourner(RED, cube);
				*compt = *compt + 1;
				coTemp = RechercherCoin(cube, tabCoins, ORANGE, couleur2, couleur3);
				casTemp = TrouveCasCoin(cube, coTemp);
				
			}
			

		}
		
		if(cas == "cote_bas_parfait")
		{
			tourner(co.coord1.face, cube);
			*compt = *compt + 1;
			coTemp = RechercherCoin(cube, tabCoins, ORANGE, couleur2, couleur3);
			casTemp = TrouveCasCoin(cube, coTemp);
			
			if(casTemp == "cote_bas_imparfait"){
				tourner(RED, cube);
				*compt = *compt + 1;
				coTemp2 = RechercherCoin(cube, tabCoins, ORANGE, couleur2, couleur3);
				casTemp2 = TrouveCasCoin(cube, coTemp2);
				if(casTemp2 != "cote_bas_parfait"){
					tourner(RED, cube);
					tourner(RED, cube);
					*compt = *compt + 2;
				}
				
				tourner(co.coord1.face, cube);
				tourner(co.coord1.face, cube);
				tourner(co.coord1.face, cube);
				*compt = *compt + 1;
				
				 
			} else {
				tourner(co.coord1.face, cube);
				tourner(co.coord1.face, cube);
				*compt = *compt + 2;
				
				coTemp2 = RechercherCoin(cube, tabCoins, ORANGE, couleur2, couleur3);
				casTemp2 = TrouveCasCoin(cube, coTemp2);
				while(casTemp2 != "cote_bas_parfait"){
					tourner(RED, cube);
					*compt = *compt + 1;
					coTemp2 = RechercherCoin(cube, tabCoins, ORANGE, couleur2, couleur3);
					casTemp2 = TrouveCasCoin(cube, coTemp2);
				}
				
				tourner(co.coord1.face, cube);
				*compt = *compt + 1;
				
			}
			
		}
		
	co = RechercherCoin(cube,tabCoins,ORANGE, couleur2, couleur3);
	cas = TrouveCasCoin(cube, co);
	
	}
	printf("===================FIN DU COIN================\n");

}
	

//appelle FaireCoinOrange, pour positionner les quatre coins manquants de la face orange après avoir fait la face
void FinirFaceOrange(int cube[6][3][3], coin tabCoins[8], int *compt){

	coin co210, co215, co253, co230;
	co210 = RechercherCoin(cube, tabCoins, 2, 1, 0);
	FaireCoinOrange(cube, co210, tabCoins, compt);
	
	co215 = RechercherCoin(cube, tabCoins, 2, 1, 5);
	FaireCoinOrange(cube, co215, tabCoins, compt);
	
	co253 = RechercherCoin(cube, tabCoins, 2, 5, 3);
	FaireCoinOrange(cube, co253, tabCoins, compt);
	
	co230 = RechercherCoin(cube, tabCoins, 2, 3, 0);
	FaireCoinOrange(cube, co230, tabCoins, compt);
}



// Renvoie le cas dans lequel se trouve le cublon milieu pour faire la couronne (seconde ligne du cube)
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



//En fonction du cas de TrouveCasCouronne, applique un algorithme pour positionner correctement le milieu passé en paramètre
void FairePartieCouronne(int cube[6][3][3], milieu mil, milieu* tabMilieux, coin *tabCoins, int *compt){
	char* cas;
	cas = TrouveCasCouronne(cube, mil);


	int couleur1 = cube[mil.coord1.face][mil.coord1.x][mil.coord1.y];
	int couleur2 = cube[mil.coord2.face][mil.coord2.x][mil.coord2.y];
	
	char* sens; 
	int orient ; // pour savoir l'orientation de la piece milieux entre la courone et la face rouge
	char* cote; // pour savoir le sens de rotation a choisir pour faire l'algorithme

	milieu milTemp;
	char* casTemp;
	char f;
	int side; // important pour le cas cote imparfait
	
	while(cas != "cote_parfait"){
		
		
		if(cas == "bas_parfait"){
			//recherche du coté sur la face du dessous
			if(mil.coord1.face == RED)
			{
				orient = 2;
			} 
			if(mil.coord2.face == RED)
			{
				orient = 1;
			}
			
			//on veut savoir si on va être en cote droit parfait ou gauche parfait.

			if(couleur1 == YELLOW && couleur2 == GREEN){if(orient == 1){cote = "droite_parfait";} else{cote = "gauche_parfait";}}
			if(couleur1 == BLUE && couleur2 == YELLOW){if(orient == 1){cote ="droite_parfait";}else{cote = "gauche_parfait";}}
			if(couleur1 == WHITE && couleur2 == GREEN){if(orient == 1){cote = "gauche_parfait";}else{cote = "droite_parfait";}}
			if(couleur1 == WHITE && couleur2 == BLUE){if(orient == 1){cote = "droite_parfait";}else{cote = "gauche_parfait";}}


		//on tourne bien sur coord1
			if(orient == 1){
				tourner(mil.coord1.face, cube);
				*compt = *compt + 1;
				milTemp = RechercherMilieu(cube, tabMilieux, couleur1, couleur2);
				casTemp = TrouveCasCouronne(cube, milTemp);
				
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
						*compt = *compt + 8;
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
						*compt = *compt + 8;
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
					*compt = *compt + 8;
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
					*compt = *compt + 8;
					}
					
				}
			}
			//on tourne sur coord2
			if(orient == 2){
				tourner(mil.coord2.face, cube);
				*compt = *compt + 1;
				milTemp = RechercherMilieu(cube, tabMilieux, couleur1, couleur2);
				casTemp = TrouveCasCouronne(cube, milTemp);
				
				
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
						*compt = *compt + 8;
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
						*compt = *compt + 8;
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
					*compt = *compt + 8;
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
					*compt = *compt + 8;
					}
					
				}
			}
		}
	    
		else if (cas == "bas_imparfait")	{
			milTemp = RechercherMilieu(cube, tabMilieux, couleur1, couleur2);
			casTemp = TrouveCasCouronne(cube, milTemp);
			int i = 0;
			while (casTemp != "bas_parfait")
			{
				tourner(RED, cube);
				*compt = *compt + 1;
				milTemp = RechercherMilieu(cube, tabMilieux, couleur1, couleur2);
				casTemp = TrouveCasCouronne(cube, milTemp);
			}
			if( i == 2){*compt = *compt + 1;}
			else{*compt = *compt + 1;}

			
		}


		else if (cas == "cote_imparfait"){
			/* Si la piece est placée dans un cote milieux, il faut savoir sur quel
			 * 'cote' (gauche ou droite) elle se trouve.
			 * On choisit alors la coordonne de la piece sur laquelle il faut tourner ( 1 ou 2)
			 * pour être toujours en cas droite parfait*/

			if((mil.coord1.face == BLUE    && mil.coord1.x == 1 && mil.coord1.y == 0)
			|| (mil.coord1.face == YELLOW  && mil.coord1.x == 0 && mil.coord1.y == 1)
			|| (mil.coord1.face == GREEN   && mil.coord1.x == 1 && mil.coord1.y == 2)
			|| (mil.coord1.face == WHITE   && mil.coord1.x == 2 && mil.coord1.y == 1)
			){side = 1;}
			else{side = 2;}
			
			


			
			if(side == 1){
				tourner(mil.coord1.face, cube);
				*compt = *compt + 1;
				milTemp = RechercherMilieu(cube, tabMilieux, couleur1, couleur2);
				casTemp = TrouveCasCouronne(cube, milTemp);
				
				
				if(casTemp != "bas_imparfait"){
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
					*compt = *compt + 8;
								
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
					*compt = *compt + 8;		
				}
			} else {
				tourner(mil.coord2.face, cube);
				*compt = *compt + 1;
				milTemp = RechercherMilieu(cube, tabMilieux, couleur1, couleur2);
				casTemp = TrouveCasCouronne(cube, milTemp);	
				
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
					*compt = *compt + 8;
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
					*compt = *compt + 8;
					
					}

			}
					
		
		}
		

		
	mil = RechercherMilieu(cube,tabMilieux,couleur1, couleur2);
	cas = TrouveCasCouronne(cube, mil);
	
	
	
	if(!(cube[2][2][0] == cube[2][2][0] && 
		 cube[2][0][2] == cube[2][2][2] &&
		 cube[2][0][0] == cube[2][2][2] &&
		 cube[2][1][0] == cube[2][2][1] &&
		 cube[2][0][1] == cube[2][1][2] &&
		 cube[2][1][0] == cube[2][0][0]))
		{
			FaireCroixOrange(cube, tabMilieux, compt);
			FinirFaceOrange(cube, tabCoins, compt);
		}
	
	
	
	}
	
	printf("--------------------------FIN COTE COURONNE-----------------------\n");

}

//Positionne les quatres milieux constituant la couronne en appelant la fonction FairePartieCouronne
void FaireCouronne(int cube[6][3][3],milieu tab[12], coin *tabCoins, int *compt)
{
	milieu mil35, mil51, mil01, mil03;

	mil35 = RechercherMilieu(cube,tab,3,5);
	FairePartieCouronne(cube, mil35,tab, tabCoins, compt);
	
	mil51 = RechercherMilieu(cube,tab,5,1);
	FairePartieCouronne(cube, mil51,tab, tabCoins, compt);

	mil01 = RechercherMilieu(cube,tab,0,1);
	FairePartieCouronne(cube, mil01,tab, tabCoins, compt);

	mil03 = RechercherMilieu(cube,tab,0,3);
	FairePartieCouronne(cube, mil03,tab, tabCoins, compt);

}



//Algorithme général permettant de faire la croix rouge (sans souci de l'endroit ou est le milieu)
void MiseEnPlaceCoteRouge(int cube[6][3][3], int *compt)
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
	*compt = *compt + 6;

}



//Applique l'algorithme de la fonction MiseEnPlaceCoteROuge et fait la croix rouge
void FaireCroixRouge(int cube[6][3][3], int *compt)
{while(cube[4][0][1] != RED || cube[4][1][0] != RED || cube[4][2][1] != RED || cube[4][1][2] != RED){
		//cas point (pas de L ni de barre)
		if(cube[4][0][1] != RED && cube[4][1][0] != RED && cube[4][2][1] != RED)
		{
			MiseEnPlaceCoteRouge(cube, compt);
		}

		//cas ligne horizontale
		if(cube[4][0][1] == cube[4][2][1]){

			MiseEnPlaceCoteRouge(cube, compt);
		}
		//cas ligne verticale
		if(cube[4][1][0] == cube[4][1][2]){

			tourner(RED,cube);
			*compt = *compt + 1;
			MiseEnPlaceCoteRouge(cube, compt);
		}
		//cas L
		else{
			int i = 0;
			while(cube[4][0][1] != RED || cube[4][1][0] != RED){
				tourner(RED,cube);
				i = i +1;
			}
			if(i == 2){*compt = *compt + 1;}
			else{*compt = *compt + i;}
			MiseEnPlaceCoteRouge(cube, compt);
		}
	}
	printf("--------------------------FIN CROIX ROUGE-----------------------\n");

}



//Algorithme général permettant de lacer les coins rouges (sans souci de leur place)
void MiseEnPlaceCoinRouge(int cube[6][3][3], int *compt)
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

	*compt = *compt + 8;

}


//applique aux moments opportuns la fonction MiseEnPlaceCoinRouge
void FaireCoinsRouge(int cube[6][3][3], int *compt)
{
	while(cube[4][0][0] != RED || cube[4][2][0] != RED || cube[4][0][2] != RED || cube[4][2][2] != RED)
		{
		//cas pas de coins
		if(cube[4][0][0] != RED && cube[4][2][0] != RED && cube[4][0][2] != RED && cube[4][2][2] != RED)
		{
			
			MiseEnPlaceCoinRouge(cube, compt);
		}

		//cas 2 coins opposés parfait
		if(cube[4][0][0] == RED && cube[4][2][2] == RED )
		{
			
			MiseEnPlaceCoinRouge(cube, compt);
		}

		//cas 2 coins opposés imparfait
		if(cube[4][0][2] == RED && cube[4][2][0] == RED )
		{
			
			tourner(RED, cube);
			*compt = *compt + 1;
			MiseEnPlaceCoinRouge(cube, compt);
		}

		//cas 2 coins alignés
		if((cube[4][0][0] == RED && cube[4][2][0] == RED) ||
			(cube[4][2][0] == RED && cube[4][2][2] == RED) ||
			(cube[4][2][2] == RED && cube[4][0][2] == RED) ||
			(cube[4][0][2] == RED && cube[4][0][0] == RED))
			{
				int i = 0;
				while(cube[4][2][2] != RED && cube[4][0][2] != RED)
				{
					tourner(RED, cube);
				}
				if(i == 2){*compt = *compt + 1;}
				else{*compt = *compt + i;}

				MiseEnPlaceCoinRouge(cube, compt);
			}

		//cas 1 seul coin
		if((cube[4][0][0] == RED && cube[4][2][0] != RED && cube[4][0][2] != RED && cube[4][2][2] != RED) ||
			(cube[4][0][0] != RED && cube[4][2][0] == RED && cube[4][0][2] != RED && cube[4][2][2] != RED) ||
			(cube[4][0][0] != RED && cube[4][2][0] != RED && cube[4][0][2] == RED && cube[4][2][2] != RED) ||
			(cube[4][0][0] != RED && cube[4][2][0] != RED && cube[4][0][2] != RED && cube[4][2][2] == RED))
		
		{
			int i = 0;
			while(cube[4][0][2] != RED)
			{
				tourner(RED,cube);
			}
			if(i == 2){*compt = *compt + 1;}
			else{*compt = *compt + i;}
			MiseEnPlaceCoinRouge(cube, compt);
		}

	}
	printf("--------------------------FIN COINS ROUGE-----------------------\n");
}


//Algorithme de mise en place des coins rouges en conservant la bonne orientation
void MiseEnPlaceCoinsFinal(int cube[6][3][3], int *compt)
{
	tourner(GREEN, cube);
	tourner(GREEN, cube);
	tourner(GREEN, cube);

	tourner(WHITE, cube);

	tourner(GREEN, cube);
	tourner(GREEN, cube);
	tourner(GREEN, cube);

	tourner(YELLOW, cube);
	tourner(YELLOW, cube);

	tourner(GREEN, cube);

	tourner(WHITE, cube);
	tourner(WHITE, cube);
	tourner(WHITE, cube);

	tourner(GREEN, cube);
	tourner(GREEN, cube);
	tourner(GREEN, cube);

	tourner(YELLOW, cube);
	tourner(YELLOW, cube);

	tourner(GREEN, cube);
	tourner(GREEN, cube);

	*compt = *compt + 12;
}


//Appelle MiseEnPlaceCoinsFinal et positionne les coins efficacement
void FaireCoinsFinal(int cube[6][3][3], int *compt)
{
	while(cube[3][2][2] != cube[3][2][0] || cube[5][2][0] != cube[5][0][0] || cube[1][0][0] != cube[1][0][2] || cube[0][0][2] != cube[0][2][2])
	{
		//cas 2coins bien cote a cote
		int i = 0;
		while((cube[5][0][0] != cube[5][2][0]) && i <= 3)
		{
			tourner(RED, cube);
			i = i + 1;
		}
		if(i == 2){*compt = *compt + 1;}
		else{*compt = *compt + i;}
		MiseEnPlaceCoinsFinal(cube, compt);
	
	
		
	}
	int i = 0;
	while(cube[5][2][0] != YELLOW)
	{
		tourner(RED, cube);
		i =  i + 1;
	}
		if(i == 2){*compt = *compt + 1;}
		else{*compt = *compt + i;}
	printf("--------------------------FIN POSITIONNEMENT COINS ROUGES-----------------------\n");
}


//algortihme de mise en place des milieux le cube est alors fini
void MiseEnPlaceMilieuxFinal(int cube[6][3][3], int *compt)
{
	tourner(WHITE, cube);
	tourner(WHITE, cube);

	tourner(RED, cube);

	tourner(GREEN, cube);
	tourner(GREEN, cube);
	tourner(GREEN, cube);

	tourner(BLUE, cube);

	tourner(WHITE, cube);
	tourner(WHITE, cube);

	tourner(BLUE, cube);
	tourner(BLUE, cube);
	tourner(BLUE, cube);

	tourner(GREEN, cube);

	tourner(RED, cube);

	tourner(WHITE, cube);
	tourner(WHITE, cube);

	*compt = *compt + 12;

}


//Appelle la fonctionne MiseEnPlaceMilieuxFinal et termine le cube
void FinirCube(int cube[6][3][3], int *compt)
{
	int cas = 0;
	while(cube[3][2][1] != cube[3][2][2] || cube[5][1][0] != cube[5][2][0] || cube[1][0][1] != cube[1][0][2] || cube[0][1][2] != cube[0][2][2])
	{
		int i = 0;
		while((cube[5][0][0] != cube[5][1][0]) && i <= 3)
		{
			tourner(RED, cube);
			i = i + 1;
			cas = 1;
		}
		if(i == 2){*compt = *compt + 1;}
		else{*compt = *compt + i;}
		MiseEnPlaceMilieuxFinal(cube, compt);
		
	}
	if(cas == 1)
	{
		int i = 0;
		while(cube[3][2][1] != BLUE || cube[5][1][0] != YELLOW || cube[1][0][1] != GREEN || cube[0][1][2] != WHITE)
		{
			tourner(RED, cube);
			i = i + 1;
		}
		if(i == 2){*compt = *compt + 1;}
		else{*compt = *compt + i;}

	}
	printf("--------------------------FIN DU CUBE-----------------------\n");
}

//Vérifie si chaque face du cube est remplie par une seule couleur
int verifie( int CubeSortie[6][3][3]){
	int sortie = 0;
	for(int i = 1; i <= 4; i++){
		if(!(CubeSortie[i][0][0] == CubeSortie[i][2][0] && 
			 CubeSortie[i][0][2] == CubeSortie[i][2][2] &&
			 CubeSortie[i][0][0] == CubeSortie[i][2][2] &&
			 CubeSortie[i][1][0] == CubeSortie[i][2][1] &&
			 CubeSortie[i][0][1] == CubeSortie[i][1][2] &&
			 CubeSortie[i][1][0] == CubeSortie[i][0][0]))
		{
			return 0;
		}
	}
	return 1;
}


//Prends un cube et un tableauSolution, et applique les rotations décrites dans le tableau au cube.
void AppliqueSolution(int cube[6][3][3], int tabSolution[18]){
	int i;
	for (i = 0; i < 18; i++)
	{
		if (tabSolution[i]!=-1)
		{
			tourner(tabSolution[i],cube);
		}
		
	}
	
		
}



//Méthode compléte du SmartSolve

void SmartSolve(int cube[6][3][3], coin tabCoins[8], milieu tabMilieux[12], int* compteur){
	


	printf("---------------------------------------------------\n");
	//--------------------Croix Orange-------------------------------
	FaireCroixOrange(cube,tabMilieux, compteur);

	//--------------------Coins Orange-------------------------------
	FinirFaceOrange(cube, tabCoins, compteur);

	//--------------------Deuxième Couronne-------------------------
	FaireCouronne(cube, tabMilieux,tabCoins, compteur);

	//--------------------Croix Rouge Couronne----------------------
	FaireCroixRouge(cube, compteur);

	//--------------------Coins Rouge-------------------------------
	FaireCoinsRouge(cube, compteur);

	//--------------------Positionnement Coins Rouge----------------
	FaireCoinsFinal(cube, compteur);

	//--------------------Positionnement Milieux Rouge--------------
	FinirCube(cube, compteur);

	printf("---------------------------------------------------\n");
	

}



//Permet de sortir des données sur un fichier texte.
void SortieDonnees(coin tabCoins[8], milieu tabMilieux[12])
{
	
	srand(time(NULL)); //Pour les fonction de mélange
	
	FILE* traj_txt = NULL;
	traj_txt = fopen("Donnees3x3.txt", "w");
	
	
	
	double tempsSmartSolve;

	
	int cube[6][3][3];
		
	int i;
	for (i = 1; i <= 100; i++)
	{
		
		init(cube);
		melangeCube(cube);
		
		int compteur = 0;
		
		//SMART_SOLVE
		
		clock_t SmartSolveClock;
		SmartSolveClock = clock();
		SmartSolve(cube, tabCoins, tabMilieux, &compteur);
		tempsSmartSolve = stopClock(SmartSolveClock);
		printf("le temps est %f\n", tempsSmartSolve);

		fprintf (traj_txt, " cube : %2d      tour : %3d     temps :%f\n",i, compteur, tempsSmartSolve); 
		
	}
	
}


