#ifndef _WAITINGCUST_h
#define _WAITINGCUST_h

#include "library.h"

/*---------- CUSTOMER ----------*/
// Konstruktor Customer
void NewCustomer (Customer * C);    // Menciptakan customer baru


/*---------- QUEUE ----------*/
// Uji Queue
boolean IsEmpty (Queue Q);  // Mengembalikan true jika Q kosong (Head = Tail = 0)
boolean IsFull (Queue Q);   // Mengembalikan true jika NBElmt = MaxEl

// Jumlah elemen Queue
int NBElmt (Queue Q);       // Mengembalikan Tail - Head + 1

// Konstruktor Queue
void CreateEmpty (Queue * Q, int Max);  // Membuat Q kosong dengan MaxEl = Max

// Tambah/Hapus Elemen Queue
void Add (Queue * Q, Customer C);           // Menambah elemen baru ke belakang Q
void SpecialAdd (Queue * Q, Customer C);    // Menambah elemen baru ke depan Q
void Del (Queue * Q, Customer * C);         // Menghapus elemen paling depan Q
void DelX (Queue * Q, int X, Customer * C); // Menghapus elemen ke-X

// Menentukan apa yang terjadi pada Queue setelah 1 tick
void LessPatient (Queue * Q);   // Mengurangi Patience semua Customer; menghapus Customer yang Patience = 0
void UpdateQueue (Queue * Q);   // LessPatient; menentukan adanya Customer baru

#endif