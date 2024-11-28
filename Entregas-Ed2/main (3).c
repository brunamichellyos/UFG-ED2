#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do nó da Árvore Patricia
typedef struct PatriciaNode {
    char *key;                     // Chave armazenada (palavra ou parte dela)
    int isEndOfWord;               // Indica se é o final de uma palavra
    struct PatriciaNode *left;     // Filhos para prefixos diferentes
    struct PatriciaNode *right;    // Filhos para prefixos iguais
} PatriciaNode;

// Função para criar um novo nó
PatriciaNode* createNode(const char *key, int isEndOfWord) {
    PatriciaNode *node = (PatriciaNode *)malloc(sizeof(PatriciaNode));
    node->key = strdup(key); // Copia a chave
    node->isEndOfWord = isEndOfWord;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Função para encontrar o primeiro índice onde duas strings divergem
int findMismatchIndex(const char *str1, const char *str2) {
    int i = 0;
    while (str1[i] && str2[i] && str1[i] == str2[i]) {
        i++;
    }
    return i;
}

// Função para inserir uma palavra na Árvore Patricia
PatriciaNode* insertPatricia(PatriciaNode *root, const char *word) {
    if (!root) {
        return createNode(word, 1); // Novo nó para palavra
    }

    int mismatchIndex = findMismatchIndex(root->key, word);

    // Caso 1: A palavra é um prefixo do nó atual
    if (mismatchIndex == strlen(root->key)) {
        if (mismatchIndex == strlen(word)) {
            // Palavra já existe
            root->isEndOfWord = 1;
        } else {
            // Inserir a parte restante na subárvore direita
            root->right = insertPatricia(root->right, word + mismatchIndex);
        }
        return root;
    }

    // Caso 2: O nó atual é um prefixo da palavra
    if (mismatchIndex == strlen(word)) {
        PatriciaNode *newNode = createNode(word, 1);
        newNode->right = root;
        return newNode;
    }

    // Caso 3: Há um ponto de divergência
    PatriciaNode *splitNode = createNode(root->key + mismatchIndex, root->isEndOfWord);
    splitNode->left = root->left;
    splitNode->right = root->right;

    root->key[mismatchIndex] = '\0'; // Divide a chave do nó atual
    root->isEndOfWord = 0;
    root->left = splitNode;
    root->right = createNode(word + mismatchIndex, 1);

    return root;
}

// Função para buscar uma palavra na Árvore Patricia
int searchPatricia(PatriciaNode *root, const char *word) {
    if (!root) {
        return 0; // Palavra não encontrada
    }

    int mismatchIndex = findMismatchIndex(root->key, word);

    // Palavra é prefixo do nó atual
    if (mismatchIndex == strlen(word) && mismatchIndex <= strlen(root->key)) {
        return root->isEndOfWord;
    }

    // Ir para a subárvore direita
    if (mismatchIndex == strlen(root->key)) {
        return searchPatricia(root->right, word + mismatchIndex);
    }

    return 0; // Palavra não encontrada
}

// Função para exibir as palavras na Árvore Patricia
void printPatricia(PatriciaNode *root, char *buffer, int depth) {
    if (!root) {
        return;
    }

    // Copiar a chave atual no buffer
    strncpy(buffer + depth, root->key, strlen(root->key));
    depth += strlen(root->key);

    // Exibir a palavra se for um final válido
    if (root->isEndOfWord) {
        buffer[depth] = '\0';
        printf("%s\n", buffer);
    }

    // Recursão para subárvores
    printPatricia(root->left, buffer, depth);
    printPatricia(root->right, buffer, depth);
}

// Função para sugerir palavras com base no prefixo
void suggestWords(PatriciaNode *root, const char *prefix, char *buffer, int depth) {
    if (!root) {
        return;
    }

    // Copiar a chave atual no buffer
    strncpy(buffer + depth, root->key, strlen(root->key));
    depth += strlen(root->key);

    // Verifica se o prefixo corresponde ao início da chave
    if (strncmp(buffer, prefix, strlen(prefix)) == 0) {
        // Exibe se for um final de palavra
        if (root->isEndOfWord) {
            buffer[depth] = '\0';
            printf("%s\n", buffer);
        }
    }

    // Recursão para subárvores
    suggestWords(root->left, prefix, buffer, depth);
    suggestWords(root->right, prefix, buffer, depth);
}

// Função para ler palavras de um arquivo e inseri-las na árvore
PatriciaNode* loadDictionary(const char *filename, PatriciaNode *root) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Erro ao abrir o arquivo %s\n", filename);
        return root;
    }

    char word[100];
    while (fscanf(file, "%s", word) != EOF) {
        root = insertPatricia(root, word);
    }

    fclose(file);
    return root;
}

int main() {
    PatriciaNode *root = NULL;
    char buffer[100]; // Buffer para exibição das palavras

    // Carregar palavras de um arquivo (substitua com o caminho do seu arquivo de dicionário)
    root = loadDictionary("dicionario.txt", root);

    // Exemplo de busca de palavras
    printf("Busca por 'car': %s\n", searchPatricia(root, "car") ? "Encontrada" : "Não encontrada");
    printf("Busca por 'dog': %s\n", searchPatricia(root, "dog") ? "Encontrada" : "Não encontrada");
    printf("Busca por 'bat': %s\n", searchPatricia(root, "bat") ? "Encontrada" : "Não encontrada");

    // Exibir todas as palavras
    printf("\nPalavras na árvore:\n");
    printPatricia(root, buffer, 0);

    // Sugestões de palavras com base em um prefixo
    char prefix[100];
    printf("\nDigite um prefixo para sugestões: ");
    scanf("%s", prefix);

    printf("Sugestões para o prefixo '%s':\n", prefix);
    suggestWords(root, prefix, buffer, 0);

    return 0;
}
