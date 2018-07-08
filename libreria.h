#ifndef LIBRERIA
#define LIBRERIA

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

void gotoxy(int x,int y);
char getch();
char pressed(char c);

#endif