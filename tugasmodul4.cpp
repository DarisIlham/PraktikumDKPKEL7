#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Produk {
public:
    string nama;
    int harga;
    int stok;

    Produk(string n, int h, int s) : nama(n), harga(h), stok(s) {}
};
// commit syafikbarda
class kasir {
private:
    vector<Produk> produk;
    int totalbelanja;

public:
    kasir() : totalbelanja(0) {
        produk.push_back(Produk("Buku", 5000, 10));
        produk.push_back(Produk("Pensil", 1000, 20));
        produk.push_back(Produk("Pulpen", 2000, 15));
    }

    void tampilkanproduk() {
        cout << "Daftar Produk:" << endl;
        for (int i = 0; i < produk.size(); ++i) {
            cout << i + 1 << ". " << produk[i].nama << " - Harga: " << produk[i].harga << " - Stok: " << produk[i].stok << endl;
        }
    }

    void beliproduk(int produkIndex, int jumlah) {
        Produk& produks = produk[produkIndex - 1];
        if (produks.stok >= jumlah) {
            int totalharga = produks.harga * jumlah;
            cout << "anda telah berbelanja sebanyak  " << produks.nama << " sebanyak " << jumlah << " dengan total harga " << totalharga << endl;
            totalbelanja += totalharga;
            produks.stok -= jumlah;
        } else {
            cout << "Mohon maaf, stok tidak tersedia dalam jumlah tersebut." << endl;
        }
    }

    void Totalbelanja() {
        cout << "Total belanja Anda adalah sebanyak: " << totalbelanja << endl;
    }

    void tampilkanmenu() {
        cout << "\nselamat datang di toko kelompok 7" << endl;
        cout << "\nMenu:" << endl;
        cout << "1. Tampilkan Produk" << endl;
        cout << "2. Beli Produk" << endl;
        cout << "3. Total Belanja" << endl;
        cout << "4. Keluar" << endl;
    }

    void run() {
        while (true) {
            tampilkanmenu();
            int pilihan;
            cout << "Pilih menu: ";
            cin >> pilihan;

            switch (pilihan) {
                case 1:
                    tampilkanproduk();
                    break;

                case 2: {
                int produkIndex, jumlah;
                char lanjut = 'y';
                while (lanjut == 'y' || lanjut == 'Y') {
                    cout << "Masukkan nomor produk yang ingin Anda beli: ";
                    cin >> produkIndex;
                    cout << "Masukkan jumlah yang ingin Anda beli: ";
                    cin >> jumlah;
                    beliproduk(produkIndex, jumlah);
                    cout << "Apakah Anda ingin melanjutkan pembelian? (y/n): ";
                    cin >> lanjut;
                    }
                    break;
                }
                case 3:
                    Totalbelanja();
                    break;
                case 4:
                    cout << "Terima kasih telah berbelanja di toko kami" << endl;
                    return;
                default:
                    cout << "Pilihan tidak valid, silakan coba lagi." << endl;
            }
        }
    }
};

int main() {
    kasir Kasir;
    Kasir.run();
    return 0;
}
//komen justin