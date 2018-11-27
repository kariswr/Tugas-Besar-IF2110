#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include "library.h"
#include <stdlib.h>
#include "title.c"

#define gotoxy(x,y) printf("\033[%d;%dH", (x), (y))
#define cls() printf("\033[H\033[J")

int main () {
    int x;
    char *Name;
    printTitle();
    printLoad(&x);
    if (x == 1) {
    	InputNama(Name);
    }
    cls();    
    printf("%s", Name);
    return 0;
}