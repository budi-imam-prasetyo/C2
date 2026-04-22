#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int data)
{
    if (top == MAX_SIZE - 1)
    {
        printf("Stack penuh\n");
        return;
    }
    stack[++top] = data;
}

int pop()
{
    if (top == -1)
    {
        printf("Stack kosong\n");
        return -1;
    }
    return stack[top--];
}

void display()
{
    if (top == -1)
    {
        printf("Stack kosong\n");
        return;
    }
    for (int i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main()
{
    int data;
    while (1)
    {
        printf("Masukkan data (0 untuk keluar): ");
        scanf("%d", &data);
        if (data == 0)
        {
            break;
        }
        push(data);
    }
    printf("Sebelum di Pop: ");
    display();
    printf("Pop: %d\n", pop());
    printf("Setelah di Pop: ");
    display();
    return 0;
}