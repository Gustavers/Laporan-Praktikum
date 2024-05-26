#include <iostream>
#include <string>
using namespace std;

const int MAX_BOOKS = 5;

struct buku {
    string judul_buku;
    string pengarang;
    string penerbit;
    string tebal_halaman;
    double harga_buku;
};

int main() {
    // Mendeklarasikan Array Dari Struct Buku
    buku arrayBuku[MAX_BOOKS];

    // Mengisi Data Array Dari Struct Buku
    arrayBuku[0].judul_buku = "Laskar Pelangi";
    arrayBuku[0].pengarang = "Andrea Hirata";
    arrayBuku[0].penerbit = "Bandung Pustaka";
    arrayBuku[0].tebal_halaman = "529 halaman";
    arrayBuku[0].harga_buku = 52000;

    arrayBuku[1].judul_buku = "Dilan 1990";
    arrayBuku[1].pengarang = "Pidi Baiq";
    arrayBuku[1].penerbit = "Pastel Books";
    arrayBuku[1].tebal_halaman = "332 Halaman";
    arrayBuku[1].harga_buku = 53000;

    arrayBuku[2].judul_buku = "Negeri Lima Menara";
    arrayBuku[2].pengarang = "Ahmad Fuadi";
    arrayBuku[2].penerbit = "Gramedia Pustaka Utama";
    arrayBuku[2].tebal_halaman = "368 Halaman";
    arrayBuku[2].harga_buku = 73000;

    arrayBuku[3].judul_buku = "Sapiens Riwayat Singkat Umat Manusia";
    arrayBuku[3].pengarang = "Yuval Noah Harari";
    arrayBuku[3].penerbit = "PT Gramedia Pustaka Utama";
    arrayBuku[3].tebal_halaman = "464 Halaman";
    arrayBuku[3].harga_buku = 96000;

    arrayBuku[4].judul_buku = "Alkimia Cinta";
    arrayBuku[4].pengarang = "Paulo Coelho";
    arrayBuku[4].penerbit = "PT Gramedia Pustaka Utama";
    arrayBuku[4].tebal_halaman = "224 Halaman";
    arrayBuku[4].harga_buku = 47000;

    // Menampilkan Data Array Dari Struct Buku
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