#include <stdio.h>

int main() {
    float nota, soma = 0.0;
    int totalNotas = 0;
    int notasAcimaDe6 = 0;

    while (1) {
        printf("Digite uma nota (entre 0.0 e 10.0): ");
        scanf("%f", &nota);

        // Verifica se a nota está fora do intervalo válido
        if (nota < 0.0 || nota > 10.0) {
            printf("Nota inválida! Encerrando a entrada de dados.\n");
            break;
        }

        soma += nota;
        totalNotas++;

        if (nota >= 6.0) {
            notasAcimaDe6++;
        }
    }

    if (totalNotas > 0) {
        float media = soma / totalNotas;
        printf("\n--- Resultados ---\n");
        printf("Média das notas: %.2f\n", media);
        printf("Total de notas válidas: %d\n", totalNotas);
        printf("Notas maiores ou iguais a 6.0: %d\n", notasAcimaDe6);
    } else {
        printf("Nenhuma nota válida foi digitada.\n");
    }

    return 0;
}
