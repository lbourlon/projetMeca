
void init(int tab[6][2][2]);
void affiche(int tab[6][2][2]);
void tourner(int face, int tab[6][2][2]);
void mtourner(int face, int tab[6][2][2]);
void melangeCube(int tab[6][2][2]);

int compare(int cube1[6][2][2], int cube2 [6][2][2]);

int* copieCube(int CubeACopier[6][2][2], int CubeSortie[6][2][2]);

void randTour(int cube[6][2][2]);

int *BruteForce(int cube[6][2][2]);

void AppliqueSolution(int cube[6][2][2], int tabSolution[14]);
void printTabSolution(int tabSolution[14]);


//TIMING

/* A exécuter avant la fonction endClock pour mesurer un temps.
 *
 * Retourne un objet clock avec l'horaire de début.
 */
clock_t startClock();

/* A exécuter après la fonction startClock pour mesurer un temps.
 * 
 * Prends en paramètre un objet clock avec le temps de début (retourné par startClock)
 * et calcule le temps passé entre les deux instants. La fonction retourne ensuite le double temps.
 */
double endClock(clock_t tempsDebut);

