#define MAX 20
#define TEXTO 999

struct noArvore{

    char info[MAX];
    int frequencia;
    struct noArvore * esq;
    struct noArvore * dir;

};
typedef struct noArvore * noArv;

struct noArvoreAVL{

    char info[MAX];
    int frequencia;
    int altura;
    struct noArvoreAVL * esq;
    struct noArvoreAVL * dir;

};
typedef struct noArvoreAVL * noArvAVL;

void VisualizaTexto();
void carregaEstrutPesqBin(char palavras[][MAX], int frequencia[]);
void palavraProcessada(char vetor[][MAX], int t, char p[], int freq[]);
int contaFrequencia(char palavras[][MAX], int frequencia[], char p[]);
noArv criaArv();
int insereArv(noArv * no, char elem[]);
void imprimeArv(noArv * no);
noArv carregaEstrutArvBin();
int BuscaArv(noArv * no, char elemento[]);
noArvAVL criaAVL();
int alturaNo(noArvAVL no);
int FatorBalanceamento(noArvAVL no);
void RotacaoEsquerda(noArvAVL * no);
void RotacaoDuplaEsquerda(noArvAVL * no);
void RotacaoDuplaDireita(noArvAVL * no);
int insereArvAVL(noArvAVL * no, char elemento[]);
void emOrdem_ArvAVL(noArvAVL *raiz);
noArvAVL carregaArvAVL();
int BuscaAVL(noArvAVL * no, char elemento[]);
void apagaNo(noArv no);
void apagaArv(noArv * no);
void apagaNoAVL(noArvAVL no);
void apagaArvAVL(noArvAVL * no);
noArvAVL BuscaAVLFreq();
int InsereAvlFrequencia(noArvAVL * no , char elemento[], int frequencia);
int BuscaAVLFreq2(noArvAVL * no, int freq);