#include <stdio.h>
#include <string.h>

int main() {
    char palavra[101]; // Ate 100 caracteres + 1 para o caractere nulo
    int i, tamanho_palavra, palindromo = 1;

    printf("Digite uma palavra: ");
    scanf("%100s", palavra); // Le no maximo 100 caracteres sem espaços

    tamanho_palavra = strlen(palavra); // Calcula tamanho da string com a funcao strlen

    for (i = 0; i < tamanho_palavra / 2; i++) { // Este "for" percorre metade da palavra
        if (palavra[i] != palavra[tamanho_palavra - 1 - i]) { // Le a primeira letra e corresponde com a ultima
            palindromo = 0;
            break;
        }
    }

    if (palindromo == 1) { // Eh um palindro se 1
        printf("A palavra e um palindromo.\n");
    } else {
        printf("A palavra NAO e um palindromo.\n"); // Nao e um palindromo se diferente de 1
    }

    return 0;
}
