#include "gioco.h"

void inizializza(int griglia[22][62]) {
    int i, j, k;
    for (i = 0; i < 22; i++) {
        for (j = 0; j < 62; j++) {
            if (i == 11 && j > 28 && j < 33) {
                griglia[i][j] = (j == 29)? 2 : 1 | LEFT;
            }
            else griglia[i][j] = 0;
        }
    }
    srand(time(NULL));
    for (k = 0; k < 3; k++) {
        do {
            i = rand() % 22;
            j = rand() % 62;
        }
        while (griglia[i][j] != 0);
        griglia[i][j] = 4; // 4 -> frutto normale
    }
}

int muovi(int griglia[][62], int* xlast, int* ylast, int* xhead, int* yhead, char mov, int* score, int* level, char* last) {
    switch (mov) {
        case 'A':
            if (*last == 'B')
                return muovi(griglia, xlast, ylast, xhead, yhead, 'B', score, level, last);
            *last = 'A';
            if (*yhead > 0 && !(griglia[*yhead - 1][*xhead] & 1)) {
                griglia[*yhead][*xhead] = 1 | UP;
                if (griglia[*yhead - 1][*xhead] == FRUIT || griglia[*yhead - 1][*xhead] == SFRUIT) {
                    (*score) += (griglia[*yhead - 1][*xhead] == FRUIT)? 5 * (*level) : 10 * (*level);
                    if (griglia[*yhead - 1][*xhead] == FRUIT) {
                        int x, y;
                        do {
                            x = rand() % 62;
                            y = rand() % 22;
                        }
                        while (griglia[y][x] != 0);
                        griglia[y][x] = FRUIT;
                    }
                }
                else {
                    switch (griglia[*ylast][*xlast] - 1) {
                        case UP:
                            griglia[*ylast][*xlast] = 0;
                            *ylast -= 1;
                            break;
                            
                        case DOWN:
                            griglia[*ylast][*xlast] = 0;
                            *ylast += 1;
                            break;
                            
                        case LEFT:
                            griglia[*ylast][*xlast] = 0;
                            *xlast -= 1;
                            break;
                            
                        case RIGHT:
                            griglia[*ylast][*xlast] = 0;
                            *xlast += 1;
                            break;

                    }
                }
                *yhead -= 1;
                griglia[*yhead][*xhead] = 2;
                return 1;
            }
            else return 0;
            break;
        
        case 'D':
            if (*last == 'C')
                return muovi(griglia, xlast, ylast, xhead, yhead, 'C', score, level, last);
            *last = 'D';
            if (*xhead > 0 && !(griglia[*yhead][*xhead - 1] & 1)) {
                griglia[*yhead][*xhead] = 1 | LEFT;
                if (griglia[*yhead][*xhead - 1] == FRUIT || griglia[*yhead][*xhead - 1] == SFRUIT) {
                    (*score) += (griglia[*yhead][*xhead - 1] == FRUIT)? 5 * (*level) : 10 * (*level);
                    if (griglia[*yhead][*xhead - 1] == FRUIT) {
                        int x, y;
                        do {
                            x = rand() % 62;
                            y = rand() % 22;
                        }
                        while (griglia[y][x] != 0);
                        griglia[y][x] = FRUIT;
                    }
                }
                else {
                    switch (griglia[*ylast][*xlast] - 1) {
                        case UP:
                            griglia[*ylast][*xlast] = 0;
                            *ylast -= 1;
                            break;
                            
                        case DOWN:
                            griglia[*ylast][*xlast] = 0;
                            *ylast += 1;
                            break;
                            
                        case LEFT:
                            griglia[*ylast][*xlast] = 0;
                            *xlast -= 1;
                            break;
                            
                        case RIGHT:
                            griglia[*ylast][*xlast] = 0;
                            *xlast += 1;
                            break;
                            
                    }
                }
                *xhead -= 1;
                griglia[*yhead][*xhead] = 2;
                return 1;
            }
            else return 0;
            break;
            
        case 'B':
            if (*last == 'A')
                return muovi(griglia, xlast, ylast, xhead, yhead, 'A', score, level, last);
            *last = 'B';
            if (*yhead < 21 && !(griglia[*yhead + 1][*xhead] & 1)) {
                griglia[*yhead][*xhead] = 1 | DOWN;
                if (griglia[*yhead + 1][*xhead] == FRUIT || griglia[*yhead + 1][*xhead] == SFRUIT) {
                    (*score) += (griglia[*yhead + 1][*xhead] == FRUIT)? 5 * (*level) : 25 * (*level);
                    if (griglia[*yhead + 1][*xhead] == FRUIT) {
                        int x, y;
                        do {
                            x = rand() % 62;
                            y = rand() % 22;
                        }
                        while (griglia[y][x] != 0);
                        griglia[y][x] = FRUIT;
                    }
                }
                else {
                    switch (griglia[*ylast][*xlast] - 1) {
                        case UP:
                            griglia[*ylast][*xlast] = 0;
                            *ylast -= 1;
                            break;
                            
                        case DOWN:
                            griglia[*ylast][*xlast] = 0;
                            *ylast += 1;
                            break;
                            
                        case LEFT:
                            griglia[*ylast][*xlast] = 0;
                            *xlast -= 1;
                            break;
                            
                        case RIGHT:
                            griglia[*ylast][*xlast] = 0;
                            *xlast += 1;
                            break;
                            
                    }
                }
                *yhead += 1;
                griglia[*yhead][*xhead] = 2;
                return 1;
            }
            else return 0;
            break;
            
        case 'C':
            if (*last == 'D')
                return muovi(griglia, xlast, ylast, xhead, yhead, 'D', score, level, last);
            *last = 'C';
            if (*xhead < 61 && !(griglia[*yhead][*xhead + 1] & 1)) {
                griglia[*yhead][*xhead] = 1 | RIGHT;
                if (griglia[*yhead][*xhead + 1] == FRUIT || griglia[*yhead][*xhead + 1] == SFRUIT) {
                    (*score) += (griglia[*yhead][*xhead + 1] == FRUIT)? 5 * (*level) : 10 * (*level);
                    if (griglia[*yhead][*xhead + 1] == FRUIT) {
                        int x, y;
                        do {
                            x = rand() % 62;
                            y = rand() % 22;
                        }
                        while (griglia[y][x] != 0);
                        griglia[y][x] = FRUIT;
                    }
                }
                else {
                    switch (griglia[*ylast][*xlast] - 1) {
                        case UP:
                            griglia[*ylast][*xlast] = 0;
                            *ylast -= 1;
                            break;
                            
                        case DOWN:
                            griglia[*ylast][*xlast] = 0;
                            *ylast += 1;
                            break;
                            
                        case LEFT:
                            griglia[*ylast][*xlast] = 0;
                            *xlast -= 1;
                            break;
                            
                        case RIGHT:
                            griglia[*ylast][*xlast] = 0;
                            *xlast += 1;
                            break;
                            
                    }
                }
                *xhead += 1;
                griglia[*yhead][*xhead] = 2;
                return 1;
            }
            else return 0;
            break;
    }
    return 1;
}

int* special(int griglia[22][62], int* tempo) {
    int estrazione = rand() % 50;
    int x, y;
    if (estrazione == 9) {
        do {
            x = rand() % 62;
            y = rand() % 22;
        }
        while (griglia[y][x] != 0);
        griglia[y][x] = SFRUIT;
        *tempo = rand() % 100 + 51;
        return &griglia[y][x];
    }
    return NULL;
}