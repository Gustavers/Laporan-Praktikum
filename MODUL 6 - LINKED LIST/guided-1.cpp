#include <iostream>
using namespace std;

//deklarasi struct
struct Node {
    string data;
    Node *next;
};

Node *head, *tail, *baru, *bantu, *hapus;

void init() {
    head = NULL;
    tail = head;
}

//pengecekan
int isEmpty() {
    if (head == NULL)
        return 1;//true
    else
        return 0;//false
}

//buat Node baru
void buatnode(string data) {
    baru = new Node;
    baru->data = data;
    baru->next = NULL;
}

//hitung list
int hitungList() {
    bantu = head;
    int jumlah = 0;

    while (bantu != NULL) {
        jumlah++;
        bantu = bantu->next;
    }

    return jumlah;
}

//tambah depan
void insertDepan(string data) {
    //buat node baru
    buatnode(data);

    if (isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        while (tail->next != head) {
            tail = tail->next;
        }
        baru->next = head;
        head = baru;
        tail->next = head;
    }


}

void insertBelakang() {

    buatnode(data);

    if (isEmpty () == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        while (tail->next != head) {
            tail = tail->next;
        }

        tail->next = baru;
        baru->next = head;
    }
}

void insertTengah(string data, int posisi) {
    if (isEmpty() == 1) {
        head = baru;
        tail = head;
        baru ->next = head;
    } else {
        baru -> data = data;
    }
    //transversing
    int nomor = 1;
    bantu = head;

    while  (nomor < posisi - 1) {
        bantu = bantu->next;
        nomor++;
    }

    baru->next = bantu->next;
    bantu->next = baru;
}


