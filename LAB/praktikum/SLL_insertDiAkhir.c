#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    Node *next;
} Node;

Node *head = NULL;

Node* pembuatNode(int itemp){
    Node *temp = (Node*)malloc(sizeof(Node));
    if(temp != NULL){
        temp->data =itemp;
        temp->next = NULL;
        return temp;
    }
    return NULL;
}

void InsertDiAkhir(int itemp){
    Node *temp = pembuatNode(itemp);
    if(temp != NULL){
        if(head == NULL){
            head = temp;
        }else{
            Node *current = head;
            while(current->next != NULL){
                current = current->next;
            }
            current->next = temp;
        }
        printf("Node telah berhasil ditambahkan.\n");
    }else{
        printf("Gagal membuat node baru.\n");
    }
}
void InsertDiAwal(int itemp){
    Node *temp = pembuatNode(itemp);
    if(temp != NULL){
        temp->next = head;
        head = temp;
        printf("Node dengan nilai %d berhasil ditambahkan di awal.\n", itemp);
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
        InsertDiAkhir(item);
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