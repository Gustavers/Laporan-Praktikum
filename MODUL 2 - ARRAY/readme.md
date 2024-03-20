# <h1 align="center">Laporan Praktikum Modul Array</h1>
<p align="center">Ahmad Fariz Gustav</p>


## Dasar Teori
Array adalah struktur data yang digunakan untuk menyimpan sekumpulan nilai yang serupa dalam satu variabel. Array memungkinkan pengelompokan dan pengaksesan elemen-elemen data menggunakan indeks numerik. Setiap elemen dalam array memiliki indeks yang dimulai dari 0 dan berlanjut secara berurutan hingga jumlah elemen dalam array dikurangi 1.
Array dalam C++ memiliki tipe data yang sama untuk semua elemennya. Ini berarti semua elemen dalam array harus memiliki tipe data yang identik, baik itu tipe data primitif seperti int, float, char, dll., maupun tipe data objek.
1. **Array satu dimensi** adalah kumpulan elemen-elemen identik yang tersusun dalam satu baris, tetapi isi dari elemen tersebut boleh berbeda.  Dapat disebut juga dengan istilah vektor yang menggambarkan data dalam suatu urutan[1].Contohnya, sebuah array satu dimensi yang berisi bilangan bulat {2, 3, 4, 5, 6} memiliki lima elemen dan indeksnya dimulai dari 0. Indeks 0 merujuk pada elemen pertama, indeks 1 merujuk pada elemen kedua, dan seterusnya hingga indeks 4 merujuk pada elemen kelima.


    **Contoh :**
    ``` c++
    #include <iostream>
    using namespace std;
    int main() {
    int arr[5] = {7,6,5,8,9,}; //deklarasi array
    cout<< arr[1] << endl;
    cout<< arr[4];
    }
    ```

    **Output** :

    ![image](https://github.com/Gustavers/Laporan-praktikum/assets/162097300/9fa39086-272e-4312-8b1e-752edb63aa35)

2. **Array Dua Dimensi** yang sering digambarkan sebagai sebuah matriks merupakan perluasan dari sebuah array satu dimensi. Jika array satu dimensi hanya terdiri dari sebuah baris dengan beberapa kolom elemen maka array dua dimensi terdiri dari beberapa baris dan beberapa kolom elemen yang bertipe sama. Pendeklarasian array dua dimensi hampir sama dengan pendeklarasian array satu dimensi, kecuali bahwa array dua dimensi terdapat dua jumlah elemen array yang terdapat di dalam kurung siku dan keduanya boleh tidak sama [1].

    **Contoh** :
    ``` c++
    #include <iostream>
    using namespace std;
    int main() {
    int matriks[2][3] = {{1, 2, 3}, {4, 5, 6}};
    // Menampilkan nilai matriks
    cout << "Isi matriks:" << endl;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
    }
    ```
    **Output** :

    ![image](https://github.com/Gustavers/Laporan-praktikum/assets/162097300/d6f8f31d-ebba-4e0e-86b4-a808c653bebd)

3. **Array Multidimensi** Sebenarnya array ini tidak terlalu sering dipakai seperti halnya array satu dimensi, dua dimensi, dan tiga dimensi. Array banyak dimensi ini pada dasarnya sama dengan array sebelumnya kecuali pada jumlah dimensinya[1].

    **Contoh :** 
    ```c++
    #include <iostream>
    using namespace std;
    int main() {
    int arr[2][2][3] = {{{2, 8, 7}, {6, 5, 1}}, {{8,
    5, 2}, {9, 2 ,7}}};
    for (int i=0; i<2; i++) {
    for(int j=0; j<2; j++) {
    for(int k=0; k<3; k++) {
    cout<< arr[i][j][k] << ends << " ";
    };
    cout<< endl;
    };
    cout<< endl;
    };
    }
    ```
    **Output :**

    ![image](https://github.com/Gustavers/Laporan-praktikum/assets/162097300/da34e1dc-229f-4bc2-8150-1b39becf38cd)
4. **Karakteristik Array** 
    - Mempunyai batasan dari pemesanan alokasi memori (bersifat statis) [1].
    -  Mempunyai tipe data sama (bersifat homogen) [1]. 
    -  Dapat diakses secara acak [1].

## Guided 
### 1. Membuat Array 3 Dimensi
![image](https://github.com/Gustavers/Laporan-praktikum/assets/162097300/b8b40b78-ec53-45ec-ad56-91b152c359e9)

```c++
#include <iostream>
using namespace std;
//program input array 3 dimensi
int main()
{
    //deklarasi array
    int arr[2][3][3];
    //input elemen
    for (int x=0; x<2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "input array["<< x <<"] [" << y << "] [" << z << "]=";
                cin >> arr[x] [y] [z];
            }
        }
        cout << endl;
    }
    //output array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout  << "Data Array  [" << x << "] [" << y << "] [" << z << "]=" << arr[x] [y] [z] << endl;
            }
        }
    }
    cout << endl;
    //tampilan array
    for (int x = 0; x<2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << arr[x] [y] [z] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }
}
```
#### Output :
![image](https://github.com/Gustavers/Laporan-praktikum/assets/162097300/0ced675c-3ceb-4966-9673-40bdb57f2ffb)

Program meminta pengguna untuk memasukkan nilai-nilai ke dalam array tiga dimensi. Hal ini dilakukan dengan menggunakan tiga perulangan bersarang yang mengiterasi melalui setiap elemen array. Pengguna diminta untuk memasukkan nilai elemen, dan nilai-nilai tersebut disimpan di dalam array.Setelah semua nilai elemen dimasukkan, program mencoba untuk melakukan output dengan mengakses dan menampilkan nilai-nilai array tersebut. Ini dilakukan dengan menggunakan tiga perulangan bersarang lagi untuk mengiterasi melalui setiap elemen array dan menampilkannya ke layar. Program menampilkan semua nilai elemen array dalam format matriks 3 dimensi. Setiap lapisan array dipisahkan oleh baris kosong. Di dalam setiap lapisan, nilai-nilai array ditampilkan dalam format baris dan kolom.

### 2. Nilai Maksimal Pada Array
![image](https://github.com/Gustavers/Laporan-praktikum/assets/162097300/926abf42-63ae-450f-ba52-6389b2b361bc)

```c++
#include <iostream>
using namespace std;
int main()
{
    //deklarasi variabel
    int maks, a, i = 1, lokasi = 0;
    // masukkan data
    cout << "masukkan panjang array :";
    cin >> a;
    int array [a];
    cout << " masukkan " << a << " angka\n";
    for (i = 0; i < a ; i++)
    {
        cout << "Array ke-" << (i) <<  ": ";
        cin >> array[i]; 
    }
    maks = array [0];
    for (i = 0; i < a; i++)
    {
        if (array[i] > maks)
        {
            maks = array[i];
            lokasi = i;
        }
    }
    cout << "Nilai maksimum adalah " << maks << " berada di array ke " << lokasi << endl;
}
```
#### Output :

![image](https://github.com/Gustavers/Laporan-praktikum/assets/162097300/1c43691f-2bb1-4516-bc8c-8c98b46a8ccc)

Program diatas bertujuan untuk mencari nilai maksimum dari sejumlah bilangan yang dimasukkan pengguna ke dalam sebuah array. Pertama, program meminta pengguna untuk memasukkan panjang array, kemudian menginisialisasi sebuah array dengan panjang tersebut. Selanjutnya, program meminta pengguna untuk memasukkan sejumlah bilangan sesuai dengan panjang array yang telah ditentukan. Setelah semua bilangan dimasukkan, program akan mencari nilai maksimum dari array tersebut dan mencatat lokasinya

## Unguided 

### 1. Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user
![image](https://github.com/Gustavers/Laporan-praktikum/assets/162097300/0b48d650-6f43-4d32-9327-73dfd800e454)

```c++
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
```

#### Output :
![image](https://github.com/Gustavers/Laporan-praktikum/assets/162097300/6bde7ad4-f60b-4c00-9bfd-107ed8b28a71)

Kode diatas menggunakan vektor untuk memisahkan nomor ganjil dan genap dari sejumlah nomor yang dimasukkan user. Langkah awal program meminta pengguna untuk memasukkan sepuluh angka dan menyimpannya dalam sebuah vektor bernama data_array. Setelah semua nomor di input, program menampilkan seluruh nomor yang telah dimasukkan oleh user. Selanjutnya, program memisahkan nomor-nomor tersebut menjadi dua vektor terpisah, yaitu even_numbers untuk nomor genap dan odd_numbers untuk nomor ganjil, dengan melakukan iterasi pada data_array dan memeriksa sisa bagi nomor dengan 2. Setelah pemisahan selesai, program menampilkan nomor genap dan ganjil yang telah dipisahkan dalam masing-masing vektor.

#### Full code Screenshot :
![image](https://github.com/Gustavers/Laporan-praktikum/assets/162097300/c6eabcab-3bff-47fa-be12-8c8336a4a218)

### 2. Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user

```c++
#include <iostream>
using namespace std;

int main() {
    int x_size, y_size, z_size;

    // input ukuran array
    cout << "Masukkan ukuran array (x y z): ";
    cin >> x_size >> y_size >> z_size;
    int arr[x_size][y_size][z_size];

    // Input elemen array
    for (int x = 0; x < x_size; x++) {
        for (int y = 0; y < y_size; y++) {
            for (int z = 0; z < z_size; z++) {
                cout << "Input array[" << x << "][" << y << "][" << z << "]: ";
                cin >> arr[x][y][z];
            }
        }
    }
    cout << endl;

    // Output array
    for (int x = 0; x < x_size; x++) {
        for (int y = 0; y < y_size; y++) {
            for (int z = 0; z < z_size; z++) {
                cout << "Data Array [" << x << "][" << y << "][" << z << "]: " << arr[x][y][z] << endl;
            }
        }
    }
    cout << endl;

    // Tampilan array
    for (int x = 0; x < x_size; x++) {
        for (int y = 0; y < y_size; y++) {
            for (int z = 0; z < z_size; z++) {
                cout << arr[x][y][z] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
```
#### Output :
![image](https://github.com/Gustavers/Laporan-praktikum/assets/162097300/b12b35f8-4f0d-4ba7-8920-b02edfad8dd2)

Kode di atas bertujuan untuk membuat dan mengisi array tiga dimensi dengan ukuran yang ditentukan oleh user. Program ini kemudian menampilkan isi array tersebut dalam tiga dimensi. program meminta pengguna untuk memasukkan ukuran array dalam tiga dimensi (x, y, z). Setelah itu, program membuat array dengan ukuran yang dimasukkan oleh user. Selanjutnya, program meminta user untuk input nilai-nilai elemen array dengan melakukan iterasi melalui setiap elemen array menggunakan tiga perulangan bersarang. Setelah semua elemen array di input, program menampilkan isi array dengan mencetak setiap elemen array beserta indeksnya (x, y, z) menggunakan tiga perulangan bersarang. Terakhir, program menampilkan isi array dalam format tiga dimensi.

#### Full code screenshot :
![image](https://github.com/Gustavers/Laporan-praktikum/assets/162097300/d3c5d894-65c2-412e-964b-dbf17b0394b5)

### 3. Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input yang dimasukan oleh user

```c++
#include <iostream>
using namespace std;

int main() {
    // Deklarasi variabel
    int panjang_array, maksimum, minimum, total = 0;

    // input panjang array
    cout << "Masukkan panjang array: ";
    cin >> panjang_array;

    // Membuat array 
    int array[panjang_array];

    // input array
    for (int i = 0; i < panjang_array; i++) {
        cout << "Array ke-" << (i + 1) << ": ";
        cin >> array[i];
    }

    // nilai maksimum dan minimum
    maksimum = minimum = array[0];
    for (int i = 1; i < panjang_array; i++) {
        if (array[i] > maksimum) {
            maksimum = array[i];
        }
        if (array[i] < minimum) {
            minimum = array[i];
        }
        total += array[i];
    }

    // Menghitung nilai rata-rata
    float rata_rata = static_cast<float>(total) / panjang_array;

    // Menampilkan hasil
    cout << "Nilai maksimum: " << maksimum << endl;
    cout << "Nilai minimum: " << minimum << endl;
    cout << "Nilai rata-rata: " << rata_rata << endl;

    return 0;
}

```
#### Output :
![image](https://github.com/Gustavers/Laporan-praktikum/assets/162097300/29c485dd-582e-447b-839c-f15dafa8cc47)

Program diatas untuk menghitung nilai maksimum, minimum, dan rata-rata dari sejumlah bilangan yang dimasukkan pengguna ke dalam sebuah array. Pertama, program meminta user untuk input panjang array. Selanjutnya, program membuat sebuah array dengan panjang tersebut dan meminta user untuk memasukkan sejumlah bilangan sesuai dengan panjang array yang telah ditetapkan. Setelah semua bilangan dimasukkan, program melakukan iterasi melalui array tersebut untuk mencari nilai maksimum, minimum, dan menghitung total dari semua elemen array. Nilai maksimum dan minimum diupdate sesuai dengan kondisi dalam perulangan, sementara total diakumulasikan dari semua elemen array. Setelah nilai maksimum, minimum, dan total didapatkan, program menghitung nilai rata-rata dengan membagi total dengan panjang array menggunakan tipe data float untuk mendapatkan hasil yang tepat.

#### Full code screenshot :
![image](https://github.com/Gustavers/Laporan-praktikum/assets/162097300/1c4587dd-aed8-42d1-a8fe-b5643e635c81)

## Kesimpulan
Array adalah struktur data yang digunakan untuk menyimpan sekumpulan nilai yang serupa dalam satu variabel, memungkinkan pengelompokan dan pengaksesan elemen-elemen data menggunakan indeks numerik yang dimulai dari 0. Setiap elemen dalam array harus memiliki tipe data yang identik, baik itu tipe data primitif seperti int, float, char, dll., maupun tipe data objek. Array satu dimensi adalah kumpulan elemen-elemen yang tersusun dalam satu baris, sementara array dua dimensi adalah perluasan dari array satu dimensi, di mana elemen-elemen disusun dalam bentuk matriks dengan beberapa baris dan beberapa kolom elemen yang bertipe sama. Pendeklarasian array dua dimensi hampir sama dengan pendeklarasian array satu dimensi, kecuali bahwa array dua dimensi memiliki dua jumlah elemen array di dalam kurung siku dan keduanya boleh tidak sama. Array multidimensi memiliki lebih dari dua dimensi, namun jarang digunakan karena kompleksitasnya yang tinggi dan batasan pada pemesanan alokasi memori, dengan sifat-sifat seperti memiliki tipe data yang sama (homogen), dapat diakses secara acak, dan mempunyai batasan dari pemesanan alokasi memori (bersifat statis).


## Referensi

[1] Pratama, M. A. (2020). STRUKTUR DATA ARRAY DUA DIMENSI  PADA PEMROGRAMAN C++. https://doi.org/10.31219/osf.io/vyech