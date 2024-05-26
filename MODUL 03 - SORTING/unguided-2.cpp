#include <iostream>
#include <string>

using namespace std;

void bubbleSort(string nama[], int n) {
  bool swapped = true;
  int i = 0;

  while (swapped) {
    swapped = false;
    for (int j = 0; j < n - i - 1; j++) {
      if (nama[j] > nama[j + 1]) {
        string temp = nama[j];
        nama[j] = nama[j + 1];
        nama[j + 1] = temp;
        swapped = true;
      }
    }
    i++;
  }
}

int main() {
  string nama[10] = {"siti", "situ", "sana", "ana", "ani", "caca", "cici", "dida", "dodo", "dadi"};
  int n = sizeof(nama) / sizeof(nama[0]);

  cout << "Nama sebelum diurutkan: " << endl;
  for (int i = 0; i < n; i++) {
    cout << nama[i] << " ";
  }
  cout << endl << endl;

  bubbleSort(nama, n);

  cout << "Nama setelah diurutkan: " << endl;
  for (int i = 0; i < n; i++) {
    cout << nama[i] << " ";
  }
  cout << endl;

  return 0;
}
