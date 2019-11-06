#include <stdio.h>
// Résolution faite en començant par la face orange

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


//Prend les coordonnées d'un milieu et les remplie dans un milieu
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
	int mil25, mil21, mil20, mil23;
	mil25 = RechercherMilieu(cube,tab,ORANGE, GREEN);
	
	char* cas = "";
	
	//Si cas FACE
	if(mil25.coord1.face == ORANGE){
		//cas parfait:
		if(mil25.coord1.x == 1 && mil25.coord1.y == 0){
			cas = "parfait";
		} else {
		//cas imparfait --> cas dessous
			cas = "imparfait";
			tourner(mil25.coord2.face, cube);
			tourner(mil25.coord2.face, cube);
			
		}
	}
	
	//Si cas CÔTÉ
	if (mil25.coord1.face == YELLOW || mil25.coord1.face == GREEN ||
		mil25.coord1.face == WHITE  || mil25.coord1.face == BLUE){
		
			
	}
		
	
	
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












