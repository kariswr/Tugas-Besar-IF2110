#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include "library.h"
#include <stdlib.h>
#include <string.h>

#define gotoxy(x,y) printf("\033[%d;%dH", (x), (y))
#define cls() printf("\033[H\033[J")

void printEngis() {
    int a = 92;
    char x = a;
    start_color();
    init_pair(1,COLOR_WHITE,COLOR_WHITE);
    init_pair(2,COLOR_WHITE,COLOR_BLACK);
    init_pair(3,COLOR_BLACK,COLOR_WHITE);

    printw("\n");
    erase();
    printw("        ");
    printw("____ ____");
    printw(" ");
    printw("_____ ");
    printw("       ");
    printw("____");
    printw("      ");
    printw("_____ ___");
    printw("    ");
    printw("___ __");
    printw("    ");
    printw("___");
    printw("       ");
    printw("__ _____\n");
    refresh();
    napms(10);

    //Baris Kedua
    //Huruf E
    printw("        ");
    attron(COLOR_PAIR(1));
    printw("WHYWHYWHY");
    attron(COLOR_PAIR(2));
    printw("|");
    //Huruf N
    attron(COLOR_PAIR(1));
    printw("whywhy");
    attron(COLOR_PAIR(2));
    printw("%c",x);
    printw("      ");
    attron(COLOR_PAIR(1));
    printw("whyw");
    attron(COLOR_PAIR(2));
    printw("|");
    printw("     ");
    //Huruf G
    attron(COLOR_PAIR(1));
    printw("WHYWHYWHY");
    attron(COLOR_PAIR(2));
    printw("%c",x);
    printw("  ");
    //Huruf I
    attron(COLOR_PAIR(1));
    printw("whywhy");
    attron(COLOR_PAIR(2));
    printw("|");
    printw("  ");
    //Kutip
    attron(COLOR_PAIR(1));
    printw("(...");
    attron(COLOR_PAIR(2));
    printw("%c",x);
    printw("      ");
    //Huruf S
    attron(COLOR_PAIR(1));
    printw("WHYWHYWH");
    attron(COLOR_PAIR(2));
    printw("%c\n",x);
    refresh();
    napms(10);

    //Baris Ketiga
    //Huruf E
    printw("        ");
    attron(COLOR_PAIR(1));
    printw("WHYWHYWHY");
    attron(COLOR_PAIR(2));
    printw("|");
    //Huruf N
    attron(COLOR_PAIR(1));
    printw("whywhyw");
    attron(COLOR_PAIR(2));
    printw("%c",x);
    printw("     ");
    attron(COLOR_PAIR(1));
    printw("whyw");
    attron(COLOR_PAIR(2));
    printw("|");
    printw("   ");
    //Huruf G
    attron(COLOR_PAIR(1));
    printw("WHYWHYWHYWHY");
    attron(COLOR_PAIR(2));
    printw("%c",x);
    printw(" ");
    //Huruf I
    attron(COLOR_PAIR(1));
    printw("whywhy");
    attron(COLOR_PAIR(2));
    printw("|");
    printw("   ");
    //Kutip
    attron(COLOR_PAIR(1));
    printw("%c...",x);
    attron(COLOR_PAIR(2));
    printw("|");
    printw("    ");
    //Huruf S
    attron(COLOR_PAIR(1));
    printw("WHYWHYWHYW");
    attron(COLOR_PAIR(2));
    printw("%c\n",x);
    refresh();
    napms(10);

    //Baris Keempat
    //Huruf E
    printw("        ");
    attron(COLOR_PAIR(1));
    printw("WHYW");
    attron(COLOR_PAIR(2));
    printw("|");
    printw("     ");
    //Huruf N
    attron(COLOR_PAIR(1));
    printw("whywwhyw");
    attron(COLOR_PAIR(2));
    printw("%c",x);
    printw("    ");
    attron(COLOR_PAIR(1));
    printw("whyw");
    attron(COLOR_PAIR(2));
    printw("|");
    printw("  ");
    //Huruf G
    attron(COLOR_PAIR(1));
    printw("WHYW");
    attron(COLOR_PAIR(2));
    printw("/");
    printw("      ");
    attron(COLOR_PAIR(1));
    printw("WHY");
    attron(COLOR_PAIR(2));
    printw("|");
    //Huruf I
    attron(COLOR_PAIR(1));
    printw("whywhy");
    attron(COLOR_PAIR(2));
    printw("|");
    printw("   ");
    //Kutip
    attron(COLOR_PAIR(1));
    printw("/..");
    attron(COLOR_PAIR(2));
    printw("/");
    printw("    ");
    attron(COLOR_PAIR(1));
    //Huruf S
    printw("WHYWH");
    attron(COLOR_PAIR(2));
    printw("/");
    printw(" ");
    attron(COLOR_PAIR(1));
    printw("WHYWH");
    attron(COLOR_PAIR(2));
    printw("|\n");
    refresh();
    napms(10);

    //Baris Kelima
    //Huruf E
    printw("        ");
    attron(COLOR_PAIR(1));
    printw("WHYW");
    attron(COLOR_PAIR(2));
    printw("|____");
    printw(" ");
    //Huruf N
    attron(COLOR_PAIR(1));
    printw("whyw");
    attron(COLOR_PAIR(2));
    printw(" ");
    attron(COLOR_PAIR(1));
    printw("whyw");
    attron(COLOR_PAIR(2));
    printw("%c",x);
    printw("   ");
    attron(COLOR_PAIR(1));
    printw("whyw");
    attron(COLOR_PAIR(2));
    printw("|");
    printw(" ");
    //Huruf G
    attron(COLOR_PAIR(1));
    printw("WHYW");
    attron(COLOR_PAIR(2));
    printw("/");
    printw("           ");
    //Huruf I
    attron(COLOR_PAIR(1));
    printw("whywhy");
    attron(COLOR_PAIR(2));
    printw("|");
    printw("   ");
    //Kutip
    attron(COLOR_PAIR(1));
    printw("(.");
    attron(COLOR_PAIR(2));
    printw("/");
    printw("    ");
    //Huruf S
    attron(COLOR_PAIR(1));
    printw("WHYWH");
    attron(COLOR_PAIR(2));
    printw("|\n");
    refresh();
    napms(10);

    //Baris Keenam
    //Huruf E
    printw("        ");
    attron(COLOR_PAIR(1));
    printw("WHYWHYWHY");
    attron(COLOR_PAIR(2));
    printw("|");
    //Huruf N
    attron(COLOR_PAIR(1));
    printw("whyw");
    attron(COLOR_PAIR(2));
    printw("  ");
    attron(COLOR_PAIR(1));
    printw("whyw");
    attron(COLOR_PAIR(2));
    printw("%c",x);
    printw("  ");
    attron(COLOR_PAIR(1));
    printw("whyw");
    attron(COLOR_PAIR(2));
    printw("|");
    //Huruf G
    attron(COLOR_PAIR(1));
    printw("WHYW");
    attron(COLOR_PAIR(2));
    printw("|");
    printw("  ");
    printw("_____ ___ ");
    //Huruf I
    attron(COLOR_PAIR(1));
    printw("whywhy");
    attron(COLOR_PAIR(2));
    printw("|");
    printw("            ");
    //Huruf S
    attron(COLOR_PAIR(1));
    printw("WHYW");
    attron(COLOR_PAIR(2));
    printw("%c\n",x);
    refresh();
    napms(10);

    //Baris Ketujuh
    //Huruf E
    printw("        ");
    attron(COLOR_PAIR(1));
    printw("WHYWHYWHY");
    attron(COLOR_PAIR(2));
    printw("|");
    //Huruf N
    attron(COLOR_PAIR(1));
    printw("whyw");
    attron(COLOR_PAIR(2));
    printw("   ");
    attron(COLOR_PAIR(1));
    printw("whyw");
    attron(COLOR_PAIR(2));
    printw("%c",x);
    printw(" ");
    attron(COLOR_PAIR(1));
    printw("whyw");
    attron(COLOR_PAIR(2));
    printw("|");
    //Huruf G
    attron(COLOR_PAIR(1));
    printw("WHYW");
    attron(COLOR_PAIR(2));
    printw("|");
    attron(COLOR_PAIR(2));
    printw("  ");
    attron(COLOR_PAIR(1));
    printw("WHYWHYWHY");
    attron(COLOR_PAIR(2));
    printw("|");
    //Huruf I
    attron(COLOR_PAIR(1));
    printw("whywhy");
    attron(COLOR_PAIR(2));
    printw("|");
    printw("             ");
    //Huruf S
    attron(COLOR_PAIR(1));
    printw("WHYWHYWHYW");
    attron(COLOR_PAIR(2));
    printw("%c\n",x);
    refresh();
    napms(10);

    //Baris Kedelapan
    //Huruf E
    printw("        ");
    attron(COLOR_PAIR(1));
    printw("WHYW");
    attron(COLOR_PAIR(2));
    printw("|");
    printw("     ");
    attron(COLOR_PAIR(1));
    printw("whyw");
    attron(COLOR_PAIR(2));
    printw("    ");
    attron(COLOR_PAIR(1));
    printw("whyw");
    attron(COLOR_PAIR(2));
    printw("%c",x);
    attron(COLOR_PAIR(1));
    printw("whyw");
    attron(COLOR_PAIR(2));
    printw("|");
    printw(" ");
    attron(COLOR_PAIR(1));
    printw("WHYW");
    attron(COLOR_PAIR(2));
    printw("%c",x);
    printw(" ");
    attron(COLOR_PAIR(1));
    printw("WHYWHYWHY");
    attron(COLOR_PAIR(2));
    printw("|");
    attron(COLOR_PAIR(1));
    printw("whywhy");
    attron(COLOR_PAIR(2));
    printw("|");
    printw("          ");
    printw("______");
    printw("  ");
    attron(COLOR_PAIR(1));
    printw("WHYWHY");
    attron(COLOR_PAIR(2));
    printw("%c\n",x);
    refresh();
    napms(10);

    //Baris Kesembilan
    //Huruf E
    printw("        ");
    attron(COLOR_PAIR(1));
    printw("WHYW");
    attron(COLOR_PAIR(2));
    printw("|_____");
    attron(COLOR_PAIR(1));
    printw("whyw");
    attron(COLOR_PAIR(2));
    printw("     ");
    attron(COLOR_PAIR(1));
    printw("why");
    attron(COLOR_PAIR(2));
    printw(" ");
    attron(COLOR_PAIR(1));
    printw("whyw");
    attron(COLOR_PAIR(2));
    printw("|");
    printw("  ");
    attron(COLOR_PAIR(1));
    printw("WHYW");
    attron(COLOR_PAIR(2));
    printw("%c______",x);
    attron(COLOR_PAIR(1));
    printw("WHY");
    attron(COLOR_PAIR(2));
    printw("|");
    attron(COLOR_PAIR(1));
    printw("whywhy");
    attron(COLOR_PAIR(2));
    printw("|          ");
    attron(COLOR_PAIR(1));
    printw("WHYWHY");
    attron(COLOR_PAIR(2));
    printw("|__");
    attron(COLOR_PAIR(1));
    printw("WHYWH");
    attron(COLOR_PAIR(2));
    printw("|\n");
    refresh();
    napms(10);
    
    //Baris Kesepuluh
    //Huruf E
    printw("        ");
    attron(COLOR_PAIR(1));
    printw("WHYWHYWHY");
    attron(COLOR_PAIR(2));
    printw("|");
    attron(COLOR_PAIR(1));
    printw("whyw");
    attron(COLOR_PAIR(2));
    printw("      ");
    attron(COLOR_PAIR(1));
    printw("whywhyw");
    attron(COLOR_PAIR(2));
    printw("|");
    printw("    ");
    attron(COLOR_PAIR(1));
    printw("WHYWHYWHYWH");
    attron(COLOR_PAIR(2));
    printw("/ ");
    attron(COLOR_PAIR(1));
    printw("whywhy");
    attron(COLOR_PAIR(2));
    printw("|            ");
    attron(COLOR_PAIR(1));
    printw("WHYWHYWHYWH");
    attron(COLOR_PAIR(2));
    printw("/\n");
    refresh();
    napms(10);
    
    //Baris Kesebelas
    printw("        ");
    attron(COLOR_PAIR(1));
    printw("WHYWHYWHY");
    attron(COLOR_PAIR(2));
    printw("|");
    attron(COLOR_PAIR(1));
    printw("whyw");
    attron(COLOR_PAIR(2));
    printw("       ");
    attron(COLOR_PAIR(1));
    printw("whywhw");
    attron(COLOR_PAIR(2));
    printw("|");
    printw("     ");
    attron(COLOR_PAIR(1));
    printw("WHYWHYWHY");
    attron(COLOR_PAIR(2));
    printw("/");
    printw("  ");
    attron(COLOR_PAIR(1));
    printw("whywhy");
    attron(COLOR_PAIR(2));
    printw("|              ");
    attron(COLOR_PAIR(1));
    printw("WHYWHYWH");
    attron(COLOR_PAIR(2));
    printw("/\n");
    refresh();
    napms(10);

}

void printKitchen(){
    int a = 92;
    char x = a;
    start_color();
    init_pair(1,COLOR_WHITE,COLOR_WHITE);
    init_pair(2,COLOR_WHITE,COLOR_BLACK);
    init_pair(3,COLOR_BLACK,COLOR_WHITE);

    printw(" ____    ____ _____ _____ _____ ___     _____ ___   ____    ____ ____ ____ _____        ____\n");
    refresh();
    napms(10);

    //Baris Kedua
    printw(" ");
    attron(COLOR_PAIR(1));
    printw("WHYW");
    attron(COLOR_PAIR(2));
    printw("|   ");
    attron(COLOR_PAIR(1));
    printw("WHYW");
    attron(COLOR_PAIR(2));
    printw("|");
    attron(COLOR_PAIR(1));
    printw("whywh");
    attron(COLOR_PAIR(2));
    printw("|");
    attron(COLOR_PAIR(1));
    printw("WHYWHYWHYWHYWHY");
    attron(COLOR_PAIR(2));
    printw("|   ");
    attron(COLOR_PAIR(1));
    printw("whywhywhyw");
    attron(COLOR_PAIR(2));
    printw("%c  ",x);
    attron(COLOR_PAIR(1));
    printw("WHYW");
    attron(COLOR_PAIR(2));
    printw("|   ");
    attron(COLOR_PAIR(1));
    printw("WHYW");
    attron(COLOR_PAIR(2));
    printw("|");
    attron(COLOR_PAIR(1));
    printw("WHYWHYWHY");
    attron(COLOR_PAIR(2));
    printw("|");
    attron(COLOR_PAIR(1));
    printw("whywhy");
    attron(COLOR_PAIR(2));
    printw("%c      ",x);
    attron(COLOR_PAIR(1));
    printw("whyw");
    attron(COLOR_PAIR(2));
    printw("|\n");
    refresh();
    napms(10);

    //Baris ketiga
    printw(" ");
    attron(COLOR_PAIR(1));
    printw("WHYW");
    attron(COLOR_PAIR(2));
    printw("|  ");
    attron(COLOR_PAIR(1));
    printw("WHYW");
    attron(COLOR_PAIR(2));
    printw("/ ");
    attron(COLOR_PAIR(1));
    printw("whywh");
    attron(COLOR_PAIR(2));
    printw("|");
    attron(COLOR_PAIR(1));
    printw("WHYWHYWHYWHYWHY");
    attron(COLOR_PAIR(2));
    printw("|  ");
    attron(COLOR_PAIR(1));
    printw("whywwhywhywh");
    attron(COLOR_PAIR(2));
    printw("%c ",x);
    attron(COLOR_PAIR(1));
    printw("WHYW");
    attron(COLOR_PAIR(2));
    printw("|   ");
    attron(COLOR_PAIR(1));
    printw("WHYW");
    attron(COLOR_PAIR(2));
    printw("|");
    attron(COLOR_PAIR(1));
    printw("WHYWHYWHY");
    attron(COLOR_PAIR(2));
    printw("|");
    attron(COLOR_PAIR(1));
    printw("whywhyw");
    attron(COLOR_PAIR(2));
    printw("%c     ",x);
    attron(COLOR_PAIR(1));
    printw("whyw");
    attron(COLOR_PAIR(2));
    printw("|\n");
    refresh();
    napms(10);

    //Baris keempat
    printw(" ");
    attron(COLOR_PAIR(1));
    printw("WHYW");
    attron(COLOR_PAIR(2));
    printw("| ");
    attron(COLOR_PAIR(1));
    printw("WHYW");
    attron(COLOR_PAIR(2));
    printw("/  ");
    attron(COLOR_PAIR(1));
    printw("whywh");
    attron(COLOR_PAIR(2));
    printw("|");
    attron(COLOR_PAIR(1));
    printw("WHYWHYWHYWHYWHY");
    attron(COLOR_PAIR(2));
    printw("| ");
    attron(COLOR_PAIR(1));
    printw("whyw");
    attron(COLOR_PAIR(2));
    printw("/     ");
    attron(COLOR_PAIR(1));
    printw("whyw");
    attron(COLOR_PAIR(2));
    printw("|");
    attron(COLOR_PAIR(1));
    printw("WHYW");
    attron(COLOR_PAIR(2));
    printw("|   ");
    attron(COLOR_PAIR(1));
    printw("WHYW");
    attron(COLOR_PAIR(2));
    printw("|");
    attron(COLOR_PAIR(1));
    printw("WHYW");
    attron(COLOR_PAIR(2));
    printw("|     ");
    attron(COLOR_PAIR(1));
    printw("whywwhyw");
    attron(COLOR_PAIR(2));
    printw("%c    ",x);
    attron(COLOR_PAIR(1));
    printw("whyw");
    attron(COLOR_PAIR(2));
    printw("|\n");
    refresh();
    napms(10);

    //Baris Kelima
    printw(" ");
    attron(COLOR_PAIR(1));
    printw("WHYW");
    attron(COLOR_PAIR(2));
    printw("|");
    attron(COLOR_PAIR(1));
    printw("WHYW");
    attron(COLOR_PAIR(2));
    printw("/   ");
    attron(COLOR_PAIR(1));
    printw("whywh");
    attron(COLOR_PAIR(2));
    printw("|    ");
    attron(COLOR_PAIR(1));
    printw("WHYWHY");
    attron(COLOR_PAIR(2));
    printw("|     ");
    attron(COLOR_PAIR(1));
    printw("whyw");
    attron(COLOR_PAIR(2));
    printw("|           ");
    attron(COLOR_PAIR(1));
    printw("WHYW");
    attron(COLOR_PAIR(2));
    printw("|___");
    attron(COLOR_PAIR(1));
    printw("WHYW");
    attron(COLOR_PAIR(2));
    printw("|");
    attron(COLOR_PAIR(1));
    printw("WHYW");
    attron(COLOR_PAIR(2));
    printw("|____ ");
    attron(COLOR_PAIR(1));
    printw("whyw");
    attron(COLOR_PAIR(2));
    printw("|");
    attron(COLOR_PAIR(1));
    printw("whyw");
    attron(COLOR_PAIR(2));
    printw("%c   ",x);
    attron(COLOR_PAIR(1));
    printw("whyw");
    attron(COLOR_PAIR(2));
    printw("|\n");
    refresh();
    napms(10);

    //Baris Keenam
    printw(" ");
    attron(COLOR_PAIR(1));
    printw("WHYWWHYW");
    attron(COLOR_PAIR(2));
    printw("/    ");
    attron(COLOR_PAIR(1));
    printw("whywh");
    attron(COLOR_PAIR(2));
    printw("|    ");
    attron(COLOR_PAIR(1));
    printw("WHYWHY");
    attron(COLOR_PAIR(2));
    printw("|     ");
    attron(COLOR_PAIR(1));
    printw("whyw");
    attron(COLOR_PAIR(2));
    printw("|           ");
    attron(COLOR_PAIR(1));
    printw("WHYWWHYWHYWH");
    attron(COLOR_PAIR(2));
    printw("|");
    attron(COLOR_PAIR(1));
    printw("WHYWHYWHY");
    attron(COLOR_PAIR(2));
    printw("|");
    attron(COLOR_PAIR(1));
    printw("whyw");
    attron(COLOR_PAIR(2));
    printw("| ");
    attron(COLOR_PAIR(1));
    printw("whyw");
    attron(COLOR_PAIR(2));
    printw("%c  ",x);
    attron(COLOR_PAIR(1));
    printw("whyw");
    attron(COLOR_PAIR(2));
    printw("|\n");
    refresh();
    napms(10);

    //Baris ketujuh
    printw(" ");
    attron(COLOR_PAIR(1));
    printw("WHYWWHYW");
    attron(COLOR_PAIR(2));
    printw("%c    ",x);
    attron(COLOR_PAIR(1));
    printw("whywh");
    attron(COLOR_PAIR(2));
    printw("|    ");
    attron(COLOR_PAIR(1));
    printw("WHYWHY");
    attron(COLOR_PAIR(2));
    printw("|     ");
    attron(COLOR_PAIR(1));
    printw("whyw");
    attron(COLOR_PAIR(2));
    printw("|           ");
    attron(COLOR_PAIR(1));
    printw("WHYWWHYWHYWH");
    attron(COLOR_PAIR(2));
    printw("|");
    attron(COLOR_PAIR(1));
    printw("WHYWHYWHY");
    attron(COLOR_PAIR(2));
    printw("|");
    attron(COLOR_PAIR(1));
    printw("whyw");
    attron(COLOR_PAIR(2));
    printw("|  ");
    attron(COLOR_PAIR(1));
    printw("whyw");
    attron(COLOR_PAIR(2));
    printw("%c ",x);
    attron(COLOR_PAIR(1));
    printw("whyw");
    attron(COLOR_PAIR(2));
    printw("|\n");
    refresh();
    napms(10);

    //Baris kedelapan
    printw(" ");
    attron(COLOR_PAIR(1));
    printw("WHYW");
    attron(COLOR_PAIR(2));
    printw("|");
    attron(COLOR_PAIR(1));
    printw("WHYW");
    attron(COLOR_PAIR(2));
    printw("%c   ",x);
    attron(COLOR_PAIR(1));
    printw("whyhw");
    attron(COLOR_PAIR(2));
    printw("|    ");
    attron(COLOR_PAIR(1));
    printw("WHYWHY");
    attron(COLOR_PAIR(2));
    printw("|     ");
    attron(COLOR_PAIR(1));
    printw("whyw");
    attron(COLOR_PAIR(2));
    printw("%c      ____ ",x);
    attron(COLOR_PAIR(1));
    printw("WHYW");
    attron(COLOR_PAIR(2));
    printw("|   ");
    attron(COLOR_PAIR(1));
    printw("WHYW");
    attron(COLOR_PAIR(2));
    printw("|");
    attron(COLOR_PAIR(1));
    printw("WHYW");
    attron(COLOR_PAIR(2));
    printw("|     ");
    attron(COLOR_PAIR(1));
    printw("whyw");
    attron(COLOR_PAIR(2));
    printw("|   ");
    attron(COLOR_PAIR(1));
    printw("whyw");
    attron(COLOR_PAIR(2));
    printw("%c",x);
    attron(COLOR_PAIR(1));
    printw("whyw");
    attron(COLOR_PAIR(2));
    printw("|\n");
    refresh();
    napms(10);

    //Baris kesembilan
    printw(" ");
    attron(COLOR_PAIR(1));
    printw("WHYW");
    attron(COLOR_PAIR(2));
    printw("| ");
    attron(COLOR_PAIR(1));
    printw("WHYW");
    attron(COLOR_PAIR(2));
    printw("%c  ",x);
    attron(COLOR_PAIR(1));
    printw("whywh");
    attron(COLOR_PAIR(2));
    printw("|    ");
    attron(COLOR_PAIR(1));
    printw("WHYWHY");
    attron(COLOR_PAIR(2));
    printw("|      ");
    attron(COLOR_PAIR(1));
    printw("whyw");
    attron(COLOR_PAIR(2));
    printw("%c_____",x);
    attron(COLOR_PAIR(1));
    printw("whyw");
    attron(COLOR_PAIR(2));
    printw("|");
    attron(COLOR_PAIR(1));
    printw("WHYW");
    attron(COLOR_PAIR(2));
    printw("|   ");
    attron(COLOR_PAIR(1));
    printw("WHYW");
    attron(COLOR_PAIR(2));
    printw("|");
    attron(COLOR_PAIR(1));
    printw("WHYW");
    attron(COLOR_PAIR(2));
    printw("|_____");
    attron(COLOR_PAIR(1));
    printw("whyw");
    attron(COLOR_PAIR(2));
    printw("|    ");
    attron(COLOR_PAIR(1));
    printw("why");
    attron(COLOR_PAIR(2));
    printw(" ");
    attron(COLOR_PAIR(1));
    printw("whyw");
    attron(COLOR_PAIR(2));
    printw("|\n");
    refresh();
    napms(10);

    //Baris Kesepuluh
    printw(" ");
    attron(COLOR_PAIR(1));
    printw("WHYW");
    attron(COLOR_PAIR(2));
    printw("|  ");
    attron(COLOR_PAIR(1));
    printw("WHYW");
    attron(COLOR_PAIR(2));
    printw("%c ",x);
    attron(COLOR_PAIR(1));
    printw("whywh");
    attron(COLOR_PAIR(2));
    printw("|    ");
    attron(COLOR_PAIR(1));
    printw("WHYWHY");
    attron(COLOR_PAIR(2));
    printw("|       ");
    attron(COLOR_PAIR(1));
    printw("whywwhywhywhy");
    attron(COLOR_PAIR(2));
    printw(" ");
    attron(COLOR_PAIR(1));
    printw("WHYW");
    attron(COLOR_PAIR(2));
    printw("|   ");
    attron(COLOR_PAIR(1));
    printw("WHYW");
    attron(COLOR_PAIR(2));
    printw("|");
    attron(COLOR_PAIR(1));
    printw("WHYWHYWHY");
    attron(COLOR_PAIR(2));
    printw("|");
    attron(COLOR_PAIR(1));
    printw("whyw");
    attron(COLOR_PAIR(2));
    printw("|     ");
    attron(COLOR_PAIR(1));
    printw("whywhyw");
    attron(COLOR_PAIR(2));
    printw("|\n");
    refresh();
    napms(10);

    //Baris kesebelas
    printw(" ");
    attron(COLOR_PAIR(1));
    printw("WHYW");
    attron(COLOR_PAIR(2));
    printw("|   ");
    attron(COLOR_PAIR(1));
    printw("WHYW");
    attron(COLOR_PAIR(2));
    printw("|");
    attron(COLOR_PAIR(1));
    printw("whywh");
    attron(COLOR_PAIR(2));
    printw("|    ");
    attron(COLOR_PAIR(1));
    printw("WHYWHY");
    attron(COLOR_PAIR(2));
    printw("|        ");
    attron(COLOR_PAIR(1));
    printw("whywhywhyw");
    attron(COLOR_PAIR(2));
    printw("   ");
    attron(COLOR_PAIR(1));
    printw("WHYW");
    attron(COLOR_PAIR(2));
    printw("|   ");
    attron(COLOR_PAIR(1));
    printw("WHYW");
    attron(COLOR_PAIR(2));
    printw("|");
    attron(COLOR_PAIR(1));
    printw("WHYWHYWHY");
    attron(COLOR_PAIR(2));
    printw("|");
    attron(COLOR_PAIR(1));
    printw("whyw");
    attron(COLOR_PAIR(2));
    printw("|      ");
    attron(COLOR_PAIR(1));
    printw("whywhw");
    attron(COLOR_PAIR(2));
    printw("|\n");
    refresh();
    napms(10);

    refresh();
}

void printeExpanded() {
    int a = 92;
    char x = a;

    initscr();
    start_color();
    init_pair(1,COLOR_WHITE,COLOR_WHITE);
    init_pair(2,COLOR_WHITE,COLOR_BLACK);

    //Baris kesatu
    printw("        ______ ___    ___ _____      ____    _____    ___  _____    ______  _____\n");
    refresh();
    napms(10);

    //Baris kedua
    printw("        ");
    attron(COLOR_PAIR(1));
    printw("whywhy");
    attron(COLOR_PAIR(2));
    printw("|");
    attron(COLOR_PAIR(1));
    printw("why");
    attron(COLOR_PAIR(2));
    printw("%c   ",x);
    attron(COLOR_PAIR(1));
    printw("why");
    attron(COLOR_PAIR(2));
    printw("/");
    attron(COLOR_PAIR(1));
    printw("whywhy");
    attron(COLOR_PAIR(2));
    printw("%c   ",x);
    attron(COLOR_PAIR(1));
    printw("whywh");
    attron(COLOR_PAIR(2));
    printw("%c   ",x);
    attron(COLOR_PAIR(1));
    printw("whywh");
    attron(COLOR_PAIR(2));
    printw("%c   ",x);
    attron(COLOR_PAIR(1));
    printw("why");
    attron(COLOR_PAIR(2));
    printw("|");
    attron(COLOR_PAIR(1));
    printw("whywhy");
    attron(COLOR_PAIR(2));
    printw("%c   ",x);
    attron(COLOR_PAIR(1));
    printw("whywhy");
    attron(COLOR_PAIR(2));
    printw("|");
    attron(COLOR_PAIR(1));
    printw("whywhy");
    attron(COLOR_PAIR(2));
    printw("%c\n",x);
    refresh();
    napms(10);

    //Baris ketiga
    printw("  ____  ");
    attron(COLOR_PAIR(1));
    printw("why");
    attron(COLOR_PAIR(2));
    printw("|__  ");
    attron(COLOR_PAIR(1));
    printw("why");
    attron(COLOR_PAIR(2));
    printw("%c/",x);
    attron(COLOR_PAIR(1));
    printw("why");
    attron(COLOR_PAIR(2));
    printw("/ ");
    attron(COLOR_PAIR(1));
    printw("why");
    attron(COLOR_PAIR(2));
    printw(" ");
    attron(COLOR_PAIR(1));
    printw("why");
    attron(COLOR_PAIR(2));
    printw("| ");
    attron(COLOR_PAIR(1));
    printw("why");
    attron(COLOR_PAIR(2));
    printw("/");
    attron(COLOR_PAIR(1));
    printw("why");
    attron(COLOR_PAIR(2));
    printw("%c  ",x);
    attron(COLOR_PAIR(1));
    printw("whywhy");
    attron(COLOR_PAIR(2));
    printw("%c  ",x);
    attron(COLOR_PAIR(1));
    printw("why");
    attron(COLOR_PAIR(2));
    printw("|");
    attron(COLOR_PAIR(1));
    printw("why");
    attron(COLOR_PAIR(2));
    printw("| ");
    attron(COLOR_PAIR(1));
    printw("why");
    attron(COLOR_PAIR(2));
    printw("%c ",x);
    attron(COLOR_PAIR(1));
    printw("why");
    attron(COLOR_PAIR(2));
    printw("|__ ");
    attron(COLOR_PAIR(1));
    printw("why");
    attron(COLOR_PAIR(2));
    printw("| ");
    attron(COLOR_PAIR(1));
    printw("why");
    attron(COLOR_PAIR(2));
    printw("%c   ____\n",x);
    refresh();
    napms(10);

    //Baris Keempat
    printw(" |____| ");
    attron(COLOR_PAIR(1));
    printw("whywhy");
    attron(COLOR_PAIR(2));
    printw("|   ");
    attron(COLOR_PAIR(1));
    printw("hywhw");
    attron(COLOR_PAIR(2));
    printw("|  ");
    attron(COLOR_PAIR(1));
    printw("whywhy");
    attron(COLOR_PAIR(2));
    printw("/ ");
    attron(COLOR_PAIR(1));
    printw("why");
    attron(COLOR_PAIR(2));
    printw("/__");
    attron(COLOR_PAIR(1));
    printw("why");
    attron(COLOR_PAIR(2));
    printw("%c ",x);
    attron(COLOR_PAIR(1));
    printw("why");
    attron(COLOR_PAIR(2));
    printw("|");
    attron(COLOR_PAIR(1));
    printw("why");
    attron(COLOR_PAIR(2));
    printw("%c ",x);
    attron(COLOR_PAIR(1));
    printw("why");
    attron(COLOR_PAIR(2));
    printw("|");
    attron(COLOR_PAIR(1));
    printw("why");
    attron(COLOR_PAIR(2));
    printw("|  ");
    attron(COLOR_PAIR(1));
    printw("why");
    attron(COLOR_PAIR(2));
    printw("|");
    attron(COLOR_PAIR(1));
    printw("whywhy");
    attron(COLOR_PAIR(2));
    printw("|");
    attron(COLOR_PAIR(1));
    printw("why");
    attron(COLOR_PAIR(2));
    printw("|  ");
    attron(COLOR_PAIR(1));
    printw("why");
    attron(COLOR_PAIR(2));
    printw("| |____|\n");
    refresh();
    napms(10);

    //Baris Kelima
    printw("        ");
    attron(COLOR_PAIR(1));
    printw("why");
    attron(COLOR_PAIR(2));
    printw("|__  ");
    attron(COLOR_PAIR(1));
    printw("why");
    attron(COLOR_PAIR(2));
    printw("/ ");
    attron(COLOR_PAIR(1));
    printw("why");
    attron(COLOR_PAIR(2));
    printw("%c ",x);
    attron(COLOR_PAIR(1));
    printw("why");
    attron(COLOR_PAIR(2));
    printw("|   ");
    attron(COLOR_PAIR(1));
    printw("whywhywhywh");
    attron(COLOR_PAIR(2));
    printw("%c",x);
    attron(COLOR_PAIR(1));
    printw("why");
    attron(COLOR_PAIR(2));
    printw("| ");
    attron(COLOR_PAIR(1));
    printw("why");
    attron(COLOR_PAIR(2));
    printw("%c",x);
    attron(COLOR_PAIR(1));
    printw("hyw");
    attron(COLOR_PAIR(2));
    printw("|");
    attron(COLOR_PAIR(1));
    printw("why");
    attron(COLOR_PAIR(2));
    printw("| ");
    attron(COLOR_PAIR(1));
    printw("why");
    attron(COLOR_PAIR(2));
    printw("/ ");
    attron(COLOR_PAIR(1));
    printw("why");
    attron(COLOR_PAIR(2));
    printw("|__ ");
    attron(COLOR_PAIR(1));
    printw("why");
    attron(COLOR_PAIR(2));
    printw("| ");
    attron(COLOR_PAIR(1));
    printw("why");
    attron(COLOR_PAIR(2));
    printw("/\n");
    refresh();
    napms(10);

    //Baris Keenam

    printw("        ");
    attron(COLOR_PAIR(1));
    printw("whywhy");
    attron(COLOR_PAIR(2));
    printw("|");
    attron(COLOR_PAIR(1));
    printw("why");
    attron(COLOR_PAIR(2));
    printw("/   ");
    attron(COLOR_PAIR(1));
    printw("why");
    attron(COLOR_PAIR(2));
    printw("%c",x);
    attron(COLOR_PAIR(1));
    printw("why");
    attron(COLOR_PAIR(2));
    printw("|   ");
    attron(COLOR_PAIR(1));
    printw("why");
    attron(COLOR_PAIR(2));
    printw("/    ");
    attron(COLOR_PAIR(1));
    printw("why");
    attron(COLOR_PAIR(2));
    printw("|");
    attron(COLOR_PAIR(1));
    printw("why");
    attron(COLOR_PAIR(2));
    printw("|  ");
    attron(COLOR_PAIR(1));
    printw("whywhy");
    attron(COLOR_PAIR(2));
    printw("|");
    attron(COLOR_PAIR(1));
    printw("whywhy");
    attron(COLOR_PAIR(2));
    printw("/   ");
    attron(COLOR_PAIR(1));
    printw("whywhy");
    attron(COLOR_PAIR(2));
    printw("|");
    attron(COLOR_PAIR(1));
    printw("whywhy");
    attron(COLOR_PAIR(2));
    printw("/\n");
    refresh();
    napms(10);

    printw("                                                                               WHY THO...\n");
}

void printTitle () {
    int a = 92;
    int b = 95;
    char x = a;
    char y= b;

    initscr();
    start_color();
    init_pair(1,COLOR_WHITE,COLOR_WHITE);
    init_pair(2,COLOR_WHITE,COLOR_BLACK);
    init_pair(3,COLOR_BLACK,COLOR_WHITE);

    printEngis();
    printKitchen();
    printeExpanded();

    refresh ();
    mvprintw(30,36,"Press Any Key..");

    getch();
    endwin();
}

void InputNama(char Name[30]) {
    char tempName[30];
    cls();
    printf(" ___________________________________________________________\n");
    printf("|                                                           |\n");
    printf("| Input Your Name :                                         |\n");
    printf("|   _____________________________________________________   |\n");
    printf("|  |                                                     |  |\n");
    printf("|  |                                                     |  |\n");
    printf("|  |_____________________________________________________|  |\n");
    printf("|___________________________________________________________|\n");
    gotoxy(6,6);
    printf("test1");
    scanf("%s",tempName);
    while (strlen(tempName) > 20) {
        cls();
        printf(" ___________________________________________________________\n");
        printf("|                                                           |\n");
        printf("| Please input name with 20 characters or less  :           |\n");
        printf("|   _____________________________________________________   |\n");
        printf("|  |                                                     |  |\n");
        printf("|  |                                                     |  |\n");
        printf("|  |_____________________________________________________|  |\n");
        printf("|___________________________________________________________|\n");
        gotoxy(6,6);
        scanf("%s",tempName);
    }

    printf("tes");  
    //strcpy(Name,tempName);
}

void printLoad (int *input) {
    cls();
    printf(" ________________________________\n");
    printf("|                                |\n");
    printf("|                                |\n");
    printf("|  1. New                        |\n");
    printf("|                                |\n");
    printf("|  2. Load                       |\n");
    printf("|                                |\n");
    printf("|  3. Quit                       |\n");
    printf("|                                |\n");
    printf("|  Input the option Number :     |\n");
    printf("|   __________________________   |\n");
    printf("|  |                          |  |\n");
    printf("|  |                          |  |\n");
    printf("|  |__________________________|  |\n");
    printf("|                                |\n");
    printf("|________________________________|\n");
    gotoxy(13,6);
    scanf("%d",input);
    while (*input != 1 && *input != 2 && *input != 3) {
        cls();
        printf(" ________________________________\n");
        printf("|                                |\n");
        printf("|                                |\n");
        printf("|  1. New                        |\n");
        printf("|                                |\n");
        printf("|  2. Load                       |\n");
        printf("|                                |\n");
        printf("|  3. Quit                       |\n");
        printf("|                                |\n");
        printf("|  Please input 1, 2, or 3 :     |\n");
        printf("|   __________________________   |\n");
        printf("|  |                          |  |\n");
        printf("|  |                          |  |\n");
        printf("|  |__________________________|  |\n");
        printf("|                                |\n");
        printf("|________________________________|\n");
        gotoxy(13,6);
        scanf("%d",input);
    }
}
