#include <stdio.h>
#include <stdlib.h>

int main()
{
 //Variáveis
 int n1;
 int term;
 int t1 = 0;
 int t2 = 1;
 int i;
    {//Solicitação do número
     printf("Informe um número inteiro e positivo");
     scanf("%d", &n1);

     if (n1 <= 0)
        {//Checagem para ver se o número é positivo ou não
         printf("Por favor, informe um número positivo e inteiro, e também pare de brincar");
         return 9;
        }//Exibição da mensagem caso informe um número que sirva para a tabela
          printf("A quantidade de termos da sequência de Fibonacci são de: ");
    }//Impressão dos termos da tabela Fubonacci
        for(i = 0; i < n1; i++)
      {
        if(i == 0) 
        {
         printf("%d", t1);
        }
         else if(i == 1) 
        {
         printf(", %d", t2);
        } 
         else 
        {
         term = t1 + t2;
         t1 = t2;
         t2 = term;
         printf(", %d", term);
        }
      }
    printf("\n");
    return 0;
}
//Vinicius Almeida Fajardo