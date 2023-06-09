void gerarCrescente(int tam);
void insert(int tamanho, double *vetor);
void bubbleSort(int tamanho, double *vetor);
int lerArquivo(char *nome_arquivo, double *numeros, int TAMANHO_MAXIMO);
void gerarDecrescente(int tam);
void printaMenu();
void printaMenu2();
void gerarAleatorio(int tam, int max);
void selectionSort(int tamanho, double *vetor);
void shellSort(int tamanho, double *vetor);
void quicksort(double *vetor, int inicio, int fim);
void quickSortHoare(double *vetor, int tam);
int partitionHoare(double *vetor, int tam);
void hoare(double *vetor, int tam);
int partitionLomuto(double arr[], int low, int high);
void lomuto(double arr[], int low, int high);
double quickSortLomuto(double *vetor, int low, int tam);
void merge(double *v, double *c, int i, int m, int f);
void sort(double *v, double *c, int i, int f);
void mergesort(double *vetor, int esq, int dir);
void radixSort(double *vetor, int tam);
void heap_sort(double *vetor, int tam);
void heapify_down(double *vetor, int i, int tamanho);
int buscaBinaria(double *vetor, int ini, int fim, double key, int *operacoes);
int buscaSequencial(double vetor[], int tamanho, int valor, int *operacoes);