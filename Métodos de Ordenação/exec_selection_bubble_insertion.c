#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Comparação entre os métodos apresentados até o momento.

// Função para trocar dois elementos de lugar
void troca(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Função que implementa o algoritmo Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j;
    int trocou;

    // Loop para passar por todo o array
    for (i = 0; i < n-1; i++) {
        trocou = 0;
        // A cada iteração completa do loop externo, o i-ésimo maior elemento é colocado na posição correta ao final do array,
        // então as comparações subsequentes podem ignorar essa parte já ordenada do array.
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                troca(&arr[j], &arr[j+1]);
                trocou = 1; // Marca que uma troca foi realizada
            }
        }

        // Se não houve nenhuma troca, o array já está ordenado
        if (trocou == 0)
            break;
    }
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
    int n = 200000; // Número de elementos
    int data[n];

    // Inicializa o gerador de números randômicos
    srand(time(NULL));

    // Gera dados aleatórios
    for (int i = 0; i < n; i++) {
        if (i % 100 == 0) {
            data[i] = rand() % 2; // Apenas 1 em cada 100 valores está fora de ordem
        } else {
            data[i] = i; // Coloca o número em ordem
        }
    }


    // Ordena o array usando o Bubble Sort
    clock_t start = clock();
    bubbleSort(data, n);
    clock_t end = clock();
    
    
    // Ordena o array usando o Selection Sort
    clock_t start_selection = clock();
    selectionSort(data, n);
    clock_t end_selection = clock();
    
    // Ordena o array usando o Insertion Sort
    clock_t start_insertion = clock();
    insertionSort(data, n);
    clock_t end_insertion = clock();


    // Calcula o tempo de execução em milissegundos
    double cpu_time_used = ((double) (end - start)) * 1000 / CLOCKS_PER_SEC;
    printf("\n Tempo de execução Bubble Sort: %f milissegundos\n", cpu_time_used);
    
    double cpu_time_used_selection = ((double) (end_selection - start_selection)) * 1000 / CLOCKS_PER_SEC;
    printf("\n Tempo de execução Selection Sort: %f milissegundos\n", cpu_time_used_selection);
    
    double cpu_time_used_insertion = ((double) (end_insertion - start_insertion)) * 1000 / CLOCKS_PER_SEC;
    printf("\n Tempo de execução Insertion Sort: %f milissegundos\n", cpu_time_used_insertion);

    return 0;
}
