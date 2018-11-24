#include "mesinkata.h"

void IgnoreBlank() {
	while (((CC == BLANK) || (CC == ENTER)) && (CC != MARK)){
		ADV();
	}
}

void STARTKATA(){
	START();
	IgnoreBlank();
	switch (CC){
		case MARK :{
			EndKata = true;
			break;
		}
		default :{
			EndKata = false;
			SalinKata();
		}
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
	int i;
	i = 1;
	do{
		// printf("%c\n",CC);
		if (i <= NMax){
			CKata.TabKata[i] = CC;
			i++;
		}
		ADV();
	} while (!(CC == MARK || CC == BLANK || CC == ENTER));
	i--;
	CKata.Length = i;
}
