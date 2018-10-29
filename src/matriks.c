//Nama/NIM : Karina Iswara/ 13517031
//Tanggal : 16 September 2018
//Topik : Pra Praktikum 4
//Deskripsi : ADT matriks.hs

#include <stdio.h>
#include "boolean.h"
#include "matriks.h"

void MakeMATRIKS (int NB, int NK, MATRIKS * M){
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
	NBrsEff (*M) = NB;
	NKolEff (*M) = NK;
}

boolean IsIdxValid (int i, int j){
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
	if ((i >= BrsMin) && (i<=BrsMax) && (j>=KolMin) && (j<=KolMax)) {
		return true;
	} else {
		return false;
	}
}

indeks GetFirstIdxBrs (MATRIKS M){
/* Mengirimkan indeks baris terkecil M */
	return BrsMin;
}

indeks GetFirstIdxKol (MATRIKS M){
/* Mengirimkan indeks kolom terkecil M */
	return KolMin;
}

indeks GetLastIdxBrs (MATRIKS M){
/* Mengirimkan indeks baris terbesar M */
	return (NBrsEff (M));
}

indeks GetLastIdxKol (MATRIKS M){
/* Mengirimkan indeks kolom terbesar M */
	return (NKolEff(M));
}

boolean IsIdxEff (MATRIKS M, indeks i, indeks j){
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
	if ((i > GetLastIdxBrs (M)) || (i<GetFirstIdxBrs(M)) || (j<GetFirstIdxKol(M)) || (j > GetLastIdxKol(M))) {
		return false;
	} else {
		return true;
	}
}

ElType GetElmtDiagonal (MATRIKS M, indeks i){
/* Mengirimkan elemen M(i,i) */
	return Elmt (M,i,i);
}

void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl){
/* Melakukan assignment MHsl  MIn */
	//Kamus
	indeks i,j;
	//Algoritma
	MakeMATRIKS (NBrsEff(MIn),NKolEff(MIn),MHsl);
	for (i=GetFirstIdxBrs (MIn); i <=GetLastIdxBrs(MIn);i++) {
		for (j=GetFirstIdxKol(MIn); j<=GetLastIdxKol(MIn); j++) {
			Elmt (*MHsl,i,j) = Elmt (MIn,i,j);
		}
	}
}	
 
void BacaMATRIKS (MATRIKS * M, int NB, int NK) {
/* I.S. IsIdxValid(NB,NK) */ 
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
	//Kamus
	indeks i,j;
	//Algoritma
	MakeMATRIKS (NB,NK,M);
	for (i=GetFirstIdxBrs(*M); i <=NB;i++) {
		j=GetFirstIdxKol(*M);
		while (j<=NK) {
			scanf ("%d",&Elmt (*M,i,j));
			j++;
		}
	}
}

void TulisMATRIKS (MATRIKS M){
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
	//Kamus
	indeks i,j;
	//Algoritma
	for (i=GetFirstIdxBrs(M); i <=GetLastIdxBrs(M);i++) {
		for (j=GetFirstIdxKol(M); j <GetLastIdxKol(M); j++){
			printf ("%d ",Elmt (M,i,j));
		}
		if (i!= GetLastIdxBrs(M)) {
			printf ("%d\n",Elmt (M,i,j));
		} else {
			printf ("%d",Elmt (M,i,j));
		}
	}
}
                               
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2){
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */
	//KAMUS
	MATRIKS M;
	indeks i,j;
	//Algoritma
	MakeMATRIKS (NBrsEff(M1),NKolEff(M1),&M);
	for (i=GetFirstIdxBrs(M1); i <=GetLastIdxBrs(M1);i++) {
		for (j=GetFirstIdxKol(M1); j<=GetLastIdxKol(M1); j++) {
			Elmt (M,i,j) = Elmt (M1,i,j) + Elmt (M2,i,j);
		}
	}
	return M;
}

MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2){
/* Prekondisi : M1 berukuran sama dengan M2 */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */ 
	//Kamus
	MATRIKS M;
	indeks i,j;
	//Algoritma
	MakeMATRIKS (NBrsEff(M1),NKolEff(M1),&M);
	for (i=GetFirstIdxBrs(M1); i <=GetLastIdxBrs(M1);i++) {
		for (j=GetFirstIdxKol(M1); j<=GetLastIdxKol(M1); j++) {
			Elmt (M,i,j) = Elmt (M1,i,j) - Elmt (M2,i,j);
		}
	}
	return M;
}

MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2){
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
	//Kamus
	MATRIKS M;
	indeks i,j,k;
	//Algoritma
	MakeMATRIKS (NBrsEff(M1),NKolEff(M2),&M);
	for (i=GetFirstIdxBrs(M1); i <=GetLastIdxBrs(M2);i++) {
		for (j=GetFirstIdxKol(M2); j<=GetLastIdxKol(M2); j++) {
			Elmt (M,i,j) = 0;
			for (k=GetFirstIdxBrs(M2);k<=GetLastIdxBrs(M2);k++){
				Elmt (M,i,j) += (Elmt (M1,i,k) * Elmt (M2,k,j));
			}
		}
	}
	return M;
}

MATRIKS KaliKons (MATRIKS M, ElType X){
/* Mengirim hasil perkalian setiap elemen M dengan X */
	//Kamus
	indeks i,j;
	//Algoritma
	for (i=GetFirstIdxBrs(M); i <=GetLastIdxBrs(M);i++) {
		for (j=GetFirstIdxBrs(M); j<=GetLastIdxKol(M); j++) {
			Elmt (M,i,j) = Elmt (M,i,j) * X;
		}
	}
	return M;
}

void PKaliKons (MATRIKS * M, ElType K){
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */
	//Algoritma
	*M= KaliKons (*M,K);
}

boolean EQ (MATRIKS M1, MATRIKS M2){
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2) 
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
	//Kamus
	indeks i,j;
	boolean cek;
	//Algoritma
	if ((NBrsEff (M1) != NBrsEff (M2)) || (NKolEff(M1) != NKolEff(M2))) {
		return false;
	} else {
		cek = true;
		for (i=GetFirstIdxBrs(M1); i <=GetLastIdxBrs(M1);i++) {
			for (j=GetFirstIdxKol(M1); j<=GetLastIdxKol(M1); j++) {
				if (Elmt (M1,i,j) != Elmt (M2,i,j)) {
					cek = false;
				}
			}
		}
		return cek;
	}
}

boolean NEQ (MATRIKS M1, MATRIKS M2){
/* Mengirimkan true jika M1 tidak sama dengan M2 */
	if (!EQ (M1,M2)) {
		return true;
	} else {
		return false;
	}
}

boolean EQSize (MATRIKS M1, MATRIKS M2){
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
	if ((NBrsEff(M1) != NBrsEff(M2)) || (NKolEff(M1)!= NKolEff(M2))) {
		return false;
	} else {
		return true;
	}
}

int NBElmt (MATRIKS M){
/* Mengirimkan banyaknya elemen M */
	return (NBrsEff(M) * NKolEff(M));
}

boolean IsBujurSangkar (MATRIKS M){
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
	if (NBrsEff(M) == NKolEff(M)) {
		return true;
	} else {
		return false;
	}
}

boolean IsSimetri (MATRIKS M){
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M) 
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
	//Kamus
	indeks i,j;
	boolean cek;
	//Algoritma
	if (!IsBujurSangkar (M)) {
		return false;
	} else {
		cek = true;
		for (i= GetFirstIdxBrs(M);i <=GetLastIdxBrs(M);i++) {
			for (j=GetFirstIdxKol(M);j<=i;j++){
				if (Elmt (M,i,j) != Elmt (M,j,i)) {
					cek = false;
				}
			}
		}
	} 
	return cek;
}


boolean IsSatuan (MATRIKS M) {
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan 
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */ 
	//Kamus
	indeks i,j;
	boolean cek;
	//Algoritma
	if (!IsBujurSangkar(M)) {
		return false;
	} else {
		cek = true;
		for (i = GetFirstIdxBrs(M);i<= GetLastIdxBrs(M); i++) {
			for (j=GetFirstIdxKol(M); j<= GetLastIdxKol(M);j++) {
				if (i==j){
					if (Elmt (M,i,j) != 1) {
					cek = false;
					}
				} else {
					if (Elmt (M,i,j) != 0 ) {
						cek = false;
					}
				}
			}
		}
	}
	return cek;
}

boolean IsSparse (MATRIKS M){
/* Mengirimkan true jika M adalah matriks sparse: matriks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */ 
	//Kamus
	int persen, count;
	indeks i,j;
	//Algoritma
	persen = NBrsEff(M)*NKolEff(M)*0.05;
	count = 0;
	for (i=GetFirstIdxBrs(M); i<=GetLastIdxBrs(M);i++) {
		for (j=GetFirstIdxKol(M); j <=GetLastIdxKol(M);j++) {
			if (Elmt (M,i,j) != 0) {
				count ++;
			}
		}
	}
	if (count > persen) {
		return false;
	} else {
		return true;
	}
}
	

MATRIKS Inverse1 (MATRIKS M){
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
	//Algoritma
	return KaliKons(M,-1);
}

float Determinan (MATRIKS M){
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
	//Kamus
	float Mout [GetLastIdxBrs(M)+1][GetLastIdxKol(M)+1];
	indeks i,k,j;
	float koef,det,temp;
	boolean found, zero;
	//Algoritma
	//Membuat Mout terdefinisi dengan nilai Matriks M yang bertipe float
	for (i=GetFirstIdxBrs(M);i<=GetLastIdxBrs(M);i++){
		for (j=GetFirstIdxKol(M);j<=GetLastIdxKol(M);j++){
			Mout[i][j] = (float)Elmt (M,i,j);
		}
	}

	/*Mengecek apakah diagonal utama bernilai 0. Jika iya maka ditukar dengan
	baris lain.jika tidak maka elemen sebaris di bawahnya dikurangi menadi 0.
	Jika tidak ada baris yang bernilai != 0 maka det =0*/
	j=GetFirstIdxKol(M);
	zero = false;
	det =1;
	while ((j<=GetLastIdxKol(M)-1) && (!zero)){
		if (Mout[j][j] != 0) {
			for (i=j+1;i<=GetLastIdxBrs(M);i++){
				koef = Mout[i][j]/Mout[j][j];
				for (k=j;k<=GetLastIdxKol(M);k++) {
					Mout[i][k] -= (koef * Mout[j][k]);
				}
			}
		}
		else { //Diagonal utama 0
			found = false;
			i = j+1;
			while (i<=GetLastIdxBrs(M) && (!found)) { //Cari baris yang dpt ditukar dgn diagonal utama sehingga != 0
				if (Mout [i][j] != 0) {
					found = true;
				} else {
					i ++;
				}
			}
			if (found) { //tukar baris
				for (k=GetFirstIdxKol(M); k<=GetLastIdxKol(M);k++) {
					temp = Mout [j][k];
					Mout [j][k] = Mout [i][k];
					Mout [i][k] = temp;
				}
				for (i=j+1;i<=GetLastIdxBrs(M);i++){
					koef = Mout[i][j]/Mout[j][j];
					for (k=j;k<=GetLastIdxKol(M);k++) {
						Mout[i][k] -= koef * Mout[j][k];
					}
				}
				det *= -1;
			} else { //tidak ditemukan baris yang dapat membuat diagonal utama != 0
				zero = true;
			}
		}
		j++;
	}
	for (i=GetFirstIdxKol(M);i<=GetLastIdxKol(M);i++){
		det *= Mout [i][i];
	}
	if (det==-0) {
		det =0;
	}
	return det;
}

void PInverse1 (MATRIKS * M){
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
	//Algoritma
	*M= Inverse1 (*M);
}

void Transpose (MATRIKS * M){
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
	//Kamus
	indeks i,j;
	int temp;
	//Algoritma
	for (i=GetFirstIdxBrs(*M)+1; i<=GetLastIdxBrs(*M);i++) {
		for (j=GetFirstIdxBrs(*M);j<=i-1;j++) {
			temp = Elmt (*M,i,j);
			Elmt (*M,i,j) = Elmt (*M,j,i);
			Elmt (*M,j,i) = temp;
		}
	}
}