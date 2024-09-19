#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_HASH 10

// Estrutura para representar uma transação financeira
typedef struct {
    int id;               // ID único da transação
    float valor;          // Valor da transação
    char local[50];       // Local da transação
    char status[20];      // Status: "normal" ou "suspeita"
} Transacao;

// Estrutura da Tabela Hash
typedef struct {
    Transacao *tabela[TAMANHO_HASH];  // Array de ponteiros para armazenar transações
} TabelaHash;

// Função Hash: Retorna o índice baseado no ID da transação
int funcao_hash(int id) {
    return id % TAMANHO_HASH;  // Usa módulo para determinar a posição na tabela
}

// Função para inserir uma transação na tabela hash
void inserir(TabelaHash *tabela, Transacao *transacao) {
    int indice = funcao_hash(transacao->id);  // Calcula o índice baseado no ID
    tabela->tabela[indice] = transacao;  // Insere a transação na tabela
}

// Função para buscar uma transação na tabela hash pelo ID
Transacao *buscar(TabelaHash *tabela, int id) {
    int indice = funcao_hash(id);  // Calcula o índice para busca
    return tabela->tabela[indice];  // Retorna a transação encontrada
}

// Função para exibir transações suspeitas
void exibir_suspeitas(TabelaHash *tabela) {
    for (int i = 0; i < TAMANHO_HASH; i++) {
        if (tabela->tabela[i] != NULL && strcmp(tabela->tabela[i]->status, "suspeita") == 0) {
            printf("Transação ID: %d, Valor: %.2f, Local: %s, Status: %s\n",
                   tabela->tabela[i]->id,
                   tabela->tabela[i]->valor,
                   tabela->tabela[i]->local,
                   tabela->tabela[i]->status);
        }
    }
}

// Função principal para demonstrar o uso da tabela hash com transações financeiras
int main() {
    // Inicializa a tabela hash
    TabelaHash tabela = {NULL};

    // Criação de algumas transações
    Transacao transacao1 = {101, 10000.50, "São Paulo", "suspeita"};
    Transacao transacao2 = {102, 250.75, "Rio de Janeiro", "normal"};
    Transacao transacao3 = {103, 50000.00, "Miami", "suspeita"};

    // Insere as transações na tabela hash
    inserir(&tabela, &transacao1);
    inserir(&tabela, &transacao2);
    inserir(&tabela, &transacao3);

    // Busca por uma transação específica
    Transacao *t = buscar(&tabela, 105);
    if (t != NULL) {
        printf("Transação encontrada: ID: %d, Valor: %.2f, Local: %s, Status: %s\n",
               t->id, t->valor, t->local, t->status);
    } else {
        printf("Transação não encontrada.\n");
    }

    // Exibir todas as transações suspeitas
    printf("\nTransações suspeitas:\n");
    exibir_suspeitas(&tabela);

    return 0;
}

