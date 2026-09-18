#include <iostream>
using namespace std;

const int MAKS_PANJANG = 1000;


int hitungPanjang(char teks[]) {
    int panjang = 0;
    while (teks[panjang] != '\0') {
        panjang++;
    }
    return panjang;
}


int posisiHuruf(char huruf) {
    return (huruf - 'A') + 1;
}


char hurufDariPosisi(int nilai) {
    return (char)((nilai - 1) + 'A');
}


int modPositif(int a, int m) {
    int hasil = a % m;
    if (hasil < 0) {
        hasil = hasil + m;
    }
    return hasil;
}


void enkripsi(char pesan[], char hasil[]) {
    int panjang = hitungPanjang(pesan);

    for (int i = 0; i < panjang; i++) {
        int nilaiAsli = posisiHuruf(pesan[i]);
        int nilaiBaru;

        if (i == 0) {
            nilaiBaru = nilaiAsli; 
        } else {
            int nilaiSebelumnya = posisiHuruf(pesan[i - 1]); 
            int temp = nilaiAsli + nilaiSebelumnya;
            nilaiBaru = modPositif(temp - 1, 26) + 1; 
        }

        hasil[i] = hurufDariPosisi(nilaiBaru);
    }
    hasil[panjang] = '\0';
}


void dekripsi(char sandi[], char asli[]) {
    int panjang = hitungPanjang(sandi);

    for (int i = 0; i < panjang; i++) {
        if (i == 0) {
            asli[i] = sandi[i]; // huruf pertama tidak berubah
        } else {
            int nilaiSandi = posisiHuruf(sandi[i]);
            int nilaiSebelumnyaAsli = posisiHuruf(asli[i - 1]);
            int temp = nilaiSandi - nilaiSebelumnyaAsli;
            int nilaiAsli = modPositif(temp - 1, 26) + 1;
            asli[i] = hurufDariPosisi(nilaiAsli);
        }
    }
    asli[panjang] = '\0';
}

int main() {
    char pesan[MAKS_PANJANG];
    char hasilEnkripsi[MAKS_PANJANG];
    char pesanAsli[MAKS_PANJANG];
    int pilihan;

    cout << "=== Sistem Sandi Alien-In-The-Middle ===" << endl;
    cout << "1. Enkripsi pesan (huruf asli -> pesan tersandi)" << endl;
    cout << "2. Dekripsi pesan (pesan tersandi -> huruf asli)" << endl;
    cout << "Pilih menu (1/2): ";
    cin >> pilihan;

    if (pilihan == 1) {
        cout << "Masukkan pesan asli (huruf kapital, tanpa spasi): ";
        cin >> pesan;
        enkripsi(pesan, hasilEnkripsi);
        cout << "Pesan setelah disandikan: " << hasilEnkripsi << endl;
    } else if (pilihan == 2) {
        cout << "Masukkan pesan tersandi (huruf kapital, tanpa spasi): ";
        cin >> pesan;
        dekripsi(pesan, pesanAsli);
        cout << "Pesan asli: " << pesanAsli << endl;
    } else {
        cout << "Pilihan tidak valid." << endl;
    }

    return 0;
}
