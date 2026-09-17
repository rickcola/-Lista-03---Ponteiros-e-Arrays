#include <stdio.h>

void func(int *px, int *py) {
    px = py;
    // Teste de mesa - x=5, y=6:
    //
    // | Momento                          |  x |  y | px | py |
    
    // | Apos scanf (leitura de x e y)     |  5 |  6 |  - |  - |
    // | Apos func(&x, &y) ser chamada     |  5 |  6 | &x | &y |
    // | Apos px = py;                     |  5 |  6 | &y | &y |
    // | Apos *py = (*py) * (*px);         |  5 | 36 | &y | &y |
    // | Apos *px = *px + 2;                |  5 | 38 | &y | &y |
    //
    // Explicacao: px = py faz o ponteiro px deixar de apontar para x
    // e passar a apontar para o mesmo endereco de py (ou seja, y).
    // A partir daí, *px e *py se referem a mesma variavel (y).
    // Por isso x nunca e alterado, e y sofre duas operacoes seguidas.

    *py = (*py) * (*px);   // y = y * y = 6 * 6 = 36
    *px = *px + 2;          // y = 36 + 2 = 38 (px aponta para y)
}

int main() {
    int x, y;
    scanf("%d", &x);
    scanf("%d", &y);
    func(&x, &y);
    printf("x = %d, y = %d", x, y); // saida: x = 5, y = 38
    return 0;
}