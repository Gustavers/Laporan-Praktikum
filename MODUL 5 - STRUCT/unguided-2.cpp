#include <iostream>
#include <string>
using namespace std;

const int MAX_BOOKS = 5;

struct Buku {
    string judul_buku;
    string pengarang;
    string penerbit;
    string tebal_halaman;
    double harga_buku;
};

int main() {
    // Deklarasi Array Struct Buku
    Buku arrayBuku[MAX_BOOKS];

    // Menampilkan Data Awal (Kosong)
    cout << "Data Awal (Kosong)" << endl;
    for (int i = 0; i < MAX_BOOKS; ++i) {
        cout << "Buku Ke-" << i + 1 << " =>" << endl;
        cout << "Judul Buku    : " << arrayBuku[i].judul_buku << endl;
        cout << "Pengarang     : " << arrayBuku[i].pengarang << endl;
        cout << "Penerbit      : " << arrayBuku[i].penerbit << endl;
        cout << "Tebal Halaman : " << arrayBuku[i].tebal_halaman << endl;
        cout << "Harga Buku    : Rp" << arrayBuku[i].harga_buku << endl;
        cout << endl;
    }

    // Mengisi Data Array Menggunakan For
    cout << "\n\nMengisi Data Buku" << endl;
    for (int i = 0; i < MAX_BOOKS; ++i) {
        cout << "Buku Ke-" << i + 1 << " =>" << endl;
        cout << "Masukkan Judul Buku    : ";
        getline(cin, arrayBuku[i].judul_buku);
        cout << "Masukkan Pengarang     : ";
        getline(cin, arrayBuku[i].pengarang);
        cout << "Masukkan Penerbit      : ";
        getline(cin, arrayBuku[i].penerbit);
        cout << "Masukkan Tebal Halaman : ";
        getline(cin, arrayBuku[i].tebal_halaman);
        cout << "Masukkan Harga Buku    : ";
        cin >> arrayBuku[i].harga_buku;
        cin.ignore();
        cout << endl;
    }

    // Menampilkan Data Array Setelah Diisi
    cout << "\n\nData Buku Setelah Diisi" << endl;
    for (int i = 0; i < MAX_BOOKS; ++i) {
        cout << "Buku Ke-" << i + 1 << " =>" << endl;
        cout << "Judul Buku    : " << arrayBuku[i].judul_buku << endl;
        cout << "Pengarang     : " << arrayBuku[i].pengarang << endl;
        cout << "Penerbit      : " << arrayBuku[i].penerbit << endl;
        cout << "Tebal Halaman : " << arrayBuku[i].tebal_halaman << endl;
        cout << "Harga Buku    : Rp" << arrayBuku[i].harga_buku << endl;
        cout << endl;
    }

    return 0;
}