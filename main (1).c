#include <stdio.h>

int fatorial(int num) {
    int resultado = 1;
    for (int i = 1; i <= num; i++)
        resultado *= i;
    return resultado;
}

int main() {
    int N;

    printf("Digite um número de 1 a 20: ");
    scanf("%d", &N);

    if (N < 1 || N > 20) {
        printf("Fatorial não definida para esse valor.\n");
    } else {
        int lista[N];
        for (int i = 0; i < N; i++) {
            lista[i] = fatorial(i + 1);
            printf("%d! = %d\n", i + 1, lista[i]);
        }
    }

    return 0;
}
