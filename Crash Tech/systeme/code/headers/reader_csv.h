#ifndef GAME_H
#define GAME_H





#ifdef _WIN32

#include <windows.h>
#define ACCES_DOSSIER_CSV() SetCurrentDirectoryA("../../../donne CSV")

#else
#define ACCES_DOSSIER_CSV() opendir("../../../donne CSV");

#endif









#include <stdio.h>
#include <string.h>

#include <stdlib.h>//pour le exit

/*

typedef struct{
	FILE* fichier;
	int nb_colone;
	char** noms_colone;
}CSV;
*/

/*

typedef struct{
	int nb_cellule;
	char** ligne;
}LigneCSV;
*/

#endif