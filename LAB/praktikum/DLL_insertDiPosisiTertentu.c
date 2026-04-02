#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

struct Node* membuatNode(int nilai){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if(newNode == NULL){
        printf("Gagal alokasi memori!\n");
        exit (1);
    }
    newNode->prev = NULL;
    newNode->data = nilai;
    newNode->next = NULL;
    return newNode;
};
void insertDiposisiTertentu(int nilai, int posisi){
    struct Node *ptr = membuatNode(nilai);

    if(ptr != NULL){
        if (head == NULL){
            head  = tail = ptr;
            printf("\nNode telah berhasil dimasukkan\n");
            return;
        }

        if(posisi == 0){
            ptr->next = head;
            head->prev = ptr;
            head = ptr;
            printf("\nNode telah berhasil dimasukkan di awal\n");
            return;
        }

        struct Node *temp = head;
        int counter = 1;

        while(temp->next != NULL && counter < posisi){
            temp = temp->next;
            counter++;
        }

        if(counter == posisi){
            ptr->next = temp->next;
            ptr->prev = temp;

            if(temp->next != NULL){
                temp->next->prev = ptr;
            }else{
                tail = ptr;
            }

            temp->next = ptr;

            printf("\nNode telah berhasil dimasukkan\n");
        }else{
            printf("\nPosisi yang dimasukan tidak valid\n");
            free(ptr);
        }
    }else{
        printf("\nGagal membuat node baru. Memori tidak cukup.\n");
    }

}

void tampilMaju(){

    struct Node *temp = head;
    printf("\nData dari awal ke akhir:\n");
    while(temp != NULL){
        printf("%d <->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

}

int main(){
    int pilihan, nilai, posisi;

    do{
        printf("\nMasukan nilai: ");
        scanf("%d", &nilai);

        printf("Masukan posisi (0 = awal): ");
        scanf("%d", &posisi);

        insertDiposisiTertentu(nilai, posisi);

        printf("\n1. Masukan data kembali\n0. Keluar\nPilihan: ");
        scanf("%d", &pilihan);
    }while(pilihan == 1);

    printf("Tampilan Data Traverse: ");
    tampilMaju();

    // int i;
    // for(i = 0; i < n; i++){
    //     printf("Masukan data ke %d: ", i + 1);
    //     scanf("%d", &nilai);
    //     insertAkhir(nilai);
    // }

    // printf("\n\nTampilkan Data Reverse: \n\n");
    // tampilMundur();

    // printf("\n\nTampilkan Data Reverse: \n\n");
    // tampilMundur();

    return 0;
}