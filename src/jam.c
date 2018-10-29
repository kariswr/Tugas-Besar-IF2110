//Nama : Karina Iswara
//NIM : 13517031
//Nama file : jam.c
//Tanggal : 5 September 2018
//Topik : Pra Praktikum 2
//Deskripsi : ADT Jam

#include "boolean.h"
#include "jam.h"
#include <stdio.h>

boolean IsJAMValid (int H, int M, int S) {
//True jika H,M,S dapat membentuk J yang valid.
//Untuk mentest sebelum membentuk sebuah jam
	//Algoritma IsJAMValid
	if ((H>=0 && H<24) && (M>=0 && M<60) && (S>=0 && S<60)) {
		return (true);
	}
	else {
		return (false);
	}
}

JAM MakeJAM (int HH, int MM, int SS) {
//Membentuk sebuah JAM dari komponen-komponennya yang valid 
//Prekondisi : HH, MM, SS valid untuk membentuk JAM
	//Kamus
	JAM J;
	//Algoritma MakeJAM
	Hour (J) = HH;
	Minute (J) = MM;
	Second (J) = SS;

	return (J);
}

void BacaJAM (JAM * J){
//I.S. : J tidak terdefinisi
//F.S. : J terdefinisi dan valid
//Mengulangi pembacaan komponen HH,MM,SS sampai mendapat inputan yang dapat
//menghasilkan J yang valid.
// Jika JAM tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
// diulangi hingga didapatkan jam yang valid. 
	//Kamus
	int HH,MM,SS;

	//Algoritma BacaJAM
	scanf ("%d %d %d", &HH,&MM,&SS);
	while (IsJAMValid (HH,MM,SS) == false) {
		printf ("Jam tidak valid");
		scanf ("%d %d %d", &HH,&MM,&SS);
	}
	*J= MakeJAM (HH,MM,SS);
}

void TulisJAM (JAM J) {
//I.S. : J sembarang */
//F.S. :   Nilai J ditulis dg format HH:MM:SS */
//Proses : menulis nilai setiap komponen J ke layar dalam format HH:MM:SS
//   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll. 
	//Algoritma TulisJAM
	printf ("%02d:%02d:%02d", Hour (J), Minute (J), Second (J));
}

long JAMToDetik (JAM J){
//Diberikan sebuah JAM, mengkonversi menjadi jumlah detik dari pukul 0:0:0
// Rumus : detik = 3600*HH + 60*MM + SS 
// Nilai maksimum = 3600*23+59*60+59 
	//Kamus
	int totalDetik;
	//Algoritma JAMtoDetik
	totalDetik = 3600*Hour(J) + 60*Minute(J) + Second(J);

	return (totalDetik);
}

JAM DetikToJAM (long N) {
//Mengubah detik ke type data JAM
	//Kamus
	JAM J;
	//Algoritma DetikToJAM
	if (N>=86400) {
		N = N % 86400;	
	}
	Hour (J) = N / 3600;
	Minute (J) = (N % 3600) / 60;
	Second (J) = (N % 3600) % 60;

	return (J);
}

boolean JEQ (JAM J1, JAM J2){
// Mengirimkan true jika J1=J2, false jika tidak
	//Kamus 
	long detikJ1, detikJ2;
	//Algoritma JEQ
	detikJ1 = JAMToDetik (J1);
	detikJ2 = JAMToDetik (J2);
	if (detikJ1 == detikJ2) {
		return (true);
	}
	else {
		return (false);
	}
}

boolean JNEQ (JAM J1, JAM J2) {
//Mengirimkan true jika J1 tidak sama dengan J2 
	//Algoritma
	return (!JEQ(J1,J2));
}

boolean JLT (JAM J1, JAM J2){
//Mengirimkan true jika J1<J2, false jika tidak 
	//Kamus
	long detikJ1, detikJ2;
	//Algoritma JLT
	detikJ1 = JAMToDetik (J1);
	detikJ2 = JAMToDetik (J2);
	if (detikJ1 < detikJ2) {
		return (true);
	}
	else {
		return (false);
	}
}


boolean JGT (JAM J1, JAM J2){
// Mengirimkan true jika J1>J2, false jika tidak
	long detikJ1, detikJ2;
	//Algoritma JGT
	detikJ1 = JAMToDetik (J1);
	detikJ2 = JAMToDetik (J2);
	if (detikJ1 > detikJ2) {
		return (true);
	}
	else {
		return (false);
	}
}

JAM NextDetik (JAM J){
// Mengirim 1 detik setelah J dalam bentuk JAM
	//Kamus
	long totalDetik;
	//Algoritma NextDetik
	totalDetik = JAMToDetik (J);
	return (DetikToJAM (totalDetik+1));
}

JAM NextNDetik (JAM J, int N) {
// Mengirim N detik setelah J dalam bentuk JAM
	//Kamus
	long totalDetik;
	//Algoritma NextNDetik
	totalDetik = JAMToDetik (J);
	return (DetikToJAM (totalDetik+N));
}

JAM PrevDetik (JAM J){
// Mengirim 1 detik sebelum J dalam bentuk JAM 
	//Kamus
	long totalDetik;
	//Algoritma PrevDetik
	totalDetik = JAMToDetik (J);
	return (DetikToJAM (totalDetik-1));
}

JAM PrevNDetik (JAM J, int N){
// Mengirim N detik sebelum J dalam bentuk JAM 
	//Kamus
	long totalDetik;
	//Algoritma PrevNDetik
	totalDetik = JAMToDetik (J);
	return (DetikToJAM (totalDetik-N));
}

long Durasi (JAM JAw, JAM JAkh){
// Mengirim JAkh-JAw dlm Detik, dengan kalkulasi
// Jika JAw > JAkh, maka JAkh adalah 1 hari setelah JAw 
	//Kamus
	long Durasi;
	//Algoritma Durasi
	if (JGT (JAw,JAkh)) {
		Second (JAkh) += 86400;
	}
	Durasi = JAMToDetik(JAkh) -JAMToDetik (JAw);
	return (Durasi);
}

