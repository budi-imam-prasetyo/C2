#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
} Node;

Node *front = NULL, *rear = NULL;

Node *newNode(int data)
{
    Node *temp = malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void enqueue(int data)
{
    Node* temp = newNode(data);
    if (front == NULL && rear == NULL) {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

int dequeue(){
    if(front == NULL){
        printf("Queue kosong\n");
        return -1;
    }

    int data = front->data;
    Node* temp = front;
    front = front->next;

    if(front == NULL){
        rear = NULL;
    }

    free(temp);
    return data;
}

void display(){
    if(front == NULL){
        printf("Queue kosong\n");
        return;
    }

    Node* temp = front;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int peek(){
    if(front == NULL){
        printf("Queue kosong\n");
        return -1;
    }
    return front->data;
}

int main(){
    int data;

    while(1){
        printf("Masukkan data (0 untuk keluar): ");
        scanf("%d", &data);

        if(data == 0){
            break;
        }
        enqueue(data);
    }

    printf("Isi Queue: ");
    printf("\nElemen terdepan: %d\n", peek());
    printf("Isi Queue: ");

}