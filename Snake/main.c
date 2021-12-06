#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "snakeGame.h"
#include "ConsoleTools.h"

int main(int argc, char** argv) {
	openConsole();

	//  int grille[TAILLEMAX][TAILLEMAX];
	char* buffer = (int*)malloc(TAILLEMAX * TAILLEMAX);

	if (buffer != NULL) {
		grille = buffer;
	}
	else {
		free(grille);
		return 0;
	}

	initGrille(grille);
	creationCorps(grille);
	creationPomme(grille);

	afficheGrille(grille);

	showCursor();
	closeConsole();

	printf("\n\n\n\n\n");
	return EXIT_SUCCESS;
}