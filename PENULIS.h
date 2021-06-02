#ifndef PENULIS_H_INCLUDED
#define PENULIS_H_INCLUDED

#include <string>
#include "BUKU.h"

struct infotypeP {
    int umur, kope, jumbuk;
    string nama;
};

typedef struct elmlistP *addressP;

struct elmlistP{
    infotypeP info;
    addressP next;
};

struct ListP {
    addressP first;
};

addressP alokasiP(infotypeP x);
void dealokasiP(addressP P);
addressP findElmP(ListP L, int x);
void createListP(ListP &L);
void insertFirstP(ListP &L, addressP P);
void deleteFirstP(ListP &L, addressP &P);
void deleteAfterP(ListP &L, addressP &P);
void deleteLastP(ListP &L, addressP &P);
void editListP(ListP &L, addressP P);
void printInfoP(ListP L);
void insertInfoP(infotypeP &x);

#endif // PENULIS_H_INCLUDED
