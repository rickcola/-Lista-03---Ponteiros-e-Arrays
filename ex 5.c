#include <stdio.h>
#include <stdlib.h>

int *adiciona_valor(int *v, int *tamanho, int valor, int pos) {
    if (pos >= *tamanho) {

        int *novo = (int *) realloc(v, (pos + 1) * sizeof(int));
        if (novo == NULL) {
            printf("Erro ao realocar memoria.\n");
            return v; 
        }
        v = novo;
        *tamanho = pos + 1; 
    }

    v[pos] = valor;
    return v;
}

int main() {
    int tamanho = 3;
    int *v = (int *) malloc(tamanho * sizeof(int));
    v[0] = 10;
    v[1] = 20;
    v[2] = 30;

    printf("Array antes:\n");
    for (int i = 0; i < tamanho; i++) printf("v[%d] = %d\n", i, v[i]);

    v = adiciona_valor(v, &tamanho, 99, 5);

    printf("\nArray depois:\n");
    for (int i = 0; i < tamanho; i++) printf("v[%d] = %d\n", i, v[i]);

    free(v);
    return 0;
}