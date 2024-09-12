# 📊 Métodos de Ordenação 📊 

Este repositório contém implementações de diversos algoritmos de ordenação em C, utilizados para organizar conjuntos de dados. O objetivo deste repositório é fornecer exemplos de diferentes métodos de ordenação e facilitar a análise de seu desempenho, tanto individualmente quanto em conjunto.

## Arquivos Disponíveis

- **bubbleSort.c**: Implementação do algoritmo **Bubble Sort**.
- **bucketSort.c**: Implementação do algoritmo **Bucket Sort**.
- **insertionSort.c**: Implementação do algoritmo **Insertion Sort**.
- **mergeSort.c**: Implementação do algoritmo **Merge Sort**.
- **quickSort.c**: Implementação do algoritmo **Quick Sort**.
- **radixSort.c**: Implementação do algoritmo **Radix Sort**.
- **selectionSort.c**: Implementação do algoritmo **Selection Sort**.
- **exec_selection_bubble_insertion.c**: Combinação dos algoritmos **Selection Sort**, **Bubble Sort** e **Insertion Sort** para facilitar a comparação dos tempos de execução.

---

## Descrição dos Algoritmos

### 1. **Bubble Sort** 🫧 
- **Descrição**: Um algoritmo simples de ordenação que percorre repetidamente a lista, comparando elementos adjacentes e trocando-os se estiverem na ordem errada.
- **Aplicação**: Utilizado para listas pequenas ou já quase ordenadas, devido à sua baixa eficiência em grandes conjuntos de dados. É fácil de implementar, mas geralmente ineficaz para grandes volumes.
- **Complexidade**: \(O(n^2)\).

### 2. **Selection Sort** 🔍
- **Descrição**: O algoritmo seleciona o menor (ou maior) elemento do array e o coloca na posição correta, repetindo o processo para todos os elementos.
- **Aplicação**: Funciona bem para conjuntos pequenos de dados. Não é recomendado para grandes volumes, mas é útil quando o número de trocas precisa ser minimizado.
- **Complexidade**: \(O(n^2)\).

### 3. **Insertion Sort** 📝 
- **Descrição**: Construído como se estivéssemos ordenando cartas em um baralho. Percorre o array e insere cada elemento na posição correta em uma sublista previamente ordenada.
- **Aplicação**: Bom para conjuntos de dados pequenos ou já parcialmente ordenados. É eficiente quando o array é quase ordenado.
- **Complexidade**: \(O(n^2)\) no pior caso, mas \(O(n)\) no melhor caso (quase ordenado).

### 4. **Merge Sort**  🔀
- **Descrição**: Um algoritmo de ordenação baseado na técnica de divisão e conquista. Divide o array em dois subarrays, ordena-os e, em seguida, os mescla.
- **Aplicação**: Ideal para ordenar grandes quantidades de dados, pois tem complexidade \(O(n log n)\), independentemente da ordenação inicial.
- **Complexidade**: \(O(n log n)\).

### 5. **Quick Sort** ⚡
- **Descrição**: Outro algoritmo de divisão e conquista. Escolhe um pivô, particiona o array em dois subarrays em torno do pivô e, então, ordena os subarrays.
- **Aplicação**: Amplamente utilizado devido à sua eficiência em tempo médio. Funciona bem na maioria dos casos, mas pode ser ineficiente no pior cenário (por exemplo, arrays já ordenados).
- **Complexidade**: \(O(n log n)\) no caso médio, \(O(n^2)\) no pior caso.

### 6. **Radix Sort** 🔢
- **Descrição**: Ordena números inteiros ao processar seus dígitos um de cada vez, da unidade até o dígito mais significativo. Utiliza uma ordenação estável, como o Counting Sort, para organizar os elementos com base em cada dígito.
- **Aplicação**: Funciona bem com números inteiros de tamanho fixo e é eficiente quando o intervalo de valores é conhecido.
- **Complexidade**: \(O(d (n + k))\), onde \(d\) é o número de dígitos e \(k\) é o intervalo de valores dos dígitos.

### 7. **Bucket Sort** 🪣 
- **Descrição**: Divide o array em "baldes" ou buckets, cada um contendo um intervalo de valores, e em seguida, ordena cada bucket individualmente com outro algoritmo de ordenação, como o Insertion Sort.
- **Aplicação**: Ideal para dados que são distribuídos de forma uniforme e quando se deseja uma ordenação linear no melhor caso.
- **Complexidade**: \(O(n)\) no melhor caso, \(O(n^2)\) no pior caso (se os dados não forem distribuídos uniformemente).

### 8. **Exec Selection, Bubble e Insertion** ⚙️
- **Descrição**: Este arquivo contém uma combinação dos algoritmos **Selection Sort**, **Bubble Sort** e **Insertion Sort**, permitindo a análise comparativa do desempenho de cada algoritmo em um único teste.
- **Aplicação**: Útil para comparar a eficiência dos três algoritmos em diferentes conjuntos de dados. 

---

## Como Usar

1. Clone o repositório para a sua máquina local.
2. Compile e execute os arquivos `.c` individualmente para testar cada algoritmo separadamente.
3. O arquivo `exec_selection_bubble_insertion.c` pode ser executado para visualizar uma comparação direta entre os três algoritmos (**Selection Sort**, **Bubble Sort** e **Insertion Sort**).

```bash
gcc nome_do_arquivo.c -o nome_do_arquivo
./nome_do_arquivo
