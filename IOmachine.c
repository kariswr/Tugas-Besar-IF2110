#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IOmachine.h"

static FILE *pita;
static int retval;

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

/******** ********/
/******** ********/
/******** ********/
/******** ********/
/******** ********/
/******** ********/