#include <stdio.h>
#include <stdlib.h>

int main()
{//Variáveis
 int quantidade = 0;
 int n1;
 int temp;
    //Solicitação do número
    printf("Informe um número inteiro e positivo ");
    scanf("%d", &n1);

     if (n1 <= 0)
    {//Menssagem caso o número seja negativo
     printf("Por favor informe um número inteiro e positivo");
     return 1;
    }//Nova variável para evitar alteração da variável "n1"
     temp = n1; 
         while (temp >= 1)
        {//Laço de repetição com a nova variável
         temp = temp / 10;
         quantidade = quantidade + 1;
        }//Menssagem final
 printf("A quantidade de digitos do número %d é de: %d" ,n1, quantidade );

return 0;

}