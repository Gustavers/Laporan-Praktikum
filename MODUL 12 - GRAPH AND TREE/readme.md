# <h1 align="center">Laporan Praktikum Modul Graph and Tree</h1>
<p align="center">Ahmad Fariz Gustav</p>
<p align="center">2311110012</p>
<p align="center">S1SD-04-A</p>

## Dasar Teori

Graph dan tree adalah dua struktur data yang penting dalam pemrograman dan algoritma. Keduanya digunakan untuk merepresentasikan hubungan atau struktur hierarki antara entitas[1]. Meskipun keduanya memiliki persamaan dalam beberapa aspek, mereka juga memiliki perbedaan yang signifikan dalam sifat dan penggunaannya.

**Graph:**
- Graph adalah struktur data yang terdiri dari serangkaian simpul (nodes) yang terhubung oleh sisi (edges).
- Setiap sisi dapat memiliki bobot atau tidak, tergantung pada apakah grafnya berbobot atau tidak.
- Graph dapat digunakan untuk merepresentasikan berbagai jenis hubungan antara entitas, seperti jaringan sosial, jaringan komputer, rute perjalanan, dan banyak lagi.
- Graph dapat dibagi menjadi dua jenis utama:
  - Directed Graph (digraf): Graf di mana setiap sisi memiliki arah.
  - Undirected Graph (graf tak berarah): Graf di mana sisi-sisinya tidak memiliki arah.

Ada beberapa jenis graph yang umum digunakan:

- Directed Graph (Digraph): Graph di mana setiap busur memiliki arah, sehingga hubungan antara dua simpul tidak selalu saling simetris.
- Undirected Graph: Graph di mana setiap busur tidak memiliki arah, sehingga hubungan antara dua simpul bersifat simetris.
- Weighted Graph: Graph di mana setiap busur memiliki bobot yang menyatakan nilai numerik yang terkait dengan busur tersebut.
- Cyclic Graph: Graph yang memiliki setidaknya satu siklus, yaitu rangkaian simpul yang membentuk jalur tertutup.
- Acyclic Graph: Graph yang tidak memiliki siklus, sehingga tidak ada jalur yang membentuk loop.

**Tree:**
- Tree adalah jenis khusus dari graf yang tidak memiliki sirkuit tertutup (cycle), artinya tidak ada dua simpul yang terhubung oleh lebih dari satu jalur[2].
- Setiap simpul dalam tree memiliki tepat satu simpul induk (parent), kecuali simpul teratas yang disebut sebagai akar (root).
- Tree sering digunakan untuk merepresentasikan hierarki, seperti struktur file dalam sistem operasi, struktur organisasi dalam perusahaan, atau struktur gen dalam biologi[3].
- Beberapa jenis tree yang umum digunakan meliputi:
  - Binary Tree: Setiap simpul memiliki maksimal dua anak.
  - Binary Search Tree (BST): Binary tree di mana setiap simpul memiliki nilai yang lebih besar dari semua nilai di anak kiri dan lebih kecil dari semua nilai di anak kanan.

## Guided 
### Guided 1
Kode Program :
```c++
#include <iostream>
#include <iomanip>

using namespace std;

string simpul[7] = {
    "Ciamis", "Bandung", "Bekasi", "Tasikmalaya", "Cianjur", "Purwokerto", "Yogyakarta"
};

int busur[7][7] = {
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 0, 15, 0},
    {0, 6, 0, 0, 5, 0, 0},
    {0, 5, 0, 0, 2, 4, 0},
    {23, 0, 0, 10, 0, 0, 8},
    {0, 0, 0, 0, 7, 0, 3},
    {0, 0, 0, 0, 9, 4, 0}   
};

void tampilGraph() {
    for (int baris = 0; baris < 7; baris++) {
        cout << " " << setiosflags(ios::left) << setw(15) << simpul[baris] << " : ";
        for (int kolom = 0; kolom < 7; kolom++) {
            if (busur[baris][kolom] != 0) {
                cout << " " << simpul[kolom] << " (" << busur[baris][kolom] << ")";
            }
        }
        cout << endl;
    }
}

int main() {
    tampilGraph();
    return 0;
}

```
#### Output :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/0cff7520-1bfd-425b-b741-006732d69ff9)

Kode diatas merepresentasikan sebuah graf berarah yang terdiri dari simpul-simpul dan busur-busur antara simpul-simpul tersebut. Setiap simpul direpresentasikan oleh string yang disimpan dalam array `simpul`, dan setiap busur diwakili oleh bobotnya yang disimpan dalam array 2 dimensi `busur`.
Fungsi `tampilGraph()` digunakan untuk menampilkan graf ke layar. Ini dilakukan dengan iterasi melalui array `simpul` untuk setiap simpul, dan kemudian untuk setiap simpul itu, kita memeriksa apakah ada busur yang terhubung ke simpul lain (yaitu dengan bobot tidak nol). Jika ada, informasi tentang simpul tersebut ditampilkan bersama dengan simpul-simpul yang terhubung kepadanya dan bobot masing-masing.
Di dalam `main()`, fungsi `tampilGraph()` dipanggil untuk menampilkan graf saat program dijalankan.
Ketika program dijalankan, ia akan menampilkan output yang menunjukkan hubungan antara simpul-simpul beserta bobot-bobot busurnya.

#### Full Code Screenshot :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/4ef5ca3c-e9e8-460f-b106-71564ec57b4c)

### Guided 2

Kode Program :
```c++

#include <iostream>
using namespace std;

struct TNode {
    int data;
    TNode *left;
    TNode *right;

    // Constructor
    TNode (int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void preOrder(TNode *node) {
    if (node != NULL) {
        cout << node->data << " ";
        preOrder (node->left);
        preOrder (node->right);
    }
}

void inOrder(TNode *node) {
    if (node != NULL) {
        inOrder (node->left);
        cout << node->data << " ";
        inOrder (node->right);
    }
}

void postOrder(TNode *node) {
    if (node != NULL) {
        preOrder (node->left);
        preOrder (node->right);
        cout << node->data << " ";
    }
}

int main() {
    TNode *zero = new TNode(0);

    TNode *one = new TNode(1);
    TNode *five = new TNode(5);
    TNode *seven = new TNode(7);
    TNode *eight = new TNode(8);
    TNode *nine = new TNode(9);

    seven->left = one;

    seven->right = nine;

    one->left = zero;

    one->right = five;

    nine->left = eight;

    preOrder(seven);
    cout << endl;

    inOrder(seven);
    cout << endl;

    postOrder(seven);
    cout << endl;

    return 0;
}
```
#### Output :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/1eeb016b-717a-4a37-96fe-8c8c52946c9b)

**interpretasi hasil :**
Kode di atas implementasi dari struktur data pohon biner dan tiga metode penelusuran pohon biner: pre-order, in-order, dan post-order.

- Struktur data `TNode` mendefinisikan simpul-simpul dari pohon biner. Setiap simpul memiliki data integer dan dua pointer yang menunjuk ke simpul anak kiri dan kanan.
- Fungsi `preOrder`, `inOrder`, dan `postOrder` digunakan untuk melakukan penelusuran pohon biner sesuai dengan urutan yang ditentukan.
- Di dalam `main()`, terdapat pembuatan beberapa simpul dan pengaturan hubungan antara simpul-simpul tersebut untuk membentuk pohon biner. Kemudian, ketiga metode penelusuran tersebut dipanggil dengan melewati simpul akar dari pohon biner.
- Setiap metode penelusuran akan mencetak nilai simpul sesuai dengan urutan penelusuran yang dipilih.

Hasil dari program ini akan mencetak nilai-nilai simpul sesuai dengan urutan pre-order, in-order, dan post-order, masing-masing diikuti dengan spasi.


#### Full Code Screenshot :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/77b11eb0-eda7-4bad-b44c-2bc68d69f49e)


## Unguided 
### 1.  Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya.

Kode Program :
```c++
#include <stdio.h>
#include <time.h>

// Struktur Untuk Representasi Graph
typedef struct {
    char nama[20];
    int jarak[10];
} Kota;

int main() {
    int n;
    printf("Masukkan Jumlah Simpul : ");
    scanf("%d", &n);
    
    Kota kota[n];
    for (int i = 0; i < n; i++) {
        printf("Masukkan Nama Simpul Ke-%d : ", i + 1);
        scanf("%s", kota[i].nama);
    }
    
    printf("Masukkan Bobot Antar Simpul\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%s--->%s = ", kota[i].nama, kota[j].nama);
            scanf("%d", &kota[i].jarak[j]);
        }
    }
    
    printf("\n");

    // Header Kolom
    printf("%-8s", "");
    for (int i = 0; i < n; i++) {
        printf("%-8s", kota[i].nama);
    }
    printf("\n");

    // Matriks Bobot
    for (int i = 0; i < n; i++) {
        printf("%-8s", kota[i].nama);
        for (int j = 0; j < n; j++) {
            printf("%-8d", kota[i].jarak[j]);
        }
        printf("\n");
    }
    
    printf("\nProcess Returned 0 (0x0)   Execution Time : ");
    
    // Menghitung Waktu Eksekusi
    clock_t start = clock();
    // Simulasi Proses Yang Memakan Waktu
    for (int i = 0; i < 100000000; i++);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%.3f s\n", time_spent);
    printf("Press Any Key To Continue.\n");

    return 0;
}
```

#### Output :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/2b8cb4f3-37eb-4d8c-9407-4c0afcec3e45)


Kode di atas merupakan program dalam bahasa C yang memungkinkan pengguna untuk memasukkan jumlah simpul dari sebuah graf, nama-nama simpul, dan bobot antar simpul. Program kemudian menampilkan matriks bobot yang merepresentasikan graf berdasarkan masukan pengguna.

- Pertama, program meminta pengguna untuk memasukkan jumlah simpul.
- Kemudian, program meminta pengguna untuk memasukkan nama-nama simpul satu per satu.
- Selanjutnya, pengguna diminta untuk memasukkan bobot antar simpul, yang direpresentasikan sebagai matriks bobot.
- Setelah itu, program menampilkan matriks bobot tersebut di layar.
- Selanjutnya, program melakukan simulasi proses yang memakan waktu (dalam contoh ini, sebuah loop yang berjalan sebanyak 100 juta kali).
- Program juga mencatat waktu eksekusi dari awal hingga akhir proses yang memakan waktu tersebut.
- Terakhir, program mencetak waktu eksekusi yang dihabiskan dan pesan untuk menekan tombol apa pun untuk melanjutkan.

Saat dijalankan, program akan meminta input dari pengguna, menampilkan matriks bobot, mencatat waktu eksekusi dari proses simulasi, dan kemudian mengakhiri program setelah pengguna menekan tombol apa pun.


#### Full Code Screenshot :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/6c214552-6af0-48c1-a1d9-1877863e49fe)


### 2. Modifikasi guided tree diatas dengan program menu menggunakan input data tree dari user dan berikan fungsi tambahan untuk menampilkan node child dan descendant dari node yang diinput kan!

Kode Program :
```c++
#include <iostream>
#include <queue>
using namespace std;

struct TNode {
    int data;
    TNode *left;
    TNode *right;

    // Konstruktor
    TNode(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void preOrder(TNode *node) {
    if (node != NULL) {
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void inOrder(TNode *node) {
    if (node != NULL) {
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
}

void postOrder(TNode *node) {
    if (node != NULL) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}

void printChild(TNode *node) {
    if (node != NULL) {
        cout << "Anak Dari " << node->data << " : ";
        if (node->left != NULL) {
            cout << node->left->data << " ";
        }
        if (node->right != NULL) {
            cout << node->right->data << " ";
        }
        if (node->left == NULL && node->right == NULL) {
            cout << "Tidak Ada Anak.";
        }
        cout << endl;
    }
}

void printDescendant(TNode *node) {
    if (node != NULL) {
        if (node->left != NULL || node->right != NULL) {
            cout << "Turunan Dari " << node->data << " : ";
            queue<TNode*> q;
            if (node->left != NULL) q.push(node->left);
            if (node->right != NULL) q.push(node->right);
            while (!q.empty()) {
                TNode* temp = q.front();
                q.pop();
                cout << temp->data << " ";
                if (temp->left != NULL) q.push(temp->left);
                if (temp->right != NULL) q.push(temp->right);
            }
            cout << endl;
        } else {
            cout << "Turunan Dari " << node->data << " : Tidak Ada Turunan." << endl;
        }
    }
}

TNode* findNode(TNode* node, int value) {
    if (node == NULL) return NULL;
    if (node->data == value) return node;
    TNode* foundNode = findNode(node->left, value);
    if (foundNode == NULL) {
        foundNode = findNode(node->right, value);
    }
    return foundNode;
}

int main() {
    int n;
    cout << "Masukkan Jumlah Node : ";
    cin >> n;

    TNode *root = NULL;

    for (int i = 0; i < n; i++) {
        int value;
        cout << "Masukkan Nilai Node " << i + 1 << " : ";
        cin >> value;

        TNode *node = new TNode(value);

        if (root == NULL) {
            root = node;
        } else {
            // Temukan Node Induk
            int parentValue;
            cout << "Masukkan Node Induk Dari " << value << " : ";
            cin >> parentValue;
            TNode *parent = findNode(root, parentValue);
            if (parent == NULL) {
                cout << "Node Induk Tidak Dapat Ditemukan!" << endl;
                delete node;
                i--;
                continue;
            }
            if (parent->left == NULL) {
                parent->left = node;
            } else if (parent->right == NULL) {
                parent->right = node;
            } else {
                cout << "Node Induk Sudah Memiliki Dua Anak!" << endl;
                delete node;
                i--;
            }
        }
    }

    cout << "\nTraversal Pre-Order      : ";
    preOrder(root);
    cout << endl;

    cout << "Traversal In-Order       : ";
    inOrder(root);
    cout << endl;

    cout << "Traversal Post-Order     : \n";
    postOrder(root);
    cout << endl;

    for (int i = 0; i < n; i++) {
        printChild(findNode(root, i + 1));
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        printDescendant(findNode(root, i + 1));
    }
    cout << endl;

    return 0;
}
```

#### Output :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/e7d9accc-a1be-4edd-bb86-27ef7a91db3b)


Program ini adalah implementasi dari pohon biner menggunakan struktur data dan fungsi-fungsi untuk melakukan penelusuran dan pencetakan informasi tentang simpul-simpul dalam pohon.

- `struct TNode` mendefinisikan simpul dalam pohon biner dengan data integer dan pointer ke simpul anak kiri dan kanan.
- `preOrder`, `inOrder`, dan `postOrder` adalah fungsi-fungsi rekursif untuk melakukan penelusuran pre-order, in-order, dan post-order pada pohon biner.
- `printChild` adalah fungsi untuk mencetak informasi tentang anak-anak dari sebuah simpul.
- `printDescendant` adalah fungsi untuk mencetak informasi tentang turunan (anak-anak dan cucu) dari sebuah simpul.
- `findNode` adalah fungsi rekursif untuk mencari simpul dengan nilai tertentu dalam pohon.

Di dalam `main()`:
- Pengguna diminta untuk memasukkan jumlah node dan nilai-nilai dari setiap node.
- Node-node tersebut dibangun dan dimasukkan ke dalam pohon sesuai dengan nilai node induk yang diberikan oleh pengguna.
- Setelah pohon dibangun, program menampilkan traversal pre-order, in-order, dan post-order dari pohon.
- Program juga mencetak informasi tentang anak-anak dan turunan dari setiap simpul dalam pohon.

Saat dijalankan, program akan meminta input dari pengguna, membangun pohon biner berdasarkan input tersebut, dan kemudian menampilkan traversal pohon serta informasi tentang anak-anak dan turunannya.


#### Full Code Screenshot :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/4264fba0-0547-4f38-90c3-a5e10f9f7c7f)

## Kesimpulan
Graph dan tree adalah struktur data penting dalam ilmu komputer yang memiliki beragam aplikasi dalam pemodelan dan pemecahan masalah. Graph digunakan untuk merepresentasikan hubungan antara objek atau entitas dalam berbagai domain, seperti jaringan sosial, jaringan komputer, dan perencanaan rute. Sementara itu, tree digunakan untuk menggambarkan hierarki data, seperti struktur direktori pada sistem file dan struktur organisasi perusahaan. Kedua struktur data ini memiliki berbagai jenis dan karakteristik yang memengaruhi implementasi dan algoritma yang digunakan. Studi tentang graph dan tree memberikan wawasan mendalam tentang struktur data dan algoritma yang penting dalam pengembangan perangkat lunak dan pemrosesan informasi.

## Referensi
[1] Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, and Clifford Stein. (2009). "Introduction to Algorithms, Third Edition." MIT Press.

[2] Robert Sedgewick and Kevin Wayne. (2011). "Algorithms, Fourth Edition." Addison-Wesley.

[3] Robert L. Kruse, Clovis L. Tondo, and Bruce P. Leung. (2009). "Data Structures and Program Design in C++." Pearson.