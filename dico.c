#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"dico.h"



int nombreAleatoire(int nombreMax){
	
	srand(time(NULL));
	return(rand() % nombreMax);
}



int piocherMot(char *motPioche){
	
	FILE *dico = NULL; // Le pointeur de fichier qui va contenir le fichier de mots secrets. 
    
    int nombresMots = 0 /* nombre de mots du fichier Dico */, numMotChoisi = 0 /* le num de la ligne du mot choisit */ , i = 0 /* compteur */;
    int caractereLu = 0;
    
    dico = fopen("Dico.txt", "r");
    
    if(dico == NULL) {// Si l'ouverture du fichier a échouée.

    	printf("Impossible de charger le dictionnaire de mots :( !");
    	return 0;
    }

    // On compte le nombre de mots dans le fichier (on compte les "entrées" \n).
    do{
    	
    	caractereLu = fgetc(dico);
    	if(caractereLu == '\n'){
    		
    		nombresMots++;
		}
	}while(caractereLu != EOF) ;
	
	numMotChoisi = nombreAleatoire(nombresMots); // On prend un mot au hasard.
	
	// On recommence la lecture du fichier jusqu'à arriver au bon mot.
	rewind(dico);
	while(numMotChoisi > 0){
		
		caractereLu = fgetc(dico);
		if(caractereLu == '\n'){
			
			numMotChoisi--;
		}
	}
	
	fgets(motPioche, 100, dico); // On récupère le mot choisi.
	motPioche[strlen(motPioche) - 1] = '\0'; // On enlève le "\n" 
	
	fclose(dico);
	
	return 1; // Tout s'est bien passé.
}
