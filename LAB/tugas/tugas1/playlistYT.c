#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char judul[100];
    char link[200];
    char kategori[100];
    char tanggalDisimpan[20];
    struct Node* next;
    struct Node* prev;
} Node;

Node* head = NULL;
Node* tail = NULL;

Node* createNode(char judul[], char link[], char kategori[], char tanggalDisimpan[]) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->judul, judul);
    strcpy(newNode->link, link);
    strcpy(newNode->kategori, kategori);
    strcpy(newNode->tanggalDisimpan, tanggalDisimpan);
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertDiAwal (char judul[], char link[], char kategori[], char tanggalDisimpan[]) {
    Node* newNode = createNode(judul, link, kategori, tanggalDisimpan);
    if (head == NULL) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertdiakhir (char judul[], char link[], char kategori[], char tanggalDisimpan[]) {
    Node* newNode = createNode(judul, link, kategori, tanggalDisimpan);
    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void deleteawal(){
    if (head == NULL){
        printf("Tidak ada Video pada Playlist yang bisa di hapus\n");
        return;
    }
    Node *temp = head;
    head = head->next;
    free(temp);
    printf("Video Playlist berhasil di hapus\n");
}

void deleteakhir(){
    if (head == NULL){
        printf("Tidak ada Video pada Playlist yang bisa di hapus\n");
        return;
    }
    Node *temp = tail;
    tail = tail->prev;
    free(temp);
    printf("Video Playlist berhasil di hapus\n");
}

void tampilan(){
    if (head == NULL){
        printf("Tidak ada Video pada Playlist\n");
        return;
    }
    Node *temp = head;
    while (temp != NULL){
        printf("====PlayList Kamu====\n");
        printf("Judul: %s\n", temp->judul);
        printf("Link: %s\n", temp->link);
        printf("Kategori: %s\n", temp->kategori);
        printf("Tanggal Disimpan: %s\n\n", temp->tanggalDisimpan);
        temp = temp->next;
    }
}


int main(){
    int pilihan;
    char judul[100], link[200], kategori[100], tanggalDisimpan[20];
    
    do {
        printf("\n=== MENU PLAYLIST YOUTUBE ===\n");
        printf("1. Insert di Awal\n");
        printf("2. Insert di Akhir\n");
        printf("3. Delete di Awal\n");
        printf("4. Delete di Akhir\n");
        printf("5. Tampilkan Playlist\n");
        printf("0. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);
        getchar();

        switch (pilihan) {
            case 1:
                printf("Judul: ");
                fgets(judul, sizeof(judul), stdin);
                judul[strcspn(judul, "\n")] = 0;

                printf("Link: ");
                fgets(link, sizeof(link), stdin);
                link[strcspn(link, "\n")] = 0;

                printf("Kategori: ");
                fgets(kategori, sizeof(kategori), stdin);
                kategori[strcspn(kategori, "\n")] = 0;

                printf("Tanggal Disimpan (DD-MM-YYYY): ");
                fgets(tanggalDisimpan, sizeof(tanggalDisimpan), stdin);
                tanggalDisimpan[strcspn(tanggalDisimpan, "\n")] = 0;

                insertDiAwal(judul, link, kategori, tanggalDisimpan);
                break;
            case 2:
                printf("Judul: ");
                fgets(judul, sizeof(judul), stdin);
                judul[strcspn(judul, "\n")] = 0;

                printf("Link: ");
                fgets(link, sizeof(link), stdin);
                link[strcspn(link, "\n")] = 0;

                printf("Kategori: ");
                fgets(kategori, sizeof(kategori), stdin);
                kategori[strcspn(kategori, "\n")] = 0;

                printf("Tanggal Disimpan (DD-MM-YYYY): ");
                fgets(tanggalDisimpan, sizeof(tanggalDisimpan), stdin);
                tanggalDisimpan[strcspn(tanggalDisimpan, "\n")] = 0;

                insertdiakhir(judul, link, kategori, tanggalDisimpan);
                break;
            case 3:
                deleteawal();
                break;
            case 4:
                deleteakhir();
                break;
            case 5:
                tampilan();
                break;
            case 0:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 0);

    return 0;

}