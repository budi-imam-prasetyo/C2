#include <stdio.h>
#include <string.h>

typedef struct{
    char nama[50];
    float ratingIMDB;
    int tahunRilis;
}Film;

int main(){
    Film filmKumpulanFilm[2];
    for(int i = 0; i < 2; i++){
        printf("Data film ke %d\n\n", i+1);
        printf("Masukkan nama film : ");
        fgets(filmKumpulanFilm[i].nama, sizeof(filmKumpulanFilm[i].nama), stdin);
        if(filmKumpulanFilm[i].nama[strlen(filmKumpulanFilm[i].nama)-1] == '\n'){
            filmKumpulanFilm[i].nama[strlen(filmKumpulanFilm[i].nama)-1] = '\0';
        }
        printf("Masukkan rating IMDB film : ");
        scanf("%f", &filmKumpulanFilm[i].ratingIMDB);
        printf("Masukkan tahun rilis film : ");
        scanf("%d", &filmKumpulanFilm[i].tahunRilis);
        getchar();
        printf("\n");
    }
    for(int i = 0; i < 2; i++){
        printf("Data film ke %d\n\n", i+1);
        printf("Nama film : %s\n", filmKumpulanFilm[i].nama);
        printf("Rating IMDB film : %.1f\n", filmKumpulanFilm[i].ratingIMDB);
        printf("Tahun rilis film : %d\n", filmKumpulanFilm[i].tahunRilis);
        printf("\n");
    }
    return 0;
}