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
            if (data[j].tahun > data[j + i].tahun){
                swap(data[j],data[j + 1]);
                swapped = true;
            }
        } if (!swapped) break;
    } cout<<"Data telah diurutkan berdasarkan tahun produksi/n";
}

void printarray(kendaraan data[], int size){
    for (int i=0; i<size; i++){
        cout<<data[i].tahun<<" ";
    }
    cout<<"\n";
}

void quicksort(kendaraan data[], int awal, int akhir, int size){
    int low = awal, high = akhir;

    int pivot = data[(awal+akhir)/2].tahun;
    cout<<"\npivot: "<<pivot<<"\n";
    do{
        while (data[low].tahun<pivot)
        low++;
        while (data[high].tahun>pivot)
        high--;
    if (low <= high){
        swap(data[low].tahun, data[high].tahun);
        printarray(data, size);
        low++;
        high--;
    }
    } while (low <= high);
    if (awal < high) quicksort(data, awal, high, size);
    if (low < akhir) quicksort(data, low, akhir, size);
}
