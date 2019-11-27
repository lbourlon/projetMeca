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


//Fonctions milieux
milieu rm(int face1,int x1,int y1,int face2,int x2,int y2);
milieu RechercherMilieu(int cube[6][3][3],milieu tab[12], int couleur1, int couleur2);
char* TrouveCasMilieu(int cube[6][3][3], milieu mil);
void FaireBrasCroix(int cube[6][3][3],milieu mil25, milieu tabMilieux[12]);
void FaireCroixOrange(int cube[6][3][3],milieu tab[12]);


//Fonctions coin
coin rc(int face1,int x1,int y1,int face2,int x2,int y2, int face3, int x3, int y3);
coin RechercherCoin(int cube[6][3][3],coin tab[8], int couleurimportante, int couleur2, int couleur3);
char* TrouveCasCoin(int cube[6][3][3], coin co);
void FaireCoinOrange(int cube[6][3][3],coin co, coin tabCoins[8]);
void FinirFaceOrange(int cube[6][3][3], coin tabCoins[8]);


//Fonctions couronne
char* TrouveCasCouronne(int cube[6][3][3], milieu mil);
void FairePartieCouronne(int cube[6][3][3], milieu mil, milieu* tabMilieux);
void FaireCouronne(int cube[6][3][3],milieu tab[12]);


void MiseEnPlaceCoteRouge(int cube[6][3][3]);
void FaireCroixRouge(int cube[6][3][3]);
void MiseEnPlaceCoinRouge(int cube[6][3][3]);
void FaireCoinsRouge(int cube[6][3][3]);
void MiseEnPlaceCoinsFinal(int cube[6][3][3]);
void FaireCoinsFinal(int cube[6][3][3]);
void MiseEnPlaceMilieuxFinal(int cube[6][3][3]);
void FinirCube(int cube[6][3][3]);




//BRUTEFORCE
int verifie( int CubeSortie[6][3][3]);
void AppliqueSolution(int cube[6][3][3], int tabSolution[18]);
int BruteForce(int cube[6][3][3]);
void printTabSolution(int tabSolution[14]);