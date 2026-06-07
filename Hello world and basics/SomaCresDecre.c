#include <stdio.h>  // Biblioteca para entrada e saída padrão (printf, scanf)

// Função recursiva que retorna a soma de 1 até n
int soma(int n) {
    if (n == 1)
        return 1;           // Caso base: soma(1) = 1
    else
        return n + soma(n - 1);  // Passo recursivo: soma(n) = n + soma(n - 1)
}

// Função recursiva para imprimir de 1 até n (ordem crescente)
void crescente(int n) {
    if (n > 0) {
        crescente(n - 1);     // Chama a função até chegar no 1
        printf("%d ", n);     // Imprime os números na volta da recursão (ordem crescente)
    }
}

// Função recursiva para imprimir de n até 1 (ordem decrescente)
void decrescente(int n) {
    if (n > 0) {
        printf("%d ", n);     // Imprime o número primeiro
        decrescente(n - 1);   // Depois chama a função com n - 1 (ordem decrescente)
    }
}

int main() {
    int n;  // Variável para armazenar o número digitado pelo usuário

    // Solicita ao usuário que digite um número inteiro positivo
    printf("Digite um número inteiro positivo: ");
    scanf("%d", &n);  // Lê o valor digitado e armazena em n

    // Exibe o resultado da soma recursiva de 1 até n
    printf("Soma de 1 até %d = %d\n", n, soma(n));

    // Mostra os números de 1 até n (em ordem crescente)
    printf("Contagem crescente: ");
    crescente(n);
    printf("\n");

    // Mostra os números de n até 1 (em ordem decrescente)
    printf("Contagem decrescente: ");
    decrescente(n);
    printf("\n");

    return 0;  // Indica que o programa terminou com sucesso
}
