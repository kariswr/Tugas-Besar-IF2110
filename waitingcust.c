#include "waitingcust.h"
#include <stdio.h>
#include <stdlib.h>

/*---------- CUSTOMER ----------*/

/* Constructor */
void NewCustomer (Customer * C) {
    int x;
    
    // Determining customer type
    x = rand() % 5;
    if (x == 0) {
        (*C).Star = true;
        (*C).Patience = InitialPatience / 2;
    } else {
        (*C).Star = false;
        (*C).Patience = InitialPatience;
    }

    // Determining number of persons
    x = rand() % 10;
    if (x > 5) {
        (*C).Persons = 2;
    } else {
        (*C).Persons = 4;
    }
};


/*---------- QUEUE ----------*/

/* Prototypes */
boolean IsQEmpty (Queue Q) {
    return ((Head(Q) == 0) && (Tail(Q) == 0));
};

boolean IsQFull (Queue Q) {
    return (NBElmtQ(Q) == MaxEl(Q));
};

int NBElmtQ (Queue Q) {
    if (IsQEmpty(Q)) {
        return 0;
    } else {
        return (Tail(Q) - Head(Q) + 1);
    }
};

/* Constructor */
void CreateEmptyQ (Queue * Q, int Max) {
    (*Q).T = (Customer *) malloc ((Max + 1) * sizeof(Customer));
    if ((*Q).T != NULL) {
        MaxEl(*Q) = Max;
        Head(*Q) = 0;
        Tail(*Q) = 0;
    } else {
        MaxEl(*Q) = 0;
    }
};

/* Add/Delete queue element */
void AddQ (Queue * Q, Customer C) {
    if (IsQEmpty(*Q)) {
        Head(*Q)++;
        Tail(*Q)++;
    } else {
        Tail(*Q)++;
    }
    InfoTail(*Q) = C;
};

void StarAddQ (Queue * Q, Customer C) {
    if (IsQEmpty(*Q)) {
        Head(*Q)++;
        Tail(*Q)++;
        InfoHead(*Q) = C;
    } else {
        Tail(*Q)++;
        int i;
        i = NBElmtQ(*Q);
        while (((*Q).T[i-1].Star != true) && (i > 1)) {
            (*Q).T[i] = (*Q).T[i-1];
            i--;
        }
        (*Q).T[i] = C;
    }
};

void DelQ (Queue * Q, Customer * C) {
    *C = InfoHead(*Q);
    if (Head(*Q) == Tail(*Q)) {
        Head(*Q) = 0;
        Tail(*Q) = 0;
    } else {
        for (int i = 1; i <= NBElmtQ(*Q); i++) {
            (*Q).T[i] = (*Q).T[i+1];
        }
        Tail(*Q)--;
    }
};

void DelXQ (Queue * Q, int X, Customer * C) {
    if (X == Head(*Q)) {
        DelQ(Q, C);
    } else if (X == Tail(*Q)) {
        *C = InfoTail(*Q);
        Tail(*Q)--;
    } else {
        *C = (*Q).T[X];
        for (int i = X; i < NBElmtQ(*Q); i++) {
            (*Q).T[i] = (*Q).T[i+1];
        }
        Tail(*Q)--;
    }
}

/* Queue changes after 1 tick */
void LessPatientQ (Queue * Q) {
    if (!IsQEmpty(*Q)) {
        for (int i = 1; i <= NBElmtQ(*Q); i++) {
            (*Q).T[i].Patience--;
        }
    }
};

void CustomersLeaveQ (Queue * Q, int * leavingCusts) {
    Customer C;
    int counter;
    counter = 0;
    if (!IsQEmpty(*Q)) {
        for (int i = 1; i <= NBElmtQ(*Q); i++) {
            if ((*Q).T[i].Patience == 0) {
                DelXQ(Q, i, &C);
                i--;
                counter++;
                //printf("A customer has left...\n");
            }
        }
    }
    *leavingCusts = counter;
}

void InitiateQueue (Queue * Q) {
    CreateEmptyQ(Q, MaxQueue);
    Customer C;
    NewCustomer(&C);
    C.Star = false;
    C.Patience = 30;
    AddQ(Q, C);
};

void UpdateQueue (Queue * Q, int * leavingCusts) {
    int x, y;

    // Decrease patience of all customers
    LessPatientQ(Q);
    // Removes customers with patience = 0
    CustomersLeaveQ(Q, &y);
    *leavingCusts = y;
    //printf("%d lives have been lost\n", y);

    // Determines if a new customer is arriving
    x = rand() % 100;
    if (x >= 90) {
        if (!IsQFull(*Q)) {
            Customer C;
            NewCustomer(&C);
            if (C.Star == true) {
                //printf("Incoming star customer!\n");
                StarAddQ(Q, C);
            } else {
                //printf("Incoming regular customer!\n");
                AddQ(Q, C);
            }
        } else {
            // If queue is full, no customers arrive
        }
    } else {
        // No customers arrive
    }
};

/* Print queue */
void PrintQueue (Queue Q) {
    printf("WAITING LINE\n");
    if (IsQEmpty(Q)) {
        printf("Empty queue\n");
    } else {
        for (int i = NBElmtQ(Q); i > 0; i--) {
            for (int j = 1; j <= Q.T[i].Persons; j++) {
                if (Q.T[i].Star == true) {
                    printf("S");
                } else {
                    printf("C");
                }
            }
            printf(" "); PrintPatience(Q.T[i]);
            printf("\n");
        }
    }
};

/* Debugging */
void PrintPatience (Customer C) {
    printf("(%d)", C.Patience);
}