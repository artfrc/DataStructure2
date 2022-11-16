#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "work.h"

#define TAM 10

double insertionFunc(int sz){

    clock_t time = 0;
    Product * ptr = (Product *) malloc(sz*sizeof(Product));
    double acc = 0;
    int i = 10;
    while(i > 0){

        time = 0;
        Random_String(ptr, sz);
        time = clock();
        InsertionSort(ptr, sz);
        time = clock() - time;

        acc += (double)time/(CLOCKS_PER_SEC);
        i--;

    }
    
    free(ptr);

    return acc/10;

}

double insertionStringFunc(int sz){

    clock_t time = 0;
    Product * ptr = (Product *) malloc(sz*sizeof(Product));
    double acc = 0;
    int i = 10;
    while(i > 0){

        time = 0;
        Random_String(ptr, sz);
        time = clock();
        InsertionSortString(ptr, sz);
        time = clock() - time;

        acc += (double)time/(CLOCKS_PER_SEC);
        i--;

    }
    
    free(ptr);

    return acc/10;

}

double QuickSort(int sz){

    clock_t time = 0;
    Product * ptr = (Product *) malloc(sz*sizeof(Product));
    double acc = 0;
    int i = 10;
    while(i > 0){

        time = 0;
        Random_String(ptr, sz);
        time = clock();
        Quick(ptr, 0, sz-1);
        time = clock() - time;

        acc += (double)time/(CLOCKS_PER_SEC);
        i--;

    }
    
    free(ptr);

    return acc/10;

}

double QuickSortString(int sz){

    clock_t time = 0;
    Product * ptr = (Product *) malloc(sz*sizeof(Product));
    double acc = 0;
    int i = 10;
    while(i > 0){

        time = 0;
        Random_String(ptr, sz);
        time = clock();
        Quick_String(ptr, 0, sz-1);
        time = clock() - time;

        acc += (double)time/(CLOCKS_PER_SEC);
        i--;

    }
    
    free(ptr);

    return acc/10;

}

double QuickSortM(int sz){

    clock_t time = 0;
    Product * ptr = (Product *) malloc(sz*sizeof(Product));
    double acc = 0;
    int i = 10;
    while(i > 0){

        time = 0;
        Random_String(ptr, sz);
        time = clock();
        Quick(ptr, 0, sz-1);
        time = clock() - time;

        acc += (double)time/(CLOCKS_PER_SEC);
        i--;

    }
    
    free(ptr);

    return acc/10;

}

double HeapSortFunc(int sz){

    clock_t time = 0;
    Product * ptr = (Product *) malloc(sz*sizeof(Product));
    double acc = 0;
    int i = 10;
    while(i > 0){

        time = 0;
        Random_String(ptr, sz);
        time = clock();
        Heap(ptr, sz-1);
        time = clock() - time;

        acc += (double)time/(CLOCKS_PER_SEC);
        i--;

    }
    
    free(ptr);

    return acc/10;

}

double HeapSortFuncString(int sz){

    clock_t time = 0;
    Product * ptr = (Product *) malloc(sz*sizeof(Product));
    double acc = 0;
    int i = 10;
    while(i > 0){

        time = 0;
        Random_String(ptr, sz);
        time = clock();
        Heap_string(ptr, sz-1);
        time = clock() - time;

        acc += (double)time/(CLOCKS_PER_SEC);
        i--;

    }
    
    free(ptr);

    return acc/10;

}

double CoutingInsertion(int sz){

    clock_t time = 0;
    Product * ptr = (Product *) malloc(sz*sizeof(Product));
    double acc = 0;
    int i = 10;
    while(i > 0){

        time = 0;
        Random_String(ptr, sz);
        time = clock();
        Counting(ptr, sz);
        time = clock() - time;

        acc += (double)time/(CLOCKS_PER_SEC);
        i--;

    }
    
    free(ptr);

    return acc/10;

}

double PancakeSort(int sz){

    clock_t time = 0;
    Product * ptr = (Product *) malloc(sz*sizeof(Product));
    double acc = 0;
    int i = 10;
    while(i > 0){

        time = 0;
        Random_String(ptr, sz);
        time = clock();
        Pancake(ptr, sz);
        time = clock() - time;

        acc += (double)time/(CLOCKS_PER_SEC);
        i--;

    }
    
    free(ptr);

    return acc/10;

}

double PancakeSortString(int sz){

    clock_t time = 0;
    Product * ptr = (Product *) malloc(sz*sizeof(Product));
    double acc = 0;
    int i = 10;
    while(i > 0){

        time = 0;
        Random_String(ptr, sz);
        time = clock();
        Pancake_String(ptr, sz);
        time = clock() - time;

        acc += (double)time/(CLOCKS_PER_SEC);
        i--;

    }
    
    free(ptr);

    return acc/10;

}

double Radix(int sz){

    clock_t time = 0;
    Product * ptr = (Product *) malloc(sz*sizeof(Product));
    double acc = 0;
    int i = 10;
    while(i > 0){

        time = 0;
        Random_String(ptr, sz);
        time = clock();
        radixSort(ptr, sz);
        time = clock() - time;

        acc += (double)time/(CLOCKS_PER_SEC);
        i--;

    }
    
    free(ptr);

    return acc/10;

}

int main(void){


    Product p[TAM];
    int op = -1;
    int op_test = -1;
    while(op != 0){
        
        system("clear");

        printf("[1]. Testar funções de ordenação.\n");
        printf("[2]. Gerar tabelas.\n");
        printf("[0]. Sair.\n");
        printf("Opção: ");
        scanf("%d", &op);

        switch(op){

            case 0:
                system("clear");
                printf(">>> Bye.\n");
                break;

            case 1:

                system("clear");
                printf("[1]. Verificar ordenacao por números.\n");
                printf("[2]. Verificar ordenação por strings.\n");
                printf("[0]. Voltar\n");
                printf("Opção: ");
                scanf("%d", &op_test);

                switch(op_test){

                    case 1:
                        system("clear");
                        printf(">>> INSERTION SORT\n");
                        printf("Vetor gerado:  \t");
                        Random_String(p,TAM);
                        Print_Vector_Numbers(p,TAM);
                        printf("Vetor ordenado:\t");
                        InsertionSort(p,TAM);
                        Print_Vector_Numbers(p,TAM);

                        printf("\n>>> HEAP SORT\n");
                        printf("Vetor gerado:  \t");
                        Random_String(p, TAM);
                        Print_Vector_Numbers(p,TAM);
                        printf("Vetor ordenado:\t");
                        Heap(p, TAM-1);
                        Print_Vector_Numbers(p,TAM);

                        printf("\n>>> QUICK SORT BASICO\n");
                        printf("Vetor gerado:  \t");
                        Random_String(p,TAM);
                        Print_Vector_Numbers(p,TAM);
                        printf("Vetor ordenado:\t");
                        Quick(p,0,TAM-1);
                        Print_Vector_Numbers(p,TAM);

                        printf("\n>>> QUICK SORT MEDIANA DE 3\n");
                        printf("Vetor gerado:  \t");
                        Random_String(p,TAM);
                        Print_Vector_Numbers(p,TAM);
                        printf("Vetor ordenado:\t");
                        Quick_mediana(p,0,TAM-1);
                        Print_Vector_Numbers(p,TAM);

                        printf("\n>>> PANCAKE SORT\n");
                        printf("Vetor gerado:  \t");
                        Random_String(p,TAM);
                        Print_Vector_Numbers(p,TAM);
                        printf("Vetor ordenado:\t");
                        Pancake(p,TAM);
                        Print_Vector_Numbers(p,TAM);

                        printf("\n>>> COUNTING SORT\n");
                        printf("Vetor gerado:  \t");
                        Random_String(p,TAM);
                        Print_Vector_Numbers(p,TAM);
                        printf("Vetor ordenado:\t");
                        Counting(p,TAM);
                        Print_Vector_Numbers(p,TAM);

                        printf("\n>>> RADIX SORT\n");
                        printf("Vetor gerado:  \t");
                        Random_String(p,TAM);
                        Print_Vector_Numbers(p,TAM);
                        printf("Vetor ordenado:\t");
                        radixSort(p,TAM);
                        Print_Vector_Numbers(p,TAM);

                        printf("\n>>> Press Enter\n");
                        setbuf(stdin,NULL);
                        getchar();

                        break;

                    case 2:
                        system("clear");
                        printf(">>> INSERTION SORT\n");
                        printf("Vetor gerado:\n");
                        Random_String(p,TAM);
                        Print_Vector_Strings(p,TAM);
                        printf("\nVetor ordenado:\n");
                        InsertionSortString(p,TAM);
                        Print_Vector_Strings(p,TAM);


                        printf("\n>>> HEAP SORT\n");
                        printf("Vetor gerado:\n");
                        Random_String(p, TAM);
                        Print_Vector_Strings(p,TAM);
                        printf("\nVetor ordenado:\n");
                        Heap_string(p, TAM-1);
                        Print_Vector_Strings(p,TAM);

                        printf("\n>>> QUICK SORT BASICO\n");
                        printf("Vetor gerado:\n");
                        Random_String(p,TAM);
                        Print_Vector_Strings(p,TAM);
                        printf("\nVetor ordenado:\n");
                        Quick_String(p,0,TAM-1);
                        Print_Vector_Strings(p,TAM);

                        printf("\n>>> QUICK SORT MEDIANA DE 3\n");
                        printf("Vetor gerado:\n");
                        Random_String(p,TAM);
                        Print_Vector_Strings(p,TAM);
                        printf("\nVetor ordenado:\n");
                        Quick_mediana_string(p,0,TAM-1);
                        Print_Vector_Strings(p,TAM);


                        printf("\n>>> PANCAKE SORT\n");
                        printf("Vetor gerado:\n");
                        Random_String(p,TAM);
                        Print_Vector_Strings(p,TAM);
                        printf("\nVetor ordenado:\n");
                        Pancake_String(p,TAM);
                        Print_Vector_Strings(p,TAM);

                        printf("\n>>> Press Enter\n");
                        setbuf(stdin,NULL);
                        getchar();

                        break;

                    case 0:

                        break;

                    default:
                        printf("\n>>> Opção inválida!\n");

                }

                break;
            
            case 2:
    
                system("clear");
                
                printf(">>> Hold! This might take a while...\n");

                // Insertion Números
                insertion ist;
                ist.e10000 = insertionFunc(str10000); 
                ist.e20000 = insertionFunc(str20000);
                ist.e50000 = insertionFunc(str50000);
                ist.e72500 = insertionFunc(str72500);
                ist.e100000 = insertionFunc(str100000);
                // Insertion Strings
                ist.c10000 = insertionStringFunc(str10000); 
                ist.c20000 = insertionStringFunc(str20000);
                ist.c50000 = insertionStringFunc(str50000);
                ist.c72500 = insertionStringFunc(str72500);
                ist.c100000 = insertionStringFunc(str100000);

                // Heap Sort Números
                heap hp;
                hp.e10000 = HeapSortFunc(str10000);
                hp.e20000 = HeapSortFunc(str20000);
                hp.e50000 = HeapSortFunc(str50000);
                hp.e72500 = HeapSortFunc(str72500);
                hp.e100000 = HeapSortFunc(str100000);
                // Heap Sort String
                hp.c10000 = HeapSortFuncString(str10000);
                hp.c20000 = HeapSortFuncString(str20000);
                hp.c50000 = HeapSortFuncString(str50000);
                hp.c72500 = HeapSortFuncString(str72500);
                hp.c100000 = HeapSortFuncString(str100000);

                // Quick Sort Básico Números
                quick qk;
                qk.e10000 = QuickSort(str10000);
                qk.e20000 = QuickSort(str20000);
                qk.e50000 = QuickSort(str50000);
                qk.e72500 = QuickSort(str72500);
                qk.e100000 = QuickSort(str100000);
                //Quick Sort Básico Strings
                qk.c10000 = QuickSortString(str10000);
                qk.c20000 = QuickSortString(str20000);
                qk.c50000 = QuickSortString(str50000);
                qk.c72500 = QuickSortString(str72500);
                qk.c100000 = QuickSortString(str100000);

                // Quick Sort Média Números
                quickm qkm;
                qkm.e10000 = QuickSortM(str10000);
                qkm.e20000 = QuickSortM(str20000);
                qkm.e50000 = QuickSortM(str50000);
                qkm.e72500 = QuickSortM(str72500);
                qkm.e100000 = QuickSortM(str100000);    
                //Quick Sort Media String            
                qkm.c10000 = QuickSortM(str10000);
                qkm.c20000 = QuickSortM(str20000);
                qkm.c50000 = QuickSortM(str50000);
                qkm.c72500 = QuickSortM(str72500);
                qkm.c100000 = QuickSortM(str100000);

                // Pancake Sort Números
                pancake pk;
                pk.e10000 = PancakeSort(str10000);
                pk.e20000 = PancakeSort(str20000);
                pk.e50000 = PancakeSort(str50000);
                pk.e72500 = PancakeSort(str72500);
                pk.e100000 = PancakeSort(str100000);
                // Pancake Sort Strings
                pk.c10000 = PancakeSortString(str10000);
                pk.c20000 = PancakeSortString(str20000);
                pk.c50000 = PancakeSortString(str50000);
                pk.c72500 = PancakeSortString(str72500);
                pk.c100000 = PancakeSortString(str100000);

                // Counting Sort Números    
                counting ctg;
                ctg.e10000 = CoutingInsertion(str10000);
                ctg.e20000 = CoutingInsertion(str20000);
                ctg.e50000 = CoutingInsertion(str50000);
                ctg.e72500 = CoutingInsertion(str72500);
                ctg.e100000 = CoutingInsertion(str100000);

                radix rdx;
                rdx.e10000 = Radix(str10000);
                rdx.e20000 = Radix(str20000);
                rdx.e50000 = Radix(str50000);
                rdx.e72500 = Radix(str72500);
                rdx.e100000 = Radix(str100000);


                print_table(ist, hp, qk, qkm, pk, ctg, rdx);
                
                setbuf(stdin,NULL);
                printf(">>> Press Enter\n");
                getchar();

                break;
            
            default:
                printf("\nOpção inválida.\n");
        }

    }


}