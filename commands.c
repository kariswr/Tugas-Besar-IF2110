#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*---------- INCLUDES ----------*/
#include "waitingcust.h"
#include "arrorder.h"
#include "arrtable.h"
#include "foodtree.h"
#include "handtray.h"
#include "printResep.h"
#include "graph.h"

#define gotoxy(x,y) printf("\033[%d;%dH", (x), (y))
#define cls() printf("\033[H\033[J")

/*---------- HEADER ----------*/
void TickPt1 (Queue * Q, ArrTable * AT, ArrOrder * AO, int * LivesLost);
// Updates queue and arrays after 1 tick. Counts how many lives are lost during update.
void PLACE (Queue * Q, ArrTable * AT, ArrOrder * AO, int * LivesLost, Player P);
// Places a customer from the queue to the array of tables
void ORDER (Queue * Q, ArrTable * AT, ArrOrder * AO, int * LivesLost, Player P);
// Takes order from an occupied table
void CH (Stack *H);
// Throws out ingredients or utensils in hand stack
void CT (Stack *T);
// Throws out foods in tray stack
void TAKE (Player P, ArrCounter C, Stack *H);
// Take ingredient or utensils from beside table
void PUT (Player P, int i, int j, Stack *H, Stack *T, FoodTree F);
// Put food on tray, i&j are tray's position
void GIVE (Player *P, ArrTable *AT, ArrOrder *AO, Stack *T);
// Give food to customer.

/*---------- BODY ----------*/
void TickPt1 (Queue * Q, ArrTable * AT, ArrOrder * AO, int * LivesLost) {
    int x, lives;
    lives = 0;
    UpdateQueue(Q, &x);
    lives += x;
    UpdateAT(AT, AO, &x);
    lives += x;
    *LivesLost = lives;
}

void PLACE (Queue * Q, ArrTable * AT, ArrOrder * AO, int * LivesLost, Player P) {
    if (!IsQEmpty(*Q)) {
        int x;
        int i;
        i = 1;
        //printf("Finding table for Customer %d.\n", i);
        //printf("NeffAT = %d\n", Neff(AT));
        x = FindEmptyTableFor(P, (*Q).T[i], *AT);
        //printf("Table %d is available.\n", x);
        while ((x == 0) && (i <= NBElmtQ(*Q))) {
            x = FindEmptyTableFor(P, (*Q).T[i], *AT);
            if (x == 0) {
                i++;
            }
        }
        
        if (x != 0) {
            Customer C;
            DelXQ(Q, i, &C);
            ElmtA(*AT, x).Cust = C;
            ElmtA(*AT, x).Occupied = true;
            ElmtA(*AT, x).Cust.Patience += AddPatience;
            //printf("Table %d has %d customers.\n", x, AT.T[x].Cust.Persons);
        }
    }
}

void ORDER (Queue * Q, ArrTable * AT, ArrOrder * AO, int * LivesLost, Player P) {
    int x;
    Order O;
    x = TableNearPlayer(P, *AT);
    if ((ElmtA(*AT, x).Occupied) && (SearchAO(*AO, x) == 0)) {
        NewOrder(&O, x);
        AddLastAO(AO, O);
    }
}

void CH (Stack *H){
	char S;
	while (Top(*H) != Nil){
		PopTray(H,&S);
	}
}

void CT (Stack *T){
	char S;
	while (Top(*T) != Nil){
		PopTray(T,&S);
	}
}

void TAKE(Player P, ArrCounter C, Stack *H){
	boolean found;
	int i;
	
	found=false;
	i=1;
	if (P.Room == 0){

		while ((!found)&& (i<=16)) {
			if (Absis(P.Position) == Absis(ElmtA(C,i).Position)){
				if (Ordinat(P.Position) == Ordinat(ElmtA(C,i).Position)+1 || Ordinat(P.Position)==Ordinat(ElmtA(C,i).Position)-1){
					found=true;
				}
			}else if (Ordinat(P.Position) == Ordinat(ElmtA(C,i).Position)) {
				if (Absis(P.Position) == Absis(ElmtA(C,i).Position)+1 || Absis(P.Position)==Absis(ElmtA(C,i).Position)-1){
					found=true;
				}
			}
			i++;
		}
		if (found){
			if (!IsStackFull(*H)){
				printf("%c\n",ElmtA(C,i-1).Code);
				Push(H,ElmtA(C,i-1).Code);
			}
		}
	}
}

void PUT(Player P, int i, int j, Stack *H, Stack*T, FoodTree F){
	boolean found;
	char C;
	
	found=false;
	if (P.Room != 0) {
        gotoxy(30,3);
		printf("You are not in the kitchen.\n");
	} else { 
		if (i == Ordinat(P.Position)){
			if(j+1 == Absis(P.Position) || j-1 == Absis(P.Position)){
				found=true;
			}
		}else if(j == Absis(P.Position)){
			if (i+1== Ordinat(P.Position) || i-1 == Ordinat(P.Position)){
				found=true;
			}
		}else if (i+1 == Ordinat(P.Position)){
			if (j+1 == Absis(P.Position) || j-1 == Absis(P.Position)){
				found=true;
			}
		}else if(i-1 == Ordinat(P.Position)){
			if (j+1 == Absis(P.Position) || j-1 == Absis(P.Position)){
				found=true;
			}
		}
		if (found){
			C = CompareFood(H,T,F);
			if (C=='0'){
                gotoxy(30,3);
				printf("Sorry, put fail.\n");
			}else{
                gotoxy(30,3);
				printf("Put succeed.\n");
			}
		} else {
            gotoxy(30,3);
			printf("Please go to the tray first.\n");
		}
	}
}


void GIVE (Player *P, ArrTable *AT, ArrOrder *AO, Stack *T){
	int i,j;
	boolean found;
	char C;
	Order O;
	
	i=TableNearPlayer(*P,*AT);
	if (i==0){
        gotoxy(30,3);
		printf("Please go to the customer's table first.\n");
	}else{
		if (!(ElmtA(*AT,i).Occupied)){
            gotoxy(30,3);
			printf("Sorry, you can't give food to empty table.\n");
		}else{
			found=false;
			j=1;
			while(j<=Neff(*AO) && !found){
				if (ElmtA(*AO,j).TableIndex == i){
					found=true;
				}else{
					j++;
				}
			}
			if (!found){
                gotoxy(30,3);
				printf("These customer haven't ordered yet.\n");
			}else{
				PopTray(T,&C);
				if (ElmtA(*AO,j).DishKey != C){
                    gotoxy(30,3);
					printf("The dish doesn't match with the customer's order.\n");
					Push(T,C);
				}else{
					DelXAO(AO,j,&O);
					ElmtA(*AT,i).Occupied = false;
					(*P).Money += 5;
                    gotoxy(30,3);
					printf("You had successfully give the dish to the customer.\n");
				}
			}
		}
	}
}

void GU (ArrTable AT, ArrCounter AC, Point PosTray,MapMatrix R, Player *P ,Graph G ) {
    int tempx = (*P).Position.i -1;
    int tempy = (*P).Position.j;
    infotypeG IdPrec,IdSucc;
    int Room,iNew,jNew;
    addrSuccNode addNode;
    addrNodeG addIdPrec;
    if (tempx == 0) {
        if((*P).Room==0){
            (*P).Room +=4;
        }
        IdPrec = ((*P).Room *100) + ((*P).Position.i *10) + ((*P).Position.j);
        if (FoundNode(G,IdPrec)) {
			addIdPrec= SearchNode(G,IdPrec);
            addNode = Trail(addIdPrec);
            IdSucc = Id(Succ(addNode));
            Room = IdSucc/100;
            iNew = (IdSucc-(Room*100))/10;
            jNew = IdSucc -(Room*100)- (iNew*10);
            (*P).Room = Room;
            (*P).Position.i = iNew;
            (*P).Position.j = jNew;
        } else {
            gotoxy(30,3);
            printf("Sorry, You cannot go through wall");
        }
    } else {
        if ((R.T[tempx][tempy][0]) == '-' ||(R.T[tempx][tempy][0]) == 'D' ) {
            (*P).Position.i = tempx;
            (*P).Position.j = tempy;
        } else {
            if (R.T[tempx][tempy][0] == 'a'||R.T[tempx][tempy][0] == 'b'||R.T[tempx][tempy][0] == 'c'||R.T[tempx][tempy][0] == 'd'||R.T[tempx][tempy][0] == 'e'||R.T[tempx][tempy][0] == 'f'||R.T[tempx][tempy][0] == 'g'||R.T[tempx][tempy][0] == 'h'||
            R.T[tempx][tempy][0] == 'i'||R.T[tempx][tempy][0] == 'j'||R.T[tempx][tempy][0] == 'k'||R.T[tempx][tempy][0] == 'l'||R.T[tempx][tempy][0] == 'm'||R.T[tempx][tempy][0] == 'n'||R.T[tempx][tempy][0] == 'o'||
            R.T[tempx][tempy][0] == 'v') {
                gotoxy(30,3);
                printf("Sorry, You cannot go through the food counter");
            } else 
            if (R.T[tempx][tempy][0] == 'T') {
                gotoxy(30,3);
                printf("Sorry, You cannot go through the food tray");
            } else
            if (R.T[tempx][tempy][0] == 'X') {
                gotoxy(30,3);
                printf("Sorry, You cannot go through the chair");
            } else 
            if ((R.T[tempx][tempy][1]== '1') || (R.T[tempx][tempy][1]== '2') || (R.T[tempx][tempy][1]== '3') || (R.T[tempx][tempy][1]== '4') || (R.T[tempx][tempy][1]== '5') || (R.T[tempx][tempy][1]== '6')
             || (R.T[tempx][tempy][1]== '7') || (R.T[tempx][tempy][1]== '8') || (R.T[tempx][tempy][1]== '9') || strcpy(R.T[tempx][tempy],"10") || strcpy(R.T[tempx][tempy], "11") || strcpy(R.T[tempx][tempy],"12")){
                 gotoxy(30,3);
                 printf("Sorry,You cannot go through the table");
             }
        }
    }       
}

void GD (ArrTable AT, ArrCounter AC, Point PosTray,MapMatrix R, Player *P, Graph G ) {
    int tempx = (*P).Position.i+1;
    int tempy = (*P).Position.j;
    infotypeG IdPrec,IdSucc;
    int Room,iNew,jNew;
    addrSuccNode addNode;
    addrNodeG addIdPrec;

    if (tempx == 9) {
        if((*P).Room==0){
            (*P).Room +=4;
        }
        IdPrec = ((*P).Room *100) + ((*P).Position.i *10) + ((*P).Position.j);
        if (FoundNode(G,IdPrec)) {
			addIdPrec= SearchNode(G,IdPrec);
            addNode = Trail(addIdPrec);
            IdSucc = Id(Succ(addNode));
            if (IdSucc >=400){
                IdSucc -= 400;
            }
            Room = IdSucc/100;
            iNew = (IdSucc-(Room*100))/10;
            jNew = IdSucc -(Room*100)- (iNew*10);
            (*P).Room = Room;
            (*P).Position.i = iNew;
            (*P).Position.j = jNew;
        } else {
            gotoxy(30,3);
            printf("Sorry, You cannot go through wall");
        }
    } else {
        if ((R.T[tempx][tempy][0]) == '-' ||(R.T[tempx][tempy][0]) == 'D' ) {
            (*P).Position.i = tempx;
            (*P).Position.j = tempy;
        } else {
            if (R.T[tempx][tempy][0] == 'a'||R.T[tempx][tempy][0] == 'b'||R.T[tempx][tempy][0] == 'c'||R.T[tempx][tempy][0] == 'd'||R.T[tempx][tempy][0] == 'e'||R.T[tempx][tempy][0] == 'f'||R.T[tempx][tempy][0] == 'g'||R.T[tempx][tempy][0] == 'h'||
            R.T[tempx][tempy][0] == 'i'||R.T[tempx][tempy][0] == 'j'||R.T[tempx][tempy][0] == 'k'||R.T[tempx][tempy][0] == 'l'||R.T[tempx][tempy][0] == 'm'||R.T[tempx][tempy][0] == 'n'||R.T[tempx][tempy][0] == 'o'||
            R.T[tempx][tempy][0] == 'v') {
                gotoxy(30,3);
                printf("Sorry, You cannot go through the food counter");
            } else 
            if (R.T[tempx][tempy][0] == 'T') {
                gotoxy(30,3);
                printf("Sorry, You cannot go through the food tray");
            } else
            if (R.T[tempx][tempy][0] == 'X') {
                gotoxy(30,3);
                printf("Sorry, You cannot go through the chair");
            } else 
            if ((R.T[tempx][tempy][1]== '1') || (R.T[tempx][tempy][1]== '2') || (R.T[tempx][tempy][1]== '3') || (R.T[tempx][tempy][1]== '4') || (R.T[tempx][tempy][1]== '5') || (R.T[tempx][tempy][1]== '6')
             || (R.T[tempx][tempy][1]== '7') || (R.T[tempx][tempy][1]== '8') || (R.T[tempx][tempy][1]== '9') || strcpy(R.T[tempx][tempy],"10") || strcpy(R.T[tempx][tempy], "11") || strcpy(R.T[tempx][tempy],"12")){
                 gotoxy(30,3);
                 printf("Sorry,You cannot go through the table");
             }
        }
    }       
}

void GL (ArrTable AT, ArrCounter AC, Point PosTray,MapMatrix R, Player *P ,Graph G) {
    int tempx = (*P).Position.i;
    int tempy = (*P).Position.j-1;
    infotypeG IdPrec,IdSucc;
    int Room,iNew,jNew;
    addrSuccNode addNode;
    addrNodeG addIdPrec;

    if (tempx == 0) {
        if((*P).Room==0){
            (*P).Room +=4;
        }
        IdPrec = ((*P).Room *100) + ((*P).Position.i *10) + ((*P).Position.j);
        if (FoundNode(G,IdPrec)) {
			addIdPrec= SearchNode(G,IdPrec);
            addNode = Trail(addIdPrec);
            IdSucc = Id(Succ(addNode));
            Room = IdSucc/100;
            iNew = (IdSucc-(Room*100))/10;
            jNew = IdSucc -(Room*100)- (iNew*10);
            (*P).Room = Room;
            (*P).Position.i = iNew;
            (*P).Position.j = jNew;
        } else {
            gotoxy(30,3);
            printf("Sorry, You cannot go through wall");
        }
    } else {
        if ((R.T[tempx][tempy][0]) == '-' || (R.T[tempx][tempy][0]) == 'D') {
            (*P).Position.i = tempx;
            (*P).Position.j = tempy;
        } else {
            if (R.T[tempx][tempy][0] == 'a'||R.T[tempx][tempy][0] == 'b'||R.T[tempx][tempy][0] == 'c'||R.T[tempx][tempy][0] == 'd'||R.T[tempx][tempy][0] == 'e'||R.T[tempx][tempy][0] == 'f'||R.T[tempx][tempy][0] == 'g'||R.T[tempx][tempy][0] == 'h'||
            R.T[tempx][tempy][0] == 'i'||R.T[tempx][tempy][0] == 'j'||R.T[tempx][tempy][0] == 'k'||R.T[tempx][tempy][0] == 'l'||R.T[tempx][tempy][0] == 'm'||R.T[tempx][tempy][0] == 'n'||R.T[tempx][tempy][0] == 'o'||
            R.T[tempx][tempy][0] == 'v') {
                gotoxy(30,3);
                printf("Sorry, You cannot go through the food counter");
            } else 
            if (R.T[tempx][tempy][0] == 'T') {
                gotoxy(30,3);
                printf("Sorry, You cannot go through the food tray");
            } else
            if (R.T[tempx][tempy][0] == 'X') {
                gotoxy(30,3);
                printf("Sorry, You cannot go through the chair");
            } else 
            if ((R.T[tempx][tempy][1]== '1') || (R.T[tempx][tempy][1]== '2') || (R.T[tempx][tempy][1]== '3') || (R.T[tempx][tempy][1]== '4') || (R.T[tempx][tempy][1]== '5') || (R.T[tempx][tempy][1]== '6')
             || (R.T[tempx][tempy][1]== '7') || (R.T[tempx][tempy][1]== '8') || (R.T[tempx][tempy][1]== '9') || strcpy(R.T[tempx][tempy],"10") || strcpy(R.T[tempx][tempy], "11") || strcpy(R.T[tempx][tempy],"12")){
                 gotoxy(30,3);
                 printf("Sorry,You cannot go through the table");
             }
        }
    }       
}

void GR (ArrTable AT, ArrCounter AC, Point PosTray,MapMatrix R, Player *P,Graph G){
    int tempx = (*P).Position.i;
    int tempy = (*P).Position.j+1;
    infotypeG IdPrec,IdSucc;
    int Room,iNew,jNew;
    addrSuccNode addNode;
    addrNodeG addIdPrec;

    if (tempx == 9) {
        if((*P).Room==0){
            (*P).Room +=4;
        }
        IdPrec = ((*P).Room *100) + ((*P).Position.i *10) + ((*P).Position.j);
        if (FoundNode(G,IdPrec)) {
			addIdPrec= SearchNode(G,IdPrec);
            addNode = Trail(addIdPrec);
            IdSucc = Id(Succ(addNode));
            Room = IdSucc/100;
            iNew = (IdSucc-(Room*100))/10;
            jNew = IdSucc -(Room*100)- (iNew*10);
            (*P).Room = Room;
            (*P).Position.i = iNew;
            (*P).Position.j = jNew;
        } else {
            gotoxy(30,3);
            printf("Sorry, You cannot go through wall");
        }
    } else {
        if ((R.T[tempx][tempy][0]) == '-' || (R.T[tempx][tempy][0]) == 'D' ) {
            (*P).Position.i = tempx;
            (*P).Position.j = tempy;
        } else {
            if (R.T[tempx][tempy][0] == 'a'||R.T[tempx][tempy][0] == 'b'||R.T[tempx][tempy][0] == 'c'||R.T[tempx][tempy][0] == 'd'||R.T[tempx][tempy][0] == 'e'||R.T[tempx][tempy][0] == 'f'||R.T[tempx][tempy][0] == 'g'||R.T[tempx][tempy][0] == 'h'||
            R.T[tempx][tempy][0] == 'i'||R.T[tempx][tempy][0] == 'j'||R.T[tempx][tempy][0] == 'k'||R.T[tempx][tempy][0] == 'l'||R.T[tempx][tempy][0] == 'm'||R.T[tempx][tempy][0] == 'n'||R.T[tempx][tempy][0] == 'o'||
            R.T[tempx][tempy][0] == 'v') {
                gotoxy(30,3);
                printf("Sorry, You cannot go through the food counter");
            } else 
            if (R.T[tempx][tempy][0] == 'T') {
                gotoxy(30,3);
                printf("Sorry, You cannot go through the food tray");
            } else
            if (R.T[tempx][tempy][0] == 'X') {
                gotoxy(30,3);
                printf("Sorry, You cannot go through the chair");
            } else 
            if ((R.T[tempx][tempy][1]== '1') || (R.T[tempx][tempy][1]== '2') || (R.T[tempx][tempy][1]== '3') || (R.T[tempx][tempy][1]== '4') || (R.T[tempx][tempy][1]== '5') || (R.T[tempx][tempy][1]== '6')
             || (R.T[tempx][tempy][1]== '7') || (R.T[tempx][tempy][1]== '8') || (R.T[tempx][tempy][1]== '9') || strcpy(R.T[tempx][tempy],"10") || strcpy(R.T[tempx][tempy], "11") || strcpy(R.T[tempx][tempy],"12")){
                 gotoxy(30,3);
                 printf("Sorry,You cannot go through the table");
             }
        }
    }       
}

void HINT (ArrFood F) {
    char x;
    cls();
    PrintFoodTable(F);
    printf("Are You Done remembering all these ingredients ? [Y] ");
    scanf("%c",&x);
}

void RECIPE (FoodTree P, ArrFood F) {
    PrintRecipe(P,F);
}

void QUIT () {
    cls();
    gotoxy(16,36);
    printf("Thanks for playing !!");
    exit(0);
}


