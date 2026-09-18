#include <iostream>
using namespace std;

const int MAKS_N = 1000; 


int astronotBerikutnya(bool hidup[], int n, int dari) {
    int posisi = dari;
    do {
        posisi = (posisi % n) + 1; 
    } while (!hidup[posisi]);
    return posisi;
}

int main() {
    int n, k;

    cout << "=== Sistem Eliminasi Astronot (The Last Astronaut) ===" << endl;
    cout << "Masukkan jumlah astronot (N): ";
    cin >> n;
    cout << "Masukkan nilai awal K: ";
    cin >> k;

    if (n < 1 || n > MAKS_N) {
        cout << "Nilai N tidak valid." << endl;
        return 0;
    }

    bool hidup[MAKS_N + 1];
    for (int i = 1; i <= n; i++) {
        hidup[i] = true;
    }

    int sisa = n;
    int posisi = 1; 

    cout << "\nUrutan astronot yang dieliminasi:" << endl;

    while (sisa > 1) {
        int hitung = 0;

        
        while (hitung < k) {
            if (hidup[posisi]) {
                hitung++;
                if (hitung == k) {
                    break;
                }
            }
            if (hitung < k) {
                posisi = (posisi % n) + 1;
            }
        }

        int dieliminasi = posisi;
        cout << "- Astronot nomor " << dieliminasi << " dieliminasi (nilai K saat itu = " << k << ")" << endl;

        hidup[dieliminasi] = false;
        sisa--;

        
        if (dieliminasi % 2 == 0) {
            k = k + 2;      
        } else {
            k = k - 1;      
        }
        if (k < 2) {
            k = 2;          
        }

        // Tentukan titik awal hitungan untuk putaran berikutnya
        if (sisa > 1) {
            posisi = astronotBerikutnya(hidup, n, dieliminasi);
        }
    }

    // Mencari astronot terakhir yang masih bertahan
    int terakhir = -1;
    for (int i = 1; i <= n; i++) {
        if (hidup[i]) {
            terakhir = i;
        }
    }

    cout << "\nAstronot terakhir yang bertahan: " << terakhir << endl;

    return 0;
}
