#include "main.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void menu() {

  system("clear");
  printf("1.\t Informacoes grafo.\n");
  printf("2.\t Inserir novo vertice.\n");
  printf("3.\t Inserir nova aresta.\n");
  printf("4.\t Iteracoes com um usuario (Letra C)\n");
  printf("5.\t Busca em Largura.\n");
  printf("6.\t Menor caminho entre dois usuarios.\n");
  printf("7.\t Busca em Profundidade modificada (Letra B).\n");
  printf("8.\t Componentes fortemente conexas.\n");
  printf("0.\t Sair.\n");
  printf("Opcao: ");
}

int main(void) {

  system("clear");

  Grafo *g;
  char nome[50];

  int *anterior;
  int *distancia;
  int ok;

  g = start();

  printf("Um grafo já foi criado!\n Aperte ENTER para continuar.");
  getchar();

  int op = -1;
  while (op != 0) {

    menu();
    scanf("%d", &op);

    system("clear");

    switch (op) {

    case 0:

      destroyGrafo(g);
      printf("Grafo sendo destruído. Aguarde...\n");
      setbuf(stdin, NULL);
      sleep(2);
      printf("Grafo destruido com sucesso! Até!\n");
      setbuf(stdin, NULL);
      sleep(3);
      system("clear");

      break;

    case 1:
      infoGrafo(g);

      break;

    case 2:
      printf("** O NOME DO VÉRTICE NAO PODE CONTER ESPACOS E NEM SER DE "
             "TAMANHO ZERO **\n");
      printf("Digite o nome do vértice: ");
      setbuf(stdin, NULL);
      scanf("%[^\n]", nome);
      if (insereVertice(g, nome, "vertices.txt") == 0)
        printf("Falha ao inserir vertice!\n");
      else
        printf("Vertice inserido com sucesso!\n");

      break;

    case 3:
      printf("** O NOME DO VÉRTICE NAO PODE CONTER ESPACOS E NEM SER DE "
             "TAMANHO ZERO **\n");
      printf("Digite o nome do vértice origem: ");
      char nome1[50];
      setbuf(stdin, NULL);
      scanf("%[^\n]", nome1);
      printf("Digite o nome do vértice destino: ");
      char nome2[50];
      setbuf(stdin, NULL);
      scanf("%[^\n]", nome2);
      printf("Digite o peso da aresta: ");
      int p;
      scanf("%d", &p);
      if (insereAresta(g, nome1, nome2, p, "vertices.txt", "arestas.txt") ==
          0) {
        printf("Erro ao tentar inserir aresta!\n");
      } else {
        printf("Aresta inserida com sucesso!\n");
      }

      break;

    case 4:
      printf("Digite o nome do usuario que deseja verificar: ");
      setbuf(stdin, NULL);
      scanf("%[^\n]", nome);
      printf("Digite o numero minimo de iteracoes: ");
      int k;
      scanf("%d", &k);
      system("clear");
      letterC(g, nome, k);

      break;

    case 5:
      printf("Digite o nome do usuario para ser vertice raiz: ");
      setbuf(stdin, NULL);
      scanf("%[^\n]", nome);
      system("clear");
      BuscaLargura(g, nome);

      break;

    case 6:
      ok = 1;
      anterior = (int *)malloc(g->nroVertice * sizeof(int));
      distancia = (int *)malloc(g->nroVertice * sizeof(int));
      printf("Digite o nome do primeiro usuario: ");
      setbuf(stdin, NULL);
      scanf("%[^\n]", nome1);
      int vnome1 = procuraVertice(g, nome1);
      int vnome2;
      if (vnome1 == -1) {
        printf("Nome inválido!\n");
        ok = 0;
      } else {
        printf("Digite o nome do segundo usuario: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]", nome2);
        vnome2 = procuraVertice(g, nome2);
        if (vnome2 == -1) {
          printf("Nome inválido!\n");
          ok = 0;
        }
      }
      if (ok) {

        int r = menorCaminho(g, nome1, anterior, g->nroVertice, distancia);

        if (!r)
          printf("Grafo desconexo!\n");

        else {
          char **pessoas;
          pessoas = (char **)malloc(g->nroVertice * sizeof(char *));
          for (int k = 0; k < g->nroVertice; k++)
            pessoas[k] = (char *)malloc(MAX * sizeof(char));

          Vertice *aux = g->matriz;
          int i = 0;
          while (aux != NULL) {
            strcpy(pessoas[i], aux->c);
            i++;
            aux = aux->prox;
          }

          int *ordem;
          ordem = (int *)malloc(g->nroVertice * sizeof(ordem));

          int pos = vnome2;
          i = 0;
          while (pos != vnome1) {

            ordem[i] = pos;
            i++;
            pos = anterior[pos];
          }
          ordem[i] = vnome1;

          pos = i;
          printf("\nCaminho minimo entre %s e %s:\n\n >", nome1, nome2);
          while (ordem[pos] != vnome2) {

            printf(" %s", pessoas[ordem[pos]]);
            pos--;
          }

          printf(" %s\n", pessoas[ordem[pos]]);

          free(ordem);

          for (int k = 0; k < g->nroVertice; k++)
            free(pessoas[k]);

          free(pessoas);
        }
      }

      free(anterior);
      free(distancia);

      break;

    case 7:
      printf("Digite o nome pelo vértice no qual deseja iniciar: ");
      setbuf(stdin, NULL);
      scanf("%[^\n]", nome);
      vnome1 = procuraVertice(g, nome);
      printf("Digite a distancia max: ");
      int dist;
      scanf("%d", &dist);
      if (vnome1 == -1)
        printf("Nome invalido.\n");
      else
        BuscaProfundidadeModificada(g, nome, dist);
      break;

    case 8:
      printf("Digite o nome pelo vértice no qual deseja iniciar: ");
      setbuf(stdin, NULL);
      scanf("%[^\n]", nome);
      vnome1 = procuraVertice(g, nome);
      if (vnome1 == -1)
        printf("Nome invalido.\n");
      else
        CFC(g, nome);

      break;

    default:
      printf("Opcao invalida!\n");
    }

    if (!op == 0) {
      printf("Aperte ENTER para continuar.");
      setbuf(stdin, NULL);
      getchar();
    }
  }
}