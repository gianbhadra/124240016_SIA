#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

struct kendaraan {
    string plat; 
    string jenis;
    string merk;
    string model;
    string pemilik;
    int tahun;
};

void bubblesort(kendaraan data[], int jmlhdt){
    bool swapped;
    for (int i = 0; i < jmlhdt - 1; i++){
        for(int j = 0; j < jmlhdt - i - 1; j++){
            if (data[j].tahun > data[j + 1].tahun){
                swap(data[j],data[j + 1]);
                swapped = true;
            }
        } if (!swapped) break;
    } cout<<"Data telah diurutkan berdasarkan tahun produksi/n";
}

void quicksort(kendaraan data[], int awal, int akhir) {
    if (awal >= akhir) return;

    int low = awal, high = akhir;
    int pivot = data[(awal + akhir) / 2].tahun;

    while (low <= high) {
        while (data[low].tahun < pivot) low++;
        while (data[high].tahun > pivot) high--;
        if (low <= high) {
            swap(data[low], data[high]);
            low++;
            high--;
        }
    }
    quicksort(data, awal, high);
    quicksort(data, low, akhir);
}

int sequentialSearch(kendaraan data[], int jmldt, string key) {
    for (int i = 0; i < jmldt; i++) {
        if (data[i].pemilik == key) {
            return i;
        }
    }
    return -1;
}

int main(){
    int jmldt = 0;
    kendaraan data[100];
    char menu;

awal:
    cout << "\n=== Menu ===" << endl
         << "1. Input Data" << endl
         << "2. Tampilkan Seluruh Data" << endl
         << "3. Urutkan Data Kendaraan (Bubble Sort)" << endl
         << "4. Urutkan Data Kendaraan (Quick Sort)"<< endl
         << "5. Cari Data Kendaraan (Sequential Search)" << endl  
         << "6. Keluar" << endl
         << "--------------------------------" << endl;
    cout << "Pilih menu: "; cin >> menu;
    cin.ignore();
    system("cls");

    switch (menu){
        case '1': {
            int jmlinput;
            cout << "Masukan Jumlah Kendaraan: "; cin >> jmlinput;
            cin.ignore();

            for (int i = 0; i < jmlinput && jmldt < 100; i++) {
                cout << "\nKendaraan ke-" << jmldt + 1 << endl;
                cout << "Masukan Nomor Plat: "; cin >> data[jmldt].plat;
                cout << "Masukan Jenis Kendaraam (mobil/motor): "; cin >> data[jmldt].jenis;
                cout << "Masukan Merk Kendaraan: "; cin >> data[jmldt].merk;
                cout << "Masukan Model Kendaraan: "; cin >> data[jmldt].model;
                cout << "Masukan Nama Pemilik: "; cin >> data[jmldt].pemilik;
                cout << "Masukan Tahun Produksi: "; cin >> data[jmldt].tahun;
            }
            cout << "Tekan Enter untuk kembali ke menu...";
            cin.ignore();
            cin.get();
            system("cls");
            goto awal;
        }
        
        case '2': {
            if (jmldt == 0) {
                cout << "Belum ada data mahasiswa yang diinput." << endl;
            } else {
                cout << "=== Data Kendaraan ===" << endl;
                for (int i = 0; i < jmldt; i++) {
                    cout << "\nKendaraan ke-" << i + 1 << endl;
                    cout << "Nomor Plat: " << data[i].plat << endl;
                    cout << "jenis Kendaraan: " << data[i].jenis << endl;
                    cout << "Merk Kendaraan: " << data[i].merk << endl;
                    cout << "Model Kendaraan: " << data[i].model << endl;
                    cout << "Nama Pemilik: " << data[i].pemilik << endl;
                    cout << "Tahun Produksi: " << data[i].tahun << endl;
                }
            }
            
            cout << "Tekan Enter untuk kembali ke menu...";
            cin.ignore();
            cin.get();
            system("cls");
            goto awal;
        }

        case '3': {
            if (jmldt == 0) {
                cout << "Belum ada data yang bisa diurutkan." << endl;
            } else {
                bubblesort(data, jmldt);
                cout << "Data berhasil diurutkan berdasarkan Tahun Produksi!" << endl;
            }
            cout << "Tekan Enter untuk kembali ke menu...";
            cin.ignore();
            cin.get();
            system("cls");
            goto awal;
        }

        case '4': {
            if (jmldt == 0) {
                cout << "Belum ada data yang bisa diurutkan.\n";
            } else {
                quicksort(data, 0, jmldt - 1);
                cout << "Data berhasil diurutkan menggunakan Quick Sort!\n";
            }
            cout << "Tekan Enter untuk kembali ke menu...";
            cin.ignore();
            cin.get();
            system("cls");
            goto awal;
        }

        case '5': {
            if (jmldt == 0) {
                cout << "Belum ada data yang bisa diurutkan.\n";
            } else {
                string key;
                cout << "Masukan nama pemilik yang di cari: "; getline(cin, key);

                int index = sequentialSearch(data, jmldt, key);
                if (index != -1){
                    cout << "Data ditemukan pada index ke-" << index + 1 << "\n";
                    cout << "Nomor Plat: " << data[index].plat << endl;
                    cout << "Jenis Kendaraan: " << data[index].jenis << endl;
                    cout << "Merk Kendaraan: " << data[index].merk << endl;
                    cout << "Model Kendaraan: " << data[index].model << endl;
                    cout << "Nama Pemilik: " << data[index].pemilik << endl;
                    cout << "Tahun Produksi: " << data[index].tahun << endl;
                } else {
                    cout << "Data tidak ditemukan!\n" << endl;
                }
            }
            cout << "Tekan Enter untuk kembali ke menu...";
            cin.ignore();
            cin.get();
            system("cls");
            goto awal;
        }

        case '6': {
            cout << "Terimakasih sudah menggunakan program ini" << endl;
        }

        default:
            cout << "Pilihan tidak valid, silahkan pilih lagi!" << endl;
            cout << "Tekan Enter untuk kembali ke menu...";
            cin.ignore();
            cin.get();
            system("cls");
            goto awal;
    }
}