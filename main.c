#include <stdio.h>
#include "library.h"
#include "commands.c"
#include "title.c"
#include "printRoom.c"
#include "foodconversion.h"
#include <ncurses.h>
#include <unistd.h>

#define gotoxy(x,y) printf("\033[%d;%dH", (x), (y))
#define cls() printf("\033[H\033[J")

int main () {
	Player P;
    char name[30];
    char input[5];
    char command[5];
    int x;
    int i, cust; 
    int tempx,tempy;
    Queue Q;
    ArrOrder AO;
    Order O;
    ArrCounter AC;
    Point PosTray;
    ArrTable  AT;
    Stack Hand;
    Stack Tray;
    FoodTree FT;
    ArrFood F;
    Graph G;
    MapMatrix R1,R2,R3,RK;
    RK.NBrsEff = 8;
    R1.NBrsEff = 8;
    R2.NBrsEff = 8;
    R3.NBrsEff = 8;
    RK.NKolEff = 8;
    R1.NKolEff = 8;
    R2.NKolEff = 8;
    R3.NKolEff = 8;
    
    R1.T[1][1] = "--"; R1.T[1][2] = "XX"; R1.T[1][3] = "--"; R1.T[1][4] = "--"; R1.T[1][5] = "--"; R1.T[1][6] = "--"; R1.T[1][7] = "--"; R1.T[1][8] = "--";
    R1.T[2][1] = "XX"; R1.T[2][2] = "01"; R1.T[2][3] = "XX"; R1.T[2][4] = "--"; R1.T[2][5] = "--"; R1.T[2][6] = "XX"; R1.T[2][7] = "02"; R1.T[2][8] = "XX";
    R1.T[3][1] = "--"; R1.T[3][2] = "XX"; R1.T[3][3] = "--"; R1.T[3][4] = "--"; R1.T[3][5] = "--"; R1.T[3][6] = "--"; R1.T[3][7] = "--"; R1.T[3][8] = "--";
    R1.T[4][1] = "--"; R1.T[4][2] = "--"; R1.T[4][3] = "--"; R1.T[4][4] = "--"; R1.T[4][5] = "--"; R1.T[4][6] = "--"; R1.T[4][7] = "--"; R1.T[4][8] = "--";
    R1.T[5][1] = "--"; R1.T[5][2] = "--"; R1.T[5][3] = "--"; R1.T[5][4] = "--"; R1.T[5][5] = "--"; R1.T[5][6] = "--"; R1.T[5][7] = "--"; R1.T[5][8] = "DD";
    R1.T[6][1] = "--"; R1.T[6][2] = "XX"; R1.T[6][3] = "--"; R1.T[6][4] = "--"; R1.T[6][5] = "--"; R1.T[6][6] = "--"; R1.T[6][7] = "--"; R1.T[6][8] = "--";
    R1.T[7][1] = "XX"; R1.T[7][2] = "03"; R1.T[7][3] = "XX"; R1.T[7][4] = "--"; R1.T[7][5] = "--"; R1.T[7][6] = "XX"; R1.T[7][7] = "04"; R1.T[7][8] = "XX";
    R1.T[8][1] = "--"; R1.T[8][2] = "XX"; R1.T[8][3] = "--"; R1.T[8][4] = "--"; R1.T[8][5] = "DD"; R1.T[8][6] = "--"; R1.T[8][7] = "--"; R1.T[8][8] = "--";

    R2.T[1][1] = "--"; R2.T[1][2] = "--"; R2.T[1][3] = "--"; R2.T[1][4] = "--"; R2.T[1][5] = "--"; R2.T[1][6] = "--"; R2.T[1][7] = "XX"; R2.T[1][8] = "--";
    R2.T[2][1] = "DD"; R2.T[2][2] = "--"; R2.T[2][3] = "__"; R2.T[2][4] = "--"; R2.T[2][5] = "--"; R2.T[2][6] = "XX"; R2.T[2][7] = "06"; R2.T[2][8] = "XX";
    R2.T[3][1] = "--"; R2.T[3][2] = "--"; R2.T[3][3] = "--"; R2.T[3][4] = "--"; R2.T[3][5] = "--"; R2.T[3][6] = "--"; R2.T[3][7] = "XX"; R2.T[3][8] = "--";
    R2.T[4][1] = "XX"; R2.T[4][2] = "05"; R2.T[4][3] = "XX"; R2.T[4][4] = "--"; R2.T[4][5] = "--"; R2.T[4][6] = "--"; R2.T[4][7] = "--"; R2.T[4][8] = "--";
    R2.T[5][1] = "--"; R2.T[5][2] = "--"; R2.T[5][3] = "--"; R2.T[5][4] = "--"; R2.T[5][5] = "--"; R2.T[5][6] = "--"; R2.T[5][7] = "--"; R2.T[5][8] = "--";
    R2.T[6][1] = "--"; R2.T[6][2] = "--"; R2.T[6][3] = "--"; R2.T[6][4] = "--"; R2.T[6][5] = "--"; R2.T[6][6] = "--"; R2.T[6][7] = "XX"; R2.T[6][8] = "--";
    R2.T[7][1] = "XX"; R2.T[7][2] = "07"; R2.T[7][3] = "XX"; R2.T[7][4] = "--"; R2.T[7][5] = "--"; R2.T[7][6] = "XX"; R2.T[7][7] = "08"; R2.T[7][8] = "XX";
    R2.T[8][1] = "--"; R2.T[8][2] = "--"; R2.T[8][3] = "--"; R2.T[8][4] = "--"; R2.T[8][5] = "--"; R2.T[8][6] = "--"; R2.T[8][7] = "Xx"; R2.T[8][8] = "--";

    R3.T[1][1] = "--"; R3.T[1][2] = "--"; R3.T[1][3] = "--"; R3.T[1][4] = "--"; R3.T[1][5] = "DD"; R3.T[1][6] = "--"; R3.T[1][7] = "--"; R3.T[1][8] = "--";
    R3.T[2][1] = "DD"; R3.T[2][2] = "--"; R3.T[2][3] = "--"; R3.T[2][4] = "--"; R3.T[2][5] = "--"; R3.T[2][6] = "--"; R3.T[2][7] = "--"; R3.T[2][8] = "--";
    R3.T[3][1] = "--"; R3.T[3][2] = "XX"; R3.T[3][3] = "09"; R3.T[3][4] = "XX"; R3.T[3][5] = "--"; R3.T[3][6] = "--"; R3.T[3][7] = "XX"; R3.T[3][8] = "--";
    R3.T[4][1] = "--"; R3.T[4][2] = "--"; R3.T[4][3] = "--"; R3.T[4][4] = "--"; R3.T[4][5] = "--"; R3.T[4][6] = "XX"; R3.T[4][7] = "10"; R3.T[4][8] = "XX";
    R3.T[5][1] = "--"; R3.T[5][2] = "--"; R3.T[5][3] = "--"; R3.T[5][4] = "--"; R3.T[5][5] = "--"; R3.T[5][6] = "--"; R3.T[5][7] = "XX"; R3.T[5][8] = "--";
    R3.T[6][1] = "--"; R3.T[6][2] = "--"; R3.T[6][3] = "XX"; R3.T[6][4] = "--"; R3.T[6][5] = "--"; R3.T[6][6] = "--"; R3.T[6][7] = "--"; R3.T[6][8] = "--";
    R3.T[7][1] = "--"; R3.T[7][2] = "XX"; R3.T[7][3] = "10"; R3.T[7][4] = "XX"; R3.T[7][5] = "--"; R3.T[7][6] = "--"; R3.T[7][7] = "--"; R3.T[7][8] = "--";
    R3.T[8][1] = "--"; R3.T[8][2] = "--"; R3.T[8][3] = "XX"; R3.T[8][4] = "--"; R3.T[8][5] = "--"; R3.T[8][6] = "XX"; R3.T[8][7] = "12"; R3.T[8][8] = "XX";

    RK.T[1][1] = "aa"; RK.T[1][2] = "--"; RK.T[1][3] = "--"; RK.T[1][4] = "--"; RK.T[1][5] = "--"; RK.T[1][6] = "--"; RK.T[1][7] = "--"; RK.T[1][8] = "TT";
    RK.T[2][1] = "bb"; RK.T[2][2] = "--"; RK.T[2][3] = "--"; RK.T[2][4] = "--"; RK.T[2][5] = "--"; RK.T[2][6] = "--"; RK.T[2][7] = "--"; RK.T[2][8] = "--";
    RK.T[3][1] = "cc"; RK.T[3][2] = "--"; RK.T[3][3] = "--"; RK.T[3][4] = "--"; RK.T[3][5] = "--"; RK.T[3][6] = "--"; RK.T[3][7] = "--"; RK.T[3][8] = "--";
    RK.T[4][1] = "dd"; RK.T[4][2] = "--"; RK.T[4][3] = "--"; RK.T[4][4] = "--"; RK.T[4][5] = "--"; RK.T[4][6] = "--"; RK.T[4][7] = "--"; RK.T[4][8] = "--";
    RK.T[5][1] = "ee"; RK.T[5][2] = "--"; RK.T[5][3] = "--"; RK.T[5][4] = "ii"; RK.T[5][5] = "jj"; RK.T[5][6] = "vv"; RK.T[5][7] = "--"; RK.T[5][8] = "--";
    RK.T[6][1] = "ff"; RK.T[6][2] = "--"; RK.T[6][3] = "--"; RK.T[6][4] = "--"; RK.T[6][5] = "--"; RK.T[6][6] = "--"; RK.T[6][7] = "--"; RK.T[6][8] = "--";
    RK.T[7][1] = "gg"; RK.T[7][2] = "--"; RK.T[7][3] = "--"; RK.T[7][4] = "--"; RK.T[7][5] = "--"; RK.T[7][6] = "--"; RK.T[7][7] = "--"; RK.T[7][8] = "--";
    RK.T[8][1] = "hh"; RK.T[8][2] = "--"; RK.T[8][3] = "--"; RK.T[8][4] = "kk"; RK.T[8][5] = "ll"; RK.T[8][6] = "mm"; RK.T[8][7] = "nn"; RK.T[8][8] = "oo";
    int LivesLost;

    printTitle();
    printLoad(&x);
    MakeGraph(&G);
    if (x == 1) {
    	InputNama(P.Name);
        //scanf("%d",&i);
        MakeEmptyFood(&F);
        ReadFood(&F);
        CreateEmptyStack(&Tray);
        CreateEmptyStack(&Hand);
        MakeEmptyAO(&AO);
        InitiateQueue(&Q);
        InitiateAT(R1,R2,R3,&AT);
        STARTTREE();
        BuildTree(&FT);
        MakeEmptyFood(&F);
        ReadFood(&F);
        MakeGraph(&G);
        ReadCounter(RK,&AC,&PosTray);
        P.Room = 1;
        P.Position.i =4;
        P.Position.j=4;
        P.Time =0;
        P.Money =0;
        P.Life = 100;
        cls();
        RoomLayout();
        UpdateRoomLayout(P,Q,AO,R1,AT,Tray,Hand,F);
        while (P.Life >0 ) {
            gotoxy(35,13);
            scanf("%s",command);
            if (command[0] == 'G' && command[1] =='U') {
                if (P.Room == 0) {
                    GU(AT,AC,PosTray,RK,&P,G); 
                    printf("%d\n",P.Room);   
                } else
                if (P.Room == 1) {
                    GU(AT,AC,PosTray,R1,&P,G);
                } else
                if (P.Room == 2) {
                    GU(AT,AC,PosTray,R2,&P,G);
                } else {
                    GU(AT,AC,PosTray,R3,&P,G);
                }
                TickPt1(&Q,&AT,&AO,&LivesLost);
                P.Life -= LivesLost;
                P.Time +=1;
                if (P.Room == 0) {
                    UpdateKitchen(P,Q,AO,RK,Tray,Hand,F);    
                } else
                if (P.Room == 1) {
                    UpdateRoomLayout(P,Q,AO,R1,AT,Tray,Hand,F);
                } else
                if (P.Room == 2) {
                    UpdateRoomLayout(P,Q,AO,R2,AT,Tray,Hand,F);
                } else {
                    UpdateRoomLayout(P,Q,AO,R3,AT,Tray,Hand,F);
                }
            } else 
            if (command[0] == 'G' && command[1]=='D') {
                if (P.Room == 0) {
                    GD(AT,AC,PosTray,RK,&P,G);    
                } else
                if (P.Room == 1) {
                    GD(AT,AC,PosTray,R1,&P,G);
                } else
                if (P.Room == 2) {
                    GD(AT,AC,PosTray,R2,&P,G);
                } else {
                    GD(AT,AC,PosTray,R3,&P,G);
                }
                TickPt1(&Q,&AT,&AO,&LivesLost);
                P.Life -= LivesLost;
                P.Time +=1;
                if (P.Room == 0) {
                    UpdateKitchen(P,Q,AO,RK,Tray,Hand,F);    
                } else
                if (P.Room == 1) {
                    UpdateRoomLayout(P,Q,AO,R1,AT,Tray,Hand,F);
                } else
                if (P.Room == 2) {
                    UpdateRoomLayout(P,Q,AO,R2,AT,Tray,Hand,F);
                } else {
                    UpdateRoomLayout(P,Q,AO,R3,AT,Tray,Hand,F);
                }
            } else 
            if (command[0] == 'G' && command[1] =='L') {
                if (P.Room == 0) {
                    GL(AT,AC,PosTray,RK,&P,G);    
                } else
                if (P.Room == 1) {
                    GL(AT,AC,PosTray,R1,&P,G);
                } else
                if (P.Room == 2) {
                    GL(AT,AC,PosTray,R2,&P,G);
                } else {
                    GL(AT,AC,PosTray,R3,&P,G);
                }
                TickPt1(&Q,&AT,&AO,&LivesLost);
                P.Life -= LivesLost;
                P.Time +=1;
                if (P.Room == 0) {
                    UpdateKitchen(P,Q,AO,RK,Tray,Hand,F);    
                } else
                if (P.Room == 1) {
                    UpdateRoomLayout(P,Q,AO,R1,AT,Tray,Hand,F);
                } else
                if (P.Room == 2) {
                    UpdateRoomLayout(P,Q,AO,R2,AT,Tray,Hand,F);
                } else {
                    UpdateRoomLayout(P,Q,AO,R3,AT,Tray,Hand,F);
                }
            } else 
            if (command[0] == 'G' && command[1]=='R') {
                if (P.Room == 0) {
                    GR(AT,AC,PosTray,RK,&P,G);    
                } else
                if (P.Room == 1) {
                    GR(AT,AC,PosTray,R1,&P,G);
                } else
                if (P.Room == 2) {
                    GR(AT,AC,PosTray,R2,&P,G);
                } else {
                    GR(AT,AC,PosTray,R3,&P,G);
                }
                TickPt1(&Q,&AT,&AO,&LivesLost);
                P.Life -= LivesLost;
                P.Time +=1;
                if (P.Room == 0) {
                    UpdateKitchen(P,Q,AO,RK,Tray,Hand,F);    
                } else
                if (P.Room == 1) {
                    UpdateRoomLayout(P,Q,AO,R1,AT,Tray,Hand,F);
                } else
                if (P.Room == 2) {
                    UpdateRoomLayout(P,Q,AO,R2,AT,Tray,Hand,F);
                } else {
                    UpdateRoomLayout(P,Q,AO,R3,AT,Tray,Hand,F);
                }
            } else 
            if (command[0] == 'O' && command[1] == 'R' && command[2] == 'D' && command[3] == 'E' && command[4] == 'R') {
                ORDER(&Q,&AT,&AO,&LivesLost,P);
                TickPt1(&Q,&AT,&AO,&LivesLost);
                P.Life -= LivesLost;
                P.Time += 1;
                if (P.Room == 0) {
                    UpdateKitchen(P,Q,AO,RK,Tray,Hand,F);    
                } else
                if (P.Room == 1) {
                    UpdateRoomLayout(P,Q,AO,R1,AT,Tray,Hand,F);
                } else
                if (P.Room == 2) {
                    UpdateRoomLayout(P,Q,AO,R2,AT,Tray,Hand,F);
                } else {
                    UpdateRoomLayout(P,Q,AO,R3,AT,Tray,Hand,F);
                }
            } else 
            if (command[0] == 'P' && command[1] == 'U' && command[2] == 'T') {
                PUT(P,PosTray.i,PosTray.j,&Hand,&Tray,FT);
                TickPt1(&Q,&AT,&AO,&LivesLost);
                P.Life -= LivesLost;
                P.Time += 1;
                if (P.Room == 0) {
                    UpdateKitchen(P,Q,AO,RK,Tray,Hand,F);    
                } else
                if (P.Room == 1) {
                    UpdateRoomLayout(P,Q,AO,R1,AT,Tray,Hand,F);
                } else
                if (P.Room == 2) {
                    UpdateRoomLayout(P,Q,AO,R2,AT,Tray,Hand,F);
                } else {
                    UpdateRoomLayout(P,Q,AO,R3,AT,Tray,Hand,F);
                }
            } else
            if (command[0] == 'T' && command[1] == 'A' && command[2] == 'K' && command[3] == 'E') {
                TAKE(P, AC,&Hand);
                TickPt1(&Q,&AT,&AO,&LivesLost);
                P.Life -= LivesLost;
                P.Time += 1;

                if (P.Room == 0) {
                    UpdateKitchen(P,Q,AO,RK,Tray,Hand,F);    
                } else
                if (P.Room == 1) {
                    UpdateRoomLayout(P,Q,AO,R1,AT,Tray,Hand,F);
                } else
                if (P.Room == 2) {
                    UpdateRoomLayout(P,Q,AO,R2,AT,Tray,Hand,F);
                } else {
                    UpdateRoomLayout(P,Q,AO,R3,AT,Tray,Hand,F);
                }
            } else
            if (command[0] == 'C' && command[1] == 'H') {
                CH(&Hand);
                TickPt1(&Q,&AT,&AO,&LivesLost);
                P.Life -= LivesLost;
                P.Time += 1;
                 if (P.Room == 0) {
                    UpdateKitchen(P,Q,AO,RK,Tray,Hand,F);    
                } else
                if (P.Room == 1) {
                    UpdateRoomLayout(P,Q,AO,R1,AT,Tray,Hand,F);
                } else
                if (P.Room == 2) {
                    UpdateRoomLayout(P,Q,AO,R2,AT,Tray,Hand,F);
                } else {
                    UpdateRoomLayout(P,Q,AO,R3,AT,Tray,Hand,F);
                }
            } else
            if (command[0] == 'C' && command[1] == 'T') {
                CT(&Tray);
                TickPt1(&Q,&AT,&AO,&LivesLost);
                P.Life -= LivesLost;
                P.Time += 1;
                 if (P.Room == 0) {
                    UpdateKitchen(P,Q,AO,RK,Tray,Hand,F);    
                } else
                if (P.Room == 1) {
                    UpdateRoomLayout(P,Q,AO,R1,AT,Tray,Hand,F);
                } else
                if (P.Room == 2) {
                    UpdateRoomLayout(P,Q,AO,R2,AT,Tray,Hand,F);
                } else {
                    UpdateRoomLayout(P,Q,AO,R3,AT,Tray,Hand,F);
                }
            } else
            if (command[0] == 'P' && command[1] == 'L' && command[2] == 'A' && command[3] == 'C' && command[4] == 'E') {
                PLACE(&Q,&AT,&AO,&LivesLost,P);
                TickPt1(&Q,&AT,&AO,&LivesLost);
                P.Life -= LivesLost;
                P.Time += 1;
                UpdateRoomLayout(P,Q,AO,R1,AT,Tray,Hand,F);
            } else 
            if (command[0] == 'G' && command[1] == 'I' && command[2] == 'V' && command[3] == 'E') {
                GIVE(&P,&AT,&AO,&Tray);
                TickPt1(&Q,&AT,&AO,&LivesLost);
                P.Life -= LivesLost;
                P.Time += 1;
                UpdateRoomLayout(P,Q,AO,R1,AT,Tray,Hand,F);
            } else
            if (command[0] == 'R'&& command[1] == 'E' && command[2] == 'C' && command[3] == 'I' && command[4] == 'P' && command[5] == 'E') {
                RECIPE(FT,F);
                if (P.Room == 0) {
                    UpdateKitchen(P,Q,AO,RK,Tray,Hand,F);    
                } else
                if (P.Room == 1) {
                    UpdateRoomLayout(P,Q,AO,R1,AT,Tray,Hand,F);
                } else
                if (P.Room == 2) {
                    UpdateRoomLayout(P,Q,AO,R2,AT,Tray,Hand,F);
                } else {
                    UpdateRoomLayout(P,Q,AO,R3,AT,Tray,Hand,F);
                }
            } else 
            if (command[0] == 'H' && command[1] == 'I' && command[2] == 'N' && command[3] == 'T') {
                HINT(F);
                TickPt1(&Q,&AT,&AO,&LivesLost);
                if (P.Room == 0) {
                    UpdateKitchen(P,Q,AO,RK,Tray,Hand,F);    
                } else
                if (P.Room == 1) {
                    UpdateRoomLayout(P,Q,AO,R1,AT,Tray,Hand,F);
                } else
                if (P.Room == 2) {
                    UpdateRoomLayout(P,Q,AO,R2,AT,Tray,Hand,F);
                } else {
                    UpdateRoomLayout(P,Q,AO,R3,AT,Tray,Hand,F);
                }
            }else
            if (command[0] == 'Q' && command[1] == 'U' && command[2] == 'I' && command[3] == 'T') {
                QUIT();
            } else
            if (command == "SAVE"){

            }
        }
        
    } else 
    if (x == 2) {
        cls();
        gotoxy(16,36);
        printf("Sory, no program were made by the programmers who were assigned to this part of the program\n");
    } else {//input = 3 
        QUIT();
    }
    if (P.Life <= 0) {
        gotoxy(16,36);
        printf("Game Over");
    }
	return 0;
}


