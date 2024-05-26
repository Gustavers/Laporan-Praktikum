#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    const int n = 5;
    char characters[n];

    // input karakter
    cout << "input n = 5" << endl;
    cout << "karakter ke-1: ";
    cin >> characters[0];
    cout << "karakter ke-2: ";
    cin >> characters[1];
    cout << "karakter ke-3: ";
    cin >> characters[2];
    cout << "karakter ke-4: ";
    cin >> characters[3];
    cout << "karakter ke-5: ";
    cin >> characters[4];

    // menampilkan urutan sebelum sorting
    cout << "\nUrutan karakter sebelum sorting: " << endl;;
    for (int i = 0; i < n; ++i) {
        cout << characters[i] << "     ";
    }
    cout << endl;

    // ascending sort
    sort(characters, characters + n);

    // Menampilkan ascending sort
    cout << "\nUrutan karakter setelah ascending sort: " << endl;
    for (int i = 0; i < n; ++i) {
        cout << characters[i] << "     ";
    }
    cout << endl;

    // descending sort
    sort(characters, characters + n, greater<char>());

    // Menampilkan descending sort
    cout << "\nUrutan karakter setelah descending sort: " << endl;
    for (int i = 0; i < n; ++i) {
        cout << characters[i] << "     ";
    }
    cout << endl;
    return 0;
}
