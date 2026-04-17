#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct buku {
    int id;
    char judul[100];
    char penulis[100];
    int tahun;
    int status;
    struct buku *next;
};

struct buku *head = NULL;

struct buku* pembuatNode(int id, char judul[], char penulis[], int tahun, int status){
    struct buku *temp = (struct buku*)malloc(sizeof(struct buku));
    if(temp != NULL){
        temp->id = id;
        strcpy(temp->judul, judul);
        strcpy(temp->penulis, penulis);
        temp->tahun = tahun;
        temp->status = status;
        temp->next = NULL;
    }
    return temp;
}

void InsertDiAwal(int id, char judul[], char penulis[], int tahun, int status){
    struct buku *temp = pembuatNode(id, judul, penulis, tahun, status);
    if(temp != NULL){
        temp->next = head;
        head = temp;
        printf("Buku berhasil ditambahkan.\n");
    } else {
        printf("Gagal membuat node.\n");
    }
}

void displayList(){
    struct buku *current = head;

    if(current == NULL){
        printf("Data buku kosong.\n");
        return;
    }

    printf("\n===== DATA PERPUSTAKAAN =====\n");
    while(current != NULL){
        printf("ID      : %d\n", current->id);
        printf("Judul   : %s\n", current->judul);
        printf("Penulis : %s\n", current->penulis);
        printf("Tahun   : %d\n", current->tahun);
        printf("Status  : %s\n", current->status ? "Tersedia" : "Dipinjam");
        printf("===========================\n");
        current = current->next;
    }
}

int main(){
    int pilihan;
    do{
        int id, tahun, status;
        char judul[100], penulis[100];

        printf("\nMasukkan ID Buku: ");
        scanf("%d", &id);
        getchar(); 

        printf("Masukkan Judul Buku: ");
        fgets(judul, sizeof(judul), stdin);
        judul[strcspn(judul, "\n")] = 0;

        printf("Masukkan Penulis: ");
        fgets(penulis, sizeof(penulis), stdin);
        penulis[strcspn(penulis, "\n")] = 0;

        printf("Masukkan Tahun Terbit: ");
        scanf("%d", &tahun);

        printf("Status (1 = Tersedia, 0 = Dipinjam): ");
        scanf("%d", &status);

        InsertDiAwal(id, judul, penulis, tahun, status);

        printf("\nTekan 1 untuk tambah buku lagi, 0 untuk keluar: ");
        scanf("%d", &pilihan);
    } while(pilihan == 1);

    displayList();

    struct buku *temp;
    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}