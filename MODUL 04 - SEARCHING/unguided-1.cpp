#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// pencarian biner (binary search)
int binarySearch(const string& arr, char target, int left, int right) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        // Jika target ditemukan pada indeks tengah
        if (arr[mid] == target) {
            return mid;
        }
        // Jika target berada di sebelah kiri
        else if (arr[mid] > target) {
            return binarySearch(arr, target, left, mid - 1);
        }
        // Jika target berada di sebelah kanan
        else {
            return binarySearch(arr, target, mid + 1, right);
        }
    }

    // Jika target tidak ditemukan
    return -1;
}

int main() {
    string kata;
    char huruf_target;

    cout << "Masukkan kata : ";
    getline(cin, kata);

    // Simpan kalimat tanpa diurutkan
    string kataAwal = kata;

    // Mengonversi kalimat ke huruf kecil
    transform(kata.begin(), kata.end(), kata.begin(), ::tolower);

    // Mengurutkan karakter dalam kalimat
    sort(kata.begin(), kata.end());

    cout << "Masukkan huruf yang ingin dicari: ";
    cin >> huruf_target;
    huruf_target = tolower(huruf_target); // Mengonversi huruf target ke huruf kecil

    // Mencari huruf target binary search
    int index = binarySearch(kata, huruf_target, 0, kata.length() - 1);

    // Menampilkan hasil
    if (index != -1) {
        // Mencari indeks huruf 
        int originalIndex = kataAwal.find(tolower(huruf_target));
        cout << "Huruf '" << huruf_target << "' ditemukan pada indeks ke-" << originalIndex << endl;
    } else {
        cout << "Huruf '" << huruf_target << "' tidak ditemukan dalam kalimat '" << kata << "'." << endl;
    }
    return 0;
}
