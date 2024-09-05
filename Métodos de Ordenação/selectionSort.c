// Inclusão de bibliotecas padrão necessárias para funções de entrada/saída, alocação de memória e manipulação de tempo
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para trocar dois elementos de lugar usando ponteiros
void troca(int *xp, int *yp) {
    int temp = *xp;  // Guarda temporariamente o valor do primeiro elemento
    *xp = *yp;       // Atribui o valor do segundo elemento ao primeiro
    *yp = temp;      // Atribui o valor temporário (original do primeiro) ao segundo
}

// Função que implementa o algoritmo Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    // Loop externo que move a fronteira do subarray não ordenado
    for (i = 0; i < n-1; i++) {
        min_idx = i; // Assume que o primeiro elemento é o menor
        // Loop interno para encontrar o menor elemento no subarray não ordenado
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j; // Atualiza o índice do menor elemento encontrado

        // Troca o menor elemento encontrado com o primeiro elemento do subarray
        troca(&arr[min_idx], &arr[i]);
    }
}

// Função principal que executa o programa
int main() {
    int n = 1000; // Define o número de elementos no array
    int data[n];  // Declara um array de 1000 elementos
    
    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    // Preenche o array com números aleatórios entre 0 e 999
    for (int i = 0; i < n; i++) {
        data[i] = rand() % 1000;
    }

    // Imprime o array original
    printf("Array original: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    // Marca o tempo inicial
    clock_t start = clock();

    // Ordena o array usando o Selection Sort
    selectionSort(data, n);

    // Marca o tempo final
    clock_t end = clock();

    // Imprime o array ordenado
    printf("Array ordenado: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    // Calcula o tempo de execução em milissegundos
    double cpu_time_used = ((double) (end - start)) * 1000 / CLOCKS_PER_SEC;
    printf("\nTempo de execução: %f milissegundos\n", cpu_time_used);

    return 0;
}
