#include <stdio.h>
#include <stdlib.h>
#include "arrorder.h"

/*---------- ORDER ----------*/
/* Constructor */
void NewOrder (Order * O, int Idx) {
    int x;
    x = rand() % 8;
    if (x == 0) {
        (*O).DishKey = 'p';
    } else if (x == 1) {
        (*O).DishKey = 'q';
    } else if (x == 2) {
        (*O).DishKey = 'r';
    } else if (x == 3) {
        (*O).DishKey = 's';
    } else if (x == 4) {
        (*O).DishKey = 't';
    } else if (x == 5) {
        (*O).DishKey = 'u';
    } else if (x == 6) {
        (*O).DishKey = 'v';
    } else if (x == 7) {
        (*O).DishKey = 'w';
    }
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

int SearchAO (ArrOrder AO, char DishKey, int TableIndex) {
    int i;
    boolean Found;
    i = 1;
    Found = false;
    while ((i <= Neff(AO)) && (!Found)) {
        if ((ElmtA(AO, i).DishKey == DishKey) && (ElmtA(AO, i).TableIndex == TableIndex)) {
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
        printf("Order array is empty.\n");
    } else {
        *O = ElmtA(*AO, X);
        Neff(*AO)--;
    }
};

/* Print array of order */
void PrintAO (ArrOrder AO) {
    printf("Order\n");
    if (IsAOEmpty(AO)) {
        printf("Empty array\n");
    } else {
        for (int i = 1; i <= Neff(AO); i++) {
            switch (ElmtA(AO, i).DishKey) {
                case 'p': printf("Banana Split");
                case 'q': printf("Sundae");
                case 'r': printf("Nasi Telur Dadar");
                case 's': printf("Nasi Ayam Goreng");
                case 't': printf("Burger");
                case 'u': printf("Hot Dog");
                case 'v': printf("Spaghetti Bolognese");
                case 'w': printf("Spaghetti Carbonara");
            }
            printf(", %d\n", ElmtA(AO, i).TableIndex);
        }
    }
};