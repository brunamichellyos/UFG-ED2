#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000  // Defina o valor de N conforme necessário.
#define RANGE 10000  // Valor máximo para os números no array.

// Função auxiliar para obter o maior número no array.
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

// Função para realizar a ordenação pelo dígito atual (Counting Sort para cada dígito).
void countingSort(int arr[], int n, int exp) {
    int output[n]; // Array temporário de saída.
    int count[10] = {0}; // Array de contagem.

    // Conta as ocorrências de cada dígito.
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Modifica count[] para que ele contenha a posição correta dos dígitos.
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Constrói o array de saída.
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copia o array de saída para arr[], de modo que arr[] agora esteja ordenado.
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Função principal do Radix Sort.
void radixSort(int arr[], int n) {
    // Encontra o maior número para saber o número de dígitos.
    int max = getMax(arr, n);

    // Aplica Counting Sort para cada dígito. Note que exp é 10^i, onde i é o dígito atual.
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

void geraEntradasDesordenadas(int arr[], int n) {
    // Função que gera N números desordenados aleatoriamente.
    srand(time(0)); // Inicializa a semente do gerador de números aleatórios.
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % RANGE; // Gera números entre 0 e RANGE.
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
    radixSort(arr, N); // Chama a função Radix Sort.
    clock_t fim = clock();

    //printf("Vetor após a ordenação:\n");
    //imprimeVetor(arr, N); // Comente esta linha para vetores grandes.

    // Calcula o tempo de execução em milissegundos.
    double tempo_execucao = (double)(fim - inicio) * 1000 / CLOCKS_PER_SEC;
    printf("Tempo de execução para %d entradas: %.3f milissegundos\n", N, tempo_execucao);

    return 0;
}
