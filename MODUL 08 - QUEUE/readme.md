# <h1 align="center">Laporan Praktikum Modul Queue</h1>
<p align="center">Ahmad Fariz Gustav</p>


## Dasar Teori
Queue adalah struktur data abstrak yang berisi kumpulan elemen. Antrian menerapkan mekanisme FIFO yaitu elemen yang dimasukkan terlebih dahulu juga dihapus terlebih dahulu. Dengan kata lain, elemen yang terakhir ditambahkan akan dihapus terlebih dahulu dalam antrian[1].
FIFO singkatan dari "First In, First Out", yang artinya elemen atau item yang pertama kali dimasukkan ke dalam suatu struktur data akan menjadi yang pertama kali dikeluarkan atau diakses. Konsep ini mirip dengan antrian di kehidupan sehari-hari, di mana orang yang pertama kali datang ke loket akan dilayani terlebih dahulu sebelum orang yang datang setelahnya.

Dalam konteks struktur data seperti queue, FIFO menjamin bahwa elemen yang pertama kali dimasukkan ke dalam queue akan menjadi elemen yang pertama kali dikeluarkan dari queue ketika operasi penghapusan (dequeue) dilakukan. Sebaliknya, elemen yang dimasukkan belakangan akan berada di posisi belakang atau menjadi elemen terakhir yang akan dikeluarkan dari queue.
Dalam C++, queue bisa diimplementasikan menggunakan dua cara:
- Menggunakan Array: Queue bisa diimplementasikan menggunakan array. Namun, penggunaan array mungkin membatasi ukuran queue, dan ketika queue sudah penuh, tidak ada cara untuk menambahkan elemen baru tanpa menghapus elemen yang sudah ada di awal[1].
- Menggunakan Linked List: Queue juga bisa diimplementasikan menggunakan linked list. Dalam implementasi ini, penambahan elemen baru dan penghapusan elemen yang sudah ada bisa dilakukan dengan mudah tanpa membatasi ukuran queue.

Berikut adalah beberapa operasi dasar pada queue:
1. enqueue(item): Menambahkan elemen baru ke dalam queue.
2. dequeue(): Menghapus elemen yang berada di depan queue.
3. front(): Mengembalikan elemen yang berada di depan queue tanpa menghapusnya.
4. isEmpty(): Memeriksa apakah queue kosong atau tidak.
5. size(): Mengembalikan jumlah elemen dalam queue.

## Guided 
Kode Program :
```c++
#include <iostream>
#include <string>
using namespace std;

const int maksimalQueue = 5; // Maksimal Antrian
int front = 0; // Penanda Depan Antrian
int back = 0; // Penanda Belakang Antrian
string queueTeller[5]; // Deklarasi Antrian Teller

bool isFull() { // Pengecekan Antrian Sudah Penuh Atau Tidak
    if (back == maksimalQueue) {
        return true; // = 1
    } else {
        return false;
    }
}


bool isEmpty() { // Pengecekan Antrian Sudah Kosong Atau Tidak
    if (back == 0) {
        return true;
    } else {
        return false;
    }
}

void enqueueAntrian(string data) { // Fungsi Menambahkan Antrian
    if (isFull()) {
        cout << "Antrian Sudah Penuh" << endl;
    } else {
        if (isEmpty()) {
            queueTeller[0] = data;
            front++;
            back++;
        } else {
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian() { // Fungsi Mengurangi Antrian
    if (isEmpty()) {
        cout << "Antrian Kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}

int countQueue() { // Fungsi Menghitung Banyak Antrian
    return back;
}

void clearQueue() { // Fungsi Menghapus Antrian
    if (isEmpty()) {
        cout << "Antrian Kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = "";
        }
        front = 0;
        back = 0;
    }
}

void viewQueue() { // Fungsi Melihat Antrian
    cout << "Data Antrian Teller :" << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (Kosong)" << endl;
        }
    }
}

int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    
    viewQueue();
    cout << "Jumlah Antrian = " << countQueue() << endl;
    
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah Antrian = " << countQueue() << endl;
    
    clearQueue();
    viewQueue();
    cout << "Jumlah Antrian = " << countQueue() << endl;
    
    return 0;
}

```
#### Output :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/5e2c5907-959e-47af-b0d2-96a13b9c778d)

Kode di atas merupakan implementasi queue menggunakan array . queue mempunyai fungsi dasar seperti enqueue (menambahkan item pada akhir antrian) dan dequeue (menghilangkan item pada awal antrian), serta menampilkan jumlah item dalam antrian dan Terdapat fungsi untuk dequeue . Kode ini menggunakan dua penanda. Artinya, "front" menunjukkan item pertama dalam antrian, dan "back" menunjukkan posisi setelah item terakhir dalam antrian. Fungsi isFull memeriksa apakah antrian sudah penuh dan isEmpty memeriksa apakah antrian kosong. Fungsi viewQueue digunakan untuk menampilkan isi antrian di layar. Pada contoh ini, data yang disimpan dalam antrian adalah nama pelanggan di register, dan jumlah antrian maksimal  5 item.

#### Full Code Screenshot :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/f0d8befd-671a-4f10-8cab-ef4ce6cfe220)

## Unguided 
### 1. Ubahlah penerapan konsep queue pada bagian guided dari array menjadi linked list.

Kode Program :
```c++
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;
};

const int maksimalQueue = 5; // Maksimal Antrian
Node* front = nullptr; // Penanda Depan Antrian
Node* back = nullptr; // Penanda Belakang Antrian
int jumlahAntrian = 0; // Jumlah Antrian

bool isFull() { // Pengecekan Antrian Sudah Penuh Atau Tidak
    return jumlahAntrian == maksimalQueue;
}

bool isEmpty() { // Pengecekan Antrian Sudah Kosong Atau Tidak
    return jumlahAntrian == 0;
}

void enqueueAntrian(string data) { // Fungsi Menambahkan Antrian
    if (isFull()) {
        cout << "Antrian Sudah Penuh" << endl;
        return;
    }
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    if (isEmpty()) {
        front = newNode;
    } else {
        back->next = newNode;
    }
    back = newNode;
    jumlahAntrian++;
}

void dequeueAntrian() { // Fungsi Mengurangi Antrian
    if (isEmpty()) {
        cout << "Antrian Kosong" << endl;
        return;
    }
    Node* temp = front;
    front = front->next;
    delete temp;
    jumlahAntrian--;
}

int countQueue() { // Fungsi Menghitung Banyak Antrian
    return jumlahAntrian;
}

void clearQueue() { // Fungsi Menghapus Antrian
    while (!isEmpty()) {
        dequeueAntrian();
    }
}

void viewQueue() { // Fungsi Melihat Antrian
    cout << "Data Antrian Teller :" << endl;
    Node* current = front;
    int i = 1;
    while (current != nullptr) {
        cout << i << ". " << current->data << endl;
        current = current->next;
        i++;
    }
    for (; i <= maksimalQueue; i++) {
        cout << i << ". (Kosong)" << endl;
    }
}

int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    
    viewQueue();
    cout << "Jumlah Antrian = " << countQueue() << endl;
    
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah Antrian = " << countQueue() << endl;
    
    clearQueue();
    viewQueue();
    cout << "Jumlah Antrian = " << countQueue() << endl;
    
    return 0;
}
```

#### Output :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/670fe2ce-cfee-45ff-afa1-a569beb8f9fa)

Kode di atas mengimplementasikan queue menggunakan linked list. Ini memungkinkan penambahan dan penghapusan elemen dari antrian, serta melihat isi antrian. Program ini menggunakan dua penanda, `front` dan `back`, untuk menunjukkan elemen pertama dan terakhir dalam antrian. Fungsi `enqueueAntrian` digunakan untuk menambahkan elemen ke belakang antrian, sementara `dequeueAntrian` digunakan untuk menghapus elemen dari depan antrian. Fungsi `viewQueue` digunakan untuk menampilkan isi antrian ke layar. Juga, terdapat fungsi `isFull` dan `isEmpty` untuk mengecek status antrian, dan fungsi `countQueue` untuk menghitung jumlah elemen dalam antrian.

#### Full code Screenshot :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/617d18c1-2f27-4e79-aa13-4eec7e715b45)

### 2. Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM Mahasiswa.
Kode Program :
```c++
#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
};

struct Node {
    Mahasiswa data;
    Node* next;
};

const int maksimalQueue = 5; // Maksimal Antrian
Node* front = nullptr; // Penanda Depan Antrian
Node* back = nullptr; // Penanda Belakang Antrian
int jumlahAntrian = 0; // Jumlah Antrian

bool isFull() { // Pengecekan Antrian Sudah Penuh Atau Tidak
    return jumlahAntrian == maksimalQueue;
}

bool isEmpty() { // Pengecekan Antrian Sudah Kosong Atau Tidak
    return jumlahAntrian == 0;
}

void enqueueAntrian(string nama, string nim) { // Fungsi Menambahkan Antrian
    if (isFull()) {
        cout << "Antrian Sudah Penuh" << endl;
        return;
    }
    Node* newNode = new Node;
    newNode->data.nama = nama;
    newNode->data.nim = nim;
    newNode->next = nullptr;
    if (isEmpty()) {
        front = newNode;
    } else {
        back->next = newNode;
    }
    back = newNode;
    jumlahAntrian++;
}

void dequeueAntrian() { // Fungsi Mengurangi Antrian
    if (isEmpty()) {
        cout << "Antrian Kosong" << endl;
        return;
    }
    Node* temp = front;
    front = front->next;
    delete temp;
    jumlahAntrian--;
}

int countQueue() { // Fungsi Menghitung Banyak Antrian
    return jumlahAntrian;
}

void clearQueue() { // Fungsi Menghapus Antrian
    while (!isEmpty()) {
        dequeueAntrian();
    }
}

void viewQueue() { // Fungsi Melihat Antrian
    cout << "Data Antrian Mahasiswa :" << endl;
    Node* current = front;
    int i = 1;
    while (current != nullptr) {
        cout << i << ". Nama: " << current->data.nama << ", NIM: " << current->data.nim << endl;
        current = current->next;
        i++;
    }
    for (; i <= maksimalQueue; i++) {
        cout << i << ". (Kosong)" << endl;
    }
}

int main() {
    enqueueAntrian("Andi", "2311110012");
    enqueueAntrian("Maya", "2311110013");
    
    viewQueue();
    cout << "Jumlah Antrian = " << countQueue() << endl;
    
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah Antrian = " << countQueue() << endl;
    
    clearQueue();
    viewQueue();
    cout << "Jumlah Antrian = " << countQueue() << endl;
    
    return 0;
}
```
#### Output :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/4aafadec-eec3-4aec-b40c-b407f1e8ebfb)

Kode di atas merupakan implementasi  struktur data antrian menggunakan linked list di C++.
Program ini menjaga antrian tempat penyimpanan data mahasiswa berupa nama dan NIM.
Struktur data yang digunakan meliputi dua struktur: "Student", yang menyimpan  nama dan informasi NIM, dan "Node", yang mewakili sebuah node dalam daftar tertaut dengan dua anggota. "Data", ini adalah objek "Siswa".
"berikutnya" adalah penunjuk ke node berikutnya.
Variabel global digunakan untuk menandai item pertama dan terakhir dalam antrian serta jumlah item.
Anda memiliki kemampuan untuk menambah, menghapus, dan melihat item dalam antrean Anda, serta melihat apakah antrean Anda penuh atau kosong. Pada contoh ini, dua data siswa ditambahkan ke dalam antrian, kemudian  data pertama dikeluarkan dari antrian, dan terakhir antrian tersebut dikosongkan. Setelah setiap langkah, jumlah item dalam antrian diperiksa.

#### Full code screenshot :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/916323f9-a12d-4e52-9dab-3c3230bbfc01)

## Kesimpulan
Queue adalah struktur data linier yang mengikuti prinsip FIFO (First In First Out), di mana elemen yang pertama dimasukkan ke dalam queue akan menjadi elemen yang pertama juga untuk dikeluarkan. Konsep ini sering digunakan dalam berbagai aplikasi yang memerlukan penanganan data berbasis antrian, seperti sistem pengolahan tugas, manajemen sumber daya, dan pengiriman data dalam jaringan. Dengan operasi dasar seperti enqueue, dequeue, front, isEmpty, dan size, serta implementasi menggunakan struktur data dasar seperti array atau linked list, queue dapat diandalkan untuk memproses data secara efisien sesuai dengan urutan waktu kedatangannya, yang merupakan hal penting dalam memastikan integritas dan keandalan sistem.

## Referensi
[1] Sianipar, R.H. (2014). _Pemrograman c++ untuk pemula_. Informatika. 

