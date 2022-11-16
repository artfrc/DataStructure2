#define MAX 50

struct adjacente{

    char c[MAX];
    int peso;
    struct adjacente * prox;

};
typedef struct adjacente Adjacente;

struct vertice{

    char c[MAX];
    struct vertice * prox;
    struct adjacente * adj;

};
typedef struct vertice Vertice;

struct grafo{

    int nroVertice;
    int nroAresta;
    struct vertice * matriz;

};
typedef struct grafo Grafo;

struct fila{

    char c[MAX];
    struct fila * prox;

};
typedef struct fila * Fila;

struct pilha{

    char c[MAX];
    struct pilha * prox;

};
typedef struct pilha * Pilha;

Grafo * start();
Grafo * criaGrafo();
int insereVertice(Grafo * g, char c[], char arq[]);
int insereAresta(Grafo * g, char origem[], char destino[], int peso, char arqv[], char arqa[]);
void infoGrafo(Grafo * g);
void destroyGrafo(Grafo * g);
void letterC(Grafo * g, char usuario[], int k);
Fila criaFila();
int vazia(Fila f);
int push(Fila * f, char c[]);
int pop(Fila * f, char c[]);
void mostraFila(Fila * f);
void destroyFila(Fila * f);
void BuscaLargura(Grafo * g, char raiz[]);
Pilha criaPilha();
int pilhaVazia(Pilha p);
int inserePilha(Pilha * p, char c[]);
int removePilha(Pilha * p, char c[]);
void imprimePilha(Pilha * p);
void destroyPilha(Pilha * p);
void BuscaProfundidadeModificada(Grafo * g, char raiz[], int D);
int procuraVertice(Grafo * g, char * vertice);
int menorCaminho(Grafo * g, char * raiz, int anterior[], int n, int * distancia);

int BuscaProfundidade(Grafo * g, char raiz[], int inicializacao[], int finalizacao[], int * cont);
Grafo * grafoTransposto(Grafo * g);
void CFC(Grafo * g, char raiz[]);