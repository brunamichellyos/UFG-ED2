#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1200  // Defina o valor de N conforme necessário.

void merge(int arr[], int left, int mid, int right) {
    // Calcula os tamanhos dos dois sub-arrays que serão mesclados.
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Cria arrays temporários.
    int L[n1], R[n2];

    // Copia os dados para os arrays temporários.
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    // Mescla os arrays temporários de volta no array original.
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de L[], se houver.
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R[], se houver.
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Calcula o ponto médio do array.
        int mid = left + (right - left) / 2;

        // Ordena recursivamente as duas metades.
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Mescla as duas metades ordenadas.
        merge(arr, left, mid, right);
    }
}

void geraEntradasDesordenadas(int arr[], int n) {
    // Função que gera N números desordenados aleatoriamente.
    srand(time(0)); // Inicializa a semente do gerador de números aleatórios.
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000; // Gera números entre 0 e 9999.
    }
}

void geraEntradasQuaseOrdenadas(int arr[], int n, int variacao){
     // Função que gera N números quase ordenados aleatoriamente.
    srand(time(0)); // Inicializa a semente do gerador de números aleatórios.
   
    // Gera um array quase ordenado.
    for (int i = 0; i < n; i++) {
        if (i % variacao == 0) {
            arr[i] = rand() % 2; // Apenas 1 em cada X valores está fora de ordem onde X = variacao
        } else {
            arr[i] = i; // Coloca o número em ordem.
        }
    }
}

void imprimeVetor(int arr[], int n) {
    // Função simples para imprimir o vetor.
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[N]; // Cria um vetor de tamanho N.

    //geraEntradasDesordenadas(arr, N); // Gera as entradas desordenadas.
    
    geraEntradasQuaseOrdenadas(arr, N, 10);
    
    //printf("Vetor antes da ordenação:\n");
    //imprimeVetor(arr, N); // Comente esta linha para vetores grandes.

    // Inicia a medição do tempo.
    clock_t inicio = clock();
    mergeSort(arr, 0, N - 1); // Chama a função Merge Sort.
    clock_t fim = clock();

    //printf("Vetor após a ordenação:\n");
    //imprimeVetor(arr, N); // Comente esta linha para vetores grandes.

    // Calcula o tempo de execução em milissegundos.
    double tempo_execucao = (double)(fim - inicio) * 1000 / CLOCKS_PER_SEC;
    printf("Tempo de execução para %d entradas: %.3f milissegundos\n", N, tempo_execucao);

    return 0;
}
