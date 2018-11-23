#include "foodconversion.h"
#include "library.h"
#include <stdio.h>


int main(){
/*Kamus*/
    ArrFood F;
    int i;

/*Algoritma*/
    MakeEmptyFood(&F);
    ReadFood(&F);
    for (i=1;i<=F.Neff;i++){
        printf("%c ",F.T[i].FoodCode);
        PrintFoodName(F,F.T[i].FoodCode);
    }
    PrintFoodTable(F);
    return 0;
}
