#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Mahasiwa{
    long long nim;
    char nama[50];
    struct Mahasiwa *next;
}mhs;

mhs *head = NULL;

mhs* createmhs(long long nim, char nama[]){
    mhs *newNode = (mhs*)malloc(sizeof(mhs));
    if(newNode != NULL){
        newNode->nim = nim;
        strcpy(newNode->nama, nama);
        newNode->next = NULL;
        return newNode;
    }
    return NULL;
}

void insertAtHead(long long nim, char nama[]){
    mhs *newNode = createmhs(nim, nama);
    if(newNode == NULL) return;

    if(head == NULL){
        head = newNode;
    }else {
        newNode->next = head;
        head = newNode;
    }
    printf("Mahasiswa dengan NIM %lld dan nama %s berhasil ditambahkan di awal.\n", nim, nama);
}

void insertAtTail(long long nim, char nama[]){
    mhs *newNode = createmhs(nim, nama);
    if(newNode == NULL) return;

    if(head == NULL){
        head = newNode;
    }else {
        mhs *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Mahasiswa dengan NIM %lld dan nama %s berhasil ditambahkan di akhir.\n", nim, nama);
}

mhs *search (long long nim){
    mhs *temp = head;
    while(temp != NULL){
        if(temp->nim == nim){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void deleteHead(){
    if(head == NULL) return;

    mhs *temp = head;
    head = head->next;
    printf("Mahasiswa dengan NIM %lld dan nama %s berhasil dihapus.\n", temp->nim, temp->nama);
    free(temp);
}

int menu(){
    int choice;
    printf("\nMenu:\n");
    printf("1. Tambah Mahasiswa dari Awal\n");
    printf("2. Tambah Mahasiswa dari Akhir\n");
    printf("3. Tampilkan Data Mahasiswa\n");
    printf("4. Hapus Data Mahasiswa\n");
    printf("5. Cari Data Mahasiswa\n");
    printf("0. Keluar\n");
    printf("Pilih menu: ");
    scanf("%d", &choice);
    return choice;

}

void displayMhs(){
    mhs *temp = head;
    int no = 1;
    if(head == NULL){
        printf("Daftar Mahasiswa kosong.\n");
        return;
    }
    printf("Daftar Mahasiswa:\n");
    while(temp != NULL){
        printf("%d. NIM: %lld, Nama: %s\n", no, temp->nim, temp->nama);
        temp = temp->next;
        no++;
    }
}

int main(){
    int choice;
    do{
        choice = menu();
        switch(choice){
            case 1:{
                long long nim;
                char nama[20];
                printf("Masukkan NIM: ");
                scanf("%lld", &nim);
                printf("Masukkan Nama: ");
                scanf("%s", nama);
                insertAtHead(nim, nama);
                break;
            }
            case 2: {
                long long nim;
                char nama[20];
                printf("Masukkan NIM: ");
                scanf("%lld", &nim);
                printf("Masukkan Nama: ");
                scanf("%s", nama);
                insertAtTail(nim, nama);
                break;
            }
            case 3:
                displayMhs();
                break;
            case 4:{
                long long nim;
                printf("Masukkan NIM mahasiswa yang ingin dihapus: ");
                scanf("%lld", &nim);
                mhs *found = search(nim);
                if(found != NULL){
                    deleteHead();
                } else {
                    printf("Mahasiswa dengan NIM %lld tidak ditemukan.\n", nim);
                }
                break;
            }
            case 5:{
                long long nim;
                printf("Masukkan NIM mahasiswa yang ingin dicari: ");
                scanf("%lld", &nim);
                mhs *found = search(nim);
                if(found != NULL){
                    printf("Mahasiswa ditemukan: NIM: %lld, Nama: %s\n", found->nim, found->nama);
                } else {
                    printf("Mahasiswa dengan NIM %lld tidak ditemukan.\n", nim);
                }
                break;
            }
            case 0:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    }while(choice != 0);
}