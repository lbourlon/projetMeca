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

coin rc(int face1,int x1,int y1,int face2,int x2,int y2, int face3, int x3, int y3);

coin RechercherCoin(int cube[6][2][2],coin tab[8], int couleur1, int couleur2, int couleur3);
char* TrouveCasCoin(int cube[6][2][2], coin co);
void FaireCoinOrange(int cube[6][2][2],coin co, coin tabCoins[8]);

void FaireFaceOrange(int cube[6][2][2], coin tabCoins[8]);