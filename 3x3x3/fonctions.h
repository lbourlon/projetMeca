void init(int cube[6][3][3]);
void affiche(int cube[6][3][3]);
void tourner(int face, int cube[6][3][3]);
void randTour(int cube[6][3][3]);
void melangeCube(int cube[6][3][3]);
void copie(int cubeACopier[6][3][3], int cubeAColler[6][3][3]);

//Fonctions du temps
double stopClock(clock_t tempsDebut);
