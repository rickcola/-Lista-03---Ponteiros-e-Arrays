#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char palavraEstatica[100];
    char *palavraDinamica;
    int tamanho;

    printf("Digite uma palavra: ");
    scanf("%s", palavraEstatica);

    tamanho = strlen(palavraEstatica) + 1;

    palavraDinamica = (char *) malloc(tamanho * sizeof(char));

    if (palavraDinamica == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    strcpy(palavraDinamica, palavraEstatica);

    printf("Palavra (estatica):  %s\n", palavraEstatica);
    printf("Palavra (dinamica):  %s\n", palavraDinamica);

    free(palavraDinamica); 

    return 0;
}