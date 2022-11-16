#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "work.h"

void print_table(insertion ist, heap hp, quick qk, quickm qkm, pancake pk, counting ctg, radix rdx){

    printf("###\t\tResults of Benchmarking - Averages of 10 runs (NUMBERS) (TIME IN SECONDS)\t\t###\n\n");

    printf("\t\t10000\t\t20000\t\t25000\t\t40000\t\t50000\n");
    printf("Insertion  \t%lf\t%lf\t%lf\t%lf\t%lf\n", ist.e10000, ist.e20000, ist.e50000, ist.e72500, ist.e100000);
    printf("Heap       \t%lf\t%lf\t%lf\t%lf\t%lf\n", hp.e10000, hp.e20000, hp.e50000, hp.e72500, hp.e100000);
    printf("Quick      \t%lf\t%lf\t%lf\t%lf\t%lf\n", qk.e10000, qk.e20000, qk.e50000, qk.e72500, qk.e100000);
    printf("Quick Media\t%lf\t%lf\t%lf\t%lf\t%lf\n", qkm.e10000, qkm.e20000, qkm.e50000, qkm.e72500, qkm.e100000);
    printf("Pancake    \t%lf\t%lf\t%lf\t%lf\t%lf\n", pk.e10000, pk.e20000, pk.e50000, pk.e72500, pk.e100000);
    printf("Couting    \t%lf\t%lf\t%lf\t%lf\t%lf\n", ctg.e10000, ctg.e20000, ctg.e50000, ctg.e72500, ctg.e100000);
    printf("Radix      \t%lf\t%lf\t%lf\t%lf\t%lf\n", rdx.e10000, rdx.e20000, rdx.e50000, rdx.e72500, rdx.e100000);

    printf("\n\n");

    printf("###\t\tResults of Benchmarking - Averages of 10 runs (STRINGS) (TIME IN SECONDS)\t\t###\n\n");

    printf("\t\t10000\t\t20000\t\t25000\t\t40000\t\t50000\n");
    printf("Insertion  \t%lf\t%lf\t%lf\t%lf\t%lf\n", ist.c10000,ist.c20000,ist.c50000,ist.c72500,ist.c100000);
    printf("Heap       \t%lf\t%lf\t%lf\t%lf\t%lf\n", hp.c10000,hp.c20000,hp.c50000,hp.c72500,hp.c100000);
    printf("Quick      \t%lf\t%lf\t%lf\t%lf\t%lf\n", qk.c10000,qk.c20000,qk.c50000,qk.c72500,qk.c100000);
    printf("Quick Media\t%lf\t%lf\t%lf\t%lf\t%lf\n", qkm.c10000,qkm.c20000,qkm.c50000,qkm.c72500,qkm.c100000);
    printf("Pancake    \t%lf\t%lf\t%lf\t%lf\t%lf\n", pk.c10000,pk.c20000,pk.c50000,pk.c72500,pk.c100000);
    printf("Couting    \t--------\t--------\t--------\t--------\t--------\n");
    printf("Radix      \t--------\t--------\t--------\t--------\t--------\n");

    printf("\n\n");

}

void Random_String(Product p[], int sz){

    //setbuf(stdin,NULL);
    //sleep(1); 

    char random[] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890";
    int size_random = sizeof(random)/sizeof(random[0]);

    // Fill in the 'description' field
    srand((unsigned int)time(NULL));
    for(int i = 0; i < sz; i++){
        int r = rand() % 1000;
        p[i].number = r;
        for(int j = 0; j < size; j++){

            r = rand() % sizeof(random)/sizeof(random[0]);
            p[i].description[j] = random[r];

        }
    }

}

void Print_Vector_Strings(Product p[], int sz){

    int ok = 0;
    for(int i = 0; i < sz; i++){
        ok = 1;
        for(int j = 0; j < size; j++){
            printf("%c", p[i].description[j]);
        }
        printf("\n");
    }

}

void Print_Vector_Numbers(Product p[], int sz){

    int ok = 0;
    for(int i = 0; i < sz; i++){
        if(ok) printf(" | ");
        printf("%d", p[i].number);
        ok = 1;
    }
    
    printf("\n");

}

// Retorna verdadeiro quando a primeira string 's1' é menor
int who_is_Minor(char s1[], char s2[]){

    int r = strcmp(s1,s2);

    if(r < 0) return 1; // s1 é menor
    else      return 0; // s2 é menor

}