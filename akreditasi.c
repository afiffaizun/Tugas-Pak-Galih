// Muhammad Afif Faizun Nim 29
// Ahmad Naim Nim 31
// Azka Ghiovani Nim 44

#include <stdio.h>

// Menghitung skor DTPS
int hitungSkorDTPS(int NDTPS) {
    if (NDTPS >= 6) {
        return 4;
    } else if (NDTPS >= 3) {
        return (2 * NDTPS) / 3;
    } else {
        return 0;
    }
}

// Menghitung skor Jabatan Akademik DTPS
float hitungSkorJabatanAkademik(float PGBLK) {
    if (PGBLK >= 70) {
        return 4;
    } else {
        return 2 + (20 * PGBLK) / 7;
    }
}

// Menghitung skor Kesesuaian Bidang Kerja
float bidangKerja(int NJ, float PBS) {
    float prmin;
    if (NJ >= 300) {
        prmin = 30;
    } else {
        prmin = 50 - ((float)NJ / 300) * 50;
    }

    if (PBS >= prmin) {
        return 4;
    } else {
        return (20 * PBS) / 3;
    }
}

// Menghitung skor Kepuasan Pengguna
float hitungSkorKepuasan(float a, float b, float c, float d) {
    return (4 * a + 3 * b + 2 * c + d) / 7;
}

// Menghitung skor Publikasi Ilmiah Mahasiswa
float hitungSkorPublikasi(float RI, float RN, float RL) {
    float skor = 0;

    if (RI >= 2) {
        skor = 4;
    } else if (RN >= 20 && RI < 2) {
        skor = 3 + (RI / 2);
    } else if (RL >= 70 && RI == 0 && RN == 0) {
        skor = 2;
    } else {
        skor = 2 + (2 * (RI / 2)) + (RN / 20) - ((RI * RN) / (2 * 20));
    }

    if (RI == 0 && RN == 0 && RL < 70) {
        skor = (2 * RL) / 70;
    }

    return skor;
}

int main() {
    int NDTPS, NDGB, NDLK, NM, NJ;
    float PGBLK, PBS;
    float a, b, c, d;
    float RI, RN, RL;

    printf("\n=== Instrumen Suplemen Konversi Akreditas ===\n");
    printf("Jumlah NDTPS (Dosen tetap sebagai pengampu): ");
    scanf("%d", &NDTPS);

    printf("Jumlah NDGB (Jabatan Guru Besar)           : ");
    scanf("%d", &NDGB);

    printf("Jumlah NDLK (Jabatan Lektor Kepala)        : ");
    scanf("%d", &NDLK);

    // Hitung PGBLK
    PGBLK = ((float)(NDGB + NDLK) / NDTPS) * 100;

    printf("\n```` Kesesuaian Bidang Kerja ````\n");
    printf("Jumlah pekerjaan (NJ)                : ");
    scanf("%d", &NJ);

    printf("Persentase bidang studi relevan (PBS): ");
    scanf("%f", &PBS);

    // Input Kepuasan Pengguna
    printf("\n```` Masukkan persentase kepuasan pengguna (0 - 100%%) ````\n");
    printf("Sangat Baik: ");
    scanf("%f", &a);
    printf("Baik       : ");
    scanf("%f", &b);
    printf("Cukup      : ");
    scanf("%f", &c);
    printf("Kurang     : ");
    scanf("%f", &d);

    // Input data Publikasi Ilmiah
    printf("\n```` Publikasi Jurnal Ilmiah ````\n");
    printf("Jurnal internasional (RI): ");
    scanf("%f", &RI);
    printf("Jurnal nasional      (RN): ");
    scanf("%f", &RN);
    printf("Jurnal lokal         (RL): ");
    scanf("%f", &RL);
    printf("Jumlah mahasiswa     (NM): ");
    scanf("%d", &NM);

    // Hitung publikasi dalam persentase
    RI = (RI / NM) * 100;
    RN = (RN / NM) * 100;
    RL = (RL / NM) * 100;

    // Hitung skor
    float skorDTPS = hitungSkorDTPS(NDTPS);
    float skorJabatanAkademik = hitungSkorJabatanAkademik(PGBLK);
    float skorBidangKerja = bidangKerja(NJ, PBS);
    float skorKepuasan = hitungSkorKepuasan(a, b, c, d);
    float skorPublikasi = hitungSkorPublikasi(RI, RN, RL);

    // Output hasil
    printf("\n== Hasil Perhitungan Akreditasi ==\n");
    printf("Skor DTPS                      : %.2f\n", skorDTPS);
    printf("Skor Jabatan Akademik DTPS     : %.2f\n", skorJabatanAkademik);
    printf("Skor Kesesuaian Bidang Kerja   : %.2f\n", skorBidangKerja);
    printf("Skor Kepuasan Pengguna Lulusan : %.2f\n", skorKepuasan);
    printf("Skor Publikasi Ilmiah Mahasiswa: %.2f\n", skorPublikasi);

    return 0;
}
