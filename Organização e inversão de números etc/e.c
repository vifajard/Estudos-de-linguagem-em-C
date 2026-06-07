#include<stdio.h>
#include<stdlib.h>
int main(){
//Declarando variaveis
int n,digitos = 0;

//Dados de entrada
printf("Digite um número: ");
scanf("%d",&n);

//verificar de o termo e positivo
if (n <= 0)
{
  printf(" O numero deve ser inteiro e positivo!\n ");
  return 0;
}

///laço de repetição
 do {
        n = n / 10;
        digitos = digitos + 1;
    } while (n >= 1);

 //Saida
 printf("O número possui %d dígitos.\n", digitos);

 return 0;
}