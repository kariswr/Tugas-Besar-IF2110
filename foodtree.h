/* File : foodtree.h */

/* deklarasi binary tree resep makanan yang bisa dibuat*/
/* yang diimplementasi dengan pohon binari berkait dengan representasi fisik pointer */
/* Representasi address dengan pointer */
/* dengan infotype array of char */

#ifndef foodtree_H
#define foodtree_H

#include "library.h"
#include "foodconversion.h"
#include "mesinkar.h"

#define Nil NULL

/*** Konstruktor ***/
void BuildTree (FoodTree *P);
/* Membentuk sebuah pohon biner P dari pita karakter yang dibaca */
/* I.S. Pita berisi "konstanta" pohon yang melambangkan bahan atau makanan dalam bentuk prefix*/
/* Memori pasti cukup, alokasi pasti berhasil.*/
/* F.S. P dibentuk dari ekspresi dalam pita*/

/*** Memory Management ***/
void AlokasiTree (FoodTree *P);
/*Mengirimkan address hasil alokasi sebuah elemen X */

void DealokasiTree (addressNode P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */


/*** Predikat ***/
boolean IsTreeEmpty (FoodTree P);
/* Mengirimkan true jika P adalah pohon biner yang kosong*/
boolean IsTreeOneElmt (FoodTree P);
/* Mengirimkan true jika P tidak kosong dan hanya terdiri
atas 1 elemen */
boolean IsUnerLeft (FoodTree P);
/* Mengirimkan true jika pohon biner tidak kosong P
adalah pohon unerleft: hanya mempunyai subpohon
kiri */
boolean IsUnerRight (FoodTree P);
/* Mengirimkan true jika pohon biner tidak kosong P
adalah pohon unerright: hanya mempunyai subpohon
kanan */
boolean IsBiner (FoodTree P);
/* Mengirimkan true jika pohon biner tidak kosong P
adalah pohon biner: mempunyai subpohon kiri dan
subpohon kanan */

void PrintTree(FoodTree P, ArrFood F, int h);
/* I.S. P terdefinisi, h adalah jarak indentasi (spasi) */
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

#endif
