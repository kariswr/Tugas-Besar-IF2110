#ifndef GRAPH_H
#define GRAPH_H

#include "listlinier.h"
#include "library.h"
#include <string.h>


typedef struct gNode *addrNodeG;
typedef struct gSuccNode *addrSuccNode;
typedef int infotypeG;
typedef struct gNode {
	infotypeG Id;
	int NPred;
	addrSuccNode Trail;
	addrNodeG next;
} NodeG;
typedef struct gSuccNode {
	addrNodeG Succ;
	addrSuccNode next;
} SuccNode;
typedef struct {
	addrNodeG First;
} Graph;

#define Id(Pn) Pn->Id 
#define NPred(Pn) Pn->NPred
#define Trail(Pn) Pn->Trail
#define Succ(Pt) Pt->Succ

void CreateGraph(infotypeG X, Graph *G);
addrNodeG AlokNodeG (infotypeG X);
void DealokNodeG(addrNodeG P);
addrSuccNode AlokSuccNode (addrNodeG Pn);
void DealokSuccNode (addrSuccNode P);
boolean FoundNode (Graph G, infotypeG X);
addrNodeG SearchNode (Graph G, infotypeG X);
addrSuccNode SearchEdge (Graph G, infotypeG prec, infotypeG succ);
void InsertNode (Graph *G, infotypeG X, addrNodeG *Pn);
void InsertEdge (Graph *G, infotypeG prec, infotypeG succ);
void MakeGraph(Graph *G);


#endif
