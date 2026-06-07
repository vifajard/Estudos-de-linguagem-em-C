#include <stdio.h>
#include <stdlib.h>

int main()
{//Variáveis
 int n1;
 int i;
 int l;
    //Solicitação do número
     printf("Informe um número inteiro e positivo");
     scanf("%d" , &n1);
     if(n1 <= 1 )//Checagem para ver se o número e positvo ou não
    {
     printf("Por favor, digite um número inteiro e positivo, e que seja maior que 1\n");
     return 1;
    }

         for (i = 1; i <= n1; i++)//Loop do primeiro * e a quantidade de linhas que irá ter no código
        {
         for (l = 1; l <= i; l++)//Loop para adicionar os demais * no resultado do código
            { 
             printf("*");
            }
             printf("\n");

        }
        return 0;
 //Vinicius Almeida Fajardo
}
