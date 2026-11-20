#include "../headers/reader_csv.h"




FILE* csvOuvreLecture(char* nom){
	FILE* fichier = fopen(nom, "r");
	if(fichier == NULL){
		printf("ATTENTION! le fichier n'existe pas, avez-vous données le bon nom?\n");
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


int csvLecteurLigne(FILE* fichier){
	
	char val[200];
	strtok(val, ";");
	//fscanf(fichier, "%s", val);
	printf("retour d'accès: %s\n", val);

}


int main(){
	FILE* fichier = csvOuvreLecture("../../../donné CSV/cy_crash_tech_small2_shuffled.csv");
	

	csvLecteurInt(fichier);
	csvLecteurInt(fichier);
	return 0;
}





