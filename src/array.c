//Nama/NIM : Karina Iswara/13517031
//Tanggal : 10 September 2018
//Topik : Pra Praktikum 3
//Deskripsi : ADT array.h

#include <stdio.h>
#include "array.h"
#include "boolean.h"

void MakeEmpty (TabInt * T){
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
	//Kamus 
	int i;
	//Algoritma MakeEmpty
	Neff(*T) = 0;
}

int NbElmt (TabInt T){
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
	//Algoritma NbElmt
	return Neff(T);
}

int MaxNbEl (TabInt T){
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
	//Algoritma MaxNbEl
	return (IdxMax-IdxMin+1);	
}

IdxType GetFirstIdx (TabInt T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
	//Algoritma GetFirstIdx
	return IdxMin;
}

IdxType GetLastIdx (TabInt T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
	//Algoritma GetLastIdx
	return IdxMin + Neff (T)-1;
}

boolean IsIdxValid (TabInt T, IdxType i){
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
	//Algoritma IsIdxValid
	if ((i <=IdxMax) && (i>=IdxMin)) {
		return true;
	} else {
		return false;
	}
}

boolean IsIdxEff (TabInt T, IdxType i){
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
	//Algoritma IsIdxEff
	if ((i <= GetLastIdx(T)) && (i >=GetFirstIdx(T))) {
		return true;
	} else {
		return false;
	}
}

boolean IsEmpty (TabInt T){
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
	//Algoritma IsEmpty
	if (NbElmt (T) == 0 ){
		return true;
	} else {
		return false;
	}
}

boolean IsFull (TabInt T){
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
	//Algoritma IsFull
	if (NbElmt (T) == IdxMax-IdxMin+1 ){
		return true;
	} else {
		return false;
	}
}

void BacaIsi (TabInt * T){
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
	//Kamus
	int N,i,j;
	//Algoritma BacaIsi	
	scanf ("%d",&N);
	while (N<0 || N>MaxNbEl(*T)) {
		scanf ("%d",&N);
	}
	Neff (*T) = 0;
	if (N>0) {
		j=IdxMin;
		for (i=1;i<=N;i++) {
			scanf ("%d", &Elmt(*T,j));
			j++;
			Neff (*T) ++;
		}
	}
}

void BacaIsiTab (TabInt * T){
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca elemen T sampai dimasukkan nilai -9999 */
	//Kamus
	int i,x;
	//Algoritma BacaIsiTab
	i = IdxMin;
	Neff (*T) = 0;
	scanf ("%d",&x);
	while ((x!= -9999) && (GetLastIdx (*T) < IdxMax )){
		Elmt(*T,i) = x;
		i++;
		Neff (*T) ++;
		scanf ("%d",&x);
	}
}

void TulisIsi (TabInt T){
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/*      Jika T kosong : Hanya menulis "Tabel kosong" */
	//Kamus
	int i;
	//Algoritma TulisIsi
	if (!(IsEmpty (T))) {
		for (i=1;i<=Neff(T);i++){
			printf ("[%d]%d\n",i, Elmt(T,i));
		}
	} else {
		printf ("Tabel kosong\n");
	}
}


void TulisIsiTab (TabInt T){
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku; 
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
	//Kamus
	int i;
	//Algoritma
	if (!(IsEmpty(T))) {
		printf ("[");
		for (i=1;i<Neff(T);i++) {
			printf ("%d,", Elmt(T,i));
		}
		printf ("%d]",Elmt (T,GetLastIdx(T)));
	} else {
	printf ("[]");
	}
}


TabInt PlusTab (TabInt T1, TabInt T2){
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
	//Kamus
	TabInt T;
	int i;
	//Algoritma
	Neff (T) = Neff (T1);
	for (i=1; i<=Neff(T1); i++) {
		Elmt (T,i) = Elmt (T1,i) + Elmt(T2,i);
	}
	return T;
}

TabInt MinusTab (TabInt T1, TabInt T2){
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
	//Kamus
	TabInt T;
	int i;
	//Algoritma
	Neff (T) = Neff (T1);
	for (i=1; i<=Neff(T1); i++) {
		Elmt (T,i) = Elmt (T1,i) - Elmt(T2,i);
	}
	return T;
}

TabInt KaliTab (TabInt T1, TabInt T2){
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 * T2 dengan definisi setiap elemen dengan indeks yang sama dikalikan */
	//Kamus
	TabInt T;
	int i;
	//Algoritma
	Neff (T) = Neff (T1);
	for (i=1; i<=Neff(T1); i++) {
		Elmt (T,i) = Elmt (T1,i) * Elmt(T2,i);
	}
	return T;
}

TabInt KaliKons (TabInt Tin, ElType c){
/* Prekondisi : Tin tidak kosong */
/* Mengirimkan tabel dengan setiap elemen Tin dikalikan c */
	//Kamus
	TabInt T;
	int i;
	//Algoritma
	Neff (T) = Neff (Tin);
	for (i=1; i<=Neff(Tin); i++) {
		Elmt (T,i) = Elmt (Tin,i) * c;
	}
	return T;
}

boolean IsEQ (TabInt T1, TabInt T2){
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */
	//Kamus
	boolean cek;
	int i;
	//Algoritma
	cek = true;
	if (Neff(T1) != Neff (T2)){
		cek = false;
	} else {
		for (i=1; i<=Neff (T1); i++) {
			if (Elmt (T1,i) != Elmt (T2,i)) {
				cek = false;
			}
		}
	}
	return cek;
}

boolean IsLess (TabInt T1, TabInt T2){
/* Mengirimkan true jika T1 < T2, */
/* yaitu : sesuai dg analogi 'Ali' < Badu'; maka [0, 1] < [2, 3] */
	//Kamus
	int i;
	//Algoritma
	if(IsEQ(T1,T2)){
		return false;
	}
	else{
		for(i = IdxMin;(i<= Neff(T1));i++){
			if(Elmt(T1,i)>Elmt(T2,i)){
				return false;
			}
			else if (Elmt(T1,i) < Elmt(T2,i)){
				return true;
			}
		}
	}
	if (Neff(T1)>Neff(T2)){
		return false;
	}
	return true;
}

IdxType Search1 (TabInt T, ElType X){
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Memakai skema s earch TANPA boolean */
	//Kamus
	IdxType k;
	int i;
	//Algoritma
	k = IdxUndef;
	i = IdxMin;
	while ((k== IdxUndef) && (i<=GetLastIdx(T))) {
		if (Elmt (T,i) == X) {
			k = i;
		} else {
			i++;
		}
	}
	return k;
}

IdxType Search2 (TabInt T, ElType X){
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search DENGAN boolean Found */
	//Kamus
	boolean found;
	int i;
	IdxType k;
	//Algoritma
	found = false;
	i = IdxMin;
	k = IdxUndef;
	while ((found == false) && (i<=GetLastIdx(T))) {
		if (Elmt(T,i) == X ) {
			found = true;
			k = i;
		} else {
			i++;
		}
	}
	return k;
}

boolean SearchB (TabInt T, ElType X){
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Memakai Skema search DENGAN boolean */
		//Kamus
	boolean found;
	int i;
	//Algoritma
	found = false;
	i = IdxMin;
	while ((found == false) && (i<=GetLastIdx(T))) {
		if (Elmt(T,i) == X) {
			found = true;
		} else {
			i++;
		}
	}
	return found;
}

boolean SearchSentinel (TabInt T, ElType X){
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* dengan metoda sequential search dengan sentinel */
	//Kamus
	int i,k;
	boolean found;
	//Algoritma
	Elmt (T,0) = X;
	found = false;
	i = GetLastIdx(T);
	while (found == false) {
		if (Elmt (T,i) == Elmt(T,0)) {
			found = true;
		} else {
			i--;
		}
	}
	if (i==0) {
		found = false;
	}
	return found;
}

ElType ValMax (TabInt T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */
	//Kamus 
	int i;
	ElType max;
	//Algoritma
	max = Elmt (T,GetFirstIdx(T));
	for (i=1;i<=GetLastIdx(T);i++) {
		if (Elmt (T,i) > max) {
			max = Elmt(T,i);
		}
	}
	return max;
}

ElType ValMin (TabInt T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum tabel */
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */
	//Kamus 
	int i;
	ElType min;
	//Algoritma
	min = Elmt (T,GetFirstIdx(T));
	for (i=1;i<=GetLastIdx(T);i++) {
		if (Elmt (T,i) < min) {
			min = Elmt(T,i);
		}
	}
	return min;
}

IdxType IdxMaxTab (TabInt T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai maksimum pada tabel */
	//Algoritma
	return Search2 (T,ValMax(T));
}

IdxType IdxMinTab (TabInt T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai minimum pada tabel */
	//Algoritma
	return Search2 (T,ValMin (T));
}

void CopyTab (TabInt Tin, TabInt * Tout){
/* I.S. Tin terdefinisi, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik) */
/* Proses : Menyalin isi Tin ke Tout */
	//Kamus
	int i;
	//Algoritma
	MakeEmpty(Tout);
	for (i=GetFirstIdx (Tin); i<= GetLastIdx (Tin); i++) {
		Elmt (*Tout,i) = Elmt (Tin,i);
	}
	Neff (*Tout) = Neff (Tin);
}

TabInt InverseTab (TabInt T) {
/* Menghasilkan tabel dengan urutan tempat yang terbalik, yaitu : */
/* elemen pertama menjadi terakhir, */
/* elemen kedua menjadi elemen sebelum terakhir, dst.. */
/* Tabel kosong menghasilkan tabel kosong */
	//Kamus
	TabInt Tout;
	int i,j;
	//Algoritma
	j=1;
	for (i=GetLastIdx(T); i>=GetFirstIdx(T); i--) {
		Elmt (Tout,j) = Elmt (T,i);
		j++;
		Neff(Tout)++;
	}
	return Tout;
}

boolean IsSimetris (TabInt T){
/* Menghasilkan true jika tabel simetrik */
/* Tabel disebut simetrik jika: */
/*      elemen pertama = elemen terakhir, */
/*      elemen kedua = elemen sebelum terakhir, dan seterusnya */
/* Tabel kosong adalah tabel simetris */
	int i,j;
	boolean simetris;
	//Algoritma
	if (IsEmpty(T)) {
		return true;
	} else {
		simetris = true;
		i = GetFirstIdx (T);
		j = GetLastIdx (T);
		while ((j > i ) && simetris) {
			if (Elmt (T,j) != Elmt (T,i)) {
				simetris = false;
			} else {
				i++;
				j--;
			}
		}
		return simetris;
	}
}

void MaxSortDesc (TabInt * T){
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menurun dengan Maximum Sort */
/* Proses : mengurutkan T sehingga elemennya menurun/mengecil */
/*          tanpa menggunakan tabel kerja */
	//Kamus
	ElType max, idxmax;
	int temp,i,j;
	//Algoritma
	max = ValMax (*T);
	idxmax = Search2 (*T,max);
	if (idxmax != 1) {
		temp= Elmt (*T,1);
		Elmt(*T,1) = max;
		Elmt (*T,idxmax) = temp;
	}
	for (i=2; i <=GetLastIdx(*T); i++) {
		j=i;
		while (Elmt (*T,j) > Elmt (*T,j-1)) {
			temp = Elmt (*T,j);
			Elmt (*T,j) = Elmt (*T,j-1);
			Elmt (*T,j-1) = temp;
			j--;
		}
	}
}

void InsSortAsc (TabInt * T){
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menaik dengan Insertion Sort */
/* Proses : mengurutkan T sehingga elemennya menaik/membesar */
/*          tanpa menggunakan tabel kerja */
	//Kamus
	ElType min, idxmin;
	int temp,i,j;
	//Algoritma
	min = ValMin (*T);
	idxmin = Search2 (*T,min);
	if (idxmin != 1) {
		temp= Elmt (*T,1);
		Elmt(*T,1) = min;
		Elmt (*T,idxmin ) = temp;
	}
	for (i=2; i <=GetLastIdx(*T); i++) {
		j=i;
		while (Elmt (*T,j) < Elmt (*T,j-1)) {
			temp = Elmt (*T,j);
			Elmt (*T,j) = Elmt (*T,j-1);
			Elmt (*T,j-1) = temp;
			j--;
		}
	}
}

void AddAsLastEl (TabInt * T, ElType X){
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
	//Algoritma
	Elmt (*T, GetLastIdx(*T)+1) = X;
	Neff (*T) += 1;
}

void AddEli (TabInt * T, ElType X, IdxType i){
/* Menambahkan X sebagai elemen ke-i tabel tanpa mengganggu kontiguitas 
   terhadap elemen yang sudah ada */
/* I.S. Tabel tidak kosong dan tidak penuh */
/*      i adalah indeks yang valid. */
/* F.S. X adalah elemen ke-i T yang baru */
/* Proses : Geser elemen ke-i+1 s.d. terakhir */
/*          Isi elemen ke-i dengan X */
	//Kamus
	int j;
	//Algoritma
	for (j=GetLastIdx(*T); j >=i;j--) {
		Elmt (*T,j+1) = Elmt (*T,j);
	}
	Elmt (*T,i) = X;
	Neff (*T) += 1;
}

void DelLastEl (TabInt * T, ElType * X){
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
	//Algoritma
	*X = Elmt (*T, GetLastIdx(*T));
	Elmt (*T, GetLastIdx(*T)) = IdxUndef;
	Neff (*T) -=1;
}

void DelEli (TabInt * T, IdxType i, ElType * X){
/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
/*          Kurangi elemen efektif tabel */
	//Kamus

	//Algoritma
	*X = Elmt (*T,i);
	while (i < GetLastIdx (*T)) {
		Elmt (*T,i) = Elmt (*T,i+1);
		i++;
	}
	Elmt (*T,GetLastIdx(*T)) = IdxUndef;
	Neff (*T) -= 1;
}

void AddElUnik (TabInt * T, ElType X) {
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/*      dan semua elemennya bernilai unik, tidak terurut */
/* F.S. Jika tabel belum penuh, menambahkan X sbg elemen terakhir T, 
        jika belum ada elemen yang bernilai X. 
		Jika sudah ada elemen tabel yang bernilai X maka I.S. = F.S. 
		dan dituliskan pesan "nilai sudah ada" */
/* Proses : Cek keunikan dengan sequential search dengan sentinel */
/*          Kemudian tambahkan elemen jika belum ada */
	//Algoritma 
	if (SearchSentinel (*T,X) == true) {
		printf ("nilai sudah ada\n");
	} else {
		Elmt (*T,GetLastIdx(*T)+1) = X;
		Neff (*T) += 1;
	}
}

IdxType SearchUrut (TabInt T, ElType X) {
/* Prekondisi: Tabel T boleh kosong. Jika tidak kosong, elemen terurut membesar. */
/* Mengirimkan indeks di mana harga X dengan indeks terkecil diketemukan */
/* Mengirimkan IdxUndef jika tidak ada elemen tabel bernilai X */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel kosong */
	//Algoritma
	return Search2 (T,X);
}

ElType MaxUrut (TabInt T){
/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai maksimum pada tabel */
	//Algoritma
	return Elmt (T,GetLastIdx(T));
}

ElType MinUrut (TabInt T){
/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai minimum pada tabel*/
	//Algoritma
	return Elmt (T,GetFirstIdx(T));
}

void MaxMinUrut (TabInt T, ElType * Max, ElType * Min){
/* I.S. Tabel T tidak kosong, elemen terurut membesar */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
	*Max = ValMax (T);
	*Min = ValMin (T);
}

void Add1Urut (TabInt * T, ElType X){
/* Menambahkan X tanpa mengganggu keterurutan nilai dalam tabel */
/* Nilai dalam tabel tidak harus unik. */
/* I.S. Tabel T boleh kosong, boleh penuh. */
/*      Jika tabel isi, elemennya terurut membesar. */
/* F.S. Jika tabel belum penuh, menambahkan X. */
/*      Jika tabel penuh, maka tabel tetap. */
/* Proses : Search tempat yang tepat sambil geser */
/*          Insert X pada tempat yang tepat tersebut tanpa mengganggu keterurutan */
	//Kamus 
	int i,j,temp;
	//Algoritma
	if (Neff (*T) == 0) {
		Elmt (*T,1)= X;
		Neff (*T) += 1;
	} else 
	if (Neff (*T) < IdxMax) {
		i=IdxMin;
		while ((X > Elmt (*T,i)) && (i <= GetLastIdx(*T))) {
			i++;
		}
		if (i <= GetLastIdx (*T)) {
			for (j=GetLastIdx(*T); j >=i; j--) {
				Elmt (*T,j+1) = Elmt (*T,j);
			}
			Elmt (*T,i) = X;
			Neff (*T)++;
		} else {
			Elmt (*T,i) = X;
			Neff (*T)++;
		}
	}
}

void Del1Urut (TabInt * T, ElType X){
/* Menghapus X yang pertama kali (pada indeks terkecil) yang ditemukan */
/* I.S. Tabel tidak kosong */
/* F.S. Jika ada elemen tabel bernilai X , */
/*      maka banyaknya elemen tabel berkurang satu. */
/*      Jika tidak ada yang bernilai X, tabel tetap. */
/*      Setelah penghapusan, elemen tabel tetap kontigu! */
/* Proses : Search indeks ke-i dengan elemen ke-i = X. */
/*          Delete jika ada. */
	//Kamus
	int i;
	//Algoritma
	if (SearchB (*T,X) == true ){
		for (i = Search2 (*T,X); i<GetLastIdx(*T);i++) {
			Elmt (*T,i) = Elmt (*T,i+1);
		}
		Neff (*T)--;
	}
}