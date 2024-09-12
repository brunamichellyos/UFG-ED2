#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000  // Defina o valor de N conforme necessário.
#define BUCKETS 10  // Defina o número de buckets.

void insertionSort(int arr[], int n) {
    // Função auxiliar de ordenação por Inserção usada dentro de cada bucket.
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bucketSort(int arr[], int n) {
    // Cria buckets (listas) vazios.
    int buckets[BUCKETS][N];
    int bucketCount[BUCKETS];

    // Inicializa o contador de elementos em cada bucket.
    for (int i = 0; i < BUCKETS; i++) {
        bucketCount[i] = 0;
    }

    // Encontra o valor máximo no array para normalizar os dados.
    int max_value = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
    }

    // Distribui os elementos nos buckets com base no valor.
    for (int i = 0; i < n; i++) {
        int bucketIndex = (arr[i] * BUCKETS) / (max_value + 1);
        buckets[bucketIndex][bucketCount[bucketIndex]++] = arr[i];
    }

    // Ordena cada bucket individualmente usando Insertion Sort.
    for (int i = 0; i < BUCKETS; i++) {
        if (bucketCount[i] > 0) {
            insertionSort(buckets[i], bucketCount[i]);
        }
    }

    // Junta os elementos ordenados de todos os buckets de volta no array original.
    int index = 0;
    for (int i = 0; i < BUCKETS; i++) {
        for (int j = 0; j < bucketCount[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

void geraEntradasDesordenadas(int arr[], int n) {
    // Função que gera N números desordenados aleatoriamente.
    srand(time(0)); // Inicializa a semente do gerador de números aleatórios.
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000; // Gera números entre 0 e 9999.
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

    geraEntradasDesordenadas(arr, N); // Gera as entradas desordenadas.
    
    //printf("Vetor antes da ordenação:\n");
    //imprimeVetor(arr, N); // Comente esta linha para vetores grandes.

    // Inicia a medição do tempo.
    clock_t inicio = clock();
    bucketSort(arr, N); // Chama a função Bucket Sort.
    clock_t fim = clock();

    //printf("Vetor após a ordenação:\n");
    //imprimeVetor(arr, N); // Comente esta linha para vetores grandes.

    // Calcula o tempo de execução em milissegundos.
    double tempo_execucao = (double)(fim - inicio) * 1000 / CLOCKS_PER_SEC;
    printf("Tempo de execução para %d entradas: %.3f milissegundos\n", N, tempo_execucao);

    return 0;
}
