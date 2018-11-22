#include <stdio.h>
#include <stdlib.h>
#include "arrorder.h"

/*---------- ORDER ----------*/
/* Constructor */
void NewOrder (Order * O, int Idx) {
    int x = rand() % 8;
    switch (x) {
        case 0: (*O).DishKey = 'p'; break;
        case 1: (*O).DishKey = 'q'; break;
        case 2: (*O).DishKey = 'r'; break;
        case 3: (*O).DishKey = 's'; break;
        case 4: (*O).DishKey = 't'; break;
        case 5: (*O).DishKey = 'u'; break;
        case 6: (*O).DishKey = 'v'; break;
        case 7: (*O).DishKey = 'w'; break;
    }
    //printf("X = %d; C = %c\n", x, (*O).DishKey);
    (*O).TableIndex = Idx;
};

/*---------- ARRAY OF ORDER ----------*/
/* Constructor */
void MakeEmptyAO (ArrOrder * AO) {
    Neff(*AO) = 0;
};

/* Miscellaneous */
boolean IsAOEmpty (ArrOrder AO) {
    return (Neff(AO) == 0);
};

boolean IsAOFull (ArrOrder AO) {
    return (Neff(AO) == MaxOrder);
};

int SearchAO (ArrOrder AO, int TableIndex) {
    int i;
    boolean Found;
    i = 1;
    Found = false;
    while ((i <= Neff(AO)) && (!Found)) {
        if (ElmtA(AO, i).TableIndex == TableIndex) {
            Found = true;
        } else {
            i++;
        }
    }
    if (Found) {
        return i;
    } else {
        return 0;
    }
};

/* Add/Delete array elements */
void AddLastAO (ArrOrder * AO, Order O) {
    if (IsAOFull(*AO)) {
        printf("Order array is full.\n");
    } else {
        Neff(*AO)++;
        ElmtA(*AO, Neff(*AO)) = O;
    }
};

void DelXAO (ArrOrder * AO, int X, Order * O) {
    if (IsAOEmpty(*AO)) {
        //printf("Order array is already empty.\n");
    } else if ((X > 0) && (X <= Neff(*AO))) {
        *O = ElmtA(*AO, X);
        //printf("Removing order from table %d\n", (*O).TableIndex);
        for (int i = X; i < Neff(*AO); i++) {
            ElmtA(*AO, i) = ElmtA(*AO, i+1);
        }
        Neff(*AO)--;
    } else {

    }
};

/* Print array of order */
void PrintAO (ArrOrder AO) {
    printf("ORDER\n");
    if (IsAOEmpty(AO)) {
        //printf("Empty array\n");
    } else {
        for (int i = 1; i <= Neff(AO); i++) {
            switch (ElmtA(AO, i).DishKey) {
                case 'p': printf("Banana Split"); break;
                case 'q': printf("Sundae"); break;
                case 'r': printf("Nasi Telur Dadar"); break;
                case 's': printf("Nasi Ayam Goreng"); break;
                case 't': printf("Burger"); break;
                case 'u': printf("Hot Dog"); break;
                case 'v': printf("Spaghetti Bolognese"); break;
                case 'w': printf("Spaghetti Carbonara"); break;
            }
            printf(", %d\n", ElmtA(AO, i).TableIndex);
        }
    }
};

/* Debugging */
void PrintAOWithIndex (ArrOrder AO) {
    printf("Order\n");
    if (IsAOEmpty(AO)) {
        printf("Empty array\n");
    } else {
        for (int i = 1; i <= Neff(AO); i++) {
            printf("i = %d\n", i);
            switch (ElmtA(AO, i).DishKey) {
                case 'p': printf("Banana Split"); break;
                case 'q': printf("Sundae"); break;
                case 'r': printf("Nasi Telur Dadar"); break;
                case 's': printf("Nasi Ayam Goreng"); break;
                case 't': printf("Burger"); break;
                case 'u': printf("Hot Dog"); break;
                case 'v': printf("Spaghetti Bolognese"); break;
                case 'w': printf("Spaghetti Carbonara"); break;
            }
            printf(", %d\n", ElmtA(AO, i).TableIndex);
        }
    }
};