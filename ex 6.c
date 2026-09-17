#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FALSE 0
#define TRUE 1

// b) aloca: recebe n e preenche (TRUE/FALSE)
int *aloca(int n, int preenche) {
    int *v;
    if (preenche == TRUE) {
        v = (int *) calloc(n, sizeof(int)); // aloca ja zerado
    } else {
        v = (int *) malloc(n * sizeof(int)); // aloca sem inicializar
    }
    return v;
}

// c) imprime: recebe v e n, usa so aritmetica de ponteiros
void imprime(int *v, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", *(v + i));
    }
    printf("\n");
}

// d) preenche: recebe v, n, valor e is_aleatorio
void preenche(int *v, int n, int valor, int is_aleatorio) {
    int i;
    if (is_aleatorio == TRUE) {
        for (i = 0; i < n; i++) {
            *(v + i) = rand() % 101; // valores aleatorios de 0 a 100
        }
    } else {
        for (i = 0; i < n; i++) {
            *(v + i) = valor;
        }
    }
}

int main() {
    srand(time(NULL)); // inicializa gerador de numeros aleatorios

    // 1. Declara dois ponteiros inteiros v1 e v2
    int *v1, *v2;
    int n = 10; // tamanho escolhido para ambos os vetores

    // 2. Chama aloca para v1, com preenche = FALSE (malloc, sem inicializar)
    v1 = aloca(n, FALSE);

    // 3. Chama aloca para v2, com preenche = TRUE (calloc, zerado)
    v2 = aloca(n, TRUE);

    // 4. Imprime ambos os vetores
    printf("v1 (recem alocado, malloc, com lixo de memoria):\n");
    imprime(v1, n);

    printf("v2 (recem alocado, calloc, zerado):\n");
    imprime(v2, n);

    // 5. Chama preenche para v1 com valor = 0 e is_aleatorio = TRUE
    preenche(v1, n, 0, TRUE);

    // 6. Chama preenche para v2 com valor = 100 e is_aleatorio = FALSE
    preenche(v2, n, 100, FALSE);

    // 7. Imprime v1 e v2 novamente
    printf("\nv1 (preenchido com valores aleatorios):\n");
    imprime(v1, n);

    printf("v2 (preenchido com valor fixo 100):\n");
    imprime(v2, n);

    free(v1);
    free(v2);

    return 0;
}