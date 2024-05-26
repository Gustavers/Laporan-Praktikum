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
