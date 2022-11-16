#include <stdio.h>
#include <stdlib.h>
#include "work.h"

void heap_max(Product arr[], int pos, int sz){

    int left, right, high;
    left = pos*2+1;
    right = pos*2+2;
    
    if(left <= sz && arr[left].number > arr[pos].number) high = left;
    else high = pos;

    if(right <= sz &&  arr[right].number > arr[high].number) high = right;

    if(high != pos){
        Product temp = arr[pos];
        arr[pos] = arr[high];
        arr[high] = temp;
        heap_max(arr, high, sz);
    }

}

void build_heap_max(Product arr[], int end){

    for(int i = (end-1)/2; i >= 0; i--){
        heap_max(arr,i,end);
    }

}

void Heap(Product arr[], int sz){

    build_heap_max(arr,sz);    

    for(int i = sz; i >= 0; i--){
        Product temp = arr[0];
        arr[0] = arr[sz];
        arr[sz] = temp;
        sz--;
        heap_max(arr,0,sz);
    }

}

/////////////////////////////////////////////////////////////////////////////////////////////////

void heap_max_string(Product arr[], int pos, int sz){

    int left, right, high;
    left = pos*2+1;
    right = pos*2+2;
    

    
    if(left <= sz && (who_is_Minor(arr[pos].description,arr[left].description))) high = left;
    else high = pos;

    if(right <= sz && (who_is_Minor(arr[high].description,arr[right].description))) high = right;

    if(high != pos){
        Product temp = arr[pos];
        arr[pos] = arr[high];
        arr[high] = temp;
        heap_max_string(arr, high, sz);
    }

}

void build_heap_max_string(Product arr[], int end){

    for(int i = (end-1)/2; i >= 0; i--){
        heap_max_string(arr,i,end);
    }

}

void Heap_string(Product arr[], int sz){

    build_heap_max_string(arr,sz);    

    for(int i = sz; i >= 0; i--){
        Product temp = arr[0];
        arr[0] = arr[sz];
        arr[sz] = temp;
        sz--;
        heap_max_string(arr,0,sz);
    }

}