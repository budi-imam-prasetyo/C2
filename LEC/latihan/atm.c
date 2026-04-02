#include <stdio.h>
#include <stdbool.h>
int main(){
    int menu;
    char nama[20];
    float saldo = 0, tarik, simpan;
    bool loop = false;
    printf("Masukan Nama Anda: ");
    scanf("%[^\n]s", nama);
    printf("Menu:\n1. Cek Saldo\n2. Tarik Dana\n3. Simpan Dana\n4. Keluar\n");
    while (loop == false)
    { 
        printf("Masukan Pilihan Menu(1-4): ");
        scanf("%d", &menu);
        switch (menu){
        case 1:
            printf("\nNama : %s \nSaldo Anda: %.2f\n", nama, saldo);
            break;
        case 2:
            printf("Masukan jumlah penarikan (%s): ", nama);
            scanf("%f", &tarik);
            if (tarik > saldo)            {
                printf("Saldo tidak cukup \n");
            }else{
                saldo -= tarik;
                printf("Penarikan berhasil, Saldo anda sekarang: %.2f\n", saldo);
            }
            break;
        case 3:
            printf("Masukan jumlah simpanan(%s): ", nama);
            scanf("%f", &simpan);
            saldo += simpan;
            printf("Simpanan berhasil, Saldo anda sekarang: %.2f\n", saldo);
            break;
        case 4:
            printf("Terima kasih\n");
            loop = true;
            break;
        default:
            printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }

    }
    
}