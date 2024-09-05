#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função que implementa o algoritmo Insertion Sort
void insertionSort(int arr[], int n) {
    int i, j, chave;

    // Percorre cada elemento do array (exceto o primeiro, considerado já ordenado)
    for (i = 1; i < n; i++) {
        chave = arr[i]; // O elemento atual a ser inserido na parte ordenada do array
        j = i - 1;

        // Desloca os elementos da parte ordenada que são maiores que a chave
        // uma posição à frente de sua posição atual
        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = chave; // Insere a chave na posição correta na parte ordenada
    }
}

// Função principal que executa o programa
int main() {
    int n = 1000; // Número de elementos
    int data[n];

    // Inicializa o gerador de números randômicos
    srand(time(NULL));

    // Gera dados aleatórios
    for (int i = 0; i < n; i++) {
        data[i] = rand() % 1000; // Números aleatórios entre 0 e 999
    }

    printf("Array original: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    clock_t start = clock();
    insertionSort(data, n);
    clock_t end = clock();

    printf("Array ordenado: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    // Calcula o tempo de execução em milissegundos
    double cpu_time_used = ((double) (end - start)) * 1000 / CLOCKS_PER_SEC;
    printf("\n Tempo de execução: %f milissegundos\n", cpu_time_used);

    return 0;
}
