#include "work.h"

int Counting(Product arr[], int SIZE){

    int high = arr[0].number;

    for(int i = 1; i < SIZE; i++){
        if(arr[i].number > high) high = arr[i].number;
        if(arr[i].number < 0) return -1; 
    }

    int v[high];
    for(int i = 0; i < high+1; i++) v[i] = 0;

    for(int i = 0; i < SIZE; i++) v[arr[i].number]++;

    int i = 0;
    int j = 0;
    while(i < high+1){
        while(v[i] > 0){
            arr[j].number = i;
            j++;
            v[i]--;
        }
        i++;
    }

    return 1;

}