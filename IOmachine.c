#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"
#include "IOmachine.h"
#include "waitingcust.h"
//#include "handtray.h"

static FILE *pita_baca;
static FILE *pita_salin;
static int retval;

char CC;
boolean EOP;
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
void ReadThumbFile(ArrThumb *ArrTh, char *Name){
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

/******** PRIMTIVE DATA TYPE CONVERSION ********/
int ConvertBoolInt(boolean n){
	if (n == true){
		return '1';
	}
	else{
		return '0';
	}
}

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

/*
/******** READ SAVE_DATA FROM FILE ********/
void ReadFileExt(Queue *Q, ArrTable *ArrT, ArrOrder *ArrO, Player *P, Stack *Tray, Stack *Hand){
	STARTKATA('1');
	/**** QUEUE ****/
	Head(*Q) = ConvertCharInt(CKata);
	ADVKATA();
	Tail(*Q) = ConvertCharInt(CKata);
	ADVKATA();
	MaxEl(*Q) = ConvertCharInt(CKata);

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
		fprintf(pita_salin, "%d\n", Head(Q));
		/** TAIL **/
		fprintf(pita_salin, "%d\n", Tail(Q));
		/** MAXEL **/
		fprintf(pita_salin, "%d\n", MaxEl(Q));
		
		int temp = Head(Q) - Tail(Q) + 1;
		for (i = 1; i <= temp; i++){
			/** STAR **/
			fprintf(pita_salin, "%d ", ConvertBoolInt(Q.T[i].Star));
			/** PERSONS **/
			fprintf(pita_salin, "%d ", Q.T[i].Persons);
			/** PATIENCE **/
			fprintf(pita_salin, "%d\n", Q.T[i].Patience);
		}
		fprintf(pita_salin, "\n");

	/**** ARRTABLE ****/
	fprintf(pita_salin, "%d\n\n", Neff(ArrT));
		/** TABLE **/
		for (i = 1; i <= NTable; i++){
			/* CAPACITY */
			fprintf(pita_salin, "%d ", ArrT.T[i].Capacity);
			/* ROOM */
			fprintf(pita_salin, "%d ", ArrT.T[i].Room);
			/* POSITION */
			fprintf(pita_salin, "%d ", Absis(ArrT.T[i].Position));
			fprintf(pita_salin, "%d ", Ordinat(ArrT.T[i].Position));
			/* IS OCCUPIED? */
			fprintf(pita_salin, "%d ", ConvertBoolInt(ArrT.T[i].Occupied));
			/* CUSTOMER */
				/** STAR **/
				fprintf(pita_salin, "%d ", ConvertBoolInt(ArrT.T[i].Cust.Star));
				/** PERSONS **/
				fprintf(pita_salin, "%d ", ArrT.T[i].Cust.Persons);
				/** PATIENCE **/
				fprintf(pita_salin, "%d\n", ArrT.T[i].Cust.Patience);
		}
		fprintf(pita_salin, "\n");
		
	/**** ARRORDER ****/
	fprintf(pita_salin, "%d\n\n", Neff(ArrO));

		/** ORDER **/
		for (i = 1; i <= Neff(ArrO); i++){
			fprintf(pita_salin, "%c ", ArrO.T[i].DishKey);
			fprintf(pita_salin, "%d\n", ArrO.T[i].TableIndex);
		}
		fprintf(pita_salin, "\n");

	/**** STATUS PLAYER ****/
		/** NAME **/
		fprintf(pita_salin, "%s ", P.Name);
		/** MONEY **/
		fprintf(pita_salin, "%d ", P.Money);
		/** LIFE **/
		fprintf(pita_salin, "%d ", P.Life);
		/** TIME **/
		fprintf(pita_salin, "%d ", P.Room);
		/** POSITION **/
		fprintf(pita_salin, "%d ", Absis(P.Position));
		fprintf(pita_salin, "%d\n\n", Ordinat(P.Position));

	/**** TRAY ****/
		/** TOP **/
		fprintf(pita_salin, "%d\n", Top(Tray));
		/** TABLE **/
		for (i = 1; i <= Top(Tray); i++){
			fprintf(pita_salin, "%c\n", Tray.T[i]);
		}
		fprintf(pita_salin, "\n");

	/**** HAND ****/
		/** TOP **/
		fprintf(pita_salin, "%d\n", Top(Hand));
		/** TABLE **/
		for (i = 1; i <= Top(Hand); i++){
			fprintf(pita_salin, "%c\n", Hand.T[i]);
		}
		fprintf(pita_salin, "/");
	
	fclose(pita_baca);
}

/******** READ MAP MATRIX ********/
void AssignMap_FileExt(MapMatrix *R){
	int i, j;
	ADV();
	for (i = 1; i <= M; i++){
		for (j = 1; j <= N; j++){
			switch (CC){
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9': {
					(*R).T[i][j][1] = '0';
					(*R).T[i][j][2] = CC;
					break;
				}
				case 'x':
					(*R).T[i][j][1] = '1';
					(*R).T[i][j][2] = '0';
					break;
				case 'y':
					(*R).T[i][j][1] = '1';
					(*R).T[i][j][2] = '1';
					break;
				case 'z': {
					(*R).T[i][j][1] = '1';
					(*R).T[i][j][2] = '2';
					break;
				}
				default:{
					(*R).T[i][j][1] = CC;
					(*R).T[i][j][2] = CC;
				}
			}
			if (j == N){
				ADV();
				break;
			}
			ADV();
		}
	}
}

void ReadMap_FileExt(MapMatrix *R1, MapMatrix *R2, MapMatrix *R3, MapMatrix *RK){
	pita_baca = fopen("externalMap.txt", "r");
	/**** FOR ROOM 01 ****/
	AssignMap_FileExt(R1);
	/**** FOR ROOM 02 ****/
	AssignMap_FileExt(R2);
	/**** FOR ROOM 03 ****/
	AssignMap_FileExt(R3);
	/**** FOR ROOM KITCHEN ****/
	AssignMap_FileExt(RK);
	fclose(pita_baca);
}
/******** ********/
/******** ********/
/******** ********/