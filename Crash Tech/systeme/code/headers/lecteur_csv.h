#ifndef LECTEUR_CSV_H
#define LECTEUR_CSV_H





#include <stdio.h>
#include <string.h>

#include <stdlib.h>//pour le exit



#define CHEMIN_CSV "../../../donne CSV/"
#define NB_COLONE 9
#define LONGEUR_LIGNE_MAX 83










typedef struct{
	FILE* fichier;
	char* ligne; //ligne complète récupérer du csv
	int nb_colone;
	char** noms_colone;
	int* cellules; //ligne du csv traité et décomposer en valeur numérique
}CSV;










int csvFerme(CSV* fichier_csv);

int csvLecteurLigne(CSV* fichier_csv);

CSV* csvOuvreLecture(char* nom);

CSV* initCSV(FILE* fichier, int nb_colone);

int ligneAint(CSV* fichier_csv);

int ligneAstr(CSV* fichier_csv);





#endif