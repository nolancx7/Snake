
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "snakeGame.h"
#include "ConsoleTools.h"
#include <windows.h>


void color(int t, int f)
{
	HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(H, f * 16 + t);
}

void initGrille(char *tab) {

	for (int y = 0; y < TAILLEMAX; y++) {
		for (int x = 0; x < TAILLEMAX; x++) {
			*(tab + (y * TAILLEMAX + x)) = space;
		}
	}
	return ;
}

void creationCorps(char* tab) {

	int x = 3;
	for (int y = 0; y < TAILLECORPS; y++) {
		*(tab + y * TAILLEMAX + x) = corps;
	}
	return;
}

void creationPomme(char * tab) {

	int x, y;

	for (int i = 0; i < 5; i++) {
		do {
			 x = rangedRand(0, 30);
			 y = rangedRand(0, 30);
		} while ((x == 3) && (y <= TAILLECORPS));
		*(tab + y * TAILLEMAX + x) = pomme;
	}
}


void afficheGrille(char* tab) {

	hideCursor();
	moveCursor(0, 0);
	for (int y = 0; y < TAILLEMAX; y++) {
		for (int x = 0; x < TAILLEMAX; x++) {
			moveCursor(x, y);
			color(10, 0);
			plotChar(*(tab + (y * TAILLEMAX + x)));
			color(15, 0);
		}
	}
	return;

}

