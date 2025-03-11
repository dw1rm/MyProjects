/* 
Dwi Rahmat Maulana
D400240014
*/
#include <stdio.h>            // Library untuk fungsi input-output

int main () {                

    // Menentukan Tipe Data dan Variabel
    int jari = 16;           // Jari-jari lingkaran (cm)
    float phi = 3.14, hasil; // Nilai phi dan variabel untuk menyimpan hasil luas

    printf("PERHITUNGAN LUAS LINGKARAN\n"); // Menampilkan judul

    printf("Jari-jari Lingkaran = %i cm\n", jari);        // Menampilkan jari-jari lingkaran

    printf("Nilai Phi = %0.2f \n", phi);                  // Menampilkan nilai phi dengan 2 angka di belakang koma

    hasil = phi * jari * jari;                            // Menghitung luas lingkaran dengan rumus π * r²

    printf("Luas Lingkaran = %0.2f cm2", hasil);          // Menampilkan luas lingkaran

    return 0;                                            // Mengakhiri program
}
