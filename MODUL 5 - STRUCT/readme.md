# <h1 align="center">Laporan Praktikum Modul Struct</h1>
<p align="center">Ahmad Fariz Gustav</p>


## Dasar Teori
Variabel adalah suatu entitas dalam pemrograman yang digunakan untuk menyimpan dan merepresentasikan data. Dalam pemrograman, variabel digunakan untuk menampung nilai-nilai yang dapat berubah selama proses eksekusi program. Variabel memiliki nama yang unik yang digunakan untuk mengidentifikasinya dan dapat diakses atau dimodifikasi oleh program sesuai dengan kebutuhan.
### Jenis Variabel
- Variabel Lokal : variabel yang dideklarasikan di dalam suatu blok kode tertentu, seperti di dalam sebuah fungsi.
- Variabel Global : variabel yang dideklarasikan di luar blok kode utama atau di luar semua fungsi.
### Struct
Struct dalam bahasa C++ merupakan struktur data yang memungkinkan terjadinya pembentukan tipe data baru dengan menggabungkan berbagai macam variabel dengan tipe data berbeda yang tersedia dalam C++. Tipe data yang baru, dapat dibentuk di luar tipe data yang sudah ada dengan menggabungkan beberapa tipe data tersebut sesuai dengan kebutuhan program atau aplikasi yang dirancang [1].
### Deklarasi Struct
Untuk mendeklarasikan sebuah struct, Anda menggunakan keyword struct diikuti dengan nama struct dan kurung kurawal {}. Di dalam kurung kurawal, Anda deklarasikan variabel-variabel yang menjadi anggota (member) dari struct tersebut.
contoh :
```c++
struct Mahasiswa {
  std::string nama;
  int nim;
  float ipk;
};
```
### Fitur Struct
- Nested Struct : Struct di dalam struct.
- Array of Struct : Array yang berisi elemen struct.
- Pointer to Struct : Pointer yang menunjuk ke struct.

### Penggunaan Struct
Struct dapat digunakan untuk berbagai keperluan, seperti:
- Menyimpan data yang berkaitan: Seperti pada contoh Mahasiswa, struct bisa digunakan untuk menyimpan data mahasiswa yang saling berkaitan.
- Mengirimkan data sebagai parameter fungsi: Anda bisa mengirimkan struct sebagai parameter fungsi untuk memudahkan transfer data yang kompleks.
- Mengembalikan data dari fungsi: Fungsi dapat mengembalikan struct untuk mengembalikan beberapa nilai sekaligus.
- Membuat array of struct: Anda bisa membuat array of struct untuk menyimpan kumpulan data yang memiliki struktur yang sama.

## Guided 
### 1. Buatlah sebuah struktur dengan nama buku yang berisi judul_buku, pengarang, penerbit, tebal_halaman, harga_buku. Isi dengan nilai kemudian tampilkan.

#### Kode Program :
```c++

#include <iostream>

using namespace std;

// Mendefinisikan struktur buku
struct buku {
    string judulBuku;
    string pengarang;
    string penerbit;
    int tebalHalaman;
    int hargaBuku;
};

int main() {
    // Mendeklarasikan variabel favorit dengan tipe buku
    buku favorit;

    // Mengisi data ke dalam variabel favorit
    favorit.judulBuku = "The Alpha Girl's Guide";
    favorit.pengarang = "Henry Manampiring";
    favorit.penerbit = "Gagas Media";
    favorit.tebalHalaman = 253;
    favorit.hargaBuku = 79000;

    // Menampilkan informasi buku favorit
    cout << "\tBuku Favorit Saya" << endl;
    cout << "\tJudul Buku : " << favorit.judulBuku << endl;
    cout << "\tPengarang : " << favorit.pengarang << endl;
    cout << "\tPenerbit : " << favorit.penerbit << endl;
    cout << "\tTebal Halaman: " << favorit.tebalHalaman << " halaman" << endl;
    cout << "\tHarga Buku : Rp " << favorit.hargaBuku << endl;
 
    return 0;
}
```
#### Output :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/e2667b5c-e7b5-4a26-85ed-64dcc9123432)

Program di atas adalah contoh sederhana penggunaan struct untuk merepresentasikan informasi tentang  buku favorit Anda.
Program ini mendefinisikan struktur yang disebut "Buku" dengan elemen seperti judul buku, penulis, penerbit, berat halaman, dan harga buku.Setelah strukturnya ditentukan, variabel 'favorit' bertipe 'buku' dibuat dan diisi dengan informasi tentang buku favorit yang telah ditentukan sebelumnya.Kemudian,  dengan menggunakan perintah "cout", program akan menampilkan informasi tentang buku favorit Anda di layar. Dengan demikian, program ini membantu menyajikan dan menampilkan informasi tentang buku favorit Anda dalam format yang terstruktur, sehingga memudahkan dalam mengolah dan memahami informasi tersebut.

#### Full Code Screenshot :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/5c0efa31-e9da-429a-a38e-80426bc5ba37)

### 2. Buatlah sebuah struktur dengan skema seperti dibawah, isi dengan nilai kemudian jalankan.
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/7da7e125-1617-4bc6-b6f5-e3e3ee504936)

#### Kode Program :
```c++
#include <iostream>
using namespace std;

struct hewan {
    string namaHewan;
    string jenisKelamin;
    string caraBerkembangbiak;
    string alatPernafasan;
    string tempatHidup;
    bool Karnivora;
};

struct hewanDarat {
    int jumlahKaki;
    bool menyusui;
    string suara;
};

struct hewanLaut {
    string bentukSirip;
    string bentukPertahananDiri;
};

int main() {
    hewanDarat kelinci; // Menggunakan tipe data hewanDarat untuk kelinci
    kelinci.jumlahKaki = 4;
    kelinci.menyusui = true;
    kelinci.suara = "Citcit";

    hewanLaut ikan; // Menggunakan tipe data hewanLaut untuk ikan
    ikan.bentukSirip = "Sirip ekor";
    ikan.bentukPertahananDiri = "Sisik";

    hewan serigala; // Tetap menggunakan tipe data hewan untuk serigala
    serigala.namaHewan = "Serigala";
    serigala.jenisKelamin = "Jantan";
    serigala.caraBerkembangbiak = "Melahirkan";
    serigala.alatPernafasan = "Paru-paru";
    serigala.tempatHidup = "Hutan terbuka";
    serigala.Karnivora = true;

    cout << "\t\tHewan" << endl;
    cout << "\t" << serigala.namaHewan << endl;
    cout << "\tJenis kelamin : " << serigala.jenisKelamin << endl;
    cout << "\tCara berkembangbiak : " << serigala.caraBerkembangbiak << endl;
    cout << "\tAlat pernafasan : " << serigala.alatPernafasan << endl;
    cout << "\tTempat hidup : " << serigala.tempatHidup << endl;
    cout << "\tKarnivora : " << (serigala.Karnivora ? "Yes" : "No") << endl << endl;

    cout << "\t\tHewan Darat" << endl;
    cout << "\tKelinci" << endl;
    cout << "\tJumlah kaki : " << kelinci.jumlahKaki << endl;
    cout << "\tMenyusui : " << (kelinci.menyusui ? "Yes" : "No") << endl;
    cout << "\tSuara : " << kelinci.suara << endl << endl;

    cout << "\t\tHewan Laut" << endl;
    cout << "\tIkan" << endl;
    cout << "\tBentuk sirip : " << ikan.bentukSirip << endl;
    cout << "\tBentuk pertahanan diri: " << ikan.bentukPertahananDiri << endl;

    return 0;
}
```
#### Output :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/4c353c2c-3078-472e-83f6-135d513c395a)

Program C++ di atas menggunakan struktur  untuk merepresentasikan informasi tentang berbagai jenis hewan, baik  darat maupun  laut.
Struktur "Hewan" digunakan untuk menyimpan informasi umum tentang hewan, seperti: Nama hewan, jenis kelamin, cara reproduksi, sistem pernapasan, tempat tinggal, dan apakah hewan tersebut karnivora. Selain itu, terdapat struktur tambahan "Hewan Darat" untuk menyimpan informasi spesifik tentang hewan darat, seperti: Seperti jumlah kaki, daya serapnya, suara yang dihasilkan, dan bahkan struktur “Hewan Laut” yang menyimpan informasi spesifik tentang hewan laut. Bentuk sirip, bentuk pertahanan diri, dll. Dengan menggunakan struktur ini, program ini memungkinkan pengguna untuk mewakili dan menampilkan informasi tentang berbagai aspekhewan dalam format  terstruktur.

#### Full Code Screenshot :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/6722ae5c-9fa8-441a-bd50-dad937f7e311)

## Unguided 
### 1. Modifikasi tugas guided pertama, sehingga setiap item yang terdapat pada struct buku berupa array yang berukuran 5, isi dengan data kemudian tampilkan

Kode Program :
```c++
#include <iostream>
#include <string>
using namespace std;

const int MAX_BOOKS = 5;

struct buku {
    string judul_buku;
    string pengarang;
    string penerbit;
    string tebal_halaman;
    double harga_buku;
};

int main() {
    // Mendeklarasikan Array Dari Struct Buku
    buku arrayBuku[MAX_BOOKS];

    // Mengisi Data Array Dari Struct Buku
    arrayBuku[0].judul_buku = "Laskar Pelangi";
    arrayBuku[0].pengarang = "Andrea Hirata";
    arrayBuku[0].penerbit = "Bandung Pustaka";
    arrayBuku[0].tebal_halaman = "529 halaman";
    arrayBuku[0].harga_buku = 52000;

    arrayBuku[1].judul_buku = "Dilan 1990";
    arrayBuku[1].pengarang = "Pidi Baiq";
    arrayBuku[1].penerbit = "Pastel Books";
    arrayBuku[1].tebal_halaman = "332 Halaman";
    arrayBuku[1].harga_buku = 53000;

    arrayBuku[2].judul_buku = "Negeri Lima Menara";
    arrayBuku[2].pengarang = "Ahmad Fuadi";
    arrayBuku[2].penerbit = "Gramedia Pustaka Utama";
    arrayBuku[2].tebal_halaman = "368 Halaman";
    arrayBuku[2].harga_buku = 73000;

    arrayBuku[3].judul_buku = "Sapiens Riwayat Singkat Umat Manusia";
    arrayBuku[3].pengarang = "Yuval Noah Harari";
    arrayBuku[3].penerbit = "PT Gramedia Pustaka Utama";
    arrayBuku[3].tebal_halaman = "464 Halaman";
    arrayBuku[3].harga_buku = 96000;

    arrayBuku[4].judul_buku = "Alkimia Cinta";
    arrayBuku[4].pengarang = "Paulo Coelho";
    arrayBuku[4].penerbit = "FPT Gramedia Pustaka Utama";
    arrayBuku[4].tebal_halaman = "224 Halaman";
    arrayBuku[4].harga_buku = 47000;

    // Menampilkan Data Array Dari Struct Buku
    for (int i = 0; i < MAX_BOOKS; ++i) {
        cout << "Buku Ke-" << i + 1 << endl;
        cout << "Judul Buku    : " << arrayBuku[i].judul_buku << endl;
        cout << "Pengarang     : " << arrayBuku[i].pengarang << endl;
        cout << "Penerbit      : " << arrayBuku[i].penerbit << endl;
        cout << "Tebal Halaman : " << arrayBuku[i].tebal_halaman << endl;
        cout << "Harga Buku    : Rp" << arrayBuku[i].harga_buku << endl;
        cout << endl;
    }
    return 0;
}
```

#### Output :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/141bed2b-166b-4dd0-bce0-0bb30c306443)

Program di atas merupakan contoh penggunaan sstruct. Program ini memiliki struct “buku” yang digunakan untuk merepresentasikan informasi tentang  buku, seperti:
Judul buku, pengarang, penerbit, berat halaman, dan harga buku. Selanjutnya, program mendeklarasikan  array  struktur 'buku' bernama 'array buku'. Ukuran array ini adalah "MAX_BOOKS", yang dalam hal ini disetel ke 5. Program kemudian menulis data ke struktur array  menggunakan indeks array. Setiap elemen array menyimpan informasi tentang  buku yang telah ditentukan sebelumnya. Program kemudian menggunakan perulangan "for" untuk menampilkan informasi tentang buku yang disimpan dalam larik, dari buku pertama hingga buku terakhir. Informasi tentang setiap buku ditampilkan di layar dalam format yang sesuai.

#### Full code Screenshot :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/53016f04-6746-4610-b9a7-fb33e6a23357)

### 2. Apa yang terjadi jika deklarasi variabel struct yang dibuat pada tugas guided I berjenis Array . Bagaimana cara mengisi data dan menampilkannya

```c++
#include <iostream>
#include <string>
using namespace std;

const int MAX_BOOKS = 5;

struct Buku {
    string judul_buku;
    string pengarang;
    string penerbit;
    string tebal_halaman;
    double harga_buku;
};

int main() {
    // Deklarasi Array Struct Buku
    Buku arrayBuku[MAX_BOOKS];

    // Menampilkan Data Awal (Kosong)
    cout << "Data Awal (Kosong)" << endl;
    for (int i = 0; i < MAX_BOOKS; ++i) {
        cout << "Buku Ke-" << i + 1 << " =>" << endl;
        cout << "Judul Buku    : " << arrayBuku[i].judul_buku << endl;
        cout << "Pengarang     : " << arrayBuku[i].pengarang << endl;
        cout << "Penerbit      : " << arrayBuku[i].penerbit << endl;
        cout << "Tebal Halaman : " << arrayBuku[i].tebal_halaman << endl;
        cout << "Harga Buku    : Rp" << arrayBuku[i].harga_buku << endl;
        cout << endl;
    }

    // Mengisi Data Array Menggunakan For
    cout << "\n\nMengisi Data Buku" << endl;
    for (int i = 0; i < MAX_BOOKS; ++i) {
        cout << "Buku Ke-" << i + 1 << " =>" << endl;
        cout << "Masukkan Judul Buku    : ";
        getline(cin, arrayBuku[i].judul_buku);
        cout << "Masukkan Pengarang     : ";
        getline(cin, arrayBuku[i].pengarang);
        cout << "Masukkan Penerbit      : ";
        getline(cin, arrayBuku[i].penerbit);
        cout << "Masukkan Tebal Halaman : ";
        getline(cin, arrayBuku[i].tebal_halaman);
        cout << "Masukkan Harga Buku    : ";
        cin >> arrayBuku[i].harga_buku;
        cin.ignore();
        cout << endl;
    }

    // Menampilkan Data Array Setelah Diisi
    cout << "\n\nData Buku Setelah Diisi" << endl;
    for (int i = 0; i < MAX_BOOKS; ++i) {
        cout << "Buku Ke-" << i + 1 << " =>" << endl;
        cout << "Judul Buku    : " << arrayBuku[i].judul_buku << endl;
        cout << "Pengarang     : " << arrayBuku[i].pengarang << endl;
        cout << "Penerbit      : " << arrayBuku[i].penerbit << endl;
        cout << "Tebal Halaman : " << arrayBuku[i].tebal_halaman << endl;
        cout << "Harga Buku    : Rp" << arrayBuku[i].harga_buku << endl;
        cout << endl;
    }

    return 0;
}
```
#### Output :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/b1b27e16-5643-46ad-88aa-7c937e226bf7)

Kode di atas menggunakan struktur (struct) dalam bahasa C++ untuk merepresentasikan informasi tentang sebuah buku. Program ini mengizinkan pengguna untuk mengisi data buku ke dalam array dari struktur Buku. Awalnya, program menampilkan data awal dari array arrayBuku, yang dalam kasus ini masih kosong. Kemudian, program meminta pengguna untuk mengisi data buku ke dalam array tersebut menggunakan perulangan for dan fungsi getline() untuk membaca input string dari pengguna. Setelah semua data dimasukkan, program menampilkan kembali data buku yang telah diisi ke layar. Dengan demikian, program ini memberikan pengguna kontrol penuh untuk mengisi dan menampilkan informasi buku dalam format yang terstruktur.
#### Full code screenshot :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/a528c7d3-436b-4cd8-ae8c-b78983ef33f8)

## Kesimpulan
variabel adalah entitas dalam pemrograman yang digunakan untuk menyimpan dan merepresentasikan data. Jenis variabel dapat dibagi menjadi variabel lokal, yang dideklarasikan di dalam suatu blok kode tertentu, dan variabel global, yang dideklarasikan di luar blok kode utama atau di luar semua fungsi. Struct dalam bahasa C++ merupakan struktur data yang memungkinkan pembentukan tipe data baru dengan menggabungkan berbagai macam variabel dengan tipe data berbeda. Deklarasi struct dilakukan dengan menggunakan keyword struct diikuti dengan nama struct dan kurung kurawal {} yang berisi deklarasi variabel-variabel anggota dari struct tersebut.
Fitur-fitur dari struct mencakup kemampuan untuk memiliki struct bertingkat (nested struct), array of struct, serta pointer to struct. Penggunaan struct sangat bermanfaat dalam menyimpan data yang berkaitan, mengirimkan data sebagai parameter fungsi, mengembalikan data dari fungsi, dan membuat array of struct untuk menyimpan kumpulan data dengan struktur yang sama. Struct merupakan konsep penting dalam C++ untuk mengelompokkan data yang berkaitan. Ini membantu Anda membuat program yang lebih terorganisir, mudah dibaca, dan efisien dalam pengelolaan data.

## Referensi
[1] Putra. M. T. D., Munawir, Yuniarti. R. H., (2023). _Belajar Pemrograman Lanjut Dengan C++_. Widia Media  Utama. 