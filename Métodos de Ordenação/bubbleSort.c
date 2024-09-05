#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    bubbleSort(data, n);
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
