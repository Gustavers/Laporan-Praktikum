#include <iostream>
using namespace std;

void selection_sort(double arr[], int length) {
    for (int i = 0; i < length - 1; i++) {
        int max_index = i;
        for (int j = i + 1; j < length; j++) {
            if (arr[j] > arr[max_index]) {
                max_index = j;
            }
        }
        if (max_index != i) {
            swap(arr[i], arr[max_index]);
        }
    }
}

void print_ips(double arr[], int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int Mahasiswa = 5;
    double ips[] = {3.8, 2.9, 3.3, 4.0, 2.4};

    cout << "IPS mahasiswa sebelum diurutkan : " << endl;
    print_ips(ips, Mahasiswa);

    selection_sort(ips, Mahasiswa);

    cout << "IPS mahasiswa setelah diurutkan : " << endl;
    print_ips(ips, Mahasiswa) ;

    return 0;
}
