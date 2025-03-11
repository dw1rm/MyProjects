/* 
Dwi Rahmat Maulana
D400240014
*/
#include <stdio.h>
int main ()
{
    // Program Memasukkan dan Menampilkan Data Diri
    char nama[30];          // Menyimpan nama pengguna (maks 30 karakter)
    char ttl[50];           // Menyimpan tempat tanggal lahir (maks 50 karakter)
    char jenis[30];         // Menyimpan jenis kelamin (maks 30 karakter)
    char darah[30];         // Menyimpan golongan darah (maks 30 karakter)
    int tinggi;             // Menyimpan tinggi badan dalam cm
    int berat;              // Menyimpan berat badan dalam kg

    puts("\nSELAMAT DATANG DI PRAKTIKUM DASAR PEMROGRAMAN\n");
    puts("==============================================");

    puts("Lengkapi Data dibawah ini: ");
    printf("\tNama : ");
    gets(nama);             // Mengambil input nama dari pengguna

    printf("\tTempat Tanggal Lahir : ");
    gets(ttl);              // Mengambil input tempat tanggal lahir

    printf("\tJenis Kelamin : ");
    gets(jenis);            // Mengambil input jenis kelamin

    printf("\tGolongan Darah : ");
    gets(darah);            // Mengambil input golongan darah

    printf("\tTinggi Badan : ");
    scanf("%i", &tinggi);   // Mengambil input tinggi badan

    printf("\tBerat Badan : ");
    scanf("%i", &berat);    // Mengambil input berat badan

    puts("==============================================");

    printf("Terimakasih %s, anda merupakan praktikan dengan TTL %s,\n"
           "Jenis Kelamin %s, Golongan Darah %s, Tinggi badan %i cm, Berat badan %i kg \n\n"
           "SELAMAT BELAJAR DI PRAKTIKUM DASAR PEMROGRAMAN!", 
           nama, ttl, jenis, darah, tinggi, berat);  // Menampilkan data yang telah diinput

    return 0;
}
