#define size 30
#define str10000 1000
#define str20000 2000
#define str50000 2500
#define str72500 4000
#define str100000 5000

struct Insertion{

    double e10000, e20000, e50000, e72500, e100000; // guarda o tempo das execuções da ordenação dos números
    double c10000, c20000, c50000, c72500, c100000; // guarda o tempo das execuções das ordenações das strings

};
typedef struct Insertion insertion;

struct Heap{

    double e10000, e20000, e50000, e72500, e100000; // guarda o tempo das execuções da ordenação dos números
    double c10000, c20000, c50000, c72500, c100000; // guarda o tempo das execuções das ordenações das strings

};
typedef struct Heap heap;


struct Quick{

    double e10000, e20000, e50000, e72500, e100000; // guarda o tempo das execuções da ordenação dos números
    double c10000, c20000, c50000, c72500, c100000; // guarda o tempo das execuções das ordenações das strings

};
typedef struct Quick quick;

struct Quickm{

    double e10000, e20000, e50000, e72500, e100000; // guarda o tempo das execuções da ordenação dos números
    double c10000, c20000, c50000, c72500, c100000; // guarda o tempo das execuções das ordenações das strings

};
typedef struct Quickm quickm;


struct Pancake{

    double e10000, e20000, e50000, e72500, e100000; // guarda o tempo das execuções da ordenação dos números
    double c10000, c20000, c50000, c72500, c100000; // guarda o tempo das execuções das ordenações das strings

};
typedef struct Pancake pancake;

struct Counting{

    double e10000, e20000, e50000, e72500, e100000; // guarda o tempo das execuções da ordenação dos números

};
typedef struct Counting counting;

struct Radix{

    double e10000, e20000, e50000, e72500, e100000; // guarda o tempo das execuções da ordenação dos números
    double c10000, c20000, c50000, c72500, c100000; // guarda o tempo das execuções das ordenações das strings

};
typedef struct Radix radix;


struct product{

    char description[size];
    int number;

};
typedef struct product Product; 

void print_table(insertion ist, heap hp, quick qk, quickm qkm, pancake pk, counting ctg, radix rdx);
void Print_Vector_Strings(Product p[], int sz);
void Print_Vector_Numbers(Product p[], int sz);

void Random_String(Product p[], int sz);

void InsertionSort(Product p[], int sz);
void InsertionSortString(Product p[], int sz);

int who_is_Minor(char s1[], char s2[]);

void heap_max(Product arr[], int pos, int sz);
void build_heap_max(Product arr[], int end);
void Heap(Product arr[], int sz);

void heap_max_string(Product arr[], int pos, int sz);
void build_heap_max_string(Product arr[], int sz);
void Heap_string(Product arr[], int sz);

int Counting(Product arr[], int SIZE);

void Pancake(Product arr[], int sz);
void Pancake_String(Product arr[], int sz);
void inverte_arr(Product arr[], int sz, int pos);

void Quick(Product v[], int esq, int dir);
void troca(Product v[], int i,int j);
int particao(Product v[],int esq,int dir);
int particao_string(Product arr[], int esq, int dir);
void Quick_String(Product arr[], int esq, int dir);


void Quick_mediana(Product v[], int esq, int dir);
void trocah(Product v[], int i,int j);
int particaoo(Product v[],int esq,int dir);
int particaoo_string(Product arr[], int esq, int dir);
void Quick_mediana_string(Product arr[], int esq, int dir);

void radixSort(Product arr[], int sz);
void count(Product arr[], int sz, int exp);