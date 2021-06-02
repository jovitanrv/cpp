#include <iostream>
#include "BUKU.h"
#include "PENULIS.h"
#include "RELASI.h"

using namespace std;

int main()
{
    ListB L;
    ListP J;
    ListR M;
    infotypeP C;
    infotypeB B;
    addressR R;
    addressP P;
    addressB K;
    createListB(L);
    createListP(J);
    createListR(M);
    int pilihan, pil;
    string pil2;

    cout<<"\t\t================================================="<<endl;
    cout<<"\t\t|                 SELAMAT DATANG                |"<<endl;
    cout<<"\t\t|              DATA BUKU DAN PENULIS            |"<<endl;
    cout<<"\t\t================================================="<<endl;
    cout<<" "<<endl;
    cout<<"\t\t[Tekan ENTER untuk melanjutkan]"<<endl;
    cin.get();
    do{
    system("CLS");
    cout<<"\t\t================================================="<<endl;
    cout<<"\t\t|                  MENU UTAMA                   |"<<endl;
    cout<<"\t\t================================================="<<endl;
    cout<<"\t\t|          1. Tambah Data                       |"<<endl;
    cout<<"\t\t|          2. Hapus Data                        |"<<endl;
    cout<<"\t\t|          3. Tampilkan Data                    |"<<endl;
    cout<<"\t\t|          4. Cari Data                         |"<<endl;
    cout<<"\t\t|          5. Status Penulis                    |"<<endl;
    cout<<"\t\t|          6. Tentang Kami                      |"<<endl;
    cout<<"\t\t|          0. Keluar                            |"<<endl;
    cout<<"\t\t================================================="<<endl;
    cout<<"\t\tPilihan : ";
    cin>>pilihan;
    if (pilihan ==1){
        system("CLS");
        cout<<"\t\t================================================="<<endl;
        cout<<"\t\t|                 TAMBAH DATA                   |"<<endl;
        cout<<"\t\t================================================="<<endl;
        cout<<"\t\t|              1. Data Buku                     |"<<endl;
        cout<<"\t\t|              2. Data Penulis                  |"<<endl;
        cout<<"\t\t|              3. Data Relasi                   |"<<endl;
        cout<<"\t\t================================================="<<endl;
        cout<<"\t\tPilihan : ";
        cin>>pilihan;
        if (pilihan == 1){
            insertInfoB(B);
            addressB Q = findElmB(L, B);
            if(Q ==NULL){
                K = alokasiB(B);
                insertSort(L, K);
                cout<<"\t\t===================================="<<endl;
                cout<<"\t\t|  Berhasil Menambahkan Data Buku  |"<<endl;
                cout<<"\t\t===================================="<<endl;
            } else {
                cout<<"\t\t========================"<<endl;
                cout<<"\t\t|    Data telah ada    |"<<endl;
                cout<<"\t\t========================"<<endl;
            }
            getch();
        } else if (pilihan == 2){
            insertInfoP(C);
            addressP Q = findElmP(J, C.kope);
            if(Q ==NULL){
                P = alokasiP(C);
                insertFirstP(J, P);
                cout<<"\t\t====================================="<<endl;
                cout<<"\t\t| Berhasil Menambahkan Data Penulis |"<<endl;
                cout<<"\t\t====================================="<<endl;
            } else {
                cout<<"\t\t========================"<<endl;
                cout<<"\t\t|    Data telah ada    |"<<endl;
                cout<<"\t\t========================"<<endl;
            }
            getch();
        } else if(pilihan == 3){
            if((first(L) == NULL) && (first(J) == NULL)){
                cout<<"\t\t======================"<<endl;
                cout<<"\t\t|    Data Kosong.    |"<<endl;
                cout<<"\t\t======================"<<endl;
            }
            else if(first(L)==NULL){
                cout<<"\t\t==========================="<<endl;
                cout<<"\t\t|    Data Buku Kosong.    |"<<endl;
                cout<<"\t\t==========================="<<endl;
            }
            else if(first(J)==NULL){
                cout<<"\t\t==============================="<<endl;
                cout<<"\t\t|     Data Penulis Kosong.    |"<<endl;
                cout<<"\t\t==============================="<<endl;
            }
            else {
                cout<<"\t\t====================================="<<endl;
                cout<<"\t\t|    Buku yang tersedia  "<<endl;
                cout<<"\t\t====================================="<<endl;
                addressB Q = first(L);
                cout<<"\t\t====================================="<<endl;
                while(Q != NULL){
                    cout<<"\t\t| Kode Buku : "<<info(Q).kode<<endl;
                    cout<<"\t\t| Nama Buku : "<<info(Q).namab<<endl;
                    cout<<"\t\t====================================="<<endl;
                    Q = next(Q);
                }
                cout<<"\t\tMasukkan Kode Buku : "; cin>>B.kode;
                cout<<"\t\t====================================="<<endl;
                cout<<endl;
                K = findElmB(L, B);
                R = findElm_RB(M, K);
                if(R == NULL){
                    if(K == NULL){
                        cout<<"\t\t====================================="<<endl;
                        cout<<"\t\t|            Buku tidak ada.        |"<<endl;
                        cout<<"\t\t====================================="<<endl;
                    } else {
                        cout<<"\t\t====================================="<<endl;
                        cout<<"\t\t|    Penulis yang tersedia : "<<endl;
                        cout<<"\t\t====================================="<<endl;
                        addressP Q = first(J);
                        while(next(Q) != first(J)){
                            cout<<"\t\t| Kode Penulis  : "<<info(Q).kope<<endl;
                            cout<<"\t\t| Nama Penulis  : "<<info(Q).nama<<endl;
                            cout<<"\t\t| Umur Penulis  : "<<info(Q).umur<<endl;
                            cout<<"\t\t====================================="<<endl;
                            Q = next(Q);
                        }
                        cout<<"\t\t| Kode Penulis  : "<<info(Q).kope<<endl;
                        cout<<"\t\t| Nama Penulis  : "<<info(Q).nama<<endl;
                        cout<<"\t\t| Umur Penulis  : "<<info(Q).umur<<endl;
                        cout<<"\t\t====================================="<<endl;
                        cout<<"\t\t Masukkan Kode Penulis : " ; cin>>C.kope;
                        cout<<"\t\t====================================="<<endl;
                        addressP P = findElmP(J, C.kope);
                        info(P).jumbuk = info(P).jumbuk + 1;
                        if(P == NULL){
                            cout<<"\t\t==============================="<<endl;
                            cout<<"\t\t|      Penulis tidak ada.     |"<<endl;
                            cout<<"\t\t==============================="<<endl;
                        }
                        else{
                            R = alokasiR(K, P);
                            insertLastR(M, R);
                            cout<<"\t\t=================="<<endl;
                            cout<<"\t\t|     SUKSES.    |"<<endl;
                            cout<<"\t\t=================="<<endl;
                        }
                    }
                }
        cout<<"\t\t[Tekan ENTER untuk melanjutkan]"<<endl;
        getch();
            }
        }
    } else if (pilihan == 2){
        system("CLS");
        cout<<"\t\t================================================="<<endl;
        cout<<"\t\t|                 HAPUS DATA                    |"<<endl;
        cout<<"\t\t================================================="<<endl;
        cout<<"\t\t|              1. Data Buku                     |"<<endl;
        cout<<"\t\t|              2. Data Penulis                  |"<<endl;
        cout<<"\t\t|              3. Data Relasi                   |"<<endl;
        cout<<"\t\t================================================="<<endl;
        cout<<"\t\tPilihan : "; cin>>pil;
        if(pil == 1){
            system("cls");
            addressB Q = first(L);
            while(next(Q)!=NULL){
                cout<<"\t\t| Kode Buku  : "<<info(Q).kode<<endl;
                cout<<"\t\t| Judul Buku : "<<info(Q).namab<<endl;
                cout<<"\n";
                Q = next(Q);
            }
            cout<<"\t\t| Kode Buku  : "<<info(Q).kode<<endl;
            cout<<"\t\t| Judul Buku : "<<info(Q).namab<<endl;
            cout<<"\n";
            cout<<"\t\t=========================================="<<endl;
            cout<<"\t\t| Masukkan kode buku yang ingin dihapus : ";
            cin>>B.kode;
            K = findElmB(L, B);
            if(K == NULL){
                system("cls");
                cout<<"\t\t=============================================="<<endl;
                cout<<"\t\t|  Data yang ingin dihapus tidak ditemukan.  |"<<endl;
                cout<<"\t\t=============================================="<<endl;
            } else {
                Q = first(L);
                while(info(Q).kode!=B.kode){
                    Q = next(Q);
                }
                cout<<"\t\t============================="<<endl;
                cout<<"\t\t| Nama Buku        : "<<info(Q).namab<<endl;
                cout<<"\t\t| Kode Buku        : "<<info(Q).kode<<endl;
                cout<<"\t\t| Jumlah Halaman   : "<<info(Q).jumhal<<endl;
                cout<<"\t\t| Tahun Terbit     : "<<info(Q).tahter<<endl;
                cout<<"\t\t============================="<<endl;
                cout<<"\n";
                cout<<"\t\tYakin ingin menghapus data di atas? [y/t]  ";
                cin>>pil2;
                if (pil2 == "y"){
                    bool cek;
                    cek = false;
                    if (K!=NULL){
                        R = findElm_RB(M,K);
                        if (R!=NULL){
                            cek = true;
                        }
                    }
                    if (cek==true) {
                        addressR O = first(M);
                        while(O != NULL){
                            if (info(parent(O)).kode == B.kode)
                                child(O)=NULL;
                            O = next(O);
                        }
                        delete_relasiB(M,B);
                        delDataR(M, R);
                    }
                        if(Q == first(L)){
                            deleteFirstB(L, Q);
                        } else if(next(Q)==NULL){
                            deleteLastB(L, Q);
                        } else {
                            deleteAfterB(L, Q);
                        }
                        cout<<"\t\t================================="<<endl;
                        cout<<"\t\t|  Data Buku berhasil dihapus.  |"<<endl;
                        cout<<"\t\t================================="<<endl;
                        getch();
                    } else if (pil2 == "t"){
                        cout<<"\t\t=================="<<endl;
                        cout<<"\t\t|  TERIMAKASIH.  |"<<endl;
                        cout<<"\t\t=================="<<endl;
                        getch();
                    }
            }
        } else if (pil == 2){
            system("cls");
            addressP Q;
            Q = first(J);
            while(next(Q) != first(J)){
                cout<<"\t\t| Kode Penulis : "<<info(Q).kope<<endl;
                cout<<"\t\t| Nama Penulis : "<<info(Q).nama<<endl;
                cout<<endl;"\n";
                Q = next(Q);
            }
            cout<<"\t\t| Kode Penulis : "<<info(Q).kope<<endl;
            cout<<"\t\t| Nama Penulis : "<<info(Q).nama<<endl;
            cout<<"\t\t============================================="<<endl;
            cout<<"\t\t| Masukkan kode penulis yang ingin dihapus : ";
            cin>>C.kope;
            P = findElmP(J, C.kope);
            if (P !=NULL){
                Q = first(J);
                while ((info(Q).kope != C.kope) && (next(Q) != first(J))){
                    Q = next(Q);
                }
                if (info(Q).kope == C.kope){
                    cout<<"\t\t============================="<<endl;
                    cout<<"\t\t| Kode Penulis     : "<<info(Q).kope<<endl;
                    cout<<"\t\t| Nama Penulis     : "<<info(Q).nama<<endl;
                    cout<<"\t\t| Umur Penulis     : "<<info(Q).umur<<endl;
                    cout<<"\t\t============================="<<endl;
                    cout<<"\n";
                }
                cout<<"\t\tApakah yakin akan menghapus data penulis diatas? [y/t]"<<endl;
                cin>>pil2;
                if (pil2 == "y"){
                    bool cek;
                    cek = false;
                    if (P!=NULL){
                        R = findElm_RP(M,P);
                        if (R!=NULL){
                            cek = true;
                        }
                    }
                    if (cek==true) {
                        addressR O = first(M);
                        while(O != NULL){
                            if (info(child(O)).kope == C.kope){
                                parent(O)=NULL;
                                O = next(O);
                            }
                        }
                            delete_relasiP(M,C);
                            delDataR(M, R);
                    }
                    if(Q == first(J)){
                        deleteFirstP(J, Q);
                    } else if (next(Q)==first(J)){
                        deleteLastP(J, Q);
                    } else {
                        deleteAfterP(J, Q);
                    }
                    system("cls");
                    cout<<"\t\t================================="<<endl;
                    cout<<"\t\t|   Data Buku penulis dihapus.   |"<<endl;
                    cout<<"\t\t================================="<<endl;
                    getch();
                } else if (pil2 == "t"){
                    system("cls");
                    cout<<"\t\t=================="<<endl;
                    cout<<"\t\t|  TERIMAKASIH.  |"<<endl;
                    cout<<"\t\t=================="<<endl;
                    getch();
                    }
            } else {
                system("cls");
                cout<<"\t\t=============================================="<<endl;
                cout<<"\t\t|  Data yang ingin dihapus tidak ditemukan.  |"<<endl;
                cout<<"\t\t=============================================="<<endl;
                getch();
            }
            } else if(pil == 3){
                cout<<"\n";
                cout<<"\t\t========================================"<<endl;
                cout << "\t\tMasukkan Kode Buku     : "; cin >> B.kode;
                cout << "\t\tMasukkan Kode Penulis  : "; cin >> C.kope;
                bool cek;
                cek = false;
                K = findElmB(L,B);
                P = findElmP(J,C.kope);
                if ((K!=NULL)&&(P!=NULL)){
                    R = findElm_RP(M,P);
                    if (R!=NULL){
                        cek = true;
                    }
                }
                if (cek==true) {
                    addressR Q = first(M);
                    while((Q != NULL)&&(info(parent(Q)).kode != B.kode )){
                        Q = next(Q);
                    }
                    child(Q) = NULL;
                    parent(Q) = NULL;
                    delDataR(M, R);
                    cout<<"\t\t=============="<<endl;
                    cout<<"\t\t|   Sukses   |"<<endl;
                    cout<<"\t\t=============="<<endl;
                }
                else{
                    system("cls");
                    cout<<"\t\t=============================="<<endl;
                    cout<<"\t\t|   Data Tidak Ditemukan.    |"<<endl;
                    cout<<"\t\t=============================="<<endl;
                }
                getch();
            }
    } else if(pilihan == 3){
        system("CLS");
        cout<<"\t\t================================================="<<endl;
        cout<<"\t\t|               TAMPILKAN DATA                  |"<<endl;
        cout<<"\t\t================================================="<<endl;
        cout<<"\t\t|              1. Data Buku                     |"<<endl;
        cout<<"\t\t|              2. Data Penulis                  |"<<endl;
        cout<<"\t\t|              3. Data Relasi                   |"<<endl;
        cout<<"\t\t================================================="<<endl;
        cout<<"\t\tPilihan : "; cin>>pilihan;
        if(pilihan == 1){
            printInfoB(L);
        }
        else if(pilihan == 2){
            printInfoP(J);
        }
        else if(pilihan == 3){
            R = first(M);
            if(R == NULL){
                cout<<"\t\t=================="<<endl;
                cout<<"\t\t| Tidak ada data. |"<<endl;
                cout<<"\t\t=================="<<endl;
            } else {
                while(R != NULL){
                    cout<<"\t\t=================================="<<endl;
                    cout<<"\t\t| Nama Buku        : "<<info(parent(R)).namab<<endl;
                    cout<<"\t\t| Nama Penulis     : "<<info(child(R)).nama<<endl;
                    cout<<"\t\t=================================="<<endl;
                    R = next(R);
                }
            }
        }
        getch();
    } else if(pilihan == 4){
        system("CLS");
        cout<<"\t\t================================================="<<endl;
        cout<<"\t\t|                 CARI DATA                     |"<<endl;
        cout<<"\t\t================================================="<<endl;
        cout<<"\t\t|              1. Data Buku                     |"<<endl;
        cout<<"\t\t|              2. Data Penulis                  |"<<endl;
        cout<<"\t\t|              3. Data Relasi (Buku)            |"<<endl;
        cout<<"\t\t|              4. Data Relasi (Penulis)         |"<<endl;
        cout<<"\t\t================================================="<<endl;
        cout<<"\t\tPilihan : "; cin>>pilihan;
        cout<<"\n";
        if(pilihan == 1){
            if(first(L)!=NULL){
                addressB Q = first(L);
                while(next(Q) != NULL){
                    cout<<"\t\tKode : "<<info(Q).kode<<endl;
                    Q =next(Q);
                }
                cout<<"\t\tKode : "<<info(Q).kode<<endl;
                cout<<"\n";
                cout<<"\t\tMasukkan Kode Buku : "; cin>>pilihan;
                Q = first(L);
                while((info(Q).kode!=pilihan) && (next(Q) != NULL)){
                    Q = next(Q);
                }
                if (info(Q).kode == pilihan){
                    cout<<"\t\t============================="<<endl;
                    cout<<"\t\t| Kode           : "<<info(Q).kode<<endl;
                    cout<<"\t\t| Nama Buku      : "<<info(Q).namab<<endl;
                    cout<<"\t\t| Jumlah Halaman : "<<info(Q).jumhal<<endl;
                    cout<<"\t\t| Tahun Terbit   : "<<info(Q).tahter<<endl;
                    cout<<"\t\t============================="<<endl;
                } else {
                    cout<<"\t\t========================="<<endl;
                    cout<<"\t\t| Data tidak ditemukan. |"<<endl;
                    cout<<"\t\t========================="<<endl;
                }
            getch();
            }
        } else if(pilihan == 2){
            if(first(J)!=NULL){
                addressP Q = first(J);
                while(next(Q) !=  first(J)){
                    cout<<"\t\tKode Penulis : "<<info(Q).kope<<endl;
                    Q = next(Q);
                }
                cout<<"\t\tKode Penulis : "<<info(Q).kope<<endl;
                cout<<"\n";
                cout<<"\t\tMasukkan Kode Penulis   : "; cin>>pilihan;
                Q = first(J);
                while((info(Q).nama!=pil2)&&(next(Q)!=first(J))){
                    Q = next(Q);
                }
                if (info(Q).kope==pilihan){
                    cout<<"\t\t================================="<<endl;
                    cout<<"\t\t| Nama       : " <<info(Q).nama<<endl;
                    cout<<"\t\t| Umur       : " <<info(Q).umur<<endl;
                    cout<<"\t\t================================="<<endl;
                } else {
                    cout<<"\t\t========================="<<endl;
                    cout<<"\t\t| Data tidak ditemukan. |"<<endl;
                    cout<<"\t\t========================="<<endl;
                }
                getch();
            }
        } else if(pilihan == 3){
            cout<<"\t\t============================"<<endl;
            cout<<"\t\t| Masukkan Kode Buku    : "; cin>>B.kode;
            cout<<"\t\t============================"<<endl;
            K = findElmB(L,B);
            R = findElm_RB(M,K);
            if(R == NULL){
                cout<<"\t\t=========================="<<endl;
                cout<<"\t\t| Data tidak ditemukan. |"<<endl;
                cout<<"\t\t=========================="<<endl;
            } else {
                addressR Q = first(M);
                while(info(parent(Q)).kode != B.kode){
                    Q = next(Q);
                }
                cout<<"\t\t================================"<<endl;
                cout<<"\t\t|          Data Buku           |"<<endl;
                cout<<"\t\t================================"<<endl;
                cout<<"\t\tKode Buku      : "<<info(parent(Q)).kode<<endl;
                cout<<"\t\tJudul Buku     : "<<info(parent(Q)).namab<<endl;
                cout<<"\t\tTahun Terbit   : "<<info(parent(Q)).tahter<<endl;
                cout<<"\t\tJumlah Halaman : "<<info(parent(Q)).jumhal<<endl;
                cout<<"\n";
                cout<<"\t\t================================"<<endl;
                cout<<"\t\t|         Data Penulis         |"<<endl;
                cout<<"\t\t================================"<<endl;
                cout<<"\t\tKode Penulis : "<<info(child(Q)).kope<<endl;
                cout<<"\t\tNama Penulis : "<<info(child(Q)).nama<<endl;
                cout<<"\t\tUmur Penulis : "<<info(child(Q)).umur<<endl;
                cout<<"\n";
            }
            getch();
           } else if(pilihan == 4){
                cout<<"\t\t=============================="<<endl;
                cout<<"\t\t| Masukkan Kode Penulis : "; cin>>C.kope;
                cout<<"\t\t=============================="<<endl;
                P = findElmP(J,C.kope);
                R = findElm_RP(M,P);
                if(R != NULL){
                    addressR Q = first(M);
                    while(info(child(Q)).kope != C.kope){
                        Q = next(Q);
                    }
                    cout<<"\t\t================================"<<endl;
                    cout<<"\t\t|          Data Buku           |"<<endl;
                    cout<<"\t\t================================"<<endl;
                    cout<<"\t\tKode Buku      : "<<info(parent(Q)).kode<<endl;
                    cout<<"\t\tJudul Buku     : "<<info(parent(Q)).namab<<endl;
                    cout<<"\t\tTahun Terbit   : "<<info(parent(Q)).tahter<<endl;
                    cout<<"\t\tJumlah Halaman : "<<info(parent(Q)).jumhal<<endl;
                    cout<<"\n";
                    cout<<"\t\t================================"<<endl;
                    cout<<"\t\t|         Data Penulis         |"<<endl;
                    cout<<"\t\t================================"<<endl;
                    cout<<"\t\tKode Penulis : "<<info(child(Q)).kope<<endl;
                    cout<<"\t\tNama Penulis : "<<info(child(Q)).nama<<endl;
                    cout<<"\t\tUmur Penulis : "<<info(child(Q)).umur<<endl;
                    cout<<"\n";
                } else {
                    cout<<"\t\t============================="<<endl;
                    cout<<"\t\t|   Data tidak ditemukan    |"<<endl;
                    cout<<"\t\t============================="<<endl;
                }
                getch();
            }
        } else if (pilihan == 5){
            system("CLS");
            cout<<"\t\t================================================="<<endl;
            cout<<"\t\t|                STATUS PENULIS                 |"<<endl;
            cout<<"\t\t================================================="<<endl;
            int temp;
            addressR P = first(M);
            temp = 0;
            while(next(P)!=NULL){
                if(info(child(P)).jumbuk >= temp){
                    temp = info(child(P)).jumbuk;
                }
                P = next(P);
            }
            if(info(child(P)).jumbuk >= temp){
                temp = info(child(P)).jumbuk;
            }
            P = first(M);
            cout<<"\t\t======================================"<<endl;
            cout<<"\t\t    Data Penulis Yang Paling Aktif    "<<endl;
            cout<<"\t\t======================================"<<endl;
            while((next(P)!=NULL)&&(info(child(P)).jumbuk != temp)){
                if(info(child(P)).jumbuk = temp){
                        P = next(P);
                    }
                }
                if(info(child(P)).jumbuk = temp){
                    cout<<"\t\t| Kode Penulis     : "<<info(child(P)).kope<<endl;
                    cout<<"\t\t| Nama Penulis     : "<<info(child(P)).nama<<endl;
                    cout<<"\t\t| Umur Penulis     : "<<info(child(P)).umur<<endl;
                    cout<<"\t\t| Jumlah Buku      : "<<info(child(P)).jumbuk<<endl;
                    cout<<"\t\t======================================"<<endl;
                }
            cout<<"\t\t======================================"<<endl;
            cout<<"\t\t Data Penulis Yang Paling Tidak Aktif "<<endl;
            cout<<"\t\t======================================"<<endl;
            addressP Q = first(J);
                while(next(Q)!= first(J)){
                    if(info(Q).jumbuk<temp){
                        temp = info(Q).jumbuk;
                    }
                    Q = next(Q);
                }
                if(info(Q).jumbuk<temp){
                    temp = info(Q).jumbuk;
                }
                Q =first(J);
                while((next(Q)!=first(J))&&(info(Q).jumbuk!=temp)){
                    Q = next(Q);
                }
                if(info(Q).jumbuk == temp){
                    cout<<"\t\t| Kode Penulis     : "<<info(Q).kope<<endl;
                    cout<<"\t\t| Nama Penulis     : "<<info(Q).nama<<endl;
                    cout<<"\t\t| Umur Penulis     : "<<info(Q).umur<<endl;
                    cout<<"\t\t| Jumlah Buku      : "<<info(Q).jumbuk<<endl;
                    cout<<"\t\t======================================"<<endl;
                }
        getch();
        } else if (pilihan == 6){
            system("cls");
            cout<<"\t\t================================================="<<endl;
            cout<<"\t\t|                 TENTANG KAMI                  |"<<endl;
            cout<<"\t\t================================================="<<endl;
            cout<<"\t\t|          Designed and Developed by :          |"<<endl;
            cout<<"\t\t|           Muhammad Athariq Purbaya            |"<<endl;
            cout<<"\t\t|                  1301174155                   |"<<endl;
            cout<<"\t\t|                Jovita Nurvania                |"<<endl;
            cout<<"\t\t|                  1301174215                   |"<<endl;
            cout<<"\t\t|                 IF - 41 - 02                  |"<<endl;
            cout<<"\t\t================================================="<<endl;
            getch();
        } else {
            system("CLS");
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<"\t\t================================================="<<endl;
            cout<<"\t\t|                 TERIMA KASIH                   |"<<endl;
            cout<<"\t\t================================================="<<endl;
            return 0;
        }
    }while(pilihan != 0);
        return 0;
}
