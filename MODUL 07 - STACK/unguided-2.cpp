#include <iostream>
#include <stack>
#include <sstream>
#include <algorithm>

using namespace std;

void balikKalimat(const string & kalimat) {
    int jumlahSpasi = count(kalimat.begin(), kalimat.end(), ' ');
    if (jumlahSpasi < 2) {
        cout << "Kalimat Harus Memiliki Minimal 3 Kata" << endl;
        return;
    }

    // Buat Stack (Tumpukan)
    stack<string> kata;

    // Memisahkan Kalimat Menjadi Kata Dan Menyimpannya Dalam Stack
    string kataSementara;
    stringstream ss(kalimat);
    while (getline(ss, kataSementara, ' ')) {
        kata.push(kataSementara);
    }

    // Membalikkan Urutan Kata Di Dalam Stack
    string kalimatTerbalik;
    while (!kata.empty()) {
        // Mengambil Kata Dari Stack Dan Membalik Urutannya
        string kataBalik = kata.top();
        reverse(kataBalik.begin(), kataBalik.end());
        kalimatTerbalik += kataBalik + " ";
        kata.pop();
    }

    // Menghapus Spasi Di Akhir
    kalimatTerbalik.erase(kalimatTerbalik.length() - 1);

    cout << "Kalimat Setelah Dibalik : " << kalimatTerbalik << endl;
}

int main() {
    string kalimat;

    cout << "Masukkan Sebuah Kalimat : ";
    getline(cin, kalimat);

    balikKalimat(kalimat);

    return 0;
}