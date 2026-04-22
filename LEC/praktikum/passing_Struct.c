#include <stdio.h>

typedef struct{
    char nama[50];
    int usia;
    int presensi;
    float nilai;
}Student;

void print(Student s){
    printf("Nama :%s\nUsia : %d\nPresensi : %d\nNilai : %.2f\n\n", s.nama, s.usia, s.presensi, s.nilai);
}

int main(){
    Student s1 = {"Ricardo",20,50,72.5};
    Student s2 = {"Milos",20,50,72.5};
    print(s1);
    print(s2);
}