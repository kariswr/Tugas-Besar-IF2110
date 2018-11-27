
#include <stdio.h>
#include "library.h"
#include <string.h>
#include "waitingcust.h"
#include "arrorder.h"
#include "arrtable.h"
#include "handtray.h"
#include "foodconversion.h"

#define gotoxy(x,y) printf("\033[%d;%dH", (x), (y))
#define cls() printf("\033[H\033[J")


void RoomLayout () {   
    printf(" _________________________________________________________________________________________________________________________\n");
    printf("|                        |                                            |                 |                                 |\n");
    printf("|                        | Money :                                    | Life :          | Time :                          |\n");
    printf("|________________________|____________________________________________|_________________|_________________________________|\n");
    printf("| Waiting Cust           |        |        |        |        |        |        |        |        | Food Stack             |\n");
    printf("|                        |        |        |        |        |        |        |        |        |                        |\n");
    printf("|                        |________|________|________|________|________|________|________|________|                        |\n");
    printf("|                        |        |        |        |        |        |        |        |        |                        |\n");
    printf("|                        |        |        |        |        |        |        |        |        |                        |\n");
    printf("|                        |________|________|________|________|________|________|________|________|                        |\n");
    printf("|                        |        |        |        |        |        |        |        |        |                        |\n");
    printf("|                        |        |        |        |        |        |        |        |        |                        |\n");
    printf("|________________________|________|________|________|________|________|________|________|________|________________________|\n");
    printf("| Order                  |        |        |        |        |        |        |        |        | Hand                   |\n");
    printf("|                        |        |        |        |        |        |        |        |        |                        |\n");
    printf("|                        |________|________|________|________|________|________|________|________|                        |\n");
    printf("|                        |        |        |        |        |        |        |        |        |                        |\n");
    printf("|                        |        |        |        |        |        |        |        |        |                        |\n");
    printf("|                        |________|________|________|________|________|________|________|________|                        |\n");
    printf("|                        |        |        |        |        |        |        |        |        |                        |\n");
    printf("|                        |        |        |        |        |        |        |        |        |                        |\n");
    printf("|                        |________|________|________|________|________|________|________|________|                        |\n");
    printf("|                        |        |        |        |        |        |        |        |        |                        |\n");
    printf("|                        |        |        |        |        |        |        |        |        |                        |\n");
    printf("|                        |________|________|________|________|________|________|________|________|                        |\n");
    printf("|                        |        |        |        |        |        |        |        |        |                        |\n");
    printf("|                        |        |        |        |        |        |        |        |        |                        |\n");
    printf("|________________________|________|________|________|________|________|________|________|________|________________________|\n");
    printf("|                                                                                                                         |\n");
    printf("|                                                                                                                         |\n");
    printf("|                                                                                                                         |\n");
    printf("|                                                                                                                         |\n");
    printf("|_________________________________________________________________________________________________________________________|\n");
    printf("|                                                                                                                         |\n");
    printf("| Command :                                                                                                               |\n");
    printf("|_________________________________________________________________________________________________________________________|\n");
}

void ClearRoomLayout () {
    gotoxy(3,3);
    printf("                       ");
    gotoxy(3,36);
    printf("                                   ");
    gotoxy(3,80);
    printf("         ");
    gotoxy(3,98);
    printf("                         ");
    gotoxy(7,3);
    for (int i = 1; i<= 5; i++) {
        printf("         ");
        gotoxy(7+i,3);
    }
    gotoxy(16,3);
    for (int i=0; i<=12; i++){
        printf("                       ");
        gotoxy(16+i,3);
    }
    for (int i=1; i<=8 ; i++) {
        for (int j=1; j<=8; j++) {
            gotoxy(6+(3*(j-1)),(30 + (9*(i-1))));
            printf("  ");
        }
    }
    gotoxy(7,100);
    for (int i = 1; i<= 5; i++) {
        printf("                       ");
        gotoxy(7+i,100);
    }
    gotoxy(16,100);
    for (int i=0; i<=8; i++){
        printf("                       ");
        gotoxy(16+i,100);
    }

    gotoxy(35,13);
    printf("      ");
    gotoxy(37,1);
}

void UpdateRoomLayout (Player P, Queue Q, ArrOrder Order, MapMatrix R, ArrTable AT,Stack Tray, Stack Hand,ArrFood F){
    int i,j,k,x,y, xpos, ypos;
    char temp[5];
    char *c;
    MapMatrix Map;

    ClearRoomLayout();
    //gotoxy(3,3);
    //printf("%s",P.Name);
    gotoxy(3,36);
    printf("%d",P.Money);
    gotoxy(3,80);
    printf("%d",P.Life);
    gotoxy(3,98);
    printf("%d",P.Time);
    gotoxy(7,3);
    PrintQueue(Q);
    gotoxy(16,3);
    PrintAO(Order);
    Map.NBrsEff = R.NBrsEff;
    Map.NKolEff = R.NKolEff;
    for (i=1; i<= Map.NBrsEff; i++) {
        for (j=1; j<= Map.NKolEff; j++){
            Map.T[i][j] = R.T[i][j];
        }
    }
    for (k=1+(4*(P.Room-1)); k<=(4*(P.Room)); k++){
        if (AT.T[k].Occupied) {
            if (AT.T[k].Cust.Star){
                c = "SS";
            } else {
                c = "CC";
            }
            if (AT.T[k].Capacity == 4) {
                y = AT.T[k].Position.j;
                x = AT.T[k].Position.i;
                Map.T[x][y+1] = c;
                Map.T[x][y+1] = c;
                Map.T[x][y-1] = c;
                Map.T[x][y-1] = c;
                Map.T[x+1][y] = c;
                Map.T[x+1][y] = c;
                Map.T[x-1][y] = c;
                Map.T[x-1][y] = c;
            } else {
                y = AT.T[k].Position.j;
                x = AT.T[k].Position.i;
                Map.T[x][y+1] = c;
                Map.T[x][y+1] = c;
                Map.T[x][y-1] = c;
                Map.T[x][y-1] = c;
            }
        }
    }
    for (i=1; i<= Map.NBrsEff; i++) {
        for (j=1; j<= Map.NKolEff; j++){
            gotoxy(6+(3*(i-1)),(30 + (9*(j-1))));
            printf("%s",Map.T[i][j]);
        }
    }
    if (Tray.TOP != Nil) {
        for (i=1; i<=Tray.TOP; i++){
            gotoxy(6+i,100);
            PrintFoodName(F,Tray.T[i]);
        }
    }
    if (Hand.TOP != Nil) {
        for (i=1; i<=Hand.TOP; i++){
            gotoxy(15+i,100);
            PrintFoodName(F,Hand.T[i]);
        }
    }
    ypos = P.Position.i;
    xpos = P.Position.j;
    gotoxy(3+(3*ypos),21+(9*xpos));
    printf("PP");

    
    gotoxy(30,3);
    printf("                                                                                                                       ");
    gotoxy(37,1);
}

void UpdateKitchen (Player P, Queue Q, ArrOrder Order, MapMatrix R,Stack Tray, Stack Hand,ArrFood F){
    int i,j,ypos,xpos;

    ClearRoomLayout();
    gotoxy(3,36);
    printf("%d",P.Money);
    gotoxy(3,80);
    printf("%d",P.Life);
    gotoxy(3,98);
    printf("%d",P.Time);
    gotoxy(7,3);
    PrintQueue(Q);
    gotoxy(16,3);
    PrintAO(Order);

    for (i=1; i<= R.NBrsEff; i++) {
        for (j=1; j<= R.NKolEff; j++){
            gotoxy(6+(3*(i-1)),(30 + (9*(j-1))));
            printf("%s",R.T[i][j]);
        }
    }
    if (Tray.TOP != Nil) {
        for (i=1; i<=Tray.TOP; i++){
            gotoxy(6+i,100);
            PrintFoodName(F,Tray.T[i]);
        }
    }
    if (Hand.TOP != Nil) {
        for (i=1; i<=Hand.TOP; i++){
            gotoxy(15+i,100);
            PrintFoodName(F,Hand.T[i]);
        }
    }
    ypos = P.Position.i;
    xpos = P.Position.j;
    gotoxy(3+(3*ypos),21+(9*xpos));
    printf("PP");

    gotoxy(30,3);
    printf("                                                                                                                       ");
    gotoxy(37,1);
}