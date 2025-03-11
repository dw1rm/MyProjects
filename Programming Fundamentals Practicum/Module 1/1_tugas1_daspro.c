/* 
Dwi Rahmat Maulana
D400240014
*/
#include <stdio.h>
#define PHI 3.14

int main() {
    int sisi;                                       // Variabel panjang sisi persegi
    float hasil_persegi, hasil_segitiga;           // Variabel luas persegi & segitiga
    float hasil_setengah_lingkaran, hasil_diarsir; // Variabel luas setengah lingkaran & bagian diarsir

    puts("\nSELAMAT DATANG DI PROGRAM PERHITUNGAN LUAS BANGUN DATAR\n");
    puts("==============================================");
    
    printf("Masukkan panjang sisi persegi: ");     // Menampilkan permintaan input
    scanf("%d", &sisi);                            // Menerima input panjang sisi dari pengguna

    hasil_persegi = sisi * sisi;                        // Menghitung luas persegi (sisi * sisi)
    hasil_segitiga = 0.5 * sisi * (sisi / 2);           // Menghitung luas segitiga (1/2 * alas * tinggi)
    hasil_setengah_lingkaran = 0.5 * PHI * (sisi / 2) * (sisi / 2); // Menghitung luas setengah lingkaran (1/2 * π * r²)
    hasil_diarsir = hasil_persegi - (hasil_segitiga + hasil_setengah_lingkaran); // Menghitung luas yang diarsir

    printf("\nLuas Persegi = %.2f cm^2\n", hasil_persegi);              // Menampilkan luas persegi
    printf("Luas Segitiga Sama Kaki = %.2f cm^2\n", hasil_segitiga);    // Menampilkan luas segitiga sama kaki
    printf("Luas Setengah Lingkaran = %.2f cm^2\n", hasil_setengah_lingkaran); // Menampilkan luas setengah lingkaran
    printf("Luas Total yang Diarsir = %.2f cm^2\n", hasil_diarsir);     // Menampilkan luas bagian yang diarsir

    return 0;                                       // Mengakhiri program dengan return 0
}
