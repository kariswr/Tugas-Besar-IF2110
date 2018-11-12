#include "waitingcust.h"
#include "arrorder.h"
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

/*---------- MODIFYING ARRAY OF ORDER ----------*/
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
   

    return 0;
}