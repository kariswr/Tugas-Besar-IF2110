/* File : foodtree.h */

/* deklarasi binary tree resep makanan yang bisa dibuat*/
/* yang diimplementasi dengan pohon binari berkait dengan representasi fisik pointer */
/* Representasi address dengan pointer */
/* dengan infotype array of char */


#include "foodtree.h"
#include "foodconversion.h"
#include <stdlib.h>
#include <stdio.h>

/*** Konstruktor ***/
void BuildTree (FoodTree *P){
/* Membentuk sebuah pohon biner P dari pita karakter yang dibaca */
/* SEBELUM MEMAKAI PROSEDUR INI, PAKAI STARTTREE DULU */
/* I.S. Pita berisi "konstanta" pohon yang melambangkan bahan atau makanan dalam bentuk prefix*/
/* Memori pasti cukup, alokasi pasti berhasil.*/
/* F.S. P dibentuk dari ekspresi dalam pita*/
/*Algoritma*/
ADV();
if (CC==')'){ /* Basis : pohon kosong */
	(*P)=Nil;
}else{ /*Rekurens 2*/
	AlokasiTree(P);
	Akar(*P)=CC;
	BuildTree(&(Left(*P)));
	BuildTree(&(Right(*P)));
}
}

/*** Memory Management ***/
void AlokasiTree (FoodTree *P){
/*Mengirimkan address hasil alokasi sebuah elemen X */
/*Algoritma*/
*P = (FoodTree) malloc(sizeof (Node));
}

void DealokasiTree (addressNode P){
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
free(P);
}

/*** Predikat ***/
boolean IsTreeEmpty (FoodTree P){
/* Mengirimkan true jika P adalah pohon biner yang kosong*/
if (P==Nil){
	return true;
}else{
	return false;
}
}

boolean IsTreeOneElmt (FoodTree P){
/* Mengirimkan true jika P tidak kosong dan hanya terdiri
atas 1 elemen */
if (!IsTreeEmpty(P)){
	if(Left(P)==Nil && Right(P)==Nil){
		return true;
	}else{
		return false;
	}
}else{
	return false;
}
}

boolean IsUnerLeft (FoodTree P){
/* Mengirimkan true jika pohon biner tidak kosong P
adalah pohon unerleft: hanya mempunyai subpohon
kiri */
if (!IsTreeEmpty(P) && !IsTreeOneElmt(P)){
	if(Left(P)!=Nil && Right(P)==Nil){
		return true;
	}else{
		return false;
	}
}else{
	return false;
}
}

boolean IsUnerRight (FoodTree P){
/* Mengirimkan true jika pohon biner tidak kosong P
adalah pohon unerright: hanya mempunyai subpohon
kanan */
if (!IsTreeEmpty(P) && !IsTreeOneElmt(P)){
	if(Left(P)==Nil && Right(P)!=Nil){
		return true;
	}else{
		return false;
	}
}else{
	return false;
}
}

boolean IsBiner (FoodTree P){
/* Mengirimkan true jika pohon biner tidak kosong P
adalah pohon biner: mempunyai subpohon kiri dan
subpohon kanan */
if (!IsTreeEmpty(P) && !IsTreeOneElmt(P)){
	if(Left(P)!=Nil && Right(P)!=Nil){
		return true;
	}else{
		return false;
	}
}else{
	return false;
}
}

void ShowFoodTree (FoodTree P ,ArrFood F,int strip,int *jumlahkar){
/*I.S. P terdefinisi
  F.S. P ditampilkan di layar pengguna sudah dalam bentuk string nama makanan beserta kodenya*/
/*Kamus lokal*/
 int i;
 int spasi;
 /*Algoritma*/
 if (!IsTreeEmpty(P)){
	printf("(%c)",Akar(P));
	i=SearchFoodName(F,Akar(P));
	PrintFoodName(F,F.T[i].FoodCode);
	spasi = 7-F.T[i].FoodLength;
	while(spasi >0){
		printf(" ");
		spasi--;
	}
 	if (!IsTreeOneElmt(P)){
 		if(IsUnerLeft(P)){
 			for(i=1;i<=strip;i++){
 				printf("-");
 			}
			*jumlahkar+=(strip+10);
 			ShowFoodTree(Left(P),F,strip,jumlahkar);
 		}else if(IsUnerRight(P)){
			printf("\n");
			for(i=1;i<=(*jumlahkar-3);i++){
				printf(" ");
			}
			for(i=1;i<=strip;i++){
				printf("-");
			}
			ShowFoodTree(Right(P),F,strip,jumlahkar);
			*jumlahkar-=(strip+10);
		}else{ /*IsBiner(P)*/
			for(i=1;i<=strip;i++){
 				printf("-");
 			}
			*jumlahkar+=(strip+10);
 			ShowFoodTree(Left(P),F,strip,jumlahkar);
			printf("\n");
			for(i=1;i<=(*jumlahkar-3);i++){
				printf(" ");
			}
			for(i=1;i<=strip;i++){
				printf("-");
			}
			ShowFoodTree(Right(P),F,strip,jumlahkar);
			*jumlahkar -=(strip+10);
		}
 	}
 }
 }