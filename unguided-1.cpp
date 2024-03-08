#include <iostream>
using namespace std;
// Fungsi untuk menghitung volume balok
int hitungVolumeBalok(int panjang, int lebar, int tinggi) {
    return panjang * lebar * tinggi;
}
int main() {
    // Variabel untuk panjang, lebar, dan tinggi balok
    int panjang, lebar, tinggi;
    // input nilai panjang
    cout << "Masukkan panjang balok: ";
    cin >> panjang;
    // input nilai lebar
    cout << "Masukkan lebar balok: ";
    cin >> lebar;
    // input nilai tinggi
    cout << "Masukkan tinggi balok: ";
    cin >> tinggi;

    // Memanggil fungsi hitungVolumeBalok dan menampilkan hasilnya
    int volume = hitungVolumeBalok(panjang, lebar, tinggi);
    cout << "Volume balok : " << volume;
    return 0;
}

