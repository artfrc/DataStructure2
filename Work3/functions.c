#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "main.h"
#include "string.h"

void VisualizaTexto(){

    char c;
    char palavra[MAX];
    int i = 0, ok = 0, cont = 0;
    FILE * arq;
    arq = fopen("palavras.txt", "r");

    do{

        c = fgetc(arq);
        if(c >= 64 && c <= 90){
            ok = 1;
            c = tolower(c);
            palavra[i] = c;
            i++;
        }else if(c >= 97 && c <= 122){
            ok = 1;
            palavra[i] = c;
            i++;
        }else{
            palavra[i] = '\0';
            printf("%s", palavra);
            if(ok){
                printf(" ");
                cont++;
            }
            
            i = 0;
            ok = 0;
        }

    }while(c != EOF);

    fclose(arq);

    printf("\n\n> Numero de palavras: %d\n", cont);

}

void carregaEstrutPesqBin(char palavras[][MAX], int frequencia[]){

    // Inicio meu vetor com todas posições contendo "#X#" e 0
    for(int i = 0; i < TEXTO; i++){
        strcpy(palavras[i],"#X#");
        frequencia[i] = 0;
    }

    // Ler o arquivo, inserir no vetor 'palavras' e contar frequencia
    char c;
    char palavra[MAX];
    int i = 0, ok = 0, cont = 0;
    FILE * arq;
    arq = fopen("palavras.txt", "r");

    do{

        c = fgetc(arq);
        if(c >= 64 && c <= 90){
            ok = 1;
            c = tolower(c);
            palavra[i] = c;
            i++;
        }else if(c >= 97 && c <= 122){
            ok = 1;
            palavra[i] = c;
            i++;
        }else{
            palavra[i] = '\0';
            if(ok){
                int t;
                for(t = 0; frequencia[t] != 0; t++){}
                palavraProcessada(palavras, t, palavra, frequencia);
            }
            
            i = 0;
            ok = 0;
        }

    }while(c != EOF);

    fclose(arq);

    int soma = 0;

}

void palavraProcessada(char vetor[][MAX], int t, char p[], int freq[]){

    // Procura a palavra no vetor utilizando busca binária
    // Se não estiver, entao insiro

    int esq = 0, dir = t-1, meio;

    if(dir == -1){
        strcpy(vetor[0],p);
        freq[0]++;
        return;
    }

    while(esq <= dir){

        meio = (esq+dir)/2;
        if(strcmp(p,vetor[meio]) == 0){
            // está no vetor
            freq[meio]++;
            return;
        }else{
            if(strcmp(p,vetor[meio]) < 0){
                dir = meio-1;
            }else{
                esq = meio+1;
            }
        }

    }

    // nova palavra é menor
    if(strcmp(p,vetor[meio]) < 0){
        for(int i = t-1; i >= meio; i--){
            strcpy(vetor[i+1],vetor[i]);
            freq[i+1] = freq[i];
        }
        strcpy(vetor[meio],p);
        freq[meio] = 1;
    }else{
        for(int i = t-1; i > meio; i--){
            strcpy(vetor[i+1],vetor[i]);
            freq[i+1] = freq[i];
        }
        strcpy(vetor[meio+1],p);
        freq[meio+1] = 1;
    }

}

int contaFrequencia(char palavras[][MAX], int frequencia[], char p[]){

    int esq = 0, dir, meio;
    for(dir = 0; frequencia[dir] != 0; dir++){}
    dir--;
    
    while(esq <= dir){

        meio = (esq+dir)/2;
        if(strcmp(p,palavras[meio]) == 0){
            // está no vetor
            return frequencia[meio];
        }else{
            if(strcmp(p,palavras[meio]) < 0){
                dir = meio-1;
            }else{
                esq = meio+1;
            }
        }

    }

    return -1;

}

noArv criaArv(){

    return NULL;

}

void apagaNo(noArv no){

    if(no != NULL){
        apagaNo(no->esq);
        apagaNo(no->dir);
        free(no);
        no = NULL;
    }

}

void apagaArv(noArv * no){

    if(no != NULL){
        apagaNo(*no);
    }

    no = NULL;

}

int insereArv(noArv * no, char elem[]){

    // Arv vazia
    if(*no == NULL){
        noArv novoNo;
        novoNo = (noArv)malloc(sizeof(struct noArvore));
        if(novoNo == NULL)
            return 0;
        novoNo->dir = NULL;
        novoNo->esq = NULL;
        novoNo->frequencia = 1;
        strcpy(novoNo->info,elem);
        *no = novoNo;
        return 1;
    }else{

        // percorrer a arvore para achar a posicao certa do novo elemento
        if(strcmp((*no)->info,elem) == 0){
            (*no)->frequencia++;
            return 0;
        }
        else if(strcmp((*no)->info,elem) < 0){
            return insereArv(&((*no)->dir),elem);
        }else{
            return insereArv(&((*no)->esq),elem);
        }

    }

}

void imprimeArv(noArv * no){

    if(*no == NULL){
        return;
    }else{

        printf("%s  ->  %s  %s\n", (*no)->info, (*no)->esq->info, (*no)->dir->info);
        imprimeArv(&((*no)->esq));
        imprimeArv(&((*no)->dir));

    }

}

noArv carregaEstrutArvBin(){

    noArv raiz = criaArv();

    char c;
    char palavra[MAX];
    int i = 0, ok = 0, cont = 0;

    FILE * arq;
    arq = fopen("palavras.txt", "r");

    do{

        c = fgetc(arq);
        if(c >= 64 && c <= 90){
            ok = 1;
            c = tolower(c);
            palavra[i] = c;
            i++;
        }else if(c >= 97 && c <= 122){
            ok = 1;
            palavra[i] = c;
            i++;
        }else{
            palavra[i] = '\0';
            if(insereArv(&raiz,palavra)){
                cont++;
            }
            
            i = 0;
            ok = 0;
        }

    }while(c != EOF);
    
    fclose(arq);

    return raiz;

}

int BuscaArv(noArv * no, char elemento[]){

    if(*no == NULL){
        //printf("\n> Palavra não encontrada.\n");
        return 0;
    }

    if(strcmp((*no)->info,elemento) == 0){
        //printf("\n> Palavra %s encontrada. Frequencia: %d\n", (*no)->info, (*no)->frequencia);
        return 1;
    }

    if(strcmp((*no)->info,elemento) < 0)
        return BuscaArv(&(*no)->dir,elemento);
    else
        return BuscaArv(&(*no)->esq,elemento);

}

noArvAVL criaAVL(){

    return NULL;

}

int alturaNo(noArvAVL no){

    if(no == NULL)
        return -1;

    else
        return (no)->altura;

}

int FatorBalanceamento(noArvAVL no){

    return abs(alturaNo(no->esq) - alturaNo(no->dir));

}

int maior(int x, int y){

    if(x > y) return x;
    else      return y;

}   

void RotacaoEsquerda(noArvAVL * no){

    noArvAVL g = (*no)->dir;
    (*no)->dir = g->esq;
    g->esq = (*no);
    
    (*no)->altura = maior(alturaNo((*no)->esq), alturaNo((*no)->dir)) + 1;
    g->altura = maior(alturaNo((g->dir)), (*no)->altura) + 1;

    (*no) = g;  

}

void RotacaoDireita(noArvAVL * no){

    noArvAVL g = (*no)->esq;
    (*no)->esq = g->dir;
    g->dir = *no;

    (*no)->altura = maior(alturaNo((*no)->esq), alturaNo((*no)->dir)) + 1;
    g->altura = maior(alturaNo((g->esq)), (*no)->altura) + 1;

    *no = g;

}

void RotacaoDuplaEsquerda(noArvAVL * no){

    RotacaoDireita(&(*no)->dir);
    RotacaoEsquerda(no);

}

void RotacaoDuplaDireita(noArvAVL * no){

    RotacaoEsquerda(&(*no)->esq);
    RotacaoDireita(no);

}

int insereArvAVL(noArvAVL * no, char elemento[]){

    int r;
    if(*no == NULL){
        noArvAVL novo;
        novo = (noArvAVL)malloc(sizeof(struct noArvoreAVL));
        if(novo == NULL)
            return 0;
        
        strcpy(novo->info,elemento);
        novo->altura = 0;
        novo->esq = NULL;
        novo->dir = NULL;
        novo->frequencia = 1;
        *no = novo;

        return 1;
    
    }else{

        noArvAVL atual = *no;
        if(strcmp(elemento,atual->info) < 0){
            r = insereArvAVL(&(atual->esq),elemento);
            if(r == 1){
                if(FatorBalanceamento(atual) >= 2){
                    if(strcmp(elemento,(*no)->esq->info) < 0){
                        RotacaoDireita(no);
                    }else{
                        RotacaoDuplaDireita(no);
                    }
                }
            }
        }else if(strcmp(elemento,atual->info) > 0){
            r = insereArvAVL(&(atual->dir),elemento);
            if(r == 1){
                if(FatorBalanceamento(atual) >= 2){
                    if(strcmp((*no)->dir->info, elemento) < 0){
                        RotacaoEsquerda(no);
                    }else{
                        RotacaoDuplaEsquerda(no);
                    }
                }
            }
        }else{
            atual->frequencia++;
            return 0;
        }

        atual->altura = maior(alturaNo(atual->esq), alturaNo(atual->dir)) + 1;

    }


    return r;

}

noArvAVL carregaArvAVL(){

    noArvAVL raiz = criaAVL();

    char c;
    char palavra[MAX];
    int i = 0, ok = 0, cont = 0;

    FILE * arq;
    arq = fopen("palavras.txt", "r");

    do{

        c = fgetc(arq);
        if(c >= 64 && c <= 90){
            ok = 1;
            c = tolower(c);
            palavra[i] = c;
            i++;
        }else if(c >= 97 && c <= 122){
            ok = 1;
            palavra[i] = c;
            i++;
        }else{
            palavra[i] = '\0';
            if(insereArvAVL(&raiz,palavra)){
                cont++;
            }
            
            i = 0;
            ok = 0;
        }

    }while(c != EOF);

    fclose(arq);

    return raiz;

}

void emOrdem_ArvAVL(noArvAVL * no){

    if(no == NULL)
        return;
    
    if(*no != NULL){
        emOrdem_ArvAVL(&((*no)->esq));
        printf("%s  ->  %s  %s\n", (*no)->info, (*no)->esq, (*no)->dir);
        emOrdem_ArvAVL(&((*no)->dir));
    }

}

int BuscaAVL(noArvAVL * no, char elemento[]){

    if(*no == NULL){
        //printf("\n> Palavra não encontrada.\n");
        return 0;
    }

    if(strcmp((*no)->info,elemento) == 0){
        //printf("\n> Palavra %s encontrada. Frequencia: %d\n", (*no)->info, (*no)->frequencia);
        return 1;
    }

    if(strcmp((*no)->info,elemento) < 0)
        return BuscaAVL(&(*no)->dir,elemento);
    else
        return BuscaAVL(&(*no)->esq,elemento);

}

void apagaNoAVL(noArvAVL no){

    if(no != NULL){
        apagaNoAVL(no->esq);
        apagaNoAVL(no->dir);
        free(no);
        no = NULL;
    }

}

void apagaArvAVL(noArvAVL * no){

    if(no != NULL){
        apagaNoAVL(*no);
    }

    no = NULL;

}

int InsereAvlFrequencia(noArvAVL * no , char elemento[], int frequencia){

    int r;
    if(*no == NULL){
        noArvAVL novo;
        novo = (noArvAVL)malloc(sizeof(struct noArvoreAVL));
        if(novo == NULL)
            return 0;
        
        strcpy(novo->info,elemento);
        novo->altura = 0;
        novo->esq = NULL;
        novo->dir = NULL;
        novo->frequencia = frequencia;
        *no = novo;

        return 1;
    
    }else{

        noArvAVL atual = *no;
        if(frequencia <= atual->frequencia){
            r = InsereAvlFrequencia(&(atual->esq),elemento,frequencia);
            if(r == 1){
                if(FatorBalanceamento(atual) >= 2){
                    if(frequencia < (*no)->esq->frequencia){
                        RotacaoDireita(no);
                    }else{
                        RotacaoDuplaDireita(no);
                    }
                }
            }
        }else{
            r = InsereAvlFrequencia(&(atual->dir),elemento,frequencia);
            if(r == 1){
                if(FatorBalanceamento(atual) >= 2){
                    if((*no)->dir->frequencia < frequencia){
                        RotacaoEsquerda(no);
                    }else{
                        RotacaoDuplaEsquerda(no);
                    }
                }
            }
        }

        //atual->altura = maior(alturaNo(atual->esq), alturaNo(atual->dir)) + 1;

    }

    return r;
    
}

int BuscaAVLFreq2(noArvAVL * no, int freq){

    if(*no == NULL){
        printf("\n> Palavra não encontrada.\n");
        return 0;
    }

    if((*no)->frequencia == freq){
        printf("\n> Palavra %s encontrada. Frequencia: %d\n", (*no)->info, (*no)->frequencia);
        return 1;
    }

    if((*no)->frequencia != freq)
        return BuscaAVLFreq2(&(*no)->dir,freq);
    else
        return BuscaAVLFreq2(&(*no)->esq,freq);

}

noArvAVL BuscaAVLFreq(){

    char palavras[TEXTO][MAX];
    int frequencia[TEXTO];
    carregaEstrutPesqBin(palavras,frequencia);

    for(int i = 0; i < TEXTO; i++){
        frequencia[i] = 0;
    }

    noArvAVL raiz = criaAVL();
    
    for(int i = 0; strcmp(palavras[i],"#X#") != 0; i++){

        char palavra[MAX];
        strcpy(palavra,palavras[i]);
        InsereAvlFrequencia(&raiz,palavra,frequencia[i]);

    }

   return raiz;

}

