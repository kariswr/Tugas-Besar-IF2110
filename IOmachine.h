#ifndef IO_MACHINE_H
#define IO_MACHINE_H

#include "library.h"

extern char CC;
extern boolean EOP;
extern boolean EndKata;
extern Kata CKata;

/******** MESIN KARAKTER ********/
void START(char n);
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita
		  Jika CC != MARK maka EOP akan padam (false)
		  Jika CC = MARK maka EOP akan menyala (true) */

void ADV();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama,
		  CC mungkin = MARK
		  Jika  CC = MARK maka EOP akan menyala (true) */

/******** MESIN KATA ********/
void IgnoreBlank();
/* 	I.S :	CC Sembarang
	F.S :	Skip BLANK atau ' ' */

void STARTKATA(char n);
/* 	I.S. : 	CC sembarang
	F.S. : 	EndKata = true, dan CC = MARK;
			atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
			CC karakter pertama sesudah karakter terakhir kata */

void ADVKATA();
/* 	I.S. : 	CC adalah karakter pertama kata yang akan diakuisisi
	F.S. : 	CKata adalah kata terakhir yang sudah diakuisisi,
			CC adalah karakter pertama dari kata berikutnya, mungkin MARK
			Jika CC = MARK, EndKata = true.
	Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinKata();
/* Mengakuisisi kata, menyimpan dalam CKata
	I.S. :	CC adalah karakter pertama dari kata
	F.S. :	CKata berisi kata yang sudah diakuisisi;
			CC = BLANK atau CC = MARK;
			CC adalah karakter sesudah karakter terakhir yang diakuisisi.
			Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

#endif