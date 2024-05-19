# <h1 align="center">Laporan Praktikum Modul Priority Queue and Heaps</h1>
<p align="center">Ahmad Fariz Gustav</p>
<p align="center">2311110012</p>
<p align="center">S1SD-04-A</p>

## Dasar Teori
Priority Queue adalah suatu bentuk struktur data yang berbasiskan struktur Queue pada umumnya. Pada priority Queue, terdapat salah satu bentuk implementasi yaitu implementasi menggunakan struktur data heaps. Dalam implementasi ini ada 3 pokok atribut yaitu heaps, comparator, dan last. Dengan menggunakan fasilitas heap ini kita bisa melakukan insert atau remove elemen dalam kompleksitas waktu logaritmik. Pada priority Queue ini, secara keseluruhan akan dibentuk sebuah pohon biner yang seimbang. Dalam pembuatan pohon biner ini diusahakan ketinggian yang terbentuk adalah minimum. Keminimuman tinggi pohon inilah yang menyebabkan kompleksitas waktu dalam memanipulasi daun menjadi fungsi logaritmik[1].
Priority Queue adalah struktur data abstrak yang memungkinkan penyimpanan dan pengambilan elemen berdasarkan prioritasnya. Elemen dengan prioritas tertinggi diakses dan dihapus terlebih dahulu. Heap (tumpukan) adalah salah satu implementasi populer dari antrian prioritas [2].

**Heap adalah struktur data pohon biner lengkap yang memenuhi dua properti:**
- Heap Max: Nilai pada setiap node tidak boleh lebih kecil dari nilai anak-anaknya.
- Heap Min: Nilai pada setiap node tidak boleh lebih besar dari nilai anak-anaknya.
Dalam heap max, elemen dengan prioritas tertinggi terletak di root (puncak) pohon. Heap min, di sisi lain, memiliki elemen dengan prioritas terendah di root.

**Operasi Dasar pada Antrian Prioritas**

- Insert(x): Memasukkan elemen baru x ke dalam antrian prioritas.
- ExtractMax(): Mengambil dan menghapus elemen dengan prioritas tertinggi dari antrian prioritas.
- DecreaseKey(i, newPriority): Menurunkan prioritas elemen pada indeks i ke nilai baru newPriority.
- IncreaseKey(i, newPriority): Menaikkan prioritas elemen pada indeks i ke nilai baru newPriority.
- PeekMax(): Mengembalikan elemen dengan prioritas tertinggi tanpa menghapusnya.

**Kelebihan Priority Queue :**

- Efisiensi : Priority queue memungkinkan akses dan penghapusan elemen dengan prioritas tertinggi dengan efisiensi waktu O(log n), di mana n adalah jumlah elemen dalam antrian.
- Fleksibilitas : Priority queue dapat digunakan untuk menyimpan elemen dengan berbagai jenis prioritas.
- Kemudahan Penggunaan : Adanya kelas std::priority_queue yang mudah digunakan untuk mengimplementasikan priority queue.

**Kekurangan Priority Queue :**
- Kompleksitas : Implementasi priority queue lebih kompleks dibandingkan array dan list.
- Penggunaan Memori : Priority queue umumnya membutuhkan lebih banyak memori dibandingkan array dan list.

## Guided 
Kode Program :
```c++
#include <iostream>
#include <algorithm>

int H[50];
int heapSize = -1;

int parent(int i) {
    return(i - 1) / 2;
}

int leftChild(int i) {
    return ((2 * i) + 1);
}

int rightChild(int i) {
    return ((2 * i) + 2);
}

void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        std::swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapSize && H[l] > H[maxIndex]) {
        maxIndex = 1;
    }
    int r = rightChild(i);
    if (r <= heapSize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        std::swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}

int extractMax() {
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

void changerPriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() {
    return H[0];
}

void remove (int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

int main() {
    insert(67);
    insert(26);
    insert(54);
    insert(38);
    insert(19);
    insert(27);
    insert(35);
    insert(41);
    insert(17);
    insert(32);

    std::cout << "Priority Queue : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Node With Maximum Priority : " << extractMax() << "\n";

    std::cout << "Priority Queue After Extracting Maximum : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    changerPriority(5, 47);
    std::cout << "Priority Queue After Priority Change : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    remove(5);
    std::cout << "Priority Queue After Removing The Element : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    return 0;
}
```
#### Output :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/78f009fa-dd36-486b-8033-12434344e8b9)

**interpretasi hasil :**

**Variabel Global**

- `H`: Array integer berukuran 50 untuk merepresentasikan heap maksimum. Heap diimplementasikan menggunakan pendekatan berbasis array.
- `heapSize`: Variabel integer untuk melacak jumlah elemen saat ini dalam heap (awalnya -1).

**Heap Utility Function**

- `parent(int i)`: Menghitung indeks simpul induk untuk simpul `i` tertentu dalam representasi pohon biner dari heap.
- `leftChild(int i)`: Menghitung indeks simpul anak kiri untuk simpul `i` tertentu.
- `rightChild(int i)`: Menghitung indeks simpul anak kanan untuk simpul `i` tertentu.

**Heap Maintenance Function**

- `shiftUp(int i)`: Memastikan properti max-heap dipertahankan dengan menukar elemen ke atas jika simpul anak memiliki nilai lebih tinggi daripada induknya. Ini digunakan saat elemen baru dimasukkan.
- `shiftDown(int i)`: Memastikan properti max-heap dipertahankan dengan menukar elemen ke bawah jika simpul induk memiliki nilai lebih rendah daripada salah satu anaknya. Ini digunakan saat elemen root (nilai maksimum) diekstrak atau saat prioritas elemen diubah.

**Heap Operation**

- `insert(int p)`: Memasukkan elemen baru `p` ke dalam heap, mempertahankan properti max-heap menggunakan `shiftUp`.
- `extractMax()`: Mengekstrak elemen dengan prioritas tertinggi (nilai maksimum) dari heap dan mengembalikannya. Ini juga mengatur ulang heap menggunakan `shiftDown` untuk mempertahankan properti max-heap dengan elemen yang tersisa.
- `changerPriority(int i, int p)`: Mengubah prioritas elemen pada indeks `i` ke nilai baru `p`. Kemudian menyesuaikan struktur heap menggunakan `shiftUp` atau `shiftDown` tergantung pada apakah prioritas baru lebih tinggi atau lebih rendah.
- `getMax()`: Cukup mengembalikan elemen dengan prioritas tertinggi (nilai maksimum) dari root heap tanpa menghapusnya.
- `remove(int i)`: Menghapus elemen pada indeks `i` dari heap. Ini dicapai dengan menyetel nilai elemen ke nilai yang lebih tinggi daripada elemen yang mungkin (`getMax() + 1`), kemudian melakukan `shiftUp` untuk memindahkannya ke root (di mana ia menjadi maksimum), dan akhirnya memanggil `extractMax` untuk menghapusnya.

**Main Function**

1. Memasukkan serangkaian integer (67, 26, 54, 38, 19, 27, 35, 41, 17, 32) ke dalam heap, mendemonstrasikan `insert`.
2. Mencetak status awal antrian prioritas (heap).
3. Mengekstrak elemen maksimum menggunakan `extractMax` dan mencetaknya.
4. Mencetak heap setelah mengekstrak elemen maksimum.
5. Mengubah prioritas elemen pada indeks 5 (yang mungkin 27 atau 35 tergantung pada urutan penyisipan) menjadi 47 menggunakan `changerPriority`.
6. Mencetak heap setelah mengubah prioritas.
7. Menghapus elemen pada indeks 5 menggunakan `remove`.
8. Mencetak status akhir heap setelah menghapus elemen.


#### Full Code Screenshot :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/1bfa29ea-5879-4a69-af23-8b0cfc92a3fd)

## Unguided 
### 1. Modifikasi guided diatas yang mana heap dikonstruksi secara manual berdasarkan user.

Kode Program :
```c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept> // Tambahkan Header Berikut Untuk std::runtime_error

class Heap {
private:
    std::vector<int> elements;
    int heapSize;

    int parent(int i) const {
        return (i - 1) / 2;
    }

    int leftChild(int i) const {
        return (2 * i) + 1;
    }

    int rightChild(int i) const {
        return (2 * i) + 2;
    }

    void shiftUp(int i) {
        while (i > 0 && elements[parent(i)] < elements[i]) {
            std::swap(elements[parent(i)], elements[i]);
            i = parent(i);
        }
    }

    void shiftDown(int i) {
        int maxIndex = i;
        int l = leftChild(i);
        if (l < heapSize && elements[l] > elements[maxIndex]) {
            maxIndex = l;
        }
        int r = rightChild(i);
        if (r < heapSize && elements[r] > elements[maxIndex]) {
            maxIndex = r;
        }
        if (i != maxIndex) {
            std::swap(elements[i], elements[maxIndex]);
            shiftDown(maxIndex);
        }
    }

public:
    Heap() : heapSize(-1) {}

    void insert(int priority) {
        heapSize++;
        elements.push_back(priority);
        shiftUp(heapSize);
    }

    int ambilMaks() {
        if (heapSize < 0) {
            throw std::runtime_error("Heap Kosong");
        }
        int hasil = elements[0];
        elements[0] = elements[heapSize];
        heapSize--;
        shiftDown(0);
        return hasil;
    }

    void ubahPrioritas(int i, int prioritasBaru) {
        int prioritasLama = elements[i];
        elements[i] = prioritasBaru;
        if (prioritasBaru > prioritasLama) {
            shiftUp(i);
        } else {
            shiftDown(i);
        }
    }

    int dapatMaks() const {
        if (heapSize < 0) {
            throw std::runtime_error("Heap Kosong");
        }
        return elements[0];
    }

    void hapus(int i) {
        if (i < 0 || i > heapSize) {
            throw std::runtime_error("Indeks Tidak Valid");
        }
        elements[i] = dapatMaks() + 1;
        shiftUp(i);
        ambilMaks();
    }

    // Menambahkan Fungsi Untuk Mendapatkan Ukuran Heap
    int ukuran() const {
        return heapSize + 1;
    }

    // Menambahkan Fungsi Untuk Mendapatkan Elemen Heap
    const std::vector<int>& dapatElemen() const {
        return elements;
    }
};

int main() {
    Heap heap;
    heap.insert(67);
    heap.insert(26);
    heap.insert(54);
    heap.insert(38);
    heap.insert(19);
    heap.insert(27);
    heap.insert(35);
    heap.insert(41);
    heap.insert(17);
    heap.insert(32);

    std::cout << "Antrian Prioritas : ";
    for (int i = 0; i < heap.ukuran(); ++i) {
        std::cout << heap.dapatElemen()[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Node Dengan Prioritas Tertinggi : " << heap.ambilMaks() << "\n";

    std::cout << "Antrian Prioritas Setelah Mengambil Prioritas Tertinggi : ";
    for (int i = 0; i < heap.ukuran(); ++i) {
        std::cout << heap.dapatElemen()[i] << " ";
    }
    std::cout << "\n";

    heap.ubahPrioritas(5, 47);
    std::cout << "Antrian Prioritas Setelah Mengubah Prioritas : ";
    for (int i = 0; i < heap.ukuran(); ++i) {
        std::cout << heap.dapatElemen()[i] << " ";
    }
    std::cout << "\n";

    heap.hapus(5);
    std::cout << "Antrian Prioritas Setelah Menghapus Elemen Pada Indeks Ke-5 : ";
    for (int i = 0; i < heap.ukuran(); ++i) {
        std::cout << heap.dapatElemen()[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
```

#### Output :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/0483ed1d-4eac-4287-ab2b-5a40d6728fcf)

**Class Heap**

- Class `Heap` merepresentasikan struktur heap (tumpukan prioritas).
- Atribut private:
    - `elements`: Vektor bilangan bulat untuk menyimpan elemen-elemen dalam heap.
    - `heapSize`: Variabel integer untuk melacak jumlah elemen saat ini dalam heap.
- Fungsi private:
    - `parent(int i)`: Menghitung indeks induk dari sebuah elemen pada indeks `i`.
    - `leftChild(int i)`: Menghitung indeks anak kiri dari sebuah elemen pada indeks `i`.
    - `rightChild(int i)`: Menghitung indeks anak kanan dari sebuah elemen pada indeks `i`.
    - `shiftUp(int i)`: Fungsi untuk memastikan properti max-heap terjaga dengan menukar elemen ke atas jika elemen anak memiliki nilai lebih tinggi daripada induknya.
    - `shiftDown(int i)`: Fungsi untuk memastikan properti max-heap terjaga dengan menukar elemen ke bawah jika elemen induk memiliki nilai lebih rendah daripada salah satu anaknya.
- Fungsi public:
    - `Heap()`: Konstruktor yang menginisialisasi `heapSize` menjadi -1.
    - `insert(int priority)`: Memasukkan elemen baru dengan prioritas tertentu (`priority`) ke dalam heap.
    - `ambilMaks()`: Mengekstrak elemen dengan prioritas tertinggi (nilai maksimum) dari heap dan mengembalikannya. Menangani kasus heap kosong dengan melempar `std::runtime_error`.
    - `ubahPrioritas(int i, int prioritasBaru)`: Mengubah prioritas elemen pada indeks `i` menjadi `prioritasBaru`. Melakukan `shiftUp` jika prioritas baru lebih tinggi, atau `shiftDown` jika prioritas baru lebih rendah.
    - `dapatMaks() const`: Mengembalikan elemen dengan prioritas tertinggi (nilai maksimum) dari heap tanpa menghapusnya. Menangani kasus heap kosong dengan melempar `std::runtime_error`.
    - `hapus(int i)`: Menghapus elemen pada indeks `i` dari heap. Menangani kasus indeks tidak valid dengan melempar `std::runtime_error`.
    - **Tambahan:**
        - `ukuran() const`: Mengembalikan ukuran heap (jumlah elemen + 1).
        - `dapatElemen() const`: Mengembalikan referensi ke vektor `elements` yang berisi elemen-elemen heap.

**Main Function**

1. Membentuk objek `heap` dari kelas `Heap`.
2. Memasukkan beberapa elemen dengan prioritas berbeda ke dalam heap menggunakan `insert`.
3. Mencetak isi heap saat ini.
4. Mengambil elemen dengan prioritas tertinggi dan mencetaknya menggunakan `ambilMaks`.
5. Mencetak isi heap setelah pengambilan elemen maksimum.
6. Mengubah prioritas elemen pada indeks ke-5 menjadi nilai baru menggunakan `ubahPrioritas`.
7. Mencetak isi heap setelah perubahan prioritas.
8. Menghapus elemen pada indeks ke-5 dari heap menggunakan `hapus`.
9. Mencetak isi heap setelah penghapusan elemen.



#### Full code Screenshot :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/0483ed1d-4eac-4287-ab2b-5a40d6728fcf)

## Kesimpulan
Priority Queue adalah struktur data abstrak yang memungkinkan elemen diproses berdasarkan prioritas, di mana elemen dengan prioritas tertinggi diproses lebih dahulu. Implementasi efisien dari priority queue dapat dilakukan menggunakan heap, yang merupakan pohon biner lengkap dengan properti heap yang memastikan elemen maksimum (max-heap) atau minimum (min-heap) selalu berada di akar. Dalam C++, heap dapat diimplementasikan menggunakan array, di mana operasi utama seperti insert dan extract-max dilakukan dengan menjaga properti heap melalui proses heapify. Implementasi ini memberikan efisiensi waktu \(O(\log n)\) untuk operasi utama, menjadikannya pilihan yang optimal untuk berbagai aplikasi yang membutuhkan pengelolaan elemen berdasarkan prioritas.

## Referensi
[1] Nurcholis, A., Batara, S., & Octamanullah, M. Penerapan struktur data Heap Priority Queue pada algoritma
Djikstra untuk mendapatkan kompleksitas O((n + m)log n), 2020.

[2] Wulandari, C. A., Raharjo, S., & Setiawan, D. Implementasi Priority Queue Berbasis Min-Heap untuk Optimasi Algoritma Huffman Coding. Jurnal Sains dan Teknologi Komputer, 2023.
