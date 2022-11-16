#include "work.h"

void inverte_arr(Product arr[], int ini, int fim){

    int i = ini;
    int j = fim;
    while(i < j){
        Product temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }

}

void Pancake(Product arr[], int sz){

    int maior = 0;
    for(int i = 1; i < sz; i++){
        if(arr[maior].number < arr[i].number) maior = i;
    }

    inverte_arr(arr,0,maior);
    inverte_arr(arr,0,sz-1);
    sz--;
    if(sz > 0) Pancake(arr,sz);

}

/////////////////////////////////////////////////////////////////////////////////////

void Pancake_String(Product arr[], int sz){

    int maior = 0;
    for(int i = 1; i < sz; i++){
        if(who_is_Minor(arr[i].description, arr[maior].description) == 0) maior = i;
    }

    inverte_arr(arr,0,maior);
    inverte_arr(arr,0,sz-1);
    sz--;
    if(sz > 0) Pancake_String(arr,sz);

}