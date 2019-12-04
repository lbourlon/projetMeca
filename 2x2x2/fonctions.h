
void init(int tab[6][2][2]);
void affiche(int tab[6][2][2]);
void tourner(int face, int tab[6][2][2]);
void mtourner(int face, int tab[6][2][2]);
void melangeCube(int tab[6][2][2]);

int compare(int cube1[6][2][2], int cube2 [6][2][2]);

int* copieCube(int CubeACopier[6][2][2], int CubeSortie[6][2][2]);

void randTour(int cube[6][2][2]);

int verifie( int CubeSortie[6][2][2]);


int CompteMouvementBF(int *TabSolution);


//------------------------------------------TIMING----------------------------------------------------------

/* A exécuter après la fonction startClock pour mesurer un temps.
 * 
 * Prends en paramètre un objet clock avec le temps de début (retourné par startClock)
 * et calcule le temps passé entre les deux instants. La fonction retourne ensuite le double temps.
 */
double stopClock(clock_t tempsDebut);


