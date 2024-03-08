#include <iostream>
using namespace std;
// Definisi class
class Mahasiswa {
public:
    // Data member
    string nama;
    int usia;
    // Fungsi anggota untuk menampilkan informasi mahasiswa
    void tampilkanInfo() {
    cout << "Nama: " << nama << "\nUsia: " << usia << " tahun\n";
    }
};
int main() {
    // Membuat objek dari class Mahasiswa
    Mahasiswa mahasiswa1;
    // Mengisi data objek
    mahasiswa1.nama = "Gustav";
    mahasiswa1.usia = 19;
    // Memanggil fungsi anggota
    mahasiswa1.tampilkanInfo();
    return 0;
}
