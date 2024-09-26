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
    int ocupada;          // Flag para indicar se o slot está ocupado
} Transacao;

// Estrutura da Tabela Hash
typedef struct {
    Transacao tabela[TAMANHO_HASH];  // Array de transações
} TabelaHash;

// Função Hash: Retorna o índice baseado no ID da transação
int funcao_hash(int id) {
    return id % TAMANHO_HASH;  // Usa módulo para determinar a posição na tabela
}

// Função hash para duplo hashing
int hash2(int id) {
    return 7 - (id % 7);  // Segunda função hash para duplo hashing
}

// Sondagem linear
int sondagem_linear(TabelaHash *tabela, int id) {
    int indice = funcao_hash(id);
    int tentativas = 0;

    while (tabela->tabela[indice].ocupada && tentativas < TAMANHO_HASH) {
        indice = (indice + 1) % TAMANHO_HASH;  // Avança linearmente
        tentativas++;
    }

    return (tentativas < TAMANHO_HASH) ? indice : -1;  // Retorna o índice ou -1 se a tabela estiver cheia
}

// Sondagem quadrática
int sondagem_quadratica(TabelaHash *tabela, int id) {
    int indice = funcao_hash(id);
    int i = 1;
    int tentativas = 0;

    while (tabela->tabela[indice].ocupada && tentativas < TAMANHO_HASH) {
        indice = (funcao_hash(id) + i * i) % TAMANHO_HASH;  // Avança quadraticamente
        i++;
        tentativas++;
    }

    return (tentativas < TAMANHO_HASH) ? indice : -1;  // Retorna o índice ou -1 se a tabela estiver cheia
}

// Duplo hashing
int duplo_hashing(TabelaHash *tabela, int id) {
    int indice = funcao_hash(id);
    int step = hash2(id);
    int tentativas = 0;

    while (tabela->tabela[indice].ocupada && tentativas < TAMANHO_HASH) {
        indice = (indice + step) % TAMANHO_HASH;  // Usa duplo hashing
        tentativas++;
    }

    return (tentativas < TAMANHO_HASH) ? indice : -1;  // Retorna o índice ou -1 se a tabela estiver cheia
}

// Função para criar uma nova transação
Transacao criar_transacao(int id, float valor, const char *local, const char *status) {
    Transacao nova_transacao;
    nova_transacao.id = id;
    nova_transacao.valor = valor;
    strcpy(nova_transacao.local, local);
    strcpy(nova_transacao.status, status);
    nova_transacao.ocupada = 1;  // Marca o slot como ocupado
    return nova_transacao;
}

// Função para inserir uma transação na tabela hash usando sondagem linear
void inserir_linear(TabelaHash *tabela, Transacao transacao) {
    int indice = funcao_hash(transacao.id);

    // Se não houver colisão, insere diretamente
    if (!tabela->tabela[indice].ocupada) {
        tabela->tabela[indice] = transacao;
    } else {
        // Se houver colisão, chama a sondagem linear
        int novo_indice = sondagem_linear(tabela, transacao.id);
        if (novo_indice != -1) {
            tabela->tabela[novo_indice] = transacao;
        } else {
            printf("Erro: Tabela hash está cheia.\n");
        }
    }
}

// Função para inserir uma transação na tabela hash usando sondagem quadrática
void inserir_quadratica(TabelaHash *tabela, Transacao transacao) {
    int indice = funcao_hash(transacao.id);

    // Se não houver colisão, insere diretamente
    if (!tabela->tabela[indice].ocupada) {
        tabela->tabela[indice] = transacao;
    } else {
        // Se houver colisão, chama a sondagem quadrática
        int novo_indice = sondagem_quadratica(tabela, transacao.id);
        if (novo_indice != -1) {
            tabela->tabela[novo_indice] = transacao;
        } else {
            printf("Erro: Tabela hash está cheia.\n");
        }
    }
}

// Função para inserir uma transação na tabela hash usando duplo hashing
void inserir_duplo_hashing(TabelaHash *tabela, Transacao transacao) {
    int indice = funcao_hash(transacao.id);

    // Se não houver colisão, insere diretamente
    if (!tabela->tabela[indice].ocupada) {
        tabela->tabela[indice] = transacao;
    } else {
        // Se houver colisão, chama o duplo hashing
        int novo_indice = duplo_hashing(tabela, transacao.id);
        if (novo_indice != -1) {
            tabela->tabela[novo_indice] = transacao;
        } else {
            printf("Erro: Tabela hash está cheia.\n");
        }
    }
}

// Função para exibir todas as transações
void exibir_todas(TabelaHash *tabela) {
    for (int i = 0; i < TAMANHO_HASH; i++) {
        if (tabela->tabela[i].ocupada) {
            printf("Transação ID: %d, Valor: %.2f, Local: %s, Status: %s (Índice: %d)\n",
                   tabela->tabela[i].id, tabela->tabela[i].valor, tabela->tabela[i].local, tabela->tabela[i].status, i);
        }
    }
}


// Função de busca


// Função de exclusão


// Função principal para demonstrar o uso da tabela hash com sondagem
int main() {
    // Inicializa a tabela hash
    TabelaHash tabela_linear = {0};  // Todos os slots começam desocupados

    // Inserir transações na tabela hash usando sondagem linear
    printf("\nInserção com Sondagem Linear:\n");
    inserir_linear(&tabela_linear, criar_transacao(101, 1000.50, "São Paulo", "suspeita"));
    inserir_linear(&tabela_linear, criar_transacao(102, 250.75, "Rio de Janeiro", "normal"));
    inserir_linear(&tabela_linear, criar_transacao(103, 50000.00, "Miami", "suspeita"));
    inserir_linear(&tabela_linear, criar_transacao(104, 1500.00, "Lisboa", "normal"));
    inserir_linear(&tabela_linear, criar_transacao(105, 2000.25, "Nova York", "suspeita"));

    exibir_todas(&tabela_linear);

    // Inserir transações na tabela hash usando sondagem quadrática
    printf("\nInserção com Sondagem Quadrática:\n");
    TabelaHash tabela_quadratica = {0};
    inserir_quadratica(&tabela_quadratica, criar_transacao(106, 750.00, "Paris", "normal"));
    inserir_quadratica(&tabela_quadratica, criar_transacao(107, 3000.50, "Berlim", "suspeita"));
    inserir_quadratica(&tabela_quadratica, criar_transacao(108, 850.00, "Madri", "normal"));
    inserir_quadratica(&tabela_quadratica, criar_transacao(109, 990.75, "Londres", "suspeita"));
    inserir_quadratica(&tabela_quadratica, criar_transacao(110, 1200.40, "Roma", "normal"));

    exibir_todas(&tabela_quadratica);

    // Inserir transações na tabela hash usando duplo hashing
    printf("\nInserção com Duplo Hashing:\n");
    TabelaHash tabela_duplo = {0};
    inserir_duplo_hashing(&tabela_duplo, criar_transacao(111, 4500.25, "Zurique", "suspeita"));
    inserir_duplo_hashing(&tabela_duplo, criar_transacao(112, 150.00, "Pequim", "normal"));
    inserir_duplo_hashing(&tabela_duplo, criar_transacao(113, 600.75, "Tóquio", "suspeita"));
    inserir_duplo_hashing(&tabela_duplo, criar_transacao(114, 200.20, "Sydney", "normal"));
    inserir_duplo_hashing(&tabela_duplo, criar_transacao(115, 3700.30, "Cidade do México", "suspeita"));

    exibir_todas(&tabela_duplo);

    return 0;
}
