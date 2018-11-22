/* File : handtray.h */

/* deklarasi stack bahan makanan pada tangan atau makanan pada tray*/
/* yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */

#include "handtray.h"

#define Nil 0

/* Nil adalah stack dengan elemen kosong . */
/* Karena indeks dalam bhs C dimulai 0 maka tabel dg indeks 0 tidak dipakai */

typedef int address;   /* indeks tabel */

/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
/* Definisi stack S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai Stack T[1]..T[MaxEl] */
/* Jika S adalah Stack maka akses elemen : */
   /* S.T[(S.TOP)] untuk mengakses elemen TOP */
   /* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]


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


