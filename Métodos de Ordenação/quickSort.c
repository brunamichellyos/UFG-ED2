#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000  // Defina o valor de N 

void troca(int *a, int *b) {
    // Função simples para trocar dois elementos.
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particiona(int arr[], int low, int high) {
    // Função que particiona o vetor em torno do pivô.
    int pivot = arr[high]; // Pivô escolhido como o último elemento.
    int i = (low - 1); // Índice do menor elemento.

    for (int j = low; j < high; j++) {
        // Se o elemento atual é menor ou igual ao pivô.
        if (arr[j] <= pivot) {
            i++; // Incrementa o índice do menor elemento.
            troca(&arr[i], &arr[j]); // Trocamos arr[i] com arr[j].
        }
    }
    troca(&arr[i + 1], &arr[high]); // Coloca o pivô na posição correta.
    return (i + 1); // Retorna o índice onde o pivô foi colocado.
}

void quickSort(int arr[], int low, int high) {
    // Função principal do Quick Sort que é chamada recursivamente.
    if (low < high) {
        // Particiona o vetor e encontra o pivô.
        int pi = particiona(arr, low, high);

        // Ordena recursivamente os sub-vetores antes e depois do pivô.
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
    srand(time(0)); // Inicializa a semente do gerador de números aleatórios.
    for (int i = 0; i < n; i++) {
        if (i % variacao == 0) {
            arr[i] = rand() % 2; // Apenas 1 em cada 10 valores está fora de ordem = variacao = 10
        } else {
            arr[i] = i; // Coloca o número em ordem
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

    geraEntradasDesordenadas(arr, N); // Gera as entradas desordenadas.
    
    //geraEntradasQuaseOrdenadas(arr, N, 10); // Gera as entradas ordenadas com base em uma variação ( 1 a cada X valores está desordenado)
    
    //printf("Vetor antes da ordenação:\n");
    //imprimeVetor(arr, N); // Comente esta linha para vetores grandes.

    // Inicia a medição do tempo.
    clock_t inicio = clock();
    quickSort(arr, 0, N - 1); // Chama a função Quick Sort.
    clock_t fim = clock();

    //printf("Vetor após a ordenação:\n");
    //imprimeVetor(arr, N); // Comente esta linha para vetores grandes.

    // Calcula o tempo de execução em milissegundos.
    double tempo_execucao = (double)(fim - inicio) * 1000 / CLOCKS_PER_SEC;
    printf("Tempo de execução para %d entradas: %.3f milissegundos\n", N, tempo_execucao);

    return 0;
}
