#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

Node* pembuatNode(int data){
    Node *temp = malloc(sizeof(Node));
    if(temp != NULL){
        temp->data =data;
        temp->next = NULL;
        return temp;
    }
    return NULL;
}

void InsertDiAwal(int data){
    Node *temp = pembuatNode(data);
    if(temp != NULL){
        temp->next = head;
        head = temp;
        printf("Node dengan nilai %d berhasil ditambahkan di awal.\n", data);
    }else{
        printf("Gagal membuat node baru.\n");
    }
}

void displayList(){
    Node *current = head;
    if(current == NULL){
        printf("Linked List kosong.\n");
        return;
    }
    printf("Isi Linked List: ");
    while(current != NULL){
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main(){
    int pilihan, item;
    do{
        printf("\nMasukkan nilai pada node pertama yang anda inginkan?\n");
        scanf("%d", &item);

        InsertDiAwal(item);
        printf("\nTekan 1 untuk memasukkan data kembali atau tekan 0 untuk mengakhiri: ");
        scanf("%d", &pilihan);
    }while(pilihan == 1);

    printf("\nTampilan Linked List:\n");
    displayList();

    Node *temp;
    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}