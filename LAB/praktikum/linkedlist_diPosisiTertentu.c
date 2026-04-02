#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node *pembuatNode(int item)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr != NULL)
    {
        ptr->data = item;
        ptr->next = NULL;
    }
    return ptr;
}

void InsertDiPosisiTertentu(int item, int posisi)
{
    struct node *ptr = pembuatNode(item);
    if (ptr != NULL)
    {
        if (head == NULL)
        {
            head = ptr;
            printf("Node telah berhasil ditambahkan sebagai node pertama.\n");
            return;
        }
        if (posisi == 0)
        {
            ptr->next = head;
            head = ptr;
            printf("Node dengan nilai %d berhasil ditambahkan di awal.\n", item);
            return;
        }
        struct node *temp = head;
        int counter = 1;
        while (temp->next != NULL && counter < posisi)
        {
            temp = temp->next;
            counter++;
        }
        if (counter == posisi)
        {
            ptr->next = temp->next;
            temp->next = ptr;
            printf("Node dengan nilai %d berhasil ditambahkan di posisi %d.\n", item, posisi);
        }
        else
        {
            printf("Posisi melebihi panjang linked list. Node dengan nilai %d ditambahkan di akhir.\n", item);
            free(ptr);
        }
    }
}

void displayList()
{
    struct node *current = head;
    if (current == NULL)
    {
        printf("Linked List kosong.\n");
        return;
    }
    printf("Isi Linked List: ");
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main()
{
    int pilihan, item, posisi;
    do
    {
        printf("\nMasukkan nilai pada node pertama yang anda inginkan?\n");
        scanf("%d", &item);

        printf("\nMasukkan Posisi Node (0 untuk awal, atau >1 untuk input spesifik node): ");
        scanf("%d", &posisi);

        InsertDiPosisiTertentu(item, posisi);
        printf("\nTekan 1 untuk memasukkan data kembali atau tekan 0 untuk mengakhiri: ");
        scanf("%d", &pilihan);
    } while (pilihan == 1);

    printf("\nTampilan Linked List:\n");
    displayList();

    struct node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}