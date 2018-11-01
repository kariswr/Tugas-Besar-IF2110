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
#define MARK '.'
// State Mesin 
extern char CC;
extern boolean EOP;

JAM?
MESIN KATA?
MULTILIST?
GRAPH?

*/

#define boolean unsigned char
#define true 1
#define false 0

/*---------- POINT ----------*/
typedef struct {
    int X;
    int Y;
} Point;


/*---------- ARRAY TABLE ----------*/
typedef struct {
    int Capacity;       // kapasitas Table; bisa 2 atau 4
    int Room;           // Room letak Table; 1 sampai 3
    Point Position;     // posisi Table pada MatriksPeta Room
    boolean Occupied;   // Table terisi
} Table;

#define NeffTable 12 	//jumlah Table
typedef struct { 
	Table T[NeffTable+1];    // array Table dari semua Room; indeks 1 sampai MaxTable
} ArrTable;


/*---------- MATRIKS PETA ----------*/

typedef char simbol[2];

#define NBrsEffPeta 8		// ukuran vertikal peta
#define NKolEffPeta 8		// ukuran horizontal peta
typedef struct { 
    simbol T[NBrsEffPeta+1][NKolEffPeta+1];     // peta berupa matriks simbol; lihat legenda di bawah
} MatriksPeta;

// LEGENDA
// -- : grid kosong
// mm : Counter; m = IngredientKey
// TT : Food Tray
// XX : kursi kosong (bisa menjadi CC)
// CC : kursi terisi (bisa menjadi XX)
// NN : indeks Table
// PP : Player (posisi player berubah-ubah)
// DD : Door

// N.B. Simbol berupa array of char karena indeks Table harus dua digit.

/*---------- STACK HAND DAN TRAY ----------*/
#define MaxStack 5

typedef struct {
	char T[MaxStack+1];     // stack makanan/bahan; indeks 1 sampai MaxStack
	int TOP;                // indeks TOP stack
} Stack;

// a sampai o = bahan
// p sampai w = makanan

/*-----------FOOD TREE-------------*/
typedef struct tNode *addressNode;
typedef struct tNode {
	char info;		// nilai elemen node (kunci karakter makanan, p sampai w)
	addressNode left;	// address cabang kiri
	addressNode right;	// address cabang kanan
} Node;

typedef addressNode FoodTree;

/*---------- ARRAY ORDER ----------*/
#define MaxOrder 8

typedef struct {
    char DishKey;   // karakter kunci makanan
    int TableIndex; // indeks Table yang memesan makanan
} Order;

typedef struct { 
	Order T[MaxOrder+1];    // array Order; indeks 1 sampai MaxOrder
	int Neff;               // jumlah Order
} ArrOrder;


/*---------- QUEUE CUSTOMER ----------*/
#define InitialPatience 30
#define AddPatience 60
#define MaxQueue 5			// jumlah Customer pada queue

typedef struct {
    boolean Star;   // Customer adalah Star Customer
    int Persons;    // jumlah orang
    int Patience;   // tingkat kesabaran; saat muncul di WaitList 30, setelah duduk ditambah 60
    int TableIndex; // indeks Table setelah Customer duduk
} Customer;

typedef struct {
    Customer * T;           // queue Customer; indeks 1 sampai MaxQueue
    int HEAD;               // indeks HEAD queue
    int TAIL;               // indeks TAIL queue
} Queue;


/*---------- PLAYER ----------*/
#define MaxNameLength 20

typedef struct {
    char Name[MaxNameLength];   // string nama Player
    int Money;                  // jumlah uang Player
    int Life;                   // jumlah nyawa Player
    int Time;                   // waktu berjalan permainan
    int Room;                   // Room letak Player
    Point Position;             // koordinat letak Player pada MatriksPeta Room
} Player;

/*-------MESIN KARAKTER-------*/
/*Silakan modifikasi procedure START pada ADT mesinkar bergantung pada nama file txt*/
/*Contoh: procedure STARTTREE untuk membaca file foodtree*/

#define MARK '.'
/* State Mesin */
extern char CC;
extern boolean EOP;

/*---------- SELEKTOR UNTUK ADT ----------*/
#define Absis(Point)   (Point).X
#define Ordinat(Point) (Point).Y

#define T(Array)    (Array).T
#define ElmtA(Array,i) (Array).T[(i)]

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
