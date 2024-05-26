#include <iostream>
using namespace std;

int main() {
    // Deklarasi variabel
    int panjang_array, maksimum, minimum, total = 0;

    // input panjang array
    cout << "Masukkan panjang array: ";
    cin >> panjang_array;

    // Membuat array 
    int array[panjang_array];

    // input array
    for (int i = 0; i < panjang_array; i++) {
        cout << "Array ke-" << (i + 1) << ": ";
        cin >> array[i];
    }

    // nilai maksimum dan minimum
    maksimum = minimum = array[0];
    for (int i = 1; i < panjang_array; i++) {
        if (array[i] > maksimum) {
            maksimum = array[i];
        }
        if (array[i] < minimum) {
            minimum = array[i];
        }
        total += array[i];
    }

    // Menghitung nilai rata-rata
    float rata_rata = static_cast<float>(total) / panjang_array;

    // Menampilkan hasil
    cout << "Nilai maksimum: " << maksimum << endl;
    cout << "Nilai minimum: " << minimum << endl;
    cout << "Nilai rata-rata: " << rata_rata << endl;

    return 0;
}
