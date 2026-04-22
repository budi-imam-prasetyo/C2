#include <stdio.h>

void input(float *num1, float *num2)
{
    printf("Masukkan Angka 1: ");
    scanf("%f", num1);
    printf("Masukkan Angka 2: ");
    scanf("%f", num2);
}
int main()
{
    float num1, num2, tambah, kurang, kali, bagi;
    char nama[20];
    int menu;
    printf("Masukkan Nama Anda: ");
    fgets(nama, sizeof(nama), stdin);
    do
    {
        printf("1. Tambah\n2. Kurang\n3. Kali\n4. Bagi\n5. Keluar\n");
        do
        {
            printf("Masukkan Pilihan Menu(1-5): ");
            scanf("%d", &menu);
        } while (menu < 1 || menu > 5);

        switch (menu)
        {
        case 1:
            input(&num1, &num2);
            tambah = num1 + num2;
            printf("\nNama : %s \nHasil Penjumlahan: %.2f\n", nama, tambah);
            break;
        case 2:
            input(&num1, &num2);
            kurang = num1 - num2;
            printf("\nNama : %s \nHasil Pengurangan: %.2f\n", nama, kurang);
            break;
        case 3:
            input(&num1, &num2);
            kali = num1 * num2;
            printf("\nNama : %s \nHasil Perkalian: %.2f\n", nama, kali);
            break;
        case 4:
            input(&num1, &num2);
            if (num2 != 0)
            {
                bagi = num1 / num2;
                printf("\nNama : %s \nHasil Pembagian: %.2f\n", nama, bagi);
            }
            else
            {
                printf("\nNama : %s \nError: Pembagian dengan nol tidak diperbolehkan.\n", nama);
            }
            break;
        default:
            printf("\nTerima kasih, %s\n", nama);
            break;
        }
    } while (menu != 5);
}