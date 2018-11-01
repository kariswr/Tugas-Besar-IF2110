#include "waitingcust.h"
#include <stdio.h>
#include <stdlib.h>

/*---------- CUSTOMER ----------*/

// Konstruktor Customer
void NewCustomer (Customer * C) {
    int x;
    
    // Menentukan tipe Customer
    x = rand() % 20; // Kemungkinan Star Customer 1/20
    if (x == 20) {
        (*C).Star = true;
        (*C).Patience = InitialPatience / 2;
    } else {
        (*C).Star = false;
        (*C).Patience = InitialPatience;
    }

    // Menentukan jumlah orang Customer
    x = rand() % 2; // Kemungkinan 2 atau 4 50/50
    if (x == 0) {
        (*C).Persons = 2;
    } else {
        (*C).Persons = 4;
    }

    // Customer tidak berada pada Table mana pun
    (*C).TableIndex = 0; 
};


/*---------- QUEUE ----------*/

// Uji Queue
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

// Konstruktor Queue
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

// Tambah/Hapus Elemen Queue
void Add (Queue * Q, Customer C) {
    if (IsEmpty(*Q)) {
        Head(*Q)++;
        Tail(*Q)++;
    } else {
        Tail(*Q)++;
    }
    InfoTail(*Q) = C;
};

void SpecialAdd (Queue * Q, Customer C) {
    if (IsEmpty(*Q)) {
        Head(*Q)++;
        Tail(*Q)++;
    } else {
        Tail(*Q)++;
        for (int i = NBElmt(*Q); i >= 1; i--) {
            (*Q).T[i+1] = (*Q).T[i];
        }
    }
    InfoHead(*Q) = C;
};

void Del (Queue * Q, Customer * C) {
    *C = InfoHead(*Q);
    if (Head(*Q) == Tail(*Q)) {
        Head(*Q) == 0;
        Tail(*Q) == 0;
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
        for (int i = X; X <= NBElmt(*Q); i++) {
            (*Q).T[i] = (*Q).T[i+1];
        }
        Tail(*Q)--;
    }
}

// Menentukan apa yang terjadi pada Queue setelah 1 tick
void LessPatient (Queue * Q) {
    for (int i = 1; i <= NBElmt(*Q); i++) {
        (*Q).T[i].Patience--;
        if ((*Q).T[i].Patience <= 0) {
            Customer C;
            DelX(Q, i, &C);
        }
    }
};

void UpdateQueue (Queue * Q) {
    // Kurangi Patience semua Customer, jika ada yang Patience <= 0, hapus dari Queue
    LessPatient(Q);

    // Menentukan apakah ada Customer baru yang datang
    int x = rand() % 20;
    if (x > 40) {
        Customer C;
        NewCustomer(&C);
        if (C.Star == true) {
            SpecialAdd(Q, C);
        } else {
            Add(Q, C);
        }
    } else {
        // Tidak ada Customer yang datang
    }
}

// Debugging
void PrintQueue (Queue Q) {
    if (IsEmpty(Q)) {
        printf("Empty queue\n"); // debug message
    } else {
        for (int i = 1; i <= NBElmt(Q); i++) {
            for (int j = 1; j <= Q.T[i].Persons; j++) {
                if (Q.T[i].Star == true) {
                    printf("S");
                } else {
                    printf("C");
                }
            }
            printf("\n");
        }
    }
};