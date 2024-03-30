# <h1 align="center">Laporan Praktikum Modul Sorting</h1>
<p align="center">Ahmad Fariz Gustav</p>


## Dasar Teori
### Konsep Dasar Sorting
Pengurutan data atau “sorting” adalah proses menyusun kembali data yang sebelumnya telah tersusun secara acakHingga tersusun secara teratur menurut aturan tertentu. Data ini biasanya bertipe numerik dan karakter.Pengurutan data memiliki banyak  fungsi  dalam  sistem.  Data yang  diurutkan  mudah  dicari,  mudahdiperiksa,  jika  terjadi  kesalahan,  mudah diperbaiki.  Data  yang  diurutkan  dengan  baik  juga  mudah  dihapus  jikaterkadang  data  tidak  lagi  diperlukan.  Selain  itu, dengan memilah data, kita akan lebih mudahmemasukkan data atau lakukan penggabungan[1]. Sorting terbagi menjadi dua jenis yaitu :
- Ascending : Dalam pengurutan ascending, data diurutkan dari nilai terkecil ke nilai terbesar. Dalam konteks numerik, ini berarti bahwa angka yang lebih kecil akan muncul terlebih dahulu di depan, diikuti oleh angka yang lebih besar, contoh : 2, 3, 4, 5, 6
- Descending :Dalam pengurutan descending, data diurutkan dari nilai terbesar ke nilai terkecil. Ini berarti bahwa angka yang lebih besar akan muncul terlebih dahulu di depan, diikuti oleh angka yang lebih kecil, contoh : 10, 9, 8, 7, 6

### 1. Insertion sort
Insertion sort adalah metode pengurutan dengan cara menyisipkan elemen
data pada posisi yang tepat. Pencarian posisi yang tepat dilakukan dengan melakukan
pencarian berurutan didalam barisan elemen, selama pencarian posisi yang tepat dilakukan
pergeseran elemen. Pengurutan insertion sort sangat mirip
dengan konsep permainan kartu, bahwa setiap kartu disisipkan secara berurutan dari kiri ke
kanan sesuai dengan besar nilai kartu tersebut, dengan syarat apabila sebuah kartu disisipkan
pada posisi tertentu kartu yang lain akan bergeser maju atau mundur sesuai dengan besaran
nilai yang dimiliki [2]. Contoh ilustrasi :

![image](https://github.com/Gustavers/Laporan-praktikum/assets/162097300/d436eef0-5aee-45ef-94b9-8e34ecbc5029)

### 2. Bubble sort
Bubble Sort  adalah  metode  pengurutan  data  dengan  cara  menukar  data  pada  data  pertama  dan  data  pada  data  pertama tetap  duduk  di  sebelahnya  sampai Anda  yakin  tidak  akan  ada  lagi  perubahan  atau  pertukaran  dalam  iterasi  tertentu[1]. Algoritma menggunakan perbandingan dalam operasi antar elemen. Algoritma bubble sort adalah algoritma pengurutan yang  paling  dasar,  dan  metode  pengurutan  juga  yang  paling  sederhana  daripada  algoritma  pengurutan  lainnya.Proses pencarian solusi dilakukan secara brute force, direct to the point, yaitu. Bandingkan elemen dalam tabel.Algoritma bubble sort adalah proses penyortiran yang secara bertahap memindahkan data ke lokasi yang benar[1]. Karena itulah algoritma ini disebut  “bubble”  atau  jika  diterjemahkan  ke  dalam  bahasa  Indonesia  Gelembung.

### 3. Selection sort
Algoritma selection sort sering juga disebut dengan metode maksimum atau minimum.
Metode maksimum karena didasarkan pada pemilihan data atau elemen maksimum sebagai
dasar pengurutan [2]. Konsepnya dengan memilih elemen maksimum kemudian mempertukarkan
elemen maksimum tersebut dengan elemen paling akhir untuk urutan ascending dan elemen
pertama untuk descending [2]. contoh ilustrasi :

![image](https://github.com/Gustavers/Laporan-praktikum/assets/162097300/fac4ec79-8fd9-4509-8ab3-88d0f422e0e3)



## Guided 
### 1. Mengurutkan secara ascending untuk data numerik bertipe double menggunakan Algoritma Bubble Sort
![image](https://github.com/Gustavers/Laporan-praktikum/assets/162097300/f0097dbf-2adf-4967-8e51-ec07592ee25a)

```c++

#include <iostream>
using namespace std;

void bubble_sort(double arr[], int length){
    bool not_sorted = true;
    int j = 0;
    double tmp;

    while (not_sorted){
        not_sorted = false;
        j++;
        for (int i = 0; i < length - j; i++){
            if (arr[i] > arr[i + 1]) {
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                not_sorted = true;
            }//end of if
        }//end of for loop
    }//end of while loop
}//end of bubble_sort

void print_array(double a[], int length) {
    for(int i =0; i < length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}
int main(){

    int length = 5;
    double a[] = {22.1,15.3,8.2,33.21,99.99};

    cout << "Urutan bilangan sebelum sorting :" << endl;
    print_array(a, length);

    bubble_sort(a, length);

    cout << "\nUrutan bilangan setelah sorting :" << endl;
    print_array(a, length);
}
```
#### Output :
![image](https://github.com/Gustavers/Laporan-praktikum/assets/162097300/78f1151b-ed8c-4330-b624-f81f4e979c15)

Kode di atas menggunakan algoritma bubble sort untuk mengurutkan array a yang berisi 5 bilangan desimal. Algoritma ini melakukan ini dengan membandingkan elemen yang berdekatan dalam array berulang kali dan akan di tukar jika urutannya tidak benar. Sampai seluruh array terurut, proses ini diulangi. Dua fungsi utama dalam kode tersebut adalah bubble_sort dan print_array. Fungsi pertama melakukan pengurutan array menggunakan algoritma bubble sort, dan fungsi kedua melakukan iterasi pada array untuk mengubah elemen jika diperlukan. Namun, isi array dapat dicetak ke layar dengan menggunakan fungsi print_array. Sebelum pengurutan dilakukan, fungsi main() menciptakan array bilangan pecahan dan mencetaknya ke layar. Untuk mengurutkan array, fungsi bubble_sort digunakan. Selanjutnya, hasil pengurutan dicetak kembali untuk menampilkan urutan setelah pengurutan. 

### 2. Mengurutkan karakter secara descending (dari terbesar hingga terkecil) menggunakan Algoritma Insertion Sort
![image](https://github.com/Gustavers/Laporan-praktikum/assets/162097300/4c43ef51-380c-4ac6-a278-232618c363d7)

```c++
#include <iostream>
using namespace std;

void insertion_sort(char arr[], int length){
    int i, j;
    char tmp;

    for (i = 1; i < length; i++) {
        j = i;
    
        while (j > 0 && arr[j - 1] < arr[j]){
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
        }
    }
}

void print_array(char a[], int length) {
    for(int i=0; i < length; i++){
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main(){

    int length = 6;
    char a[length] = {'c', 'f', 'a','z', 'd','p'};

    cout << "Urutan karakter sebelum sorting :" << endl;
    print_array(a, length);

    insertion_sort(a, length);

    cout << "\nUrutan karakter setelah sorting :" << endl;
    print_array(a, length);
}
```
#### Output :
![image](https://github.com/Gustavers/Laporan-praktikum/assets/162097300/130d183a-ee01-43ba-9fbb-8c44c7735380)

Insertion Sort digunakan untuk mengurutkan array dengan membandingkan setiap elemen secara berurutan dan memindahkan elemen yang tidak terurut ke posisi yang tepat dalam array yang sudah terurut. Untuk melakukan ini, fungsi "insertion_sort" melakukan iterasi melalui array dan membandingkan setiap elemen dengan elemen sebelumnya; jika elemen sebelumnya lebih kecil, maka elemen tersebut di switch. Selanjutnya, sebuah array karakter dibuat dan dicetak di dalam fungsi "main()" sebelum proses pengurutan dimulai lalu untuk fungsi "insertion_sort" digunakan untuk mengurutkan array tersebut. Hasil pengurutan dicetak kembali ke layar untuk menampilkan urutan setelah pengurutan.

## Unguided 

### 1. Kelas S1 IF 2016 G memiliki 5 mahasiswa. Pada akhir semester mereka menerimalembar Indeks Prestasi Semester (IPS), masing-masing mahasiswa tersebut memiliki IPSsebagai berikut: {3.8, 2.9, 3.3, 4.0, 2.4}. Buatlah program untuk mengurutkan IPS mahasiswa tersebut dari yang terbesar hingga terkecil dengan menggunakan algoritma Selection Sort!
```c++
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
```

#### Output :
![image](https://github.com/Gustavers/Laporan-praktikum/assets/162097300/d5da102c-4a80-4afa-af85-f3353fb0bdfd)

Kode diatas bertujuan untuk mengurutkan Indeks Prestasi Semester (IPS) siswa. Program ini bekerja dengan mencari nilai IPS terbesar pada setiap iterasi, dan kemudian menukarnya dengan elemen pertama yang belum diurutkan. Sampai seluruh array terurut, proses ini berakhir. Sementara fungsi "selection_sort" melakukan proses pengurutan, fungsi "print_ips" mencetak nilai IPS siswa ke layar. Nilai IPS siswa telah ditetapkan dalam array "ips" dalam fungsi "main". Setelah nilai IPS sebelum pengurutan dicetak, fungsi "selection_sort" digunakan untuk mengurutkan nilai IPS. Setelah pengurutan selesai, hasilnya dicetak kembali ke layar. Ini menampilkan urutan dari IPS tertinggi hingga terendah. Untuk kompleksitas waktu dari program ini adalah O(n2) dikarenakan adanya dua loop bersarang.

#### Full code Screenshot :
![image](https://github.com/Gustavers/Laporan-praktikum/assets/162097300/143e7539-144f-4775-9e44-60d9bce6b6b3)

### 2. Pak RT memiliki 10 warga dengan nama: siti, situ, sana, ana, ani, caca, cici, dida, dodo, dan dadi. Supaya mudah dalam melakukan pencarian, Pak RT akan mengurutkan namanama tersebut sesuai dengan alfabet. Buatlah program untuk membantu Pak RT dengan menggunakan algoritma Bubble Sort

```c++
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

```
#### Output :
![image](https://github.com/Gustavers/Laporan-praktikum/assets/162097300/5aee5768-d494-4f66-94fc-c3590bf6904d)

Kode di atas untuk mengurutkan array string yang berisi nama penduduk menggunakan algoritma bubble sort. Fungsi BubbleSort diimplementasikan untuk mengurutkan dengan melakukan iterasi melalui array dan membandingkan setiap pasangan elemen secara berurutan. Jika nama indeks saat ini lebih besar dari nama indeks berikutnya, maka posisinya ditukar. Proses ini diulangi hingga tidak ada lagi pertukaran yang perlu dilakukan, yang menunjukkan bahwa array telah diurutkan. Pada fungsi utama dideklarasikan tabel nama yang berisi nama-nama warga negara. Sebelum disortir, nama-nama tersebut dicetak di layar. Setelah menyortir dengan BubbleSort, nama yang telah diurutkan akan dicetak kembali ke layar untuk menampilkan urutannya ketika proses sorting selesai. Untuk kompleksitas waktu dari program ini adalah O(n2) dikarenakan adanya dua loop bersarang

#### Full code screenshot :
![image](https://github.com/Gustavers/Laporan-praktikum/assets/162097300/92f72f90-3c2e-41a3-bcb7-4d86c4ea2129)

### 3. . Buatlah program yang meminta user menginputkan suatu bilangan n dan meminta user untuk menginputkan sejumlah n karakter. Kemudian program akan melakukan sorting secara menaik (ascending) dan menurun (descending)!

```c++
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
```
#### Output :
![image](https://github.com/Gustavers/Laporan-praktikum/assets/162097300/7b965519-0fd4-4841-8575-3735953a7bd2)

Program diatas meminta user memasukkan 5 karakter satu per satu. Setelah memasukkan karakter, program menampilkan string sebelum menyortir. Program kemudian melakukan pengurutan menaik menggunakan dan menampilkan hasil item. Program kemudian melakukan pengurutan menurun yang menghasilkan pengurutan menurun. Hasil penyortiran juga ditampilkan. Program ini menampikan karakter sebelum di urutkan dan karakter yang sudah diurutkan secara ascending maupun descending. Kompleksitas waktu program ini adalah O(n log n) untuk kedua proses pengurutan (ascending dan descending), di mana n adalah jumlah elemen dalam array.

#### Full code screenshot :
![image](https://github.com/Gustavers/Laporan-praktikum/assets/162097300/aa68413c-52e2-42ca-8abf-e049af4fb48c)

## Kesimpulan
Singkatnya, algoritma pengurutan adalah serangkaian langkah atau prosedur yang digunakan untuk mengurutkan atau menyusun catatan dalam urutan tertentu dari nilai terendah ke nilai tertinggi (ascending order) atau sebaliknya (descending order).
 Berbagai jenis algoritma pengurutan telah dikembangkan, masing-masing dengan cara kerja yang berbeda dan  kompleksitas ruang dan waktu yang berbeda.
 Algoritma pengurutan yang paling umum digunakan meliputi pengurutan gelembung, pengurutan pilihan, dan pengurutan penyisipan.
 Bubble sort membandingkan setiap pasangan elemen yang berurutan dalam sebuah array.
 Pengurutan pilihan membagi array menjadi dua bagian dan secara berulang memilih elemen terkecil dan memindahkannya ke bagian yang diurutkan.
 Sebaliknya, pengurutan penyisipan membagi array menjadi bagian-bagian yang terurut dan tidak terurut dan menyisipkan setiap elemen di bagian yang tidak terurut ke  posisi yang sesuai di bagian yang terurut.
 .
 Setiap algoritma memiliki kekuatan dan kelemahannya masing-masing dan cocok untuk digunakan dalam situasi dan konteks tertentu, bergantung pada volume data, kebutuhan penyimpanan, dan faktor lainnya.
 Dengan memahami karakteristik masing-masing algoritma, Anda dapat memilih algoritma pengurutan terbaik untuk  setiap skenario pengurutan data.




## Referensi

[1] Nasution, R., Syahputra, A., Widiyanto, A., Subuhanto, D., & Abdillah, A. Y. (2023). _Persepsi Mahasiswa Informatika Terhadap Keefektifan Algoritma Bubble Sort dalam Mengurutkan Data. Blend Sains Jurnal Teknik_ , 1(3), 220–225. https://doi.org/10.56211/blendsains.v1i3.186

[2] Retnoningsih E. (2018). _Algoritma Pengurutan Data (Sorting) Dengan Metode
Insertion Sort dan Selection Sort_. Information Management For Educators And Professionals. 3
(1): 95 - 106