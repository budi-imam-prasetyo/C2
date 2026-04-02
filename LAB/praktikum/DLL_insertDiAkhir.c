#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
} Node;

Node *head = NULL;
Node *tail = NULL;

Node *membuatNode(int nilai) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Gagal Alokasi Memori\n");
        return NULL;
    }
    newNode->prev = NULL;
    newNode->data = nilai;
    newNode->next = NULL;  
    return newNode;
}

void insertDiAkhir(int nilai){
    Node *newNode = membuatNode(nilai);
    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void tampilMaju() {
    Node *temp = head;
    printf("Data dari Awal ke Akhir: ");
    while (temp != NULL) {
        printf("%d  <->", temp->data);
        temp = temp->next;
    }
    printf(" NULL\n");
}

int main(){
    int n, nilai;
    printf("Masukkan jumlah node yang ingin ditambahkan: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        printf("Masukkan nilai untuk node %d: ", i + 1);
        scanf("%d", &nilai);
        insertDiAkhir(nilai);
    }
    printf("\n\nTampilkan Data Traverse Dari Akhir: \n\n");
    tampilMaju();
    // printf("\n\nTampilkan Data Traverse Dari Akhir: \n\n");
    // tampilMundur();
    return 0;
}