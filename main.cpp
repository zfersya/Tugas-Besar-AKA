#include <iostream>

using namespace std;

struct Mobil {
  string merk;
  string tipe;
  float konsumsiBahanBakar;
};

// Binary Search Function
Mobil cariMobilPalingHematBinary(Mobil mobil[], int kiri, int kanan) {
  while (kiri < kanan) {
    int tengah = kiri + (kanan - kiri) / 2;
    if (mobil[tengah].konsumsiBahanBakar < mobil[tengah + 1].konsumsiBahanBakar){
      kanan = tengah;
    } else {
      kiri = tengah + 1;
    }
  }
  return mobil[kiri];
}

// Sequential Search Function
Mobil cariMobilPalingHematSequential(Mobil mobil[], int jumlahMobil) {
  float konsumsiBahanBakarTerendah = mobil[0].konsumsiBahanBakar;
  int indeksMobilTerendah = 0;
  for (int i = 1; i < jumlahMobil; i++) {
    if (mobil[i].konsumsiBahanBakar < konsumsiBahanBakarTerendah) {
      konsumsiBahanBakarTerendah = mobil[i].konsumsiBahanBakar;
      indeksMobilTerendah = i;
    }
  }
  return mobil[indeksMobilTerendah];
}

int main() {
  Mobil mobil[] = {
    {"Toyota", "Avanza", 15.0},
    {"Honda", "Jazz", 16.0},
    {"Daihatsu", "Xenia", 17.0},
    {"Mitsubishi", "Xpander", 18.0},
    {"Suzuki", "Ertiga", 19.0},
  };

  int jumlahMobil = sizeof(mobil) / sizeof(mobil[0]);

  Mobil mobilHematBinary = cariMobilPalingHematBinary(mobil, 0, jumlahMobil - 1);
  cout << "Mobil dengan konsumsi bahan bakar paling hemat (Binary Search): " << mobilHematBinary.merk << " " << mobilHematBinary.tipe
  << "\n Dengan Per-liter sama dengan "  << mobilHematBinary.konsumsiBahanBakar << " KM "<< endl;

  Mobil mobilHematSequential = cariMobilPalingHematSequential(mobil, jumlahMobil);
  cout << "Mobil dengan konsumsi bahan bakar paling hemat (Sequential Search): " << mobilHematSequential.merk
   << " " << mobilHematSequential.tipe << "\n Dengan per-liter sama dengan " << mobilHematBinary.konsumsiBahanBakar << " KM "<<endl;

  return 0;
}
