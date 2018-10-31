#include "boolean.h"

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

JAM?
MESIN KARAKTER?
MESIN KATA?
MULTILIST?
GRAPH?

*/

/*---------- POINT ----------*/
typedef struct {
	int X;
	int Y;
} Point;


/*---------- ARRAY TABLE ----------*/
typedef struct {
	/* Capacity 	: maksimum orang tiap meja, 2 atau 4
	** Room 		: nomor ruang
	** Position 	: koordinat meja
	** Occupied 	: apakah sudah diduduki */
	int Capacity;
	int Room;
	Point Position;
	boolean Occupied;
} Table;

typedef struct {
	/* termasuk semua Room; indeks 1 sampai 12*/
	Table T[13];
	int Neff = 12;
} ArrTable;


/*---------- MATRIKS PETA ----------*/
typedef char symbol[2];

typedef struct {
	/* Akses array 1..8 */
	symbol T[9][9];
	int NBrsEff = 8;
	int NKolEff = 8;
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
typedef char FoodKey;		// karakter kunci bahan atau makanan jadi; a sampai w 

typedef struct tNode *addressNode;
typedef struct tNode {
	/* FoodKey	: value elemen pada NODE
	** left		: cabang kiri
	** right	: cabang kanan */
	char Info;
	address left;
	address right;
} Node;

typedef addressNode FoodTree;

/*---------- ARRAY ORDER ----------*/
#define MaxOrder 8

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
	int TableIndex;
} Customer;

typedef struct {
	/* T		: QUEUE Customer
	** HEAD		: yang akan keluar dahulu
	** TAIL 	: yang masuk terakhir
	** NBQueue	: jumlah antrian */
	Customer *T;
	int HEAD;
	int TAIL;
	int NBQueue;
} Queue;


/*---------- PLAYER ----------*/
#define MaxNameLength 20

typedef struct {
	/* Name 	: nama player, maks 20 karakter
	** Money	: uang player
	** Life		: "nyawa" player
	** Time 	: time ELAPSED sejak game dimulai
	** Room		: nomor ruangan player currently berada
	** Position : koordinat player di dalam ruang terkait */
	char Name[MaxNameLength];
	int Money;
	int Life;
	int Time;
	int Room;
	Point Position;
} Player;


/*---------- SELEKTOR UNTUK ADT ----------*/
#define Absis(Point)	(Point).X
#define Ordinat(Point)	(Point).Y

#define Neff(Array)	(Array).Neff
#define T(Array)	(Array).T
#define ElmtA(Array,i)	(Array).T[(i)]

#define NBrsEff(Matriks)	(Matriks).NBrsEff
#define NKolEff(Matriks)	(Matriks).NKolEff
#define ElmtM(Matriks,i,j)	(Matriks).T[(i)][(j)]

#define Head(Queue)		(Queue).HEAD
#define Tail(Queue)		(Queue).TAIL
#define InfoHead(Queue)	(Queue).T[(Queue).HEAD]
#define InfoTail(Queue)	(Queue).T[(Queue).TAIL]
#define MaxEl(Queue)	(Queue).MaxEl

#define Top(Stack)		(Stack).TOP
#define InfoTop(Stack)	(Stack).T[(Stack).TOP]

#define Info(Address)	(Address)->info
#define Next(Address)	(Address)->next
#define First(List)		(List).First

/******** PRIMITIF POINT ********/
Point Point_Create (int x, int y);
/** P1 == P2 (?) **/
boolean Point_Equal (Point P1, Point P2);

/** Menggeser Posisi **/
void Point_Translate (Point *P, int dx, int dy);

/******** PRIMITIF ARRAY TABLE ********/
/** Meja menjadi KOSONG, tanpa CUSTOMER **/
void Table_Reset (Table *T);

/** Membuat susunan Meja, kapasitas, dan posisi **/
void Tables_Create (ArrTable *ArrT);

/** TABLE sudah diduduki? **/
boolean Table_Occupied (Table *T);

/******** PRIMITIF PETA ********/
/** Menciptakan PETA dari START GAME **/
void Map_CreateSub (MapMatrix *MM);

/**** Termasuk UI ****/
/** Menampilkan Peta Kecil SATU RUANG **/
void Map_Show (MapMatrix MM);
/** Meng-update Peta Kecil elemen di dalam ruangan
*** berubah **/
void Map_Update (MapMatrix MM);

/******** PRIMITIF STACK HAND ********/
void Stack_CreateEmpty (Stack *St);
boolean Stack_IsEmpty (Stack St);
boolean Stack_IsFull (Stack St);
void Stack_Push (Stack *St, char Key);
void Stack_Pop (Stack *St, char *Key);

#endif