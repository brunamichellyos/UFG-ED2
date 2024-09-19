# Exemplo Prático: Classificação de Transações Financeiras com Tabela Hash

Neste exemplo, vamos implementar uma tabela hash para armazenar transações financeiras com base no ID da transação como chave e os detalhes da transação como valor. A tabela será usada para classificar transações suspeitas, que precisam ser monitoradas de perto para detecção de fraudes.

#### Definição da Estrutura da Transação e da Tabela Hash

- Definição de uma struct para representar as transações financeiras:

  ```bash
    typedef struct {
        int id;               // ID único da transação
        float valor;          // Valor da transação
        char local[50];       // Local da transação
        char status[20];      // Status: "normal" ou "suspeita"
    } Transacao; 
   ```

- definição uma Tabela Hash simples usando um array de ponteiros para structs de Transação:

  ```bash
    #define TAMANHO_HASH 10
    
    typedef struct {
        Transacao *tabela[TAMANHO_HASH];  // Array de ponteiros para armazenar as transações
    } TabelaHash; 
   ```
#### Função Hash

- A função hash será usada para calcular o índice da tabela com base no ID da transação:

  ```bash
    int funcao_hash(int id) {
        return id % TAMANHO_HASH;  // Usa o módulo para distribuir os índices
    }
  ```

### Operações realizadas na tabela

- **Inserção**: As transações são inseridas na tabela hash usando o ID da transação como chave.
- **Busca**: É possível buscar por uma transação específica pelo seu ID.
- **Exibição de Transações Suspeitas**: Percorremos a tabela e exibimos as transações marcadas como "suspeita", que podem representar possíveis fraudes.


