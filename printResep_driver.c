#include <stdio.h>
#include "library.h"
#include "foodtree.h"
#include "printResep.h"

#define gotoxy(x,y) printf("\033[%d;%dH", (x), (y))
#define cls() printf("\033[H\033[J")


int main () {
	printf ("\e[8;45;150t");
	FoodTree P;
    ArrFood F;
    cls();
	STARTTREE();
    BuildTree(&P);
    MakeEmptyFood(&F);
    ReadFood(&F);
    PrintRecipe(P,F);
	return 0;
}