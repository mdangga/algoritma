#include <iostream>
#include <set>
#include <map>

//sahfajlh
using namespace std;

const int karyawanMaks = 100;


int karyawanMendapatkan8Juta = 0;

void tampil_hasil(long long distribusiSekarang[], int index) {
    cout << "Output: " << index << " orang\n";

    for (int i = 0; i < index; ++i) {
        cout << "Karyawan " << i + 1 << ": Rp. " << distribusiSekarang[i] << endl;
        if (distribusiSekarang[i] == 8000000) {
            karyawanMendapatkan8Juta++;
        }
    }cout << "Jumlah karyawan yang menerima Rp. 8 juta: ";
    if(distribusiSekarang[i] == 8000000){
        cout<< karyawanMendapatkan8Juta << endl;
    }else{
        cout << "Tidak Diketahui" <<endl;
    }
    exit(0);
}


void proses_distribusi(long long total, int sisaKaryawan, long long distribusiSekarang[], int index, set<string>& dikunjungi, map<string, bool>& temp) {
    if (sisaKaryawan == 0) {
        for (int i = 0; i < index; ++i) {
            if (distribusiSekarang[i] < 1000000 || distribusiSekarang[i] == 4000000) {
                return;
            }
        }
        long long totalDistribusi = 0;
        for (int i = 0; i < index; ++i) {
            totalDistribusi += distribusiSekarang[i];
        }

        if (totalDistribusi == total) {
            for (int i = 0; i < index; ++i) {
                for (int j = i + 1; j < index; ++j) {
                    if (distribusiSekarang[i] < distribusiSekarang[j]) {
                        swap(distribusiSekarang[i], distribusiSekarang[j]);
                    }
                }
            }

            tampil_hasil(distribusiSekarang, index);
        }
        return;
    }

    for (long long amount = 1000000; amount <= min(8000000LL, total - (sisaKaryawan - 1) * 1000000); amount += 1000000) {
        distribusiSekarang[index] = amount;

        string distribution_string;
        for (int i = 0; i <= index; ++i) {
            distribution_string += to_string(distribusiSekarang[i]) + "_";
        }

        if (dikunjungi.find(distribution_string) == dikunjungi.end() && !temp[distribution_string]) {
            dikunjungi.insert(distribution_string);
            proses_distribusi(total, sisaKaryawan - 1, distribusiSekarang, index + 1, dikunjungi, temp);
            temp[distribution_string] = true;
            dikunjungi.erase(distribution_string);
        }
    }
}

int main() {
    long long total;
    int jumlah_karyawan;

    cout << "Input laba bersih (total): Rp. ";
    cin >> total;

    cout << "Input jumlah karyawan: ";
    cin >> jumlah_karyawan;

    long long distribusiSekarang[karyawanMaks];
    set<string> dikunjungi;
    map<string, bool> temp;

    proses_distribusi(total, jumlah_karyawan, distribusiSekarang, 0, dikunjungi, temp);

    cout << "Tidak Diketahui" << endl;

    return 0;
}
