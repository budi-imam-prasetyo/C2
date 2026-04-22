#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    char nama[20];
    int usia;
    struct node *link;
} Node;

int main(){
    Node *head = (Node*)malloc(sizeof(Node));
    head->nama[0] = 'A';
    head->nama[1] = 'l';
    head->nama[2] = 'i';
    head->nama[3] = '\0';
    head->usia = 10;
    head->link = NULL;
    
    Node *current = (Node*)malloc(sizeof(Node));
    current->usia = 11;
    current->link = NULL;
    head->link = current;
    
    current = (Node*)malloc(sizeof(Node));
    current->usia = 12;
    current->link = NULL;
    head->link->link = current;
    printf("head pada node pertama(%s): %d\n", head->nama, head->usia);
    printf("head pada node ketiga: %d\n", head->link->usia);
    printf("head pada node ketiga: %d\n", head->link->link->usia);
    return 0;
}