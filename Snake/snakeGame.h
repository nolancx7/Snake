
#pragma once 

#define SIZEX 30 
#define SIZEY 30 
#define TAILLECORPS 5 //taille du corps de la chenille (au début)
#define NBPOMMES 5
#define TAILLECORPSMAX TAILLECORPS + NBPOMMES 
#define pomme '@'
#define corps '\1'
#define space ' '


typedef struct pos {
	int X;
	int Y;
}POSITION;

POSITION snake;

char* grille,tmpTab;

void initGrille();

void creationCorps();

void creationPomme();

void saveTab();



