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


milieu rm(int face1,int x1,int y1,int face2,int x2,int y2);
milieu RechercherMilieu(int cube[6][3][3],milieu tab[12], int couleur1, int couleur2);
void FaireCroixOrange(int cube[6][3][3],milieu tab[12]);
char* TrouveCasMilieu(int cube[6][3][3], milieu mil);
void FaireBrasCroix(int cube[6][3][3],milieu mil25, milieu tabMilieux[12]);



coin rc(int face1,int x1,int y1,int face2,int x2,int y2, int face3, int x3, int y3);
