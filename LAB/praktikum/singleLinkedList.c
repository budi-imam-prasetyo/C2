#include <stdio.h>
#include <stdlib.h>
struct node {
    char nama[20];
    int usia;
    struct node *link;
};

int main(){
    struct node *head = (struct node*)malloc(sizeof(struct node));
    head->nama[0] = 'A';
    head->nama[1] = 'l';
    head->nama[2] = 'i';
    head->nama[3] = '\0';
    head->usia = 10;
    head->link = NULL;
    
    struct node *current = (struct node*)malloc(sizeof(struct node));
    current->usia = 11;
    current->link = NULL;
    head->link = current;
    
    current = (struct node*)malloc(sizeof(struct node));
    current->usia = 12;
    current->link = NULL;
    head->link->link = current;
    printf("head pada node pertama(%s): %d\n", head->nama, head->usia);
    printf("head pada node ketiga: %d\n", head->link->usia);
    printf("head pada node ketiga: %d\n", head->link->link->usia);
    return 0;
}