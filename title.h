#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include "library.h"
#include <stdlib.h>
#include <string.h>

#define gotoxy(x,y) printf("\033[%d;%dH", (x), (y))
#define cls() printf("\033[H\033[J")

void printEngis();
/* Prosedur menampilkan tulisan 'Engi's'*/

void printKitchen();
/*Prosedur menampilkan tulisan 'Kitchen'*/

void printeExpanded();
/* Prosedur menampilkan tulisan '-Expanded-'*/

void printTitle ();
/*Prosdeur menampilkan title yaitu Engi's Kitchen Expanded*/

void InputNama(char Name[30]);
/*Prosedur menampilkan box input nama dan menerima inputan nama*/

void printLoad (int *input);
/*prosedur menampilkan box dengan pilihan new, load,quit*/