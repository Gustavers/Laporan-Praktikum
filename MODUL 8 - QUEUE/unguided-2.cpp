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
