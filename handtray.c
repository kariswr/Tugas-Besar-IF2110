/* File : handtray.h */

/* deklarasi stack bahan makanan pada tangan atau makanan pada tray*/
/* yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */

#include "handtray.h"
#include "foodtree.h"
#include <stdio.h>


/* Nil adalah stack dengan elemen kosong . */
/* Karena indeks dalam bhs C dimulai 0 maka tabel dg indeks 0 tidak dipakai */

typedef int address;   /* indeks tabel */

/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
/* Definisi stack S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai Stack T[1]..T[MaxEl] */
/* Jika S adalah Stack maka akses elemen : */
   /* S.T[(S.TOP)] untuk mengakses elemen TOP */
   /* S.TOP adalah alamat elemen TOP */


/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStack (Stack *S){
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP bernilai Nil */
Top(*S)=Nil;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsStackEmpty (Stack S){
/* Mengirim true jika Stack kosong: lihat definisi di atas */
if (Top(S) == Nil){
	return true;
}else{
	return false;
}
}

boolean IsStackFull (Stack S){
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
if (Top(S) == MaxStack){
	return true;
}else{
	return false;
}
}

/* ************ Menambahkan sebuah bahan ke Stack Hand atau Tray************ */
void Push (Stack * S, char C){
/* Menambahkan bahan atau makanan sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. bahan menjadi TOP yang baru,TOP bertambah 1 */
(*S).TOP +=1;
(*S).T[Top(*S)] = C;
}

/* ************ Menghapus sebuah elemen Stack Tray ************ */
void PopTray (Stack * S, char * C){
/* Menghapus C dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
*C=InfoTop(*S);
(*S).TOP -=1;
}

char CompareFood (Stack *H, Stack *T, FoodTree F){
/* membandingkan bahan-bahan dengan resep*/
/* I.S. H terdefinisi*/
/* F.S. menghasilkan FoodCode bila sesuai resep, '0' bila tidak berhasil*/
	/*Kamus lokal*/
	Stack temp;
	char C,X;
	boolean accept;
	addressNode P;
	
	/*Algoritma*/
	CreateEmptyStack(&temp);
	while (Top(*H) != Nil){
		PopTray(H,&C);
		Push(&temp,C);
	}
	accept = true;
	PopTray(&temp,&C);
	Push(H,C);
	if (C != Akar(F)){
		accept=false;
	}
	P=F;
	while (Top(temp)!=Nil && accept){
		PopTray(&temp,&C);
		Push(H,C);
		if(IsBiner(P)){
			if (C == Akar(Right(P))){
				P=Right(P);
			}else if (C == Akar(Left(P))){
				P=Left(P);
			}else{
				accept=false;
			}
		}else if (IsUnerLeft(P)){
			if (C==Akar(Left(P))){
				P=Left(P);
			}else{
				accept=false;
			}
		}else if (IsUnerRight(P)){
			if (C==Akar(Right(P))){
				P=Right(P);
			}else{
				accept=false;
			}
		}else if (IsTreeOneElmt(P)){
			accept=false;
		}
	}
	if (accept){
		if (IsUnerLeft(P)){
			P=Left(P);
			if(IsTreeOneElmt(P)){
				X=Akar(P);
			}else{
				accept=false;
			}
		}else{
			accept=false;
		}
	}
	if(accept){
		if (!IsStackFull(*T)){
			Push(T,X);
			while (Top(*H) != Nil){
				PopTray(H,&C);
			}
			return X;
		}else{
			while (!IsStackEmpty(temp)){
				PopTray(&temp,&C);
				Push(H,C);
			}
			return '0';
		}
	}else{
		while (!IsStackEmpty(temp)){
			PopTray(&temp,&C);
			Push(H,C);
		}
		return '0';
	}
}
