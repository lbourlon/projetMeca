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

//SMART SOLVE
coin rc(int face1,int x1,int y1,int face2,int x2,int y2, int face3, int x3, int y3);
coin RechercherCoin(int cube[6][2][2],coin tab[8], int couleur1, int couleur2, int couleur3);
char* TrouveCasCoin(int cube[6][2][2], coin co);
void FaireCoinOrange(int cube[6][2][2],coin co, coin tabCoins[8], int *compt);
void FaireFaceOrange(int cube[6][2][2], coin tabCoins[8], int *compt);
void MiseEnPlaceCoinRouge(int cube[6][2][2], int *compt);
void FaireCoinsRouge(int cube[6][2][2], int *compt);
void MiseEnPlaceCoinsFinal(int cube[6][2][2], int *compt);
void FaireCoinsFinal(int cube[6][2][2], int *compt);
void SmartSolve(int cube[6][2][2], coin tabCoins[8], int *compteur);


//BRUTE FORCE
int* BruteForce(int cube[6][2][2]);
void AppliqueSolution(int cube[6][2][2], int tabSolution[14]);
void printTabSolution(int tabSolution[14]);



//AUTRES
void SortieDonnees(coin tabCoins[8], int n);
