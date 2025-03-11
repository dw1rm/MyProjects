#include <stdio.h>
#include <string.h>

int main() {
    // Deklarasi variabel
    char nama[50], nim[20], kelas[20];
    int sks1, sks2, sks3, sks4, sks5;
    int total_sks;

    puts("\nSELAMAT DATANG DI INFORMASI MAHASISWA\n");
    puts("==============================================");

    // Input data mahasiswa
    printf("\tNama  : ");
    fgets(nama, sizeof(nama), stdin);
    nama[strcspn(nama, "\n")] = 0;

    printf("\tNIM   : ");
    fgets(nim, sizeof(nim), stdin);
    nim[strcspn(nim, "\n")] = 0;

    printf("\tKelas : ");
    fgets(kelas, sizeof(kelas), stdin);
    kelas[strcspn(kelas, "\n")] = 0;

    puts("==============================================");

    // Input SKS tanpa perulangan
    printf("Masukkan jumlah SKS:\n");
    printf("\tSemester 1: "); scanf("%d", &sks1);
    printf("\tSemester 2: "); scanf("%d", &sks2);
    printf("\tSemester 3: "); scanf("%d", &sks3);
    printf("\tSemester 4: "); scanf("%d", &sks4);
    printf("\tSemester 5: "); scanf("%d", &sks5);

    // Hitung total SKS
    total_sks = sks1 + sks2 + sks3 + sks4 + sks5;

    puts("==============================================");

    // Tampilkan hasil
    printf("Terima kasih %s, Anda adalah mahasiswa dengan NIM %s dari kelas %s.\n",
           nama, nim, kelas);
    puts("Berikut adalah jumlah SKS yang telah Anda ambil:");
    printf("\tSemester 1: %d SKS\n", sks1);
    printf("\tSemester 2: %d SKS\n", sks2);
    printf("\tSemester 3: %d SKS\n", sks3);
    printf("\tSemester 4: %d SKS\n", sks4);
    printf("\tSemester 5: %d SKS\n", sks5);

    printf("\nTotal SKS yang telah Anda ambil: %d SKS\n", total_sks);
    puts("SELAMAT BELAJAR DAN SUKSES SELALU!");

    return 0;
}
