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

    (*C).TableIndex = 0; 
};


/*---------- QUEUE ----------*/

/* Prototypes */
boolean IsEmpty (Queue Q) {
    return ((Head(Q) == 0) && (Tail(Q) == 0));
};

boolean IsFull (Queue Q) {
    return (NBElmt(Q) == MaxEl(Q));
};

int NBElmt (Queue Q) {
    if (IsEmpty(Q)) {
        return 0;
    } else {
        return (Tail(Q) - Head(Q) + 1);
    }
};

/* Constructor */
void CreateEmpty (Queue * Q, int Max) {
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
void Add (Queue * Q, Customer C) {
    if (IsEmpty(*Q)) {
        Head(*Q)++;
        Tail(*Q)++;
    } else {
        Tail(*Q)++;
    }
    InfoTail(*Q) = C;
};

void StarAdd (Queue * Q, Customer C) {
    if (IsEmpty(*Q)) {
        Head(*Q)++;
        Tail(*Q)++;
        InfoHead(*Q) = C;
    } else {
        Tail(*Q)++;
        int i;
        i = NBElmt(*Q);
        while (((*Q).T[i-1].Star != true) && (i > 1)) {
            (*Q).T[i] = (*Q).T[i-1];
            i--;
        }
        (*Q).T[i] = C;
    }
};

void Del (Queue * Q, Customer * C) {
    *C = InfoHead(*Q);
    if (Head(*Q) == Tail(*Q)) {
        Head(*Q) = 0;
        Tail(*Q) = 0;
    } else {
        for (int i = 1; i <= NBElmt(*Q); i++) {
            (*Q).T[i] = (*Q).T[i+1];
        }
        Tail(*Q)--;
    }
};

void DelX (Queue * Q, int X, Customer * C) {
    if (X == Head(*Q)) {
        Del(Q, C);
    } else if (X == Tail(*Q)) {
        *C = InfoTail(*Q);
        Tail(*Q)--;
    } else {
        *C = (*Q).T[X];
        for (int i = X; i < NBElmt(*Q); i++) {
            (*Q).T[i] = (*Q).T[i+1];
        }
        Tail(*Q)--;
    }
}

/* Queue changes after 1 tick */
void LessPatient (Queue * Q) {
    if (!IsEmpty(*Q)) {
        for (int i = 1; i <= NBElmt(*Q); i++) {
            (*Q).T[i].Patience--;
        }
    }
};

void CustomersLeave (Queue * Q) {
    Customer C;
    if (!IsEmpty(*Q)) {
        for (int i = 1; i <= NBElmt(*Q); i++) {
            if ((*Q).T[i].Patience == 0) {
                DelX(Q, i, &C);
                i--;
                //printf("A customer has left...\n");
            }
        }
    }
}

void InitiateQueue (Queue * Q) {
    CreateEmpty(Q, MaxQueue);
    Customer C;
    NewCustomer(&C);
    C.Star = false;
    C.Patience = 30;
    Add(Q, C);
};

void UpdateQueue (Queue * Q) {
    int x;

    // Decrease patience of all customers
    LessPatient(Q);
    // Removes customers with patience = 0
    CustomersLeave(Q);

    // Determines if a new customer is arriving
    x = rand() % 100;
    if (x >= 90) {
        if (!IsFull(*Q)) {
            Customer C;
            NewCustomer(&C);
            if (C.Star == true) {
                //printf("Incoming star customer!\n");
                StarAdd(Q, C);
            } else {
                //printf("Incoming regular customer!\n");
                Add(Q, C);
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
    if (IsEmpty(Q)) {
        printf("Empty queue\n");
    } else {
        for (int i = NBElmt(Q); i > 0; i--) {
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