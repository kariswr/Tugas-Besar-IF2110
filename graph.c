#include "graph.h"
#include "library.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Nil NULL

void CreateGraph(infotypeG X, Graph *G){
	First(*G) = AlokNodeG(X);
}

addrNodeG AlokNodeG (infotypeG X){
	/*kamus lokal*/
	addrNodeG P;

	/*algoritma*/
	P =(addrNodeG) malloc (1*sizeof(NodeG));

	if (P != Nil)	{
		(Id(P)) = X;
		Next(P)=Nil;
		Trail(P)=Nil;
	}
	return P;
}

void DeAlokNodeG(addrNodeG P){
	free(P);
}

addrSuccNode AlokSuccNode (addrNodeG Pn){
	/*kamus lokal*/
	addrSuccNode P;

	/*algoritma*/
	P =(addrSuccNode) malloc (sizeof(SuccNode));

	if (P!=Nil){
		Succ(P) = Pn;
		Next(P) = Nil;
	}
	return P;
}

void DealokSuccNode (addrSuccNode P){
	free(P);
}

boolean FoundNode (Graph G, infotypeG X){
 	/*kamus lokal*/
	 addrNodeG P;
	 boolean found;

	 /*algoritma*/
	P = First(G);
	found = false;
	while(!found && (P != Nil)){
		if (Id(P) == X ){
			found = true;
		} else {
			P = Next(P);
		}
	}
	return found;
	}

addrNodeG SearchNode (Graph G, infotypeG X){
	/*kamus lokal*/
	addrNodeG P;
	boolean found;

	/*algoritma*/
	P = First(G);
	found = false;
	while(!found && (P != Nil)){
		if (Id(P) == X ){
			found = true;
		} else {
			P = Next(P);
		}
	}
	return P;
}

addrSuccNode SearchEdge (Graph G, infotypeG prec, infotypeG succ){
	/*kamus lokal*/
	addrNodeG P;
	addrSuccNode Pt;
	boolean found;

	/*algoritma*/
	P = SearchNode(G,prec);

	if (P!=Nil){
		Pt = Trail(P);
		found = false;
		while(!found && (Pt != Nil))
		{
			if(Id(Succ(Pt))==succ){
				found = true;
			} else {
				Pt = Next(Pt);
			}
		}
		return Pt;
	}
	else{
		return Nil;
	}
}

void InsertNode (Graph *G, infotypeG X, addrNodeG *Pn) {
	addrNodeG P;

	*Pn = AlokNodeG(X);
	if (*Pn!=Nil) {
		P = First(*G);
		while (Next(P)!=Nil){
			P=Next(P);
		}
		Next(P)=*Pn;
	}
}

void InsertEdge (Graph *G, infotypeG prec, infotypeG succ){
	addrNodeG Px,Py;
	addrSuccNode Pz,Pt;
	boolean found = false;
	Px = SearchNode(*G,prec);
	Py = SearchNode(*G,succ);
	
	//in case not found prec and succ
	if (Px == Nil) {
		InsertNode(G,prec,&Px);
	}
	
	if (Py==Nil) {
		InsertNode(G,succ,&Py);
	}
	//melihat apakah succ sudah terhubung dengan prec
	Pz=Trail(Px);
	while (Pz!=Nil && !found) {
		if(Id(Succ(Pz))==succ ) {
			found = true; //berarti uda terhubung
		} else {
			Pz = Next(Pz);
		}
	}
	if (!found)	{
		Pt=AlokSuccNode(Py);
		if (Pt!=Nil) {
			Next(Pt) = Trail(Px);
			Trail(Px)=Pt;
			NPred(Py)+=1;
		}
	}
}

void MakeGraph(Graph *G) {
	int x;
	addrNodeG adNode1, adNode2, adNode3,adNode4,adNode5,adNode6,adNode7;
	x =415;
	CreateGraph(x,G);
	InsertNode(G,185,&adNode1);
	InsertNode(G,158,&adNode2);
	InsertNode(G,221,&adNode3);
	InsertNode(G,285,&adNode4);
	InsertNode(G,315,&adNode5);
	InsertNode(G,321,&adNode6);
	InsertNode(G,458,&adNode7);


	InsertEdge(G,185,415);
	InsertEdge(G,158,221);
	InsertEdge(G,221,158);
	InsertEdge(G,285,315);
	InsertEdge(G,315,285);
	InsertEdge(G,321,458);
	InsertEdge(G,458,321);
	InsertEdge(G,415,185);

}



// int main(){
// 	Graph G;
// 	infotypeG X;
// 	X.idxruangan = 1;
// 	X.Pintu = MakePOINT(3,3);
// 	strcpy(X.cmd,"GU");
// 	CreateGraph(X,&G);
// 	printf("isi graph:\nidxruangan: %d\nPintu:%d %d \ncmd:%s",X.idxruangan,Absis(X.Pintu),Ordinat(X.Pintu),X.cmd);
// }
