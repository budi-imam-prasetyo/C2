#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;;
} Node;

Node *create_node(int value){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *insert_node(Node *root, int value){
    if (root == NULL) {
        return create_node(value);
    }else if (value < root->data) {
        root->left = insert_node(root->left, value);
    } else if (value > root->data) {
        root->right = insert_node(root->right, value);
    }
    
    return root;
}

void inorder(Node *root){
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main(){
    Node *root = NULL;
    root = insert_node(root, 35);
    insert_node(root, 30);
    insert_node(root, 20);
    insert_node(root, 50);
    insert_node(root, 70);
    insert_node(root, 60);
    insert_node(root, 83);
    insert_node(root, 23);
    insert_node(root, 35);
    insert_node(root, 34);
    inorder(root);
    printf("\n");
    return 0;
}