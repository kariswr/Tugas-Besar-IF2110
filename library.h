#ifndef _LIBRARY_H
#define _LIBRARY_H

/*
---------- DAFTAR ADT YANG DAPAT DIGUNAKAN ----------
typedef struct {
    int X;
    int Y;
} Point;
typedef struct { 
	infotype T[100];
	int Neff;
} ArrInfotype;
typedef struct { 
	infotype T[100][100];
    int NBrsEff;
	int NKolEff;
} MatriksInfotype;
typedef struct {
    infotype * T;
    int HEAD;
    int TAIL;
    int MaxEl;
} QueueInfotype;
typedef struct { 
	infotype T[100];
	int TOP;
} StackInfotype;
typedef struct tElmtlist *address;
typedef struct tElmtlist { 
	infotype info;
	address next;
} ElmtListInfotype;
typedef struct {
	address First;
} ListInfotype;
-----------TREE--------------
typedef struct tNode *address;
typedef struct tNode {
	infotype info;
	address left;
	address right;
} Node;
typedef address BinTree;
-------MESIN KARAKTER-------
typedef struct {
	char TabKata[NMax + 1];
	int Length;
} Kata;
#define MARK '/'
#define NMax 50
#define BLANK ' '
#define ENTER '\n'

extern char CC;
extern boolean EOP;

extern boolean EndKata;
extern Kata CKata;

JAM?
MULTILIST?
GRAPH?
*/

/*---------- BOOLEAN ----------*/
#define boolean unsigned char
#define true 1
#define false 0

/*---------- POINT ----------*/
typedef struct {
    /* i = Y
    ** j = X */
    int i;
    int j;
} Point;

/*---------- QUEUE CUSTOMER ----------*/
#define InitialPatience 30
#define AddPatience 60
#define MaxQueue 5
typedef struct {
 	/* Star		: apakah CUSTOMER tersebut VIP
	** Persons	: jumlah orang per tamu
	** Patience	: LEVEL kesabaran tamu, saat ngantri, 30, setelah dapat duduk, +60
	** TableIndex	: no MEJA setelah duduk, NOL(0) jika masih dalam ANTRIAN */
	boolean Star;
	int Persons;
	int Patience;
} Customer;

typedef struct {
	/* T		: QUEUE Customer
	** HEAD		: yang akan keluar dahulu
	** TAIL 	: yang masuk terakhir
	** NBQueue	: jumlah antrian */
	Customer *T;
	int HEAD;
	int TAIL;
	int MaxEl;
	} Queue;


/*---------- ARRAY TABLE ----------*/
typedef struct {
	/* Capacity 	: maksimum orang tiap meja, 2 atau 4
	** Room 		: nomor ruang
	** Position 	: koordinat meja
	** Occupied 	: apakah sudah diduduki
	** Customer		: data customer yang menduduki meja */
	int Capacity;
	int Room;
	Point Position;
	boolean Occupied;
	Customer Cust;
} Table;

#define NTable 12

typedef struct { 
	/* termasuk semua Room; indeks 1 sampai 12*/
	Table T[NTable+1];
	int Neff;
} ArrTable;

/*---------- ARRAY COUNTER ----------*/
typedef struct {
	/* Position 	: koordinat counter
	** Code		 	: foodcode*/
	Point Position;
	char  Code;
} Counter;

#define NCounter 16

typedef struct { 
	/* semua berada pada room 0; indeks 1 sampai 16*/
	Counter T[NCounter+1];
	int Neff;
} ArrCounter;

/*---------- MATRIKS PETA ----------*/

#define M 8
#define N 8

typedef struct { 
		/* Akses array 1..8 */
	char T[M+1][N+1][3];
	int NBrsEff;
	int NKolEff;
} MapMatrix;

/*LEGENDA
-- : grid kosong
mm : Counter; m = IngredientKey
TT : Food Tray
XX : kursi kosong (bisa menjadi CC)
CC : kursi terisi (bisa menjadi XX)
NN : indeks Table
PP : Player (posisi player berubah-ubah)
DD : Door
N.B. Simbol berupa array of char karena indeks Table harus dua digit.*/

/*---------- STACK HAND & TRAY ----------*/
#define MaxStack 5

typedef struct {
	/* indeks dimulai dari 1..MaxStack 
	** indek TOP stack */
	char T[MaxStack+1];
	int TOP;
} Stack;
/* a..o = bahan
** p..w = makanan */

/*-----------FOOD TREE-------------*/
typedef struct tNode *addressNode;
typedef struct tNode {
	/*info		:nilai elemen node (kunci karakter makanan, p sampai w)
	** left		: cabang kiri
	** right	: cabang kanan */
	char info;
	addressNode left;
	addressNode right;
} Node;

typedef addressNode FoodTree;

/*---------- ARRAY KONVERSI MAKANAN ----------*/
/*digunakan untuk menampilkan nama bahan makanan atau
nama makanan jadi sesuai dengan code char*/

#define MaxFood 24

typedef struct {
	/* FoodCode		: kata kunci bahan makanan atau makanan(a..w)
	** FoodName		: nama bahan makanan atau makanan 
	** FoodLength	: panjang karakter foodname*/
	char FoodCode;
	char FoodName[20];
	int FoodLength;
} Food;

typedef struct { 
	/* Array of Food	: Konversi kode ke nama makanan
	** Neff				: Banyaknya jenis bahan makanan atau makanan jadi */
	Food T[MaxFood+1];
	int Neff;
} ArrFood;

/*---------- ARRAY ORDER ----------*/
#define MaxOrder 5

typedef struct {
	/* DishKey		: kata kunci makanan
	** TableIndex	: no meja yang memesan mknn */
	char DishKey;
	int TableIndex;
} Order;

typedef struct { 
	/* Array of Order	: Susunan Order
	** Neff				: Jumlah Order maks yang dapat diingat */
	Order T[MaxOrder+1];
	int Neff;
} ArrOrder;

/*---------- PLAYER ----------*/
typedef struct {
	/* Name 	: nama player, maks 20 karakter
	** Money	: uang player
	** Life		: "nyawa" player
	** Time 	: time ELAPSED sejak game dimulai
	** Room		: nomor ruangan player currently berada
	** Position : koordinat player di dalam ruang terkait */
	char * Name;
	int Money;
	int Life;
	int Time;
	int Room;
	Point Position;
} Player;

/*-------IO MACHINE-------*/
#define MARK '/'
#define NMax 50
#define BLANK ' '
#define ENTER '\n'
#define MaxUser 9

typedef struct {
	char TabKata[NMax + 1];
	int Length;
} Kata;

typedef struct {
	Kata UserThumb[MaxUser + 1];
	int Length;
} ArrThumb;

/*---------- SELEKTOR UNTUK ADT ----------*/
#define Absis(Point)   (Point).j
#define Ordinat(Point) (Point).i

#define Neff(Array)	(Array).Neff
#define T(Array)    (Array).T
#define ElmtA(Array,i) (Array).T[(i)]

#define NBrsEff(Matriks)	(Matriks).NBrsEff
#define NKolEff(Matriks)	(Matriks).NKolEff
#define ElmtM(Matriks,i,j) (Matriks).T[(i)][(j)]

#define Head(Queue)     (Queue).HEAD
#define Tail(Queue)     (Queue).TAIL
#define InfoHead(Queue) (Queue).T[(Queue).HEAD]
#define InfoTail(Queue) (Queue).T[(Queue).TAIL]
#define MaxEl(Queue)    (Queue).MaxEl

#define Top(Stack)     (Stack).TOP
#define InfoTop(Stack) (Stack).T[(Stack).TOP]

#define Info(Address) (Address)->info
#define Next(Address) (Address)->next
#define First(List)   (List).First

#define Akar(addressNode) (addressNode)->info
#define Left(addressNode) (addressNode)->left
#define Right(addressNode) (addressNode)->right

#endif
