
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "snakeGame.h"
#include "ConsoleTools.h"


void initGrille(int *tab) {

	for (int x = 0; x < TAILLEMAX; x++) {
		for (int y = 0; y < TAILLEMAX; y++) {
			*(tab + x*TAILLEMAX + y) = 0;
		}
	}
	return ;
}

void creationCorps(int* tab) {

	int x = 0;
	for (int y = 0; y < TAILLECORPS; y++) {
		*(tab + x*TAILLEMAX + y) = 1;
	}
	return;
}

void creationCorps(int* tab) {}

int main(int argc, char** argv) {

	openConsole();

	//  int grille[TAILLEMAX][TAILLEMAX];
	int *buffer = (int*) malloc(TAILLEMAX * TAILLEMAX * sizeof(int));

	if (buffer != NULL) {
		grille = buffer;
	}

	initGrille(grille);
	creationCorps(grille);


	showCursor();
	closeConsole();

	return EXIT_SUCCESS;
}