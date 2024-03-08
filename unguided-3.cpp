#include <iostream>
#include <map>
using namespace std;
int main() {
    // Membuat map dengan key bertipe string dan value bertipe int
    map<string, int> nilai;
    // Menambahkan pasangan key-value
    nilai["Gustav"] = 90;
    nilai["Fauzan"] = 85;
    nilai["Ferdinan"] = 92;
    // Mengakses nilai dengan key
    cout << "Nilai Gustav: " << nilai["Gustav"] << endl;
    // Pencarian key yang tidak ada
    if (nilai.find("bunga") != nilai.end()) {
        cout << "Nilai Bunga: " << nilai["bunga"] << endl;
    } 
    else {
        cout << "bunga tidak ditemukan." << endl;
    }
    return 0;
}
