#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node* pembuatNode(int itemp){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if(temp != NULL){
        temp->data =itemp;
        temp->next = NULL;
        return temp;
    }
    return NULL;
}

void InsertDiAwal(int itemp){
    struct node *temp = pembuatNode(itemp);
    if(temp != NULL){
        temp->next = head;
        head = temp;
        printf("Node dengan nilai %d berhasil ditambahkan di awal.\n", itemp);
    }else{
        printf("Gagal membuat node baru.\n");
    }
}

void displayList(){
    struct node *current = head;
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

    struct node *temp;
    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}