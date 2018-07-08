#include <stdlib.h>
#include "libreria.h"
#include "interfaccia.h"
#include "gioco.h"

int main() {
    int score;
    int level;
    int griglia[22][62];
    int xlast, ylast, xhead, yhead;
    int flag;
    char mov, nmov, last;
    int tempo;
    int* pspecial;
    int partita = 1;
    system("cd desktop");
    printf("\033[38;5;33m");
    copertina();
    getch();
    do {
        xlast = 32;
        ylast = 11;
        xhead = 29;
        yhead = 11;
        mov = 'D';
        last = 'D';
        level = 1;
        score = 0;
        pspecial = NULL;
        contorno();
        inizializza(griglia);
        stampa(griglia, score, level);
        do  {
            clock_t init = clock(), now = init;
            nmov = '\0';
            switch (level) {
                case 1:
                    while ((double)(now - init) / CLOCKS_PER_SEC < 0.4) {
                        mov = pressed(mov);
                        gotoxy(75, 24);
                        printf("    \b\b\b\b");
                        now = clock();
                    }
                    break;
                    
                case 2:
                    while ((double)(now - init) / CLOCKS_PER_SEC < 0.36) {
                        mov = pressed(mov);
                        gotoxy(75, 24);
                        printf("    \b\b\b\b");
                        now = clock();
                    }
                    break;
                    
                case 3:
                    while ((double)(now - init) / CLOCKS_PER_SEC < 0.32) {
                        mov = pressed(mov);
                        gotoxy(75, 24);
                        printf("    \b\b\b\b");
                        now = clock();
                    }
                    break;
                    
                case 4:
                    while ((double)(now - init) / CLOCKS_PER_SEC < 0.28) {
                        mov = pressed(mov);
                        gotoxy(75, 24);
                        printf("    \b\b\b\b");
                        now = clock();
                    }
                    break;
                    
                case 5:
                    while ((double)(now - init) / CLOCKS_PER_SEC < 0.24) {
                        mov = pressed(mov);
                        gotoxy(75, 24);
                        printf("    \b\b\b\b");
                        now = clock();
                    }
                    break;
                    
                case 6:
                    while ((double)(now - init) / CLOCKS_PER_SEC < 0.20) {
                        mov = pressed(mov);
                        gotoxy(75, 24);
                        printf("    \b\b\b\b");
                        now = clock();
                    }
                    break;
                    
                case 7:
                    while ((double)(now - init) / CLOCKS_PER_SEC < 0.16) {
                        mov = pressed(mov);
                        gotoxy(75, 24);
                        printf("    \b\b\b\b");
                        now = clock();
                    }
                    break;
                    
                case 8:
                    while ((double)(now - init) / CLOCKS_PER_SEC < 0.12) {
                        mov = pressed(mov);
                        gotoxy(75, 24);
                        printf("    \b\b\b\b");
                        now = clock();
                    }
                    break;
                    
                case 9:
                    while ((double)(now - init) / CLOCKS_PER_SEC < 0.10) {
                        mov = pressed(mov);
                        gotoxy(75, 24);
                        printf("    \b\b\b\b");
                        now = clock();
                    }
                    break;
            }
            flag = muovi(griglia, &xlast, &ylast, &xhead, &yhead, mov, &score, &level, &last);
            if (flag == 0) {
                clock_t init = clock(), now = init;
                do {
                    mov = pressed(mov);
                    now = clock();
                }
                while ((double)(now - init) / CLOCKS_PER_SEC < 0.26);
                flag = muovi(griglia, &xlast, &ylast, &xhead, &yhead, mov, &score, &level, &last);
            }
            switch (level) {
                case 1:
                    if (score >= 15)
                        level++;
                    break;
                    
                case 2:
                    if (score >= 30)
                        level++;
                    break;
                    
                case 3:
                    if (score >= 100)
                        level++;
                    break;
                    
                case 4:
                    if (score >= 300)
                        level++;
                    break;
                    
                case 5:
                    if (score >= 900)
                        level++;
                    break;
                    
                case 6:
                    if (score >= 3000)
                        level++;
                    break;
                    
                case 7:
                    if (score >= 6000)
                        level++;
                    break;
                    
                case 8:
                    if (score >= 12000)
                        level++;
                    break;
            }
            if (flag)
                stampa(griglia, score, level);
            if (pspecial == NULL)
                pspecial = special(griglia, &tempo);
            else {
                if (*pspecial != 1 && *pspecial != 2) {
                    if (tempo != 0)
                        tempo--;
                    else {
                        *pspecial = 0;
                        pspecial = NULL;
                    }
                }
                else
                    pspecial = NULL;
            }
        }
        while (flag);
        pulisci();
        partita = nuova_partita(score);
    }
    while (partita);
    pulisci();
}