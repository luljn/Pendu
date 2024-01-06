#ifndef Fonctions_h
#define Fonctions_h



char lireCaractere();
int rechercheLettre(char lettre, char motSecret[], int *lettreTrouvee);
int tailleMot(char motSecret[]);
int winGame(int *lettreTrouvee, int nombreLettres);
void initTableau(int *lettreTrouvee, int taille);
void ModeDemploie();
void AfficherMenu();
void Pendu();



#endif
