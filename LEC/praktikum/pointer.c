#include <stdio.h>

int main(){
    int nilai1 = 50;
    int *pNilai1;
    int **pNilai2;
    pNilai1 = &nilai1;
    pNilai2 = &pNilai1;
    printf("Isi variabel1 yaitu %d\n", nilai1);
    printf("Alamat variabel nilai1 yaitu %p\n", &nilai1);
    printf("Isi variabel pointer pNilai1 yaitu %d\n", *pNilai1);
    printf("Alamat pointer pNilai1 yaitu %p\n", pNilai1);
    printf("Isi variabel pointer pNilai2 yaitu %d\n", **pNilai2);
    printf("Alamat pointer pNilai2 yaitu %p\n", *pNilai2);
    return 0;
}