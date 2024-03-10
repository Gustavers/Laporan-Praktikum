# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Ahmad Fariz Gustav</p>


## Tipe Data Primitif
Tipe data primitif adalah tipe data dasar yang disediakan oleh bahasa pemrograman untuk merepresentasikan nilai dasar atau elemen-elemen dasar dalam program. Tipe data primitif digunakan untuk menyimpan nilai sederhana seperti bilangan bulat, bilangan riil, karakter, dan sebagainya. Setiap bahasa pemrograman memiliki tipe data primitifnya sendiri dengan ukuran dan ciri-ciri tertentu.

- **Integer** dalam C++, seperti dalam matematika, adalah angka-angka berikut:- 6728, -67, 0, 78, 36782, +763. Perhatikan dua aturan berikut:
1. Integer positif tidak memerlukan tanda +.
2. Koma tidak dipakai pada sebuah integer Ingat bahwa dalam C++, koma dipakai untuk memisahkan tiap item pada sebuah daftar atau senarai. Jadi, 34,56 akan diinterpretasikan sebagai dua integer: 34 dan 56.[1]

- **Float** atau disebut juga floating point atau real number adalah tipe data angka yang memiliki bagian desimal di akhir angka. Jika ingin menyimpan angka berkoma, kita bisa menggunakan tipe data ini. contohnya  1.4, 2.6, 3.04, dan sebagainya.

- Tipe data **char** merupakan tipe data integral yang terkecil. la umumnya dipakai untuk merepresentasikan karakter, yaitu huruf, dijit, dan simbol spesial. Jadi, tipe data char dapat merepresentasikan setiap kunci pada papanketik Anda. Ketika menggunakan tipe data char, Anda perlu mengapit setiap karakter dengan sepasang tanda kutip tunggal.[1]

- Tipe data **Boolean** hanya memiliki dua nilai: true dan false. Selain itu, true dan false dikenal pula dengan nilai logikal (Boolean). Tujuan utama dari tipe data ini adalah untuk memanipulasi ekspresi logikal (Boolean), Ekspresi logikal akan didiskusikan secara detil pada Bab 3. Dalam C++, bool, true, dan false adalah kata kunci.[1]

## Tipe Data Abstrak
Tipe data abstrak atau yang biasa disebut Abstrak Data Tipe(ADT) adalah tipe data yang dibuat oleh programer itu sendiri. Pada tipe data abstrak bisa berisi lebih darti satu tipe data, jadi nilainya bisa beragam. Fitur Class
adalah fitur Object Oriented Program(OPP) pada bahasa C++ yang mirip dengan fitur data structures Struct pada bahasa C. Keduanya berfungsi untuk membungkus tipe data di dalamnya sebagai anggota.Struct dan Class adalah pada akses defaultnya dimana Struct bersifat public dan Class
bersifat private.

## Tipe Data Koleksi 
Tipe data koleksi (Collection Data Type) merupakan tipe data yang digunakan untuk
mengelompokkan dan menyimpan beberapa nilai atau objek secara bersamaan. Jadi Tipe
data koleksi dapat menyimpan, mengelola, dan mengakses data dengan cara yang terstruktur. Ada beberapa tipe data koleksi yang sering digunakan dalam pemrograman di antaranya adalah:
- **Array** adalah suatu struktur yang terdiri dari sejumlah elemen yang memiliki tipe data yang sama. Elemen-elemen array tersusun secara sekuensial dalam memori komputer. Semua elemem array bertipe sama. Array cocok untuk organisasi kumpulan data homogen yang ukuran atau jumlah elemen maksimumnya telah diketahui dari awal. Homogen adalah bahwa setiap elemen dari sebuah array tertentu haruslah mempunyai tipe data yang sama.[2]
- **Vector** adalah struktur data dinamis yang disediakan oleh C++ Standard Template Library (STL). Ini adalah implementasi dari array dinamis yang mengelola alokasi memori dan penyimpanan secara otomatis, memungkinkan programmer untuk dengan mudah menambah atau mengurangi ukuran vector selama runtime.
- **Map** adalah struktur data yang menyimpan pasangan key-value, dimana setiap key memiliki value yang terkait dengannya. Map biasanya diimplementasikan sebagai tabel hash atau pohon pencarian biner dalam berbagai bahasa pemrograman.

## Guided 
### 1. Tipe Data Primitif
![Screenshot (1)](https://github.com/Gustavers/Laporan-praktikum/assets/162097300/5b35b0a0-962c-4984-bd72-ee9e6a9a85b2)

```c++
#include <iostream>
using namespace std;
 main()
 {   
     char op;
     float num1, num2;
     cin >> op;
     cin >> num1 >> num2;
     switch (op)
     {
     case '+':
         cout << num1 + num2;
         break;
     case '-' :
         cout << num1 - num2;
         break;
     case '*' :
         cout << num1 * num2;
         break;
     case '/' :
         cout << num1 / num2;
         break;
     default:
         cout << "Error operator is not correct";
     }
     return 0;
 }

```
#### Output :
![image](https://github.com/Gustavers/Laporan-praktikum/assets/162097300/876b5350-e886-4f67-8a5b-2e0267235f53)

Program dimulai dengan deklarasi sebuah variabel char 'op' untuk menyimpan operator, serta dua variabel float 'num1' dan 'num2' untuk menyimpan dua bilangan yang akan dioperasikan. disini pengguna diminta untuk input operator dan dua bilangan melalui input. Selanjutnya, program menggunakan struktur switch untuk memeriksa nilai variabel 'op' dan menjalankan operasi aritmetika sesuai dengan kasus yang diminta (penjumlahan, pengurangan, perkalian, atau pembagian). Jika operator yang dimasukkan tidak sesuai dengan empat operasi tersebut, program akan mencetak pesan "error operator is not correct".

### 2. Tipe data abstrak
![Screenshot (2)](https://github.com/Gustavers/Laporan-praktikum/assets/162097300/a9191d62-9091-4c7e-979e-d82d862623f5)

```c++
#include <stdio.h>
struct Mahasiswa
{
    const char *name;
    const char *address;
    int age;
};
int main()
{
    struct Mahasiswa mhs1, mhs2;
    mhs1.name = "Dian";
    mhs1.address = "Mataram";
    mhs1.age = 22;
    mhs2.name = "Bambang";
    mhs2.address = "Surabaya";
    mhs2.age = 23;
    printf("## Mahasiswa 1 ##\n");
    printf("Nama: %s\n", mhs1.name);
    printf("Alamat: %s\n", mhs1.address);
    printf("Umur: %d\n", mhs1.age);
    printf("## Mahasiswa 2 ##\n");
    printf("Nama: %s\n", mhs2.name);
    printf("Alamat: %s\n", mhs2.address);
    printf("Umur: %d\n", mhs2.age);
    return 0;
}
```
#### Output :

![image](https://github.com/Gustavers/Laporan-praktikum/assets/162097300/024ca324-e4ae-485c-93ad-374a5da4be5a)

Program diatas menggunakan fungsi struct "Mahasiswa" yang memiliki tiga anggota yaitu "name" untuk nama mahasiswa, "address" untuk alamat mahasiswa, dan "age" untuk umur mahasiswa. Dalam fungsi main() terdapat dua variabel struct Mahasiswa, yaitu mhs1 dan mhs2, dideklarasikan dan diinisialisasi dengan data masing-masing mahasiswa. Setelah itu, program mencetak informasi tentang kedua mahasiswa yang mencakup nama, alamat, dan umur, menggunakan fungsi printf(). Hasilnya adalah output yang menampilkan data mahasiswa mhs1 dan mhs2 secara terstruktur. Program ini memberikan contoh cara menggunakan struktur untuk mengorganisir dan menyimpan data terkait dalam bahasa pemrograman C.

### 3. Tipe Data Koleksi
![Screenshot (4)](https://github.com/Gustavers/Laporan-praktikum/assets/162097300/52665d72-2e95-4008-8be6-a6f4a70bdc11)

```C++
#include <iostream>
using namespace std;
int main()
{
    //deklasrasi dan inisialisasi array
    int nilai[5];
    nilai[0] = 23;
    nilai[1] = 50;
    nilai[2] = 34;
    nilai[3] = 78;
    nilai[4] = 90;

    //mencetak array
    cout << "isi array pertama :"<< nilai[0] << endl;
    cout << "isi array kedua :" << nilai[1] << endl;
    cout << "isi array ketiga :"  << nilai[2] << endl;
    cout << "isi array keempat :"  << nilai[3] << endl;
    cout << "isi array kelima :" << nilai[4] << endl;
    return 0;
}
```
#### Output :
![image](https://github.com/Gustavers/Laporan-praktikum/assets/162097300/9d69762f-762d-4ba3-af55-985de84ce7a6)

Program di atas adalah contoh penggunaan Array dengan nama "nilai" yang dideklarasikan sebagai array integer dengan panjang 5 dan kemudian diinisialisasi dengan nilai-nilai tertentu. Setelah itu, program mencetak isi array tersebut menggunakan perintah cout. Setiap elemen array dicetak secara terpisah dengan menyertakan indeksnya, dimulai dari indeks 0 hingga indeks 4. Hasilnya adalah output yang menampilkan nilai dari setiap elemen array "nilai". Program ini memberikan gambaran sederhana tentang deklarasi, inisialisasi, dan penggunaan array dalam bahasa C++ untuk menyimpan dan mengakses sejumlah nilai terkait.
## Unguided 

### 1. Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas ,Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!

![Screenshot (6)](https://github.com/Gustavers/Laporan-praktikum/assets/162097300/d3023973-045c-489c-ad33-ea0ddd6beb0c)
```c++
#include <iostream>
using namespace std;
// Fungsi untuk menghitung volume balok
int hitungVolumeBalok(int panjang, int lebar, int tinggi) {
    return panjang * lebar * tinggi;
}
int main() {
    // Variabel untuk panjang, lebar, dan tinggi balok
    int panjang, lebar, tinggi;
    // input nilai panjang
    cout << "Masukkan panjang balok: ";
    cin >> panjang;
    // input nilai lebar
    cout << "Masukkan lebar balok: ";
    cin >> lebar;
    // input nilai tinggi
    cout << "Masukkan tinggi balok: ";
    cin >> tinggi;

    // Memanggil fungsi hitungVolumeBalok dan menampilkan hasilnya
    int volume = hitungVolumeBalok(panjang, lebar, tinggi);
    cout << "Volume balok : " << volume;
    return 0;
}
```

#### Output :
![image](https://github.com/Gustavers/Laporan-praktikum/assets/162097300/0fbfec36-feb8-4caf-959d-da1e1f9d274d)

kode diatas merupakan contoh penggunaan data primitif yaitu integer untuk menghitung volume balok berdasarkan panjang, lebar, dan tinggi yang dimasukkan oleh pengguna melalui input. Program dimulai dengan mendeklarasikan fungsi hitungVolumeBalok, yang terdapat tiga parameter (panjang, lebar, tinggi) dan mengembalikan hasil perkalian ketiga parameter tersebut. Dalam fungsi main, variabel panjang, lebar, dan tinggi dideklarasikan sebagai integer untuk menyimpan input pengguna. Pengguna diminta untuk memasukkan nilai panjang, lebar, dan tinggi melalui cin. Selanjutnya, fungsi hitungVolumeBalok dipanggil dengan menggunakan input pengguna sebagai argumen, dan hasilnya disimpan dalam variabel volume. Hasil volume kemudian dicetak menggunakan cout. Program ini memberikan contoh sederhana tentang penggunaan tipe data primitif untuk menghitung volume balok.

### 2. Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya
Class dan struct adalah dua konsep dasar dalam pemrograman berorientasi objek yang digunakan untuk mengatur data dan fungsi ke dalam satu unit yang disebut sebagai "tipe data". Meskipun keduanya memiliki kesamaan, terdapat beberapa perbedaan utama dalam cara mereka digunakan dan perilaku default mereka.
1. **Class** berfungsi sebagai model untuk membuat objek dan mendefinisikan tipe data baru dengan anggota dan perilaku (metode). Anggota class default tetap anonim, dan konsep pewarisan class memungkinkan class baru mewarisi anggota dari class yang sudah ada. Selain itu, class dapat memiliki konstruktor dan destruktor untuk memulai dan membersihkan sumber daya.

#### contoh program :
![Screenshot (7)](https://github.com/Gustavers/Laporan-praktikum/assets/162097300/9e83d9f7-678a-4f85-bf62-e8ceb10ffd0d)
```c++
#include <iostream>
using namespace std;
// Definisi class
class Mahasiswa {
public:
    // Data member
    string nama;
    int usia;
    // Fungsi anggota untuk menampilkan informasi mahasiswa
    void tampilkanInfo() {
    cout << "Nama: " << nama << "\nUsia: " << usia << " tahun\n";
    }
};
int main() {
    // Membuat objek dari class Mahasiswa
    Mahasiswa mahasiswa1;
    // Mengisi data objek
    mahasiswa1.nama = "Gustav";
    mahasiswa1.usia = 19;
    // Memanggil fungsi anggota
    mahasiswa1.tampilkanInfo();
    return 0;
}
```
#### Output :
![image](https://github.com/Gustavers/Laporan-praktikum/assets/162097300/c4796831-5a54-4816-b371-ed00644c8598)

2. **Struct**, di sisi lain, digunakan untuk membuat tipe data yang juga dapat menyimpan data terkait, tetapi umumnya digunakan untuk kasus sederhana tanpa tingkah laku kompleks. Anggota struct defaultnya bersifat public, yang berarti bahwa mereka dapat diakses langsung dari luar struct. Struct tidak mendukung konsep pewarisan dan memiliki constructor secara default yang dihasilkan oleh kompilator.

#### contoh program :
![Screenshot (8)](https://github.com/Gustavers/Laporan-praktikum/assets/162097300/0d97727d-baee-4634-9313-ce3556c8b23a)
```c++
#include <iostream>
using namespace std;
struct Mahasiswa {
    // Data member
    string nama;
    int usia;
};
int main() {
    // Membuat objek dari struct Mahasiswa
    Mahasiswa mahasiswa1;
    // Mengisi data objek
    mahasiswa1.nama = "Gustav";
    mahasiswa1.usia = 19;
    // Menampilkan informasi langsung
    cout << "Nama: " << mahasiswa1.nama << "\nUsia: " << mahasiswa1.usia << " tahun\n";
    return 0;
}
```
#### Output :
![image](https://github.com/Gustavers/Laporan-praktikum/assets/162097300/f61058ee-0200-452d-b5b8-9575ade42332)

### 3. Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map
![Screenshot (9)](https://github.com/Gustavers/Laporan-praktikum/assets/162097300/f07423a8-baf2-489b-b510-69a59738adc7)
```c++
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

```
#### Output :
![image](https://github.com/Gustavers/Laporan-praktikum/assets/162097300/7c9114fe-c4fe-4316-b10e-457f5911fbf3)

Program di atas struktur data map dari STL (Standard Template Library). Map digunakan untuk menyimpan pasangan key-value, di mana key bertipe string dan value bertipe int. Pertama, program membuat objek map bernama "nilai" dan menambahkan beberapa pasangan key-value yang mewakili nilai-nilai mahasiswa. Lalu program mengakses nilai dengan key tertentu dan mencetaknya ke layar. Kemudian, program melakukan pencarian key "bunga" dalam map menggunakan metode find(). Jika key tersebut ditemukan, nilai yang sesuai dicetak, namun karena key "bunga" tidak ada dalam map, program mencetak pesan "bunga tidak ditemukan". Program ini memberikan contoh penggunaan map untuk menyimpan dan mengakses data dengan key dan value. perbedaan map dengan array salah satunya adalah array menggunakan indeks numerik sebagai alat akses langsung ke elemen-elemen. Indeks dimulai dari 0 dan berlanjut secara terurut. sedangkan map menggunakan key sebagai alat akses ke nilai yang sesuai. Key dapat berupa tipe data apa pun yang mendukung operasi perbandingan dan memiliki sifat unik.

## Kesimpulan

Kesimpulannya tipe data primitif adalah tipe data dasar yang disediakan oleh bahasa pemrograman untuk merepresentasikan nilai dasar seperti integer, float, char, dan boolean. Masing-masing tipe data primitif memiliki fungsi dan karakteristiknya sendiri. Di sisi lain, tipe data abstrak atau ADT adalah tipe data yang dibuat oleh programer dengan lebih banyak fleksibilitas, dapat berisi lebih dari satu tipe data, dan sering digunakan dalam pemrograman berorientasi objek dengan menggunakan konsep Class dan Struct. Selain itu, tipe data koleksi seperti array, vector, dan map digunakan untuk mengelompokkan dan menyimpan data secara terstruktur, dengan masing-masing memiliki kegunaan khusus dalam mengelola dan mengakses data. Secara keseluruhan, pemahaman yang baik tentang berbagai tipe data ini penting dalam pengembangan perangkat lunak untuk memilih struktur data yang sesuai dengan kebutuhan dan karakteristik program yang sedang dibangun.

## Referensi

[1] Sianipar, R.H. (2014). _Pemrograman c++ untuk pemula_. Informatika. 

[2] Pratama, M. A. (2020). _Sttuktur data array dua dimensi pada pemrograman C++_.