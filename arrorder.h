#ifndef _ARRORDER_h
#define _ARRORDER_h

#include "library.h"

/*---------- ORDER ----------*/
/* Constructor */
void NewOrder (Order * O, int Idx);
// Generates a new order

/*---------- ARRAY OF ORDER ----------*/
/* Constructor */
void MakeEmptyAO (ArrOrder * AO);
// Creates an empty array of orders

/* Miscellaneous */
boolean IsAOEmpty (ArrOrder AO);
// Returns TRUE if OL is empty (Neff = 0)
boolean IsAOFull (ArrOrder AO);
// Returns TRUE if OL is full (Neff = MaxOrder)
int SearchAO (ArrOrder AO, char DishKey, int TableIndex);
// Returns the index for the order, 0 if there is no such order
boolean HasOrdered (ArrOrder AO, int TableIndex);
// Returns TRUE if a Table has ordered

/* Add/Delete array elements */
void AddLastAO (ArrOrder * AO, Order O);
// Adds an order as the last element of the array
void DelXAO (ArrOrder * AO, int X, Order * O);
// Deletes X-th element of the array

/* Print array of order */
void PrintAO (ArrOrder AO);
// Prints the contents of array as tuples of <"Dish", TableIndex>

/* Debugging */
void PrintAOWithIndex (ArrOrder AO);
// Prints the index, and the contents of array as tuples

#endif