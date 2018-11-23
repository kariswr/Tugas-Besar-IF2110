/* File foodtree_driver digunakan untuk mengetes ADT foodtree*/

#include "foodtree.h"
#include "foodconversion.h"
#include <stdio.h>

int main(){
    /*Kamus*/
    FoodTree P,Q;
    ArrFood F;

    /*Algoritma*/
    /*Mengetes prosedur BuildTree*/
    
    /*Mengetes prosedur ShowFoodTree*/
    /*jumlahkar=0;*/
    STARTTREE();
    BuildTree(&P);
    MakeEmptyFood(&F);
    ReadFood(&F);
    printf("%c\n",Akar(P));
    Q=Right(P);
    Q=Right(Q);
    Q=Right(Q);
    printf("%c\n",Akar(Q));
    PrintTree(P,F,5);
return 0;
}
