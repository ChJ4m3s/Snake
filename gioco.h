#ifndef GIOCO
#define GIOCO

#include <time.h>
#include <stdlib.h>

#define FRUIT 4
#define SFRUIT 8
#define UP 16
#define DOWN 32
#define LEFT 64
#define RIGHT 128

void inizializza(int griglia[][62]);
int muovi(int griglia[][62], int* xlast, int* ylast, int* xhead, int* yhead, char mov, int* score, int* level, char* last);
int* special(int griglia[22][62], int* tempo);

#endif