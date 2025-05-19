#include <stdio.h>
#include <string.h>

int main() {
    char palavra[101]; // ate 100 caracteres + 1 para o caractere nulo
    int i, tamanho, palindromo = 1;

    printf("Digite uma palavra: ");
    scanf("%100s", palavra); // le no maximo 100 caracteres sem espaços

    tamanho = strlen(palavra);

    for (i = 0; i < tamanho / 2; i++) {
        if (palavra[i] != palavra[tamanho - 1 - i]) {
            palindromo = 0;
            break;
        }
    }

    if (palindromo == 1) {
        printf("A palavra e um palindromo.\n");
    } else {
        printf("A palavra NAO e um palindromo.\n");
    }

    return 0;
}
