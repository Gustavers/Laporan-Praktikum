# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Ahmad Fariz Gustav</p>


## Tipe Data Primitif
Tipe data primitif adalah tipe data dasar yang disediakan oleh bahasa pemrograman untuk merepresentasikan nilai dasar atau elemen-elemen dasar dalam program. Tipe data primitif digunakan untuk menyimpan nilai sederhana seperti bilangan bulat, bilangan riil, karakter, dan sebagainya. Setiap bahasa pemrograman memiliki tipe data primitifnya sendiri dengan ukuran dan ciri-ciri tertentu.

- Int atau integer adalah tipe data yang nilainya terdiri dari angka bulat. Tipe data ini hanya bisa menyimpan angka bulat saja tanpa pecahan (desimal). Nilainya bisa positif maupun negatif seperti 1, 2, 3 dan sebagainya

- Float atau disebut juga floating point atau real number adalah tipe data angka yang memiliki bagian desimal di akhir angka. Jika ingin menyimpan angka berkoma, kita bisa menggunakan tipe data ini. contohnya  1.4, 2.6, 3.04, dan sebagainya.

- Char adalah tipe data yang digunakan untuk menyimpan satu karakter saja. Dan penulisannya harus diapit oleh tanda petik tunggal

- Boolean adalah tipe data yang hanya memiliki 2 pilihan nilai, yaitu true dan false.

## Tipe Data Abstrak
Tipe data abstrak atau yang biasa disebut Abstrak Data Tipe(ADT) adalah tipe data yang dibuat oleh programer itu sendiri. Pada tipe data abstrak bisa berisi lebih darti satu tipe data, jadi nilainya bisa beragam. Fitur Class
adalah fitur Object Oriented Program(OPP) pada bahasa C++ yang mirip dengan fitur data structures Struct pada bahasa C. Keduanya berfungsi untuk membungkus tipe data di dalamnya sebagai anggota.Struct dan Class adalah pada akses defaultnya dimana Struct bersifat public dan Class
bersifat private.

## Tipe Data Koleksi 
Tipe data koleksi (Collection Data Type) merupakan tipe data yang digunakan untuk
mengelompokkan dan menyimpan beberapa nilai atau objek secara bersamaan. Jadi Tipe
data koleksi dapat menyimpan, mengelola, dan mengakses data dengan cara yang terstruktur. Ada beberapa tipe data koleksi yang sering digunakan dalam pemrograman di antaranya adalah:
- Array adalah struktur data yang menyimpan elemen-elemen dengan tipe data yang sama dalam urutan terindeks. Setiap elemen dalam array dapat diakses menggunakan indeks atau posisi tertentu. Array digunakan untuk menyimpan dan mengelola sejumlah besar data dengan cara yang efisien dan terstruktur.
- Vector adalah struktur data dinamis yang disediakan oleh C++ Standard Template Library (STL). Ini adalah implementasi dari array dinamis yang mengelola alokasi memori dan penyimpanan secara otomatis, memungkinkan programmer untuk dengan mudah menambah atau mengurangi ukuran vector selama runtime.
- Map adalah struktur data yang menyimpan pasangan key-value, dimana setiap key memiliki value yang terkait dengannya. Map biasanya diimplementasikan sebagai tabel hash atau pohon pencarian biner dalam berbagai bahasa pemrograman.

## Guided 
### 1. Tipe Data Primitif
![Screenshot (1)](https://github.com/Gustavers/MODUL-1-TIPE-DATA/assets/162097300/93c8e447-d259-4c2c-b59d-507908010cd4)

Program dimulai dengan deklarasi sebuah variabel char 'op' untuk menyimpan operator, serta dua variabel float 'num1' dan 'num2' untuk menyimpan dua bilangan yang akan dioperasikan. disini pengguna diminta untuk input operator dan dua bilangan melalui input. Selanjutnya, program menggunakan struktur switch untuk memeriksa nilai variabel 'op' dan menjalankan operasi aritmetika sesuai dengan kasus yang diminta (penjumlahan, pengurangan, perkalian, atau pembagian). Jika operator yang dimasukkan tidak sesuai dengan empat operasi tersebut, program akan mencetak pesan "error operator is not correct".

### 2. Tipe data abstrak
![Screenshot (2)](https://github.com/Gustavers/MODUL-1-TIPE-DATA/assets/162097300/348248f9-2dfa-43dd-8d53-b28ff361b5f4)
Program diatas menggunakan fungsi struct "Mahasiswa" yang memiliki tiga anggota yaitu "name" untuk nama mahasiswa, "address" untuk alamat mahasiswa, dan "age" untuk umur mahasiswa. Dalam fungsi main() terdapat dua variabel struct Mahasiswa, yaitu mhs1 dan mhs2, dideklarasikan dan diinisialisasi dengan data masing-masing mahasiswa. Setelah itu, program mencetak informasi tentang kedua mahasiswa yang mencakup nama, alamat, dan umur, menggunakan fungsi printf(). Hasilnya adalah output yang menampilkan data mahasiswa mhs1 dan mhs2 secara terstruktur. Program ini memberikan contoh cara menggunakan struktur untuk mengorganisir dan menyimpan data terkait dalam bahasa pemrograman C.

### 3. Tipe Data Koleksi
![Screenshot (4)](https://github.com/Gustavers/MODUL-1-TIPE-DATA/assets/162097300/3a20f1f2-c2da-4631-bf23-c39870df9514)
Program di atas adalah contoh penggunaan Array dengan nama "nilai" yang dideklarasikan sebagai array integer dengan panjang 5 dan kemudian diinisialisasi dengan nilai-nilai tertentu. Setelah itu, program mencetak isi array tersebut menggunakan perintah cout. Setiap elemen array dicetak secara terpisah dengan menyertakan indeksnya, dimulai dari indeks 0 hingga indeks 4. Hasilnya adalah output yang menampilkan nilai dari setiap elemen array "nilai". Program ini memberikan gambaran sederhana tentang deklarasi, inisialisasi, dan penggunaan array dalam bahasa C++ untuk menyimpan dan mengakses sejumlah nilai terkait.
## Unguided 

### 1. Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas ,Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!

![Screenshot (6)](https://github.com/Gustavers/MODUL-1-TIPE-DATA/assets/162097300/94488813-e113-49b9-92fb-2c30009e301e)
kode diatas merupakan contoh penggunaan data primitif yaitu integer untuk menghitung volume balok berdasarkan panjang, lebar, dan tinggi yang dimasukkan oleh pengguna melalui input. Program dimulai dengan mendeklarasikan fungsi hitungVolumeBalok, yang terdapat tiga parameter (panjang, lebar, tinggi) dan mengembalikan hasil perkalian ketiga parameter tersebut. Dalam fungsi main, variabel panjang, lebar, dan tinggi dideklarasikan sebagai integer untuk menyimpan input pengguna. Pengguna diminta untuk memasukkan nilai panjang, lebar, dan tinggi melalui cin. Selanjutnya, fungsi hitungVolumeBalok dipanggil dengan menggunakan input pengguna sebagai argumen, dan hasilnya disimpan dalam variabel volume. Hasil volume kemudian dicetak menggunakan cout. Program ini memberikan contoh sederhana tentang penggunaan tipe data primitif untuk menghitung volume balok.

### 2. Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya
Class dan struct adalah dua konsep dasar dalam pemrograman berorientasi objek yang digunakan untuk mengatur data dan fungsi ke dalam satu unit yang disebut sebagai "tipe data". Meskipun keduanya memiliki kesamaan, terdapat beberapa perbedaan utama dalam cara mereka digunakan dan perilaku default mereka.
1. Class berfungsi sebagai model untuk membuat objek dan mendefinisikan tipe data baru dengan anggota dan perilaku (metode). Anggota class default tetap anonim, dan konsep pewarisan class memungkinkan class baru mewarisi anggota dari class yang sudah ada. Selain itu, class dapat memiliki konstruktor dan destruktor untuk memulai dan membersihkan sumber daya.

#### contoh program :
![Screenshot (7)](https://github.com/Gustavers/MODUL-1-TIPE-DATA/assets/162097300/e8e1361e-e779-459b-aab7-d5adc64915c5)

2. Struct, di sisi lain, digunakan untuk membuat tipe data yang juga dapat menyimpan data terkait, tetapi umumnya digunakan untuk kasus sederhana tanpa tingkah laku kompleks. Anggota struct defaultnya bersifat public, yang berarti bahwa mereka dapat diakses langsung dari luar struct. Struct tidak mendukung konsep pewarisan dan memiliki constructor secara default yang dihasilkan oleh kompilator.

#### contoh program :
![Screenshot (8)](https://github.com/Gustavers/MODUL-1-TIPE-DATA/assets/162097300/b3d0f968-4212-46fd-86ab-bc186152b676)

### Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map
![Screenshot (9)](https://github.com/Gustavers/MODUL-1-TIPE-DATA/assets/162097300/6a3b0225-ff98-4a4d-852d-b76cc1670669)
Program di atas struktur data map dari STL (Standard Template Library). Map digunakan untuk menyimpan pasangan key-value, di mana key bertipe string dan value bertipe int. Pertama, program membuat objek map bernama "nilai" dan menambahkan beberapa pasangan key-value yang mewakili nilai-nilai mahasiswa. Lalu program mengakses nilai dengan key tertentu dan mencetaknya ke layar. Kemudian, program melakukan pencarian key "bunga" dalam map menggunakan metode find(). Jika key tersebut ditemukan, nilai yang sesuai dicetak, namun karena key "bunga" tidak ada dalam map, program mencetak pesan "bunga tidak ditemukan". Program ini memberikan contoh penggunaan map untuk menyimpan dan mengakses data dengan key dan value. perbedaan map dengan array salah satunya adalah array menggunakan indeks numerik sebagai alat akses langsung ke elemen-elemen. Indeks dimulai dari 0 dan berlanjut secara terurut. sedangkan map menggunakan key sebagai alat akses ke nilai yang sesuai. Key dapat berupa tipe data apa pun yang mendukung operasi perbandingan dan memiliki sifat unik.
## Kesimpulan
kesimpulannya tipe data primitif adalah tipe data dasar yang disediakan oleh bahasa pemrograman untuk merepresentasikan nilai dasar seperti integer, float, char, dan boolean. Masing-masing tipe data primitif memiliki fungsi dan karakteristiknya sendiri. Di sisi lain, tipe data abstrak atau ADT adalah tipe data yang dibuat oleh programer dengan lebih banyak fleksibilitas, dapat berisi lebih dari satu tipe data, dan sering digunakan dalam pemrograman berorientasi objek dengan menggunakan konsep Class dan Struct. Selain itu, tipe data koleksi seperti array, vector, dan map digunakan untuk mengelompokkan dan menyimpan data secara terstruktur, dengan masing-masing memiliki kegunaan khusus dalam mengelola dan mengakses data. Secara keseluruhan, pemahaman yang baik tentang berbagai tipe data ini penting dalam pengembangan perangkat lunak untuk memilih struktur data yang sesuai dengan kebutuhan dan karakteristik program yang sedang dibangun.