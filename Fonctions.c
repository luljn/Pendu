#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include"Fonctions.h"



int tailleMot(char motSecret[]){
	
	int nombreLettres = 0;
	int i = 0;
	
	for (i = 0 ; motSecret[i] != '\0' ; i++){
		
		nombreLettres++;
	}
	return nombreLettres;
}



void initTableau(int *lettreTrouvee, int taille){
	
	int i = 0;
	
	for (i = 0 ; i < taille ; i++){
		
		lettreTrouvee[i] = 0; 
	}
}



int winGame(int *lettreTrouvee, int nombreLettres){
	
	int i = 0;
	int joueurGagne = 1;
	
	for(i = 0 ; i < nombreLettres ; i++){
		
		if (lettreTrouvee[i] == 0){
			
			joueurGagne = 0;
		}
	    
	}
	
	return joueurGagne;
}



char lireCaractere(){
	
	char caractere = 0;
	
	caractere = getchar(); // On lit le premier caractère 
	caractere = toupper(caractere); // On met la lettre en Majuscule si elle ne l'est pas déjà 

	// On lit les autres caractères mémorisés un à un jusqu'au \n (pour les effacer)
	while(getchar() != '\n');
	
	return caractere; // On retourne la premier caractère qu'on a lu
	
}	



int rechercheLettre(char lettre, char motSecret[], int *lettreTrouvee){
	
	int i = 0;
	int bonneLettre = 0;
	
	// On parcours motSecret pour vérifier si la lettre proposée y est
	
	for(i = 0 ; motSecret[i] != '\0' ; i++ ){
		
		if(lettre == motSecret[i]){ // Si la lettre y est
		
			bonneLettre = 1; // On mémorise que c'est une bonne lettre
			lettreTrouvee[i] = 1; // On met 1 à la case du tableau de booléens correspondant à la lettre actuelle
		}
	}
	
	return bonneLettre;
		
}



void ModeDemploie(){
	
	system("cls");
	printf("\n\n\t\tMODE D'EMPLOIE :\n\n\n\n");
	printf("\t\tCeci est le jeu du Pendu !\n");
	printf("\t\tLe but est de trouver un mot secret en un minimum de tentatives.\n");
	printf("\t\tPour jouer, vous devez proposez une lettre au fur et a mesure jusqu'a trouver le fameux \"mot secret\".\n");
	printf("\t\tToutes vos lettres doivent etre des MAJUSCULES !\n\n\n");
	printf("\t\tBonne Chance :) !\n\n\t\t");
	
}



void AfficherMenu(){
	
	printf("\n\n");
	printf("\t\t##        #######           #######    #######  ##        ##  #######    ##      ##\n");                                                                                                                         
	printf("\t\t##        ##                ##    ##   ##       ###       ##  ##      #  ##      ##\n");                                                                                                       
	printf("\t\t##        ##                ##    ##   ##       ##  #     ##  ##      #  ##      ##\n");                                                                                                              
	printf("\t\t##        ####              #######    ####     ##    #   ##  ##      #  ##      ##\n");                                                                                                          
	printf("\t\t##        ##                ##         ##       ##      # ##  ##      #  ##      ##\n");                                                                                                               
	printf("\t\t##        ##                ##         ##       ##       ###  ##      #  ##      ##\n");                                                                                                                 
	printf("\t\t########  ######            ##         #######  ##        ##  ########   ##########\n");   
	
	printf("\n\n\n\t\tBIENVENUE DANS LE JEU DU PENDU !!!!!!\n\n\n");
	printf("\n\n\t\t\t\t\t\t****_MENU_**** \n");
	printf("\n\t\t\t\t\t\t1- Nouvelle Partie.\n");
	printf("\n\t\t\t\t\t\t2- Mode d'emploie (Comment jouer).\n");
	printf("\n\t\t\t\t\t\t3- Quitter le jeu. \n\n");
	
}

                                                                                                                               

void Pendu(){
	
	printf("\n\n");
	printf("\t\t\t\t\t             _______________   \n");
	printf("\t\t\t\t\t                    ||         \n");                                                                                                                    
	printf("\t\t\t\t\t                    ||         \n");                                                                                                                    
	printf("\t\t\t\t\t                    ||         \n");                                                                                                                         
	printf("\t\t\t\t\t                    ||         \n");                                                                                                                           
	printf("\t\t\t\t\t                    ||         \n");                                                                                                                     
    printf("\t\t\t\t\t                    ||         \n");                                                                                                                          	
	printf("\t\t\t\t\t                    ||         \n");                                                                                                        
	printf("\t\t\t\t\t                  _(  )_       \n");                                                                                                                  
    printf("\t\t\t\t\t                 /(    )\\     \n");                                                                                                                           	
	printf("\t\t\t\t\t                /(      )\\    \n");                                                                                                                     
	printf("\t\t\t\t\t                (________)     \n");                                                                                                                           
	printf("\t\t\t\t\t                   |  |        \n");                                                                                                                        
	printf("\t\t\t\t\t                   |  |        \n");
	printf("\t\t\t\t\t                   /  /        \n");                                                                                                                     
		                                                                                                                                                                                
}
