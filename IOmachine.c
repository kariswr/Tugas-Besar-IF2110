#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IOmachine.h"
#include "library.h"
#include "waitingcust.h"
#include "handtray.h"

static FILE *pita;
static int retval;

boolean EndKata;
Kata CKata;

char CC;
boolean EOP;

/******** MESIN KARAKTER ********/
void START(char n){
	char src_txt[15] = "";
	strcat(src_txt, "savedata_");
	strcat(src_txt, &n);
	strcat(src_txt, ".txt");

	pita = fopen(src_txt, "r");
	ADV();
}

void ADV(){
	retval = fscanf(pita, "%c", &CC);
	EOP = (CC == MARK);
	if (EOP){
		fclose(pita);
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
	count[1] = CWord.TabWord[1];
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
				for (int i = 1; i <= CWord.Length; i++){
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

/******** READ DATA FROM FILE ********/
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
/******** WRITE DATA TO FILE ********/
/******** ********/
/******** ********/
/******** ********/
/******** ********/