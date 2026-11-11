#include <iostream>
using namespace std;

int main() {
    int angka[2][3][4];

    // Mengisi lapis pertama dengan bilangan genap
    int genap = 2;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            angka[0][i][j] = genap;
            genap += 2;
        }
    }

    // Mengisi lapis kedua dengan bilangan ganjil
    int ganjil = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            angka[1][i][j]= ganjil;
            ganjil += 2;
        }
    }

    // Menampilkan hasil penjumlahan
    cout << "hasil penjumlahan lapis 1 (genap) "
         << "dan lapis 2 (ganjil):" << endl;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << angka[0][i][j] + angka[1][i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}