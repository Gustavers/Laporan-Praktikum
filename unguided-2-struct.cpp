#include <iostream>
using namespace std;
struct Mahasiswa {
    // Data member
    string nama;
    int usia;
};
int main() {
    // Membuat objek dari struct Mahasiswa
    Mahasiswa mahasiswa1;
    // Mengisi data objek
    mahasiswa1.nama = "Gustav";
    mahasiswa1.usia = 19;
    // Menampilkan informasi langsung
    cout << "Nama: " << mahasiswa1.nama << "\nUsia: " << mahasiswa1.usia << " tahun\n";
    return 0;
}
