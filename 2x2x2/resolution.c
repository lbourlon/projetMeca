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

/* Les structures suivantes définissent le coublon coin, 
 * ce dernier, constitué de 3 coordonnée, pour le repérer dans le tableau cube
 * les objets coord repèrent les couleurs indiviuelles dans le tableau grace à face, x et y.
 * face donne la face où se retrouve la couleur, x et y donnent la coordonnée dans la face.
 */ 
 
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



/* Abréviation de RemplirCoin
 * Place les informations du cublon dans le cublon.
 */
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

/* Recherche l'emplacement du cublon coin contenant les couleurs 1 et 2 et 3
 * Et retourne ce coin avec les coordonées respectives aux couleurs
 * Il rend toujours la couleur 1 sur coord1, les autres importent moins
 */
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
	
	printf("vous vous êtes trompés de couleurs \n");
	return	rc(0,0,0,0,0,0,0,0,0);
}

/* Les cas nous donnent des informations sur la configuration du cube
 * suivant le cas, on utiliseras des algorithmes différents dans la fonction faireCoinsOrange
 */
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

//Place le coin orange donnée en paramètre dans son bon emplacement.
void FaireCoinOrange(int cube[6][2][2],coin co, coin tabCoins[8],int *compt){
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
			*compt = *compt + 1;

			coTemp = RechercherCoin(cube, tabCoins, ORANGE, couleur2, couleur3);
			casTemp = TrouveCasCoin(cube, coTemp);
			if(casTemp == "cote_bas_imparfait"){
				mtourner(RED, cube);
				mtourner(RED, cube);
				mtourner(co.coord2.face, cube);
				mtourner(co.coord2.face, cube);
				mtourner(co.coord2.face, cube);
				*compt = *compt + 3;
				
			} else {
				mtourner(co.coord2.face, cube);
				mtourner(co.coord2.face, cube);
				mtourner(RED, cube);
				mtourner(RED, cube);
				mtourner(co.coord2.face, cube);
				*compt = *compt + 5;
				
			}
		
		
		}
		
	
		//devient coté_bas
		if(cas == "cote_haut")
		{

			mtourner(co.coord1.face, cube);
			*compt = *compt + 1;
			coTemp = RechercherCoin(cube, tabCoins, ORANGE, couleur2, couleur3);
			casTemp = TrouveCasCoin(cube, coTemp);
			if(casTemp == "cote_bas_imparfait" ||  casTemp == "cote_bas_parfait" ){
				mtourner(RED, cube);
				mtourner(RED, cube);
				mtourner(co.coord1.face, cube);
				mtourner(co.coord1.face, cube);
				mtourner(co.coord1.face, cube);
				*compt = *compt + 3;
				
			} else {
				mtourner(co.coord1.face, cube);
				mtourner(co.coord1.face, cube);
				mtourner(RED, cube);
				mtourner(RED, cube);
				mtourner(co.coord1.face, cube);
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
				mtourner(co.coord2.face, cube);
				*compt = *compt + 1;

				coTemp = RechercherCoin(cube, tabCoins, ORANGE, couleur2, couleur3);
				casTemp = TrouveCasCoin(cube, coTemp);
				if(casTemp == "cote_bas_imparfait"){
					mtourner(RED, cube);
					mtourner(RED, cube);
					mtourner(co.coord2.face, cube);
					mtourner(co.coord2.face, cube);
					mtourner(co.coord2.face, cube);
					*compt = *compt + 3;
				} else {
					mtourner(co.coord2.face, cube);
					mtourner(co.coord2.face, cube);
					mtourner(RED, cube);
					mtourner(RED, cube);
					mtourner(co.coord2.face, cube);
					*compt = *compt + 5;
				}
				
			} else {
				mtourner(RED, cube);
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
				mtourner(RED, cube);
				*compt = *compt + 1;
				coTemp = RechercherCoin(cube, tabCoins, ORANGE, couleur2, couleur3);
				casTemp = TrouveCasCoin(cube, coTemp);

				
			}
			

		}
		
		if(cas == "cote_bas_parfait")
		{
			mtourner(co.coord1.face, cube);
			*compt = *compt + 1;
			coTemp = RechercherCoin(cube, tabCoins, ORANGE, couleur2, couleur3);
			casTemp = TrouveCasCoin(cube, coTemp);
			
			if(casTemp == "cote_bas_imparfait"){
				mtourner(RED, cube);
				*compt = *compt + 1;
				coTemp2 = RechercherCoin(cube, tabCoins, ORANGE, couleur2, couleur3);
				casTemp2 = TrouveCasCoin(cube, coTemp2);
				if(casTemp2 != "cote_bas_parfait"){
					mtourner(RED, cube);
					mtourner(RED, cube);
					*compt = *compt + 2;
				}
				
				mtourner(co.coord1.face, cube);
				mtourner(co.coord1.face, cube);
				mtourner(co.coord1.face, cube);
				*compt = *compt + 1;
				
				 
			} else {
				mtourner(co.coord1.face, cube);
				mtourner(co.coord1.face, cube);
				*compt = *compt + 2;
				
				coTemp2 = RechercherCoin(cube, tabCoins, ORANGE, couleur2, couleur3);
				casTemp2 = TrouveCasCoin(cube, coTemp2);
				while(casTemp2 != "cote_bas_parfait"){
					mtourner(RED, cube);
					*compt = *compt + 1;
					coTemp2 = RechercherCoin(cube, tabCoins, ORANGE, couleur2, couleur3);
					casTemp2 = TrouveCasCoin(cube, coTemp2);
				}
				
				mtourner(co.coord1.face, cube);
				*compt = *compt + 1;
				
			}
			
		}
		
	co = RechercherCoin(cube,tabCoins,ORANGE, couleur2, couleur3);
	cas = TrouveCasCoin(cube, co);

	}
	//printf("===================FIN DU COIN================\n");

}

//Appelle FaireCoinOrange, pour résouder les quatre coins de la face orange
void FaireFaceOrange(int cube[6][2][2], coin tabCoins[8], int *compt){
	coin co210, co215, co253, co230;
	
	co210 = RechercherCoin(cube, tabCoins, 2, 1, 0);
	FaireCoinOrange(cube, co210, tabCoins, compt); 
	affiche(cube);

	co215 = RechercherCoin(cube, tabCoins, 2, 1, 5);
	FaireCoinOrange(cube, co215, tabCoins, compt);
	affiche(cube);
	
	co253 = RechercherCoin(cube, tabCoins, 2, 5, 3);
	FaireCoinOrange(cube, co253, tabCoins, compt);
	affiche(cube);
	
	co230 = RechercherCoin(cube, tabCoins, 2, 3, 0);
	FaireCoinOrange(cube, co230, tabCoins, compt);
	affiche(cube);
}

// Algorithme repris dans FaireCoinsRouge.
void MiseEnPlaceCoinRouge(int cube[6][2][2], int *compt)
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

	*compt = *compt + 8;

}

/* Utilise MiseEnPlaceCoinRouge pour placer les coins rouges une fois la face orange bien faite.
 * Oriente le cube pour appliquer de manière pertinente l'algorithme.
 * FaireCoinRouge, place oriente les cublons coins mais sans les placer.
 */
void FaireCoinsRouge(int cube[6][2][2], int *compt)
{
	while(cube[4][0][0] != RED || cube[4][1][0] != RED || cube[4][0][1] != RED || cube[4][1][1] != RED)
		{
		//cas pas de coins
		if(cube[4][0][0] != RED && cube[4][1][0] != RED && cube[4][0][1] != RED && cube[4][1][1] != RED)
		{

			MiseEnPlaceCoinRouge(cube, compt);
		}

		//cas 2 coins opposés parfait
		if(cube[4][0][0] == RED && cube[4][1][1] == RED )
		{

			MiseEnPlaceCoinRouge(cube, compt);
		}

		//cas 2 coins opposés imparfait
		if(cube[4][0][1] == RED && cube[4][1][0] == RED )
		{

			mtourner(RED, cube);
			*compt = *compt + 1;
			MiseEnPlaceCoinRouge(cube, compt);
		}

		//cas 2 coins alignés
		if((cube[4][0][0] == RED && cube[4][1][0] == RED) ||
			(cube[4][1][0] == RED && cube[4][1][1] == RED) ||
			(cube[4][1][1] == RED && cube[4][0][1] == RED) ||
			(cube[4][0][1] == RED && cube[4][0][0] == RED))
			{

				while(cube[4][1][1] != RED && cube[4][0][1] != RED)
				{
					mtourner(RED, cube);
					*compt = *compt + 1;
				}
				MiseEnPlaceCoinRouge(cube, compt);
			}

		//cas 1 seul coin
		if((cube[4][0][0] == RED && cube[4][1][0] != RED && cube[4][0][1] != RED && cube[4][1][1] != RED) ||
			(cube[4][0][0] != RED && cube[4][1][0] == RED && cube[4][0][1] != RED && cube[4][1][1] != RED) ||
			(cube[4][0][0] != RED && cube[4][1][0] != RED && cube[4][0][1] == RED && cube[4][1][1] != RED) ||
			(cube[4][0][0] != RED && cube[4][1][0] != RED && cube[4][0][1] != RED && cube[4][1][1] == RED))
		
		{
			while(cube[4][0][1] != RED)
			{
				mtourner(RED,cube);
				*compt = *compt + 1;
			}
			MiseEnPlaceCoinRouge(cube, compt);
		}
		
	}

}

//Algorithme repris dans FaireCoinsCoinsFinal.
void MiseEnPlaceCoinsFinal(int cube[6][2][2], int *compt)
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

	*compt = *compt + 12;
	
}

/* Similairement à FaireCoinsRouge, reprend un algorithme de base
 * La fonction oriente les coins sur la face rouge. 
 */
void FaireCoinsFinal(int cube[6][2][2], int *compt)
{
	while(cube[3][1][1] != cube[3][1][0] || cube[5][1][0] != cube[5][0][0] || cube[1][0][0] != cube[1][0][1] || cube[0][0][1] != cube[0][1][1])
	{
		int i = 0;
		while((cube[5][0][0] != cube[5][1][0]) && i <= 3)
		{
			mtourner(RED, cube);
			i = i + 1;
		}
		if(i == 2){compt = compt + 1;}
		else{if(i != 3){*compt = *compt + i;}}
	
		MiseEnPlaceCoinsFinal(cube, compt);
		affiche(cube);
	
	}

	while(cube[3][1][1] != cube[3][0][0])
	{
		mtourner(RED, cube);
		*compt = *compt + 1;

	}
	
	
}

//Applique les fonctions de résolution pour la méthode SmartSolve
void SmartSolve(int cube[6][2][2], coin tabCoins[8], int *compteur)
{
	FaireFaceOrange(cube, tabCoins, compteur);	
	
	FaireCoinsRouge(cube, compteur);

	FaireCoinsFinal(cube, compteur);
	affiche(cube); //affichage cube final
}


//Prend un cube et le tableauSolution retourné par BruteForce, et ensutie applique les rotations décrites dans le tableau au cube.
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

/* La fonction prend un cube mélangé en paramètre et trouve la solution la plus éfficace en terme de coups.
 * Sachant que le nombre de dieu pour le 2x2x2 est 14, on 14 boucles imbriquées pour chaque mouvement possible.
 * La fonction essaye toute les possibilités en ordre croissant de nombre de tours, rendant ainsi la solution la plus éfficace.
 * Et renvoie un tableauSolution des faces à tourner suivant l'ordre à appliquer les rotations.
 */
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

//Prend un tableaux Solution retourné par BruteForce, ce dernier qui contient des données lisibles par la machine (contenant des 0,1,2,3,4,5 et -1)
// et affiche les cotés a tourner par l'utilisateur.
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



/* Fonction permettant de récuperer le temps de calcul et le nombre de tours éfectués pour les fonctions BF et SS.
 * Cette fonction mélange n fois le cube et rend n points de données.
 */
void SortieDonnees(coin tabCoins[8], int n){
	
	
	
	FILE* traj_txt = NULL;
	traj_txt = fopen("Donnees2x2.txt", "w");
	
	int cube1[6][2][2];
	int cube2[6][2][2];

	


		
	for(int k = 0; k <= n; k++)
	{
		printf("tour %d\n", k);
		
		double tempsSmartSolve;
		double tempsBruteForce;
		int compteur1 = 0;
		int compteur2 = 0;
		
		init(cube1);
		melangeCube(cube1);
		copieCube(cube1, cube2);
		
		
		
		//SMART_SOLVE
		clock_t SmartSolveClock = clock();
		SmartSolve(cube1, tabCoins, &compteur1);
		tempsSmartSolve = stopClock(SmartSolveClock);
		
		
		
		
		//BRUTE_FORCE
		/*
		int* tabSolution;
		clock_t BruteForceClock = clock();
		tabSolution = BruteForce(cube2);
		tempsBruteForce = stopClock(BruteForceClock);
		
		compteur2 = CompteMouvementBF(tabSolution);
		*/
		fprintf (traj_txt, " cube : %d      tour : %d     temps :%f", k, compteur1, tempsSmartSolve); 
		//fprintf (traj_txt, " 	     		tour : %3d     temps :%f\n", compteur2, tempsBruteForce); 
		
		
	}
	
}

