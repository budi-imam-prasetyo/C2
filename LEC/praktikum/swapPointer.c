#include <stdio.h>
#include <string.h>

void swap(int *nilai1, int *nilai2){
    int temp = *nilai1;
    *nilai1 = *nilai2;
    *nilai2 = temp;
}

int main(){
    int nilai1 =10;
    int nilai2 =20;
    printf("Nilai sebelum ditukar : nilai1 (%d) dan nilai2 (%d)\n", nilai1, nilai2);
    swap(&nilai1, &nilai2);
    printf("Nilai setelah ditukar : nilai1 (%d) dan nilai2 (%d)", nilai1, nilai2);
}