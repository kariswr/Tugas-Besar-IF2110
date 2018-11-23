/* ADT konversi makanan */

/* deklarasi array yang menampung kode makanan dan nama makanan*/
/* ADT ini digunakan untuk menampilkan nama makanan berdasarkan kode*/
/* kode dan nama makanan diambil dari file eksternal*/

#ifndef FOODCONVERSION_H
#define FOODCONVERSION_H

#include "library.h"
#include "mesinkata.h"

void ReadFood (ArrFood *T);
/*membaca file eksternal, memasukkan datanya ke dalam tabel T*/
/*I.S. T kosong*/
/*F.S. T terisi sesuai data file eksternal*/

void MakeEmptyFood (ArrFood * T);
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas MaxFood */

boolean IsArrFoodEmpty (ArrFood T);
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */

boolean IsArrFoodFull (ArrFood T);
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

int SearchFoodName (ArrFood T, char X);
/* Search apakah ada elemen tabel T dengan kode X */
/* Jika ada, menghasilkan indeks T */
/* Jika tidak ada, mengirimkan 0 */

void AddLastElFood (ArrFood * T, char X, Kata CKata);
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */

void PrintFoodName(ArrFood F, char X);
/* I.S. F dan X terdefinisi*/
/* F.S. print nama makanan berdasarkan FoodCode*/

void PrintFoodTable (ArrFood F);
/* untuk menampilkan keterangan meja dapur*/
/* I.S. F terdefinisi*/
/* F.S. keterangan meja dapur ditampilkan*/

#endif
