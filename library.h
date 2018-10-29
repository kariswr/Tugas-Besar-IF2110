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

typedef struct { 
	Table T[13];    // array Table dari semua Room; indeks 1 sampai MaxTable
	int Neff = 12;  // jumlah Table
} ArrTable;


/*---------- MATRIKS PETA ----------*/
#define N 8
#define M 8

typedef char simbol[2];

typedef struct { 
	simbol T[N+1][M+1]; // peta berupa matriks simbol; lihat legenda di bawah
    int NBrsEff = N;    // ukuran vertikal peta
	int NKolEff = M;    // ukuran horizontal peta
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

/*---------- STACK HAND ----------*/
#define MaxHand 5

typedef char IngredientKey;     // karakter kunci bahan; a sampai o

typedef struct { 
	IngredientKey T[MaxHand+1]; // stack Ingredient(Key) yang ada pada Hand; indeks 1 sampai MaxHand
	int TOP;                    // indeks TOP stack
} StackHand;


/*---------- STACK TRAY ----------*/
#define MaxTray 5

typedef char DishKey;       // karakter kunci makanan; p sampai w

typedef struct {
	DishKey T[MaxTray+1];   // stack Dish(Key) yang ada pada Tray; indeks 1 sampai MaxTray
	int TOP;                // indeks TOP stack
} StackTray;

/*-----------FOOD TREE-------------*/
typedef char FoodKey;		// karakter kunci bahan atau makanan jadi; a sampai w 

typedef struct tNode *address;
typedef struct tNode {
	FoodKey info;		//nilai elemen node
	address left;		//address cabang kiri
	address right;		//address cabang kanan
} Node;

typedef address FoodTree;

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
#define MaxQueue 5

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
    int MaxEl = MaxQueue;   // jumlah Customer pada queue
} QueueCustomer;


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


/*---------- SELEKTOR UNTUK ADT ----------*/
#define Absis(Point)   (Point).X
#define Ordinat(Point) (Point).Y

#define Neff(Array)   (Array).Neff
#define T(Array)    (Array).T
#define ElmtA(Array,i) (Array).T[(i)]

#define NBrsEff(Matriks)  (Matriks).NBrsEff
#define NKolEff(Matriks)  (Matriks).NKolEff
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

#endif
