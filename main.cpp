#include "Doublylist.h"

int main() {
    List L;
    CreateList(L);
    infotype x;

    // ===== Soal 1: input 4 data, nopol harus unik =====
    for (int i = 0; i < 4; i++) {
        cout << "masukkan nomor polisi: ";
        cin >> x.nopol;
        cout << "masukkan warna kendaraan: ";
        cin >> x.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> x.thnBuat;

        if (findElm(L, x) != Nil) {
            cout << "nomor polisi sudah terdaftar" << endl << endl;
        } else {
            insertLast(L, alokasi(x));
            cout << endl;
        }
    }

    cout << "DATA LIST 1" << endl << endl;
    printInfo(L);
    cout << endl;

    // ===== Soal 2: cari nopol =====
    cout << "Masukkan Nomor Polisi yang dicari  : ";
    cin >> x.nopol;
    address P = findElm(L, x);
    if (P != Nil) {
        cout << endl;
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
    } else {
        cout << "Data tidak ditemukan" << endl;
    }
    cout << endl;

    // ===== Soal 3: hapus nopol =====
    cout << "Masukkan Nomor Polisi yang akan dihapus  : ";
    cin >> x.nopol;
    P = findElm(L, x);
    if (P == Nil) {
        cout << "Data tidak ditemukan" << endl;
    } else {
        address hapus;
        if (P == L.First) {
            deleteFirst(L, hapus);
        } else if (P == L.Last) {
            deleteLast(L, hapus);
        } else {
            deleteAfter(P->prev, hapus);
        }
        cout << "Data dengan nomor polisi " << hapus->info.nopol
             << " berhasil dihapus." << endl << endl;
        dealokasi(hapus);
    }

    cout << "DATA LIST 1" << endl << endl;
    printInfo(L);

    return 0;
}
