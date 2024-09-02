/*
O código abaixo recebe do usuário elementos que são inseridos em uma matriz 3x3, em seguida, imprime a soma de sua diagonal principal.
- faça uma modificação para que seja possível dinamizar o tamanho da matriz (utilizar alocação dinâmica de memória usando malloc)
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int linhas, colunas = 0;
    int soma = 0;
    
    printf("Digite o numero de linhas e logo em seguida o numero de colunas: ");
    scanf("%d", &linhas);
    scanf("%d", &colunas);
    
    
    int **matriz = (int **)malloc(linhas * sizeof(int *));
    
    for(int i = 0; i < linhas; i++){
        matriz[i] = (int *)malloc(colunas * sizeof(int));
    }

    printf("Insira os elementos da matriz %dx%d:\n",linhas,colunas);
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            scanf("%d", &matriz[i][j]);
            if(i == j){
                soma += matriz[i][j];
            }
        }
    }
    
    printf("Matriz:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    
    printf("Soma da diagonal principal: %d ",soma);

    return 0;
}