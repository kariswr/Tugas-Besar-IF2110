#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*---------- INCLUDES ----------*/
#include "waitingcust.h"
#include "arrorder.h"
#include "arrtable.h"

/*---------- HEADER ----------*/
void TickPt1 (Queue * Q, ArrTable * AT, ArrOrder * AO, int * LivesLost);
// Updates queue and arrays after 1 tick. Counts how many lives are lost during update.
void PLACE (Queue * Q, ArrTable * AT, ArrOrder * AO, int * LivesLost, Player P);
// Places a customer from the queue to the array of tables
void ORDER (Queue * Q, ArrTable * AT, ArrOrder * AO, int * LivesLost, Player P);
// Takes order from an occupied table

/*---------- BODY ----------*/
void TickPt1 (Queue * Q, ArrTable * AT, ArrOrder * AO, int * LivesLost) {
    int x, lives;
    lives = 0;
    UpdateQueue(Q, &x);
    lives += x;
    UpdateAT(AT, AO, &x);
    lives += x;
    *LivesLost = lives;
}

void PLACE (Queue * Q, ArrTable * AT, ArrOrder * AO, int * LivesLost, Player P) {
    if (!IsQEmpty(*Q)) {
        int x;
        int i;
        i = 1;
        //printf("Finding table for Customer %d.\n", i);
        //printf("NeffAT = %d\n", Neff(AT));
        x = FindEmptyTableFor(P, (*Q).T[i], *AT);
        //printf("Table %d is available.\n", x);
        while ((x == 0) && (i <= NBElmtQ(*Q))) {
            x = FindEmptyTableFor(P, (*Q).T[i], *AT);
            if (x == 0) {
                i++;
            }
        }
        
        if (x != 0) {
            Customer C;
            DelXQ(Q, i, &C);
            ElmtA(*AT, x).Cust = C;
            ElmtA(*AT, x).Occupied = true;
            ElmtA(*AT, x).Cust.Patience += AddPatience;
            //printf("Table %d has %d customers.\n", x, AT.T[x].Cust.Persons);
        }
        TickPt1(Q, AT, AO, LivesLost);
    }
}

void ORDER (Queue * Q, ArrTable * AT, ArrOrder * AO, int * LivesLost, Player P) {
    int x;
    Order O;
    x = TableNearPlayer(P, *AT);
    if ((ElmtA(*AT, x).Occupied) && (SearchAO(*AO, x) == 0)) {
        NewOrder(&O, x);
        AddLastAO(AO, O);
        TickPt1(Q, AT, AO, LivesLost);
    }
}