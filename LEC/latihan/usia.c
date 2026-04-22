#include <stdio.h>

int main()
{
    int tahunLahir;
    int hitungUsia;
    printf("Masukkan tahun lahir Anda: ");
    scanf("%d", &tahunLahir);
    hitungUsia = 2024 - tahunLahir;

    // cara saya
    if (tahunLahir > 2024 || tahunLahir < 1900)
    {
        printf("Tahun lahir tidak valid\n");
        return 0;
    }else{
        if (hitungUsia >= 0 && hitungUsia <= 5){
            printf("Balita berumur %d tahun\n", hitungUsia);
        }
        else if (hitungUsia > 5 && hitungUsia <= 12){
            printf("Anak-anak berumur %d tahun\n", hitungUsia);
        }
        else if (hitungUsia > 12 && hitungUsia <= 18){
            printf("Remaja berumur %d tahun\n", hitungUsia);
        }
        else if (hitungUsia > 18 && hitungUsia < 60){
            printf("Dewasa berumur %d tahun\n", hitungUsia);
        }
        else if (hitungUsia >= 60){
            printf("Lansia berumur %d tahun\n", hitungUsia);
        }
        return 0;
    }

    // // cara ihsan
    // if (tahunLahir > 2024 || tahunLahir < 1900)
    // {
    //     printf("Tahun lahir tidak valid\n");
    //     return 0;
    // }
    // else if (hitungUsia >= 0 && hitungUsia <= 5)
    // {
    //     printf("Balita berumur %d tahun\n", hitungUsia);
    // }
    // else if (hitungUsia > 5 && hitungUsia <= 12)
    // {
    //     printf("Anak-anak berumur %d tahun\n", hitungUsia);
    // }
    // else if (hitungUsia > 12 && hitungUsia <= 18)
    // {
    //     printf("Remaja berumur %d tahun\n", hitungUsia);
    // }
    // else if (hitungUsia > 18 && hitungUsia < 60)
    // {
    //     printf("Dewasa berumur %d tahun\n", hitungUsia);
    // }
    // else if (hitungUsia >= 60)
    // {
    //     printf("Lansia berumur %d tahun\n", hitungUsia);
    // }
    // return 0;

    // // cara hardian
    // if (tahunLahir > 2024 || tahunLahir < 1900)
    // {
    //     printf("Tahun lahir tidak valid\n");
    //     return 0;
    // }
    // else if(hitungUsia >=60 )
    // {
    //     printf("Lansia berumur %d tahun\n", hitungUsia);
    // }
    // else if (hitungUsia < 60)
    // {
    //     printf("Dewasa berumur %d tahun\n", hitungUsia);
    // }
    // else if (hitungUsia < 19)
    // {
    //     printf("Remaja berumur %d tahun\n", hitungUsia);
    // }
    // else if (hitungUsia < 13)
    // {
    //     printf("Anak-anak berumur %d tahun\n", hitungUsia);
    // }
    // else if (hitungUsia < 6)
    // {
    //     printf("Balita berumur %d tahun\n", hitungUsia);
    // }
    // else
    // {
    //     printf("Tahun lahir tidak valid\n");
    // }
    return 0;
}
