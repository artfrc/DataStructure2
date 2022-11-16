#include "work.h"

void count(Product arr[], int sz, int exp){

    Product output[sz];
    int counter[10] = { 0 };
    for(int i = 0; i < sz; i++){
        counter[(arr[i].number/exp) % 10]++;
    }

    for (int i = 1; i < 10; i++)
        counter[i] += counter[i - 1];

    for (int i = sz - 1; i >= 0; i--){
        output[counter[(arr[i].number / exp) % 10] - 1] = arr[i];
        counter[(arr[i].number / exp) % 10]--;
    }

    for(int i = 0; i < sz; i++) arr[i] = output[i];

}

void radixSort(Product arr[], int sz){

    int high = 0;
    for(int i = 1; i < sz; i++) if(arr[i].number > arr[high].number) high = i;

    int exp = 1;

    while(arr[high].number/exp > 0){

        count(arr,sz,exp);

        exp *= 10;
    }

}
