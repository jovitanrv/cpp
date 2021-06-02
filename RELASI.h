#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED
#include "BUKU.h"
#include "PENULIS.h"

typedef struct elmlistR *addressR;

struct elmlistR{
    addressR next;
    addressR prev;
    addressB parent;
    addressP child;
};

struct ListR {
    addressR first;
    addressR last;
};

addressR alokasiR(addressB x, addressP y);
void dealokasiR(addressR P);
addressR findElm_RB(ListR L, addressB x);
addressR findElm_RP(ListR L, addressP y);
void createListR(ListR &L);
void insertLastR(ListR &L, addressR P);
void delDataR(ListR &L, addressR &P);
void delete_relasiB(ListR &L, infotypeB x);
void delete_relasiP(ListR &L, infotypeP x);
void statusP(ListR &R);

#endif // RELASI_H_INCLUDED
