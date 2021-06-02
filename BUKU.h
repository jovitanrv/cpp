#ifndef BUKU_H_INCLUDED
#define BUKU_H_INCLUDED

#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

#define next(P) P->next
#define prev(P) P->prev
#define parent(P) P->parent
#define child(P) P->child
#define info(P) P->info
#define first(L) L.first
#define last(L) L.last

struct infotypeB {
    int kode;
    string namab,jumhal,tahter;
};

typedef struct elmlistB *addressB;

struct elmlistB{
    infotypeB info;
    addressB next;
};

struct ListB {
    addressB first;
};

addressB alokasiB(infotypeB x);
void dealokasiB(addressB P);
addressB findElmB(ListB L, infotypeB x);
void createListB(ListB &L);
void insertLastB(ListB &L, addressB P);
void insertSort(ListB &L, addressB P);
void deleteFirstB(ListB &L, addressB &P);
void deleteLastB(ListB &L, addressB &P);
void deleteAfterB(ListB &L, addressB &P);
void deleteDataB(ListB &L, addressB &P);
void printInfoB(ListB  L);
void insertInfoB(infotypeB &x);

#endif // BUKU_H_INCLUDED
