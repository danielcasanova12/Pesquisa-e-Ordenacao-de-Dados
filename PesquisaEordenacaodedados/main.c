#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
  clock_t inicio, fim;
  double tempo;
  int tam;
  int opcaoAlgoritmo, op, tipoArquivo;
  char nomeArquivo[80], nomeAlgoritimo[80];

  int quantidade_numeros = 0;
  printaMenu();
  scanf("%d", &tipoArquivo);
  printf("Digite o tamanho do arquivo: ");
  printf("\n1 para 500000\n2 para 750000\n3 para 1000000\n");
  scanf("%d", &op);

  switch (op) {
  case 1:
    tam = 500000;
    break;
  case 2:
    tam = 750000;
    break;
  default:
    tam = 1000000;
    break;
  }

  double *numeros = malloc(tam * sizeof(double));

  switch (tipoArquivo) {
  case 1:
    gerarCrescente(tam);
    sprintf(nomeArquivo, "arquivos/crescente%d.txt", tam);
    break;
  case 2:
    gerarDecrescente(tam);
    sprintf(nomeArquivo, "arquivos/decrescente%d.txt", tam);
    break;
  case 3:
    sprintf(nomeArquivo, "arquivos/randomico%d.txt", tam);
    gerarAleatorio(tam, tam);
    break;

  default:
    printf("Opcao invalida.\n");
    break;
  }

  if (lerArquivo(nomeArquivo, numeros, tam) != 0) {
    printf("Erro ao ler o arquivo.\n");
    return 1;
  }

  printaMenu2();
  scanf("%d", &opcaoAlgoritmo);

  switch (opcaoAlgoritmo) {
  case 1:
    inicio = clock();
    bubbleSort(tam, numeros);
    fim = clock();
    sprintf(nomeAlgoritimo, "Bubllesort");
    break;
  case 2:
    inicio = clock();
    insert(tam, numeros);
    fim = clock();
    sprintf(nomeAlgoritimo, "Insert");
    break;
  case 3:
    inicio = clock();
    selectionSort(tam, numeros);
    fim = clock();
    sprintf(nomeAlgoritimo, "SelectionSort");
    break;
  case 4:
    inicio = clock();
    shellSort(tam, numeros);
    fim = clock();
    sprintf(nomeAlgoritimo, "ShellSort");
    break;
  case 5:
    inicio = clock();
    quickSortHoare(numeros, tam);
    fim = clock();
    sprintf(nomeAlgoritimo, "Quick Sort Hoare");
    break;
  case 6:
    inicio = clock();
    quickSortLomuto(numeros, 0, tam - 1);
    fim = clock();
    sprintf(nomeAlgoritimo, "Quick Sort Lomuto");
    break;
  case 7:
    inicio = clock();
    mergesort(numeros, 0, tam);
    fim = clock();
    sprintf(nomeAlgoritimo, "Merge Sort");
    break;
  case 8:
    inicio = clock();
    radixSort(numeros, tam);
    fim = clock();
    sprintf(nomeAlgoritimo, "Radix Sort");
    break;
  case 9:
    inicio = clock();
    heap_sort(numeros, tam);
    fim = clock();
    sprintf(nomeAlgoritimo, "heap_sort");
    break;

  default:
    printf("Opcao invalida.\n");
    break;
  }
  system("clear");
  printf("\n\nNumeros ordenados \n");
  for (int i = 0; i < 20; i++) {
    printf("%.0f \n", numeros[i]);
  }
  tempo = (double)(fim - inicio) / CLOCKS_PER_SEC; // Calcula o tempo em
  printf("Tempo de execucao: %f segundos\n", tempo);

  FILE *arquivo_resultados = fopen("resultados.txt", "a");
  if (arquivo_resultados == NULL) {
    printf("Erro ao abrir o arquivo resultados.txt\n");
    // return 1;
  }
  fprintf(arquivo_resultados,
          "Tempo de execucao do arquivo %s usando o algoritimo %s: %f segundos "
          "topo arquiv:%d\n",
          nomeArquivo, nomeAlgoritimo, tempo, tipoArquivo);
  fclose(arquivo_resultados);
  int valor;
  printf("qual valor deseja procurar?");
  scanf("%d", &valor);
  int operacoes = 0;
  inicio = clock();
  buscaSequencial(numeros, tam - 1, valor, &operacoes);
  printf("\n\nforam usadas %d operaçoes para achar pelo sequencial", operacoes);
  tempo = (double)(clock() - inicio) / CLOCKS_PER_SEC; // Calcula o tempo em
  printf("\nTempo de pesquisa: %f segundos\n\n\n\n\n", tempo);
  operacoes = 0;
  inicio = clock();
  buscaBinaria(numeros, 0, tam - 1, valor, &operacoes);

  printf("\n\nforam usadas %d operaçoes para achar", operacoes);
  tempo = (double)(clock() - inicio) / CLOCKS_PER_SEC; // Calcula o tempo em
  printf("\nTempo de pesquisa: %f segundos\n", tempo);
}