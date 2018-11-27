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
// }if(CC=='('){
// 	BuildTree(P);
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


void PrintTree(FoodTree P, ArrFood F, int h, int x){
/* I.S. P dan F terdefinisi, h adalah jarak indentasi (spasi) DIISI 5 !!! */
/* F.S. Semua simpul P sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2: 
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
*/
	/*Kamus lokal*/
	int i;
	/*ALgortima*/
	if (!IsTreeEmpty(P)) {
		if (IsTreeOneElmt(P)) {
			printf("(%c) ", Akar(P));
			i=SearchFoodName(F,Akar(P));
			PrintFoodName(F,F.T[i].FoodCode);
			/*gotoxy(x+1,y);
			x=x+1;*/
			printf("\n");
		} else 
		if (IsUnerLeft(P)){
			printf("(%c) ", Akar(P));
			i=SearchFoodName(F,Akar(P));
			PrintFoodName(F,F.T[i].FoodCode);
			/*gotoxy(x+1,y);
			x=x+1;*/
			printf("\n");
			for (i=1; i<=h+x; i++) {
				if (i==21){
					printf("|");
				}else {
					printf(" ");
				}
			}
			PrintTree(Left(P),F,h+5,x);	
		} else 
		if (IsUnerRight(P)){
			printf("(%c) ", Akar(P));
			i=SearchFoodName(F,Akar(P));
			PrintFoodName(F,F.T[i].FoodCode);
			/*gotoxy(x+1,y);
			x=x+1;*/
			printf("\n");
			for (i=1; i <=h+x; i++) {
				if (i==21){
					printf("|");
				}else {
					printf(" ");
				}
			}
			PrintTree(Right(P),F, h+5,x);
		} else {
			printf("(%c) ", Akar(P));
			i=SearchFoodName(F,Akar(P));
			PrintFoodName(F,F.T[i].FoodCode);
			/*gotoxy(x+1,y);
			x=x+1;*/
			printf("\n");
            for (i = 1; i<=h+x; i++){
                    if (i==21){
						printf("|");
					}else {
						printf(" ");
					}
                }
                PrintTree(Left(P),F,h+5,x);
                for (i = 1; i<=h+x; i++){
                    if (i==21){
						printf("|");
					}else {
						printf(" ");
					}
                }
                PrintTree(Right(P),F,h+5,x);
		}
	}
}

