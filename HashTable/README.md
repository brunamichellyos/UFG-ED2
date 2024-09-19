# Exemplo Prático: Classificação de Transações Financeiras com Tabela Hash

**Desafio**: Um banco precisa ordenar uma grande quantidade de transações financeiras com base no risco de fraude. Transações com valores elevados, realizadas em locais ou horários suspeitos, precisam ser analisadas com prioridade para identificar atividades fraudulentas em tempo real.

**Informações adicionais**: Os dados envolvem montantes, localização, histórico de transações e outros padrões que podem indicar fraude. O sistema precisa garantir que as transações mais suspeitas sejam analisadas primeiro.

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

#### Observações ⚠️ 

O exemplo de código apresentado aqui, é destinado a fins didáticos, com o objetivo de ilustrar os conceitos e o funcionamento básico de uma tabela hash. Ele não resolve o desafio proposto de forma completa, pois aspectos como o tratamento de colisões e a remoção eficiente de transações não foram abordados de maneira aprofundada. Para uma solução robusta, ajustes adicionais serão necessários. Continuaremos explorando e aprimorando esses conceitos nas próximas aulas.
