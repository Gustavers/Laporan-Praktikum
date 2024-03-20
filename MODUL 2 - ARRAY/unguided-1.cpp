#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int n = 10; 
    vector<int> data_array(n);
    // input nomor
    for (int i = 0; i < n; ++i) {
        cout << "Array ke-" << i+1 << ": ";
        cin >> data_array[i];
    }
    // Menampilkan data array
    cout << "Data array : ";
    for (int i = 0; i < n; ++i) {
        cout << data_array[i] << " ";
    }
    cout << endl;
    // Memisahkan nomor ganjil dan genap
    vector<int> even_numbers;
    vector<int> odd_numbers;

    for (int i = 0; i < n; ++i) {
        if (data_array[i] % 2 == 0) {
            even_numbers.push_back(data_array[i]);
        } else {
            odd_numbers.push_back(data_array[i]);
        }
    }
    // Menampilkan nomor genap
    cout << "Nomor Genap: ";
    for (int num : even_numbers) {
        cout << num << ", ";
    }
    cout << endl;

    // Menampilkan nomor ganjil
    cout << "Nomor Ganjil: ";
    for (int num : odd_numbers) {
        cout << num << ", ";
    }
    cout << endl;


    return 0;
}
