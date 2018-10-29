//Nama : Karina Iswara
//NIM : 13517031
//Nama file : point.c
//Tanggal : 5 September 2018
//Topik : Pra Praktikum 2
//Deskripsi : ADT point

#include <stdio.h>
#include "boolean.h"
#include "point.h"
#include <math.h>

POINT MakePOINT (float X, float Y){
//Membentuk sebuah POINT dari komponen-komponennya
	//Kamus
	POINT P;
	//Algoritma
	Absis (P) = X;
	Ordinat (P) = Y;

	return (P);
}

void BacaPOINT (POINT * P){
// Membaca nilai absis dan ordinat dari keyboard dan membentuk 
// POINT P berdasarkan dari nilai absis dan ordinat tersebut 
// I.S. Sembarang 
// F.S. P terdefinisi 
	//Kamus
	float X,Y;
	//Algoritma
	scanf ("%f %f",&X,&Y);
	*P = MakePOINT (X,Y);
}

void TulisPOINT (POINT P){
//Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
// I.S. P terdefinisi
// F.S. P tertulis di layar dengan format "(X,Y)" 
	//Algoritma
	printf ("(%.2f,%.2f)", Absis (P),Ordinat(P));
}

boolean EQ (POINT P1, POINT P2){
// Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama
	//Algoritma
	if ((Absis (P1) == Absis (P2)) && (Ordinat(P1) == Ordinat (P2))) {
		return (true);
	}
	else {
		return (false);
	}
}

boolean NEQ (POINT P1, POINT P2){
// Mengirimkan true jika P1 tidak sama dengan P2
	//Algoritma
	return (!EQ (P1,P2));
}

boolean IsOrigin (POINT P){
// Menghasilkan true jika P adalah titik origin
	//Algoritma
	if ((Absis (P)==0) && (Ordinat (P)==0)) {
		return (true);
	}
	else {
		return (false);
	}
}

boolean IsOnSbX (POINT P){
// Menghasilkan true jika P terletak Pada sumbu X
	//Algoritma 	
	if (Ordinat (P)== 0) {
		return (true);
	}
	else {
		return (false);
	}
}

boolean IsOnSbY (POINT P){
//Menghasilkan true jika P terletak pada sumbu Y
//Algoritma 	
	if (Absis (P)== 0) {
		return (true);
	}
	else {
		return (false);
	}
}

int Kuadran (POINT P){
// Menghasilkan kuadran dari P: 1, 2, 3, atau 4 
// Prekondisi : P bukan titik origin, 
//              dan P tidak terletak di salah satu sumbu 
	//Kamus
	int kuadran;
	//Algoritma
	if (Absis (P) >0) {
		if (Ordinat (P)>0) {
			kuadran = 1;
		}
		else {
			kuadran = 4;
		}
	}
	else {
		if (Ordinat (P)>0) {
			kuadran = 2;
		}
		else {
			kuadran = 3;
		}
	}
	return (kuadran);
}

POINT NextX (POINT P){
// Mengirim salinan P dengan absis ditambah satu
	//Algoritma
	Absis (P) = Absis (P) +1;
	return (P);
}

POINT NextY (POINT P){
// Mengirim salinan P dengan ordinat ditambah satu	
	//Algoritma
	Ordinat (P) = Ordinat (P) +1;
	return (P);
}

POINT PlusDelta (POINT P, float deltaX, float deltaY){
//Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY 
	//Algoritma
	Absis (P) = Absis (P) + deltaX;
	Ordinat (P) = Ordinat (P) + deltaY;
	return (P);
}

POINT MirrorOf (POINT P, boolean SbX){
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
	//Algoritma
	if (SbX) {
		Ordinat(P) = -1 * Ordinat (P);
	}
	else {
		Absis (P) = -1 * Absis (P);
	}
	return (P);
}

float Jarak0 (POINT P){
// Menghitung jarak P ke (0,0) 
	//Kamus
	float jarak;
	//Algoritma
	jarak = sqrt ((Absis (P)*Absis(P))+(Ordinat (P)*Ordinat(P)));
	return (jarak);
}

float Panjang (POINT P1, POINT P2) {
//Menghitung jarak dari P1 ke P2
	//Kamus
	float jarak,deltaX, deltaY;
	//Algoritma
	deltaX = Absis (P1)- Absis (P2);
	deltaY = Ordinat (P1)- Ordinat (P2);
	jarak = sqrt ((deltaX*deltaX)+(deltaY*deltaY));
	return (jarak);
}

void Geser (POINT *P, float deltaX, float deltaY){
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
	//Algoritma
	Absis (*P) += deltaX;
	Ordinat (*P) += deltaY;
}

void GeserKeSbX (POINT *P){
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
	//Algoritma
	Ordinat (*P) = 0;
}

void GeserKeSbY (POINT *P){
/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
	//Algoritma
	Absis (*P) = 0;
}

void Mirror (POINT *P, boolean SbX){
/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */
	//Algoritma
	if (SbX){
		Ordinat (*P) = -1 * Ordinat (*P);
	}
	else 
		Absis (*P) = -1 * Absis (*P);
}

void Putar (POINT *P, float Sudut){
/* I.S. P terdefinisi */
/* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) */
	//kamus
	float X1, X2, Y1, Y2;
	double rad;
	//Algoritma
	X1 = Absis(*P);
	Y1 = Ordinat(*P);
	rad = (Sudut * 3.14159265 / 180);

	X2 = X1*(cos(rad)) - Y1*(sin(rad));
	Y2 = Y1*(cos(rad)) + X1*(sin(rad));

	Absis(*P) = X2;
	Ordinat(*P) = Y2;
}