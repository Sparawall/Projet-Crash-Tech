#include "../headers/reader_csv.h"






/*
CSV initCSV(FILE* fichier, int nb_colone){
	CSV csv;
	csv.noms_colone = malloc(sizeof(char*) * nb_colone);
	if(csv.noms_colone == NULL){
		printf(ERREUR D'ALLOCATION!!);
		exit(4);
	}
	csv.fichier = fichier;
	csv.nb_colone = nb_colone;
	
	
	return csv;
}
*/

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

















FILE* csvOuvreLecture(char* nom){
	ACCES_DOSSIER_CSV();
	FILE* fichier = fopen(nom, "r");
	
	if(fichier == NULL){
		printf("ATTENTION! le fichier n'existe pas, avez-vous données le bon nom?\n");
		exit(1);
	}
	
	return fichier;
}




int csvFerme(FILE* fichier){
	int retour = fclose(fichier);
	if(retour != 0){
		printf("Erreur lors de la fermeture du fichier!\n l'erreur n'est pas urgente, le programme continue\n");
	}
	
	return retour;
}



















char* csvLecteurLigne(FILE* fichier){
	char* ligne = NULL;
	if(fichier == NULL){
		printf("Impossible, fichier non trouvé!\n");
	}else{
		ligne = malloc(sizeof(char)*83);
		if(ligne == NULL){
			printf("ERREUR D'ALLOCATION!!");
			exit(4);
		}
		int t = fscanf(fichier, "%s", ligne);
		if(t==EOF){
			free(ligne);
			ligne=NULL;
		}
	}
	return ligne;
}




int* ligneAint(char* ligne, int* cellules_int){
	if(cellules_int == NULL){
		cellules_int = malloc(sizeof(int)*9);
		if(cellules_int == NULL){
			printf("ERREUR D'ALLOCATION!!");
			exit(4);
		}
	}


	int j = 0;
	for(int i = 0; i<9; i++){
		cellules_int[i] = 0;
		while (ligne[j] != ';' && ligne[j] != '\n' && ligne[j] != '\0'){
			cellules_int[i] *= 10;
			cellules_int[i] += ligne[j] - '0';
			j++;
		}
		j++;
		//ligne = strtok(cellules_int[i], ";");
	}
	
	return cellules_int;
}


char** ligneAstr(char* ligne, char** cellules_str){
	if(cellules_str != NULL){
		free(cellules_str);
		cellules_str = NULL;
	}
	
	cellules_str = malloc(sizeof(char*)*9);
	if(cellules_str == NULL){
		printf("ERREUR D'ALLOCATION!!");
		exit(4);
	}
	
	cellules_str[0] = strtok(ligne, ";");
	for(int i = 1; i<9; i++){
		cellules_str[i] = strtok(NULL, ";");
	}
	
	return cellules_str;
}


























int main(){
	//FILE* fichier = csvOuvreLecture("../../../donne CSV/cy_crash_tech_small2_shuffled.csv");
	//FILE* fichier = csvOuvreLecture("../../../donne CSV/cy_crash_tech_big_shuffled.csv");
	

	
	FILE* fichier = csvOuvreLecture("cy_crash_tech_small2_shuffled.csv");

	
	
	
	
	
	
	char* ligne = NULL;
	int* cellules_int = NULL;
	char** cellules_str = NULL;
	
	
	printf("Debut\n");
	
	ligne = csvLecteurLigne(fichier);
	cellules_str = ligneAstr(ligne, cellules_str);
	for(int i = 0; i<8; i++){
		printf("%s;", cellules_str[i]);		
	}
	printf("%s\n", cellules_str[8]);	
		
	
	printf("Millieu\n");
	

	
	
	
	do{
		ligne = csvLecteurLigne(fichier);
		
		if(ligne != NULL){
			cellules_int = ligneAint(ligne, cellules_int);
			
			for(int i = 0; i<8; i++){
				printf("%i;", cellules_int[i]);		
			}
			printf("%i\n", cellules_int[8]);
		}
	}while(ligne != NULL);
	
	printf("Fin\n");
	return 0;
}





