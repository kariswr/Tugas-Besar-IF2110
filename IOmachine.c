#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"
#include "IOmachine.h"
#include "waitingcust.h"
#include "handtray.h"

static FILE *pita_baca;
static FILE *pita_salin;
static int retval;

extern char CC;
extern boolean EOP;
boolean EndKata;
Kata CKata;

/******** MESIN KARAKTER ********/
void START(char n){
	char src_txt[15] = "";
	strcat(src_txt, "savedata_");
	strcat(src_txt, &n);
	strcat(src_txt, ".txt");

	pita_baca = fopen(src_txt, "r");
	ADV();
}

void ADV(){
	retval = fscanf(pita_baca, "%c", &CC);
	EOP = (CC == MARK);
	if (EOP){
		fclose(pita_baca);
	}
}

/******** MESIN KATA ********/
void IgnoreBlank(){
	while ((CC == BLANK || CC == ENTER) && (CC != MARK)){
		ADV();
	}
}

void STARTKATA(char n){
	START(n);
	IgnoreBlank();

	if (CC != MARK){
		EndKata = false;
		SalinKata();
	}
	else{
		EndKata = true;
	}
}

void ADVKATA(){
	IgnoreBlank();
	if (CC == MARK){
		EndKata = true;
	}
	else{
		EndKata = false;
		SalinKata();
	}
}

void SalinKata(){
	int i = 1;
	do{
		if (i <= NMax){
			CKata.TabKata[i] = CC;
			i = i + 1;
		}
		ADV();
	} while (!(CC == MARK || CC == BLANK || CC == ENTER));
	i = i - 1;
	CKata.Length = i;
}

/******** READ THUMBNAIL DATA ********/
void ReadThumbFile(ArrThumb *ArrTh){
	char *count;
	int int_count, j;

	STARTKATA('0');

	count = (char*) malloc ((CKata.Length + 1) *sizeof(char));
	count[1] = CKata.TabKata[1];
	int_count = atoi(&(count[1]));

	(*ArrTh).Length = int_count;
	if (int_count == 0){
		printf("no savedata found");
	}
	else{
		while (!EOP){
			ADVKATA();
			/** Write to the screen **/

			for (j = 1; j <= int_count; j++){
				for (int i = 1; i <= CKata.Length; i++){
					/** Save the thumbnails to the array **/
					(*ArrTh).UserThumb[j].TabKata[i] = CKata.TabKata[i];

					printf("%d. %c", j, CKata.TabKata[i]);
				}
				/** Save the length of the username **/
				(*ArrTh).UserThumb[j].Length = CKata.Length;
				printf("\n");
			}
		}
	}
}

/******** WRITE THUMBNAIL DATA********/
void WriteThumbFile(ArrThumb ArrTh, char *Name){
	int i;
}

/******** READ SAVE_DATA FROM FILE ********/
int ConvertCharInt(Kata K){
	char *c_Temp;
	int lenTemp;

	lenTemp = K.Length;
	c_Temp = (char *) malloc ((lenTemp + 1) *sizeof(char));
	c_Temp = K.TabKata;

	return atoi(&c_Temp[1]);
}

boolean ConvertCharBool(Kata K){
	return (K.TabKata[1] == '1');
}

void ReadFileExt(Queue *Q, ArrTable *ArrT, ArrOrder *ArrO, Player *P, Stack *Tray, Stack *Hand){
	STARTKATA('1');
	/**** QUEUE ****/
	Head(*Q) = ConvertCharInt(CKata);
	ADVKATA();
	Tail(*Q) = ConvertCharInt(CKata);
	ADVKATA();
	MaxEl(*Q) = ConvertCharInt(CKata);

	/** ALOCATE the MEMORY **/
	CreateEmptyQ(Q, MaxQueue);
	int i;

	/** Temporary Customer DATA TYPE **/
	Customer tempCust;
	int temp;

	for (i = 1; i <= MaxEl(*Q); i++){
		/** VIP **/
		ADVKATA();
		tempCust.Star = ConvertCharBool(CKata);
		
		/** PERSONS **/
		ADVKATA();
		temp = ConvertCharInt(CKata);
		tempCust.Persons = temp;

		/** PATIENCE **/
		ADVKATA();
		temp = ConvertCharInt(CKata);
		tempCust.Patience = temp;

		AddQ(Q, tempCust);
	}

	/**** ARRTABLE ****/
	ADVKATA();
	int NeffTable = ConvertCharInt(CKata);
	Neff(*ArrT) = NeffTable;

	for (i = 1; i <= NTable; i++){
		/** CAPACITY **/
		ADVKATA();
		temp = ConvertCharInt(CKata);
		ElmtA(*ArrT, i).Capacity = temp;

		/** ROOM **/
		ADVKATA();
		temp = ConvertCharInt(CKata);
		ElmtA(*ArrT, i).Room = temp;

		/** POINT **/
			/* ABSIS */
			ADVKATA();
			temp = ConvertCharInt(CKata);
			Absis(ElmtA(*ArrT, i).Position) = temp;

			/* ORDINAT */
			ADVKATA();
			temp = ConvertCharInt(CKata);
			Ordinat(ElmtA(*ArrT, i).Position) = temp;
		
		/** IS OCCUPIED? **/
		ADVKATA();
		temp = ConvertCharBool(CKata);
		ElmtA(*ArrT, i).Occupied = temp;

		/** CUSTOMER **/
			/* VIP */
			ADVKATA();
			temp = ConvertCharBool(CKata);
			ElmtA(*ArrT, i).Cust.Star = temp;

			/* PERSONS */
			ADVKATA();
			temp = ConvertCharInt(CKata);
			ElmtA(*ArrT, i).Cust.Star = temp;

			/* PATIENCE */
			ADVKATA();
			temp = ConvertCharInt(CKata);
			ElmtA(*ArrT, i).Cust.Patience = temp;
	}

	/**** ARRORDER ****/
	MakeEmptyAO(ArrO);
	ADVKATA();
	Neff(*ArrO) = ConvertCharInt(CKata);

	
	for (i = 1; i <= Neff(*ArrO); i++){
		/** DISHKEY **/
		ADVKATA();
		ElmtA(*ArrO, i).DishKey = CKata.TabKata[1];

		/** TABLEINDEX **/
		ADVKATA();
		ElmtA(*ArrO, i).TableIndex = ConvertCharInt(CKata);
	}

	/**** PLAYER ****/
		/** NAME **/
		ADVKATA();
		(*P).Name = (char*) malloc ((CKata.Length + 1) *sizeof(char));
		for (i = 1; i <= CKata.Length; i++){
			(*P).Name[i] = CKata.TabKata[i];
		}

		/** MONEY **/
		ADVKATA();
		(*P).Money = ConvertCharInt(CKata);

		/** LIFE **/
		ADVKATA();
		(*P).Life = ConvertCharInt(CKata);

		/** TIME **/
		ADVKATA();
		(*P).Room = ConvertCharInt(CKata);

		/** POINT **/
			/* ABSIS */
			ADVKATA();
			Absis((*P).Position) = ConvertCharInt(CKata);

			/* Ordinat */
			ADVKATA();
			Ordinat((*P).Position) = ConvertCharInt(CKata);

	/**** TRAY ****/
	CreateEmptyStack(Hand);
		/** TOP **/
		ADVKATA();
		Top(*Hand) = ConvertCharInt(CKata);

		/** ITEM **/
		for (i = 1; i <= MaxStack; i++){
			ADVKATA();
			if (CKata.TabKata[1] != 'x'){
				(*Hand).T[i] = CKata.TabKata[1];
			}
		}

	/**** HAND ****/
		/** TOP **/
		ADVKATA();
		Top(*Tray) = ConvertCharInt(CKata);

		/** ITEM **/
		i = 1;
		for(i = 1; i <= MaxStack; i++){
			ADVKATA();
			if (CKata.TabKata[1] != 'x'){
				(*Tray).T[i] = CKata.TabKata[1];
			}
		}
}
/******** WRITE SAVE_DATA TO FILE ********/
void WriteFileExt(Queue Q, ArrTable ArrT, ArrOrder ArrO, Player P, Stack Tray, Stack Hand, char n){
	/**** PREPARATION FOR CONNECTING FILE EXT ****/
	char src_txt[15] = "";
	strcat(src_txt, "savedata_");
	strcat(src_txt, &n);
	strcat(src_txt, ".txt");

	int i;
	/**** CONNECTING FILE EXT ****/
	pita_baca = fopen(src_txt, "w");
	/**** QUEUE ****/
		/** HEAD **/
		fprintf(pita_salin, "%d", Head(Q));
		/** TAIL **/
		fprintf(pita_salin, "%d", Tail(Q));
		/** MAXEL **/
		fprintf(pita_salin, "%d", MaxEl(Q));
		
		int temp;
		for (i = 1; i <= NBElmtQ(Q); i++){
			/** STAR **/
			if (Q.T[i].Star == true){
				temp = 1;
			}
			else{
				temp = 0;
			}
			fprintf(pita_salin, "%d", temp);
			/** PERSONS **/
			fprintf(pita_salin, "%d", Q.T[i].Persons);
			/** PATIENCE **/
			fprintf(pita_salin, "%d", Q.T[i].Patience);
		}

	fclose(pita_baca);
}

/******** READ MAP MATRIX ********/
void AssignMap_FileExt(MapMatrix *R, char CC){
	int i, j;
	for (i = 1; i <= M; i++){
		for (j = 1; j <= N; j++){
			IgnoreBlank();
			if (CC == '-'){
				(*R).T[i][j] = "--";
			}
			else if (CC == 'X'){
				(*R).T[i][j] = "XX";
			}
			else if (CC == 'D'){
				(*R).T[i][j] = "DD";
			}
			else if (CC == 'T'){
				(*R).T[i][j] = "TT";
			}
			else if (CC == '1'){
				(*R).T[i][j] = "01";
			}
			else if (CC == '2'){
				(*R).T[i][j] = "02";
			}
			else if (CC == '3'){
				(*R).T[i][j] = "03";
			}
			else if (CC == '4'){
				(*R).T[i][j] = "04";
			}
			else if (CC == '5'){
				(*R).T[i][j] = "05";
			}
			else if (CC == '6'){
				(*R).T[i][j] = "06";
			}
			else if (CC == '7'){
				(*R).T[i][j] = "07";
			}
			else if (CC == '8'){
				(*R).T[i][j] = "08";
			}
			else if (CC == '9'){
				(*R).T[i][j] = "09";
			}
			else if (CC == 'x'){
				(*R).T[i][j] = "10";
			}
			else if (CC == 'y'){
				(*R).T[i][j] = "11";
			}
			else if (CC == 'z'){
				(*R).T[i][j] = "12";
			}
			else if (CC == 'a'){
				(*R).T[i][j] = "aa";
			}
			else if (CC == 'b'){
				(*R).T[i][j] = "bb";
			}
			else if (CC == 'c'){
				(*R).T[i][j] = "cc";
			}
			else if (CC == 'd'){
				(*R).T[i][j] = "dd";
			}
			else if (CC == 'e'){
				(*R).T[i][j] = "ee";
			}
			else if (CC == 'f'){
				(*R).T[i][j] = "f";
			}
			else if (CC == 'g'){
				(*R).T[i][j] = "gg";
			}
			else if (CC == 'h'){
				(*R).T[i][j] = "hh";
			}
			else if (CC == 'j'){
				(*R).T[i][j] = "jj";
			}
			else if (CC == 'k'){
				(*R).T[i][j] = "kk";
			}
			else if (CC == 'l'){
				(*R).T[i][j] = "ll";
			}
			else if (CC == 'm'){
				(*R).T[i][j] = "mm";
			}
			else if (CC == 'n'){
				(*R).T[i][j] = "nn";
			}
			else if (CC == 'o'){
				(*R).T[i][j] = "oo";
			}
		}
	}
}

void ReadMap_FileExt(MapMatrix *R1, MapMatrix *R2, MapMatrix *R3, MapMatrix *RK){
	pita_baca = fopen("externalMap.txt", "r");
	/**** FOR ROOM 01 ****/
	AssignMap_FileExt(R1, CC);
	/**** FOR ROOM 02 ****/
	AssignMap_FileExt(R2, CC);
	/**** FOR ROOM 03 ****/
	AssignMap_FileExt(R3, CC);
	/**** FOR ROOM KITCHEN ****/
	AssignMap_FileExt(RK, CC);
}
/******** ********/
/******** ********/
/******** ********/