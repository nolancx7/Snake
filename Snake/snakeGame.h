
#pragma once 

#define TAILLEMAX 30 //taille de la grille qui est en 30x30 
#define TAILLECORPS 5 //taille du corps de la chenille (au début)

#define pomme '@'
#define corps '\1'
#define space ' '

char* grille;

void initGrille();

void creationCorps();

void creationPomme();



