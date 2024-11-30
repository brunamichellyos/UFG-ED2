#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_HASH 10

// Estrutura para representar um pedido de delivery
typedef struct Transacao{
    int id;                // ID único do pedido
    float valor;           // Valor do pedido
    char local[50];        // Local de entrega
    char status[20];       // Status: "pedido feito", "entregue", "cancelado"
    float tempo_preparo;   // Tempo de preparo em minutos
    float distancia;       // Distância da entrega em minutos
    float tempo_pedido;    // Tempo total do pedido em minutos
    struct Transacao *proximo;
} Transacao;

// Estrutura da Tabela Hash
typedef struct {
    Transacao *tabela[TAMANHO_HASH];  // Array de ponteiros para armazenar pedidos
} TabelaHash;

// Função Hash: Retorna o índice baseado no ID do pedido
int funcao_hash(int id) {
    return id % TAMANHO_HASH;  // Usa módulo para determinar a posição na tabela
}

// Função para criar uma nova transação
Transacao *criar_transacao(int id, float valor, const char *local, const char *status, float tempo_preparo, float distancia, float tempo_pedido) {
    Transacao *nova_transacao = (Transacao *)malloc(sizeof(Transacao));
    if (nova_transacao == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    nova_transacao->id = id;
    nova_transacao->valor = valor;
    strcpy(nova_transacao->local, local);
    strcpy(nova_transacao->status, status);
    nova_transacao->tempo_preparo = tempo_preparo;
    nova_transacao->distancia = distancia;
    nova_transacao->tempo_pedido = tempo_pedido;
    nova_transacao->proximo = NULL;
    return nova_transacao;
}

// Função para inserir uma transação na tabela hash (usando listas ligadas para colisões)
void inserir(TabelaHash *tabela, Transacao *transacao) {
    int indice = funcao_hash(transacao->id);  // Calcula o índice baseado no ID
    transacao->proximo = tabela->tabela[indice];  // Insere no início da lista ligada
    tabela->tabela[indice] = transacao;
}

// Função para exibir todas as transações
void exibir_todas(TabelaHash *tabela) {
    for (int i = 0; i < TAMANHO_HASH; i++) {
        Transacao *atual = tabela->tabela[i];
        while (atual != NULL) {
            printf("Transação ID: %d, Valor: %.2f, Local: %s, Status: %s, Tempo de Preparo %.2f, Distância %.2f, Tempo do pedido %.2f (Índice: %d)\n",
                   atual->id, atual->valor, atual->local, atual->status,atual->tempo_preparo,atual->distancia,atual->tempo_pedido, i);
            atual = atual->proximo;  // Avança para a próxima transação
        }
    }
}

// Função para buscar uma transação na tabela hash pelo ID
Transacao *buscar(TabelaHash *tabela, int id) {
    int indice = funcao_hash(id);  // Calcula o índice para busca
    Transacao *atual = tabela->tabela[indice];
   
    while (atual != NULL) {
        if (atual->id == id) {
            return atual;  // Retorna a transação se encontrada
        }
        atual = atual->proximo;  // Vai para a próxima transação na lista ligada
    }
    return NULL;  // Retorna NULL se não for encontrada
}

// Função para excluir uma transação na tabela hash pelo ID
void excluir(TabelaHash *tabela, int id) {
    int indice = funcao_hash(id);  // Calcula o índice para exclusão
    Transacao *atual = tabela->tabela[indice];
    Transacao *anterior = NULL;

    while (atual != NULL) {
        if (atual->id == id) {
            // Se o elemento a ser removido for o primeiro da lista
            if (anterior == NULL) {
                tabela->tabela[indice] = atual->proximo;  // Remove o primeiro elemento
            } else {
                anterior->proximo = atual->proximo;  // Remove o elemento no meio ou fim
            }
            free(atual);  // Libera a memória da transação
            printf("Transação com ID %d foi excluída.\n", id);
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    printf("Transação com ID %d não encontrada para exclusão.\n", id);
}

// Função para contar o número total de elementos (transações) na tabela hash
int contar_elementos(TabelaHash *tabela) {
    int total = 0;

    // Percorre todas as posições da tabela hash
    for (int i = 0; i < TAMANHO_HASH; i++) {
        Transacao *atual = tabela->tabela[i];

        // Percorre a lista ligada em cada posição
        while (atual != NULL) {
            total++;  // Incrementa o contador para cada transação encontrada
            atual = atual->proximo;  // Vai para o próximo elemento na lista
        }
    }

    return total;
}


// Função para inserir 20 transações predefinidas na tabela hash
void inserir_dados_predefinidos(TabelaHash *tabela) {
    // Inserindo transações diretamente
    inserir(tabela, criar_transacao(101, 1000.50, "São Paulo", "pedido feito", 15.0, 12.5, 30.0));
    inserir(tabela, criar_transacao(102, 250.75, "Rio de Janeiro", "entregue", 10.0, 8.0, 25.0));
    inserir(tabela, criar_transacao(103, 50000.00, "Miami", "cancelado", 45.0, 100.0, 120.0));
    inserir(tabela, criar_transacao(104, 1500.00, "Lisboa", "entregue", 20.0, 50.0, 60.0));
    inserir(tabela, criar_transacao(105, 2000.25, "Nova York", "pedido feito", 25.0, 80.0, 90.0));
    inserir(tabela, criar_transacao(106, 750.00, "Paris", "entregue", 12.0, 25.0, 40.0));
    inserir(tabela, criar_transacao(107, 3000.50, "Berlim", "cancelado", 30.0, 60.0, 70.0));
    inserir(tabela, criar_transacao(108, 850.00, "Madri", "entregue", 10.0, 15.0, 25.0));  
    inserir(tabela, criar_transacao(109, 990.75, "Londres", "pedido feito", 18.0, 40.0, 50.0)) ;
    inserir(tabela, criar_transacao(110, 1200.40, "Roma", "entregue", 22.0, 55.0, 65.0));
    inserir(tabela, criar_transacao(111, 4500.25, "Zurique", "cancelado", 40.0, 90.0, 100.0));
    inserir(tabela, criar_transacao(112, 150.00, "Pequim", "entregue", 8.0, 10.0, 20.0));
    inserir(tabela, criar_transacao(113, 600.75, "Tóquio", "pedido feito", 15.0, 35.0, 45.0));
    inserir(tabela, criar_transacao(114, 200.20, "Sydney", "entregue", 11.0, 20.0, 30.0));  
    inserir(tabela, criar_transacao(115, 3700.30, "Cidade do México", "cancelado", 28.0, 75.0, 85.0));
    inserir(tabela, criar_transacao(116, 550.00, "Seul", "entregue", 9.0, 18.0, 27.0));
    inserir(tabela, criar_transacao(117, 480.45, "Santiago", "pedido feito", 13.0, 30.0, 40.0));
    inserir(tabela, criar_transacao(118, 900.10, "Amsterdã", "entregue", 14.0, 22.0, 32.0));
    inserir(tabela, criar_transacao(119, 120.70, "Viena", "cancelado", 7.0, 12.0, 18.0));
    inserir(tabela, criar_transacao(120, 300.55, "Dubai", "entregue", 16.0, 20.0, 35.0));  


    printf("Transações foram inseridas com sucesso.\n");
}


// Função principal para demonstrar o uso da tabela hash com transações financeiras
int main() {
    // Inicializa a tabela hash
    TabelaHash tabela = {NULL};

    // Inserir os dados predefinidos na tabela hash
    inserir_dados_predefinidos(&tabela);
   
    // Exibir todas as transações inseridas
    printf("\nTodas as transações inseridas: %d\n", contar_elementos(&tabela));
    exibir_todas(&tabela);

   
    // Busca por uma transação específica
    printf("\nBuscar uma Transação:\n");
    Transacao *t = buscar(&tabela, 102);
    if (t != NULL) {
        printf("Transação encontrada: ID: %d, Valor: %.2f, Local: %s, Status: %s\n",
               t->id, t->valor, t->local, t->status);
    } else {
        printf("Transação não encontrada.\n");
    }
   
   
    // Excluir as transações selecionadas
    printf("\nTransações excluidas:\n");
    excluir(&tabela, 119);
   
   
    // Exibir todas as transações inseridas
    printf("\nTransações Atualizadas: %d\n", contar_elementos(&tabela));
    exibir_todas(&tabela);
   

    return 0;
}
