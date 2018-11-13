#include "waitingcust.h"
#include "arrorder.h"
#include "arrtable.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

/*---------- ADDING AND DELETING A CUSTOMER ---------- 
    Queue Q;
    Customer C;

    CreateEmpty(&Q, MaxQueue);
    NewCustomer(&C);
    Add(&Q, C);
    NewCustomer(&C);
    Add(&Q, C);
    PrintQueue(Q);
    printf("Head: %d\n", Head(Q));
    printf("Tail: %d\n", Tail(Q));
    DelX(&Q, 2, &C);
    printf("Head: %d\n", Head(Q));
    printf("Tail: %d\n", Tail(Q));
    PrintQueue(Q);
*/


/*---------- TIMER RUNNING SIMULATION ----------
    Queue Q;
    Customer C;
    int timer;
    char command;

    srand(time(0));

    timer = 1;
    InitiateQueue(&Q);
    printf("Time = %d\n", timer);
    PrintQueue(Q);
    printf("\n");

    scanf("%c", &command);
    while (command != 'x') {
        if (command == 'p') {
            timer++;
            UpdateQueue(&Q);
            printf("Time = %d\n", timer);
            PrintQueue(Q);
            printf("\n");
        }
        scanf("%c", &command);
    }
*/

/*---------- MODIFYING ARRAY OF ORDER ----------
    ArrOrder AO;
    Order O;
    srand(time(0));

    MakeEmptyAO(&AO);
    
    NewOrder(&O, 1);
    AddLastAO(&AO, O);
    NewOrder(&O, 10);
    AddLastAO(&AO, O);
    NewOrder(&O, 11);
    AddLastAO(&AO, O);
    NewOrder(&O, 12);
    AddLastAO(&AO, O);

    printf("Index of last order: %d\n\n", SearchAO(AO, O.DishKey, O.TableIndex));

    PrintAO(AO); printf("\n");

    NewOrder(&O, 12);
    if (HasOrdered(AO, 12)) {
        printf("This table has ordered.\n\n");
    } else {
        AddLastAO(&AO, O);
    }

    DelXAO(&AO, 1, &O);
    DelXAO(&AO, 3, &O);
    DelXAO(&AO, 3, &O);
    PrintAOWithIndex(AO);
*/

/*---------- ARRTABLE AND STUFF ----------*/
    MapMatrix R1, R2, R3;
    R1.NBrsEff = 8;
    R2.NBrsEff = 8;
    R3.NBrsEff = 8;
    R1.NKolEff = 8;
    R2.NKolEff = 8;
    R3.NKolEff = 8;

    R1.T[1][1] = "--"; R1.T[1][2] = "XX"; R1.T[1][3] = "--"; R1.T[1][4] = "--"; R1.T[1][5] = "--"; R1.T[1][6] = "--"; R1.T[1][7] = "--"; R1.T[1][8] = "--";
    R1.T[2][1] = "XX"; R1.T[2][2] = "01"; R1.T[2][3] = "XX"; R1.T[2][4] = "--"; R1.T[2][5] = "--"; R1.T[2][6] = "XX"; R1.T[2][7] = "03"; R1.T[2][8] = "XX";
    R1.T[3][1] = "--"; R1.T[3][2] = "XX"; R1.T[3][3] = "--"; R1.T[3][4] = "--"; R1.T[3][5] = "--"; R1.T[3][6] = "--"; R1.T[3][7] = "--"; R1.T[3][8] = "--";
    R1.T[4][1] = "--"; R1.T[4][2] = "--"; R1.T[4][3] = "--"; R1.T[4][4] = "--"; R1.T[4][5] = "--"; R1.T[4][6] = "--"; R1.T[4][7] = "--"; R1.T[4][8] = "--";
    R1.T[5][1] = "--"; R1.T[5][2] = "--"; R1.T[5][3] = "--"; R1.T[5][4] = "--"; R1.T[5][5] = "--"; R1.T[5][6] = "--"; R1.T[5][7] = "--"; R1.T[5][8] = "--";
    R1.T[6][1] = "--"; R1.T[6][2] = "XX"; R1.T[6][3] = "--"; R1.T[6][4] = "--"; R1.T[6][5] = "--"; R1.T[6][6] = "--"; R1.T[6][7] = "--"; R1.T[6][8] = "--";
    R1.T[7][1] = "XX"; R1.T[7][2] = "02"; R1.T[7][3] = "XX"; R1.T[7][4] = "--"; R1.T[7][5] = "--"; R1.T[7][6] = "XX"; R1.T[7][7] = "04"; R1.T[7][8] = "XX";
    R1.T[8][1] = "--"; R1.T[8][2] = "XX"; R1.T[8][3] = "--"; R1.T[8][4] = "--"; R1.T[8][5] = "--"; R1.T[8][6] = "--"; R1.T[8][7] = "--"; R1.T[8][8] = "--";

    R2.T[1][1] = "--"; R2.T[1][2] = "XX"; R2.T[1][3] = "--"; R2.T[1][4] = "--"; R2.T[1][5] = "--"; R2.T[1][6] = "--"; R2.T[1][7] = "--"; R2.T[1][8] = "--";
    R2.T[2][1] = "XX"; R2.T[2][2] = "05"; R2.T[2][3] = "XX"; R2.T[2][4] = "--"; R2.T[2][5] = "--"; R2.T[2][6] = "XX"; R2.T[2][7] = "07"; R2.T[2][8] = "XX";
    R2.T[3][1] = "--"; R2.T[3][2] = "XX"; R2.T[3][3] = "--"; R2.T[3][4] = "--"; R2.T[3][5] = "--"; R2.T[3][6] = "--"; R2.T[3][7] = "--"; R2.T[3][8] = "--";
    R2.T[4][1] = "--"; R2.T[4][2] = "--"; R2.T[4][3] = "--"; R2.T[4][4] = "--"; R2.T[4][5] = "--"; R2.T[4][6] = "--"; R2.T[4][7] = "--"; R2.T[4][8] = "--";
    R2.T[5][1] = "--"; R2.T[5][2] = "--"; R2.T[5][3] = "--"; R2.T[5][4] = "--"; R2.T[5][5] = "--"; R2.T[5][6] = "--"; R2.T[5][7] = "--"; R2.T[5][8] = "--";
    R2.T[6][1] = "--"; R2.T[6][2] = "XX"; R2.T[6][3] = "--"; R2.T[6][4] = "--"; R2.T[6][5] = "--"; R2.T[6][6] = "--"; R2.T[6][7] = "--"; R2.T[6][8] = "--";
    R2.T[7][1] = "XX"; R2.T[7][2] = "06"; R2.T[7][3] = "XX"; R2.T[7][4] = "--"; R2.T[7][5] = "--"; R2.T[7][6] = "XX"; R2.T[7][7] = "08"; R2.T[7][8] = "XX";
    R2.T[8][1] = "--"; R2.T[8][2] = "XX"; R2.T[8][3] = "--"; R2.T[8][4] = "--"; R2.T[8][5] = "--"; R2.T[8][6] = "--"; R2.T[8][7] = "--"; R2.T[8][8] = "--";

    R3.T[1][1] = "--"; R3.T[1][2] = "XX"; R3.T[1][3] = "--"; R3.T[1][4] = "--"; R3.T[1][5] = "--"; R3.T[1][6] = "--"; R3.T[1][7] = "--"; R3.T[1][8] = "--";
    R3.T[2][1] = "XX"; R3.T[2][2] = "09"; R3.T[2][3] = "XX"; R3.T[2][4] = "--"; R3.T[2][5] = "--"; R3.T[2][6] = "XX"; R3.T[2][7] = "11"; R3.T[2][8] = "XX";
    R3.T[3][1] = "--"; R3.T[3][2] = "XX"; R3.T[3][3] = "--"; R3.T[3][4] = "--"; R3.T[3][5] = "--"; R3.T[3][6] = "--"; R3.T[3][7] = "--"; R3.T[3][8] = "--";
    R3.T[4][1] = "--"; R3.T[4][2] = "--"; R3.T[4][3] = "--"; R3.T[4][4] = "--"; R3.T[4][5] = "--"; R3.T[4][6] = "--"; R3.T[4][7] = "--"; R3.T[4][8] = "--";
    R3.T[5][1] = "--"; R3.T[5][2] = "--"; R3.T[5][3] = "--"; R3.T[5][4] = "--"; R3.T[5][5] = "--"; R3.T[5][6] = "--"; R3.T[5][7] = "--"; R3.T[5][8] = "--";
    R3.T[6][1] = "--"; R3.T[6][2] = "XX"; R3.T[6][3] = "--"; R3.T[6][4] = "--"; R3.T[6][5] = "--"; R3.T[6][6] = "--"; R3.T[6][7] = "--"; R3.T[6][8] = "--";
    R3.T[7][1] = "XX"; R3.T[7][2] = "10"; R3.T[7][3] = "XX"; R3.T[7][4] = "--"; R3.T[7][5] = "--"; R3.T[7][6] = "XX"; R3.T[7][7] = "12"; R3.T[7][8] = "XX";
    R3.T[8][1] = "--"; R3.T[8][2] = "XX"; R3.T[8][3] = "--"; R3.T[8][4] = "--"; R3.T[8][5] = "--"; R3.T[8][6] = "--"; R3.T[8][7] = "--"; R3.T[8][8] = "--";

    ArrTable AT;
    InitiateAT(R1, R2, R3, &AT);
    PrintAT(AT);

    Player P;
    P.Life = 0;
    P.Money = 0;
    P.Name = "Dummy";
    P.Position.i = 1;
    P.Position.j = 1;
    P.Room = 1;
    P.Time = 0;

    Customer C;
    C.Patience = 0;
    C.Persons = 2;
    C.Star = true;

    int x;
    int y;
    x = TableNearPlayer(P, AT);
    printf("Player is near Table %d.\n", x);
    y = FindEmptyTableFor(P, C, AT);
    printf("Table %d is available.\n", y);

    return 0;
}