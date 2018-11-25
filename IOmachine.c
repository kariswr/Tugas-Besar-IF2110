#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IOmachine.h"

static FILE *pita;
static int retval;

boolean EndWord;
Word CWord;

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
		EndWord = false;
		SalinKata();
	}
	else{
		EndWord = true;
	}
}

void ADVKATA(){
	IgnoreBlank();
	if (CC == MARK){
		EndWord = true;
	}
	else{
		EndWord = false;
		SalinKata();
	}
}

void SalinKata(){
	int i = 1;
	do{
		if (i <= NMax){
			CWord.TabWord[i] = CC;
			i = i + 1;
		}
		ADV();
	} while (!(CC == MARK || CC == BLANK || CC == ENTER));
	i = i - 1;
	CWord.Length = i;
}

/******** READ THUMBNAIL DATA ********/
void ReadThumbFile(ArrThumb *ArrTh){
	char *count;
	int int_count, j;

	STARTKATA('0');

	count = (char*) malloc ((CWord.Length + 1) *sizeof(char));
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
					(*ArrTh).UserThumb[j].TabWord[i] = CWord.TabWord[i];

					printf("%d. %c", j, CWord.TabWord[i]);
				}
				/** Save the length of the username **/
				(*ArrTh).UserThumb[j].Length = CWord.Length;
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
int ConvertCharInt(Word W){
	char *c_Temp;
	int lenTemp;

	lenTemp = W.Length;
	c_Temp = (char *) malloc ((lenTemp + 1) *sizeof(char));
	c_Temp = W.TabWord;

	return atoi(&c_Temp[1]);
}

void ReadFileExt(Queue *Q, ArrTable *ArrT, ArrOrder *ArrO, Player *P, Stack *Tray, Stack *Hand){
	STARTKATA('1');
	/**** QUEUE ****/
	Head(*Q) = ConvertCharInt(CWord);
	ADVKATA();
	Tail(*Q) = ConvertCharInt(CWord);
	ADVKATA();
	MaxEl(*Q) = ConvertCharInt(CWord);
	/**** ARRTABLE ****/

}
/******** WRITE DATA TO FILE ********/
/******** ********/
/******** ********/
/******** ********/
/******** ********/