#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *right;
    struct Node *prev;
} Node;

Node* createNode(int data, Node* parent){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->right = NULL;
    newNode->prev = parent;
    return newNode;
}

Node* inputTree(Node* parent){
    int data;
    printf("Masukkan data (-1 jika kosong) ");
    scanf("%d", &data);

    if (data == -1){
        return NULL;
    }

    Node* root = createNode(data, parent);
    printf("Input child kiri dari %d\n", data);
    root->prev = inputTree(root);
    printf("Input child kanan dari %d\n", data);
    root->right = inputTree(root);

    return root;
}

void preorder(Node* root){
    if(root != NULL){
        printf("%d ", root->data);
        preorder(root->prev);
        preorder(root->right);
    }
}

void inorder(Node* root){
    if(root != NULL){
        inorder(root->prev);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(Node* root){
    if(root != NULL){
        postorder(root->prev);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

Node* searchNode(Node* root, int key){
    if(root == NULL){
        return NULL;
    }
    if(root->data == key){
        return root;
    }

    Node* leftSearch = searchNode(root->prev, key);
    if(leftSearch != NULL){
        return leftSearch;
    }
    return searchNode(root->right, key);
}

int countLeaf(Node* root){
    if(root == NULL){
        return 0;
    }

    if(root->prev == NULL && root->right == NULL){
        return 1;
    }
    return countLeaf(root->prev) + countLeaf(root->right);
}

int main(){
    Node* root = NULL;
    int pilihan;
    int cari;
    Node* hasil;

    do{
        printf("\n===MENU BINARY TREE===\n");
        printf("1. Tambah Data\n");
        printf("2. Preorder\n");
        printf("3. Inorder\n");
        printf("4. Postorder\n");
        printf("5. Cari Parent Node\n");
        printf("6. Hitung Leaf Node\n");
        printf("7. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch(pilihan){
            case 1:
                // Tambah Data
                printf("Masukkan Tree\n");
                root = inputTree(NULL);
                break;
            case 2:
                // Preorder
                printf("Preorder:\n");
                preorder(root);
                break;
            case 3:
                // Inorder
                printf("Inorder:\n");
                inorder(root);
                break;
            case 4:
                // Postorder
                printf("Postorder:\n");
                postorder(root);
                break;
            case 5:
                // Cari Parent Node
                printf("Masukkan node yang dicari parentnya: ");
                scanf("%d", &cari);
                hasil = searchNode(root, cari);

                if(hasil == NULL){
                    printf("Node tidak ditemukan.\n");
                } else if(hasil->prev == NULL){
                    printf("Node tersebut adalah root, tidak memiliki parent.\n");
                } else {
                    printf("Parent dari node %d adalah %d.\n", hasil->data, hasil->prev->data);
                }
                break;
            case 6:
                // Hitung Leaf Node
                printf("Jumlah Leaf Node: %d\n", countLeaf(root));

                break;
            case 7:
                printf("Program selesain.\n");
                break;
            default:
                printf("Menu yang ada pilih tidak tersedia.\n");
        }
    } while(pilihan != 7);
}