#ifndef _printResep_h
#define _printResep_h

#include <stdio.h>
#include "library.h"
#include "foodtree.h"

void PrintRecipe (FoodTree P, ArrFood F);
/* P merukapan pohon Biner, dan F merupakan Array yang berisi data makanana */
/*Prosedur akan menampilkan Recipe yang didapat dari FoodTree, dengan ArrFood sebagai 'translator' agar char FoodTree menjadi nama barang
yang dimaksud*/

#endif