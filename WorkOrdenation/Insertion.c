#include "work.h"
#include <string.h>
#include <stdio.h>

void InsertionSort(Product p[], int sz){

    for(int i = 1; i < sz; i++){
        Product current = p[i];
        int j = i-1;
        while(j >= 0 && current.number < p[j].number){
            p[j+1] = p[j];
            j--;
        }
        p[j+1] = current;
    }

}

void InsertionSortString(Product p[], int sz){

    for(int i = 1; i < sz; i++){
        Product current = p[i];
        int j = i-1;
        while(j >= 0 && who_is_Minor(current.description,p[j].description)){
        
            p[j+1].number = p[j].number;
            strcpy(p[j+1].description,p[j].description);
            j--;
        
        }
        p[j+1].number = current.number;
        strcpy(p[j+1].description,current.description);
    }

}