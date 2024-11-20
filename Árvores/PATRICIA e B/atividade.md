## **Desafio: Corretor Ortográfico com Árvores Patricia e Árvores B**


### **Descrição do Problema**

Uma empresa de tecnologia está desenvolvendo um corretor ortográfico para melhorar a experiência do usuário em seu editor de texto. O sistema precisa ser capaz de:

1. **Armazenar palavras do dicionário:** Inserir uma grande quantidade de palavras de maneira eficiente.
2. **Buscar palavras corretas:** Verificar se uma palavra digitada pelo usuário está no dicionário.
3. **Sugerir palavras próximas:** Listar sugestões de palavras com base em um prefixo digitado pelo usuário.

Os engenheiros sugeriram duas abordagens: **Árvores Patricia** e **Árvores B**. Sua tarefa é implementar ambas as estruturas de dados em C, realizar os testes necessários, e determinar qual delas é mais eficiente para o problema proposto.

---
#### **Objetivo:**
Desenvolver um corretor ortográfico básico que permita:
1. Inserir palavras em um dicionário (Árvore Patricia ou Árvore B).
2. Buscar palavras no dicionário.
3. Sugerir palavras com base no prefixo digitado pelo usuário (autocompletar).
---

### **Etapas para Implementação**

#### **1. Inserir Palavras no Dicionário**
   - Crie uma função para inserir palavras no dicionário.
   - **Entrada:** Um conjunto de palavras fornecido pelo professor, como um arquivo `dicionario.txt` com cerca de 1.000 palavras.
   - **Saída Esperada:** As palavras serão armazenadas na estrutura (Patricia ou B), e uma mensagem será exibida confirmando cada inserção.

   **Exemplo de Teste:**
   ```c
   insertWord(dicionario, "carro");
   insertWord(dicionario, "casa");
   ```

---

#### **2. Buscar Palavras no Dicionário**
   - Crie uma função para verificar se uma palavra está presente no dicionário.
   - **Entrada:** Uma palavra digitada pelo usuário.
   - **Saída Esperada:** Retornar "Encontrada" ou "Não encontrada".

   **Exemplo de Teste:**
   ```c
   printf("Busca: %s\n", searchWord(dicionario, "carro") ? "Encontrada" : "Não encontrada");
   ```

---

#### **3. Autocompletar Palavras com Base em Prefixo**
   - Implemente uma função que sugira palavras com base no prefixo digitado.
   - **Entrada:** Um prefixo fornecido pelo usuário.
   - **Saída Esperada:** Uma lista de palavras do dicionário que começam com o prefixo.

   **Exemplo de Teste:**
   ```c
   printf("Sugestões para 'car':\n");
   suggestWords(dicionario, "car");
   // Saída: carro, carta, cartela
   ```

---

#### **4. Interagir com o Usuário**
   - Crie um menu simples no programa para que o usuário possa:
     - Inserir palavras no dicionário.
     - Buscar palavras no dicionário.
     - Obter sugestões com base em um prefixo.

   **Exemplo de Menu:**
   ```c
   printf("Escolha uma opção:\n");
   printf("1. Inserir palavra\n");
   printf("2. Buscar palavra\n");
   printf("3. Sugerir palavras (autocompletar)\n");
   ```

---

#### **Funções-Chave a Implementar**

##### **1. Função de Inserção**
```c
void insertWord(PatriciaNode **root, const char *word);
// Ou para Árvore B:
void insertWord(BTreeNode **root, const char *word);
```

##### **2. Função de Busca**
```c
int searchWord(PatriciaNode *root, const char *word);
// Ou para Árvore B:
int searchWord(BTreeNode *root, const char *word);
```

##### **3. Função de Sugestão (Autocompletar)**
```c
void suggestWords(PatriciaNode *root, const char *prefix);
// Ou para Árvore B:
void suggestWords(BTreeNode *root, const char *prefix);
```

---

### **Entrega Final**
1. **Código Funcional:** Implementação completa com o menu interativo.
2. **Teste de Conjunto de Palavras:** Incluindo palavras de um arquivo `dicionario.txt` no programa.
3. **Autocompletar Operacional:** Sugestões baseadas em prefixos funcionando corretamente.

---

Desafie-se a construir soluções inteligentes para problemas reais! Este exercício não é apenas uma prática – é uma oportunidade de aplicar sua criatividade e habilidade em estruturas de dados para resolver desafios do mundo moderno!
