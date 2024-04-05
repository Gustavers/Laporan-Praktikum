# <h1 align="center">Laporan Praktikum Modul Searching</h1>
<p align="center">Ahmad Fariz Gustav</p>


## Dasar Teori
Pencarian (searching) adalah hal yang sering kita lakukan dalam
kehidupan sehari-hari [1]. Kita seringkali melakukan pencarian sebuah
kata tertentu dalam sebuah berkas naskah untuk menggantinya
dengan kata yang lain[1]. Dalam konteks ilmu komputer, pengambilan
dan organisasi data merepresentasikan prinsip dasar algoritma[1]. Proses
iteratif terhadap elemen dalam struktur data untuk ekstraksi informasi
spesifik dikenal sebagai pencarian[1]. Sebaliknya, penyortiran merujuk
pada proses penataan elemen dalam struktur data berdasarkan kriteria
tertentu. Terdapat beragam algoritma pencarian dan penyortiran yang
dikhususkan untuk jenis struktur data tertentu. Terdapat dua jenis algoritma searching yaitu :
1. __Sequential Search__ adalah algoritma yang paling sederhana. Sequential search disebut juga pencarian lurus
(linear search). Pencarian linier adalah nama lain dari algoritma pencarian berkelanjutan. Setiap elemen dalam
array dibandingkan secara berurutan, dimulai dengan elemen pertama, sampai elemen yang diinginkan ditemukan [2]. Contoh ilustrasi proses sequential search :
![image](https://github.com/Gustavers/Laporan-praktikum/assets/162097300/0aff5297-b8a8-47f5-8dc7-adaa0c6c7d68)

- Misalkan kita ingin mencari data 10
- Sehingga akan melalui proses iterasi untuk pencarian datanya:
- 1 = 10 ( Tidak ! )
- 2 = 10 ( Tidak ! )
- 5 = 10 ( Tidak ! )
- 10 = 10 ( Ya ) Outputunya adalah “ Ada ” pada index ke-3
- jika sampai pengurutan data terakhir yang di cari tidak juga ditemukan maka outputnya adalah “data yang
dicari tidak ada”.

2. __Binary   Search__   adalah   metode pencarian  data  pada  array  yang  telah terurut,  metode  ini lebih  effisien  dari  pada  metode  pencarian  linier  dimana semua  elemen  di  dalam  array  diuji  satu  persatu  sampai ditemukan elemen yang diinginkan [3].Algoritma  ini  bekerja  dengan  cara  memilih  record dengan  indeks  tengah  dari  tabel  dan  membandingkannya dengan  record  yang  hendak  dicari [3].  Jika  record  tersebut lebih  rendah  atau  lebih  tinggi,  maka  tabel  tersebut  dibagi dua  dan  bagian  tabel  yang  bersesuaian  akan  diproses kembali secara rekursif [3].
langkah-langkah dalam kerja algoritma pencarian biner :
    -  Proses pencarian dimulai dengan menempatkan elemen tengah dari larik data yang diurutkan Setiap data yang menggunakan algoritma pencarian biner harus diurutkan terlebih dahulu sehingga baru bisa melanjutkan proses kerja selanjutnya. Apabila data belum urut, maka data yang ada perlu diurutkan lebih dahulu 
    - Kemudian nilai kunci dibandingkan dengan elemennya 
    - Apabila nilai kunci lebih kecil dari elemen tengah, maka penelusuran akan menganalisis nilai atas hingga elemen tengah untuk perbandingan dan pencocokan 
    - Akan tetapi, apabila nilai kunci lebih besar dari elemen tengah, maka penelusuran menganalisis nilai yang lebih rendah ke elemen tengah untuk perbandingan dan pencocokan.
    Contoh :

![image](https://github.com/Gustavers/Laporan-praktikum/assets/162097300/16ede433-50c2-4dd7-92d8-f3be5e55703c)

- Terdapat sebuah array yang menampung 7 elemen seperti ilustrasi di atas
Nilai yang akan dicari pada array tersebut adalah 13
- Jadi karena konsep dari binary search ini adalah membagi array menjadi dua bagian, maka pertama tama kita cari nilai tengahnya dulu
- total elemen dibagi 2 yaitu 7/2 = 4.5 dan kita bulatkan jadi 4.
- Maka elemen ke empat pada array adalah nilai tengahnya, yaitu angka 9 pada indeks ke 3
- Kemudian kita cek apakah 13 > 9 atau 13 < 9?
- 13 lebih besar dari 9, maka kemungkinan besar angka 13 berada setelah 9 atau di sebelah kanan
- Selanjutnya kita cari ke kanan dan kita dapat mengabaikan elemen yang ada di kiri
- Setelah itu kita cari lagi nilai tengahnya, didapatlah angka 14 sebagai nilai tengah
- Kita bandingkan apakah 13 > 14 atau 13 < 14?
- Ternyata 13 lebih kecil dari 14, maka selanjutnya kita cari ke kiri
Karna tersisa 1 elemen saja, maka elemen tersebut adalah nilai tengahnya
- Setelah dicek ternyata elemen pada indeks ke-4 adalah elemen yang dicari, maka telah selesai proses pencariannya.

## Guided 
### 1. Buatlah sebuah project dengan menggunakan sequential search sederhana untuk melakukan pencarian data
![image](https://github.com/Gustavers/Laporan-praktikum/assets/162097300/d88a3387-c592-4621-9350-643a1b34147b)

```c++

#include <iostream>
using namespace std;
int main(){
    int n = 10;
    int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10};
    int cari = 10;
    bool ketemu = false;
    int i;
 // algoritma Sequential Search
 for (i = 0; i < n; i++){
 if(data[i] == cari){
 ketemu = true;
 break;
 }
 }
 cout << "\t Program Sequential Search Sederhana\n" << endl;
 cout << " data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}"<< endl;
 if (ketemu){ 
    cout << "\n angka "<< cari << " ditemukan pada indeks ke-" << i << endl;
 } 
    else {
 cout << cari << " tidak dapat ditemukan pada data." << endl;
 }
 return 0;
}
```
#### Output :
![image](https://github.com/Gustavers/Laporan-praktikum/assets/162097300/28e0f3a4-3c2a-4d5c-97c4-71037603796b)

Kode di atas merupakan implementasi dari algoritma Sequential, Program mencari nilai tertentu  dalam array data berukuran n (pencarian).
Periksa setiap elemen dalam array data, mulai dari indeks 0.
Jika nilai yang dicari ditemukan, variabel yang ditemukan disetel ke true dan program keluar dari loop dengan Break.
Setelah pencarian selesai, program akan menampilkan hasilnya.
Jika nilai yang dicari ditemukan, program akan mengeluarkan pesan  bahwa nomor tersebut ditemukan beserta indeksnya.
Jika nilai tidak ditemukan, program akan mencetak pesan yang menunjukkan bahwa nilai  tidak ditemukan dalam data.




### 2. Buatlah sebuah project untuk melakukan pencarian data dengan menggunakan Binary Search
![image](https://github.com/Gustavers/Laporan-praktikum/assets/162097300/d14c2217-1041-4251-bd81-06b85388c0cd)

```c++
#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

int cari;

void selection_sort(int data[], int length) {
    int temp, min, i, j;
    for(i = 0; i < 7; i++){
        min = i;
        for(j = i + 1; j < 7; j++){
            if(data[j] < data[min]) {
                min = j;
            }
        }
        temp = data[i];
        data[i] = data[min];
        data[min] = temp;
    }
}

void binarysearch(int data[], int length) {
    int awal, akhir, tengah, b_flag = 0;
    awal = 0;
    akhir = length - 1;
    while(b_flag == 0 && awal <= akhir) {
        tengah = (awal + akhir) / 2;
        if(data[tengah] == cari) {
            b_flag = 1;
            break;
        } else if(data[tengah] < cari)
            awal = tengah + 1;
        else 
            akhir  = tengah - 1;
    }
    if(b_flag == 1)
        cout << "\n Data ditemukan pada indeks ke- " << tengah << endl;
    else
        cout << "\n Data tidak ditemukan \n";
}

int main() {
    int data[7] = {1, 8, 2, 5, 4, 9, 7};
    int length = sizeof(data) / sizeof(data[0]);

    cout << "\t BINARY SEARCH " << endl;
    cout << "\n Data : ";
    // tampilan data awal
    for(int x = 0; x < length; x++)
        cout << setw(3) << data[x];
    cout << endl;

    cout << "\n Masukan data yang ingin anda cari : ";
    cin >> cari;

    cout << "\n Data diurutkan : ";
    // urutkan data dengan selection sort
    selection_sort(data, length);

    // tampilan data setelah diurutkan 
    for(int x = 0; x < length; x++)
        cout << setw(3) << data[x];
    cout << endl;

    binarysearch(data, length);
    return 0;
}
```
#### Output :
![image](https://github.com/Gustavers/Laporan-praktikum/assets/162097300/03505b5c-f837-43fe-9ee1-7ebd27318fbd)

Program ini menggunakan algoritma Sorting Selection untuk mencari nilai tertentu (cari) dalam array data yang telah diurutkan terlebih dahulu. Setelah data diurutkan, program meminta pengguna untuk memasukkan nilai yang ingin dicari. Jika nilai ditemukan, program mencetak indeks di mana nilai tersebut ditemukan, dan jika tidak ditemukan, program mencetak pesan bahwa nilai tersebut tidak ditemukan dalam data.

## Unguided 

### 1. Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!
```c++
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
```

#### Output :
![image](https://github.com/Gustavers/Laporan-praktikum/assets/162097300/89de4e9d-7e78-4543-b56f-f44553b68da3)

Program ini meminta pengguna untuk memasukkan sebuah kata dan sebuah huruf yang ingin dicari di dalam kata tersebut. Kemudian, program akan mengubah semua huruf dalam kata menjadi huruf kecil, mengurutkan huruf-huruf tersebut, dan mencari huruf target menggunakan algoritma binary search. Jika huruf target ditemukan, program akan menampilkan indeks dari huruf tersebut dalam kata awal yang dimasukkan pengguna. Jika tidak ditemukan, program akan memberikan pesan bahwa huruf tersebut tidak ditemukan dalam kata yang dimasukkan.

#### Full code Screenshot :
![image](https://github.com/Gustavers/Laporan-praktikum/assets/162097300/6d2d7de1-e7c0-416d-a2e5-582f29273d11)

### 2. Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!

```c++
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isVowel(char c) {
    // Mengubah huruf menjadi huruf kecil 
    c = tolower(c);
    // Memeriksa apakah karakter adalah huruf vokal
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int countVowels(string sentence) {
    int count = 0;
    // Menghitung jumlah huruf vokal 
    for (char c : sentence) {
        if (isVowel(c)) {
            count++;
        }
    }
    return count;
}

int main() {
    string sentence;
    cout << "Masukkan kalimat: ";
    getline(cin, sentence);
    int vowelCount = countVowels(sentence);
    cout << "Jumlah huruf vokal : " << vowelCount << endl;
    return 0;
}

```
#### Output :
![image](https://github.com/Gustavers/Laporan-praktikum/assets/162097300/0a3d14f3-092a-4057-95ff-0f602942c092)

Program diatas dapat menghitung berapa banyak huruf vokal yang ada dalam kalimat yang dimasukkan pengguna. Pertama, program meminta pengguna menggunakan fungsi "getline" untuk memasukkan kalimat melalui input. Setelah mendapatkan kalimat, program memanggil fungsi "countVowels" dengan parameter kalimat yang dimasukkan oleh pengguna. Fungsi "countVowels" akan menggunakan loop "for" untuk mengiterasi setiap karakter dalam kalimat, dan fungsi "isVowel" akan memeriksa apakah karakter tersebut adalah huruf vokal atau tidak. Jika Setelah menghitung jumlah huruf vokal, program mencetak hasilnya ke layar. Fungsi "isVowel" memeriksa apakah sebuah karakter adalah huruf vokal dengan mengubahnya menjadi huruf kecil, lalu memeriksa apakah itu adalah huruf "a", "e", "i", "o", atau "u".

#### Full code screenshot :
![image](https://github.com/Gustavers/Laporan-praktikum/assets/162097300/678fbf71-0496-4791-a4af-a10f1c0d31c3)

### 3. Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!

```c++
#include <iostream>
#include <vector>
using namespace std;

int sequentialSearchCount(vector<int> data, int target) {
    int count = 0;
    for (int num : data) {
        if (num == target) {
            count++;
        }
    }
    return count;
}

int main() {
    vector<int> data = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int target = 4;

    int count = sequentialSearchCount(data, target);

    cout << "Banyaknya angka " << target << " dalam data adalah: " << count << endl;

    return 0;
}

```
#### Output :
![image](https://github.com/Gustavers/Laporan-praktikum/assets/162097300/fe52ec33-0ecb-4edc-aa62-834d01b9eda9)

Program di atas dapat menghitung berapa kali suatu bilangan tertentu muncul dalam suatu vektor.
Pertama, program membuat fungsi "Hitungan Pencarian Berikutnya" dengan dua parameter.
Vektor "data"  berisi angka dan nomor target yang akan dicari.
Fungsi ini menggunakan algoritma pencarian sekuensial (juga dikenal sebagai pencarian sekuensial) untuk menghitung berapa kali angka yang dimaksud muncul dalam vektor data.
Untuk vektor, setiap elemen  diperiksa satu per satu.
Jika elemennya sama dengan angka target, variabel count bertambah satu.
Setelah pencarian selesai, fungsi  mengembalikan nilai 'Jumlah'.
Dalam fungsi "utama", vektor data dimulai pada ukuran tertentu.
Selanjutnya, program memanggil fungsi "Jumlah Pencarian Berikutnya" dengan vektor data dan nomor target sebagai argumen dan menyimpan hasilnya  dalam variabel "Jumlah".
Terakhir, program mencetak nomor target.



#### Full code screenshot :
![image](https://github.com/Gustavers/Laporan-praktikum/assets/162097300/4acb8898-308e-4b2d-a964-e40e62adf62f)

## Kesimpulan
Algoritma pencarian adalah proses untuk menemukan keberadaan atau lokasi suatu nilai dalam suatu himpunan data. Sequential Search merupakan metode sederhana yang memeriksa setiap elemen secara berurutan dari awal hingga akhir himpunan data, cocok digunakan untuk himpunan data kecil atau tidak terurut. Di sisi lain, Binary Search adalah algoritma yang efisien dan hanya berlaku pada himpunan data yang terurut. Dengan membagi himpunan data menjadi dua bagian dan mencari nilai di bagian yang sesuai, Binary Search memiliki kompleksitas waktu yang rendah, membuatnya sangat efisien untuk himpunan data besar. Oleh karena itu, pemilihan antara Sequential Search dan Binary Search harus mempertimbangkan sifat himpunan data dan kebutuhan aplikasi untuk mendapatkan kinerja pencarian yang optimal.



## Referensi
[1] Purbasari, Wika, et al. Algoritma Pemrograman. Edited by Setiya Putra, Yusuf W., and Hanson P. Putro, CV WIDINA MEDIA UTAMA, 2024.

[2] Wahyuni, S. P., Andryana, S., & Rahman, B. (2022). Penggunaan Algoritma Sequential Searching Pada Aplikasi Perpustakaan Berbasis Web , 1(3), 220–225.

[3] Toyib, R., Darnita, Y., & Deva, A. R. (2021). PENERAPAN ALGORITMA BINARY SEARCH PADA APLIKASI E-ORDER. JURNAL MEDIA INFOTAMA, 17(1). https://doi.org/10.37676/jmi.v17i1.1314
