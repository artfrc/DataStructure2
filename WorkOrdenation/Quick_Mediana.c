#include "work.h"

void troca(Product v[], int i,int j){
  Product temp;
  temp=v[i];
  v[i]=v[j];
  v[j]=temp;
}

int particao(Product v[],int esq,int dir){
    int i, fim;

    fim=esq;

    for(i=esq+1;i<=dir;i++){
        if(v[i].number<v[esq].number) {
            fim=fim+1;
            troca(v,fim,i);
        }
    }
    troca(v,esq,fim);

    return fim;
}

void Quick_mediana(Product v[], int esq, int dir){
    int i;
    if(esq >= dir) return;
    
    // trocar elemento do meio com o segundo
    troca(v,esq+1,(esq+dir)/2);

    // colocar em ordem os tres elementos
    if(v[esq].number > v[esq+1].number) troca(v,esq,esq+1);
    if(v[esq].number > v[dir].number) troca(v,esq,dir);
    if(v[esq+1].number > v[dir].number) troca(v,esq+1,dir);

    i=particao(v,esq+1,dir-1);
    Quick_mediana(v,esq,i-1);
    Quick_mediana(v,i+1,dir);

}

//////////////////////////////////////////////////////////////////////////////////

int particaoo_string(Product arr[], int esq, int dir){

    int fim = esq;
    for(int i = esq+1; i <= dir; i++){
        if(who_is_Minor(arr[i].description,arr[esq].description)){
            fim++;
            troca(arr,i,fim);
        }
    }

    troca(arr,fim,esq);

    return fim;

}

void Quick_mediana_string(Product arr[], int esq, int dir){

    if(esq >= dir) return;

    int i;
    troca(arr, esq+1,(esq+dir)/2);

    if(who_is_Minor(arr[esq].description,arr[esq+1].description) == 0){
        troca(arr,esq,esq+1);
    }
    if(who_is_Minor(arr[esq].description,arr[dir].description) == 0){
        troca(arr,esq,dir);
    }
    if(who_is_Minor(arr[dir].description,arr[esq+1].description)){
        troca(arr,dir,esq+1);
    }

    i = particaoo_string(arr,esq+1,dir-1);

    Quick_mediana_string(arr,esq,i-1);
    Quick_mediana_string(arr,i+1,dir);

}