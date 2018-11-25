/* File foodtree_driver digunakan untuk mengetes ADT foodtree*/

#include "foodtree.h"
#include "handtray.h"
#include "foodconversion.h"
#include <stdio.h>

int main(){
    /*Kamus*/
    FoodTree P,Q;
    ArrFood F;
    Stack H,T;
    char C;

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
    
    CreateEmptyStack(&H);
    CreateEmptyStack(&T);
    
    Push(&H,'a');
    Push(&H,'b');
    Push(&H,'d');
    Push(&H,'h');
    
    C = CompareFood(&H,&T,P);
    
    printf("%c\n",C);
    
    while (Top(H)!=Nil){
		PopTray(&H,&C);
		printf("%c",C);
	}
	printf("\n");
	while(Top(T)!=Nil){
		PopTray(&T,&C);
		printf("%c",C);
	}
    
return 0;
}
