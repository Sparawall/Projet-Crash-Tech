#include "../headers/lecteur_csv.h"







CSV* initCSV(FILE* fichier, int nb_colone){
	CSV* csv = malloc(sizeof(CSV));
	if(csv == NULL){
		printf("ERREUR D'ALLOCATION!!");
		exit(4);
	}
	
	
	csv->ligne = malloc(sizeof(char)*LONGEUR_LIGNE_MAX);
	if(csv->ligne == NULL){
		printf("ERREUR D'ALLOCATION!!");
		exit(4);
	}
	csv->noms_colone = malloc(sizeof(char*) * nb_colone);
	if(csv->noms_colone == NULL){
		printf("ERREUR D'ALLOCATION!!");
		exit(4);
	}
	for(int i = 0; i<nb_colone; i++){
		csv->noms_colone[i] = NULL;
	}
	
	csv->cellules = calloc(nb_colone, sizeof(int));
	if(csv->cellules == NULL){
		printf("ERREUR D'ALLOCATION!!");
		exit(4);
	}
	
	csv->fichier = fichier;
	csv->nb_colone = nb_colone;
	
	
	return csv;
}


/*
LigneCSV initLigneCSV(FILE* fichier, int nb_cellule){
	CSV csv;
	csv.noms_colone = malloc(sizeof(char*) * nb_colone);
	if(csv.noms_colone == NULL){
		printf(ERREUR D'ALLOCATION!!);
		exit(4);
	}
	csv.fichier = fichier;
	csv.nb_colone = nb_colone;
	
	
	return csv;
}*/

















CSV* csvOuvreLecture(char* nom){
	//ACCES_DOSSIER_CSV();
	FILE* fichier = fopen(nom, "r");
	
	
	
	if(fichier == NULL){
		printf("ATTENTION! le fichier n'existe pas, avez-vous données le bon nom?\n");
		exit(1);
	}
	CSV* fichier_csv = initCSV(fichier, NB_COLONE);
	
	
	
	
	
	//on défini le noms des colones
	if(csvLecteurLigne(fichier_csv)==EOF){
		printf("ERREUR, le fichier csv est vide!");
		exit(1);
	}
	if(ligneAstr(fichier_csv)!=fichier_csv->nb_colone){
		printf("Toute les valeur n'ont pas put etre récupérere, erreur dans le csv?");
		exit(1);
	}
	
	return fichier_csv;
}




int csvFerme(CSV* fichier_csv){
	int retour = fclose(fichier_csv->fichier);
	if(retour != 0){
		printf("Erreur lors de la fermeture du fichier!\n l'erreur n'est pas urgente, le programme continue\n");
	}
	
	return retour;
}

















int csvLecteurLigne(CSV* fichier_csv){
	//lis la ligne entière et la stock en chaine de caractère
	int retour = 0;
	

	if(fichier_csv == NULL){
		printf("Erreur dans les parametre, il n'y a pas le fichier csv\n");
	}else{
		
		if(fichier_csv->fichier == NULL){
			printf("Impossible, fichier non trouvé!\n");
		}else{
			retour = fscanf(fichier_csv->fichier, "%s", fichier_csv->ligne);
			if(retour == 0){
				printf("Erreur la ligne lu est erroner\n");
				exit(1);
			}
		}
		
	}
	return retour;
}




int ligneAint(CSV* fichier_csv){
	int retour = 0;
	if(fichier_csv == NULL){
		printf("Erreur dans les parametre, il n'y a pas le fichier csv\n");
	}else{
		if(fichier_csv->cellules == NULL || fichier_csv->ligne == NULL){
			printf("Impossible, aucune zone de recepteur/envoyeur!\n");
		}else{
			int i = 0;
			while(retour<fichier_csv->nb_colone){
				fichier_csv->cellules[retour] = 0;
				while (fichier_csv->ligne[i] != ';' && fichier_csv->ligne[i] != '\n' && fichier_csv->ligne[i] != '\0'){
					fichier_csv->cellules[retour] *= 10;
					fichier_csv->cellules[retour] += fichier_csv->ligne[i] - '0';
					i++;
				}
				i++;
				retour++;
			}
		}
	}
	return retour;
}






int ligneAstr(CSV* fichier_csv){
	int retour = 0;
	if(fichier_csv == NULL){
		printf("Erreur dans les parametre, il n'y a pas le fichier csv\n");
	}else{
		if(fichier_csv->noms_colone == NULL || fichier_csv->ligne == NULL){
			printf("Impossible, aucune zone de recepteur/envoyeur!\n");
		}else{
			char* text_actuel;
			
			for(int i = 0; i<fichier_csv->nb_colone; i++){
				if(i==0){
					text_actuel = strtok(fichier_csv->ligne, ";");
				}else{
					text_actuel = strtok(NULL, ";");
				}
				
				

				if(fichier_csv->noms_colone[i] != NULL){
					free(fichier_csv->noms_colone[i]);
					fichier_csv->noms_colone[i] = NULL;
				}

				fichier_csv->noms_colone[i] = malloc(sizeof(char)* (strlen(text_actuel)+1));
				if(fichier_csv->noms_colone[i] == NULL){
					printf("ERREUR D'ALLOCATION!!");
					exit(4);
				}
				
				
				
				strcpy(fichier_csv->noms_colone[i], text_actuel);
				retour ++;
			}
		}
	}
	return retour;
}

























/*
int main(){
//exemple d'utilisation du fichier:

	//pour ouvrir le fichier
	CSV* fichier = csvOuvreLecture("../../../donne CSV/cy_crash_tech_small2_shuffled.csv");
	
	
	
	//on peut directement retrouver le nombre de colone et le noms de celle-ci
	for(int i = 0; i<fichier->nb_colone; i++){
		printf("%12s			%i\n", fichier->noms_colone[i], fichier->cellules[i]);
	}
	
	
	
	//lorsque toute les ligne seront lu csvLecteurLigne() retournera EOF
	while(csvLecteurLigne(fichier) != EOF){
		printf(" \n");
		ligneAint(fichier);//permet d'enregistrer la ligne lu dans un tableau de int
		for(int i = 0; i<fichier->nb_colone; i++){
			printf("%12s			%i\n", fichier->noms_colone[i], fichier->cellules[i]);//fichier->cellules est le tableau qui permet d'acceder a ces valeur
		}
	}
	
	//pour fermer le fichier une fois qu'on en a plus besoins
    csvFerme(fichier);
	
	
	
	
	return 0;
}
*/