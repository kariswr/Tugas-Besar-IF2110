#include <stdio.h>
#include "library.h"
#include "foodtree.h"
#include "printResep.h"
#include "foodconversion.h"

#define gotoxy(x,y) printf("\033[%d;%dH", (x), (y))
#define cls() printf("\033[H\033[J")

void PrintRecipe (FoodTree P, ArrFood F) {
		printf("                .._____________________________________________________________________________________________________..\n");
		printf("    ___________..                                                                                                     ..___________.\n");
		printf("  .           ..                                                                                                     ..          .   .\n");
		printf(" .            ..                                                                                                     ..         .     .\n");
		printf("  .           ..                                                                                                     ..          .   .\n");
		printf("    ___________..                                                                                                     ..___________.\n");
		printf("                .._____________________________________________________________________________________________________.. |\n");
		printf("                    |                                                                                                     |\n");
		printf("                    |                                                                                                     |\n");
		printf("                    |                                                                                                     |\n");
		printf("                    |                                                                                                     |\n");
		printf("                    |                                                                                                     |\n");
		printf("                    |                                                                                                     |\n");
		printf("                    |                                                                                                     |\n");
		printf("                    |                                                                                                     |\n");
		printf("                    |                                                                                                     |\n");
		printf("                    |                                                                                                     |\n");
		printf("                    |                                                                                                     |\n");
		printf("                    |                                                                                                     |\n");
		printf("                    |                                                                                                     |\n");
		printf("                    |                                                                                                     |\n");
		printf("                    |                                                                                                     |\n");
		printf("                    |                                                                                                     |\n");
		printf("                    |                                                                                                     |\n");
		printf("                    |                                                                                                     |\n");
		printf("                    |                                                                                                     |\n");
		printf("                    |                                                                                                     |\n");
		printf("                    |                                                                                                     |\n");
		printf("                    |                                                                                                     |\n");
		printf("                    |                                                                                                     |\n");
		printf("                    |                                                                                                     |\n");
		printf("                    |                                                                                                     |\n");
		printf("                    |                                                                                                     |\n");
		printf("                 ..___________________________________________________________________________________________________..  |\n");
		printf("    ___________..                                                                                                   ..___________.\n");
		printf(" .            ..                                                                                                   ..         .     .\n");
		printf(" .            ..                                                                                                   ..         .     .\n");
		printf("  .           ..                                                                                                   ..          .   .\n");
		printf("    ___________..                                                                                                   ..___________.\n");
		printf("                ..____________________________________________________________________________________________________.. \n");
		printf("\n");
		gotoxy(8,23);
    	PrintTree(P,F,5,23);
    	gotoxy(41,1);
}


