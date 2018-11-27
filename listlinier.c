/*	NIM				:13517019
	Nama			:Lydia Astrella Wiguna
	Tanggal			:22 Oktober 2018
	Deskripsi		:ADT list linier */
	
/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* infotype adalah integer */


#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>


/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=Nil */

#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) (L).First

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L){
/* Mengirim true jika list kosong */
if (First(L)==Nil){
	return true;
}else{
	return false;
}
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
(*L).First = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X){
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
/*Kamus lokal*/
address P;
/*Algoritma*/
P = (address) malloc(sizeof (ElmtList));
if (P==Nil){
	return Nil;
}else{
	Info(P)=X;
	Next(P)=Nil;
	return P;
}
}
	

void Dealokasi (address *P){
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X){
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
/*Kamus lokal*/
address P;
boolean found;
/*Algoritma*/
P=First(L);
found= false;
while ((P!=Nil) && (!found)){
	if (Info(P) == X){
		found=true;
	}else{
		P=Next(P);
	}
}
if(!found){
	return Nil;
}else{
	return P;
}
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
/*Kamus lokal*/
address P;
/*algoritma*/
P = Alokasi(X);
if (P!=Nil){
	InsertFirst(&(*L),P);
}
}

void InsVLast (List *L, infotype X){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
/*Kamus lokal*/
address P;
/*algoritma*/
P=Alokasi(X);
if (P!=Nil){
	InsertLast(&(*L),P);
}
}


/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X){
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
/*Kamus lokal*/
address P;
/*algoritma*/
DelFirst(&(*L),&P);
*X=Info(P);
Dealokasi(&P);
}

void DelVLast (List *L, infotype *X){
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
/*Kamus lokal*/
address P;
/*algoritma*/
DelLast(&(*L),&P);
*X=Info(P);
Dealokasi(&P);
}


/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
Next(P) = First(*L);
First(*L)=P;
}

void InsertAfter (List *L, address P, address Prec){
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
Next(P)=Next(Prec);
Next(Prec)=P;
}

void InsertLast (List *L, address P){
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
/*Kamus lokal*/
address last;
/*algoritma*/
if (First(*L)==Nil){
	InsertFirst(&(*L),P);
}else{
	last=First(*L);
	while(Next(last)!=Nil){
		last=Next(last);
	}
	InsertAfter(&(*L),P,last);
}
}


/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P){
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
*P=First(*L);
First(*L)=Next(*P);
}

void DelP (List *L, infotype X){
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
/*Kamus lokal*/
address Prec,P;
boolean found;
infotype Elmt;
/*algoritma*/
if(!IsEmpty(*L)){
	if (Info(First(*L))==X){
		DelVFirst(L,&Elmt);
	}else{
		found=false;
		P=First(*L);
		Prec=Nil;
		while (P!=Nil && !found){
			if(Info(P)==X){
				found=true;
				DelAfter(L,&P,Prec);
				Dealokasi(&P);
			}else{
				Prec=P;
				P=Next(P);
			}
		}
	}
}
}

void DelLast (List *L, address *P){
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
/*kamus lokal*/
address pred;
/*algoritma*/
*P=First(*L);
if (Next(First(*L))==Nil){
	First(*L)=Nil;
}else{
	pred = Nil;
	while(Next(*P) != Nil){
		pred=*P;
		*P=Next(*P);
	}
	Next(pred) =Nil;
}
}

void DelAfter (List *L, address *Pdel, address Prec){
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
*Pdel=Next(Prec);
Next(Prec)=Next(*Pdel);
Next(*Pdel)=Nil;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L){
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
/*kamus lokal*/
address P;
/*algoritma*/
printf("[");
P=First(L);
while(P!=Nil){
	printf("%d",Info(P));
	if(Next(P)!=Nil){
		printf(",");
	}
	P=Next(P);
}
printf("]");
}

int NbElmt (List L){
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
/*Kamus lokal*/
int count;
address P;
/*algoritma*/
count=0;
P=First(L);
while(P!=Nil){
	count+=1;
	P=Next(P);
}
return count;
}

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L){
/* Mengirimkan nilai Info(P) yang maksimum */
/*kamus lokal*/
infotype max;
address P;
/*algoritma*/
P=First(L);
max = Info(P);
while(P!=Nil){
	if(max<Info(P)){
		max=Info(P);
	}
	P=Next(P);
}
return max;
}

/****************** PROSES TERHADAP LIST ******************/
void Konkat1 (List *L1, List *L2, List *L3){
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
/*Kamus lokal*/
address lastL1;
/*algoritma*/
CreateEmpty(L3);
lastL1=First(*L1);
if(lastL1==Nil){
	First(*L3) = First(*L2);
}else{
	First(*L3)=lastL1;
	while(Next(lastL1) !=Nil){
		lastL1=Next(lastL1);
	}
	Next(lastL1) = First(*L2);
}
CreateEmpty(L1);
CreateEmpty(L2);
}


