#include "BUKU.h"

addressB alokasiB(infotypeB x){
    addressB P;
    P = new elmlistB;
    info(P) = x;
    next(P) = NULL;
    return P;
}

void dealokasiB(addressB P){
    delete P;
}

addressB findElmB(ListB L, infotypeB x){
    addressB p;
    bool cek;
    cek = false;
    if (first(L) != NULL){
        p = first(L);
        while ((cek==false) && (p != NULL)){
            if (info(p).kode == x.kode){
                cek = true;
            }
            else {
                p = next(p);
            }
        }
    }
    if (cek==true) {
        return p;
    }
    else{
        return NULL;
    }
}

void insertSort(ListB &L, addressB P){
    if(first(L)!=NULL){
        insertLastB(L, P);
        P = first(L);
        addressB Q;
        addressB R;
        addressB S;
        addressB T;
        while(next(P)!=NULL){
            if(next(P)!=NULL){
                Q = next(P);
                while(Q!=NULL){
                    if(info(Q).kode < info(P).kode){
                        if((P == first(L)) && (Q == next(P))){
                            first(L) =  Q;
                            next(P) = next(Q);
                            next(Q) = P;
                            P = first(L);
                            Q = P;
                        } else if ((P == first(L))&&(Q != next(P))){
                            first(L) = next(P);
                            next(P) = next(Q);
                            next(Q) = P;
                            P =first(L);
                            Q = P;
                        } else if ((P!=first(L))&&(next(Q)!=NULL)){
                            if(next(P)!=Q){
                                S = first(L);
                                T = first(L);
                                while(next(T)!= Q){
                                    T = next(T);
                                }
                                while(next(S)!=P){
                                    S = next(S);
                                }
                                next(S) = Q;
                                next(T) = next(Q);
                                next(Q) = next(P);
                                next(P) = next(T);
                                next(T) = P;
                                P = first(L);
                                Q = P;
                            } else if (next(P)==Q){
                                S = first(L);
                                while(next(S)!=P){
                                    S =next(S);
                                }
                                next(S) = Q;
                                next(P) = next(Q);
                                next(Q) = P;
                                P =first(L);
                                Q = P;
                            }
                        } else if ((P == first(L))&&(next(Q)==NULL)){
                            T = first(L);
                            while(next(T)!=Q){
                                T = next(T);
                            }
                            next(Q) = next(P);
                            first(L) = Q;
                            next(T) = P;
                            next(P) = NULL;
                            P = first(L);
                        } else if ((P!=first(L))&&(next(Q)==NULL)){
                            T = first(L);
                            S = first(L);
                            while(next(S)!=P){
                                S =next(S);
                            }
                            while(next(T)!=Q){
                                T = next(T);
                            }
                            next(S) = Q;
                            next(T) = P;
                            next(Q) = next(P);
                            next(P) = NULL;
                            P = first(L);
                            Q = P;
                        }
                    }
                    Q = next(Q);
                }
            }
            P =next(P);
        }
    } else {
        first(L) = P;
    }
}


void createListB(ListB &L){
    first(L) = NULL;
}

void insertLastB(ListB &L, addressB P){
    if (first(L)==NULL){
        first(L)=P;
    }
    else {
        addressB Q;
        Q = first(L);
        while(next(Q)!=NULL){
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void deleteFirstB(ListB &L, addressB &P){
     if(first(L)!=NULL){
        if(next(first(L))!= NULL){
            P = first(L);
            first(L) = next(P);
            next(P) = NULL;
        } else {
            P = first(L);
            first(L) = NULL;
        }
    } else {
        cout<<"\t\tTidak ada data yang dapat dihapus"<<endl;
    }
}

void deleteLastB(ListB &L, addressB &P){
    if(first(L)!= NULL){
        P = first(L);
        if(next(P)!=NULL){
            addressB Q = first(L);
            P = next(P);
            while(next(P)!=NULL){
                Q = next(Q);
                P = next(P);
            }
            next(Q) = NULL;
        }
        else {
            deleteFirstB(L, P);
        }
    }
    else {
        cout<<"\t\tTidak ada data yang dapat dihapus"<<endl;
    }
}

void deleteAfterB(ListB &L, addressB &P){
    if(first(L)!= NULL){
        if(next(first(L))!=NULL){
            addressB Q = first(L);
            while(next(Q)!=P){
                Q = next(Q);
            }
            next(Q) = next(P);
            next(P) = NULL;
        }
        else{
            deleteFirstB(L, P);
        }
    }
    else {
        cout<<"\t\tTidak ada data yang dapat dihapus"<<endl;
    }
}

void printInfoB(ListB L){
    addressB P;
    P = first(L);
    if (P==NULL){
        cout << endl << "\t\tList Kosong";
        getch();
    }
    else {
        while (P != NULL ) {
            cout << endl;
            cout<<"\t\t============================="<<endl;
            cout<<"\t\t| Kode           : "<<info(P).kode<<endl;
            cout<<"\t\t| Nama Buku      : "<<info(P).namab<<endl;
            cout<<"\t\t| Jumlah Halaman : "<<info(P).jumhal<<endl;
            cout<<"\t\t| Tahun Terbit   : "<<info(P).tahter<<endl;
            cout<<"\t\t============================="<<endl;
            P = next(P);
        }
    }
}

void insertInfoB(infotypeB &x){
    cout<<"\t\t============================="<<endl;
    cout<<"\t\t| Kode           : "; cin >> x.kode;
    cout<<"\t\t| Nama Buku      : "; cin.ignore(); getline(cin,x.namab);
    cout<<"\t\t| Jumlah Halaman : "; cin >> x.jumhal;
    cout<<"\t\t| Tahun Terbit   : "; cin >> x.tahter;
    cout<<"\t\t============================="<<endl;
}
