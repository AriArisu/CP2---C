#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> // Incluindo para usar o tipo bool
 
#define MAX 100
 
void fibonacci();
void fatorial();
void palindromo();
void substring();
void menu();
 
int main() {
    menu();
    return 0;
}
 
void fibonacci() {
    int n;
    printf("Digite um numero de 1 a 50:\n");
    if (scanf("%d", &n) != 1) {
        printf("Entrada inválida.\n");
        // Limpar o buffer de entrada
        while (getchar() != '\n');
        return;
    }
 
    if (n < 1 || n > 50) {
        printf("Numero invalido. Deve estar entre 1 e 50.\n");
        return;
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
    // Limpar o buffer de entrada
    while (getchar() != '\n');
}
 
 
void fatorial() {
    unsigned long long calcular_fatorial(int num) {
        unsigned long long resultado = 1;
        for (int i = 1; i <= num; i++)
            resultado *= i;
        return resultado;
    }
    int N;
 
    printf("Digite um numero de 1 a 20: ");
    if (scanf("%d", &N) != 1) {
        printf("Entrada inválida.\n");
        // Limpar o buffer de entrada
        while (getchar() != '\n');
        return;
    }
 
    if (N < 1 || N > 20) {
        printf("Fatorial não definido para esse valor.\n");
        // Limpar o buffer de entrada
        while (getchar() != '\n');
        return;
    }
 
    unsigned long long lista[N];  // Armazena os fatoriais
 
    for (int i = 0; i < N; i++) {
        lista[i] = calcular_fatorial(i + 1);
        printf("%d! = %llu\n", i + 1, lista[i]);
    }
    // Limpar o buffer de entrada
    while (getchar() != '\n');
}
 
void palindromo() {
    char palavra[101]; // Ate 100 caracteres + 1 para o caractere nulo
    int i, tamanho_palavra, eh_palindromo = 1; // Renomeei a variável para melhor clareza
 
    printf("Digite uma palavra: ");
    if (scanf("%100s", palavra) != 1) { // Le no maximo 100 caracteres sem espaços
        printf("Entrada inválida.\n");
        // Limpar o buffer de entrada
        while (getchar() != '\n');
        return;
    }
 
    tamanho_palavra = strlen(palavra); // Calcula tamanho da string com a funcao strlen
 
    for (i = 0; i < tamanho_palavra / 2; i++) { // Este "for" percorre metade da palavra
        if (palavra[i] != palavra[tamanho_palavra - 1 - i]) { // Le a primeira letra e corresponde com a ultima
            eh_palindromo = 0;
            break;
        }
    }
 
    if (eh_palindromo == 1) { // Eh um palindromo se 1
        printf("A palavra e um palindromo.\n");
    } else {
        printf("A palavra NAO e um palindromo.\n"); // Nao e um palindromo se diferente de 1
    }
    // Limpar o buffer de entrada
    while (getchar() != '\n');
}
 
void substring() {
    bool eh_substring_sem_ponteiro(const char str[], const char sub[]) {
        int i, j;
        int n = strlen(str);
        int m = strlen(sub);
 
        if (m == 0) return true;
        if (n == 0) return false;
 
        for (i = 0; i <= n - m; i++) {
            bool encontrou = true;
            for (j = 0; j < m; j++) {
                if (str[i + j] != sub[j]) {
                    encontrou = false;
                    break;
                }
            }
            if (encontrou) return true;
        }
        return false;
    }
 
    void verificar_substring_sem_ponteiro() {
        char a[MAX], b[MAX];
 
        printf("\nDigite a primeira string: ");
        fgets(a, MAX, stdin);
        a[strcspn(a, "\n")] = '\0';
 
        printf("Digite a segunda string: ");
        fgets(b, MAX, stdin);
        b[strcspn(b, "\n")] = '\0';
 
        if (eh_substring_sem_ponteiro(a, b))
            printf("A segunda string esta contida na primeira.\n\n");
        else
            printf("A segunda string NAO esta contida na primeira.\n\n");
    }
    verificar_substring_sem_ponteiro();
    // Limpar o buffer de entrada
    while (getchar() != '\n');
}
 
void menu() {
    int opcao;
 
    do {
        printf("\n===== MENU DE OPÇÕES =====\n");
        printf("1. Sequência de Fibonacci com Vetores\n");
        printf("2. Fatoriais com Vetores\n");
        printf("3. Palíndromo\n");
        printf("4. Verificar Substring\n");
        printf("5. Sair\n");
        printf("========================\n");
        printf("Digite sua opção: ");
        if (scanf("%d", &opcao) != 1) {
            printf("\nEntrada inválida! Por favor, digite um número.\n");
            // Limpar o buffer de entrada
            while (getchar() != '\n');
            opcao = -1; // Para continuar no loop
            continue;
        }
        // Limpar o buffer de entrada após a leitura do inteiro
        while (getchar() != '\n');
 
        switch (opcao) {
            case 1:
                fibonacci();
                break;
            case 2:
                fatorial();
                break;
            case 3:
                palindromo();
                break;
            case 4:
                substring();
                break;
            case 5:
                printf("\nPrograma encerrado. Até mais!\n");
                break;
            default:
                printf("\nOpção inválida! Pressione Enter para tentar novamente...");
                getchar();
        }
 
    } while (opcao != 5);
}