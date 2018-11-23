
#include <stdio.h>
#include <string.h>
#include "library.h"
#include "foodconversion.h"
#include "mesinkata.h"

void ReadFood (ArrFood *F){
/*membaca file eksternal, memasukkan datanya ke dalam tabel T*/
/*I.S. T kosong*/
/*F.S. T terisi sesuai data file eksternal*/
/*Kamus lokal*/
char X;
/*Algoritma*/
STARTFOOD();
STARTKATA();
while(!EndKata && !IsArrFoodFull(*F)){
	X = CKata.TabKata[1];
    ADVKATA();
    AddLastElFood(F,X,CKata);
    ADVKATA();
}
}

void MakeEmptyFood (ArrFood * F){
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas MaxFood */
	//Algoritma MakeEmpty
	Neff(*F) = 0;
}

boolean IsArrFoodEmpty (ArrFood F){
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
	//Algoritma IsEmpty
	if (Neff(F) == 0 ){
		return true;
	} else {
		return false;
	}
}

boolean IsArrFoodFull (ArrFood F){
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
	//Algoritma IsFull
	if (Neff(F) == MaxFood ){
		return true;
	} else {
		return false;
	}
}

int SearchFoodName (ArrFood F, char X){
/* Search apakah ada elemen tabel T dengan kode X */
/* Jika ada, menghasilkan indeks T */
/* Jika tidak ada, mengirimkan 0 */
	//Kamus
	boolean found;
	int i;
	//Algoritma
	found = false;
	i = 1;
	while (!found && (i<=Neff(F))) {
		if (F.T[i].FoodCode == X ) {
			found = true;
		} else {
			i++;
		}
	}
	if(found){
		return i;
	}else{
		return 0;
	}
}

void AddLastElFood (ArrFood * F, char X, Kata CKata){
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
	//Kamus lokal
	int i;
	//Algoritma
    Neff (*F) += 1;
	(*F).T[Neff(*F)].FoodCode = X;
	(*F).T[Neff(*F)].FoodLength = CKata.Length;
	for (i=1;i<=(*F).T[Neff(*F)].FoodLength;i++){
		if(CKata.TabKata[i]=='-'){
			(*F).T[Neff(*F)].FoodName[i]=' ';
		}else{
    		(*F).T[Neff(*F)].FoodName[i]= CKata.TabKata[i];
		}
	}
}

void PrintFoodName(ArrFood F, char X){
/* I.S. F dan X terdefinisi*/
/* F.S. print nama makanan berdasarkan FoodCode*/
	//Kamus lokal
	int i,j;
	//Algoritma
	i=SearchFoodName(F,X);
	if(1!=0){
		for (j=1;j<=F.T[i].FoodLength;j++){
			printf("%c",F.T[i].FoodName[j]);
		}
	}
}

void PrintFoodTable (ArrFood F){
/* untuk menampilkan keterangan meja dapur*/
/* I.S. F terdefinisi*/
/* F.S. keterangan meja dapur ditampilkan*/
	//Kamus lokal
	int i;
	//Algoritma
	printf("Hmm.. Where should I take the ingrendients/utensils?\n");
	printf("\n");
	printf("Kitchen Counter | Ingrendients/Utensils Name\n");
	for (i=1;i<=15;i++){
		printf("        %c       |  ",F.T[i].FoodCode);
		PrintFoodName(F,F.T[i].FoodCode);
		printf("\n");
	}
	printf("        %c       |  ",F.T[22].FoodCode);
	PrintFoodName(F,F.T[22].FoodCode);
	printf("\n");
}