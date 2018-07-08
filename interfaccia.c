#include "libreria.h"
#include "interfaccia.h"

void pulisci() {
    int i, j;
    for (i = 1; i <= 80; i++) {
        for (j = 1; j <= 24; j++) {
            gotoxy(i, j);
            printf(" ");
        }
    }
    gotoxy(1, 1);
}

void contorno() {
    int i, j;
    pulisci();
    printf(".");
    for (i = 0; i < 62; i++)
        printf("-");
    printf(".\n");
    for (i = 0; i < 22; i++) {
        printf("|");
        for (j = 0; j < 62; j++)
            printf(" ");
        switch (i) {
            case 1:
                printf("| SCORE:\n");
                break;
                
            case 2:
                printf("| LEVEL:\n");
                break;
                
            case 8:
                printf("|\n");
                break;
                
            case 9:
                printf("|\n");
                break;
                
            case 10:
                printf("|\n");
                break;
                
            case 11:
                printf("|\n");
                break;
                
            case 12:
                printf("|\n");
                break;
                
            case 20:
                printf("| CREDITS:\n");
                break;
                
            case 21:
                printf("|   ~ ChJames ~\n");
                break;
                
            default:
                printf("|\n");
                break;
        }
    }
    printf(".");
    for (i = 0; i < 62; i++)
        printf("-");
    printf(".");
}

void copertina() {
    pulisci();
    printf("\n");
    printf("                    /^\\ /^\\\n");
    printf("                  _| o | O |\n");
    printf("         \\/     /~  \\_/ \\_/ \\\n");
    printf("          \\____|__________/  \\\n");
    printf("                 \\_______      \\\n");
    printf("                         `\\     \\                 \\\n");
    printf("                           |     |                  \\\n");
    printf("                          /      /                    \\\n");
    printf("                         /     /                       \\\\\n");
    printf("                       /      /                         \\ \\\n");
    printf("                      /     /                            \\  \\\n");
    printf("                    /     /             _----_            \\   \\\n");
    printf("                   /     /           _-~      ~-_         |   |\n");
    printf("                  (      (        _-~    _--_    ~-_     _/   |\n");
    printf("                   \\      ~-____-~    _-~    ~-_    ~-_-~    /\n");
    printf("                     ~-_           _-~          ~-_       _-~\n");
    printf("                        ~--______-~                ~-___-~\n\n");
    printf("  /¯¯\\\n");
    printf("  \\__  |\\  |   /\\   | / |¯¯   2000\n");
    printf("     \\ | \\ |  /__\\  |–  |-\n");
    printf("  \\__/ |  \\| /    \\ | \\ |__   premi un tasto per continuare…\n");
    printf("                                    developed by ChJames");
    gotoxy(1, 1);
}

void stampa(int griglia[22][62], int score, int livello) {
    int i, j;
    gotoxy(72, 3);
    printf("%d", score);
    gotoxy(72, 4);
    printf("%d", livello);
    for (i = 0; i < 22; i++) {
        for (j = 0; j < 62; j++) {
            gotoxy(j + 2, i + 2);
            if (griglia[i][j] & 1)
                printf("o");
            else {
                switch (griglia[i][j]) {
                    case 2:
                        printf("@");
                        break;
                        
                    case 4:
                        printf("x");
                        break;
                        
                    case 8:
                        printf("&");
                        break;
                        
                    default:
                        printf(" ");
                        break;
                }
            }
        }
    }
    gotoxy(75, 24);
}

int nuova_partita(int score) {
    char nuova;
    printf("\n YOUR SCORE: %d", score);
    printf("\n\n vuoi avviare una nuova partita? (y/n)  ");
    do {
        nuova = getch();
        gotoxy(41, 4);
    }
    while (nuova != 'y' && nuova != 'n');
    return (nuova == 'y')? 1 : 0;
}