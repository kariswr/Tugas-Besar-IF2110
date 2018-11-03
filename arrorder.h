#ifndef _ARRORDER_h
#define _ARRORDER_h

#include "library.h"

/*---------- ORDER ----------*/
/* Constructor */
void NewOrder (Order * O, int Idx);
// Generates a new order

/*---------- ARRAY OF ORDER ----------*/
/* Constructor */
void MakeEmpty (ArrOrder * AO);
// Creates an empty array of orders

/* Miscellaneous */
boolean IsEmpty (ArrOrder AO);
// Returns TRUE if OL is empty (Neff = 0)
boolean IsFull (ArrOrder AO);
// Returns TRUE if OL is full (Neff = MaxOrder)
int Search (ArrOrder AO, char DishKey, int TableIndex);
// Returns the index for the order, 0 if there is no such order

/* Add/Delete array elements */
void AddLast (ArrOrder * AO, Order O);
// Adds an order as the last element of the array
void DelX (ArrOrder * AO, int X, Order * O);
// Deletes X-th element of the array

/* Print array of order */
void PrintOrders (ArrOrder OA);
// Prints the contents of array as tuples of <"Dish", TableIndex>

#endif