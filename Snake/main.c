#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "snakeGame.h"
#include "ConsoleTools.h"

int main(int argc, char** argv) {

	openConsole();
	int nbPommes = 5;
	int tailleCorpsActuel = 5;

	char* buffer = (char*)malloc(SIZEX * SIZEY);

	if (buffer != NULL) {
		grille = buffer;
	}
	else {
		free(grille);
		return 0;
	}

	POSITION snake[TAILLECORPSMAX] = { {3,0},{3,1},{3,2},{3,3},{3,4},{0,0},{0,0},{0,0},{0,0},{0,0} };
	//Après test snake vers le bas par exemple , on aura :
	//POSITION snake[TAILLECORPSMAX] = { {3,1},{3,2},{3,3},{3,4},{3,5},{0,0},{0,0},{0,0},{0,0},{0,0} };

	//POSITION tmpTab[TAILLECORPSMAX] = { {3,0},{3,1},{3,2},{3,3},{3,4},{0,0},{0,0},{0,0},{0,0},{0,0} };

	initGrille(grille);
	creationCorps(grille);
	creationPomme(grille);

	while (nbPommes > 0) {

		afficheGrille(grille);

		int direction;
		do {
			direction = rangedRand(0, 3);
			// 0 en haut , 1 en bas , 2 à droite , 3 à gauche.
		} while (((direction == 0) && (snake[TAILLECORPS].Y - 1 < 0)) || ((direction == 1) && (snake[TAILLECORPS].Y + 1 > SIZEY)) || ((direction == 2) && (snake[TAILLECORPS].X + 1  > SIZEX)) || ((direction == 3) && (snake[TAILLECORPS].X - 1 < 0)));

		switch (direction)
		{
		case 0: 
			for (int i = 0; i < tailleCorpsActuel - 1; i++) {
				snake[i].X = snake[i + 1].X;
				snake[i].Y = snake[i + 1].Y;
			}
			--snake[TAILLECORPS].Y;
			break;

		case 1: 
			for (int i = 0; i < tailleCorpsActuel - 1; i++) {
				snake[i].X = snake[i + 1].X;
				snake[i].Y = snake[i + 1].Y;
			}
			++snake[TAILLECORPS].Y;
			break;

		case 2: 
			for (int i = 0; i < tailleCorpsActuel - 1; i++) {
				snake[i].X = snake[i + 1].X;
				snake[i].Y = snake[i + 1].Y;
			}
			++snake[TAILLECORPS].X;
			break;

		case 3:
			for (int i = 0; i < tailleCorpsActuel - 1; i++) {
				snake[i].X = snake[i + 1].X;
				snake[i].Y = snake[i + 1].Y;
			}
			--snake[TAILLECORPS].X;
			break;

		default: 
			break;

		}

		/*for (int y = 0; y < SIZEY; y++) {
			for (int x = 0; x < SIZEX; x++) {
				if (x == snake[0].x) && (y == snake[0].y) {
					*(tab + (y * SIZEX + x)) = corps;
				}
			
				else {

				}
			}
		}*/
		
		//if(*(tab + tete.Y * SIZEX + tete.X) == pomme){
		//*(tab + tete.Y * SIZEX + tete.X) = corps;
		//snake[0].x = corps;
		//snake[0].y = corps;
		// 
		//}
	}
	showCursor();
	closeConsole();

	printf("\n\n\n\n\n");
	return EXIT_SUCCESS;
}