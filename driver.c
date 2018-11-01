#include "waitingcust.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    Queue Q;
    Customer C;

/*---------- ADDING AND DELETING A CUSTOMER ---------- 
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


/*---------- TIMER RUNNING SIMULATION ----------*/
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

    return 0;
}