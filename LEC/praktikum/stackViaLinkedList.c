#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

struct stack
{
    int data;
    struct stack *next;
    struct stack *top;
};

struct stack *push(struct stack *top, int val){
    struct stack *ptr;
    ptr = (struct stack *)malloc(sizeof(struct stack*));
    ptr->data = val;
    if(top == NULL){
        top = ptr;
        ptr->top = NULL;
    }else{
        ptr -> next = top;
        top = ptr;
    }
    return top;
};
struct stack *pop(struct stack *top){
    struct stack *ptr;
    ptr = top;
    if(top == NULL){
        printf("\n Stack Underflow");
    }else{
        top = top->next;
        printf("\n\nThe deleted value: %d\n", ptr->data);
        free(ptr);
    }
    return top;
};
struct stack *display(struct stack *top){
    struct stack *ptr;
    ptr = top;
    if(top == NULL){
        printf("\n Stack is Empty");
    }else{
        while(ptr != NULL){
            printf("\n%d", ptr->data);
            ptr = ptr-> next;
        }
    }
    return top;
};
int peek (struct stack *top){
    return top -> data;
}

int main()
{
    int data;
    struct stack *top = NULL;
    while (1)
    {
        printf("Masukkan data (0 untuk keluar): ");
        scanf("%d", &data);
        if (data == 0)
        {
            break;
        }
        top = push(top, data);
    }
    printf("\nSebelum di Pop: ");
    top = display(top);
    top = pop(top);

    printf("\nSetelah di Pop: ");
    top = display(top);

    printf("\nPeek: %d\n", peek(top));
    return 0;
}