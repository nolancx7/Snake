#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "snakeGame.h"
#include "ConsoleTools.h"

int main(int argc, char** argv) {

	openConsole();

	char* buffer = (char*)malloc(SIZEX * SIZEY);

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

	int nbPommes = 5;
	int tailleCorpsActuel = 5;
	tete.X = 3;
	tete.Y = TAILLECORPS;

	while (nbPommes > 0) {

		afficheGrille(grille);

		int direction;
		do {
			direction = rangedRand(0, 3);
			// 0 en haut , 1 en bas , 2 à droite , 3 à gauche.
		} while (((direction == 0) && (tete.Y - 1 < 0)) || ((direction == 1) && (tete.Y + 1 > SIZEY)) || ((direction == 2) && (tete.X + 1  > SIZEX)) || ((direction == 3) && (tete.X - 1 > 0)));

		switch (direction)
		{
		case 0: 
			saveTab(tete.X,tete.Y,grille, tailleCorpsActuel);
			--tete.Y;
			break;

		case 1: 
			saveTab(tete.X,tete.Y, grille, tailleCorpsActuel);
			++tete.Y;
			break;

		case 2: 
			saveTab(tete.X,tete.Y, grille, tailleCorpsActuel);
			++tete.X;
			break;

		case 3:
			saveTab(tete.X, tete.Y, grille, tailleCorpsActuel);
			--tete.X;
			break;

		default: 
			break;

		}
	}
	showCursor();
	closeConsole();

	printf("\n\n\n\n\n");
	return EXIT_SUCCESS;
}