#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x, y;
}Point;

Point* fun(int a, int b)
{
    Point *ptr = (Point *)malloc(sizeof(Point));
    ptr->x = a;
    ptr->y = b +5;
    // return ptr;
};

void print(Point *ptr)
{
    printf("x = %d, y = %d\n", ptr->x, ptr->y);
}


int main(){
    Point *s1 = fun(10, 20);
    Point *s2 = fun(30, 40);
    print(s1);
    print(s2);
    free(s1);
    free(s2);
    print(s1);
    print(s2);
    return 0;
}