#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

int main(void){

    clock_t time = 0;
    double tempo;
    noArv raiz;
    noArvAVL raizAVL, raizAVLFreq;
    char palavras[TEXTO][MAX], palavra[MAX];
    int frequencia[TEXTO];
    int op = -1, estrutCarregadas = 0;
    while(op != 0){

        system("clear");

        printf("[1].\t Ler primeiro capitulo do livro Harry Potter e a Pedra Filosofal.\n");
        printf("[2].\t Visualizar texto e quantidade de palavras.\n");
        printf("[3].\t Carregar arquivo nas estruturas.\n");
        printf("[4].\t Visualizar frequencia de palavra.\n");
        printf("[5].\t Buscar palavra pela sua frequencia.\n");
        printf("[0].\t Sair.\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);

        system("clear");
        setbuf(stdin,NULL);

        switch(op){

            case 1:
                printf("> Olá, trouxa! (Espero que entenda a referencia)\nSe algum momento quiser sair do modo leitura, basta apertar ENTER.\n\nTenha uma boa leitura!\n\n>> Aperte ENTER.\n");
                
                getchar();

                system("clear");

                printf("Malfeito, feito.\n");
                sleep(2);
                
            break;

            case 2:
                printf("> O texto a seguir ja esta sem caracteres especiais!\n");
                getchar();
                VisualizaTexto();
                getchar();

            break;

            case 3:

                printf("> Pesquisa Binaria\n\n");

                time = clock();
                carregaEstrutPesqBin(palavras, frequencia);
                time = clock() - time;
                double tempo = (double)time/(CLOCKS_PER_SEC);

                printf("> Tempo de execucao em ms: %lf\n", tempo/10);

                int soma = 0;
                for(int i = 0; frequencia[i] != 0; i++){
                    //printf("%d ", frequencia[i]);
                    soma += frequencia[i];
                }
                printf("> Soma frequencias = %d\n", soma);

                printf("\n> Palavras do texto ordenadas:\n\n");

                for(int i = 0; strcmp(palavras[i],"#X#") != 0; i++){
                    printf("%s ", palavras[i]);
                }    
                printf("\n");
                
                printf("\n=======================================================================================================================================================================\n");

                printf("\n> Arvore Binaria\n");
                time = 0;
                time = clock();
                raiz = carregaEstrutArvBin();
                time = clock() - time;
                tempo = (double)time/(CLOCKS_PER_SEC);

                printf("\n> Tempo de execucao em ms: %lf\n", tempo/10);

                printf("\n(No)  |  (Esq)  |  (Dir)\n");
                imprimeArv(&raiz);

                printf("\n=======================================================================================================================================================================\n");

                printf("\n> Arvore AVL\n");
                time = 0;
                time = clock();
                raizAVL = carregaArvAVL();
                time = clock() - time;
                tempo = (double)time/(CLOCKS_PER_SEC);
                
                printf("\n> Tempo de execucao em ms: %lf\n", tempo/10);

                printf("\n(No)  |  (Esq)  |  (Dir)\n");
                emOrdem_ArvAVL(&raizAVL);
                
                estrutCarregadas = 1;
                getchar();

            break;

            case 4:
                if (estrutCarregadas){
                    VisualizaTexto();
                    printf("\n> Digite a palavra que deseja verificar a frequencia: ");
                    scanf("%s", palavra);

                    time = 0;
                    time = clock();
                    int cf = contaFrequencia(palavras,frequencia,palavra);
                    time = clock()-time;

                    tempo = (double)time/(CLOCKS_PER_SEC);

                    if(cf == -1)
                        printf("\n> A palavra %s aparece 0 vez(es).\n", palavra);
                    else
                        printf("\n> A palavra %s aparece %d vez(es).\n", palavra,cf);
                        
                    printf("\n(BuscaBin Vetor)> Tempo para executar a busca em ms: %lf.\n", tempo/10);

                    time = 0;
                    time = clock();
                    BuscaArv(&raiz,palavra);
                    time = clock() - time;

                    tempo = (double)time/(CLOCKS_PER_SEC);
                    printf("(BuscaArv Binaria)> Tempo para executar a busca em ms: %lf.\n", tempo/10);
                    
                    time = 0;
                    time = clock();
                    BuscaAVL(&raizAVL,palavra);
                    time = clock() - time;

                    tempo = (double)time/(CLOCKS_PER_SEC);
                    printf("(BuscaAVL)> Tempo para executar a busca em ms: %lf.\n", tempo/10);

                    setbuf(stdin,NULL);
                    getchar();

                }else{
                    printf("> Carregue as estruturas primeiro. (Opcao 3)\n");
                    getchar();
                }

            break;

            case 5:
            
                printf("Digite a frequencia da palavra que deseja buscar: ");
                int freq;
                scanf("%d", &freq);
                system("clear");
                printf("> Arvore AVL Frequencia\n");

                raizAVLFreq = BuscaAVLFreq(freq);
                
                time = 0;
                time = clock();
                BuscaAVLFreq2(&raizAVLFreq,freq);
                time = clock() - time;
                tempo = (double)time/(CLOCKS_PER_SEC);
                printf("\n> Tempo de execucao em ms: %lf\n", tempo/10);

                setbuf(stdin,NULL);
                //printf("\n(No)  |  (Esq)  |  (Dir)\n");
                //emOrdem_ArvAVL(&raizAVLFreq);
                getchar();

            break;

            case 0:
                apagaArv(&raiz);
                apagaArvAVL(&raizAVL);
                apagaArvAVL(&raizAVLFreq);
                printf("> Ate mais!\n");

            break;

            default:
                setbuf(stdin,NULL);
                printf("> Opcao invalida! Aperte ENTER.\n");
                getchar();

            break;

        }

    }

}