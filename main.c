#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

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

int main() {
    verificar_substring_sem_ponteiro();
    return 0;
}
