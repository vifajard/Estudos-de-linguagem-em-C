#include <stdio.h>
#include <stdlib.h>  // Para malloc e free

int main() {
    int *numeros; // Ponteiro para vetor dinâmico
    int n, i;

    // Solicita a quantidade de números
    printf("Digite a quantidade de numeros: ");
    scanf("%d", &n);

    // Aloca dinamicamente o vetor com n posições
    numeros = (int*) malloc(n * sizeof(int));

    if (numeros == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return 1;  // Encerra o programa com erro
    }

    // Lê os números informados pelo usuário
    printf("Digite os %d numeros:\n", n);
    for (i = 0; i < n; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    // Exibe os números na ordem inversa
    printf("\nNumeros na ordem inversa:\n");
    for (i = n - 1; i >= 0; i--) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    // Libera a memória alocada
    free(numeros);

    return 0;
}
