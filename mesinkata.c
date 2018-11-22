/*Nama		:Lydia Astrella Wiguna
 * NIM		:13517019
 * Tanggal	:22-9-2018
 * Topik	:ADT mesin kata*/

/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */


#include "library.h"
#include "mesinkar.h"

/* State Mesin Kata */
 boolean EndKata;
 Kata CKata;

void IgnoreBlank(){
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */
while (CC==BLANK){
	ADV();
}
}

void SalinKata(){
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
/*Kamus Lokal*/
int i;
/*Algortima*/
i=1;
while (CC!=MARK || CC!=BLANK){
	CKata.TabKata[i]=CC;
	ADV();
	if (CC==MARK || CC==BLANK || i>=NMax){
		break;
	}else{
		i++;
	}
}
CKata.Length=i;
}



void STARTKATA(){
/* I.S. : CC sembarang 
   F.S. : EndKata = true, dan CC = MARK; 
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
IgnoreBlank();
if (CC==MARK){
	EndKata=true;
}else{
	EndKata=false;
	SalinKata();
}
}

void ADVKATA(){
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */
IgnoreBlank();
if (CC==MARK){
	EndKata=true;
} else{
	SalinKata();
	IgnoreBlank();
}
}

