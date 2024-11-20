# Atividade Prática: Balanceamento Dinâmico de Dados de Clientes

## Descrição da Atividade

Nesta atividade, vamos implementar e explorar uma árvore AVL para gerenciar dados de clientes em um sistema. 
A árvore AVL é uma estrutura de dados balanceada que permite operações eficientes de inserção, remoção e busca, sendo utilizada em aplicações que requerem rápidas operações de busca e organização de dados.

**Cenário:** Uma equipe de desenvolvedores em uma empresa que está criando um sistema para gerenciar dados de clientes. Cada grupo será responsável por simular o cadastro e atualização de clientes em uma árvore AVL, onde cada cliente tem um número de identificação (ID).

Os objetivos da atividade são:

Inserir novos clientes (nós) e manter o balanceamento.
Remover clientes específicos e reajustar o balanceamento.
Realizar consultas de clientes pela ID, mostrando como a árvore se reorganiza.

- **Implementar** as operações básicas de uma árvore AVL (remoção e consulta).
  - **Remover** clientes específicos e reajustar o balanceamento.
  - **Realizar consultas** de clientes pelo ID, mostrando como a árvore se reorganiza, a fim de simular um sistema de gerenciamento de clientes.

## Estrutura do Código

O código inicial fornecido implementa as operações básicas de uma árvore AVL: criação de nós, inserção com balanceamento, rotações e exibição dos nós em ordem.

### Explicação do Código

#### 1. Estrutura do Nó (`struct Node`)
Cada nó na árvore AVL possui:
- `key`: o valor armazenado no nó.
- `left` e `right`: ponteiros para os nós filho.
- `height`: a altura do nó, que é usada para calcular o balanceamento da árvore.

```c
struct Node {
    int id;               // ID do cliente (chave de busca)
    char name[50];        // Nome do cliente
    struct Node *left;
    struct Node *right;
    int height;
};
```

#### 2. Função `height`
Calcula a altura de um nó. A altura de um nó é definida como o número de arestas no caminho mais longo até uma folha. É usada para verificar o balanceamento dos nós.

```c
int height(struct Node *N) {
    if (N == NULL)
        return 0;
    return N->height;
}
```

#### 3. Função `max`
Retorna o maior valor entre dois inteiros, usada para atualizar a altura de um nó com base nas alturas dos filhos.

```c
int max(int a, int b) {
    return (a > b) ? a : b;
}
```

#### 4. Funções de Rotação (`rightRotate` e `leftRotate`)
Essas funções realizam rotações nos nós para corrigir o balanceamento. As rotações são:
- **Rotação à Direita** (`rightRotate`): utilizada quando a subárvore esquerda é mais alta.
- **Rotação à Esquerda** (`leftRotate`): utilizada quando a subárvore direita é mais alta.

```c
struct Node *rightRotate(struct Node *y) { /* Implementação da rotação à direita */ }
struct Node *leftRotate(struct Node *x) { /* Implementação da rotação à esquerda */ }
```

#### 5. Função `getBalance`
Calcula o fator de balanceamento de um nó, que é a diferença entre as alturas das subárvores esquerda e direita. Se o fator for maior que 1 ou menor que -1, o nó está desbalanceado e uma rotação será necessária.

```c
int getBalance(struct Node *N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
```

#### 6. Função `insert`
Insere um novo nó na árvore AVL e ajusta o balanceamento usando as rotações apropriadas quando necessário. A altura do nó é atualizada após cada inserção.

```c
struct Node* insert(struct Node* node, int key) {
    // Inserção e balanceamento
}
```

#### 7. Função `inOrder`
Percorre a árvore em ordem crescente e imprime as chaves dos nós, permitindo visualizar a organização da árvore.

```c
void inOrder(struct Node *tree) {
    if(tree != NULL) {
        inOrder(tree->left);
        printf("%d ", tree->key);
        inOrder(tree->right);
    }
}
```

#### 8. Função `printHeight`
Essa função adicional permite imprimir a altura de cada nó para verificar o balanceamento da árvore após cada operação.

```c
void printHeight(struct Node *tree) {
    if (tree != NULL) {
        printHeight(tree->left);
        printf("Nó: %d, Altura: %d\n", tree->key, tree->height);
        printHeight(tree->right);
    }
}
```

### Exemplo de Execução

Ao executar o código principal:

```c
int main() {
    struct Node *tree = NULL;

    tree = insert(tree, 10);
    tree = insert(tree, 20);
    tree = insert(tree, 30);
    tree = insert(tree, 40);
    tree = insert(tree, 50);
    tree = insert(tree, 25);

    printf("Árvore AVL em ordem: ");
    inOrder(tree);
    printf("\nAltura total da árvore: %d\n", height(tree));
    printHeight(tree);

    return 0;
}
```

A saída exibe a árvore AVL em ordem e imprime a altura de cada nó.

## Tarefas!

1. **Expandir o Código**: Implementar uma função para remover um nó da árvore AVL.
2. **Analisar o Balanceamento**: Desenhar a árvore após cada operação de inserção e remoção.
3. **Responder Consultas**: Criar funções para buscar elementos na árvore.

## Conclusão

Essa atividade auxilia no entendimento sobre a importância de estruturas balanceadas, como as árvores AVL, e o impacto das rotações no desempenho das operações de inserção e remoção. 
Aproveitem a atividade e explorem as propriedades de balanceamento da árvore AVL!
