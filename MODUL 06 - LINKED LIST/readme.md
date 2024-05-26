# <h1 align="center">Laporan Praktikum Modul Linked List</h1>
<p align="center">Ahmad Fariz Gustav</p>


## Dasar Teori
Linked list adalah struktur data linier yang terdiri dari simpul-simpul yang saling terhubung melalui pointer. Setiap simpul menyimpan data dan alamat (pointer) ke simpul berikutnya dalam urutan. Terdapat beberapa jenis linked list, antara lain: single linked list,
double linked list, dan circular linked list (Trivusi, 2022)[1].

Ada beberapa jenis linked list, di antaranya adalah:

1. **Singly Linked List**: Setiap node memiliki satu pointer yang menunjuk ke node berikutnya dalam urutan.

2. **Doubly Linked List**: Setiap node memiliki dua pointer, yaitu pointer yang menunjuk ke node sebelumnya dan pointer yang menunjuk ke node berikutnya.

3. **Circular Linked List**: Mirip dengan singly atau doubly linked list, tetapi node terakhir menunjuk kembali ke node pertama (untuk circular singly linked list) atau node pertama dan terakhir saling menunjuk satu sama lain (untuk circular doubly linked list).

Linked list memiliki beberapa keuntungan dan kelemahan:

Keuntungan:
- Memungkinkan alokasi memori yang dinamis, karena setiap node dialokasikan secara terpisah di memori.
- Penyisipan dan penghapusan elemen dapat dilakukan dengan cepat, terutama jika kita memiliki referensi langsung ke node yang ingin kita sisipkan atau hapus.
- Kapasitas linked list tidak tetap, sehingga dapat menyesuaikan diri dengan jumlah elemen yang dimasukkan ke dalamnya.

Kelemahan:
- Akses acak ke elemen tidak efisien, karena kita harus melakukan pencarian dari awal atau akhir linked list untuk menemukan elemen tertentu.
- Memerlukan alokasi memori tambahan untuk menyimpan pointer, yang dapat menyebabkan overhead memori.

Linked list digunakan dalam berbagai aplikasi, termasuk implementasi struktur data lain seperti stack, queue, dan tree. Ini juga sering digunakan dalam implementasi algoritma yang melibatkan manipulasi data secara dinamis, seperti algoritma sorting dan searching. Memahami konsep dan penggunaan linked list merupakan bagian penting dalam mempelajari pemrograman dan ilmu komputer secara umum.

## Guided 
### 1. Latihan Single Linked List

#### Kode Program :
```c++
#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node {
    int data;
    Node *next;
};

Node *head;
Node *tail;

// Inisialisasi Node
void init() {
    head = NULL;
    tail = NULL;
}

// Pengecekan
bool isEmpty() {
    return (head == NULL);
}

// Tambah Data Depan
void insertDepan(int nilai) {
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
    } else {
        baru->next = head;
        head = baru;
    }
}

// Tambah Data Belakang
void insertBelakang(int nilai) {
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

// Hitung Jumlah Node
int hitungList() {
    Node *hitung = head;
    int jumlah = 0;
    while (hitung != NULL) {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

// Tambah Data Tengah
void insertTengah(int data, int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi Di Luar Jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi Bukan Posisi Tengah" << endl;
    } else {
        Node *baru = new Node();
        baru->data = data;
        Node *bantu = head;
        for (int nomor = 1; nomor < posisi - 1; nomor++) {
            bantu = bantu->next;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Node Depan
void hapusDepan() {
    if (!isEmpty()) {
        Node *hapus = head;
        if (head->next != NULL) {
            head = head->next;
        } else {
            head = tail = NULL;
        }
        delete hapus;
    } else {
        cout << "List Kosong!" << endl;
    }
}

// Hapus Node Belakang
void hapusBelakang() {
    if (!isEmpty()) {
        Node *hapus = tail;
        if (head != tail) {
            Node *bantu = head;
            while (bantu->next != tail) {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        } else {
            head = tail = NULL;
        }
        delete hapus;
    } else {
        cout << "List Kosong!" << endl;
    }
}

// Hapus Node Tengah
void hapusTengah(int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi Di Luar Jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi Bukan Posisi Tengah" << endl;
    } else {
        Node *hapus;
        Node *bantu = head;
        for (int nomor = 1; nomor < posisi - 1; nomor++) {
            bantu = bantu->next;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    }
}

// Ubah Data Depan
void ubahDepan(int data) {
    if (!isEmpty()) {
        head->data = data;
    } else {
        cout << "List Masih Kosong!" << endl;
    }
}

// Ubah Data Tengah
void ubahTengah(int data, int posisi) {
    if (!isEmpty()) {
        if (posisi < 1 || posisi > hitungList()) {
            cout << "Posisi Di Luar Jangkauan" << endl;
        } else if (posisi == 1) {
            cout << "Posisi Bukan Posisi Tengah" << endl;
        } else {
            Node *bantu = head;
            for (int nomor = 1; nomor < posisi; nomor++) {
                bantu = bantu->next;
            }
            bantu->data = data;
        }
    } else {
        cout << "List Masih Kosong!" << endl;
    }
}

// Ubah Data Belakang
void ubahBelakang(int data) {
    if (!isEmpty()) {
        tail->data = data;
    } else {
        cout << "List Masih Kosong!" << endl;
    }
}

// Hapus Semua Node
void clearList() {
    Node *hapus;
    while (head != NULL) {
        hapus = head;
        head = head->next;
        delete hapus;
    }
    tail = NULL;
    cout << "List Berhasil Terhapus!" << endl;
}

// Tampilkan List
void tampil() {
    Node *bantu = head;
    if (!isEmpty()) {
        while (bantu != NULL) {
            cout << bantu->data << " ";
            bantu = bantu->next;
        }
        cout << endl;
    } else {
        cout << "List Masih Kosong!" << endl;
    }
}

int main() {
    init();
    insertDepan(3); 
    tampil();
    insertBelakang(5); 
    tampil();
    insertDepan(2); 
    tampil();
    insertDepan(1); 
    tampil();
    hapusDepan(); 
    tampil();
    hapusBelakang(); 
    tampil();
    insertTengah(7, 2); 
    tampil();
    hapusTengah(2); 
    tampil();
    ubahDepan(1); 
    tampil();
    ubahBelakang(8); 
    tampil();
    ubahTengah(11, 2); 
    tampil();
    clearList();
    return 0;
}
```
#### Output :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/928bdf96-713b-4539-80d9-4e518c6535ff)

Program di atas adalah implementasi dari struktur data linked list dalam bahasa C++. Linked list adalah kumpulan data terhubung secara sekuensial, di mana setiap elemen disebut node. Setiap node memiliki dua bagian, yaitu data (yang menyimpan nilai) dan next (yang menunjukkan ke node berikutnya). Program tersebut menyediakan fungsi-fungsi untuk menambah, mengubah, menghapus, dan menampilkan elemen-elemen dalam linked list. Dalam main(), terdapat contoh penggunaan fungsi-fungsi tersebut untuk menambah, mengubah, dan menghapus data dalam linked list, serta menampilkan isi linked list atau menghapus linked list secara keseluruhan.

#### Full Code Screenshot :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/e08f05d2-d101-4559-ae68-e43f36929f68)

### 2. Latihan Double Linked List
#### Kode Program :
```c++
#include <iostream>
using namespace std;

/// PROGRAM DOUBLE LINKED LIST
class Node {
public:
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }
        head = newNode;
    }

    void pop() {
        if (head == NULL) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL;
        }
        delete temp;
    }

    bool update(int oldData, int newData) {
        Node* current = head;
        while (current != NULL) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void deleteAll() {
        Node* current = head;
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = NULL;
        tail = NULL;
    }

    void display() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Perbarui Data" << endl;
        cout << "4. Hapus Semua Data" << endl;
        cout << "5. Tampilkan Data" << endl;
        cout << "6. Keluar" << endl;
        int choice;
        cout << "Masukkan Pilihan Anda : ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int data;
                cout << "Masukkan Data Yang Akan Ditambahkan : ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Masukkan Data Lama : ";
                cin >> oldData;
                cout << "Masukkan Data Baru : ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if (!updated) {
                    cout << "Data Tidak Ditemukan" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Pilihan Tidak Valid" << endl;
                break;
            }
        }
    }
}
```
#### Output :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/329b7663-f179-45c9-9afe-d4dbd3e26d94)

Program di atas adalah implementasi C++ dari struktur data daftar tertaut ganda. Daftar tertaut ganda adalah kumpulan data yang terhubung secara berurutan, di mana setiap node memiliki dua pointer: prev (penunjuk ke node sebelumnya) dan next (penunjuk ke node berikutnya). Kelas Node digunakan untuk mewakili setiap node dalam daftar tertaut dengan atribut data yang menyimpan nilai data, dan penunjuk sebelumnya dan berikutnya yang menunjuk ke node sebelumnya dan berikutnya. Kelas DoublyLinkedList mengelola operasi daftar tertaut seperti: B. Tambahkan (push), hapus (pop), perbarui (update), dan hapus semua data (deleteAll) ke daftar tautan dan tampilkan.Di main(), program menyediakan opsi menu kepada pengguna untuk melakukan operasi ini. Pengguna dapat menambah data, menghapus data, memperbarui data, menghapus semua data, melihat data, atau keluar dari program. Program ini menggunakan loop tak terbatas (sementara benar) untuk terus menampilkan menu hingga pengguna  keluar dari program (opsi 6).

#### Full Code Screenshot :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/1b4a4ab9-dae5-437c-8980-93fce405419b)

### 3. Linked List Non Circular
#### Kode Program :
```c++
#include <iostream> 
using namespace std; 

/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR 

// Deklarasi Struct Node 
struct Node 
{ 
    int data; 
    Node *next; 
}; 

Node *head; 
Node *tail; 

// Inisialisasi Node 
void init() 
{ 
    head = NULL; 
    tail = NULL; 
} 

// Pengecekan 
bool isEmpty() 
{ 
    return head == NULL; 
} 

// Tambah Depan 
void insertDepan(int nilai) 
{ 
    Node *baru = new Node; 
    baru->data = nilai; 
    baru->next = NULL; 
    if (isEmpty()) 
    { 
        head = tail = baru; 
    } 
    else 
    { 
        baru->next = head; 
        head = baru; 
    } 
} 

// Tambah Belakang 
void insertBelakang(int nilai) 
{ 
    Node *baru = new Node; 
    baru->data = nilai; 
    baru->next = NULL; 
    if (isEmpty()) 
    { 
        head = tail = baru; 
    } 
    else 
    { 
        tail->next = baru; 
        tail = baru; 
    } 
} 

// Hitung Jumlah List 
int hitungList() 
{ 
    Node *hitung = head; 
    int jumlah = 0; 
    while (hitung != NULL) 
    { 
        jumlah++; 
        hitung = hitung->next; 
    } 
    return jumlah; 
} 

// Tambah Tengah 
void insertTengah(int data, int posisi) 
{ 
    if (posisi < 1 || posisi > hitungList()) 
    { 
        cout << "Posisi Di Luar Jangkauan" << endl; 
    } 
    else if (posisi == 1) 
    { 
        cout << "Posisi Bukan Posisi Tengah" << endl; 
    } 
    else 
    { 
        Node *baru = new Node(); 
        baru->data = data; 
        Node *bantu = head; 
        for (int nomor = 1; nomor < posisi - 1; nomor++) 
        { 
            bantu = bantu->next; 
        } 
        baru->next = bantu->next; 
        bantu->next = baru; 
    } 
} 

// Hapus Depan 
void hapusDepan() 
{ 
    if (!isEmpty()) 
    { 
        Node *hapus = head; 
        if (head->next != NULL) 
        { 
            head = head->next;
        } 
        else 
        { 
            head = tail = NULL; 
        } 
        delete hapus; 
    } 
    else 
    { 
        cout << "List Kosong!" << endl; 
    } 
} 

// Hapus Belakang 
void hapusBelakang() 
{ 
    if (!isEmpty()) 
    { 
        Node *hapus = tail; 
        if (head != tail) 
        { 
            Node *bantu = head; 
            while (bantu->next != tail) 
            { 
                bantu = bantu->next; 
            } 
            tail = bantu; 
            tail->next = NULL; 
        } 
        else 
        { 
            head = tail = NULL; 
        } 
        delete hapus; 
    } 
    else 
    { 
        cout << "List Kosong!" << endl; 
    } 
} 

// Hapus Tengah 
void hapusTengah(int posisi) 
{ 
    if (!isEmpty()) 
    { 
        Node *bantu = head, *hapus = NULL, *sebelum = NULL; 
        if (posisi < 1 || posisi > hitungList()) 
        { 
            cout << "Posisi Di Luar Jangkauan" << endl; 
        } 
        else if (posisi == 1) 
        { 
            cout << "Posisi Bukan Posisi Tengah" << endl; 
        } 
        else 
        { 
            int nomor = 1; 
            while (nomor <= posisi) 
            { 
                if (nomor == posisi - 1) 
                { 
                    sebelum = bantu; 
                } 
                if (nomor == posisi) 
                { 
                    hapus = bantu; 
                } 
                bantu = bantu->next; 
                nomor++; 
            } 
            sebelum->next = bantu; 
            delete hapus; 
        } 
    } 
    else 
    { 
        cout << "List Masih Kosong!" << endl; 
    } 
}
// Ubah Depan 
void ubahDepan(int data) 
{ 
    if (!isEmpty()) 
    { 
        head->data = data; 
    } 
    else 
    { 
        cout << "List Masih Kosong!" << endl; 
    } 
} 

// Ubah Tengah 
void ubahTengah(int data, int posisi) 
{ 
    if (!isEmpty()) 
    { 
        if (posisi < 1 || posisi > hitungList()) 
        { 
            cout << "Posisi Di Luar Jangkauan" << endl; 
        } 
        else if (posisi == 1) 
        { 
            cout << "Posisi Bukan Posisi Tengah" << endl; 
        } 
        else 
        { 
            Node *bantu = head; 
            for (int nomor = 1; nomor < posisi; nomor++) 
            { 
                bantu = bantu->next; 
            } 
            bantu->data = data; 
        } 
    } 
    else 
    { 
        cout << "List Masih Kosong!" << endl; 
    } 
} 

// Ubah Belakang 
void ubahBelakang(int data) 
{ 
    if (!isEmpty()) 
    { 
        tail->data = data; 
    } 
    else 
    { 
        cout << "List Masih Kosong!" << endl; 
    } 
} 

// Hapus List 
void clearList() 
{ 
    Node *bantu = head, *hapus; 
    while (bantu != NULL) 
    { 
        hapus = bantu; 
        bantu = bantu->next; 
        delete hapus; 
    } 
    head = tail = NULL; 
    cout << "List Berhasil Terhapus!" << endl; 
} 

// Tampilkan List 
void tampil() 
{ 
    if (!isEmpty()) 
    { 
        Node *bantu = head; 
        while (bantu != NULL) 
        { 
            cout << bantu->data << " "; 
            bantu = bantu->next; 
        } 
        cout << endl; 
    } 
    else 
    { 
        cout << "List Masih Kosong!" << endl; 
    } 
} 

int main() 
{ 
    init(); 
    insertDepan(3); 
    tampil(); 
    insertBelakang(5); 
    tampil(); 
    insertDepan(2); 
    tampil(); 
    insertDepan(1); 
    tampil(); 
    hapusDepan(); 
    tampil(); 
    hapusBelakang(); 
    tampil(); 
    insertTengah(7, 2); 
    tampil(); 
    hapusTengah(2); 
    tampil(); 
    ubahDepan(1); 
    tampil(); 
    ubahBelakang(8); 
    tampil(); 
    ubahTengah(11, 2); 
    tampil(); 
    clearList(); 
    return 0; 
}
```
#### Output :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/8080df27-4948-4248-9198-f343ddac1830)

Kode di atas merupakan implementasi dari struktur data linked list non-circular (satu arah) dalam bahasa C++. Dimulai dengan definisi struktur data `Node` yang memiliki anggota `data` untuk menyimpan nilai dan `next` untuk menunjuk ke node selanjutnya. Terdapat juga dua pointer global, `head` dan `tail`, yang menunjuk ke node pertama dan terakhir dalam linked list. Fungsi-fungsi seperti `insertDepan`, `insertBelakang`, `hapusDepan`, `hapusBelakang`, dan lainnya, digunakan untuk operasi-operasi pada linked list. Program memberikan contoh penggunaan fungsi-fungsi tersebut dengan menambah, menghapus, mengubah, dan menampilkan data dalam linked list dalam `main()`, diikuti dengan pemanggilan `tampil()` untuk menampilkan hasilnya.

#### Full Code Screenshot :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/1b4a4ab9-dae5-437c-8980-93fce405419b)

### 4. Linked List Circular
#### Kode Program :
```c++
#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST CIRCULAR

// Deklarasi Struct Node
struct Node
{
    string data;
    Node *next;
};
Node *head, *tail, *baru, *bantu, *hapus;

void init()
{
    head = NULL;
    tail = head;
}

// Pengecekan
int isEmpty()
{
    return head == NULL ? 1 : 0;
}

// Buat Node Baru
void buatNode(string data)
{
    baru = new Node;
    baru->data = data;
    baru->next = NULL;
}

// Hitung List
int hitungList()
{
    bantu = head;
    int jumlah = 0;
    while (bantu != NULL)
    {
        jumlah++;
        bantu = bantu->next;
    }
    return jumlah;
}

// Tambah Depan
void insertDepan(string data)
{
    // Buat Node baru
    buatNode(data);

    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        tail->next = baru;
        baru->next = head;
        head = baru;
    }
}

// Tambah Belakang
void insertBelakang(string data)
{
    // Buat Node baru
    buatNode(data);

    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        tail->next = baru;
        tail = baru;
        tail->next = head;
    }
}

// Tambah Tengah
void insertTengah(string data, int posisi)
{
    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        baru->data = data;
        // Transversing
        int nomor = 1;
        bantu = head;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Depan
void hapusDepan()
{
    if (isEmpty() == 0)
    {
        hapus = head;
        tail->next = head->next;
        head = head->next;
        delete hapus;
    }
    else
    {
        cout << "List Masih Kosong!" << endl;
    }
}

// Hapus Belakang
void hapusBelakang()
{
    if (isEmpty() == 0)
    {
        hapus = tail;
        bantu = head;
        while (bantu->next != tail)
        {
            bantu = bantu->next;
        }
        tail = bantu;
        tail->next = head;
        delete hapus;
    }
    else
    {
        cout << "List Masih Kosong!" << endl;
    }
}

// Hapus Tengah
void hapusTengah(int posisi)
{
    if (isEmpty() == 0)
    {
        // transversing
        int nomor = 1;
        bantu = head;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    }
    else
    {
        cout << "List Masih Kosong!" << endl;
    }
}

// Hapus List
void clearList()
{
    if (head != NULL)
    {
        hapus = head->next;
        while (hapus != head)
        {
            bantu = hapus->next;
            delete hapus;
            hapus = bantu;
        }
        delete head;
        head = NULL;
    }
    cout << "List Berhasil Terhapus!" << endl;
}

// Tampilkan List
void tampil()
{
    if (isEmpty() == 0)
    {
        Node *temp = head;
        do
        {
            cout << temp->data << ends;
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
    else
    {
        cout << "List Masih Kosong!" << endl;
    }
}

int main()
{
    init();
    insertDepan("Ayam");
    tampil();
    insertDepan("Bebek");
    tampil();
    insertBelakang("Cicak");
    tampil();
    insertBelakang("Domba");
    tampil();
    hapusBelakang();
    tampil();
    hapusDepan();
    tampil();
    insertTengah("Sapi", 2);
    tampil();
    hapusTengah(2);
    tampil();
    return 0;
}
```
#### Output :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/196c6d51-968a-4afe-9cfc-ab678be26af0)

Kode di atas adalah implementasi dari struktur data linked list circular (lingkaran) dalam bahasa C++. Program dimulai dengan deklarasi struktur `Node` yang memiliki anggota `data` untuk menyimpan nilai dan `next` untuk menunjuk ke node berikutnya. Terdapat juga beberapa pointer global seperti `head`, `tail`, `baru`, `bantu`, dan `hapus`. Fungsi `init()` digunakan untuk menginisialisasi linked list. Fungsi-fungsi lain seperti `isEmpty()`, `buatNode()`, `hitungList()`, `insertDepan()`, `insertBelakang()`, `insertTengah()`, `hapusDepan()`, `hapusBelakang()`, `hapusTengah()`, dan `clearList()` digunakan untuk operasi-operasi pada linked list seperti menambah, menghapus, dan mengubah data dalam linked list. Program juga memiliki fungsi `tampil()` untuk menampilkan isi dari linked list. Dalam `main()`, beberapa operasi pada linked list dipanggil dan hasilnya ditampilkan menggunakan fungsi `tampil()`.

#### Full Code Screenshot :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/4989757d-5daa-41a9-a07e-afd166681283)

## Unguided 
### 1. Buatlah program menu Linked List Non Circular untuk menyimpan Nama dan NIM mahasiswa, dengan menggunakan input dari user Buatlah menu untuk menambahkan, mengubah, menghapus, dan melihat Nama dan NIM mahasiswa, berikut contoh tampilan output dari nomor 1 :
#### Kode Program :
```c++
#include <iostream>
using namespace std;

// Deklarasi Struct Node
struct Node {
    string nama;
    string nim;
    Node* next;
};

// Pointer global untuk kepala (head) dan ekor (tail) linked list
Node* head = NULL;
Node* tail = NULL;

// Fungsi untuk menampilkan menu
void tampilkanMenu() {
    cout << "PROGRAM SINGLE LINKED LIST NON-CIRCULAR" << endl;
    cout << "1. Tambah Depan" << endl;
    cout << "2. Tambah Belakang" << endl;
    cout << "3. Tambah Tengah" << endl;
    cout << "4. Ubah Depan" << endl;
    cout << "5. Ubah Belakang" << endl;
    cout << "6. Ubah Tengah" << endl;
    cout << "7. Hapus Depan" << endl;
    cout << "8. Hapus Belakang" << endl;
    cout << "9. Hapus Tengah" << endl;
    cout << "10. Hapus List" << endl;
    cout << "11. TAMPILKAN" << endl;
    cout << "0. KELUAR" << endl;
}

// Fungsi untuk menambahkan node di depan linked list
void tambahDepan(string nama, string nim) {
    Node* baru = new Node;
    baru->nama = nama;
    baru->nim = nim;
    baru->next = head;
    head = baru;
    if (tail == NULL) {
        tail = head;
    }
}

// Fungsi untuk menambahkan node di belakang linked list
void tambahBelakang(string nama, string nim) {
    Node* baru = new Node;
    baru->nama = nama;
    baru->nim = nim;
    baru->next = NULL;
    if (tail == NULL) {
        head = baru;
        tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

// Fungsi untuk menambahkan node di tengah linked list pada posisi tertentu
void tambahTengah(string nama, string nim, int posisi) {
    if (posisi <= 0) {
        cout << "Posisi tidak valid." << endl;
        return;
    }

    if (posisi == 1) {
        tambahDepan(nama, nim);
    } else {
        Node* bantu = head;
        for (int i = 1; i < posisi - 1; i++) {
            if (bantu == NULL) {
                cout << "Posisi tidak valid." << endl;
                return;
            }
            bantu = bantu->next;
        }
        if (bantu == NULL) {
            cout << "Posisi tidak valid." << endl;
            return;
        }
        Node* baru = new Node;
        baru->nama = nama;
        baru->nim = nim;
        baru->next = bantu->next;
        bantu->next = baru;
        if (bantu == tail) {
            tail = baru;
        }
    }
}

// Fungsi untuk menghitung jumlah node dalam linked list
int hitungList() {
    int jumlah = 0;
    Node* bantu = head;
    while (bantu != NULL) {
        jumlah++;
        bantu = bantu->next;
    }
    return jumlah;
}

// Fungsi untuk menampilkan seluruh data dalam linked list
void tampilData() {
    cout << "========DATA MAHASISWA=======" << endl;
    cout << "=============================" << endl;
    cout << "  NAMA\t\tNIM         " << endl;
    cout << "=============================" << endl;
    
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->nama << "\t\t" << temp->nim << endl;
        temp = temp->next;
    }
    cout << "=============================" << endl;
}


// Fungsi untuk mengubah data pada node di depan linked list
void ubahDepan(string nama, string nim) {
    if (head != NULL) {
        head->nama = nama;
        head->nim = nim;
    } else {
        cout << "Linked list masih kosong." << endl;
    }
}

// Fungsi untuk mengubah data pada node di belakang linked list
void ubahBelakang(string nama, string nim) {
    if (tail != NULL) {
        tail->nama = nama;
        tail->nim = nim;
    } else {
        cout << "Linked list masih kosong." << endl;
    }
}

// Fungsi untuk mengubah data pada node di tengah linked list pada posisi tertentu
void ubahTengah(string nama, string nim, int posisi) {
    if (posisi <= 0 || posisi > hitungList()) {
        cout << "Posisi tidak valid." << endl;
        return;
    }

    Node* bantu = head;
    for (int i = 1; i < posisi; i++) {
        if (bantu == NULL) {
            cout << "Posisi tidak valid." << endl;
            return;
        }
        bantu = bantu->next;
    }
    bantu->nama = nama;
    bantu->nim = nim;
}

// Fungsi untuk menghapus node di depan linked list
void hapusDepan() {
    if (head != NULL) {
        Node* hapus = head;
        head = head->next;
        delete hapus;
        if (head == NULL) {
            tail = NULL;
        }
    } else {
        cout << "Linked list masih kosong." << endl;
    }
}

// Fungsi untuk menghapus node di belakang linked list
void hapusBelakang() {
    if (head != NULL) {
        if (head == tail) {
            delete head;
            head = tail = NULL;
        } else {
            Node* bantu = head;
            while (bantu->next != tail) {
                bantu = bantu->next;
            }
            delete tail;
            tail = bantu;
            tail->next = NULL;
        }
    } else {
        cout << "Linked list masih kosong." << endl;
    }
}

// Fungsi untuk menghapus node di tengah linked list pada posisi tertentu
void hapusTengah(int posisi) {
    if (posisi <= 0 || posisi > hitungList()) {
        cout << "Posisi tidak valid." << endl;
        return;
    }

    if (posisi == 1) {
        hapusDepan();
    } else {
        Node* bantu = head;
        for (int i = 1; i < posisi - 1; i++) {
            bantu = bantu->next;
        }
        Node* hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
        if (bantu->next == NULL) {
            tail = bantu;
        }
    }
}

// Fungsi untuk menghapus seluruh linked list
void hapusList() {
    while (head != NULL) {
        hapusDepan();
    }
}

int main() {
    int choice;
    string nama, nim;
    int posisi;

    do {
        tampilkanMenu();
        cout << "Pilih Operasi : ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                tambahDepan(nama, nim);
                cout << "Data Telah Ditambahkan" << endl;
                break;
            case 2:
                cout << "Masukkan nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                tambahBelakang(nama, nim);
                cout << "Data Telah Ditambahkan" << endl;
                break;
            case 3:
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                cout << "Masukkan posisi : ";
                cin >> posisi;
                tambahTengah(nama, nim, posisi);
                break;
            case 4:
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                ubahDepan(nama, nim);
                break;
            case 5:
                cout << "Masukkan nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                ubahBelakang(nama, nim);
                break;
            case 6:
                cout << "Masukkan nama mahasiswa: ";
                cin >> nama;
                cout << "Masukkan NIM mahasiswa: ";
                cin >> nim;
                cout << "Masukkan posisi yang ingin diubah: ";
                cin >> posisi;
                ubahTengah(nama, nim, posisi);
                break;
            case 7:
                cout << "==Hapus depan==" << endl;
                cout << "Data Telah Terhapus" << endl;
                hapusDepan();
                break;
            case 8:
                cout << "==Hapus belakang==" << endl;
                cout << "Data Telah Terhapus" << endl;
                hapusBelakang();
                break;
            case 9:
                cout << "Masukkan posisi yang ingin dihapus: ";
                cin >> posisi;
                hapusTengah(posisi);
                break;
            case 10:
                cout << "Menghapus seluruh list..." << endl;
                hapusList();
                cout << "Seluruh list telah terhapus." << endl;
                break;
            case 11:
                tampilData();
                break;
            case 0:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}
```
#### Output :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/f4d42520-431c-4a54-a3d4-f38e92e68e3b)

Kode di atas merupakan implementasi dari sebuah linked list non-circular dalam C++. Struct `Node` digunakan untuk merepresentasikan setiap node, dengan dua string (`nama` dan `nim`) untuk menyimpan data mahasiswa, serta pointer `next` yang menunjuk ke node berikutnya. Terdapat fungsi-fungsi seperti `tambahDepan`, `tambahBelakang`, dan `tambahTengah` untuk menambahkan node pada berbagai posisi, serta fungsi-fungsi `hapusDepan`, `hapusBelakang`, dan `hapusTengah` untuk menghapus node pada posisi tertentu. Fungsi `tampilkanMenu()` digunakan untuk menampilkan menu operasi yang tersedia. Selain itu, terdapat juga fungsi-fungsi untuk mengubah data pada node dan menampilkan seluruh data dalam linked list. Program menggunakan sebuah loop `do-while` untuk memungkinkan pengguna memilih operasi yang ingin dilakukan dari menu yang ditampilkan, dengan pilihan 0 untuk keluar dari program.

#### Full Code Screenshot :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/e142bee4-d13f-46fd-87af-0ad0a95c24ff)


### 2. Setelah membuat menu tersebut, masukkan data sesuai urutan berikut, lalu tampilkan data yang telah dimasukkan. (Gunakan insert depan, belakang atau tengah)
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/668e9c1f-e60c-4e7f-bcbf-ebc1266f4308)

#### Output :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/791f6a81-cc7b-4728-bfb5-9b44180332c6)

### 3. Lakukan perintah berikut :

- Tambahkan data berikut diantara Farrel dan Denis : Wati 2330004

    ![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/50770bb3-f639-4084-b1a6-6dfccfddfb0e)

- Hapus data Denis

    ![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/6cc35332-1cf5-4cf9-bedd-07cf3232ee5a)

- Tambahkan data berikut di awal : Owi 2330000

    ![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/cbf36cf8-7a96-48ae-ba03-f05d0d36f4c4)

- Tambahkan data berikut di akhir : David 23300100

    ![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/87efc1e1-1080-4c8c-b5b6-2e38dd4188cd)

- Ubah data Udin menjadi data berikut : Idin 23300045

    ![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/4f1002da-f4e6-40ab-bfde-dfb42218ec76)

- Ubah data terkahir menjadi berikut : Lucy 23300101

    ![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/b3150626-4c9c-49ab-89f8-6d757cd85812)

- Hapus data awal

    ![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/09981739-6d51-4e99-826e-99f589ed4a6c)

-  Ubah data awal menjadi berikut : Bagas 2330002

    ![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/45c0d0a7-abb4-457f-81fb-5397374fe5a2)

- Hapus data akhir

    ![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/9158de1f-eb52-489a-ab0d-fc2cdc91d948)

- Tampilkan seluruh data

    ![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/dd86ab64-2732-42d2-9e98-6560c8b6f324)

## Kesimpulan
Dalam kesimpulan, linked list adalah struktur data yang penting dan fleksibel dalam ilmu komputer dan pemrograman. Ini memungkinkan alokasi memori dinamis dan efisien untuk penyimpanan dan manipulasi data. Meskipun memiliki keuntungan seperti kemampuan untuk menyisipkan dan menghapus elemen dengan cepat, linked list juga memiliki beberapa kelemahan, termasuk akses acak yang tidak efisien dan overhead memori untuk menyimpan pointer. Namun demikian, penggunaan linked list sangat luas dalam berbagai aplikasi dan algoritma, seperti dalam implementasi struktur data lain dan algoritma pencarian dan pengurutan. Oleh karena itu, pemahaman tentang konsep dan penggunaan linked list merupakan aspek penting dalam pengembangan perangkat lunak dan penyelesaian masalah komputer secara umum.
## Referensi
[1] Erkamim, M. (2024). _Buku Ajar algoritma dan struktur data_. PT Sonpedia Publishing Indonesia. 

