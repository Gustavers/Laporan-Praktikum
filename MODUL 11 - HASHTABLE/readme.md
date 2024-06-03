# <h1 align="center">Laporan Praktikum Modul Hashtable</h1>
<p align="center">Ahmad Fariz Gustav</p>
<p align="center">2311110012</p>
<p align="center">S1SD-04-A</p>

## Dasar Teori
Hash Table adalah struktur data yang digunakan untuk menyimpan pasangan kunci-nilai. Struktur ini memungkinkan operasi penyimpanan, pencarian, dan penghapusan data dilakukan dengan sangat efisien, biasanya dalam waktu konstan (O(1))[1].
Fungsi hash table adalah sebuah fungsi yang digunakan untuk memetakan nilai kunci yang unik menjadi sebuah indeks pada sebuah tabel. Fungsi hash ini memungkinkan untuk melakukan penambahan, penghapusan, dan pencarian data dengan waktu rata-rata konstan [2]. Fungsi hash table memiliki beberapa kelebihan, seperti kemampuan untuk melakukan pencarian dan penambahan data dengan waktu rata-rata konstan, serta efisiensi dalam penggunaan memori. Namun, fungsi hash table juga memiliki beberapa kelemahan, seperti kemungkinan terjadinya tabrakan (collision) yang memerlukan penanganan khusus untuk mengatasi masalah tersebut[2]. 

Operasi-operasi yang dapat dilakukan pada hash table meliputi[5]:
1. Search (Pencarian): Operasi ini memungkinkan pengguna untuk mencari data yang telah disimpan di dalam hash table dengan menggunakan kunci (key).

2. Insert (Penyisipan): Operasi ini memungkinkan pengguna untuk menambahkan data baru ke dalam hash table dengan menggunakan kunci (key).

3. Delete (Penghapusan): Operasi ini memungkinkan pengguna untuk menghapus data yang telah disimpan di dalam hash table dengan menggunakan kunci (key)[3].

4. Update (Pengubahan): Operasi ini memungkinkan pengguna untuk mengubah data yang telah disimpan di dalam hash table dengan menggunakan kunci (key)[4].

5. Collision Resolution (Penanganan Tabrakan): Operasi ini memungkinkan pengguna untuk mengatasi tabrakan (collision) yang terjadi ketika dua kunci memiliki nilai hash yang sama, sehingga memungkinkan pengguna untuk mengatur bagaimana mengatasi tabrakan tersebut dalam hash table.

Contoh Penggunaan Tabel Hash :
Tabel hash dapat digunakan dalam berbagai aplikasi, seperti:
- Sistem pengindeksan dokumen
- Sistem pengindeksan basis data
- Sistem pengindeksan kata-kata dalam bahasa
- Sistem pengindeksan nomor telepon

Keunggulan Hashtable :
- Akses dan manipulasi data yang sangat cepat.
Implementasi yang fleksibel untuk berbagai jenis data.
Kelemahan:
- Tidak ada urutan elemen yang jelas.
- Memerlukan pemilihan fungsi hash yang baik untuk mengurangi tabrakan.
- Konsumsi memori yang lebih besar dibandingkan struktur data lain.

## Guided 1
Kode Program :
```c++
#include <iostream>
using namespace std;
const int MAX_SIZE = 10;

// Fungsi hash sederhana
int hash_func(int key) {
    return key % MAX_SIZE;
}

// Struktur data untuk setiap node
struct Node {
    int key;
    int value;
    Node* next;
    Node(int key, int value) : key(key), value(value), next(nullptr) {}
};

// Class hash table
class HashTable {
private:
    Node** table;
public:
    HashTable() {
        table = new Node*[MAX_SIZE]();
    }
    ~HashTable() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    // Insertion
    void insert(int key, int value) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                current->value = value;
                return;
            }
            current = current->next;
        }
        Node* node = new Node(key, value);
        node->next = table[index];
        table[index] = node;
    }

    // Searching
    int get(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }

    // Deletion
    void remove(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current->key == key) {
                if (prev == nullptr) {
                    table[index] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    // Traversal
    void traverse() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                cout << current->key << ": " << current->value << endl;
                current = current->next;
            }
        }
    }
};

int main() {
    HashTable ht;
    // Insertion
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);

    // Searching
    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 4: " << ht.get(4) << endl;
   
    // Deletion
    ht.remove(4);
   
    // Traversal
    ht.traverse();
   
    return 0;
}
```
#### Output :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/3b003f63-2e4f-419c-8f9b-09fac2d7925e)


**interpretasi hasil :**
1. Definisi Konstanta dan Fungsi Hash
- MAX_SIZE adalah ukuran maksimum dari hash table, yang diatur menjadi 10.
- hash_func adalah fungsi hash sederhana yang mengembalikan indeks dari tabel berdasarkan nilai kunci (key). Fungsi ini menggunakan operasi modulus (%) untuk memastikan bahwa indeks berada dalam rentang 0 hingga MAX_SIZE - 1.

2. Struct Data Node
- Node adalah struktur data yang menyimpan kunci (key), nilai (value), dan pointer ke node berikutnya (next). Ini digunakan untuk membentuk linked list di setiap slot hash table untuk menangani tabrakan.

3. class HashTable
- HashTable adalah kelas yang mengimplementasikan hash table dengan chaining.
- Konstruktor (HashTable()): Menginisialisasi tabel hash dengan array pointer ke Node berukuran MAX_SIZE.
- Destruktor (~HashTable()): Membersihkan memori yang dialokasikan untuk setiap node dalam tabel untuk mencegah kebocoran memori.
- Insertion (insert): Menambahkan pasangan kunci-nilai ke dalam hash table. Jika kunci sudah ada, nilai diperbarui.
- Searching (get): Mengambil nilai yang terkait dengan kunci tertentu. Mengembalikan -1 jika kunci tidak ditemukan.
- Deletion (remove): Menghapus pasangan kunci-nilai dari hash table.
- Traversal (traverse): Menampilkan semua kunci dan nilai yang disimpan dalam hash table.

4. Fungsi main
- Insertion: Menambahkan tiga pasangan kunci-nilai ke dalam hash table (1: 10, 2: 20, 3: 30).
- Searching: Mencari nilai dari kunci 1 dan 4. Kunci 4 tidak ada, jadi akan mengembalikan -1.
- Deletion: Mencoba menghapus kunci 4 (tidak ada efek karena kunci 4 tidak ditemukan).
- Traversal: Menampilkan semua kunci dan nilai dalam hash table.

#### Full Code Screenshot :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/d2fa8d25-bd02-417a-b86b-866c12e9f2ee)

## Guided 2
Kode Program :
```c++
#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int TABLE_SIZE = 11;

string name;
string phone_number;

class HashNode {
public:
    string name;
    string phone_number;

    HashNode(string name, string phone_number) {
        this->name = name;
        this->phone_number = phone_number;
    }
};

class HashMap {
private:
    vector<HashNode*> table[TABLE_SIZE];
public:
    int hashFunc(string key) {
        int hash_val = 0;
        for (size_t i = 0; i < key.length(); ++i) {
            hash_val += key[i];
        }
        return hash_val % TABLE_SIZE;
    }

    void insert(string name, string phone_number) {
        int hash_val = hashFunc(name);

        for (vector<HashNode*>::iterator it = table[hash_val].begin(); it != table[hash_val].end(); ++it) {
            if ((*it)->name == name) {
                (*it)->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name, phone_number));
    }

    void remove(string name) {
        int hash_val = hashFunc(name);

        for (vector<HashNode*>::iterator it = table[hash_val].begin(); it != table[hash_val].end(); ++it) {
            if ((*it)->name == name) {
                delete *it;
                table[hash_val].erase(it);
                return;
            }
        }
    }

    string searchByName(string name) {
        int hash_val = hashFunc(name);
        for (vector<HashNode*>::iterator it = table[hash_val].begin(); it != table[hash_val].end(); ++it) {
            if ((*it)->name == name) {
                return (*it)->phone_number;
            }
        }
        return "";
    }

    void print() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << " : ";
            for (vector<HashNode*>::iterator it = table[i].begin(); it != table[i].end(); ++it) {
                if (*it != NULL) {
                    cout << "[" << (*it)->name << ", " << (*it)->phone_number << "] ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    HashMap employee_map;

    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");

    cout << "Nomor Hp Mistah : " << employee_map.searchByName("Mistah") << endl;
    cout << "Phone Hp Pastah : " << employee_map.searchByName("Pastah") << endl;

    employee_map.remove("Mistah");

    cout << "Nomor Hp Mistah Setelah Dihapus : " << employee_map.searchByName("Mistah") << endl << endl;

    cout << "Hash Table : " << endl;

    employee_map.print();

    return 0;
}
```
#### Output :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/5538cc78-97b0-40bf-897a-ea5f93352351)

**interpretasi hasil :**
1. Definisi Konstanta dan Header
- Header file yang digunakan: iostream untuk input/output, string untuk menangani string, dan vector untuk menggunakan vektor dari STL.
- TABLE_SIZE adalah konstanta yang menentukan ukuran tabel hash, yang diatur menjadi 11.
- name dan phone_number adalah variabel string global yang digunakan.

2. Class HashNode
- HashNode adalah kelas yang menyimpan pasangan nama (name) dan nomor telepon (phone_number).
- Konstruktor kelas HashNode menginisialisasi dua atribut ini.

3. Class HashMap
- Hash Function (hashFunc): Menghitung nilai hash berdasarkan penjumlahan nilai ASCII dari setiap karakter dalam string, kemudian - hasilnya dimodulus dengan TABLE_SIZE untuk mendapatkan indeks tabel.
- Insertion (insert): Menambahkan pasangan nama dan nomor telepon ke dalam hash table. Jika nama sudah ada, nomor telepon diperbarui. Jika tidak, node baru ditambahkan ke list pada indeks yang sesuai.
- Deletion (remove): Menghapus pasangan nama dan nomor telepon dari hash table. Jika nama ditemukan, node dihapus dan memori dibebaskan.
- Searching (searchByName): Mencari nomor telepon berdasarkan nama. Mengembalikan nomor telepon jika nama ditemukan, atau string kosong jika tidak ditemukan.
- Print (print): Menampilkan semua elemen dalam hash table. Menampilkan indeks tabel dan pasangan nama-nomor telepon dalam format [name, phone_number].

4. Fungsi main
- Insertion: Menambahkan tiga pasangan nama-nomor telepon (Mistah: 1234, Pastah: 5678, Ghana: 91011).
- Searching: Mencari nomor telepon untuk nama "Mistah" dan "Pastah".
- Deletion: Menghapus pasangan nama-nomor telepon untuk "Mistah".
- Print: Menampilkan semua elemen dalam hash table.

#### Full Code Screenshot :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/a8a89a61-6380-46c7-a082-d9d0176201e2)

## Unguided 
### 1. Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai. Dengan ketentuan :
A. Setiap mahasiswa memiliki NIM dan nilai.

B. Program memiliki tampilan pilihan menu berisi poin C.

C. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai (80 – 90).

Kode Program :
```c++
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Struktur data untuk setiap mahasiswa
struct Mahasiswa {
    string nim;
    int nilai;
};

// Struktur data untuk setiap node di dalam tabel hash
struct HashNode {
    Mahasiswa data;
    HashNode* next;
    HashNode(const Mahasiswa& data) : data(data), next(nullptr) {}
};

// Class hash table untuk menyimpan data mahasiswa
class HashTable {
private:
    static const int TABLE_SIZE = 10;
    vector<HashNode*> table[TABLE_SIZE];

    // Fungsi hash sederhana untuk menghasilkan indeks dari sebuah NIM
    int hashFunc(const string& nim) {
        int sum = 0;
        for (char c : nim) {
            sum += c;
        }
        return sum % TABLE_SIZE;
    }

public:
    // Menambahkan data mahasiswa ke dalam tabel hash
    void tambahData(const Mahasiswa& mahasiswa) {
        int index = hashFunc(mahasiswa.nim);
        HashNode* newNode = new HashNode(mahasiswa);
        newNode->next = table[index].empty() ? nullptr : table[index][0];
        table[index].clear();
        table[index].push_back(newNode);
    }

    // Menghapus data mahasiswa dari tabel hash berdasarkan NIM
    void hapusData(const string& nim) {
        int index = hashFunc(nim);
        for (HashNode* node : table[index]) {
            if (node->data.nim == nim) {
                delete node;
                table[index].clear();
                cout << "Data dengan NIM " << nim << " berhasil dihapus." << endl; // Tambah keterangan
                return;
            }
        }
        cout << "Data mahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
    }

    // Mencari data mahasiswa berdasarkan NIM
    Mahasiswa* cariByNIM(const string& nim) {
        int index = hashFunc(nim);
        for (HashNode* node : table[index]) {
            if (node->data.nim == nim) {
                return &node->data;
            }
        }
        return nullptr;
    }

    // Mencari data mahasiswa berdasarkan rentang nilai
    vector<Mahasiswa> cariByNilai(int minNilai, int maxNilai) {
        vector<Mahasiswa> hasil;
        for (int i = 0; i < TABLE_SIZE; ++i) {
            for (HashNode* node : table[i]) {
                if (node->data.nilai >= minNilai && node->data.nilai <= maxNilai) {
                    hasil.push_back(node->data);
                }
            }
        }
        return hasil;
    }
};

int main() {
    HashTable hashTable;

    // Menu
    cout << "Menu:\n";
    cout << "1. Tambah Data Mahasiswa\n";
    cout << "2. Hapus Data Mahasiswa\n";
    cout << "3. Cari Data Mahasiswa berdasarkan NIM\n";
    cout << "4. Cari Data Mahasiswa berdasarkan Rentang Nilai\n";
    cout << "0. Keluar\n";

    int pilihan;
    do {
        cout << "\nPilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                string nim;
                int nilai;
                cout << "Masukkan NIM: ";
                cin >> nim;
                cout << "Masukkan Nilai: ";
                cin >> nilai;
                Mahasiswa mahasiswa = {nim, nilai};
                hashTable.tambahData(mahasiswa);
                cout << "Data mahasiswa berhasil ditambahkan.\n";
                break;
            }
            case 2: {
                string nim;
                cout << "Masukkan NIM mahasiswa yang ingin dihapus: ";
                cin >> nim;
                hashTable.hapusData(nim);
                break;
            }
            case 3: {
                string nim;
                cout << "Masukkan NIM mahasiswa yang ingin dicari: ";
                cin >> nim;
                Mahasiswa* hasil = hashTable.cariByNIM(nim);
                if (hasil != nullptr) {
                    cout << "NIM: " << hasil->nim << ", Nilai: " << hasil->nilai << endl;
                } else {
                    cout << "Data mahasiswa tidak ditemukan.\n";
                }
                break;
            }
            case 4: {
                int minNilai, maxNilai;
                cout << "Masukkan rentang nilai (minimal dan maksimal): ";
                cin >> minNilai >> maxNilai;
                vector<Mahasiswa> hasil = hashTable.cariByNilai(minNilai, maxNilai);
                cout << "Hasil pencarian berdasarkan rentang nilai " << minNilai << " - " << maxNilai << ":\n";
                for (const Mahasiswa& mahasiswa : hasil) {
                    cout << "NIM: " << mahasiswa.nim << ", Nilai: " << mahasiswa.nilai << endl;
                }
                break;
            }
            case 0:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
                break;
        }
    } while (pilihan != 0);

    return 0;
}
```

#### Output :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/e925e46b-aa5d-4b7b-9ff2-1f4c9567e687)

**Interpretasi hasil**
1. Definisi struct Mahasiswa dan Node
- Mahasiswa adalah struktur data yang menyimpan NIM dan nilai mahasiswa.
- HashNode adalah struktur data yang menyimpan data Mahasiswa dan pointer ke node berikutnya (next). Digunakan untuk membuat linked list di setiap slot hash table untuk menangani tabrakan (collision).

2. class HashTable
- Hash Function (hashFunc): Menghitung nilai hash berdasarkan penjumlahan nilai ASCII dari setiap karakter dalam string NIM, kemudian hasilnya dimodulus dengan TABLE_SIZE untuk mendapatkan indeks tabel.
- Insertion (tambahData): Menambahkan data mahasiswa ke dalam hash table. Jika ada tabrakan, node baru ditambahkan di awal linked list pada indeks yang sesuai.
- Deletion (hapusData): Menghapus data mahasiswa berdasarkan NIM. Jika ditemukan, node dihapus dan memori dibebaskan.
- Searching by NIM (cariByNIM): Mencari data mahasiswa berdasarkan NIM. Mengembalikan pointer ke data mahasiswa jika ditemukan, atau nullptr jika tidak ditemukan.
- Searching by Range of Grades (cariByNilai): Mencari data mahasiswa yang nilai nya berada dalam rentang tertentu. Mengembalikan vektor berisi data mahasiswa yang memenuhi kriteria.

3. Fungsi main
- Menu: Menampilkan opsi kepada pengguna untuk menambah, menghapus, mencari berdasarkan NIM, dan mencari berdasarkan rentang nilai.
- Loop Menu: Mengambil pilihan pengguna dan menjalankan aksi yang sesuai hingga pengguna memilih untuk keluar (pilihan 0).
- Case 1: Menambah data mahasiswa dengan memasukkan NIM dan nilai.
- Case 2: Menghapus data mahasiswa berdasarkan NIM.
- Case 3: Mencari data mahasiswa berdasarkan NIM dan menampilkan hasil pencarian.
- Case 4: Mencari data mahasiswa berdasarkan rentang nilai dan menampilkan hasil pencarian.
- Case 0: Mengakhiri program.

#### Full code Screenshot :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/c09d6706-47bb-4ea2-a05d-a6dfee18f182)

## Kesimpulan
Hash table adalah struktur data yang sangat efisien untuk operasi pencarian, penyisipan, dan penghapusan data. Dengan menggunakan fungsi hash, hash table memetakan kunci ke indeks dalam array, memungkinkan akses data yang cepat. Operasi dasar dalam hash table, seperti penyisipan, penghapusan, dan pencarian, biasanya memiliki kompleksitas waktu rata-rata O(1). Meskipun demikian, tantangan seperti tabrakan (collision) dapat terjadi ketika dua kunci berbeda menghasilkan indeks yang sama. Untuk mengatasi tabrakan, teknik seperti chaining (menggunakan linked list) dan open addressing dapat diterapkan. Hash table juga sederhana dan mudah dipahami, menjadikannya pilihan populer dalam berbagai aplikasi, termasuk penyimpanan cache, tabel simbol dalam kompilator, dan basis data.

Namun, hash table juga memiliki kelemahan yang perlu diperhatikan. Salah satu kelemahan utama adalah penggunaan memori yang bisa lebih besar dibandingkan struktur data lainnya, karena perlu mengalokasikan array dengan ukuran yang cukup besar untuk mengurangi kemungkinan tabrakan. Selain itu, data dalam hash table tidak disimpan dalam urutan tertentu, sehingga struktur data ini kurang sesuai untuk aplikasi yang memerlukan data terurut. Dalam praktikum, implementasi hash table dalam bahasa C++ menunjukkan bagaimana struktur data ini dapat digunakan untuk mengelola data mahasiswa berdasarkan NIM dan nilai, dengan fungsi-fungsi dasar seperti penambahan, penghapusan, dan pencarian data. Hash table tetap menjadi pilihan yang sangat efektif untuk aplikasi yang membutuhkan kecepatan akses data yang tinggi, dengan catatan penting untuk merancang fungsi hash yang baik dan teknik penanganan tabrakan yang efektif.

## Referensi
[1] Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009). Introduction to Algorithms (3rd ed.). MIT Press.
[2] Weiss, M. A. (2012). Data Structures and Algorithm Analysis in C++ (4th ed.). Pearson.
[3] Goodrich, M. T., Tamassia, R., & Mount, D. M. (2011). Data Structures and Algorithms in C++. Wiley.
[4] Stroustrup, B. (2013). The C++ Programming Language (4th ed.). Addison-Wesley.
[5] Sedgewick, R., & Wayne, K. (2011). Algorithms (4th ed.). Addison-Wesley.
