#include "RELASI.h"

addressR alokasiR(addressB x, addressP y){
    addressR P;
    P = new elmlistR;
    next(P) = NULL;
    prev(P) = NULL;
    parent(P) = x;
    child(P) = y;
    return P;
}

void dealokasiR(addressR P) {
    delete P;
}

addressR findElm_RB(ListR L, addressB x){
    addressR P;
    bool cek;
    cek = false;
    if (first(L) != NULL){
        P = first(L);
        while ((cek==false) && (P != NULL)){
            if (parent(P) == x){
                cek = true;
            }
            else {
                P = next(P);
    }
        }
    }
    if (cek==true) {
        return P;
    }
    else{
        return NULL;
    }
}

addressR findElm_RP(ListR L, addressP y){
    addressR P;
    bool cek;
    cek = false;
    if (first(L) != NULL){
        P = first(L);
        while ((cek==false) && (P != first(L))){
            if (child(P) == y){
                cek = true;
            }
            else {
                P = next(P);
            }
        }
        if (child(P) == y){
            cek = true;
        }
    }
    if (cek==true) {
        return P;
    }
    else{
        return NULL;
    }
}

void createListR(ListR &L){
    first(L) = NULL;
    last(L) = NULL;
}

void insertLastR(ListR &L, addressR P){
    if (first(L)==NULL){
        first(L)=P;
        last(L)=P;
    }
    else {
        next(last(L))=P;
        prev(P)=last(L);
        last(L)=P;
    }
}

void delDataR(ListR &L, addressR &P){
    if(first(L)!=NULL){
        if (first(L)==last(L)){
            P = first(L);
            first(L) = NULL;
            last(L) = NULL;
        }
        else if (last(L)==P){
            P = last(L);
            last(L) = prev(last(L));
            next(last(L)) = NULL;
            prev(P) = NULL;
        }
        else if (first(L)==P){
            P = first(L);
            first(L) = next(P);
            prev(first(L)) = NULL;
            next(P) = NULL;
        }
        else{
            next(prev(P)) = next(P);
            prev(next(P)) = prev(P);
            next(P) = NULL;
            prev(P) = NULL;
        }
        dealokasiR(P);
    }
}


void delete_relasiB(ListR &L, infotypeB x){
    addressR Q = first(L);
    while(Q != NULL){
        if (info(parent(Q)).kode == x.kode)
            parent(Q)=NULL;
        Q = next(Q);
    }
}

void delete_relasiP(ListR &L, infotypeP x){
    addressR Q = first(L);
    while(Q != NULL){
        if (info(child(Q)).kope == x.kope)
            child(Q)=NULL;
        Q = next(Q);
    }
}

void statusP(ListR &L){
    addressR P = first(L);
    addressR Q = next(P);
    int temp, temp1;
    temp1 = 0;
    while(next(P) != last(L)){
        temp = 1;
        while(Q!=last(L)){
            if(info(child(Q)).kope == info(child(P)).kope){
                temp = temp + 1;
            }
            Q = next(Q);
        }
        if(info(child(Q)).kope == info(child(P)).kope){
            temp = temp + 1;
        }
        info(child(P)).jumbuk = temp;
        if(temp >= temp1){
            temp1 = temp;
        }
        P = next(P);
        Q = next(P);
    }
    if(info(child(Q)).kope == info(child(P)).kope){
        temp = temp + 1;
    }
    if(temp >= temp1){
        temp1 = temp;
    }
    info(child(P)).jumbuk = temp;
    temp = 1;
    Q = first(L);
    while(Q!=last(L)){
        if(info(child(Q)).kope == info(child(P)).kope){
            temp = temp + 1;
        }
        Q =next(Q);
    }
    if(temp >= temp1){
        temp1 = temp;
    }
    info(child(P)).jumbuk = temp;
    P = first(L);
    cout<<"\t\t============================="<<endl;
    cout<<"\t\tData Penulis Yang Paling Aktif : "<<endl;
    cout<<"\t\t============================="<<endl;
    while(next(P)!=NULL){
        if(info(child(P)).jumbuk==temp1){
            cout<<"\t\t| Kode Penulis     : "<<info(child(P)).kope<<endl;
            cout<<"\t\t| Nama Penulis     : "<<info(child(P)).nama<<endl;
            cout<<"\t\t| Umur Penulis     : "<<info(child(P)).umur<<endl;
            cout<<"\t\t| Jumlah Buku      : "<<info(child(P)).jumbuk<<endl;
            cout<<"\t\t============================="<<endl;
        }
        P = next(P);
    }
    if(info(child(P)).jumbuk==temp1){
        cout<<"\t\t| Kode Penulis     : "<<info(child(P)).kope<<endl;
        cout<<"\t\t| Nama Penulis     : "<<info(child(P)).nama<<endl;
        cout<<"\t\t| Umur Penulis     : "<<info(child(P)).umur<<endl;
        cout<<"\t\t| Jumlah Buku      : "<<info(child(P)).jumbuk<<endl;
        cout<<"\t\t============================="<<endl;
    }
}

