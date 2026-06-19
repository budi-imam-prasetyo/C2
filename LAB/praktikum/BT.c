#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;;
} Node;

Node *Create() {
    int x;
    struct Node *newNode;

    printf("Masukkan data (-1 untuk tidak ada data): ");
    scanf("%d", &x);

    if (x == -1) {
        return NULL;
    }

    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;

    printf("Masukkan data anak kiri dari %d:\n", x);
    newNode->left = Create();

    printf("Masukkan data anak kanan dari %d:\n", x);
    newNode->right = Create();

    return newNode;
}

void inorderTraversal(Node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}
void preorderTraversal(Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}
void postorderTraversal(Node *root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main(){
    Node *root;
    root = Create();
        
    printf("Tampilkan data dalam inorder traversal:\n");
    inorderTraversal(root);
    printf("\n");
    printf("Tampilkan data dalam preorder traversal:\n");
    preorderTraversal(root);
    printf("\n");
    printf("Tampilkan data dalam postorder traversal:\n");
    postorderTraversal(root);
    return 0;
}