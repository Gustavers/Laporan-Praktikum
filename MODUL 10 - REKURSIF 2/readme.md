# <h1 align="center">Laporan Praktikum Modul Rekursif</h1>
<p align="center">Ahmad Fariz Gustav</p>
<p align="center">2311110012</p>
<p align="center">S1SD-04-A</p>

## Dasar Teori
Rekursif adalah sub program yang memanggil dirinya sendiri selama kondisi pemanggilan dipenuhi. Rekursif umumnya dipakai untuk permasalahan yang memiliki langkah penyelesaian yang terpola atau langkah-langkah yang teratur. Bila ada suatu permasalahan dan sudah diketahui algoritma penyelesaiannya, maka sub program rekursif dapat menjadi pilihan untuk digunakan[1].

**Cara Kerja Rekursif**

Fungsi rekursif bekerja dengan memanggil dirinya sendiri secara berulang hingga mencapai kondisi dasar (base case). Kondisi dasar ini adalah titik henti rekursi dan memastikan bahwa fungsi tidak memanggil dirinya sendiri secara tak terbatas, mencegah stack overflow.

**Jenis-Jenis Rekursif**

Terdapat dua jenis fungsi rekursi:

- Rekursi Langsung (Direct Recursion): Fungsi memanggil dirinya sendiri secara langsung .
- Rekursi Tidak Langsung (Indirect Recursion): Fungsi memanggil dirinya sendiri secara tidak langsung melalui fungsi lain.

**Kelebihan dan Kekurangan Rekursif**

**Kelebihan:**
- Kesederhanaan: Rekursi seringkali menghasilkan kode yang lebih bersih dan mudah dipahami untuk masalah kompleks.
Penyelesaian Masalah yang Alami: Beberapa masalah, seperti traversal pohon atau algoritma Divide and Conquer (misalnya, Merge Sort), lebih mudah diimplementasikan secara rekursif [2].

**Kekurangan:**
- Overhead Memori: Setiap panggilan rekursif menyimpan status fungsi di stack, yang dapat menyebabkan penggunaan memori yang besar dan potensi stack overflow.
- Kinerja: Rekursi dapat lebih lambat dibandingkan iterasi karena overhead pemanggilan fungsi berulang kali [2].
## Guided 
**1. Rekursif Langsung**

Kode Program :
```c++

#include <iostream>
/// Rekursif Langsung
using namespace std;

void countdown(int n) {
    if (n == 0) {
        return;
    }

    cout << n << " ";
    countdown(n-1);
}

int main() {
    cout << "Rekursif Langsung: ";
    countdown(5);
    cout << endl;
    return 0;
}
```
#### Output :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/7d1ce4a3-3937-4d3c-907b-dbbebd6eed83)

**interpretasi hasil :**

**1. Fungsi countdown**
- void countdown(int n): Fungsi ini diberi nama hitungMundur dan menerima argumen bilangan bulat n. Fungsi ini tidak mengembalikan apapun, ditunjukkan oleh tipe pengembalian void.
- if (n == 0) { return; }: Ini adalah kasus dasar dari rekursi. Jika nilai n adalah 0, fungsi diakhiri dengan mengembalikan menggunakan pernyataan return. Ini mencegah rekursi tak terbatas.
- cout << n << " ";: Jika tidak, nilai n saat ini dicetak ke konsol diikuti oleh spasi.
- countdown(n - 1);: Ini adalah panggilan rekursif. Fungsi memanggil dirinya sendiri lagi, meneruskan n - 1 sebagai argumen. Ini secara efektif mengurangi nilai hitung mundur dan mengulangi proses hingga kasus dasar (n == 0) tercapai.

**2. Fungsi main**
- int main(): Ini adalah titik masuk program tempat eksekusi dimulai. Fungsi ini mengembalikan bilangan bulat (biasanya 0 untuk menunjukkan eksekusi berhasil).
- cout << "Hitung Mundur Rekursif Langsung: ";: Baris ini mencetak "Hitung Mundur Rekursif Langsung: " ke konsol, memberi label output sebagai implementasi rekursif langsung.
- countdown(5);: Fungsi hitungMundur dipanggil dengan nilai awal 5, memicu urutan hitung mundur.
- cout << endl;: Baris baru dicetak setelah hitung mundur untuk memindahkan kursor ke baris berikutnya.
- return 0;: Fungsi main mengembalikan 0, menandakan program berhasil diakhiri.

#### Full Code Screenshot :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/291c376b-b7da-4bde-b034-dabbeee51395)

**2. Rekursif Tidak Langsung**

Kode Program :
```c++

#include <iostream>

using namespace std;

void functionB(int n);

void functionA(int n){
    if (n > 0) {
        cout << n << " ";
        functionB(n - 1);
    }
}

void functionB(int n) {
    if (n > 0) {
        cout << n << " ";
        functionA(n / 2);
    }
}

int main() {
    int num = 5;
    cout << "Rekursi Tidak Langsung: ";
    functionA(num);
    return 0;
}
```
#### Output :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/884b78c9-cc82-4f31-a508-9c69c0ad4453)

**interpretasi hasil :**

1. **Deklarasi Fungsi**:
   - `void functionB(int n);` mendeklarasikan fungsi `functionB`, sehingga bisa dipanggil dalam `functionA` meskipun `functionB` didefinisikan setelah `functionA`.
   - `void functionA(int n);` dideklarasikan dan didefinisikan. Fungsi ini memanggil `functionB`.

2. **Definisi `functionA`**:
   - `void functionA(int n) { if (n > 0) { cout << n << " "; functionB(n - 1); } }`
     - Jika `n` lebih besar dari 0, cetak nilai `n` diikuti oleh spasi.
     - Kemudian panggil `functionB` dengan parameter `n - 1`.

3. **Definisi `functionB`**:
   - `void functionB(int n) { if (n > 0) { cout << n << " "; functionA(n / 2); } }`
     - Jika `n` lebih besar dari 0, cetak nilai `n` diikuti oleh spasi.
     - Kemudian panggil `functionA` dengan parameter `n / 2`.

4. **Fungsi `main`**:
   - `int main() { int num = 5; cout << "Rekursi Tidak Langsung: "; functionA(num); return 0; }`
     - Memulai dengan `num` yang bernilai 5.
     - Cetak pesan "Rekursi Tidak Langsung: ".
     - Panggil `functionA` dengan `num` (5).

Berikut adalah bagaimana program berjalan:

- `main` memanggil `functionA(5)`.
- Dalam `functionA(5)`, karena 5 > 0, cetak "5 " dan panggil `functionB(4)`.
- Dalam `functionB(4)`, karena 4 > 0, cetak "4 " dan panggil `functionA(2)` (4 / 2).
- Dalam `functionA(2)`, karena 2 > 0, cetak "2 " dan panggil `functionB(1)` (2 - 1).
- Dalam `functionB(1)`, karena 1 > 0, cetak "1 " dan panggil `functionA(0)` (1 / 2).
- Dalam `functionA(0)`, karena 0 tidak lebih besar dari 0, fungsi berhenti dan kembali.
- `functionB(1)` kembali.
- `functionA(2)` kembali.
- `functionB(4)` kembali.
- `functionA(5)` kembali.
- `main` selesai.

#### Full Code Screenshot :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/3078d145-3534-45d3-b8f3-8120569cbd86)

## Unguided 
### 1. Buatlah sebuah program Rekursif Langsung (Direct Recursion) yang menghitung nilai faktorial dari sebuah inputan bilangan bulat positif!

Kode Program :
```c++
#include <iostream>
/// Rekursif Langsung
using namespace std;

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int number;
    cout << "Masukkan bilangan bulat positif: ";
    cin >> number;

    if (number < 0) {
        cout << "Input tidak valid. Masukkan bilangan bulat positif." << endl;
    } else {
        int result = factorial(number);
        cout << "Faktorial dari " << number << " adalah: " << result << endl;
    }

    return 0;
}
```

#### Output :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/e4be85a3-6ca9-4572-a76f-af3c3ff7984e)


**interpretasi hasil :**

1. **Deklarasi dan Definisi Fungsi `factorial`**:
   - `int factorial(int n) { if (n == 0) { return 1; } return n * factorial(n - 1); }`
     - Fungsi `factorial` menerima satu argumen `n` (sebuah bilangan bulat).
     - Basis kasus: Jika `n` sama dengan 0, fungsi mengembalikan 1. Ini karena faktorial dari 0 (0!) adalah 1.
     - Rekursi: Jika `n` bukan 0, fungsi mengembalikan hasil dari `n` dikalikan dengan `factorial(n - 1)`. Ini mengimplementasikan definisi faktorial `n! = n * (n-1)!`.

2. **Fungsi `main`**:
   - `int main() { int number; cout << "Masukkan bilangan bulat positif: "; cin >> number; ... }`
     - Deklarasi variabel `number` untuk menyimpan input pengguna.
     - Mencetak pesan "Masukkan bilangan bulat positif: " untuk meminta pengguna memasukkan sebuah bilangan bulat positif.
     - Membaca input dari pengguna dan menyimpannya di `number`.

3. **Validasi Input dan Perhitungan Faktorial**:
   - `if (number < 0) { cout << "Input tidak valid. Masukkan bilangan bulat positif." << endl; }`
     - Memeriksa apakah `number` kurang dari 0. Jika ya, mencetak pesan bahwa input tidak valid karena faktorial hanya didefinisikan untuk bilangan bulat positif (termasuk 0).
   - `else { int result = factorial(number); cout << "Faktorial dari " << number << " adalah: " << result << endl; }`
     - Jika `number` tidak kurang dari 0, maka menghitung faktorial dari `number` dengan memanggil fungsi `factorial(number)`.
     - Menyimpan hasil perhitungan dalam variabel `result`.
     - Mencetak hasil faktorial dari `number`.

4. **Pengembalian dari `main`**:
   - `return 0;`: Menandakan bahwa program selesai dengan sukses.

### Contoh Eksekusi

Misalkan pengguna memasukkan `5` sebagai input. Berikut adalah langkah-langkah eksekusi:

- `main` meminta input dan membaca nilai `5`.
- Memanggil `factorial(5)`:
  - `factorial(5)` memanggil `factorial(4)`.
  - `factorial(4)` memanggil `factorial(3)`.
  - `factorial(3)` memanggil `factorial(2)`.
  - `factorial(2)` memanggil `factorial(1)`.
  - `factorial(1)` memanggil `factorial(0)`.
  - `factorial(0)` mengembalikan `1`.
  - `factorial(1)` mengembalikan `1 * 1 = 1`.
  - `factorial(2)` mengembalikan `2 * 1 = 2`.
  - `factorial(3)` mengembalikan `3 * 2 = 6`.
  - `factorial(4)` mengembalikan `4 * 6 = 24`.
  - `factorial(5)` mengembalikan `5 * 24 = 120`.
- `main` mencetak "Faktorial dari 5 adalah: 120".

Output yang dihasilkan adalah:

```
Masukkan bilangan bulat positif: 5
Faktorial dari 5 adalah: 120
```

#### Full Code Screenshot :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/e1567c4d-2d9e-49c5-ba81-4c93df3c65ce)

### 2. Buatlah versi program Rekursif Tidak Langsung (Indirect Recursion) dari soal nomor 1 diatas!

Kode Program :
```c++
#include <iostream>
using namespace std;

int factorialHelper(int n, int result) {
    if (n == 0 || n == 1) {
        return result;
    }
    return factorialHelper(n - 1, n * result);
}

int factorialStart(int n) {
    return factorialHelper(n, 1);
}

int main() {
    int number;
    cout << "Masukkan bilangan bulat positif: ";
    cin >> number;

    if (number < 0) {
        cout << "Input tidak valid. Masukkan bilangan bulat positif." << endl;
    } else {
        int result = factorialStart(number);
        cout << "Faktorial dari " << number << " adalah: " << result << endl;
    }

    return 0;
}
```

#### Output :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/3d2607dd-bbf0-4a7f-9a93-151d2c6bf211)

**interpretasi hasil :**
Kode di atas adalah implementasi dari perhitungan faktorial menggunakan rekursi ekor (tail recursion). Berikut adalah interpretasi rinci dari setiap bagian kode:

### Struktur Kode

1. **Pustaka dan Namespace**:
   ```cpp
   #include <iostream>
   using namespace std;
   ```
   - `#include <iostream>`: Menyertakan pustaka input-output standar untuk memungkinkan penggunaan `cout` dan `cin`.
   - `using namespace std;`: Menggunakan namespace `std` untuk menghindari penulisan `std::` sebelum setiap fungsi pustaka standar.

2. **Fungsi `factorialHelper`**:
   ```cpp
   int factorialHelper(int n, int result) {
       if (n == 0 || n == 1) {
           return result;
       }
       return factorialHelper(n - 1, n * result);
   }
   ```
   - Fungsi ini adalah fungsi rekursi ekor yang digunakan untuk menghitung faktorial dengan parameter `n` (bilangan yang faktorialnya dihitung) dan `result` (akumulator yang menyimpan hasil sementara dari perhitungan faktorial).
   - **Basis Kasus**: 
     - Jika `n` adalah 0 atau 1, fungsi mengembalikan `result`. Ini karena faktorial dari 0 dan 1 adalah 1.
   - **Rekursi**:
     - Jika `n` lebih besar dari 1, fungsi memanggil dirinya sendiri dengan `n-1` dan hasil perkalian `n * result`, memperbarui `result` pada setiap langkah rekursi.

3. **Fungsi `factorialStart`**:
   ```cpp
   int factorialStart(int n) {
       return factorialHelper(n, 1);
   }
   ```
   - Fungsi ini memulai proses perhitungan faktorial dengan memanggil `factorialHelper` dan menginisialisasi `result` dengan 1.
   - Ini adalah fungsi pembantu yang menyederhanakan pemanggilan fungsi rekursif.

4. **Fungsi `main`**:
   ```cpp
   int main() {
       int number;
       cout << "Masukkan bilangan bulat positif: ";
       cin >> number;

       if (number < 0) {
           cout << "Input tidak valid. Masukkan bilangan bulat positif." << endl;
       } else {
           int result = factorialStart(number);
           cout << "Faktorial dari " << number << " adalah: " << result << endl;
       }

       return 0;
   }
   ```
   - Fungsi utama yang menjalankan program:
     - Meminta input dari pengguna untuk memasukkan bilangan bulat positif.
     - Membaca input pengguna dan menyimpannya dalam variabel `number`.
     - Memeriksa apakah `number` kurang dari 0. Jika ya, mencetak pesan kesalahan.
     - Jika `number` tidak negatif (valid), menghitung faktorial dengan memanggil `factorialStart(number)` dan mencetak hasilnya.

### Contoh Eksekusi

Misalkan pengguna memasukkan `5` sebagai input:

1. **Input dan Validasi**:
   - Pengguna memasukkan `5`.
   - Input `5` valid karena tidak kurang dari 0.

2. **Perhitungan Faktorial**:
   - Memanggil `factorialStart(5)`.
   - `factorialStart(5)` memanggil `factorialHelper(5, 1)`.
   - **Dalam `factorialHelper`**:
     - Panggilan pertama: `factorialHelper(5, 1)`:
       - `n` adalah 5, `result` adalah 1.
       - Memanggil `factorialHelper(4, 5 * 1)`.
     - Panggilan kedua: `factorialHelper(4, 5)`:
       - `n` adalah 4, `result` adalah 5.
       - Memanggil `factorialHelper(3, 4 * 5)`.
     - Panggilan ketiga: `factorialHelper(3, 20)`:
       - `n` adalah 3, `result` adalah 20.
       - Memanggil `factorialHelper(2, 3 * 20)`.
     - Panggilan keempat: `factorialHelper(2, 60)`:
       - `n` adalah 2, `result` adalah 60.
       - Memanggil `factorialHelper(1, 2 * 60)`.
     - Panggilan kelima: `factorialHelper(1, 120)`:
       - `n` adalah 1, `result` adalah 120.
       - Basis kasus tercapai, mengembalikan `result` (120).

3. **Output**:
   - `factorialStart(5)` mengembalikan 120.
   - `main` mencetak "Faktorial dari 5 adalah: 120".

Output yang dihasilkan adalah:

```
Masukkan bilangan bulat positif: 5
Faktorial dari 5 adalah: 120
```


#### Full Code Screenshot :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/fa008bec-3a28-4eca-858e-da7fb1721fe4)

## Kesimpulan
Rekursi adalah teknik pemrograman yang memungkinkan sebuah fungsi memanggil dirinya sendiri untuk menyelesaikan masalah yang dapat dipecah menjadi submasalah yang lebih kecil. Dengan basis kasus untuk menghentikan rekursi dan panggilan rekursif untuk mendekati basis kasus, rekursi menawarkan solusi yang lebih sederhana dan alami untuk masalah seperti perhitungan faktorial, traversal pohon, dan algoritma divide and conquer. Meskipun memiliki kelemahan seperti overhead memori dan potensi stack overflow, rekursi ekor dapat mengoptimalkan penggunaan memori. Dalam bahasa C++, rekursi sangat berguna untuk menyederhanakan kode dan membuatnya lebih mudah dipahami, terutama dalam konteks struktur data dan algoritma kompleks.
## Referensi
[1] U. Indahyanti and Y. Rahmawati, “Buku Ajar Algoritma Dan Pemrograman Dalam Bahasa C++”, umsidapress, pp. 1-146, Aug. 2021.

[2] Putra, Muhammad Taufik Dwi, Munawir Munawir, and Ana Rahma Yuniarti. "BELAJAR PEMROGRAMAN LANJUT DENGAN C++." 2023.