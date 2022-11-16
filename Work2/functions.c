#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"


// Inicialização do programa

Grafo * start(){

    FILE * arq;
    arq = fopen("vertices.txt", "w");
    if(arq == NULL){
        printf(">>> Erro ao criar arquivo!\n");
        exit(1);
    }
    
    fclose(arq);

    arq = fopen("arestas.txt", "w");
    if(arq == NULL){
        exit(1);
    }

    fclose(arq);

    Grafo * g;
    g = criaGrafo();

    insereVertice(g,"marina","vertices.txt");
    insereVertice(g,"mirela","vertices.txt");
    insereVertice(g,"ana","vertices.txt");
    insereVertice(g,"daniely","vertices.txt");
    insereVertice(g,"lucas","vertices.txt");
    insereVertice(g,"victor","vertices.txt");
    insereVertice(g,"arthur","vertices.txt");
    insereVertice(g,"matheus","vertices.txt");

    insereAresta(g,"ana","lucas",3,"vertices.txt","arestas.txt");
    insereAresta(g,"marina","mirela",5,"vertices.txt","arestas.txt");
    insereAresta(g,"mirela","marina",5,"vertices.txt","arestas.txt");
    insereAresta(g,"mirela","victor",7,"vertices.txt","arestas.txt");
    insereAresta(g,"ana","mirela",4,"vertices.txt","arestas.txt");
    insereAresta(g,"ana","matheus",4,"vertices.txt","arestas.txt");
    insereAresta(g,"daniely","arthur",7,"vertices.txt","arestas.txt");
    insereAresta(g,"daniely","mirela",6,"vertices.txt","arestas.txt");
    insereAresta(g,"victor","marina",2,"vertices.txt","arestas.txt");
    insereAresta(g,"victor","mirela",6,"vertices.txt","arestas.txt");
    insereAresta(g,"arthur","daniely",8,"vertices.txt","arestas.txt");
    insereAresta(g,"arthur","matheus",3,"vertices.txt","arestas.txt");
    insereAresta(g,"matheus","ana",5,"vertices.txt","arestas.txt");
    insereAresta(g,"matheus","arthur",3,"vertices.txt","arestas.txt");
    insereAresta(g,"lucas","ana",7,"vertices.txt","arestas.txt");
    insereAresta(g,"lucas","victor",4,"vertices.txt","arestas.txt");
    
    return g;

}

// Grafo

int insereVertice(Grafo * g, char c[], char arq[]){

    if(g == NULL || strlen(c) < 2) return 0;

    // nao deixo inserir nome de vertice que contenha espaços no meio
    // isso devido a forma q estou organizando os arquivos
    for(int i = 0; c[i] != '\0'; i++){
        if(c[i] == ' ')
            return 0;
    }

    FILE * f;
    f = fopen(arq, "r");
    if(f == NULL){
        printf("Erro ao abrir arquivo '%s'.\n",arq);
        return 0;
    }

    char texto[51];
    while(fgets(texto, 50, f) != NULL){

        int i;
        char t[51];
        for(i = 0; texto[i] != '\n'; i++)
            t[i] = texto[i];

        t[i] = '\0';

        if(strcmp(c,t) == 0){
            fclose(f);
            return 0;
        }

    }

    fclose(f);

    f = fopen(arq, "a");
    if(f == NULL){
        printf("Erro ao abrir arquivo!\n");
        return 0;
    }

    fprintf(f, "%s\n", c);
    fclose(f);

    Vertice * novo = (Vertice *) malloc(sizeof(Vertice));
    if(novo != NULL){
        strcpy(novo->c,c);
        novo->prox = g->matriz;
        novo->adj = NULL;
        g->matriz = novo;
        g->nroVertice++;    
    }

    return 1;

}

int insereAresta(Grafo * g, char origem[], char destino[], int peso, char arqv[], char arqa[]){

    if(g == NULL) return 0;

    FILE * f;
    
    int ok = 0;

    f = fopen(arqv, "r");
    if(f == NULL){
        printf("Erro ao abrir arquivo 'vertices.txt'.\n");
        return 0;
    }

    char texto[51];
    while(fgets(texto, 50, f) != NULL && ok != 2){

        int i;
        char t[51];
        for(i = 0; texto[i] != '\n'; i++)
            t[i] = texto[i];

        t[i] = '\0';

        if(strcmp(origem,t) == 0 || strcmp(destino,t) == 0){
            ok++;
        }

    }

    fclose(f);

    if(ok != 2){
        printf("Vertices invalidos!\n");
        return 0; // vértices inválidos
    }

    
    f = fopen(arqa, "r");

    while(fgets(texto, 50, f) != NULL){

        int i = 0, flag = 0;
        char v1[50];
        while(texto[i] != ' '){
            v1[i] = texto[i];
            i++;
        }

        v1[i] = '\0';

        if(strcmp(v1,origem) == 0){
            i++;
            int j = 0;
            while(texto[i] != ' '){
                v1[j] = texto[i];
                i++;
                j++;
            }
            v1[j] = '\0';
        
            if(strcmp(v1,destino) == 0)
                return 0; // já existe a aresta
        }

    }
    fclose(f);

    f = fopen(arqa, "a");
    if(f == NULL){
        printf("Erro ao abrir arquivo!\n");
        return 0;
    }
    fprintf(f, "%s %s %d\n", origem, destino, peso);

    Vertice * aux = g->matriz;
    while(strcmp(aux->c,origem) != 0)
        aux = aux->prox;

    Adjacente * novo = (Adjacente *) malloc(sizeof(Adjacente));
    if(novo != NULL){
        novo->peso = peso;
        novo->prox = aux->adj;
        aux->adj = novo;
        strcpy(novo->c, destino);
        g->nroAresta++;
    }

    fclose(f);

    return 1;

}


Grafo * criaGrafo(){

    Grafo * g;
    g = (Grafo *) malloc(sizeof(Grafo));
    if(g != NULL){

        g->matriz = NULL;
        g->nroAresta = 0;
        g->nroVertice = 0;
        
    }

    return g;

}

void infoGrafo(Grafo * g){

    if(g != NULL){


        Vertice * aux = g->matriz;
        while(aux != NULL){

            printf("%s ->", aux->c);
            Adjacente * adAux = aux->adj;
            while(adAux != NULL){
                printf(" %s(%d)", adAux->c, adAux->peso);
                adAux = adAux->prox;
            }

            printf("\n");
            aux = aux->prox;

        }

        printf("\nNúmero de vértices: %d\nNúmero de arestas: %d\n", g->nroVertice, g->nroAresta);

    }

}

void destroyGrafo(Grafo * g){

    if(g != NULL){


        Vertice * aux = g->matriz;
        while(aux != NULL){

            Adjacente * adAux = aux->adj;
            while(adAux != NULL){
                Adjacente * ad = adAux->prox;
                free(adAux);
                adAux = ad;
            }

            Vertice * vt = aux->prox;
            free(aux);
            aux = vt;

        }

    }    

}

// Letra C

void letterC(Grafo * g, char usuario[], int k){

    if(g == NULL) return;

    // verificar se usuario está no grafo
    Vertice * aux = g->matriz;
    while(aux != NULL && strcmp(usuario,aux->c) != 0){
        aux = aux->prox;
    }

    if(aux == NULL) return; // usuario não está no grafo

    printf("Pessoas que %s interagiu pelo menos %d vezes:\n>>", usuario, k);
    Adjacente * adAux = aux->adj;
    while(adAux != NULL){
        if(adAux->peso >= k){
            printf(" %s(%d)", adAux->c,adAux->peso);
        }
        adAux = adAux->prox;
    }
    printf("\n\nPessoas que interagiram a %s pelo menos %d vezes:\n>>", usuario, k);
    aux = g->matriz;
    while(aux != NULL){
        adAux = aux->adj;
        while(adAux != NULL && strcmp(adAux->c,usuario) != 0){
            adAux = adAux->prox;
        }
        if(adAux != NULL && adAux->peso >= k){ // achei o usuario
            printf(" %s(%d)", aux->c, adAux->peso);
        }
        aux = aux->prox;
    }

    printf("\n");

}

Fila criaFila(){

    return NULL;

}

int vazia(Fila f){

    if(f == NULL) return 1;
    else          return 0;

}

int push(Fila * f, char c[]){

    Fila novo = (Fila) malloc(sizeof(struct fila));
    if(novo == NULL) return 0;

    strcpy(novo->c,c);
    if(vazia(*f)){
        novo->prox = novo;
    }else{
        novo->prox = (*f)->prox;
        (*f)->prox = novo;
    }

    *f = novo;

    return 1;

}

int pop(Fila * f, char c[]){

    if(vazia(*f)) return 0;

    strcpy(c,(*f)->prox->c);
    Fila aux = (*f)->prox;

    if(aux == *f) *f = NULL;
    else          (*f)->prox = aux->prox;

    free(aux);

    return 1;

}

void mostraFila(Fila * f){

    if(vazia(*f)){
        printf("Fila vazia!\n");
        return;
    }

    Fila aux = (*f)->prox;
    printf("Fila:");
    while(aux != (*f)){
        printf(" %s", aux->c);
        aux = aux->prox;
    }

    printf(" %s", (*f)->c);

    printf("\n");

}

void destroyFila(Fila * f){

    if(vazia(*f))
        return;

    Fila aux = (*f)->prox;
    while(aux != (*f)){
        Fila aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }

    free(aux);
    (*f) = NULL;

}

void BuscaLargura(Grafo * g, char raiz[]){

    if(g == NULL) return;

    // verificar se raiz existe no grafo
    Vertice * vAux = g->matriz;
    
    while(vAux != NULL && strcmp(vAux->c, raiz) != 0){
        vAux = vAux->prox;
    }

    if(vAux == NULL) return;

    Fila f;
    f = criaFila();
    char ** visita;
    visita = (char **) malloc(g->nroVertice * sizeof(char *));

    for(int i = 0; i < g->nroVertice; i++){
        visita[i] = (char *) malloc(MAX * sizeof(char));
    }

    for(int i = 0; i < g->nroVertice; i++){
        strcpy(visita[i] ,"#");
    }

    strcpy(visita[0],raiz);
    push(&f, raiz);

    while(!vazia(f)){
        vAux = g->matriz;
        while(vAux != NULL && strcmp(vAux->c,f->prox->c) != 0){
            vAux = vAux->prox;
        }

        Adjacente * adjAux = vAux->adj;
        while(adjAux != NULL){
            int i = 0;
            while(i < g->nroVertice && strcmp(visita[i],"#") != 0 && strcmp(visita[i],adjAux->c) != 0){
                i++;
            }
            if(i < g->nroVertice && strcmp(visita[i],"#") == 0){

                strcpy(visita[i],adjAux->c);
                push(&f,adjAux->c);

            } // vertice não está no vetor
            adjAux = adjAux->prox;
        }
        char p[MAX];
        pop(&f,p);
    }

    printf("Ordem Visitados:\n>");
    for(int i = 0; i < g->nroVertice; i++){
        printf(" %s", visita[i]);
        free(visita[i]);
    }
    printf("\n");
    free(visita);
    destroyFila(&f);

}

Pilha criaPilha(){

    return NULL;

}

int pilhaVazia(Pilha p){

    if (p == NULL) return 1;
    return 0;

}

int inserePilha(Pilha * p, char c[]){

    Pilha novo;
    novo = (Pilha)malloc(sizeof(struct pilha));
    if(novo == NULL)
        return 0;

    strcpy(novo->c,c);
    novo->prox = *p;
    *p = novo;

    return 1;

}

int removePilha(Pilha * p, char c[]){

    if(pilhaVazia(*p)) return 0;

    strcpy(c,(*p)->c);
    Pilha aux = *p;
    *p = aux->prox;
    free(aux);

    return 1;

}

void imprimePilha(Pilha * p){

    if(pilhaVazia(*p))
        printf("Pilha vazia\n");

    Pilha aux = *p;
    while(aux != NULL){
        printf("%s ", aux->c);
        aux = aux->prox;
    }
    printf("\n");

}

void destroyPilha(Pilha * p){

    if(pilhaVazia(*p)) return;

    Pilha aux = *p;
    while(aux != NULL){
        Pilha aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }

}

void BuscaProfundidadeModificada(Grafo * g, char raiz[], int D){

    if (g == NULL) return;

    Pilha p = criaPilha();

    int * visitados;
    visitados = (int *) malloc(g->nroVertice * sizeof(int));
    if(visitados == NULL) return;

    int * dist;
    dist = (int *) malloc(g->nroVertice * sizeof(int));
    if(dist == NULL){
        free(visitados);
        return;
    }

    char ** answer;
    answer = (char **) malloc(g->nroVertice * sizeof(char *));
    if(answer == NULL){
        free(visitados);
        free(dist);
        return;
    }
    for(int i = 0; i < g->nroVertice; i++){
        answer[i] = (char *) malloc(MAX * sizeof(char));
    }

    int a = 0;

    for(int i = 0; i < g->nroVertice; i++){
        dist[i] = -1;
        visitados[i] = 0;
    }

    int pos = procuraVertice(g,raiz);
    dist[pos] = 0;

    inserePilha(&p,raiz);
    while(!pilhaVazia(p)){

        pos = 0;
        Vertice * aux = g->matriz;
        // busco o vértice do topo da pilha
        while(strcmp(aux->c,p->c) != 0){
            aux = aux->prox;
            pos++;
        }
        char c[MAX];
        visitados[pos] = 1;
        strcpy(answer[a],p->c);
        a++;
        removePilha(&p,c);
        Adjacente * adjAux = aux->adj;
        // passo em todos os vértices adjacentes de vértice que está no  topo da pilha
        while(adjAux != NULL){
            int posAdj = 0;
            Vertice * vAux = g->matriz;
            while(strcmp(vAux->c, adjAux->c) != 0){
                vAux = vAux->prox;
                posAdj++;
            }   
            if(!visitados[posAdj]){
                dist[posAdj] = dist[pos]+1;
                visitados[posAdj] = 1;
                if(dist[posAdj] < D)
                    inserePilha(&p,vAux->c);
                else{
                    strcpy(answer[a],vAux->c);
                    a++;
                }
            }else{
                if(dist[posAdj] > dist[pos]+1)
                    dist[posAdj] = dist[pos]+1;
            }

            adjAux = adjAux->prox;
        }

    }

    printf("\nVertices com dist MAX de %d arestas:\n>", D);
    int i;
    for(i = 0; i < a; i++){
        pos = procuraVertice(g,answer[i]);
        if(dist[pos] <= D)
            printf(" %s", answer[i]);
        free(answer[i]);
    }
    while(i < g->nroVertice){
        free(answer[i]);
        i++;
    }

    printf("\n");

    destroyPilha(&p);
    free(answer);
    free(visitados);
    free(dist);

}

int procuraVertice(Grafo * g, char * vertice){

    if(g == NULL) return -1;

    Vertice * aux = g->matriz;
    int pos = 0;
    while(aux != NULL && strcmp(aux->c,vertice) != 0){
        aux = aux->prox;
        pos++;
    }

    if(aux == NULL) // vertice n encontrado
        return -1;

    return pos;

}

int menorDistancia(int v[], int d[],  int n){

    int i, menor = -1, primeiro = 1;
    
    for(i = 0; i < n; i++){
        if(v[i] == 0 && d[i] != -1){
            if(primeiro){
                menor = i;
                primeiro = 0;
            }else{
                if(d[i] < d[menor])
                    menor = i;
            }
        }
    }

    return menor;

}

int menorCaminho(Grafo * g, char * raiz, int anterior[], int n, int * distancia){

    if(g == NULL) return 0;

    int cont = n;
   
    int * visitados = (int *) malloc(n*sizeof(int));
    if(visitados == NULL) return 0;


    for(int i = 0; i < n; i++){
        visitados[i] = 0;
        anterior[i] = -1;
        distancia[i] = -1;
    }

    int pos = procuraVertice(g,raiz);
    if(pos == -1) return 0;

    distancia[pos] = 0;
    int m;
    while(cont > 0){

        m = menorDistancia(visitados,distancia,n);
        if(m == -1)
            break;

        visitados[m] = 1;
        cont--;    
        // Buscar o vértice de menor distancia e ver quem é seu vizinho de menor peso que ainda não foi visitado
        Vertice * aux = g->matriz;
        int flag = m;
        while(flag > 0){   
            aux = aux->prox;
            flag--;
        }

        Adjacente * adjAux = aux->adj;
        int primeiro = 1;
        while(adjAux != NULL){

            pos = procuraVertice(g,adjAux->c);
            if(distancia[pos] < 0){
                distancia[pos] = distancia[m] + adjAux->peso;
                anterior[pos] = m;
            }else{
                if(distancia[pos] > distancia[m] + adjAux->peso){
                    distancia[pos] = distancia[m]+ adjAux->peso;
                    anterior[pos] = m;
                }
            }
            adjAux = adjAux->prox;

        }
    
    }
    /*
    for(int i = 0; i < n; i++){
        printf("%d ", visitados[i]);
    }
    printf("\n");

    for(int i = 0; i < n; i++){
        printf("%d ", distancia[i]);
    }
    printf("\n");

    for(int i = 0; i < n; i++){
        printf("%d ", anterior[i]);
    }
    printf("\n");
    */

    free(visitados);

    if(m == -1)
        return 0;

    return 1;
    
}

int BuscaProfundidade(Grafo * g, char raiz[], int inicializacao[], int finalizacao[], int * cont){

    if(g == NULL) return -1;

    int pos = procuraVertice(g,raiz);

    if(pos == -1){
        printf("Vertice raiz nao esta no grafo.\n");
        return 0;
    }

    int temp = 1;
    inicializacao[pos] = temp;
    temp++;
    Pilha p = criaPilha();
    inserePilha(&p,raiz);

    while(!pilhaVazia(p)){

        char c[MAX];
        pos = procuraVertice(g,p->c);

        Vertice * aux = g->matriz;
        int cont2 = pos;
        while(cont2 > 0){
            aux = aux->prox;
            cont2--;
        }

        //printf("\n%s\n",aux->c);
        Adjacente * adj = aux->adj;
        int ok = 1;
        while(adj != NULL){
            int posADJ = procuraVertice(g,adj->c);
            if(inicializacao[posADJ] == 0){
          //      printf("\n%s\n", adj->c);
                inicializacao[posADJ] = temp;
                temp++;
                inserePilha(&p,adj->c);
                ok = 0;
            }
            adj = adj->prox;
        }
        if(ok){
            finalizacao[pos] = temp;
            temp++;
            removePilha(&p,c);
            (*cont)++;
        }

    }

    destroyPilha(&p);

    if(*cont == g->nroVertice) return 1;
    else                       return 0;

}

Grafo * grafoTransposto(Grafo * g){

    if(g == NULL) return NULL;

    Grafo * gt;
    gt = criaGrafo();
    
    Vertice * aux = g->matriz;
    

    FILE * arq;
    arq = fopen("GTVertice.txt", "w");
    if(arq == NULL){
        printf(">>> Erro ao criar arquivo!\n");
        exit(1);
    }
    
    fclose(arq);
    
    arq = fopen("GTAresta.txt", "w");
    if(arq == NULL){
        printf(">>> Erro ao criar arquivo!\n");
        exit(1);
    }
    
    fclose(arq);

    char ** nomes;
    nomes = (char **) malloc(g->nroVertice * sizeof(char *));
    if(nomes == NULL)
        return NULL;

    for(int i = 0; i < g->nroVertice; i++){
        nomes[i] = (char *) malloc(MAX * sizeof(char));
    }

    int i = 0;
    while(aux != NULL){
        strcpy(nomes[i], aux->c);
        i++;
        //printf("%s\n", aux->c);
        aux = aux->prox;
    }

    for(i = g->nroVertice-1; i >= 0; i--){
        insereVertice(gt,nomes[i],"GTVertice.txt");
        free(nomes[i]);
    }

    free(nomes);

    aux = g->matriz;

    while(aux != NULL){

        Adjacente * adj = aux->adj;
        while(adj != NULL){
            insereAresta(gt,adj->c,aux->c,adj->peso,"GTVertice.txt","GTAresta.txt");
            adj = adj->prox;
        }

        aux = aux->prox;
    }

    
    //infoGrafo(g);
    //printf("\n");
    //infoGrafo(gt);

    return gt;

}

void CFC(Grafo * g, char raiz[]){

    // vetor que irá guardar o tempo em que cada elemento do grafo é encontrado na busca de profundidade

    int * inicializacao;
    inicializacao = (int *) malloc(g->nroVertice * sizeof(int));
    if(inicializacao == NULL){
        return;
    }

    // vetor que irá guardar o tempo de finalização de cada elemento do grafo

    int * finalizacao;
    finalizacao = (int *) malloc(g->nroVertice * sizeof(int));
    if(finalizacao == NULL){
        free(inicializacao);
        return;
    }

    for(int i = 0; i < g->nroVertice; i++){
        inicializacao[i] = 0;
        finalizacao[i] = 0;
    }

    int cont = 0; // mostra quantos elementos foram achados na busca (podemos saber se um grafo é conexo ou nao, pois caso cont < g->nroVertices, entao o grafo é desconexo, nao foi possível acessar todos os elementos do grafo)

    BuscaProfundidade(g,raiz,inicializacao,finalizacao, &cont);

    for(int i = 0; i < g->nroVertice; i++){
        printf("%d ", inicializacao[i]);
    }
    printf("\n");
    for(int i = 0; i < g->nroVertice; i++){
        printf("%d ", finalizacao[i]);
    }
    printf("\n");

    Grafo * gt;
    gt = grafoTransposto(g); // gera o grafo transposto de g

    cont = 0;

    // Vetor para guardar o tempo de finalizacao de GT
    int * tempFinaliz;
    tempFinaliz = (int *) malloc(g->nroVertice * sizeof(int));
    if(tempFinaliz == NULL){
        free(inicializacao);
        free(finalizacao);
        destroyGrafo(gt);
        return;
    }

    for(int i = 0; i < g->nroVertice; i++){
        inicializacao[i] = 0; // reseto minha inicialização para fazer a nova busca com gt
        tempFinaliz[i] = 0;
    }

    int n = 1;
    // irei ficar nesse loop até encontrar as componentes fortemente conexas do grafo
    while(cont < g->nroVertice){

        printf("\nComponente Fortemente Conexa %d:\n>", n);

        // achar o elemento que foi finalizado por ultimo e que ainda não está em nenhuma componente
        int maior = 0;
        for(int i = 1; i < g->nroVertice; i++){
            // finalizacao == -1 é pq ja está em alguma componente
            if(finalizacao[i] != -1 && finalizacao[i] > finalizacao[maior])
                maior = i;
        }

        // buscar o elemento que está na posiçao 'maior'
        Vertice * auxVert = g->matriz;
        while(maior > 0){
            auxVert = auxVert->prox;
            maior--;
        }

 //       printf("%s\n", auxVert->c);

        BuscaProfundidade(gt,auxVert->c,inicializacao, tempFinaliz, &cont);
        for(int i = 0; i < g->nroVertice; i++){
            
            
            // Se for ZERO é pq ainda não passei pelo vertice, se for -1 então ja passei por ele e já está em uma CFC
            if(tempFinaliz[i] != 0 && tempFinaliz[i] != -1){
                
                int auxBusca = i;
                auxVert = g->matriz;
                while(auxBusca > 0){
                    auxVert = auxVert->prox;
                    auxBusca--;
                }
                printf(" %s", auxVert->c);
                tempFinaliz[i] = -1;
                finalizacao[i] = -1;
            }
        }
        printf("\n");
        n++;

    }

    free(inicializacao);
    free(finalizacao);
    free(tempFinaliz);
    destroyGrafo(gt);
    
}