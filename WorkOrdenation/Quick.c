#include "work.h"

void trocah(Product v[], int i,int j){
  Product temp;
  temp=v[i];
  v[i]=v[j];
  v[j]=temp;
}

int particaoo(Product v[],int esq,int dir){
    int i, fim;

    fim=esq;

    for(i=esq+1;i<=dir;i++){
        if(v[i].number<v[esq].number) {
            fim=fim+1;
            trocah(v,fim,i);
        }
    }
    trocah(v,esq,fim);

    return fim;
}

void Quick(Product v[], int esq, int dir){
    int i;
    if(esq >= dir) return;
    i=particaoo(v,esq,dir);
    Quick(v,esq,i-1);
    Quick(v,i+1,dir);
}

/////////////////////////////////////////////////////////////////

int particao_string(Product arr[], int esq, int dir){

    int fim = esq;

    for(int i = esq+1; i <= dir; i++){
        if(who_is_Minor(arr[i].description,arr[esq].description)){
            fim++;
            trocah(arr,fim,i);
        }
    }

    trocah(arr,fim,esq);

    return fim;

}

void Quick_String(Product arr[], int esq, int dir){

    int i;
    if(esq >= dir) return;

    i = particao_string(arr,esq,dir);

    Quick_String(arr,esq,i-1);
    Quick_String(arr,i+1,dir);

}