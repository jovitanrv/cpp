#include "PENULIS.h"

addressP alokasiP(infotypeP x){
    addressP P;
    P = new elmlistP;
    info(P) = x;
    next(P) = NULL;
    return P;
}

void dealokasiP(addressP P){
    delete P;
}

addressP findElmP (ListP L, int x){
    addressP P;
    bool cek = false;
    if (first(L) != NULL){
        P = first(L);
        while ((cek == false) && (next(P) != first(L))){
            if (info(P).kope == x){
                cek = true;
            }
            else {
                P = next(P);
            }
        }
        if (info(P).kope == x){
                cek = true;
        }
    }
    if (cek==true) {
        return P;
    } else {
        return NULL;
    }
}

void createListP(ListP &L){
        first(L) = NULL;
}


void insertFirstP(ListP &L, addressP P)
{
    if (first(L) == NULL){
        first(L) = P;
        next(P) = first(L);
    } else {
        addressP Q = first(L);
        while (next(Q) != first(L)){
            Q = next(Q);
        }
        next(P) = first(L);
        next(Q) = P;
        first(L) = P;
    }
}


void deleteAfterP(ListP &L, addressP &P){
    if (first(L) != NULL){
        if (P == first(L)){
            deleteFirstP(L,P);
        } else if(next(P)==first(L)){
           deleteLastP(L, P);
        } else {
            addressP Q = first(L);
            while(next(Q)!=P){
                Q = next(Q);
            }
            next(Q) = next(P);
            next(P) = NULL;
        }
    } else {
        cout<<"\t\tData yang dicari kosong"<<endl;
    }
    dealokasiP(P);
}

void deleteFirstP(ListP &L, addressP &P){
    if (next(first(L)) == first(L)){
        P = first(L);
        next(P) = NULL;
        first(L) = NULL;
    } else if (next(P) != first(L)){
        addressP Q = first(L);
        while (next(Q) != first(L)){
            Q = next(Q);
        }
        P = first(L);
        first(L) = next(P);
        next(Q) = first(L);
        next(P) = NULL;
    }
    dealokasiP(P);
}

void deleteLastP(ListP &L, addressP &P){
    if (next(first(L)) == first(L)){
        deleteFirstP(L,P);
    } else {
        P = first(L);
        addressP Q;
        while (next(P) != first(L)){
            Q = P;
            P = next(P);
        }
        next(Q) = first(L);
        next(P) = NULL;
    }
    dealokasiP(P);
}

void printInfoP(ListP L){
    addressP P;
    P = first(L);
    if (P == NULL){
        cout <<"\t\tList Kosong"<<endl;
        getch();
    } else {
        cout<<"\t\t============================="<<endl;
        while (next(P) != first(L)) {
            cout<<"\t\t| Nama       : " <<info(P).nama<<endl;
            cout<<"\t\t| Umur       : " <<info(P).umur<<endl;
            cout<<"\t\t============================="<<endl;
            P = next(P);
        }
        cout<<"\t\t| Nama       : " <<info(P).nama<<endl;
        cout<<"\t\t| Umur       : " <<info(P).umur<<endl;
        cout<<"\t\t============================="<<endl;
    }
}

void insertInfoP(infotypeP &x){
    cout<<"\t\t============================="<<endl;
    cout<<"\t\t| Kode        : "; cin>>x.kope;
    cout<<"\t\t| Nama        : "; cin.ignore(); getline(cin,x.nama);
    cout<<"\t\t| Umur        : "; cin>>x.umur;
    x.jumbuk = 0;
    cout<<"\t\t============================="<<endl;
}
