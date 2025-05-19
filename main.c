#include <stdio.h>
#include <stdlib.h>


int main() {
    int n;
    printf("Digite um numero de 1 a 50:\n");
    scanf("%d", &n);

    if (n < 1 || n > 50) {
        printf("Numero invalido. Deve estar entre 1 e 50.\n");
        return 1;
    }

    // Usando long long para evitar estouro
    long long res[n];

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            res[i] = 0;
        } else if (i == 1) {
            res[i] = 1;
        } else {
            res[i] = res[i - 1] + res[i - 2];
        }
    }

    printf("Sequencia de Fibonacci:\n");
    for (int i = 0; i < n; i++) {
        printf("%lld ", res[i]);
    }
    printf("\n");

    return 0;
}


//pseudo código abaixo, para facilitar a correção.

// Início
//Escreva "Digite um número de 1 a 50:"
// Leia n
// Se n < 1 ou n > 50 então
//Escreva "Número inválido. Deve estar entre 1 e 50."
//Encerrar programa
//FimSe
//Criar um vetor res de tamanho n
//Para i de 0 até n - 1 faça
//   Se i == 0 então
//     res[0] ← 0
//   Senão se i == 1 então
//     res[1] ← 1
//   Senão
//     res[i] ← res[i - 1] + res[i - 2]
//   FimSe
// FimPara
// Escreva "Sequência de Fibonacci:"
// Para i de 0 até n - 1 faça
//   Escreva res[i] com espaço
// FimPara
//Fim
