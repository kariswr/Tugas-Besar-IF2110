
#include <stdio.h>
#include "library.h"
#include <string.h>
#include "waitingcust.h"
#include "arrorder.h"
#include "arrtable.h"
#include "handtray.h"
#include "foodconversion.h"

#define gotoxy(x,y) printf("\033[%d;%dH", (x), (y))
#define cls() printf("\033[H\033[J")

void RoomLayout ();
/*Prosedur akan menampilkan Layout tabel ruangan tanpa isinya*/

void ClearRoomLayout ();
/*Prosedur akan membuat Layout yang ditampilkan menjadi layout tabel ruangan  tanapa isinya*/

void UpdateRoomLayout (Player P, Queue Q, ArrOrder Order, MapMatrix R, ArrTable AT,Stack Tray, Stack Hand,ArrFood F);
/*Prosedur akan menampilkan ruangan tabel layout dengan isi nya*/

void UpdateKitchen (Player P, Queue Q, ArrOrder Order, MapMatrix R,Stack Tray, Stack Hand,ArrFood F);
/*Prosedur akan menampilkan ruangan Kitchen beserta dengan isinya*/