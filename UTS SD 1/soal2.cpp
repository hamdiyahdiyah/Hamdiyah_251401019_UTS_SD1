#include <iostream>
#include <string>
using namespace std;

// Node Linked List: menyimpan nama (string) dan skor (int)
struct Node {
    string nama;
    int skor;
    Node* next;
}

Node* head = NULL;
Node* tail = NULL;

// Menu 1: Tambah data di awal
void insertHead(const string& nama, int skor) {
    Node* baru = new Node{nama, skor, head};
    head = baru;
    if (tail == NULL) {
        tail = baru;
    }
}

// Menu 2: Tambah data di akhir
void insertTail(const string& nama, int skor) {
    Node* baru = new Node{nama, skor, NULL};
    if (head == NULL) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

// Menu 3: Hapus data di awal
void deleteHead() {
    if (head == NULL) {
        return; // list kosong, tidak ada yang dihapus
    }
    Node* hapus = head;
    head = head->next;
    if (head == NULL) {
        tail = NULL;
    }
    delete hapus;
}

// Menu 4: Tampilkan HANYA pendaftar yang lolos (Skor >= 75)
void tampilkanLolos() {
    cout << "\n=== Pendaftar yang Lolos (Skor >= 75) ===\n";
    Node* bantu = head;
    int no = 1;
    while (bantu != NULL) {
        if (bantu->skor >= 75) {
            cout << no++ << ". " << bantu->nama << " (Skor: " << bantu->skor << ")\n";
        }
        bantu = bantu->next;
    }
    if (no == 1) {
        cout << "Tidak ada pendaftar yang lolos.\n";
    }
}

void hapusSemua() {
    while (head != NULL) {
        deleteHead();
    }
}

int main() {
    int pilihan;
    do {
        cout << "\n===== MENU PENDAFTAR LOMBA =====\n";
        cout << "1. Tambah data di awal (Insert Head)\n";
        cout << "2. Tambah data di akhir (Insert Tail)\n";
        cout << "3. Hapus data di awal (Delete Head)\n";
        cout << "4. Tampilkan pendaftar yang lolos\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1 || pilihan == 2) {
            string nama;
            int skor;
            cout << "Nama : ";
            getline(cin >> ws, nama);
            cout << "Skor : ";
            cin >> skor;
            if (pilihan == 1) {
                insertHead(nama, skor);
            } else {
                insertTail(nama, skor);
            }
        } else if (pilihan == 3) {
            deleteHead();
        } else if (pilihan == 4) {
            tampilkanLolos();
        } else if (pilihan != 0) {
            cout << "Menu tidak valid.\n";
        }
    } while (pilihan != 0);

    hapusSemua();
    return 0;
}