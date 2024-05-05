# <h1 align="center">Laporan Praktikum Modul Stack</h1>
<p align="center">Ahmad Fariz Gustav</p>


## Dasar Teori
stack merupakan  sebuah  tumpukan  dengan metode LIFO (Last In First Out), yaitu data terakhir yang  masuk  ke  dalam  tumpukan  merupakan  data pertama  yang  akan  dikeluarkan [1]. Stack dapat diibaratkan seperti tumpukan buku di atas meja, di mana buku yang terakhir diletakkan di atas tumpukan adalah yang pertama kali diambil.

![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/dd8a83bc-17d9-42c5-91f9-77e8d0e9639c)

Operasi dasar pada stack meliputi:
- Push: Menambahkan elemen ke dalam stack.
- Pop: Menghapus elemen teratas dari stack.
 -Peek atau Top: Mengakses elemen teratas dari stack tanpa menghapusnya.
- isEmpty: Memeriksa apakah stack kosong.
- isFull: Memeriksa apakah stack penuh (pada implementasi statis).
- Size : Mengembalikan jumlah elemen yang ada dalam tumpukan.
- Peek : Melihat nilai atau elemen pada posisi tertentu dalam tumpukan tanpa menghapusnya.
- Clear : Mengosongkan atau menghapus semua elemen dari tumpukan.
- Search : Mencari keberadaan elemen tertentu dalam tumpukan.


Stack memiliki banyak kelebihan dalam pemrograman, seperti:
- Ekspresi Matematika: Stack digunakan untuk mengevaluasi ekspresi matematika dengan menggunakan notasi infix ke postfix.
- Compiler: Stack digunakan untuk menyimpan informasi tentang variabel dan label selama proses kompilasi.
- Undo/Redo: Stack digunakan untuk menyimpan status program sebelumnya sehingga pengguna dapat membatalkan atau mengulangi tindakan mereka.
- Algoritma Pencocokan Pola: Stack digunakan untuk mencocokkan pola dalam string teks.

Implementasi stack umumnya dilakukan dengan menggunakan array atau linked list. Dengan array, stack direpresentasikan sebagai kumpulan elemen yang disimpan secara berurutan dalam array, dengan sebuah indeks (`top`) untuk melacak elemen teratas. Operasi push menambahkan elemen ke `top`, sementara operasi pop menghapus elemen dari `top`. Namun, ukuran stack tetap dan tidak fleksibel. Implementasi dengan linked list, di sisi lain, memungkinkan stack untuk tumbuh dan menyusut sesuai kebutuhan. Setiap node dalam linked list menyimpan elemen stack dan alamat node berikutnya, sehingga operasi push dilakukan dengan menambahkan node baru, sementara operasi pop dilakukan dengan menghapus node pertama dari linked list. Dengan demikian, pilihan implementasi tergantung pada kebutuhan spesifik dan preferensi pengembang.


## Guided 
#### Kode Program :
```c++
#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull() {
    return (top == maksimal);
}

bool isEmpty() {
    return (top == 0);
}

void pushArrayBuku(string data) {
    if (isFull()) {
        cout << "Data Telah Penuh" << endl;
    } else {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak Ada Data Yang Dihapus" << endl;
    } else {
        arrayBuku[top - 1] = "";
        top--;
    }
}

void peekArrayBuku(int posisi) {
    if (isEmpty()) {
        cout << "Tidak Ada Data Yang Bisa Dilihat" << endl;
    } else {
        int index = top - 1;
        for (int i = 1; i < posisi; i++) {
            index--;
        }
        
        cout << "Posisi Ke-" << posisi << " Adalah " << arrayBuku[index] << endl;
    }
}

int countStack() {
    return top;
}

void changeArrayBuku(int posisi, string data) {
    if (posisi > top) {
        cout << "Posisi Melebihi Data Yang Ada" << endl;
    } else {
        int index = top - 1;
        for (int i = 1; i < posisi; i++) {
            index--;
        }
        arrayBuku[index] = data;
    }
}

void destroyArrayBuku() {
    for (int i = top - 1; i >= 0; i--) {
        arrayBuku[i] = "";
    }
    top = 0;
}

void cetakArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak Ada Data Yang Dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main() {
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Bahasa Inggris");

    cetakArrayBuku();
    cout << "\n";

    cout << "Apakah Data Stack Penuh? " << isFull() << endl;
    cout << "Apakah Data Stack Kosong? " << isEmpty() << endl;

    peekArrayBuku(2);
    popArrayBuku();

    cout << "Banyaknya Data = " << countStack() << endl;
    changeArrayBuku(2, "Bahasa Perancis");
    cetakArrayBuku();

    cout << "\n";

    destroyArrayBuku();
    cout << "Jumlah Data Setelah Dihapus : " << top << endl;
    cetakArrayBuku();
    return 0;
}

```
#### Output :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/2bef7a70-2ff4-49cf-8dd0-469fb5379dff)

Program C++ di atas merupakan implementasi  struktur data stack dengan menggunakan array.
Struktur data bertumpuk merupakan struktur data linier yang mengikuti prinsip LIFO (Last In First Out), dimana elemen terakhir yang disisipkan adalah elemen yang pertama kali dikeluarkan. Program ini memiliki beberapa fungsi yang mewakili operasi dasar pada stack.
Fungsi PushArrayBooks() digunakan untuk menambahkan data buku ke tumpukan. Ketika tumpukan sudah penuh, fungsi isFull() mengembalikan nilai true dan menampilkan pesan "Data sudah penuh. Fungsi PopArrayBooks() digunakan untuk mengeluarkan data buku dari tumpukan.
Jika tumpukan kosong, fungsi isEmpty() mengembalikan nilai true dan pesan "Tidak ada data yang dihapus" ditampilkan.
Fungsi PeakArrayBooks() memungkinkan pengguna  melihat data buku pada posisi tertentu dalam tumpukan.
Jika tumpukan kosong, Anda akan melihat pesan "Tidak dapat menampilkan data".
Fungsi "countStack()" digunakan untuk menghitung jumlah data dalam tumpukan. Fungsi changeArrayBooks() memungkinkan pengguna  mengubah data buku pada posisi tertentu dalam tumpukan. Jika posisi yang Anda masukkan melebihi jumlah data yang ada dalam batch, pesan ``Posisi melebihi data yang ada'' akan ditampilkan. Fungsi destroyArrayBooks() digunakan untuk menghapus semua data dalam tumpukan dan mereset variabel tingkat atas. Fungsi printArrayBook() digunakan untuk mencetak semua data buku di layar sekaligus.
Jika batch kosong, pesan "Tidak ada data yang akan dicetak" akan ditampilkan. Fungsi main() melakukan operasi tumpukan seperti push, pop, peek, dan destroy  untuk menguji implementasi struktur data tumpukan yang dibuat. 

#### Full Code Screenshot :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/58ad4c32-bb90-46bc-ad88-d05f0c8e8539)

## Unguided 
### 1. Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya.

Kode Program :
```c++
#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

bool isPalindrome(string sentence) {
    // Menghapus spasi dan karakter non-alphanumeric dari kalimat
    string cleanSentence = "";
    for (char c : sentence) {
        if (isalnum(c)) {
            cleanSentence += tolower(c);
        }
    }
    
    // Membuat objek stack
    stack<char> charStack;
    
    // Menambahkan setiap karakter ke dalam stack
    for (char c : cleanSentence) {
        charStack.push(c);
    }
    
    // Membuat kalimat terbalik dengan menggunakan stack
    string reversedSentence = "";
    while (!charStack.empty()) {
        reversedSentence += charStack.top();
        charStack.pop();
    }
    
    // Memeriksa apakah kalimat asli sama dengan kalimat terbalik
    return cleanSentence == reversedSentence;
}

int main() {
    // Input kalimat dari pengguna
    string kalimat;
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);
    
    // Memeriksa apakah kalimat adalah palindrom
    if (isPalindrome(kalimat)) {
        cout << "Kalimat tersebut adalah palindrom." << endl;
    } else {
        cout << "Kalimat tersebut bukan palindrom." << endl;
    }
    
    return 0;
}
```

#### Output :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/2215f90c-07c6-4425-a9ab-ca16a3e49ba7)

Program ini menggunakan fungsi isPalindrome(). Fungsi ini mengambil  string sebagai argumen dan mengembalikan nilai Boolean yang menunjukkan apakah string tersebut merupakan palindrom. Fungsi ini menghilangkan spasi dan karakter non-alfanumerik dari kumpulan dan menyisipkan setiap karakter  ke dalam  struktur data tumpukan. Karakter-karakter ini kemudian dikeluarkan dari tumpukan untuk membuat kalimat terbalik dan dibandingkan dengan kalimat asli untuk menentukan apakah itu palindrom.
Program kemudian menampilkan hasilnya di layar.

#### Full code Screenshot :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/6816d037-a257-47b7-9627-d8954941d6ac)

### 2. Buatlah program untuk melakukan pembalikan terhadap kalimat menggunakan stack dengan minimal 3 kata. Jelaskan output program dan source codenya beserta operasi/fungsi yang dibuat?

```c++
##include <iostream>
#include <stack>
#include <sstream>
#include <algorithm>

using namespace std;

void balikKalimat(const string & kalimat) {
    int jumlahSpasi = count(kalimat.begin(), kalimat.end(), ' ');
    if (jumlahSpasi < 2) {
        cout << "Kalimat Harus Memiliki Minimal 3 Kata" << endl;
        return;
    }

    // Buat Stack (Tumpukan)
    stack<string> kata;

    // Memisahkan Kalimat Menjadi Kata Dan Menyimpannya Dalam Stack
    string kataSementara;
    stringstream ss(kalimat);
    while (getline(ss, kataSementara, ' ')) {
        kata.push(kataSementara);
    }

    // Membalikkan Urutan Kata Di Dalam Stack
    string kalimatTerbalik;
    while (!kata.empty()) {
        // Mengambil Kata Dari Stack Dan Membalik Urutannya
        string kataBalik = kata.top();
        reverse(kataBalik.begin(), kataBalik.end());
        kalimatTerbalik += kataBalik + " ";
        kata.pop();
    }

    // Menghapus Spasi Di Akhir
    kalimatTerbalik.erase(kalimatTerbalik.length() - 1);

    cout << "Kalimat Setelah Dibalik : " << kalimatTerbalik << endl;
}

int main() {
    string kalimat;

    cout << "Masukkan Sebuah Kalimat : ";
    getline(cin, kalimat);

    balikKalimat(kalimat);

    return 0;
}
```
#### Output :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/848ced44-14d7-42ed-be40-29ef81e3ab68)

Program di atas bertujuan untuk membalik urutan kata dalam  kalimat yang dimasukkan oleh pengguna. Program pertama-tama memeriksa jumlah spasi dalam kalimat untuk memastikan bahwa kalimat tersebut berisi setidaknya tiga kata.Jika jumlah spasi kurang dari 2, program  menampilkan pesan ``Kalimat harus berisi minimal 3 kata'' dan berhenti. Program kemudian membuat  objek Stack bertipe String untuk menyimpan kata-kata dalam urutan terbalik. Kalimat tersebut dipecah menjadi kata-kata menggunakan Stringstream dan setiap kata ditambahkan ke tumpukan. Program kemudian membalikkan urutan kata  dalam tumpukan dengan mengeluarkan setiap kata dari tumpukan, menggunakan fungsi reverse() untuk membalikkan urutan, dan menyimpannya dalam string "kalimat terbalik". Spasi  akhir dari string "pernyataan pencarian terbalik" dihilangkan dan pernyataan pencarian terbalik ditampilkan di layar. Oleh karena itu, program ini memanfaatkan secara praktis  struktur data tumpukan dan manipulasi string untuk melakukan pembalikan urutan kata dalam sebuah kalimat.

#### Full code screenshot :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/da17fcbb-11bf-415b-a35b-ecb7e89bd2e9)

## Kesimpulan
stack adalah struktur data yang mengikuti prinsip Last In, First Out (LIFO), di mana elemen terakhir yang dimasukkan adalah yang pertama kali dikeluarkan. Ini adalah struktur data sederhana yang terdiri dari operasi dasar seperti push (menambahkan elemen), pop (menghapus elemen teratas), dan peek (melihat elemen teratas tanpa menghapusnya). Stack sering digunakan dalam pemrograman untuk berbagai tujuan, termasuk dalam pemanggilan fungsi, evaluasi ekspresi matematika, manajemen memori, dan pengurutan data. Implementasi stack dapat dilakukan menggunakan array atau linked list, dengan masing-masing memiliki kelebihan dan kekurangan tertentu. Dengan fleksibilitas dan efisiensi operasinya, stack menjadi salah satu struktur data yang penting dan sering digunakan dalam pengembangan perangkat lunak.

## Referensi
[1] Putri, G. M., Pradja, K. A. D., Azizi, M. B., Nurwahid, P., Perdana, A. S., & ., M. (2024). Implementasi Stack dan Array pada Pengurutan Lagu dengan Metode Selection Sort. Jurnal Teknologi Dan Sistem Informasi Bisnis, 6(2), 286-296. https://doi.org/10.47233/jteksis.v6i2.119


