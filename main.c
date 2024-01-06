#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include"Fonctions.h"
#include"dico.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(){
	
	char lettre = 0; // Stocke la lettre proposé par l'utilisateur 
//	char motSecret[100] = {0};
//	char *monPointeur = &motSecret; // c'est le mot à trouver
	char motSecret[] = "ANTHROPOCENTRISME"; // C'est le mot à trouver
     
//	piocherMot(monPointeur);    

	int coupsRestants = 10; // Compteur des coups restants (0 = mort)
	int nombreLettres = tailleMot(motSecret);
	int *lettreTrouvee = NULL; // Tableau de booléens. Chaque case correspond à une lettre du mot
	int i = 0, a = 0;
//	long y, taille;
	
	lettreTrouvee = malloc(nombreLettres*sizeof(int));
	initTableau(lettreTrouvee, nombreLettres);
	
	system("color 09");
	AfficherMenu();
	printf("\n\t\tVotre choix :  ");
	scanf("%d", &a);
	
	switch(a){
		
		case 1:
			system("cls");
			printf("\n\n\t\t\t\t\t\tC'est parti :) !");
			while(coupsRestants > 0 && !winGame(lettreTrouvee, nombreLettres)){
			
				printf("\n\n\n\t\t\tIl vous reste %d coups a jouer.", coupsRestants);
				printf("\n\t\t\tQuel est le mot secret ?\t");
				
				// On affiche le mot secret en masquant les lettres non trouvées  Exemple: *A**OU
				
				for (i = 0 ; i < nombreLettres ; i++){
					
					if (lettreTrouvee[i]){
						printf("%c", motSecret[i]);
					}
					else{
						printf("*");
					}
				}
		        
				printf("\n\t\t\tProposez une lettre :\t");
				lettre = lireCaractere();
				system("cls");
				
				// Si ce n'est pas la bonne lettre
				
				if(!rechercheLettre(lettre, motSecret, lettreTrouvee)){
					
					coupsRestants--;	
				}		
			}
			
			if (winGame(lettreTrouvee, nombreLettres)){
				
				printf("\n\n\n\t\t\tBravo , \"%s\" est bien le mot secret :) !\n\n\n", motSecret);
				printf("\n\t\t\t\t");
				system("pause");
			}
			else{
				
				printf("\n\n\n\t\t\tPlus de coups restants !");
				printf("\n\n\n\t\t\tOn vous a Pendu !!!!!!");
				Pendu();
				printf("\n\n\t\t\t\tPerdu , le mot secret etait \"%s\" :( !\n\n\n", motSecret);
			    printf("\n\t\t\t\t");
				system("pause");
			}
			
	        break;
	        return 0;
	        
		case 2:
			ModeDemploie();
			system("pause");
			system("cls");
			main();
			break;
		
		case 3:
			exit(0);
			return 0;
			break;
		
		default:
			printf("\n\t\tChoix non disponible :( !\n\n");
			system("pause");
			system("cls");
			main();
			break;
	}
	
	free(lettreTrouvee);
//	free(motSecret);
	
	return 0;
	
}
