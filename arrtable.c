#include <stdio.h>
#include <stdlib.h>
#include "arrtable.h"

/*---------- TABLE ----------*/
/* Constructor */
void BuildTable (Table * T, int Room, int i, int j, MapMatrix R) {
    (*T).Room = Room;

    Point P;
    Absis(P) = j;
    Ordinat(P) = i;
    (*T).Position = P;

    (*T).Occupied = false;
    
    //printf("(%d, %d) %s - ", (P.Y-1), P.X, ElmtM(R, (P.Y-1), P.X));
    if (ElmtM(R, (P.i-1), P.j)[1] == 'X') {
        //printf("This table has capacity for 4 people\n");
        (*T).Capacity = 4;
    } else {
        //printf("This table has capacity for 2 people\n");
        (*T).Capacity = 2;
    }
};

/* Tests */
boolean IsUnoccupied (Table T) {
    return (T.Occupied = false);
};

/*---------- ARRAY OF TABLE ----------*/
/* Constructor */
void ReadRoom (int Room, MapMatrix R, ArrTable * AT) {
    int x;
    for (int i = 1; i <= NBrsEff(R); i++) {
        for (int j = 1; j <= NKolEff(R); j++) {
            sscanf(ElmtM(R, i, j), "%d", &x);
            //printf("Scanning [%d][%d], found label '%d'.\n", i, j, x);
            if ((x > 0) && (x <= 12)) {
                //printf("Putting table in.\n");
                Table T;
                BuildTable(&T, Room, i, j, R);
                AddTableX(AT, x, T);
                x = 0;
            }
        }
    }
};

void InitiateAT (MapMatrix R1, MapMatrix R2, MapMatrix R3, ArrTable * AT) {
    Neff(*AT) = 0;
    ReadRoom(1, R1, AT);
    ReadRoom(2, R2, AT);
    ReadRoom(3, R3, AT);
};

/* Add array element */
void AddTableX (ArrTable * AT, int X, Table T) {
    ElmtA(*AT, X) = T;
    Neff(*AT)++;
};

// NOT YET DEBUGGED
/* Search through array */
int PlayerIsNearTable (Player P, ArrTable AT) {
    int Xdiff, Ydiff;
    int i;
    boolean Found;

    i = 1;
    Found = false;
    while ((i <= Neff(AT)) && (!Found)) {
        if (ElmtA(AT, i).Room == P.Room) {
            Xdiff = Absis(P.Position) - Absis(ElmtA(AT, i).Position);
            Ydiff = Ordinat(P.Position) - Ordinat(ElmtA(AT, i).Position);
            // Player is diagonally next to table
            if (((Xdiff == 1) || (Xdiff == -1)) && ((Ydiff == 1) || (Ydiff == -1))) {
                Found = true;
            }
            // Player is next to a chair and 2 columns away from table
            else if ((Ydiff == 0) && ((Xdiff == 2) || (Xdiff == -2))) {
                Found = true;
            }
            // Player is next to a chair and 2 rows away from table
            else if ((ElmtA(AT, i).Capacity == 4) && (Xdiff == 0) && ((Ydiff == 2) || (Ydiff == -2))) {
                Found = true;
            } else {
                i++;
            }
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

// NOT YET DEBUGGED
int FindEmptyTableFor (Player P, Customer C, ArrTable AT) {
    int i;
    boolean Found;

    i = 1;
    Found = false;
    while ((i <= Neff(AT)) && (!Found)) {
        if ((ElmtA(AT, i).Room == P.Room) && (IsUnoccupied(ElmtA(AT, i)))) {
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

/* Debugging */
void PrintAT (ArrTable AT) {
    for (int i = 1; i <= Neff(AT); i++) {
        printf("[%d] %d - (%d, %d) | %d | %d\n", i, ElmtA(AT, i).Room, ElmtA(AT, i).Position.i, ElmtA(AT, i).Position.j, ElmtA(AT, i).Capacity, ElmtA(AT, i).Occupied);
    }
};

