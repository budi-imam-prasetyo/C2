#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur Node (minimal 4 atribut)
struct Node {
    char judul[100];
    char channel[100];
    int durasi;       // dalam detik
    int tahun;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;
struct Node* tail = NULL;

// Membuat node baru
struct Node* createNode(char judul[], char channel[], int durasi, int tahun) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    strcpy(newNode->judul, judul);
    strcpy(newNode->channel, channel);
    newNode->durasi = durasi;
    newNode->tahun = tahun;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Insert di awal
void insertAwal(char judul[], char channel[], int durasi, int tahun) {
    struct Node* newNode = createNode(judul, channel, durasi, tahun);

    if (head == NULL) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// Insert di akhir
void insertAkhir(char judul[], char channel[], int durasi, int tahun) {
    struct Node* newNode = createNode(judul, channel, durasi, tahun);

    if (tail == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// Delete di awal
void deleteAwal() {
    if (head == NULL) {
        printf("List kosong!\n");
        return;
    }

    struct Node* temp = head;

    if (head == tail) {
        head = tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }

    free(temp);
}

// Delete di akhir
void deleteAkhir() {
    if (tail == NULL) {
        printf("List kosong!\n");
        return;
    }

    struct Node* temp = tail;

    if (head == tail) {
        head = tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }

    free(temp);
}

// Traverse (menampilkan data)
void tampilkan() {
    struct Node* temp = head;

    if (temp == NULL) {
        printf("Playlist kosong!\n");
        return;
    }

    printf("\n=== Playlist ===\n");
    while (temp != NULL) {
        printf("Judul   : %s\n", temp->judul);
        printf("Channel : %s\n", temp->channel);
        printf("Durasi  : %d detik\n", temp->durasi);
        printf("Tahun   : %d\n", temp->tahun);
        printf("----------------------\n");
        temp = temp->next;
    }
}

// Menu utama
int main() {
    int pilihan;
    char judul[100], channel[100];
    int durasi, tahun;

    do {
        printf("\n=== MENU PLAYLIST DLL ===\n");
        printf("1. Insert Awal\n");
        printf("2. Insert Akhir\n");
        printf("3. Delete Awal\n");
        printf("4. Delete Akhir\n");
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

                printf("Channel: ");
                fgets(channel, sizeof(channel), stdin);
                channel[strcspn(channel, "\n")] = 0;

                printf("Durasi (detik): ");
                scanf("%d", &durasi);

                printf("Tahun: ");
                scanf("%d", &tahun);

                insertAwal(judul, channel, durasi, tahun);
                break;

            case 2:
                printf("Judul: ");
                fgets(judul, sizeof(judul), stdin);
                judul[strcspn(judul, "\n")] = 0;

                printf("Channel: ");
                fgets(channel, sizeof(channel), stdin);
                channel[strcspn(channel, "\n")] = 0;

                printf("Durasi (detik): ");
                scanf("%d", &durasi);

                printf("Tahun: ");
                scanf("%d", &tahun);

                insertAkhir(judul, channel, durasi, tahun);
                break;

            case 3:
                deleteAwal();
                break;

            case 4:
                deleteAkhir();
                break;

            case 5:
                tampilkan();
                break;

            case 0:
                printf("Keluar program...\n");
                break;

            default:
                printf("Pilihan tidak valid!\n");
        }

    } while (pilihan != 0);

    return 0;
}